#include "playscene.h"
#include "mypushbutton.h"
#include "chooselevelscene.h"
PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
{


    connect(menuBtn,&MyPushButton::clicked,[=](){
               // qDebug() << "select: " << i;
                if(pScene == NULL)  //游戏场景最好不用复用，直接移除掉创建新的场景
                {
                    this->hide();
                    pScene = new PlayScene(i+1); //将选择的关卡号 传入给PlayerScene
                    pScene->show();
                }
            });




}
