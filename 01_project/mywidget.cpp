#include "mywidget.h"
#include "QPushButton"
myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
//    QPushButton *btn= new QPushButton;
//    btn ->setParent(this);
//    btn->setText("adfasdfadf");
//    btn->show();
    QPushButton *btn = new QPushButton("button",this);
    btn->move(10,10);
    setFixedSize(600,400);
    resize(600,1000);
    setWindowTitle("asdfasdfdsa");


}

myWidget::~myWidget()
{
}

