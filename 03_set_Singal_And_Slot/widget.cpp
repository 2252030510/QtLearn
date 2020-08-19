#include "widget.h"
#include "./ui_widget.h"
#include "QPushButton"
#include "QDebug"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    //创建老师对象
    this->zt =new Teancher(this);
        //创建学生对象
    this->st = new Student(this);

    QPushButton *btn = new QPushButton("下课",this);
    this->resize(600,400);
    //调用下课函数
    //classIsOver();

    void (Teancher:: *teacherSignal)(QString) = &Teancher::hungary;
    void (Student:: *stuentSlot)(QString) = &Student::treat;
    connect(zt,teacherSignal,st,stuentSlot);

    connect(btn,&QPushButton::clicked,this,&Widget::classIsOver);
//    connect(btn,&QPushButton::clicked,zt,teacherSignal);
    //断开信号
//    disconnect(zt,teacherSignal,st,stuentSlot);

    //connect(zt,&Teancher::hungary,st,&Student::treat);

//    [btn](){
//      btn->setText("aaa");
//    }();

//    QPushButton *mybtn  = new QPushButton(this);
//    QPushButton *mybtn2 = new QPushButton(this);
//    mybtn2->move (100,100);
//    int m=10;
//    connect (mybtn,&QPushButton::clicked,this,[m]()mutable {m=100+10;qDebug()<<m;});
//    connect (mybtn2,&QPushButton::clicked,this,[=](){qDebug()<<m;});

      QPushButton *btn3 = new QPushButton("关闭",this);
      btn3->move(100,0);
//    connect(btn3,&QPushButton::clicked,this,&QPushButton::close);
      connect(btn3,&QPushButton::clicked,this,[=](){
          this->close();
          emit zt->hungary("宫爆鸡丁");
      });
}

void Widget::classIsOver()
{
//    emit zt->hungary();
      emit zt->hungary("宫爆鸡丁");
}


Widget::~Widget()
{
    delete ui;
}

