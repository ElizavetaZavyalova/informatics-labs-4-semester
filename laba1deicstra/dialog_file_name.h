#ifndef DIALOG_FILE_NAME_H
#define DIALOG_FILE_NAME_H

#include <QDialog>
class MainMenu;
namespace Ui {
class Dialog_file_name;
}

class Dialog_file_name : public QDialog
{
    Q_OBJECT
    QString str="";

public:
    explicit Dialog_file_name(QWidget *parent = nullptr);
    ~Dialog_file_name();
    friend class MainMenu;

private slots:
    void on_Ok_clicked();

private:
    Ui::Dialog_file_name *ui;
};

#endif // DIALOG_FILE_NAME_H
