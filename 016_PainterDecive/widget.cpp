#include "widget.h"
#include "ui_widget.h"
#include "QPainter"
#include "QPicture"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    QPixmap pix(300,300);
//    pix.fill(Qt::transparent);


//    QPainter painter(&pix);
//    painter.setPen(Qt::red);
//    painter.drawEllipse(QPoint(150,150),100,100);

//    pix.save("E:/pix.png");


      QPicture pic;
      QPainter painter;
      painter.begin(&pic);
      painter.setPen(Qt::cyan);
      painter.drawEllipse(QPoint(150,150),100,100);

      painter.end();

      pic.save("E:/pic.hh");




}

void Widget::paintEvent(QPaintEvent *)
{




    QPainter painter(this);
    QPicture pic;
    pic.load("E:/pic.hh");
    painter.drawPicture(0,0,pic);

}



Widget::~Widget()
{
    delete ui;
}

