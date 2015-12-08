#include "repositories/scientistrepository.h"
#include "utilities/utils.h"
#include "utilities/constants.h"
#include <fstream>
#include <cstdlib>
#include <iostream>

ScientistRepository::ScientistRepository()
{
    fileName = constants::DATA_FILE_NAME;
}

std::vector<Scientist> ScientistRepository::getAllScientists(std::string orderBy)
{
    std::vector<Scientist> scientists;

    QString orderQuery = QString::fromStdString(constants::SELECT_ALL_SCIENTISTS) + " " + QString::fromStdString(orderBy);
    QSqlQuery query(orderQuery);

    while (query.next()) {
        std::string name = query.value(0).toString().toStdString();
        enum sexType sex = utils::stringToSex(query.value(1).toString().toStdString());
        int yearBorn = query.value(2).toInt();

        if (query.value(3).isNull())
        {
            scientists.push_back(Scientist(name, sex, yearBorn));
        }
        else
        {
            int yearDied = query.value(3).toInt();
            scientists.push_back(Scientist(name, sex, yearBorn, yearDied));
        }

    }

    return scientists;
}

std::vector<Scientist> ScientistRepository::searchForScientists(std::string searchTerm)
{
    //std::vector<Scientist> allScientists = getAllScientists(constants::SORT_SCIENTIST_NAME_ASCENDING);
    std::vector<Scientist> filteredScientists;
    QString QSearchTerm = QString::fromStdString(searchTerm);
    QString searchQuery = QString::fromStdString(constants::SELECT_ALL_SCIENTISTS) +
    " WHERE s.name LIKE %" + QSearchTerm + "%" +
    " OR s.gender LIKE %" + QSearchTerm + "%" +
    " OR s.yearOfBirth LIKE %" + QSearchTerm + "%" +
    " OR s.yearOfDeath LIKE %" + QSearchTerm + "%";

    QSqlQuery query(searchQuery);

    while (query.next()) {
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

    query.exec();

    return true; //TODO return false if failed
}
