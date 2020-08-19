#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

    //槽函数,返回值为void 要声明要实现，有参数可重载
    void treat();
    void treat(QString foodName);



signals:

};

#endif // STUDENT_H
