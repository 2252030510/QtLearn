#include "smallwidget.h"
#include "ui_smallwidget.h"

smallwidget::smallwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::smallwidget)
{
    ui->setupUi(this);
}

smallwidget::~smallwidget()
{
    delete ui;
}
