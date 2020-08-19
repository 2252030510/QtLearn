#include "widget.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //主窗口属性
    setFixedSize(400,400);
    setWindowTitle("作业");

    //open按钮属性
    btn1= new QPushButton();
    btn1->setParent(this);
    btn1->setText("open");

//    //close属性
//    QPushButton *btn2= new QPushButton();
//    btn2->setParent(this);
//    btn2->move(100,100);
//    btn2->setText("close");



    //open打开窗口
    connect(btn1,&QPushButton::clicked,this,&Widget::openwindow);
    //close关闭窗口
//    connect(btn2,&QPushButton::clicked,this,&Widget::closewindow);



}

void Widget::openwindow(){

    myw.show();
    btn1->setText("close");
    disconnect(btn1,&QPushButton::clicked,this,&Widget::openwindow);
    connect(btn1,&QPushButton::clicked,this,&Widget::closewindow);

}
void Widget::closewindow(){
    myw.close();
    btn1->setText("open");
    disconnect(btn1,&QPushButton::clicked,this,&Widget::closewindow);
    connect(btn1,&QPushButton::clicked,this,&Widget::openwindow);


}
Widget::~Widget()
{
}

