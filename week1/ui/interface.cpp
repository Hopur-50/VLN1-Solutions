#include "ui/interface.h"
#include "utilities/constants.h"
#include "utilities/utils.h"
#include "models/computer.h"

#include <iostream>
#include <iomanip>

Interface::Interface()
{
    start();
}

Interface::~Interface()
{

}

void Interface::start()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "secondDatabase.sqlite";
    db.setDatabaseName(dbName);

    db.open();

    QSqlQuery query(db);

    if(!db.open())
    {
        cout << "Failed to open the database" << endl;
    }
    else
    {
        cout << "Connected..." << endl;
    }
}

void Interface::menu(int& userChoice) //Displays the main menu for user
{
    cout << "Choose a number from the menu" << endl;
    cout << "-----------------------------" << endl;
    cout << "1 to add new item to database" << endl;
    cout << "2 to display info" << endl;
    cout << "3 to arrange list" << endl;
    cout << "4 to search for scientists or computers" << endl;
    cout << "5 to quit the program" << endl;

    cin >> userChoice;
    switch (userChoice)
    {
        case 1:
            add();
            break;
        case 2:
            display();
            break;
        case 3:
            selectOrder();
            break;
        case 4:
            search();
            break;
        case 5:     //Quits the program
            break;
        default:
            cout << "Wrong input" << endl;
            menu(userChoice);
            break;
    }
}

void Interface::add()
{
    cout << "Choose one of the following numbers" << endl;
    cout << "-----------------------------------" << endl;
    cout << "0 go to main menu" << endl;
    cout << "1 to add a scientist" << endl;
    cout << "2 to add a computer" << endl;
    cout << "3 to add a relation" << endl;


    int userChoice2;
    cin >> userChoice2;

    switch (userChoice2)
    {
        case 0:        //Main menu
            break;
        case 1:
            addScientist();
            break;
        case 2:
            addComputer();
            break;
        case 3:
            if(addRelation())
            {
                cout << "SUCCESS" << endl;
            }
            else
            {
                cout << "FAILURE" << endl;
            }
            break;
        default:
            cout << "Wrong input" << endl;
            add();
            break;
    }
}

bool Interface::addScientist()
{
    int userChoice;

    cout << "To add a scientist, type in:" << endl;
    cout << "Name, sex, yearBorn, yearDied(optional)" << endl;
    cout << "Comma separated like in the example above." << endl;
    cout << "If you would like to go back to the main menu, please type the number 0" << endl;
    cout << "Input: ";
    string data;
    cin.ignore();
    getline(cin, data);
    vector<string> fields = utils::splitString(data, ','); //Sker strenginn niður á kommu.

    if(data == "0" || data == " 0")
    {
        menu(userChoice);
    }

    if (fields.size() > 2 && fields.size() < 5)
    {
        string name = fields.at(0);

        enum sexType sex;

        if (fields.at(1) == "male" || fields.at(1) == " male") //Because EVERYONE writes a space after a comma.
        {
            sex = sexType::male;
        }

        else if(fields.at(1) == "female" || fields.at(1) == " female")
        {
            sex = sexType::female;
        }

        int yearBorn = utils::stringToInt(fields.at(2));

        if (fields.size() == 3)
        {
            return scientistService.addScientist(Scientist(name, sex, yearBorn));
            cout << "Successfully added a scientist" << endl;
        }
        else
        {
            int yearDied = utils::stringToInt(fields.at(3));

            return scientistService.addScientist(Scientist(name, sex, yearBorn, yearDied));
            cout << "Successfully added a scientist" << endl;
        }
    }

    cout << "There was an error in your input." << endl;
    return false;
}

bool Interface::addComputer()
{
    int userChoice;

    cout << "To add a computer, type in:" << endl;
    cout << "Name, type, wasItConstructed? (Y/N), yearOfConstruction(optional)" << endl;
    cout << "Comma separated like in the example above." << endl;
    cout << "If you would like to go back to the main menu, please type the number 0" << endl;
    cout << "Input: ";
    string data;
    cin.ignore();
    getline(cin, data);
    vector<string> fields = utils::splitString(data, ',');

    if(data == "0" || data == " 0")
    {
        menu(userChoice);
    }

    if (fields.size() > 2 && fields.size() < 5)
    {
        string name = fields.at(0);
        string type = fields.at(1);

        bool wasItConstructed;

        if(fields.at(2) == "Y" || fields.at(2) == "y") //Ef tölvan var búin til skilar það true en ef ekki þá skilar fallið false
        {
            wasItConstructed = true;

        }
        else if(fields.at(2) == "N" || fields.at(2) == "n")
        {
            wasItConstructed = false;
        }
        else
        {
            return false;
        }

        if (fields.size() == 3)
        {
            cout << "Successfully added a computer" << endl;
            return computerService.addComputer(Computer(name, type, wasItConstructed));
        }
        else
        {
            int yearOfConstruction = utils::stringToInt(fields.at(3)); //Skilagildi ef tölvan var búin til, wasItConstructed = true
            cout << "Successfully added a computer" << endl;
            return computerService.addComputer(Computer(name, type, wasItConstructed, yearOfConstruction));
        }
    }

    cout << "There was an error in your input." << endl;
    return false;
}

