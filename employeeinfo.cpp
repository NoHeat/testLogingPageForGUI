#include "employeeinfo.h"
#include "ui_employeeinfo.h"
#include "QSqlDatabase"

EmployeeInfo::EmployeeInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeInfo)
{
    ui->setupUi(this);
    LoginWindow conn;

    if(!conn.connOpen())
    {
        ui->label_sec_Status->setText("Failed to open the database.");
    }
    else
    {
        ui->label_sec_Status->setText("Connected...");
    }

}
EmployeeInfo::~EmployeeInfo()
{
    delete ui;
}

void EmployeeInfo::on_pushButton_clicked()
{

}
