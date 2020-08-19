#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->action_2->setIcon(QIcon(":/Image/Luffy.png"));
    ui->actionopen_2->setIcon(QIcon(":/Iamge/LuffyQ.png)"));
}
MainWindow::~MainWindow()
{
    delete ui;
}

