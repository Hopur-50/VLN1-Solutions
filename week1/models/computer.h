#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>

/*
enum computerType{

};*/

class Computer
{
public:
    Computer(std::string name, std::string type, bool wasItConstructed);
    Computer(std::string name, std::string type, bool wasItConstructed, int yearOfConstruction);

    std::string getName() const;
    std::string getType() const;
    //enum computerType getType() const;
    int getYearOfConstruction() const;
    bool getWasItConstructed()const;


private:
    std::string name;
    std::string type;
    int yearOfConstruction;
    bool wasItConstructed;

};

#endif // COMPUTER_H
