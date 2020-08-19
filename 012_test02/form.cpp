#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    void(QSpinBox::*qsb)(int)=(&QSpinBox::valueChanged);
    connect(ui->spinBox,qsb,ui->horizontalSlider,&QSlider::setValue);

    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);

}


int Form::getNum(){
    return ui->Form::spinBox->value();
}

void Form::setNum(int num){
    ui->spinBox->setValue(num);
}


Form::~Form()
{
    delete ui;
}
