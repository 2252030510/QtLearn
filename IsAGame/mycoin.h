#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include "QTimer"
class MyCoin : public QPushButton
{
    Q_OBJECT
public:
//    explicit MyCoin(QWidget *parent = nullptr);
    //传入币的路径
    MyCoin(QString btnImg);

    //金币的属性
    int posX;
    int posy;
    bool flag;


    //改变标志的方法
    void changeFlag();
    QTimer *timer1;
    QTimer *timer2;
    int min = 1;
    int max = 8;

    bool isAnimation = false;

    void mousePressEvent(QMouseEvent *e);

    bool isWin = false;//胜利标志
signals:

};

#endif // MYCOIN_H
