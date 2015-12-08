#include "services/scientistservice.h"

#include <algorithm>

ScientistService::ScientistService()
{

}

std::vector<Scientist> ScientistService::getAllScientists(std::string orderBy)
{
    std::vector<Scientist> scientists = scientistRepo.getAllScientists(orderBy);

    //std::sort(scientists.begin(), scientists.end(), ScientistComparator(orderBy, orderAscending));

    return scientists;
}

std::vector<Computer> ScientistService::getAllComputers()
{
    std::vector<Computer> compVec;
    return compVec;
}

std::vector<Scientist> ScientistService::searchForScientists(std::string searchTerm)
{
    return scientistRepo.searchForScientists(searchTerm);
}

bool ScientistService::addScientist(Scientist scientist)
{
    return scientistRepo.addScientist(scientist);
}

bool ScientistService::addComputer(Computer computer)
{
    return true;
}

bool ScientistService::addRelation(std::string scientist, std::string computer)
{
    return true;
}

std::vector<Computer> ScientistService::getRelatedComputers(std::string input)
{
    std::vector<Computer> compVec;
    return compVec;
}

std::vector<Scientist> ScientistService::getRelatedScientists(std::string input)
{
    std::vector<Scientist> scientistVec;
    return scientistVec;
}

void ScientistService::changeSortOrder(int input)
{

}

std::vector<Computer> ScientistService::searchForComputers(std::string searchTerm)
{
    std::vector<Computer> compVec;
    return compVec;
}
