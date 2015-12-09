
#include "ui/interface.h"
#include <QCoreApplication>
#include <iostream>
#include <QtSql>
#include <string>
using namespace std;

int main()
{
    Interface message;

    int userChoice;
    do
    {
        message.menu(userChoice);
    }while(userChoice!=5);

    return 0;
}

