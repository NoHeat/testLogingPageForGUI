#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "employeeinfo.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT
public:
    QSqlDatabase mydb;
    void connClose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connOpen()
    {
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/sqlite3/employeeinfo.sqlite");

        if(!mydb.open())
        {
            qDebug() << ("Failed to open the database"); //Will removing the ( ) make a dif?
            return false;
        }
        else
        {
            qDebug() << ("Connected...");
            return true;
        }
    }
public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();
//making functions public make it reusable from other forms and windows

private slots:
    void on_pushButton_clicked();

private:
    Ui::LoginWindow *ui;


};

#endif // LOGINWINDOW_H
