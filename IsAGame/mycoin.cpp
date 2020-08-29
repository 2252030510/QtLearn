#include "mycoin.h"
#include "QDebug"
//MyCoin::MyCoin(QWidget *parent) : QPushButton(parent)
//{

//}


MyCoin::MyCoin(QString btnImg)
{
    QPixmap pix;
    bool ret = pix.load(btnImg);
    if(!ret)
    {
        QString str = QString("图片 %1 加载失败").arg(btnImg);
        qDebug()<<str;
       return;


    }

        this->setFixedSize( pix.width(), pix.height() );
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));



        //初始化定时器
        timer1 = new QTimer(this);
        timer2 = new QTimer(this);

        //银币翻金币
        connect(timer1,&QTimer::timeout,[=](){
            QPixmap pix;
            QString str = QString(":/res/Coin000%1").arg(this->min++);
            pix.load(str);

            this->setFixedSize( pix.width(), pix.height() );
            this->setStyleSheet("QPushButton{border:0px;}");
            this->setIcon(pix);
            this->setIconSize(QSize(pix.width(),pix.height()));

            if(this->min>this->max)
            {
                this->min = 1;
                isAnimation = false;
                timer1->stop();
            }
        });


        //金币翻银币
        connect(timer2,&QTimer::timeout,[=](){
            QPixmap pix;
            QString str = QString(":/res/Coin000%1").arg(this->max--);
            pix.load(str);

            this->setFixedSize( pix.width(), pix.height() );
            this->setStyleSheet("QPushButton{border:0px;}");
            this->setIcon(pix);
            this->setIconSize(QSize(pix.width(),pix.height()));

            if(this->max<this->min)
            {
                this->max = 8;
                isAnimation = false;
                timer2->stop();
            }
        });
}


void MyCoin:: mousePressEvent(QMouseEvent *e)
{
    if(this->isAnimation||this->isWin)
    {
        return;

    }
    else
    {
        QPushButton::mousePressEvent(e);
    }
}



//改变正反面的方法

void MyCoin::changeFlag()
{
    if(this->flag)
    {
        timer1->start(30);
        isAnimation = true;

        this->flag = false;

    }
    else
    {
        timer2->start(30);
        isAnimation = true;
        this->flag = true;
    }
}
