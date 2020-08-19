#include "widget.h"
#include "ui_widget.h"
#include "QMovie"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    ui->stackedWidget->setCurrentIndex(1);
//    connect(ui->pushButton_8,&QPushButton::clicked,[=](){
//        ui->stackedWidget->setCurrentIndex(0);
//    });

//    connect(ui->pushButton_9,&QPushButton::clicked,[=](){
//        ui->stackedWidget->setCurrentIndex(1);
//    });
//    connect(ui->pushButton_10,&QPushButton::clicked,[=](){
//        ui->stackedWidget->setCurrentIndex(2);
//    });


//    ui->comboBox->addItem("1");
//    ui->comboBox->addItem("2");
//    connect(ui->pushButton_11,&QPushButton::clicked,[=](){
//        ui->comboBox->setCurrentIndex(1);
//    });
      QLabel *lab = new QLabel(this);
      lab->setPixmap(QPixmap(":/Image/butterfly.png"));
      QLabel *lab2 = new QLabel(this);
      QMovie *movie = new QMovie(":/Image/mario.gif");
      lab2->setMovie(movie);
      movie->start();

}

Widget::~Widget()
{
    delete ui;
}

