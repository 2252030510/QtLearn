#include "mywidget.h"
#include "QPushButton"
#include "mypushbutton.h"
#include "QDebug"
myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
//    QPushButton *btn= new QPushButton;
//    btn ->setParent(this);
//    btn->setText("adfasdfadf");
//    btn->show();
//主窗口属性
    setFixedSize(600,400);
    resize(600,1000);
    setWindowTitle("第一个窗口");


//第一个按钮属性
    QPushButton *btn = new QPushButton("button",this);
    btn->move(10,10);


//自己创建的按钮的属性
    mypushbutton *mybtn=new mypushbutton;
    mybtn->setText("我自己的按钮");
    mybtn->move(200,0);
    mybtn->setParent(this);

    //信号和槽处理
    connect(mybtn,&QPushButton::clicked,this,&myWidget::close);
}

myWidget::~myWidget()
{

}

