#include "dialog_file_name.h"
#include "ui_dialog_file_name.h"

Dialog_file_name::Dialog_file_name(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_file_name)
{
    ui->setupUi(this);
}

Dialog_file_name::~Dialog_file_name()
{
    delete ui;
}

void Dialog_file_name::on_Ok_clicked()
{
    str=ui->LineEdid_name->text();
    this->close();
}
