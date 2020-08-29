#include "mainscene.h"
#include "ui_mainscene.h"
#include "QPainter"
#include "QTimer"
#include "mypushbutton.h"
#include "QSound"
MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);


    //配置主场景

    //设置固定大小
    setFixedSize(320,568);

    //设置图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    //设置标题
     setWindowTitle("翻金币主场景");

     //退出按钮实现
     connect(ui->actionquit,&QAction::triggered,[=](){
         this->close();
     });


    //音效
    QSound *startSound = new QSound(":/res/TapButtonSound.wav",this);
//    startSound->setLoops(-1); -1为无限循环
//    startSound->play();
    //开始按钮
    MyPushButton *startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.7);


    //实例化选择关卡的场景
    chooseScene = new ChooseLevelScene;

    //监听选择关卡的返回按钮的信号
    connect(chooseScene,&ChooseLevelScene::chooseSceneBack,this,[=](){
        this->setGeometry(chooseScene->geometry());
        chooseScene->hide();
        this->show();
    });


    connect(startBtn,&MyPushButton::clicked,[=](){
        //播放音效
        startSound->play();
        startBtn->zoom1();
        startBtn->zoom2();

        //延时进入
        QTimer::singleShot(500,this,[=](){
            //设置场景位置
            chooseScene->setGeometry(this->geometry());
            //进入到选择关卡中
            //自身隐藏
            this->hide();
            //显示关卡
            chooseScene->show();




        });


    });


}


void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,pix);


    //画背景图标
    pix.load(":/res/Title.png");
    painter.drawPixmap(this->width()*0.5-pix.width()*0.5,30,pix.width(),pix.height(),pix);

}



MainScene::~MainScene()
{
    delete ui;
}

