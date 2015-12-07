#include "services/scientistservice.h"
#include "utilities/scientistcomparator.h"

#include <algorithm>

using namespace std;

ScientistService::ScientistService()
{

}

std::vector<Scientist> ScientistService::getAllScientists(QString orderBy)
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

bool ScientistService::addRelation(string scientist, string computer)
{
    return true;
}

vector<Computer> ScientistService::getRelatedComputers(std::string input)
{
    std::vector<Computer> compVec;
    return compVec;
}

vector<Scientist> ScientistService::getRelatedScientists(std::string input)
{
    std::vector<Scientist> scientistVec;
    return scientistVec;
}

void ScientistService::change_sort_order(int input)
{

}

std::vector<Computer> ScientistService::searchForComputers(std::string searchTerm)
{
    std::vector<Computer> compVec;
    return compVec;
}