bool Interface::addRelation()
{
    std::vector<Scientist> scientists = scientistService.getAllScientists();
    displayScientists(scientists);
    cout << "Choose the number of the scientist to be added in the relation";
    int scientistId;
    cin >> scientistId;
    Scientist scientist = scientists[scientistId-1];

    std::vector<Computer> computers = computerService.getAllComputers();
    displayComputers(computers);
    cout << "Choose the number of the computer to be added in the relation";
    int computerId;
    cin >> computerId;
    Computer computer = computers[computerId-1];

    return computerService.addRelation(scientist, computer);
}

void Interface::display() //Prints from the vector
{
    cout << "Choose a number from the menu" << endl;
    cout << "-----------------------------" << endl;
    cout << "0 go to main menu" << endl;
    cout << "1 to display scientists" << endl;
    cout << "2 to display computers" << endl;
    cout << "3 to display relations" << endl;
    int userChoice2;
    cin >> userChoice2;
    switch (userChoice2)
    {
        case 0:
            break;
        case 1:
            displayAllScientists();
            break;
        case 2:
            displayAllComputers();
            break;
        case 3:
            displayRelations();
            break;
        default:
            cout << "Wrong input" << endl;
            display();
            break;
    }
}

void Interface::displayAllScientists()
{
    vector<Scientist> scientists = scientistService.getAllScientists();
    displayScientists(scientists);
    cout << '\n';
}

void Interface::displayAllComputers()
{
    vector<Computer> computers = computerService.getAllComputers();
    displayComputers(computers);
    cout << '\n';
}

void Interface::displayScientists(std::vector<Scientist> scientists)
{
    if (scientists.size() == 0)
    {
        cout << "No scientist found.\n";
        return;
    }

    cout << "Printing all scientists:\n";

    cout << setw(5)  << std::left << "Nr:"
         << setw(24) << std::left << "Name:"
         << setw(8)  << std::left << "Sex:"
         << setw(12) << std::left << "Year born:"
         << setw(12) << std::left << "Year died:" << endl;

    for (unsigned int i = 0; i < scientists.size(); i++)
    {
        string scientistSex = (scientists.at(i).getSex() == sexType::male) ? "Male" : "Female";

        int yearDied = scientists.at(i).getYearDied();
        string died = (yearDied == constants::YEAR_DIED_DEFAULT_VALUE) ? "Alive" : utils::intToString(yearDied);

        cout << setw(5)  << std::left << i + 1
             << setw(24) << std::left << scientists.at(i).getName()
             << setw(8)  << std::left << scientistSex
             << setw(12) << std::left << scientists.at(i).getYearBorn()
             << setw(12) << std::left << died << endl;
    }
}

void Interface::displayComputers(std::vector<Computer> computers)
{
    if (computers.size() == 0)
    {
        cout << "No computer found.\n";
        return;
    }

    cout << "Printing all computers:\n";

    cout << setw(5)  << std::left << "Nr:"
         << setw(20) << std::left << "Name:"
         << setw(15) << std::left << "Type:"
         << setw(12) << std::left << "Year built:" << endl;

    for (unsigned int i = 0; i < computers.size(); i++)
    {
        string computerType = computers.at(i).getType();

        int yearOfConstruction = computers.at(i).getYearOfConstruction();
        string built = (yearOfConstruction == constants::YEAR_OF_CONSTRUCTION_VALUE) ? "Not built" : utils::intToString(yearOfConstruction);

        cout << setw(5)  << std::left << i + 1
             << setw(20) << std::left << computers.at(i).getName()
             << setw(15)  << std::left << computerType
             << setw(12) << std::left << built << endl;
    }
}

