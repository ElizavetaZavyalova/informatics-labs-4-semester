#ifndef SLIDER_H
#define SLIDER_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Slider;
}

class Slider : public QDialog
{
    Q_OBJECT
    int pos_1;
     int pos_2;
     bool ok=0;

public:
    explicit Slider(QWidget *parent = nullptr);
    ~Slider();
    int &get_pos_1(){
        return pos_1;
    }
    int &get_pos_2(){
        return pos_2;
    }
    bool get_ok(){
        return ok;
    }


private slots:
    void on_pushButton_clicked();



    void on_range_1_sliderMoved(int position);

    void on_range_2_sliderMoved(int position);

private:
    Ui::Slider *ui;
};

#endif // SLIDER_H
