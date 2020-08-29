#include "widget.h"
#include "ui_widget.h"
#include "QFileDialog"
#include "QFile"
#include "QTextCodec"
#include "QFileInfo"
#include "QDebug"
#include "QDateTime"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    connect(ui->pushButton,&QPushButton::clicked,[=](){
//        QString path=QFileDialog::getOpenFileName(this,"打开文件","D:/zm");
//        ui->lineEdit->setText(path);

//        QTextCodec *codec = QTextCodec::codecForName("gbk");

//        QFile file(path);
//        file.open(QIODevice::ReadOnly);
//        QByteArray array = file.readAll();
//        QByteArray array = file.readLine();
//        ui->textEdit->setText(array);
//        file.close();

//        file.open(QIODevice::Append);
//        file.write("aaaaaaaaa");
//        file.close();
//    });


    connect(ui->pushButton,&QPushButton::clicked,[=](){
        QString path=QFileDialog::getOpenFileName(this,"打开文件","D:/");
        ui->lineEdit->setText(path);

        QFile file(path);
        file.open(QIODevice::ReadOnly);
        QByteArray array = file.readAll();

        QTextCodec *code = QTextCodec::codecForName("gbk");


//        ui->textEdit->setText(code->toUnicode( array));
        ui->textEdit->setText(array);


        file.close();

//        file.open(QIODevice::Append);
//        file.write("a");
//        file.close();

        QFileInfo info(path);
        qDebug()<<info.created().toString("yyyy/MM/dd hh/mm/ss");
    });




}

Widget::~Widget()
{
    delete ui;
}

