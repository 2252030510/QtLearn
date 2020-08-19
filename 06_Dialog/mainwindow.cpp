#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDialog"
#include "QDebug"
#include "QMessageBox"
#include "QColorDialog"
#include "QFileDialog"
#include "QFontDialog"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionnew,&QAction::triggered,[=](){
        //模态对话框
//        QDialog dlg(this);
//        dlg.exec();

//         qDebug()<<"asdf";

//           QDialog *dlg2=new QDialog(this);
//           //防止内存溢出
//           dlg2->setAttribute(Qt::WA_DeleteOnClose);
//           dlg2->show();

        //对话框
//        QMessageBox::critical(this,"critial","错误");
//        QMessageBox::information(this,"信息","内容");
//        QMessageBox *qmb=new QMessageBox;
//        qmb->setParent(this);
//        qmb->resize(100,100);

//        if(QMessageBox::Save==(qmb->question(this,"标题","内容",QMessageBox::Save|QMessageBox::Cancel)))
//        {
//           qDebug()<<"baocun";
//        }
//                else
//        {
//            qDebug()<<"quxiao";
//        }
//           QMessageBox::warning(this,"biaoti","neirong ",QMessageBox::Open,QMessageBox::Cancel);



           //颜色对话框
//           QColor color=QColorDialog::getColor(QColor(255,0,0));
//           qDebug()<<color.red()<<color.green()<<color.blue();

            //文件对话框
//            QString str =QFileDialog::getOpenFileName(this,"文件","C://","(*.txt)");
//            qDebug()<<str;


    });






}

MainWindow::~MainWindow()
{
    delete ui;
}

