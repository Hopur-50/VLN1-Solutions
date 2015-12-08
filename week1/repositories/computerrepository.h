#ifndef COMPUTERREPOSITORY_H
#define COMPUTERREPOSITORY_H

#include <vector>
#include <string>

#include "models/computer.h"
#include <QtSql>

class ComputerRepository
{
public:
    ComputerRepository();
    void OpenDatabase();

    std::vector<Computer> getAllComputers();
    std::vector<Computer> searchForComputer(std::string searchTerm);
    bool addComputer(Computer computer);
    std::vector<Computer> getAllComputers(std::string orderBy);

private:
    std::string fileName;
};

#endif // COMPUTERREPOSITORY_H
