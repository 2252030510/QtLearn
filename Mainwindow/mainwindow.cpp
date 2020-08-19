#include "mainwindow.h"
#include "QMenuBar"
#include "QToolBar"
#include "QDebug"
#include "QPushButton"
#include "QStatusBar"
#include "QLabel"
#include "QDockWidget"
#include "QTextEdit"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //充值窗口d大小

    resize(600,400);

    //创建菜单栏  最多一个
    QMenuBar *bar=menuBar();
    //将菜单栏放入窗口中
    setMenuBar(bar);
   //创建菜单
    QMenu *fileMenu = bar->addMenu("文件");
    QMenu *editMenu = bar->addMenu("编辑");

    //创建菜单项
    QAction *newAction =fileMenu->addAction("新建");
    //添加分隔符
     fileMenu->addSeparator();

    QAction *openAction= fileMenu->addAction("打开");

    QToolBar *toolBar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea,toolBar);

    toolBar->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea);
    toolBar->setFloatable(false);
    toolBar->setMovable(true);


    toolBar->addAction(newAction);
    toolBar->addSeparator();
    toolBar->addAction(openAction);

    QPushButton *btn = new QPushButton("add",this);
    toolBar->addWidget(btn);


    //状态栏 最多一个
    QStatusBar *stBar= statusBar();
    //设置到窗口中
    setStatusBar(stBar);
    QLabel *label =new QLabel("提示信息",this);
    stBar->addWidget(label);
    QLabel *label2 =new QLabel("提示信息2",this);
    stBar->addPermanentWidget(label2);

    //铆接部件（浮动窗口） 可以有多个

    QDockWidget *dockWidget = new QDockWidget("浮动",this);
    addDockWidget(Qt::BottomDockWidgetArea,dockWidget);
    dockWidget->setAllowedAreas(Qt::TopDockWidgetArea|Qt::BottomDockWidgetArea);



    //中心部件
    QTextEdit *edit = new QTextEdit(this);
    setCentralWidget(edit);

}

MainWindow::~MainWindow()
{
}

