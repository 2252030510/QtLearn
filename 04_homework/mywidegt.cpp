#include "mywidegt.h"

mywidegt::mywidegt(QWidget *parent) : QWidget(parent)
{
    setFixedSize(400,400);
    setWindowTitle("另一个窗口");

    int a=a+1;
    qDebug()<<a;


}






mywidegt::~mywidegt(){

}
