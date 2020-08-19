#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QListWidgetItem"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    ui->rbw->setChecked(true);

//    connect(ui->rbw,&QRadioButton::clicked,[](){
//        qDebug()<<"女";
//    });

      QListWidgetItem *item = new QListWidgetItem("chuhe") ;
      ui->listWidget->addItem(item);
      item->setTextAlignment(Qt::AlignHCenter);
      QStringList list;
      list<<"abcde"<<"fghij"<<"klmno"<<"pqwxyz";
      ui->listWidget->addItems(list);


}

MainWindow::~MainWindow()
{
    delete ui;
}

