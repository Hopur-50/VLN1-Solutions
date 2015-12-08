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
    void OpenDatabase();

    std::vector<Computer> getAllComputers();
    std::vector<Computer> searchForComputer(std::string searchTerm);
    void addComputer(Computer computer);
    std::vector<Scientist> getRelatedScientists(std::string name);
    std::vector<Computer> getAllComputers(std::string orderBy);
    void addRelation(std::string scientist, std::string computer);

private:
    std::string fileName;
};

#endif // COMPUTERREPOSITORY_H
