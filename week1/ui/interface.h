#ifndef INTERFACE_H
#define INTERFACE_H
#include "models/computer.h"

#include "services/scientistservice.h"

using namespace std;

class Interface
{
public:
    Interface();
    void menu(int& userchoice);
    void add();
    bool addScientist();
    bool addComputer();
    bool addRelation();
    void display();
    void displayAllScientists();
    void displayAllComputers();
    void displayScientists(std::vector<Scientist> scientists);
    void displayComputers(std::vector<Computer> computers);
    void displayRelations();
    void displayScientistRelations();
    void displayComputerRelations();
    void selectOrder();
    void search();
    void searchScientist();
    void searchComputer();

private:
    ScientistService scientistService;
};

#endif // INTERFACE_H
