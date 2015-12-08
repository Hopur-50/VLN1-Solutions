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
    /*QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbComputers = "NefnadbName.db.sqlite";
    db.setDatabaseName(dbComputers);
    db.open();*/
    /*
    if(!db.open())
    {
        cout << "Fail, big time..." << endl;
    }
    else
    {
        cout << "Awesomeness incarnate" << endl;
    }
*/
    QSqlQuery query;


    std::string name = computer.getName();
    std::string type = computer.getType();
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
        // string queryAdd = "INSERT INTO Computer (name, type, wasItConstructed, yearOfConstruction) VALUES";
        query.prepare("INSERT INTO Computers (name, type, wasItConstructed, yearOfConstruction) VALUES(:dbname,:dbtype,:dbwasItConstructed,:dbyearOfConstruction)");
        query.bindValue(":dbname", QString::fromStdString(name));
        query.bindValue(":dbtype", QString::fromStdString(type));
        query.bindValue(":dbwasItConstructed", QString::number(IntWasItConstructed));
        query.bindValue(":dbyearOfConstruction", QString::number(yearOfConstruction));
    }
    query.exec();
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
