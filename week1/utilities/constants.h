#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <QtSql>
/**
 * This file contains constants that this application uses
 */

namespace constants
{
    const std::string DATA_FILE_NAME = "database.txt";
    const char FILE_DELIMETER = '\t';
    const int YEAR_DIED_DEFAULT_VALUE = 13337;
    const int YEAR_OF_CONSTRUCTION_VALUE = 80083;

    const unsigned int MENU_COMMAND_WIDTH = 15;

    const std::string SELECT_ALL_SCIENTISTS = "SELECT name, sex, yearOfBirth, yearOfDeath FROM Scientists s";
    const std::string SORT_SCIENTIST [6] = {"ORDER BY s.name",
                                            "ORDER BY s.name DESC",
                                            "ORDER BY s.yearOfBirth, name",
                                            "ORDER BY s.yearOfBirth DESC, name",
                                            "ORDER BY s.yearOfDeath, name",
                                            "ORDER BY s.yearOfDeath DESC, name"};
    /*
    const std::string SORT_SCIENTIST_NAME_ASCENDING = "ORDER BY s.name";
    const std::string SORT_SCIENTIST_NAME_DESCENDING = "ORDER BY s.name DESC";
    const std::string SORT_SCIENTIST_YEAR_BORN_ASCENDING = "ORDER BY s.yearOfBirth, name";
    const std::string SORT_SCIENTIST_YEAR_BORN_DESCENDING = "ORDER BY s.yearOfBirth DESC, name";
    const std::string SORT_SCIENTIST_YEAR_DIED_ASCENDING = "ORDER BY s.yearOfDeath, name";
    const std::string SORT_SCIENTIST_YEAR_DIED_DESCENDING = "ORDER BY s.yearOfDeath DESC, name";
    */
    const std::string SELECT_ALL_COMPUTERS = "SELECT name, buildYear, computerType, construct FROM Computers c";
    const std::string SORT_COMPUTER [6] = {"ORDER BY c.name",
                                           "ORDER BY c.name DESC",
                                           "ORDER BY c.buildYear, name",
                                           "ORDER BY c.buildYear DESC, name",
                                           "ORDER BY c.computerType, name",
                                           "ORDER BY c.computerType DESC, name"};
    /*
    const std::string SORT_COMPUTER_NAME_ASCENDING = "ORDER BY c.name";
    const std::string SORT_COMPUTER_NAME_DESCENDING = "ORDER BY c.name DESC";
    const std::string SORT_COMPUTER_BUILD_YEAR_ASCENDING = "ORDER BY c.buildYear, name";
    const std::string SORT_COMPUTER_BUILD_YEAR_DESCENDING = "ORDER BY c.buildYear DESC, name";
    const std::string SORT_COMPUTER_COMPUTER_TYPE_ASCENDING = "ORDER BY c.computerType, name";
    const std::string SORT_COMPUTER_COMPUTER_TYPE_DESCENDING = "ORDER BY c.computerType DESC, name";
    */
    const std::string SORT_RELATION_SCIENTIST_ASCENDING;
    const std::string SORT_RELATION_SCIENTIST_DESCENDING;
    const std::string SORT_RELATION_COMPUTER_ASCENDING;
    const std::string SORT_RELATION_COMPUTER_DESCENDING;
}

#endif // CONSTANTS_H

