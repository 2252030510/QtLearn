#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *ev);


    bool event(QEvent *e);



signals:

};

#endif // MYLABEL_H
