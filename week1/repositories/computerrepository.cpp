#include "computerrepository.h"
#include "utilities/utils.h"
#include "utilities/constants.h"
#include <fstream>
#include <cstdlib>
#include <iostream>



ComputerRepository::ComputerRepository()
{
    fileName = constants::DATA_FILE_NAME;
}
std::vector<Computer> ComputerRepository::searchForComputer(std::string searchTerm)
{
    std::vector<Computer> filteredComputers;
    QString QSearchTerm = QString::fromStdString(searchTerm);
    QString searchQuery = QString::fromStdString(constants::SELECT_ALL_COMPUTERS)+
    "WHERE s.name LIKE %" + QSearchTerm + "%" +
    "OR s.type LIKE %" + QSearchTerm + "%" +
    "OR s.wasItConstructed LIKE %" + QSearchTerm + "%" +
    "OR s.yearOfConstruction LIKE %" + QSearchTerm + "%";

    QSqlQuery query(searchQuery);

    while(query.next())
    {
        std::string name = query.value(0).toString().toStdString();
        std::string type = query.value(1).toString().toStdString();
        int wasItConstructed = query.value(3).toInt();
        int yearOfConstruction = query.value(4).toInt();

        if(wasItConstructed == 0)
        {
            filteredComputers.push_back(Computer(name, type, wasItConstructed));
        }
        else
        {
            filteredComputers.push_back(Computer(name, type, wasItConstructed, yearOfConstruction));
        }

    }
    return filteredComputers;
}
bool ComputerRepository::addRelation(std::string scientist, std::string computer)
{
    QSqlQuery query;

    query.prepare("SELECT id FROM Computers WHERE name = :dbComputer");
    query.bindValue(":dbComputer", QString::fromStdString(computer));
    query.exec();
    query.next();
    int cId = query.value(0).toInt();

    query.prepare("SELECT id FROM Scientists WHERE name = :dbScientist");
    query.bindValue(":dbScientist", QString::fromStdString(scientist));
    query.exec();
    query.next();
    int csId = query.value(0).toInt();

    query.prepare("INSERT INTO relations(cId, csId) VALUES(:dbCId, :dbCsId");
    query.bindValue(":dbCId", cId);
    query.bindValue(":dbCsId", csId);

    return query.exec();
}

std::vector<Scientist> ComputerRepository::getRelatedScientists(std::string name)
{
    QSqlQuery query;
    std::vector<Scientist> scientists;
    query.prepare("SELECT id FROM Computers WHERE name = :dbName");
    query.bindValue(":dbName", QString::fromStdString(name));
    query.exec();
    query.next();
    int computerId = query.value(0).toInt();

    query.prepare("SELECT csId FROM Relations WHERE cId = :dbCId");
    query.bindValue(":dbCId", computerId);
    query.exec();
    int i=0;
    QSqlQuery query2;
    while(query.next())
    {
        int csId = query.value(i).toInt();
        query2.prepare("SELECT name, sex, yearOfBirth, yearOfDeath FROM Scientists WHERE id = :dbCsId");
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

bool ComputerRepository::addComputer(Computer computer)
{
    QSqlQuery query;

    std::string name = computer.getName();
    std::string type = computer.getType();                  //Þarf ekki að vera cin á breytum?? virkar ekki í keyrslu
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

    query.exec();
    return true;
}


std::vector<Computer> ComputerRepository::getAllComputers(std::string orderBy)
{
    std::cout << "start\n";
    std::vector<Computer> computers;

    QString orderQuery = QString::fromStdString(constants::SELECT_ALL_COMPUTERS) + " " + QString::fromStdString(orderBy);
    QSqlQuery query(orderQuery);  //Vantar breytu fyrir framan orderQuery
    std::cout << "1\n";

    while (query.next())
    {
        std::cout << "2\n";
        std::string name = query.value(0).toString().toStdString();
        std::string type = query.value(1).toString().toStdString();
        bool wasItConstructed = query.value(2).toInt();
        std::cout << "wasit constr " << wasItConstructed << std::endl;
        int yearOfConstruction = query.value(3).toInt();

        if (query.value(2) == false)
        {
            std::cout << "3\n";
            computers.push_back(Computer(name, type, wasItConstructed));
        }
        else
        {
            std::cout << "4\n";
              computers.push_back(Computer(name, type, wasItConstructed, yearOfConstruction));
        }
    }

    return computers;
}

