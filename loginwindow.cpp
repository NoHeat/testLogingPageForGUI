#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "QSqlDatabase"


LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);


    if(!connOpen())
    {
        ui->status->setText("Failed to open the database");
    }
    else
    {
        ui->status->setText("Connected....");


    }


}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_clicked()
{
    QString username, password;
    username = ui->lineEditUsername->text();
    password = ui->lineEditPassWord->text();

    if(!connOpen())
    {
        qDebug() << "Failed to open the database";
        return;
    }
    connOpen();
    QSqlQuery qry;
    qry.prepare("select * from employeeinfo where username='"+username+"' and password='"+password+"'");
    if(qry.exec())
    {
           int count = 0;
           while(qry.next())
           {
               count++;
           }
           if(count == 1)
           {
               /*The reason for hiding the new window is so that if the user has the right authentication information the
                * they will go directly to the other page. Otherwise they will remain in the same place until they can
                * validate their identity*/

               ui->status->setText("username and password is correct");
               connClose(); //why don't I need mydb.connClose()? This is because the method is in the same class
               this->hide(); //this is to hide the current page which is login.ui
               EmployeeInfo employeeinfo;
               employeeinfo.setModal(true);
               employeeinfo.exec();

           }
           if(count > 1)
           {
               ui->status->setText("Duplicated username and password");
           }
           if(count < 1)
           {
               ui->status->setText("Username and password is not correct");
           }

    }


}


