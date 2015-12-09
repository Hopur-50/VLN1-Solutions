#ifndef COMPUTERREPOSITORY_H
#define COMPUTERREPOSITORY_H

#include <vector>
#include <string>

#include "models/computer.h"
#include "models/scientist.h"

#include <QtSql>

class ComputerRepository
{
public:
    ComputerRepository();

    bool addComputer(Computer computer);
    std::vector<Computer> getAllComputers(std::string orderBy);
    std::vector<Computer> searchForComputer(std::string searchTerm);
    std::vector<Scientist> getRelatedScientists(Computer computer);
    bool addRelation(Scientist scientist, Computer computer);

private:
    std::string fileName;
};

#endif // COMPUTERREPOSITORY_H
