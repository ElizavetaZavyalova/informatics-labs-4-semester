#include "imagefunctions.h"
//#include "slider.h"
#include <cmath>
#include "mainwindow.h"
#include <math.h>
#include <complex>
//using namespace  ;

void ImageFunctions::DFT::fourier(QImage&img, QImage &img_filter){

     uchar *px_img_filter = img_filter.bits();
    int h = img.height();
    int w = img.width();

    int pixelsQuo = h * w;
    int r=0, g=0, b=0;
     std::complex<double> e(0,0);
     double sum=0;
    uchar *px_img = img.bits();
    const auto i = std::complex<double>(0.0, -1.0);
   for (int k = 0; k < pixelsQuo; k++)
   {
     r = *px_img;
     g = *++px_img;
     b = *++px_img;
     double Y= ImageFunctions::Brightness::getBrightness(r,g,b);
      sum+=Y;
      e=std::exp((2.0 * M_PI *((double)(k)) * i)/((double)pixelsQuo));
   }
    for (int j = 0; j < pixelsQuo; j++)
    {

    r = *px_img_filter;
    g = *++px_img_filter;
    b = *++px_img_filter;
     e=std::exp((2.0 * M_PI *((double)((j)*(pixelsQuo-1))) * i)/((double)pixelsQuo))/double(j);
     ImageFunctions::Brightness::britnes_to_RGB(abs(e)*sum,r,g,b);
     px_img_filter -= 2;
     *px_img_filter = r;
     *++px_img_filter = g;
     *++px_img_filter = b;

     px_img_filter += 2;

     }

}
void ImageFunctions::filters::filtrate(std::vector<std::vector<double>>&filter,QImage img, QImage &img_filter){

    for(int y=0; y<img.height(); y++){
    for(int x=0; x<img.width(); x++){
        long long int pixel=0;
        int r=0, g=0, b=0, j=0;
        int u=-(int)filter.size()/2;
         while(j<(int)filter.size()){
            int v=-(int)filter.size()/2;int i=0;
            while(i<(int)filter[j].size()){
                 int p1=(x+v<0)?(0):(x+v>=img.width())?(img.width()-1):(x+v);
                int p2=(y+u<0)?(0):(y+u>=img.height())?(img.height()-1):(y+u);
                r= QColor(img.pixel(p1,p2)).red();
                g= QColor(img.pixel(p1,p2)).green();
                b=QColor(img.pixel(p1,p2)).blue();
                pixel+= (filter[j][i]*ImageFunctions::Brightness::getBrightness(r,g,b));
                v++;  i++;
            } ;
            u++;j++;
        } ;
        r= QColor(img_filter.pixel(x,y)).red();
        g= QColor(img_filter.pixel(x,y)).green();
        b=QColor(img_filter.pixel(x,y)).blue();
        //(abs(pixel)>255)?(pixel=255):(abs(pixel));
        ImageFunctions::Brightness::britnes_to_RGB(abs(pixel), r,g,b);
        img_filter.setPixelColor(x,y,QColor(r,g,b));
            }

        }

    }
void ImageFunctions::filters::box(QImage&img,QImage &img_filter){
    std::vector<std::vector<double>> filter;
    for(int i=0; i<5; i++){
        filter.push_back(std::vector<double>());
        for(int j=0; j<5; j++){
            filter[i].push_back(0.04);
        }
    }
    ImageFunctions::filters::filtrate(filter, img,img_filter);


    }

void ImageFunctions::filters::gaus(QImage&img, QImage &img_filter){
    std::vector<std::vector<double>> filter;
    double count=0;
    for(int i=-3; i<=3; i++){
        filter.push_back(std::vector<double>());
        for(int j=-3; j<=3; j++){
            double func=(((exp((double)(-(double)(i*i+j*j))*0.5))/(2.0*M_PI)));
            filter[i+3].push_back(func);
            count+=func;
        }
    }
    for(int i=0; i<7; i++){

        for(int j=0; j<7; j++){

            filter[i][j]/=count;
        }
    }

    ImageFunctions::filters::filtrate(filter, img,img_filter);
    }
