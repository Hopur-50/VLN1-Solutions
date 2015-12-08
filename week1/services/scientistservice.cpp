#include "services/scientistservice.h"

#include <algorithm>

ScientistService::ScientistService()
{
    currentOrder = constants::SORT_SCIENTIST[0];
}

std::vector<Scientist> ScientistService::getAllScientists()
{
    return scientistRepo.getAllScientists(currentOrder);
}

std::vector<Scientist> ScientistService::searchForScientists(std::string searchTerm)
{
    return scientistRepo.searchForScientists(searchTerm);
}

bool ScientistService::addScientist(Scientist scientist)
{
    return scientistRepo.addScientist(scientist);
}

bool ScientistService::addRelation(std::string scientist, std::string computer)
{
    return true; //TODO implement
}

std::vector<Computer> ScientistService::getRelatedComputers(std::string input)
{
    return scientistRepo.getRelatedComputers(input);
    std::vector<Computer> compVec;
    return compVec; //TODO implement
}

void ScientistService::changeSortOrder(int input)
{
    currentOrder = constants::SORT_SCIENTIST[input - 1];
}
