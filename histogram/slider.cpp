#include "slider.h"
#include "ui_slider.h"


Slider::Slider(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Slider)
{
    ui->setupUi(this);
    this->pos_1=0;
      this->pos_2=0;
    if(!MainWindow::pos_1){
       ui->range_1->hide();
    }
    if(!MainWindow::pos_2){
        ui->range_2->hide();
    }
}

Slider::~Slider()
{
    delete ui;
}

void Slider::on_pushButton_clicked()
{    this->ok=1;
    this->accept();
}



void Slider::on_range_1_sliderMoved(int position)
{
      this->pos_1=position;
}

void Slider::on_range_2_sliderMoved(int position)
{
    this->pos_2=position;
}
