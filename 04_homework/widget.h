#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include "mywidegt.h"


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void openwindow();
    void closewindow();
    mywidegt myw;
    QPushButton *btn1;
};
#endif // WIDGET_H
