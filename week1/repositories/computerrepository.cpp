#include "computerrepository.h"
#include "utilities/utils.h"
#include "utilities/constants.h"
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <sstream>

ComputerRepository::ComputerRepository()
{

}

bool ComputerRepository::addComputer(Computer computer)
{
    QSqlQuery query;

    std::string name = computer.getName();
    std::string type = computer.getType();
    bool wasItConstructed = computer.getWasItConstructed();
    int IntWasItConstructed = wasItConstructed;

    if (wasItConstructed == false)
    {
        query.prepare("INSERT INTO Computers (name, computerType, constructed) VALUES(:dbname,:dbtype,:dbwasItConstructed)");
        query.bindValue(":dbname", QString::fromStdString(name));
        query.bindValue(":dbtype", QString::fromStdString(type));
        query.bindValue(":dbwasItConstructed", QString::number(IntWasItConstructed));

    }
    else
    {
        int yearOfConstruction = computer.getYearOfConstruction();
        //std::string queryAdd = "INSERT INTO Computer (name, type, wasItConstructed, yearOfConstruction) VALUES";
        query.prepare("INSERT INTO Computers (name, computerType, constructed, buildYear) VALUES(:dbname,:dbtype,:dbwasItConstructed,:dbyearOfConstruction)");
        query.bindValue(":dbname", QString::fromStdString(name));
        query.bindValue(":dbtype", QString::fromStdString(type));
        query.bindValue(":dbwasItConstructed", QString::number(IntWasItConstructed));
        query.bindValue(":dbyearOfConstruction", QString::number(yearOfConstruction));
    }

    return query.exec();
}

std::vector<Computer> ComputerRepository::getAllComputers(std::string orderBy)
{
    std::vector<Computer> computers;

    QString orderQuery = QString::fromStdString(constants::SELECT_ALL_COMPUTERS) + " " + QString::fromStdString(orderBy);
    QSqlQuery query(orderQuery);

    while (query.next())
    {
        std::string name = query.value(0).toString().toStdString();
        std::string type = query.value(1).toString().toStdString();
        bool wasItConstructed = query.value(2).toInt();
        int yearOfConstruction = query.value(3).toInt();

        if (query.value(2) == false)
        {
            computers.push_back(Computer(name, type, wasItConstructed));
        }
        else
        {
              computers.push_back(Computer(name, type, wasItConstructed, yearOfConstruction));
        }
    }

    return computers;
}

std::vector<Computer> ComputerRepository::searchForComputers(std::string searchTerm)
{
<<<<<<< HEAD

    std::vector<Computer> filteredComputers;
=======
    std::vector<Computer> foundComputers;
>>>>>>> d3d3d2d2da3652fde360fa5076c31842ee096dea
    QString QSearchTerm = QString::fromStdString(searchTerm);

    QString searchQuery = QString::fromStdString(constants::SELECT_ALL_COMPUTERS)+
<<<<<<< HEAD
    "WHERE c.name LIKE '%'" + QSearchTerm + '%' +
    "OR c.computerType LIKE '%'" + QSearchTerm + '%' +
    "OR c.constructed LIKE '%'" + QSearchTerm + '%' +
    "OR c.buildYear LIKE '%'" + QSearchTerm + '%';
=======
    " WHERE c.name LIKE '%" + QSearchTerm + "%'" +
    " OR c.computerType LIKE '%" + QSearchTerm + "%'" +
    " OR c.constructed LIKE '%" + QSearchTerm + "%'" +
    " OR c.buildYear LIKE '%" + QSearchTerm + "%'";
>>>>>>> d3d3d2d2da3652fde360fa5076c31842ee096dea

    QSqlQuery query(searchQuery);

    while(query.next())
    {
        std::string name = query.value(0).toString().toStdString();
        std::string type = query.value(1).toString().toStdString();
        int wasItConstructed = query.value(2).toInt();
        int yearOfConstruction = query.value(3).toInt();

        if(query.value(2).isNull())
        {
            foundComputers.push_back(Computer(name, type, wasItConstructed));
        }
        else
        {
<<<<<<< HEAD

            filteredComputers.push_back(Computer(name, type, wasItConstructed, yearOfConstruction));
=======
            foundComputers.push_back(Computer(name, type, wasItConstructed, yearOfConstruction));
>>>>>>> d3d3d2d2da3652fde360fa5076c31842ee096dea
        }
    }
    return foundComputers;
}

std::vector<Scientist> ComputerRepository::getRelatedScientists(Computer computer)
{
    QSqlQuery query;
    std::vector<Scientist> scientists;
    query.prepare("SELECT id FROM Computers WHERE name = :dbName");
    query.bindValue(":dbName", QString::fromStdString(computer.getName()));
    query.exec();
    query.next();

    int computerId = query.value(0).toInt();

    query.prepare("SELECT scientistsID FROM Relations WHERE computersID = :dbCId");
    query.bindValue(":dbCId", computerId);
    query.exec();

    int i = 0;
    QSqlQuery query2;

    while(query.next())
    {
        int csId = query.value(i).toInt();
        query2.prepare("SELECT name, gender, yearOfBirth, yearOfDeath FROM Scientists WHERE id = :dbCsId");
        query2.bindValue(":dbCsId", csId);
        query2.exec();
        while(query2.next())
        {
            std::string name = query.value(0).toString().toStdString();
            enum sexType sex = utils::stringToSex(query.value(1).toString().toStdString());
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
        i++;
    }

    return scientists;
}

bool ComputerRepository::addRelation(Scientist scientist, Computer computer)
{
    QSqlQuery query;

    std::string name = computer.getName();
    std::string type = computer.getType();
    bool wasItConstructed = computer.getWasItConstructed();
    int IntWasItConstructed = wasItConstructed;

    if (wasItConstructed == false)
    {
        query.prepare("INSERT INTO Computers (name, computerType, constructed) VALUES(:dbname,:dbtype,:dbwasItConstructed)");
        query.bindValue(":dbname", QString::fromStdString(name));
        query.bindValue(":dbtype", QString::fromStdString(type));
        query.bindValue(":dbwasItConstructed", QString::number(IntWasItConstructed));
    }
    else
    {
        int yearOfConstruction = computer.getYearOfConstruction();
        //std::string queryAdd = "INSERT INTO Computer (name, type, wasItConstructed, yearOfConstruction) VALUES";
        query.prepare("INSERT INTO Computers (name, computerType, constructed, buildYear) VALUES(:dbname,:dbtype,:dbwasItConstructed,:dbyearOfConstruction)");
        query.bindValue(":dbname", QString::fromStdString(name));
        query.bindValue(":dbtype", QString::fromStdString(type));
        query.bindValue(":dbwasItConstructed", QString::number(IntWasItConstructed));
        query.bindValue(":dbyearOfConstruction", QString::number(yearOfConstruction));
    }

    query.prepare("SELECT id FROM Computers WHERE name = :dbComputer");
    query.bindValue(":dbComputer", QString::fromStdString(computer.getName()));
    query.exec();
    query.next();
    int cId = query.value(0).toInt();

    query.prepare("SELECT id FROM Scientists WHERE name = :dbScientist");
    query.bindValue(":dbScientist", QString::fromStdString(scientist.getName()));
    query.exec();
    query.next();
    int csId = query.value(0).toInt();

    query.prepare("INSERT INTO relations(cId, csId) VALUES(:dbCId, :dbCsId");
    query.bindValue(":dbCId", cId);
    query.bindValue(":dbCsId", csId);

    return query.exec();
}

