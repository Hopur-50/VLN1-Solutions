#ifndef SCIENTISTREPOSITORY_H
#define SCIENTISTREPOSITORY_H

#include <vector>
#include <string>

#include "models/scientist.h"
#include "models/computer.h"
#include <QtSql>

class ScientistRepository
{
public:
    ScientistRepository();

    bool addScientist(Scientist scientist);
    std::vector<Scientist> getAllScientists(std::string orderBy);
    std::vector<Scientist> searchForScientists(std::string searchTerm);
    std::vector<Computer> getRelatedComputers(std::string name);    

private:
    std::string fileName;
};

#endif // SCIENTISTREPOSITORY_H