void ImageFunctions::filters::shahuro(QImage&img, QImage &img_filter){
    std::vector<std::vector<double>> filter={{-0.1,-0.2,-0.1},{-0.2,2.2,-0.2},{-0.1,-0.2,-0.1}};
    ImageFunctions::filters::filtrate(filter, img,img_filter);
}

void  ImageFunctions::filters::laplasian(QImage&img, QImage &img_filter){
    std::vector<std::vector<double>> filter={{0,-1,0},{-1,4,-1},{0,-1,0}};
    ImageFunctions::filters::filtrate(filter, img,img_filter);
}
void  ImageFunctions::filters::sobela_x(QImage&img, QImage &img_filter){
    std::vector<std::vector<double>> filter={{-1,-2,-1},{0,0,0},{1,2,1}};
    ImageFunctions::filters::filtrate(filter, img,img_filter);
}
void  ImageFunctions::filters::sobela_y(QImage&img, QImage &img_filter){
    std::vector<std::vector<double>> filter={{-1,0,1},{-2,0,2},{-1,0,1}};
    ImageFunctions::filters::filtrate(filter, img,img_filter);
}
void ImageFunctions::filters::derivatives_x(QImage&img, QImage &img_filter){
    std::vector<std::vector<double>> filter={{1,-2,1}};
    ImageFunctions::filters::filtrate(filter, img,img_filter);
}
void ImageFunctions::filters::derivatives_y(QImage&img, QImage &img_filter){
    std::vector<std::vector<double>> filter={{1},{-2},{1}};
    ImageFunctions::filters::filtrate(filter, img,img_filter);
}

void ImageFunctions::filters::median(QImage&img, QImage &img_filter){
    for(int y=0; y<img.height(); y++){
    for(int x=0; x<img.width(); x++){
        int r=0, g=0,b=0;
        std::vector<int> median;
        for(int i=y-1; i<=y+1; i++){
            for(int j=x-1; j<=x+1; j++){
                int p1=(j<0)?(0):(j>=img.width())?(img.width()-1):(j);
                 int p2=(i<0)?(0):(i>=img.height())?(img.height()-1):(i);
               r= QColor(img.pixel(p1,p2)).red();
               g= QColor(img.pixel(p1,p2)).green();
               b=QColor(img.pixel(p1,p2)).blue();
               median.push_back(ImageFunctions::Brightness::getBrightness(r,g,b));
            }
        }
        std::sort(median.begin(),median.end());
        r= QColor(img_filter.pixel(x,y)).red();
        g= QColor(img_filter.pixel(x,y)).green();
        b=QColor(img_filter.pixel(x,y)).blue();
        ImageFunctions::Brightness::britnes_to_RGB(median[4], r,g,b);
        img_filter.setPixelColor(x,y,QColor(r,g,b));
            }
    }

}

void MainWindow::setToBrightnessMap(QImage& img)// Берем картинку и переводим в чернобелое
{   Slider s;
    s.exec();
    if(s.get_ok()){
    //uchar *px = img.bits();

    int h = img.height();
    int w = img.width();

    //int pixelsQuo = h * w;

    int r, g, b;

    for(int y=0; y<img.height(); y++){
    for(int x=0; x<img.width(); x++){
      // QRgb pixel=img.pixel(x,y);
      r= QColor(img.pixel(x,y)).red();
      g= QColor(img.pixel(x,y)).green();
      b=QColor(img.pixel(x,y)).blue();
      int p1=s.get_pos_1();
      int p2=s.get_pos_2();
      image_work(r,g,b,p1,p2);

      img.setPixelColor(x,y,QColor(r,g,b));

    }
    }
    }

    /*if(MainWindow::use){

        //ImageFunctions::Histogram::setHistogramData(img ,ImageFunctions::histogramData);
    }
    for (int i = 0; i < pixelsQuo; i++)
    {
        r = *px;
        g = *++px;
        b = *++px;
        int p1=s.get_pos_1();
        int p2=s.get_pos_2();

     image_work(r,g,b,p1,p2);
        px -= 2;
        *px = r;
        *++px = g;
        *++px = b;

        px += 2;
    }
    }*/
}

