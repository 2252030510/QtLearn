#include "widget.h"

Widget::Widget(QWidget *parent)
  : QWidget(parent)
{
  btn=new QPushButton("open",this);
  connect(btn,&QPushButton::clicked,this,&Widget::showW2);
}

Widget::~Widget()
{

}

void Widget::showW2()
{
  w2.show();
  disconnect(btn,&QPushButton::clicked,this,&Widget::showW2);
  btn->setText("close");
  connect(btn,&QPushButton::clicked,this,&Widget::hideW2);
}

void Widget::hideW2()
{
  w2.close();
  disconnect(btn,&QPushButton::clicked,this,&Widget::hideW2);
  btn->setText("open");
  connect(btn,&QPushButton::clicked,this,&Widget::showW2);
}

