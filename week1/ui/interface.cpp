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

void Interface::menu(int& userChoice)//displays the initial menu for user
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
        case 5:
            break;
        default:
            cout << "Wrong input" << endl;
            break;
    }
}

void Interface::add()
{
    cout << "Choose one of the following numbers" << endl;
    cout << "-----------------------------------" << endl;
    cout << "1 to add a scientist" << endl;
    cout << "2 to add a computer" << endl;
    cout << "3 to add a relation" << endl;

    int userChoice2;
    cin >> userChoice2;

    switch (userChoice2)
    {
        case 1:
            addScientist();
            break;
        case 2:
            addComputer();
            break;
        case 3:
            addRelation();
            break;
        default:
            cout << "Wrong input" << endl;
            break;
    }
}

bool Interface::addScientist()
{
    cout << "To add a scientist, type in:" << endl;
    cout << "Name,sex,yearBorn,yearDied (optional)" << endl;
    cout << "Comma separated like in the example above." << endl;
    cout << "If you would like to go back to the main menu, please type: back" << endl;
    cout << "Input: ";
    string data;
    getline(cin, data);
    vector<string> fields = utils::splitString(data, ',');

    if (fields.size() > 2 && fields.size() < 5)
    {
        string name = fields.at(0);

        enum sexType sex;
        if (fields.at(1) == "male" || fields.at(1) == " male") //Because EVERYONE writes a space after a comma.
        {
            sex = sexType::male;
        }
        else
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
    cout << "To add a computer, type in:" << endl;
    cout << "Name,type,wasItConstructed?(Y/N),yearOfConstruction (optional)" << endl;
    cout << "Comma separated like in the example above." << endl;
    cout << "If you would like to go back to the main menu, please type: back" << endl;
    cout << "Input: ";
    string data;
    getline(cin, data);
    vector<string> fields = utils::splitString(data, ',');

    if (fields.size() > 2 && fields.size() < 5)
    {
        string name = fields.at(0);
        string type = fields.at(1);
        bool wasItConstructed;
        if(fields.at(2) == "Y" || fields.at(2) == "y")
        {
            wasItConstructed = true;
        }else if(fields.at(2) == "N" || fields.at(2) == "n")
        {
            wasItConstructed = false;
        }else
        {
            return false;
        }
        if (fields.size() == 3)
        {
            cout << "Successfully added a computer" << endl;
            return scientistService.addComputer(Computer(name, type, wasItConstructed));
        }
        else
        {
            int yearOfConstruction = utils::stringToInt(fields.at(3));
            cout << "Successfully added a computer" << endl;
            return scientistService.addComputer(Computer(name, type, wasItConstructed, yearOfConstruction));
        }
    }

    cout << "There was an error in your input." << endl;
    return false;
}

bool Interface::addRelation()
{
    cout << "To add a relation, type in:" << endl;
    cout << "scientist,computer" << endl;
    cout << "Comma separated like in the example above." << endl;
    cout << "If you would like to go back to the main menu, please type: back" << endl;
    cout << "Input: ";
    string data;
    getline(cin, data);
    vector<string> fields = utils::splitString(data, ',');

    if (fields.size() == 2)
    {
        string scientist = fields.at(0);
        string computer = fields.at(1);
        cout << "Successfully added a relation" << endl;
        return(scientistService.addRelation(scientist, computer));
    }

    cout << "There was an error in your input." << endl;
    return false;
}

void Interface::display() //Prints from the vector
{
    cout << "Choose a number from the menu" << endl;
    cout << "-----------------------------" << endl;
    cout << "1 to display scientists" << endl;
    cout << "2 to display computers" << endl;
    cout << "3 to display relations" << endl;
    int userChoice2;
    cin >> userChoice2;
    switch (userChoice2) {
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
        break;
    }
}

void Interface::displayAllScientists()
{
    std::string orderBy = "DELETA ÞESSU";
    vector<Scientist> scientists = scientistService.getAllScientists(orderBy);
    displayScientists(scientists);
    cout << '\n';
}

void Interface::displayAllComputers()
{
    vector<Computer> computers = scientistService.getAllComputers();
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

    cout << setw(20) << std::left << "Name:"
         << setw(8)  << std::left << "Sex:"
         << setw(12) << std::left << "Year born:"
         << setw(12) << std::left << "Year died:" << endl;

    for (unsigned int i = 0; i < scientists.size(); i++)
    {
        string scientistSex = (scientists.at(i).getSex() == sexType::male) ? "Male" : "Female";

        int yearDied = scientists.at(i).getYearDied();
        string died = (yearDied == constants::YEAR_DIED_DEFAULT_VALUE) ? "Alive" : utils::intToString(yearDied);

        cout << setw(20) << std::left << scientists.at(i).getName()
             << setw(8) << std::left << scientistSex
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

    cout << setw(20) << std::left << "Name:"
         << setw(8)  << std::left << "Type:"
         << setw(12) << std::left << "Was it built?:"
         << setw(12) << std::left << "Year built:" << endl;

    for (unsigned int i = 0; i < computers.size(); i++)
    {
        string computerType = computers.at(i).getType();

        int yearOfConstruction = computers.at(i).getYearOfConstruction();
        //Þarf að laga built um leið og veit hvernig það er storað
        string built = (yearOfConstruction == constants::YEAR_DIED_DEFAULT_VALUE) ? "Not built" : utils::intToString(yearOfConstruction);

        cout << setw(20) << std::left << computers.at(i).getName()
             << setw(8) << std::left << computerType
             << setw(12) << std::left << computers.at(i).getYearOfConstruction()
             << setw(12) << std::left << built << endl;
    }
}

void Interface::displayRelations()
{
    cout << "Choose one of the following numbers:" << endl;
    cout << "------------------------- ---------------" << endl;
    cout << "1 to display all relations to a scientist" << endl;
    cout << "2 to display all relations to a computer" << endl;
    int userChoice3;
    cin >> userChoice3;
    switch (userChoice3)
    {
        case 1:
            displayScientistRelations();
            break;
        case 2:
            displayComputerRelations();
            break;
        default:
            cout << "Wrong input" << endl;
            break;
    }
}

void Interface::displayScientistRelations()
{
    cout << "Enter the scientist whose computers you would like to see: ";
    string input;
    cin >> input;
    vector<Computer> computers = scientistService.getRelatedComputers(input);
    displayComputers(computers);
    cout << '\n';
}

void Interface::displayComputerRelations()
{
    cout << "Enter the computer whose scientists you would like to see: ";
    string input;
    cin >> input;
    vector<Scientist> scientists = scientistService.getRelatedScientists(input);
    displayScientists(scientists);
    cout << '\n';
}

void Interface::selectOrder()
{
    int userChoice2;
    cout << "Which order would you like to retrieve list items in?" << endl;
    cout << "Choose one of the following numbers:" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "1 for a list of last names in alphabetical order" << endl;
    cout << "2 for a list of first names in alphabetical order" << endl;
    cout << "3 for a list sorted by date of birth in ascending order" << endl;
    cout << "4 for a list sorted by date of birth in descending order" << endl;
    cin >> userChoice2;

    if(userChoice2 > 0 && userChoice2 < 5)
    {
        scientistService.changeSortOrder(userChoice2);
    }
    else
    {
        cout << "Wrong input" << endl;
        selectOrder();
    }
}

void Interface::search()
{
    cout << "Choose one of the following numbers:" << endl;
    cout << "------------------------------------" << endl;
    cout << "1 to search for a scientist" << endl;
    cout << "2 to search for a computer" << endl;
    int userChoice2;
    cin >> userChoice2;
    switch (userChoice2)
    {
        case 1:
            searchScientist();
            break;
        case 2:
            searchComputer();
            break;
        default:
            cout << "Wrong input" << endl;
            break;
    }

}

void Interface::searchScientist()
{
    cout << "Type in the search term: ";
    string userInput;
    cin >> userInput;
    displayScientists(scientistService.searchForScientists(userInput));
}

void Interface::searchComputer()
{
    cout << "Type in the search term: ";
    string userInput;
    cin >> userInput;
    displayComputers(scientistService.searchForComputers(userInput));
}

