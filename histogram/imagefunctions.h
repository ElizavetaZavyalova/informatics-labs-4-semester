#ifndef IMAGEFUNCTIONS_H
#define IMAGEFUNCTIONS_H
#include<QImage>
#include<QDebug>
#include"slider.h"


namespace ImageFunctions {

    void do_nothing(int &r, int &g, int &b,int pos_1,int pos_2);
   // void (*image_work) (int&, int&, int&,int,int);
    namespace Image {
    void inversion(int &r, int &g, int &b,int pos_1,int pos_2);
    void black_and_white(int &r, int &g, int&b,int pos_1,int pos_2);
    void doterstep_1(int &r, int &g, int&b,int pos_1,int pos_2);
    void doterstep_2(int &r, int &g, int &b,int pos_1,int pos_2);

    }
    namespace  DFT{
      void fourier(QImage&img, QImage &img_filter);
    }
    namespace filters{
    void box(QImage&img, QImage &img_filter);
    void shahuro(QImage&img, QImage &img_filter);
    void median(QImage&img, QImage &img_filter);
    void laplasian(QImage&img, QImage &img_filter);
    void gaus(QImage&img, QImage &img_filter);
    void sobela_x(QImage&img, QImage &img_filter);
    void sobela_y(QImage&img, QImage &img_filter);
    void derivatives_x(QImage&img, QImage &img_filter);
    void derivatives_y(QImage&img, QImage &img_filter);
    void filtrate(std::vector<std::vector<double>>&filter,QImage img, QImage &img_filter);
    }
    namespace Brightness {

     void britnes_to_RGB(double Y, int &r, int &g, int &b);
     int getBrightness(int r, int g, int b);
   // void setToBrightnessMap(QImage &img);
    void logarithmic(int&r, int&g, int&b,int pos_1,int pos_2);
    void power(int&r, int&g, int&b,int pos_1,int pos_2);
    void doterstep(int&r, int&g, int&b,int pos_1,int pos_2);
     void piecewise_linear(int &r, int &g, int&b,int pos_1,int pos_2);
    }
    namespace Histogram {
      void setHistogramData(const QImage &img, unsigned long long(&histogramData)[256]);
    }



}

#endif // IMAGEFUNCTIONS_H
