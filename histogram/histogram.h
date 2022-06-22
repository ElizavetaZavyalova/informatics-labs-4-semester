#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <QWidget>
#include <QPainter>
#include <QPicture>
#include <QImage>
#include <QDebug>

class Histogram : public QWidget
{
    Q_OBJECT

public:
    Histogram();
    void doHistogram(const QImage& img);
    void paintEvent(QPaintEvent* event);

private:
    unsigned long long histogramData[256];
    unsigned long long pixelsQuo, Hmax;
    QPainter painter;
    QPicture picture;
    QPen hPen, borderPen;

    void setHmax();
    void setPaintBuffer();

signals:

};

#endif // HISTOGRAM_H
