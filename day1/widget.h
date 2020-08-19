#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include "widget2.h"
class Widget : public QWidget
{
  Q_OBJECT

public:
  Widget(QWidget *parent = 0);
  ~Widget();
  QPushButton * btn;
  Widget2 w2;
  void showW2();
  void hideW2();
};

#endif // WIDGET_H
