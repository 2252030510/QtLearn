#include "playscene.h"
#include "QDebug"
#include "QMenuBar"
#include "QPainter"
#include "mypushbutton.h"
#include "QTimer"
#include "QLabel"
#include "mycoin.h"
#include "dataconfig.h"
#include "QPropertyAnimation"
#include "QSound"
PlayScene::PlayScene(int levelNum)
{
    QString str = QString("进入了：%1 关").arg(levelNum);
    qDebug()<<str;
    this->levelIndex = levelNum;




    this->setFixedSize(320,568);
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    QString str2= QString("第 %1 关").arg(levelNum);
    this->setWindowTitle(str2);

    QLabel *label = new QLabel(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPixelSize(20);
    label->setFont(font);
    label->setText(str2);
    label->setGeometry(30,this->height()-50,120,50);


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

   //返回按钮音效
   QSound *backSound = new QSound(":/res/BackButtonSound.wav",this);
   //翻金币音效
   QSound *flipSound = new QSound(":/res/ConFlipSound.wav",this);
   //胜利按钮音效
   QSound *winSound = new QSound(":/res/LevelWinSound.wav",this);



   //返回按钮
   MyPushButton *backBtn = new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
   backBtn->setParent(this);
   backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());

   //点击返回
   connect(backBtn,&MyPushButton::clicked,[=](){
       //播放音效
       backSound->play();

       QTimer::singleShot(300,this,[=](){
           emit this->chooseSceneBack();
       });

   });

   dataConfig config;
   for(int i=0;i<4;i++)
   {
       for(int j=0;j<4;j++)
       {
           this->gameArray[i][j] = config.mData[this->levelIndex][i][j];
       }
   }

       QLabel* winLabel = new QLabel;
       QPixmap tmpPix;
       tmpPix.load(":/res/LevelCompletedDialogBg.png");
       winLabel->setGeometry(0,0,tmpPix.width(),tmpPix.height());
       winLabel->setPixmap(tmpPix);
       winLabel->setParent(this);
       winLabel->move( (this->width() - tmpPix.width())*0.5 , -tmpPix.height());




   //创建金币的背景图片
       for(int i = 0 ; i < 4;i++)
       {
           for(int j = 0 ; j < 4; j++)
           {
              //绘制背景图片
               QPixmap pix = QPixmap(":/res/BoardNode.png");
               QLabel* label = new QLabel;
               label->setGeometry(0,0,pix.width(),pix.height());
               label->setPixmap(pix);
               label->setParent(this);
               label->move(57 + i*50,200+j*50);


                //创建金币
               QString str;
               if(this->gameArray[i][j]==1)
               {
                   //显示金币
                   str = ":/res/Coin0001.png";
               }
               else
               {
                   str = ":/res/Coin0008.png";
               }
               MyCoin *coin =new MyCoin(str);
               coin->setParent(this);
               coin->move(59 + i*50,204+j*50);
               //给金币赋值
               coin->posX=i;
               coin->posy=j;
               coin->flag = this->gameArray[i][j]; //1正 0反
               //将金币放入到二维数组中
               coinBtn[i][j]= coin;

               //点击金币进行翻转
               connect(coin,&MyCoin::clicked,[=](){
                   //播放音效
                   flipSound->play();

                   coin->changeFlag();
                   this->gameArray[i][j]=this->gameArray[i][j]==0?1:0;
                   for (int i = 0;i<4;i++) {
                       for (int j=0;j<4;j++) {
                           coinBtn[i][j]->isWin = true;

                       }
                   }



                   //延时翻转
                   QTimer::singleShot(300,this,[=](){
                       //翻转周围硬币
                       //右侧
                       if(coin->posX+1<=3)
                       {
                           coinBtn[coin->posX+1][coin->posy]->changeFlag();
                           this->gameArray[coin->posX+1][coin->posy]=this->gameArray[coin->posX+1][coin->posy]==0?1:0;

                       }
                       //左侧
                       if(coin->posX-1>=0)
                       {
                           coinBtn[coin->posX-1][coin->posy]->changeFlag();
                           this->gameArray[coin->posX-1][coin->posy]=this->gameArray[coin->posX-1][coin->posy]==0?1:0;
                       }
                       //上侧
                       if(coin->posy+1<=3)
                       {
                           coinBtn[coin->posX][coin->posy+1]->changeFlag();
                           this->gameArray[coin->posX][coin->posy+1]=this->gameArray[coin->posX][coin->posy+1]==0?1:0;
                       }
                       //下侧
                       if(coin->posy-1>=0)
                       {
                           coinBtn[coin->posX][coin->posy-1]->changeFlag();
                           this->gameArray[coin->posX][coin->posy-1]=this->gameArray[coin->posX][coin->posy-1]==0?1:0;
                       }


                       for (int i = 0;i<4;i++) {
                           for (int j=0;j<4;j++) {
                               coinBtn[i][j]->isWin = false;

                           }
                       }


                       //判断是否胜利
                       this->isWin=true;
                       for (int i = 0;i<4;i++) {
                           for (int j=0;j<4;j++) {
                               if(coinBtn[i][j]->flag==false)
                               {
                                   this->isWin=false;
                                   break;
                               }
                           }
                       }





                       if(this->isWin==true)
                       {
                           //胜利了
                           winSound->play();

                           for (int i = 0;i<4;i++) {
                               for (int j=0;j<4;j++) {
                                   coinBtn[i][j]->isWin = true;

                               }
                           }



                           QPropertyAnimation * animation1 =  new QPropertyAnimation(winLabel,"geometry");
                           animation1->setDuration(1000);
                           animation1->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));
                           animation1->setEndValue(QRect(winLabel->x(),winLabel->y()+114,winLabel->width(),winLabel->height()));
                           animation1->setEasingCurve(QEasingCurve::OutBounce);
                           animation1->start();


                       }


                   });
               });

           }
       }

}



void PlayScene::paintEvent(QPaintEvent *)
{
    //画背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,pix);




    //画背景图标
    pix.load(":/res/Title.png");
    painter.drawPixmap(this->width()*0.5-pix.width()*0.5,30,pix.width(),pix.height(),pix);
}

