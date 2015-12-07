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

std::vector<Scientist> ScientistService::searchForScientists(std::string searchTerm)
{
    return scientistRepo.searchForScientists(searchTerm);
}

bool ScientistService::addScientist(Scientist scientist)
{
    return scientistRepo.addScientist(scientist);
}
