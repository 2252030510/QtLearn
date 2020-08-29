#include "widget.h"
#include "ui_widget.h"
#include "QTimer"
#include "QDebug"
#include "QMouseEvent"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    id1=startTimer(1000);
    id2=startTimer(2000);

    QTimer *timer = new QTimer(this);
    timer->start(500);

    connect(timer,&QTimer::timeout,[=](){
        static int num3=1;

        ui->label_4->setText(QString::number(num3++));
    });


    connect(ui->btn,&QPushButton::clicked,[=](){
        timer->stop();
    });



     ui->label->installEventFilter(this);
}


void Widget::timerEvent(QTimerEvent *ev){
    if(ev->timerId()==id1){
        static int num=1;

        ui->label_2->setText(QString::number(num++));

    }
    if(ev->timerId()==id2){
        static int num2=1;

        ui->label_3->setText(QString::number(num2++));
    }
}



bool Widget::eventFilter(QObject * obj , QEvent * e)
{
    if(obj==ui->label)
    {
        if(e->type()==QEvent::MouseButtonPress){
            QMouseEvent *ev = static_cast<QMouseEvent*>(e);
            QString str = QString( "过滤器中：：鼠标按下了 x = %1   y = %2  globalX = %3 globalY = %4 " ).arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
            qDebug() << str;

            return true;

        }
    }

    return QWidget::eventFilter(obj,e);
}


Widget::~Widget()
{
    delete ui;
}

