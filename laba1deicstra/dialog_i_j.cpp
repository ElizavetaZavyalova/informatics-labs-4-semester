#include "dialog_i_j.h"
#include "ui_dialog_i_j.h"

Dialog_i_j::Dialog_i_j(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_i_j)
{
    ui->setupUi(this);
}

Dialog_i_j::~Dialog_i_j()
{
    delete ui;
}

void Dialog_i_j::on_ok_clicked()
{
    w=(ui->weight->text()).toInt();
    h=(ui->height->text()).toInt();
    this->close();
}
