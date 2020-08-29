#include "mainscenery.h"
#include "ui_mainscenery.h"
#include "QPaintEvent"
#include "QPainter"
#include "QTimer"
mainScenery::mainScenery(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainScenery)
{
    ui->setupUi(this);
    //主窗口属性

    this->setFixedSize(320,588);
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));

    this->setWindowTitle("翻金币");


    //添加开始按钮
    MyPushButton *startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.7);

    //弹起画面
    connect(startBtn,&MyPushButton::clicked,[=](){
        startBtn->zoom1(); //向下跳跃
        startBtn->zoom2(); //向上跳跃

     });
    //0.5进入选关界面
    QTimer::singleShot(500, this,[=](){
         this->hide();
         chooseScene->show();
    });



    connect(chooseScene,&ChooseLevelScene::chooseSceneBack,[=](){
                    this->show();
                });


}




void mainScenery::paintEvent(QPaintEvent *){

    //定义画家
    QPainter painter(this);
    QPixmap pix;

    //主界面
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //大标题
    pix.load(":/res/Title.png");
    painter.drawPixmap(30,90,pix);



}

mainScenery::~mainScenery()
{
    delete ui;
}

