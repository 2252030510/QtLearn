#include "chooselevelscene.h"
#include "QMenuBar"
#include "QPainter"
#include "mypushbutton.h"
#include "QTimer"
#include "QLabel"
#include "QDebug"
#include "QSound"
ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    //配置选择关卡场景
    this->setFixedSize(320,568);
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    this->setWindowTitle("选择关卡");

     //创建菜单栏
    QMenuBar *bar = menuBar();
    setMenuBar(bar);

    //创建开始菜单
    QMenu *startMenu = bar->addMenu("开始");

    QAction *quitAction = startMenu->addAction("退出");

    //点击退出实现
    connect(quitAction,&QAction::triggered,[=](){
        this->close();
    });


    //选择关卡按钮音效
    QSound *chooseSound = new QSound(":/res/TapButtonSound.wav",this);
    //返回按钮音效
    QSound *backSound = new QSound(":/res/BackButtonSound.wav",this);



    //返回按钮
    MyPushButton *backBtn = new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());

    //点击返回
    connect(backBtn,&MyPushButton::clicked,[=](){
        //播放音效
        backSound->play();

        QTimer::singleShot(500,this,[=](){
            emit this->chooseSceneBack();
        });

    });



    //创建选关按钮
    for(int i = 0;i<20;i++)
    {
        MyPushButton *menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25+i%4*70,130+i/4*70);

        //监听每个按钮
        connect(menuBtn,&MyPushButton::clicked,[=](){
            //播放音效
            chooseSound->play();

            qDebug()<<QString::number(i+1);


            this->hide();
            play = new PlayScene(i+1);

            //设置初始位置
            play->setGeometry(this->geometry());
            play->show();

            connect(play,&PlayScene::chooseSceneBack,[=](){
                this->setGeometry(play->geometry());

                QTimer::singleShot(500,this,[=](){
                    this->show();
                    delete play;
                    play = NULL;
                });

            });

        });


        QLabel *label = new QLabel;
        label->setParent(this);
        label->setText(QString::number(i+1));
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->move(25+i%4*70,130+i/4*70);

        //设置对其方式
        label->setAlignment(Qt::AlignCenter);
        //设置穿透事件
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }


}


void ChooseLevelScene::paintEvent(QPaintEvent *)
{
    //画背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,pix);




    //画背景图标
    pix.load(":/res/Title.png");
    painter.drawPixmap(this->width()*0.5-pix.width()*0.5,30,pix.width(),pix.height(),pix);
};
