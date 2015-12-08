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

bool ComputerRepository::addComputer(Computer computer)
{
    QSqlQuery query;

    std::string name = computer.getName();
    std::string type = computer.getType();                  //Þarf ekki að vera cin á breytum?? virkar ekki í keyrslu
    bool wasItConstructed = computer.getWasItConstructed();
    int IntWasItConstructed = wasItConstructed;

    if (wasItConstructed != true)
    {
        query.prepare("INSERT INTO Computers (name, type, wasItConstructed) VALUES(:dbname,:dbtype,:dbwasItConstructed)");
        query.bindValue(":dbname", QString::fromStdString(name));
        query.bindValue(":dbtype", QString::fromStdString(type));
        query.bindValue(":dbwasItConstructed", QString::number(IntWasItConstructed));

    }
    else
    {
        int yearOfConstruction = computer.getYearOfConstruction();
        std::string queryAdd = "INSERT INTO Computer (name, type, wasItConstructed, yearOfConstruction) VALUES";

        query.prepare("INSERT INTO Computers (name, type, wasItConstructed, yearOfConstruction) VALUES(:dbname,:dbtype,:dbwasItConstructed,:dbyearOfConstruction)");
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
    QSqlQuery query(orderQuery);  //Vantar breytu fyrir framan orderQuery

    while (query.next())
    {
        std::string name = query.value(0).toString().toStdString();
        std::string type = query.value(1).toString().toStdString();
        int wasItConstructed = query.value(2).toInt();
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

/*
std::vector<Computer> ComputerRepository::getAllComputers()
{
    ifstream file;

    file.open(fileName.c_str());

    vector<Computer> computers;

    if(file.is_open())
    {
        string line;
        while(getline(file, line))
        {
            vector<string> fields = utils::splitString(line, constants::FILE_DELIMETER);

            if (fields.size() >= 3)
            {
                computers.push_back(Computer(name, type, wasItConstructed));
            }
            else
            {
                int yearOfConstruction;
                computers.push_back(Computer(name, type, wasItConstructed, yearOfConstruction));
            }
        }
    }

    file.close();

    return computers;
}

std::vector<Computer> searchForComputer(std::string searchTerm)
{
    vector <Computer> allComputers = getAllComputers();
    vector<Computer> filteredComputers;
    for(unsigned int i = 0; i < allComputers.size(); i++)
    {
        if(allComputers.at(i).contains(searchTerm))
        {
            filteredComputers.push_back(allComputers.at(i));
        }
    }
    return filteredComputers;
}

bool addComputer(Computer computer)
{
    ofstream file;

    file.open();

    if(file.is_open())
    {
        string name = computer.getName();
        string type = computer.getType();
        bool wasItConstructed = getWasItConstructed();
        int yearOfConstruction = getWasItConstructed();

        file << name << constants::FILE_DELIMETER
             << type << constants::DATA_FILE_NAME
             << wasItConstructed << constants::DATA_FILE_NAME;

        if(yearOfConstruction != constants::YEAR_DIED_DEFAULT_VALUE)
        {
                file << yearOfConstruction;
        }
        file << '\n';
    }
    else
    {
        return false;
    }
    file.close();
    return true;

}

*/
