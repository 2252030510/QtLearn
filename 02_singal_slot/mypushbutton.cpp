#include "mypushbutton.h"
#include <QDebug>
mypushbutton::mypushbutton(QWidget *parent) : QPushButton(parent)
{
    qDebug()<<"我的按钮类的构造调用";
}
mypushbutton::~mypushbutton()
{
    qDebug()<<"我的按钮类的析构调用";
}
