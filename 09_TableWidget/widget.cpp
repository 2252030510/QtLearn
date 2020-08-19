#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"性别"<<"年龄");
    ui->tableWidget->setRowCount(5);
    ui->tableWidget->setItem(0,0,new QTableWidgetItem("亚瑟"));

    QStringList nameList;
    nameList<<"亚瑟"<<"adsf"<<"a456sf"<<"a4564578dsf"<<"ad789sf";
    QList<QString> sexList;
    sexList <<"nan" <<"nan" <<"nan" <<"nan" <<"nv";
    for(int i=0;i<5;i++){
        int col=0;
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(nameList[i]));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(sexList.at(i)));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString::number(i+18)));


    }









}

Widget::~Widget()
{
    delete ui;
}

