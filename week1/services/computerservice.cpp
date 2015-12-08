#include "services/computerservice.h"

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
    return computerRepo.searchForComputer(searchTerm);
}

bool ComputerService::addComputer(Computer computer)
{
    return computerRepo.addComputer(computer);
}

bool ComputerService::addRelation(Scientist scientist, Computer computer)
{
    return computerRepo.addRelation(scientist, computer);
}

std::vector<Scientist> ComputerService::getRelatedScientists(std::string input)
{
    return computerRepo.getRelatedScientists(input);
}

void ComputerService::changeSortOrder(int input)
{
    currentOrder = constants::SORT_COMPUTER[input - 1];
}
