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

std::vector<Scientist> ScientistRepository::getAllScientists(QString orderQuery)
{
    //ifstream file;

    //file.open(fileName.c_str());

    std::vector<Scientist> scientists;

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

/*
    if (file.is_open())
    {
        string line;
        while(getline(file, line))
        {
            vector<string> fields = utils::splitString(line, constants::FILE_DELIMETER);

            if (fields.size() >= 3)
            {
                string name = fields.at(0);
                enum sexType sex = utils::stringToSex(fields.at(1));
                int yearBorn = utils::stringToInt(fields.at(2));

                if (fields.size() == 3)
                {
                    scientists.push_back(Scientist(name, sex, yearBorn));
                }
                else
                {
                    int yearDied = utils::stringToInt(fields.at(3));

                    scientists.push_back(Scientist(name, sex, yearBorn, yearDied));
                }
            }
        }
    }

    file.close();
*/
    return scientists;
}

std::vector<Scientist> ScientistRepository::searchForScientists(std::string searchTerm)
{
    std::vector<Scientist> allScientists = getAllScientists(constants::SORT_SCIENTIST_NAME_ASCENDING);
    std::vector<Scientist> filteredScientists;

    for (unsigned int i = 0; i < allScientists.size(); i++)
    {
        if (allScientists.at(i).contains(searchTerm))
        {
            filteredScientists.push_back(allScientists.at(i));
        }
    }

    return filteredScientists;
}

bool ScientistRepository::addScientist(Scientist scientist)
{/*
    ofstream file;

    file.open(fileName.c_str(), std::ios::app);

    if (file.is_open())
    {
        std::string name = scientist.getName();
        enum sexType sex = scientist.getSex();
        int yearBorn = scientist.getYearBorn();
        int yearDied = scientist.getYearDied();

        file << name << constants::FILE_DELIMETER
             << sex << constants::FILE_DELIMETER
             << yearBorn << constants::FILE_DELIMETER;

        if (yearDied != constants::YEAR_DIED_DEFAULT_VALUE)
        {
            file << yearDied;
        }

        file << '\n';
    }
    else
    {
        return false;
    }

    file.close();*/
    return true;
}
