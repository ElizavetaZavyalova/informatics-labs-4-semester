#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QImage>
#include <QColor>
#include <QLayout>

#include "imagewidget.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   // void (*image_work) (int&, int&, int&,int,int);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //void setToBrightnessMap(QImage& img);
    static bool use;
    static bool pos_1;
     static bool pos_2;

private:
    Ui::MainWindow *ui;
    void load_image();
    void make_inner_widgets();
    bool make_and_save_image();
    void (*image_work) (int&, int&, int&,int,int);
    void setToBrightnessMap(QImage& img);
    QImage image;
    QImage image_filter;
    ImageWidget *img_widget;
    QHBoxLayout *qlayout;
    Histogram *histogram;

signals:

private slots:
    void on_autor_triggered();
    void on_about_triggered();
    void on_blackwhite_triggered();
    void on_inversion_triggered();
    void on_porog_triggered();
    void on_logorifm_triggered();
    void on_piecewise_linear_triggered();
    void on_power_triggered();
    void on_equalization_triggered();
    void on_normal_triggered();
    void on_porog_1_triggered();
    void on_porog_2_triggered();
    void on_dft_triggered();
    void on_averaged_triggered();
    void on_Gaus_triggered();
    void on_median_triggered();
    void on_Loplassian_triggered();
    void on_Derivatives_x_triggered();
    void on_Sobel_x_triggered();
    void on_Shahuro_triggered();
    void on_Derivatives_y_triggered();
    void on_Sobel_y_triggered();
};
#endif // MAINWINDOW_H
