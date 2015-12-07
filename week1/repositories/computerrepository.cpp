#include "computerrepository.h"
#include "utilities/utils.h"
#include "utilities/constants.h"
#include <fstream>
#include <cstdlib>
#include <iostream>

using namespace std;

ComputerRepository::ComputerRepository()
{
    fileName = constants::DATA_FILE_NAME;
}

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
