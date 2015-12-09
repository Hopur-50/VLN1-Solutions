#include "services/computerservice.h"
#include<iostream>

ComputerService::ComputerService()
{
    currentOrder = constants::SORT_COMPUTER[0];
}

std::vector<Computer> ComputerService::getAllComputers()
{
    return computerRepo.getAllComputers(currentOrder);
}

std::vector<Computer> ComputerService::searchForComputers(std::string searchTerm)
{
    return computerRepo.searchForComputers(searchTerm);
}

bool ComputerService::addComputer(Computer computer)
{
    return computerRepo.addComputer(computer);
}

bool ComputerService::addRelation(Scientist scientist, Computer computer)
{
    std::cout << "SERVICEADDINGRELATION\n";
    return computerRepo.addRelation(scientist, computer);
}

std::vector<Scientist> ComputerService::getRelatedScientists(Computer computer)
{
    return computerRepo.getRelatedScientists(computer);
}

void ComputerService::changeSortOrder(int input)
{
    currentOrder = constants::SORT_COMPUTER[input - 1];
}
