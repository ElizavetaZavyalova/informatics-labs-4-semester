//#include "imagewidget.h"
#include "imagefunctions.h"
#include "mainwindow.h"

ImageWidget::ImageWidget(QWidget *parent) : QWidget(parent)//Отрисовывает картинку Переданную
{
    //painter = new QPainter(this);
    /* QPainter не наследуется от QObject и не имеет метода setParent.
     *  Т.е. он не включается в объектную иерархию.
     *  И его нужно удалять самостоятельно, если он создавался динамически (через new).
     *  Смысла выделять его в дин. памяти в текущей задаче нет.
    */
    img_ptr = nullptr;

    histogram = new Histogram();


}

void ImageWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    if (!img_ptr) return;

    painter.begin(this);
    painter.drawImage(0, 0, *img_ptr);
    painter.end();
}

void ImageWidget::set_image(QImage& img)//Установка картинки для отрисовки
{
   img_ptr = &img;
    //setToBrightnessMap(img);
   histogram->doHistogram(img);

   this->update();
   // setToBrightnessMap(img);
}
