#ifndef DIALOG_I_J_H
#define DIALOG_I_J_H

#include <QDialog>

namespace Ui {
class Dialog_i_j;
}

class Dialog_i_j : public QDialog
{
    int w=2;
    int h=2;
    Q_OBJECT

public:

    explicit Dialog_i_j(QWidget *parent = nullptr);
    ~Dialog_i_j();

friend class MainMenu;
private slots:
    void on_ok_clicked();


private:
    Ui::Dialog_i_j *ui;
};

#endif // DIALOG_I_J_H
