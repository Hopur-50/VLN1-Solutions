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
    void OpenDatabase();
    std::vector<Scientist> getAllScientists(std::string orderBy);
    std::vector<Computer> getRelatedComputers(std::string name);
    std::vector<Scientist> searchForScientists(std::string searchTerm);
    bool addScientist(Scientist scientist);

private:
    std::string fileName;
};

#endif // SCIENTISTREPOSITORY_H
