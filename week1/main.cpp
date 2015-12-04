#include "ui/consoleui.h"

#include <QCoreApplication>
#include <iostream>
#include <QtSql>
#include <string>

using namespace std;

int main()
{

    void ScientistRepository();

    //ConsoleUI ui;
    //return ui.start();
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "secondDatabase.sqlite";
    db.setDatabaseName(dbName);

    db.open();

    QSqlQuery query(db);

    if(!db.open())
            cout << "Failed to open the database" << endl;
    else
            cout << "Connected....." << endl;

   /* int born;
    int died;
    string firstName;
    string lastName;
    cout << "First name: ";
    cin >> firstName;
    cout << "Last name: ";
    cin >> lastName;
    cout << "Born: ";
    cin >> born;
    cout << "Died(0 if alive): ";
    cin >> died;
    cout << endl; */

    /* QString qfirstName(firstName.c_str());
    QString qlastName(lastName.c_str());

    QSqlQuery query;
    query.prepare("INSERT INTO people(id, firstName, lastName, born, died)"
                  "VALUES (NULL, ?, ?, ?, ?)");
    query.addBindValue(qfirstName);
    query.addBindValue(qlastName);
    query.addBindValue(born);
    query.addBindValue(died);
    query.exec(); */

    return 0;
}

