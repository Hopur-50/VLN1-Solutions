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

std::vector<Computer> ScientistService::getRelatedComputers(Scientist scientist)
{
    return scientistRepo.getRelatedComputers(scientist);
}

void ScientistService::changeSortOrder(int input)
{
    currentOrder = constants::SORT_SCIENTIST[input - 1];
}