int ImageFunctions::Brightness::getBrightness(int r, int g, int b)//Получение яркости пикселя из ргб
{
    int brightness = 0.299*r+0.587*g+0.114*b;
    if((brightness > 255) || (brightness < 0)){
        qDebug() << "brightness error. Brightness =  " << brightness;
        qDebug() << "r; g; b = "<<r << "; " << g << "; "<< b <<".";
        exit(-110);
    }
    return brightness;
}
void ImageFunctions::do_nothing(int &r, int &g, int &b,int pos_1,int pos_2){

}

void ImageFunctions::Brightness::britnes_to_RGB(double Y,int&r, int&g, int&b){
    double U=-0.169*r-0.332*g+0.5*b;
    double V=0.5*r-0.419*g-0.0813*b;
    r=Y+1.403*V;
    g=Y-0.344*U-0.714*V;
    b=Y+1.770*U;

    (r<0)?(r=0):(r>255)?(r=255):(r);
   (g<0)?(g=0):(g>255)?(g=255):(g);
    (b<0)?(b=0):(b>255)?(b=255):(b);
}
void ImageFunctions::Brightness::piecewise_linear(int&r, int&g, int&b,int pos_1,int pos_2){
    if(pos_1>pos_2){
        std::swap(pos_1, pos_2);
    }
     int Y=ImageFunctions::Brightness::getBrightness(r,g,b);

    Y=( pos_1>=Y)?(0):(pos_2<=Y)?(255):(Y);
     ImageFunctions::Brightness::britnes_to_RGB(Y, r, g, b);

}

void ImageFunctions::Brightness::logarithmic(int&r, int&g, int&b,int pos_1,int pos_2){



    int Y=ImageFunctions::Brightness::getBrightness(r,g,b);

     Y=(pos_1*log(Y+1));
    ImageFunctions::Brightness::britnes_to_RGB(Y, r, g, b);

    return ;
    }

void ImageFunctions::Brightness::power(int&r, int&g, int&b,int pos_1,int pos_2){


    int Y=ImageFunctions::Brightness::getBrightness(r,g,b);

     Y=(pos_1*pow(((double)Y)/255,pos_2))*255;
    ImageFunctions::Brightness::britnes_to_RGB(Y, r, g, b);
    return;
    }

void ImageFunctions::Image::black_and_white(int &r, int &g, int &b,int pos_1,int pos_2){
    int averaging=0.2126*r+0.7125*g+0.0722*b;
    r=averaging;
    g=averaging;
     b=averaging;

}

void ImageFunctions::Image::doterstep_1(int &r, int &g, int &b,int pos_1,int pos_2){



    r=(r <=pos_1)?(0):(255);
   g=(g <=pos_1)?(0):(255);
   b=(b <=pos_1)?(0):(255);
    return ;
    }

void ImageFunctions::Image::doterstep_2(int &r, int &g, int &b,int pos_1,int pos_2){

    r=(r >=pos_1)?(0):(255);
   g=(g >=pos_1)?(0):(255);
   b=(b >=pos_1)?(0):(255);
    return ;

}
void ImageFunctions::Brightness::doterstep(int &r, int &g, int &b,int pos_1,int pos_2){

     int Y=ImageFunctions::Brightness::getBrightness(r,g,b);

    if( pos_1>=Y){
        r=0;
        g=0; b=0;
    }
    else{
        r=255;
        g=255; b=255;
    }

    return ;

}


void ImageFunctions::Image::inversion(int &r, int &g, int &b,int pos_1,int pos_2)
{
     r=255-r;
     b=255-b;
     g=255-g;
}

void ImageFunctions::Histogram::setHistogramData(const QImage &img, unsigned long long(&histogramData)[256]/*Массив для заполнения*/)//Расчитывает гистограмму
{
    const uchar *px = img.constBits();

    int h = img.height();
    int w = img.width();

    unsigned long long pixelsQuo = h * w;

    int r, g, b;  // , a = 255;
    int brightness = 0;
    for (unsigned long long i = 0; i < pixelsQuo; i++)
    {
        r = *px;
        g = *++px;
        b = *++px;

        brightness = ImageFunctions::Brightness::getBrightness(r, g, b);
        histogramData[brightness]++;

        px += 2;
    }
}
