#ifndef SCIENTISTSERVICE_H
#define SCIENTISTSERVICE_H

#include "repositories/scientistrepository.h"
#include "utilities/constants.h"

class ScientistService
{
public:
    ScientistService();
    std::vector<Scientist> getAllScientists();
    std::vector<Scientist> searchForScientists(std::string searchTerm);
    bool addScientist(Scientist scientist);
    std::vector<Computer> getRelatedComputers(Scientist scientist);
    void changeSortOrder(int input);

private:
    ScientistRepository scientistRepo;
    std::string currentOrder;
};

#endif // SCIENTISTSERVICE_H