void Interface::displayRelations()
{
    cout << "Choose one of the following numbers:" << endl;
    cout << "-----------------------------------" << endl;
    cout << "0 to go back to main menu" << endl;
    cout << "1 to display all relations to a scientist" << endl;
    cout << "2 to display all relations to a computer" << endl;
    int userChoice3;
    cin >> userChoice3;
    switch (userChoice3)
    {
        case 0:
            break;
        case 1:
            displayScientistRelations();
            break;
        case 2:
            displayComputerRelations();
            break;
        default:
            cout << "Wrong input" << endl;
            displayRelations();
            break;
    }
}

void Interface::displayScientistRelations()
{
    std::vector<Scientist> scientists = scientistService.getAllScientists();
    displayScientists(scientists);
    cout << "Choose the number of the scientist whose relations you wish to see: ";
    int scientistId;
    cin >> scientistId;
    Scientist scientist = scientists[scientistId-1];
    vector<Computer> computers = scientistService.getRelatedComputers(scientist);
    displayComputers(computers);
    cout << '\n';
}

void Interface::displayComputerRelations()
{
    cout << "Enter the computer whose scientists you would like to see: ";
    std::vector<Computer> computers = computerService.getAllComputers();
    displayComputers(computers);
    cout << "Choose the number of the computer whose relations you would like to see: ";
    int computerId;
    cin >> computerId;
    Computer computer = computers[computerId-1];
    vector<Scientist> scientists = computerService.getRelatedScientists(computer);
    displayScientists(scientists);
    cout << '\n';
}

void Interface::selectOrder()
{
    cout << "Which order would you like to change?" << endl;
    cout << "Choose one of the following numbers:" << endl;
    cout << "-----------------------------------" << endl;
    cout << "0 to go back to main menu" << endl;
    cout << "1 to change the order of scientists" << endl;
    cout << "2 to change the order of computers" << endl;

    int orderChoice;
    cin >> orderChoice;
    switch(orderChoice)
    {
        case 0:
            break;
        case 1:
            selectScientistOrder();
            break;
        case 2:
            selectComputerOrder();
            break;
        default:
            cout << "Wrong input" << endl;
            selectOrder();
            break;
    }
}

void Interface::selectScientistOrder()
{
    cout << "Which order would you like to retrieve list items in?" << endl;
    cout << "Choose one of the following numbers:" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "0 to go back to main menu" << endl;
    cout << "1 for a list sorted by names in ascending order" << endl;
    cout << "2 for a list sorted by names in descending order" << endl;
    cout << "3 for a list sorted by year born in ascending order" << endl;
    cout << "4 for a list sorted by year born in descending order" << endl;
    cout << "5 for a list sorted by year died in ascending order" << endl;
    cout << "6 for a list sorted by year died in descending order" << endl;
    int scientistOrderChoice;
    cin >> scientistOrderChoice;

    scientistService.changeSortOrder(scientistOrderChoice);
}

void Interface::selectComputerOrder()
{
    cout << "Which order would you like to retrieve list items in?" << endl;
    cout << "Choose one of the following numbers:" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "0 to go back to main menu" << endl;
    cout << "1 for a list sorted by names in ascending order" << endl;
    cout << "2 for a list sorted by names in descending order" << endl;
    cout << "3 for a list sorted by year of construction in ascending order" << endl;
    cout << "4 for a list sorted by year of construction in descending order" << endl;
    cout << "5 for a list sorted by type in ascending order" << endl;
    cout << "6 for a list sorted by type in descending order" << endl;
    int computerOrderChoice;
    cin >> computerOrderChoice;

    computerService.changeSortOrder(computerOrderChoice);
}


void Interface::search()
{
    cout << "Choose one of the following numbers:" << endl;
    cout << "------------------------------------" << endl;
    cout << "0 to go back to main menu" << endl;
    cout << "1 to search for a scientist" << endl;
    cout << "2 to search for a computer" << endl;
    int userChoice2;
    cin >> userChoice2;
    switch (userChoice2)
    {
        case 0:
            break;
        case 1:
            searchScientist();
            break;
        case 2:
            searchComputer();
            break;
        default:
            cout << "Wrong input" << endl;
            search();
            break;
    }

}

void Interface::searchScientist()
{
    cout << "Type in the search term: ";
    string userInput;
    cin.ignore();
    getline(cin, userInput);
    displayScientists(scientistService.searchForScientists(userInput));
}

void Interface::searchComputer()
{
    cout << "Type in the search term: ";
    string userInput;
    cin.ignore();
    getline(cin, userInput);
    //displayComputers(computerService.searchForComputers(userInput));
}

