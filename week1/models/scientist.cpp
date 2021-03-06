#include "models/scientist.h"
#include "utilities/utils.h"
#include "utilities/constants.h"

using namespace std;

Scientist::Scientist(string name, enum sexType sex, int yearBorn)
{
    this->name = name;
    this->sex = sex;
    this->yearBorn = yearBorn;
    this->yearDied = constants::YEAR_DIED_DEFAULT_VALUE;  //If the computer scientist is alive.
}

Scientist::Scientist(string name, enum sexType sex, int yearBorn, int yearDied)
{
    this->name = name;
    this->sex = sex;
    this->yearBorn = yearBorn;
    this->yearDied = yearDied;                          //If the computer scientist has passed away.
}

std::string Scientist::getName() const
{
    return name;
}

enum sexType Scientist::getSex() const
{
    return sex;
}

int Scientist::getYearBorn() const
{
    return yearBorn;
}

int Scientist::getYearDied() const
{
    return yearDied;
}
