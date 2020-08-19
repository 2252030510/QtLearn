#ifndef TEANCHER_H
#define TEANCHER_H

#include <QObject>

class Teancher : public QObject
{
    Q_OBJECT
public:
    explicit Teancher(QObject *parent = nullptr);

signals:
    //自定义信号写到这
    //返回值未void 只要声明不用实现
    //可以有参数，可以重载
    void hungary();
    void hungary(QString foodName);
};

#endif // TEANCHER_H
