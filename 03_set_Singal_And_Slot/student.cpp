#include "student.h"
#include "QDebug"
Student::Student(QObject *parent) : QObject(parent)
{

}


void Student::treat()
{
    qDebug()<<"请老师恰饭";
}

void Student::treat(QString foodName)
{

    qDebug()<<"请老师吃："<<foodName.toUtf8().data();

}
