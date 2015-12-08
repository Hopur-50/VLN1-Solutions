#include "services/computerservice.h"

ComputerService::ComputerService()
{

}

std::vector<Computer> ComputerService::getAllComputers()
{
    return computerRepo.getAllComputers(currentOrder);
}
/*
std::vector<Computer> ComputerService::searchForComputers(std::string searchTerm)
{
    return computerRepo.searchForComputer(searchTerm);
}
*/ //TODO implement in repo

bool ComputerService::addComputer(Computer computer)
{
    return computerRepo.addComputer(computer);
}

std::vector<Scientist> ComputerService::getRelatedScientists(std::string input)
{
    std::vector<Scientist> scientistVec;
    return scientistVec; //TODO implement
}

void ComputerService::changeSortOrder(int input)
{
    currentOrder = constants::SORT_COMPUTER[input - 1];
}
