#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->treeWidget->setHeaderLabels(QStringList()<<"英雄"<<"英雄简介");
    QTreeWidgetItem *liItem = new QTreeWidgetItem(QStringList()<<"力量");
    QTreeWidgetItem *miItem = new QTreeWidgetItem(QStringList()<<"敏捷");
    QTreeWidgetItem *zhItem = new QTreeWidgetItem(QStringList()<<"智力");
    ui->treeWidget->addTopLevelItem(liItem);
    ui->treeWidget->addTopLevelItem(miItem);
    ui->treeWidget->addTopLevelItem(zhItem);

    QStringList heroL1;
    heroL1 << "刚被猪" << "前排坦克，能在吸收伤害的同时造成可观的范围输出";
    QTreeWidgetItem *l1 = new QTreeWidgetItem(heroL1);
    liItem->addChild(l1);

}

Widget::~Widget()
{
    delete ui;
}

