#include "mylabel.h"
#include "QMouseEvent"
#include "QDebug"

myLabel::myLabel(QWidget *parent) : QLabel(parent)
{

}


void myLabel::mousePressEvent(QMouseEvent *ev){
    QString str = QString("x:%1  y=%2").arg(ev->x()).arg(ev->y());
    qDebug()<<str;


}

bool myLabel::event(QEvent *e){
    if(e->type()==QEvent::MouseButtonPress){
        QMouseEvent *ev = static_cast<QMouseEvent*>(e);
        QString str = QString( "Event函数中：：鼠标按下了 x = %1   y = %2  globalX = %3 globalY = %4 " ).arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;

        return true;

    }

    return QLabel::event(e);


}


