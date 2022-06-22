#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <QGraphicsScene>
//#include <moveitem.h>
#include <stick.h>
#include "dialog_i_j.h"
#include "dialog_file_name.h"
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainMenu; }
QT_END_NAMESPACE

class MainMenu : public QMainWindow
{
    Q_OBJECT

    Dialog_i_j dialog_random;
    Dialog_file_name  file_open;
    Game game;
    QColor color= QColor(128,128,128,100);
    int num=0;


public:
    MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void on_Start_clicked();

    void on_Finish_clicked();

    void on_Searf_clicked();

    void on_Upload_clicked();

    void on_Random_clicked();
    friend class Stick;

    void on_Blue_clicked();

    void on_White_clicked();

    void on_Red_clicked();

    void on_NoStick_clicked();

    void on_Yellow_clicked();

    void on_Green_clicked();

    void on_Forest_clicked();

    void on_Brown_clicked();

    void on_star_clicked();

private:
    Ui::MainMenu *ui;
    QGraphicsScene *scene;

};
#endif // MAINMENU_H
