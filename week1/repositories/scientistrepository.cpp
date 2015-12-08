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

    QString searchQuery = QString::fromStdString(constants::SELECT_ALL_SCIENTISTS) +
    " WHERE s.name LIKE %" + QString::fromStdString(searchTerm) + "%" +
    " OR s.gender LIKE %" + QString::fromStdString(searchTerm) + "%" +
    " OR s.yearOfBirth LIKE %" + QString::fromStdString(searchTerm) + "%" +
    " OR s.yearOfDeath LIKE %" + QString::fromStdString(searchTerm) + "%";

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
