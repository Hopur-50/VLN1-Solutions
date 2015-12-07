#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <QtSql>
/**
 * This file contains constants that this application uses
 */

namespace constants {
    const std::string DATA_FILE_NAME = "database.txt";
    const char FILE_DELIMETER = '\t';
    const int YEAR_DIED_DEFAULT_VALUE = 13337;
    const int YEAR_OF_CONSTRUCTION_VALUE = 80083;

    const unsigned int MENU_COMMAND_WIDTH = 15;

    const QString SELECT_ALL_SCIENTISTS = "SELECT name, gender, yearOfBirth, yearOfDeath FROM Scientists s";
    const QString SORT_SCIENTIST_NAME_ASCENDING = "ORDER BY s.name";
    const QString SORT_SCIENTIST_NAME_DESCENDING = "ORDER BY s.name DESC";
    const QString SORT_SCIENTIST_YEAR_BORN_ASCENDING = "ORDER BY s.yearOfBirth, name";
    const QString SORT_SCIENTIST_YEAR_BORN_DESCENDING = "ORDER BY s.yearOfBirth DESC, name";
    const QString SORT_SCIENTIST_YEAR_DIED_ASCENDING = "ORDER BY s.yearOfDeath, name";
    const QString SORT_SCIENTIST_YEAR_DIED_DESCENDING = "ORDER BY s.yearOfDeath DESC, name";

    const QString SELECT_ALL_COMPUTERS = "SELECT name, buildYear, computerType, construct FROM Computers c";
    const QString SORT_COMPUTER_NAME_ASCENDING = "ORDER BY c.name";
    const QString SORT_COMPUTER_NAME_DESCENDING = "ORDER BY c.name DESC";
    const QString SORT_COMPUTER_BUILD_YEAR_ASCENDING = "ORDER BY c.buildYear, name";
    const QString SORT_COMPUTER_BUILD_YEAR_DESCENDING = "ORDER BY c.buildYear DESC, name";
    const QString SORT_COMPUTER_COMPUTER_TYPE_ASCENDING = "ORDER BY c.computerType, name";
    const QString SORT_COMPUTER_COMPUTER_TYPE_DESCENDING = "ORDER BY c.computerType DESC, name";
}

#endif // CONSTANTS_H

