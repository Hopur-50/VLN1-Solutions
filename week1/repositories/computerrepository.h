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

    std::vector<Computer> getAllComputers();
    std::vector<Computer> searchForComputer(std::string searchTerm);
    bool addComputer(Computer computer);
    std::vector<Scientist> getRelatedScientists(Computer computer);
    std::vector<Computer> getAllComputers(std::string orderBy);
    bool addRelation(Scientist scientist, Computer computer);

private:
    std::string fileName;
};

#endif // COMPUTERREPOSITORY_H
