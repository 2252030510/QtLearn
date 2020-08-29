#ifndef MAINSCENERY_H
#define MAINSCENERY_H

#include <QMainWindow>

#include "mypushbutton.h"
#include "chooselevelscene.h"


QT_BEGIN_NAMESPACE
namespace Ui { class mainScenery; }
QT_END_NAMESPACE

class mainScenery : public QMainWindow
{
    Q_OBJECT

public:
    mainScenery(QWidget *parent = nullptr);
    ~mainScenery();



    void paintEvent(QPaintEvent *);


    ChooseLevelScene *chooseScene = new ChooseLevelScene;

private:
    Ui::mainScenery *ui;
};
#endif // MAINSCENERY_H
