#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QDebug>
#include "histogram.h"


class ImageWidget : public QWidget
{
    Q_OBJECT

public:

    explicit ImageWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent* event);
    void set_image(QImage& img);

    Histogram * get_histogram(){
        return histogram;
    }
    QImage* get_img(){
        return img_ptr;
    }

private:
    QPainter painter;
    QImage* img_ptr;
    Histogram *histogram;
signals:

};

#endif // IMAGEWIDGET_H
