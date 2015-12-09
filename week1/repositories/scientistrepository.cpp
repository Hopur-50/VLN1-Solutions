#include "repositories/scientistrepository.h"
#include "utilities/utils.h"
#include "utilities/constants.h"
#include <fstream>
#include <cstdlib>
#include <iostream>


ScientistRepository::ScientistRepository()
{
}

bool ScientistRepository::addScientist(Scientist scientist)
{
    QSqlQuery query;

    std::string name = scientist.getName();
    enum sexType sex = scientist.getSex();
    int yearBorn = scientist.getYearBorn();
    int yearDied = scientist.getYearDied();

    if (yearDied == constants::YEAR_DIED_DEFAULT_VALUE)
    {
        query.prepare("INSERT INTO Scientists (name, gender, yearOfBirth) VALUES(:dbname,:dbgender,:dbyearOfBirth)");
        query.bindValue(":dbname", QString::fromStdString(name));
        query.bindValue(":dbgender", QString::fromStdString(utils::sexToString(sex)));
        query.bindValue(":dbyearOfBirth", QString::number(yearBorn));

    }
    else
    {
        query.prepare("INSERT INTO Scientists (name, gender, yearOfBirth, yearOfDeath) VALUES(:dbname,:dbgender,:dbyearOfBirth, :dbyearOfDeath)");
        query.bindValue(":dbname", QString::fromStdString(name));
        query.bindValue(":dbgender", QString::fromStdString(utils::sexToString(sex)));
        query.bindValue(":dbyearOfBirth", QString::number(yearBorn));
        query.bindValue(":dbyearOfDeath", QString::number(yearDied));
    }

    return query.exec();
}

std::vector<Scientist> ScientistRepository::getAllScientists(std::string orderBy)
{
    std::vector<Scientist> scientists;

    QString orderQuery = QString::fromStdString(constants::SELECT_ALL_SCIENTISTS) + " " + QString::fromStdString(orderBy);
    QSqlQuery query(orderQuery);

    while (query.next())
    {
        std::string name = query.value(0).toString().toStdString();
        std::string sexString = query.value(1).toString().toStdString();
        enum sexType sex;
        if(sexString == "m" || sexString == " m" || sexString == "male" || sexString == " male")
        {
            sex = male;
        }
        else
        {
            sex = female;
        }
        int yearBorn = query.value(2).toInt();
        int yearDied = query.value(3).toInt();

        if (query.value(3).isNull())
        {
            scientists.push_back(Scientist(name, sex, yearBorn));
        }
        else
        {

            scientists.push_back(Scientist(name, sex, yearBorn, yearDied));
        }

    }

    return scientists;
}

std::vector<Scientist> ScientistRepository::searchForScientists(std::string searchTerm)
{
    std::vector<Scientist> filteredScientists;
    QString QSearchTerm = QString::fromStdString(searchTerm);
    QString searchQuery = QString::fromStdString(constants::SELECT_ALL_SCIENTISTS) +
    " WHERE s.name LIKE %" + QSearchTerm + "%" +
    " OR s.gender LIKE %" + QSearchTerm + "%" +
    " OR s.yearOfBirth LIKE %" + QSearchTerm + "%" +
    " OR s.yearOfDeath LIKE %" + QSearchTerm + "%";

    QSqlQuery query(searchQuery);

    while (query.next())
    {
        std::string name = query.value(0).toString().toStdString();
        enum sexType sex = utils::stringToSex(query.value(1).toString().toStdString());
        int yearBorn = query.value(2).toInt();

        if (query.value(3).isNull())
        {
            filteredScientists.push_back(Scientist(name, sex, yearBorn));
        }
        else
        {
            int yearDied = query.value(3).toInt();
            filteredScientists.push_back(Scientist(name, sex, yearBorn, yearDied));
        }

    }

    return filteredScientists;
}

std::vector<Computer> ScientistRepository::getRelatedComputers(Scientist scientist)
{
    QSqlQuery query;
    std::vector<Computer> computers;
    query.prepare("SELECT id FROM Scientists WHERE name = :dbName");
    query.bindValue(":dbName", QString::fromStdString(scientist.getName()));
    query.exec();
    query.next();
    int scientistId = query.value(0).toInt();

    query.prepare("SELECT computersID FROM Relations WHERE scientistsID = :dbCsId");
    query.bindValue(":dbCsId", scientistId);
    query.exec();
    int i=0;
    QSqlQuery query2;
    while(query.next())
    {
        int cId=query.value(i).toInt();
        query2.prepare("SELECT name, buildYear, computerType, constructed FROM Computers WHERE id = :dbCId");
        query2.bindValue(":dbCId", cId);
        query2.exec();
        while(query2.next())
        {
            std::string name = query2.value(0).toString().toStdString();
            int buildYear = query2.value(1).toInt();
            std::string type = query2.value(2).toString().toStdString();
            bool wasItConstructed = query2.value(3).toBool();
            if(query2.value(1).isNull())
            {
                computers.push_back(Computer(name, type, wasItConstructed));
            }
            else
            {
                computers.push_back(Computer(name, type, wasItConstructed, buildYear));
            }
        }
        i++;
    }

    return computers;
}


