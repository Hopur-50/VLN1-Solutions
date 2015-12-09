#ifndef INTERFACE_H
#define INTERFACE_H
#include "models/computer.h"

#include "services/scientistservice.h"
#include "services/computerservice.h"

using namespace std;

class Interface
{
public:
    Interface();
    ~Interface();
    void menu(int &userchoice);
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
    void selectScientistOrder();
    void selectComputerOrder();
    std::string selectRelationOrder();
    void search();
    void searchScientist();
    void searchComputer();

private:
    ScientistService scientistService;
    ComputerService computerService;
    QSqlDatabase db;
};

#endif // INTERFACE_H
