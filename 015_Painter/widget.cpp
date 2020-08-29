#include "widget.h"
#include "ui_widget.h"
#include "QPainter"
#include "QPushButton"
#include "QDebug"
#include "QTimer"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    QTimer *timer = new QTimer(this);
    timer->start(100);
    connect(timer,&QTimer::timeout,[=](){
        pox+=20;
        update();
        qDebug()<<"1";
    });
}



void Widget::paintEvent(QPaintEvent *event){

//    QPainter painter(this);


//    QPen pen(QColor(255,0,0));
//    pen.setWidth(3);
//    pen.setStyle(Qt::DotLine);
//    painter.setPen(pen);

//    QBrush brush(Qt::green);
//    brush.setStyle(Qt::Dense6Pattern);
//    painter.setBrush(brush);



//    painter.drawLine(0,0,100,100);
//    painter.drawEllipse(100,100,50,100);
//    painter.drawRect(20,20,50,50);
//    painter.drawText(10,200,100,50,100,"hhhh");








//    QPainter painter(this);

//    painter.drawEllipse(QPoint(100,50),50,50);
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.drawEllipse(QPoint(200,50),50,50);

//       QPainter painter(this);
//       painter.drawRect(20,20,50,50);
//       painter.translate(100,0);

//       painter.save();


//       painter.drawRect(20,20,50,50);
//       painter.translate(100,0);
//       painter.restore();
//       painter.drawRect(20,20,50,50);



         QPainter painter(this);
         if(pox>this->width()){
            pox=0;
         }else{
         painter.drawPixmap(pox,0,QPixmap(":/Image/Luffy.png"));

         }
}

Widget::~Widget()
{
    delete ui;
}

