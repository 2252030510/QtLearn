#include "mylabel.h"
#include "QDebug"
#include "QMouseEvent"
myLabel::myLabel(QWidget *parent) : QLabel(parent)
{
    setMouseTracking(true);


}


void myLabel::enterEvent(QEvent *event){
    qDebug()<<"enter";
}
void myLabel::leaveEvent(QEvent *event){

    qDebug()<<"leave";
}


void myLabel::mouseMoveEvent(QMouseEvent *ev){
    QString str = QString("x=%1  y%2").arg(ev->x()).arg(ev->y());
    qDebug()<<str;

}

