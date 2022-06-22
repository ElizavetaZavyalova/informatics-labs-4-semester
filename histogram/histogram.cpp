#include "histogram.h"
#include "imagefunctions.h"
#include "math.h"


Histogram::Histogram()
{
    hPen = QPen(Qt::black);
    borderPen = QPen(Qt::red);
    borderPen.setWidth(7);

    setFixedWidth(256 + borderPen.width()*2);
    setFixedHeight(256 + borderPen.width()*2);

    pixelsQuo = 1;
    Hmax = 0;
    memset(histogramData, 0, sizeof(*histogramData) * 256);
}

void Histogram::doHistogram(const QImage& img)//Пересчитывание яркости(Корзины)
{
    /** Пересчитывает корзины гистограммы по поданному изображению.
    **/
    ImageFunctions::Histogram::setHistogramData(img, histogramData);
    setHmax();
    setPaintBuffer();
}

void Histogram::setHmax()
{
    /** считает максимальную высоту корзины яркости по всей гистограмме.
     *  Нужно, чтобы столбцы были видимой высоты
     **/
    Hmax = 0;
    for (auto p = histogramData; p < histogramData + 256; ++p)
    {
        if (Hmax < *p){
            Hmax = *p;
        }
    }
}

void Histogram::setPaintBuffer()//Заполняем данные о следущей отрисовки
{
    /** Переписывает буффер отрисовки
    **/
    picture = QPicture();
    painter.begin(&picture);
    painter.setPen(borderPen);
    int dw = ceil((float)borderPen.width() / 2);
    painter.drawRect(dw, dw, height()- 2*dw, width() - 2*dw);

    if(Hmax < 1)
    {
        painter.end();
        update(this->rect());
        return;
    }

    painter.setPen(hPen);
    int y = height() - 2*dw;
    int hh = y - 2*dw, x = 2*dw;
    unsigned long long h;

    for (auto p = histogramData; p < histogramData + 256; ++p)
    {
        h = ((double)(*p * hh)) / Hmax ;
        painter.drawLine(x, y, x, y - h);
        ++x;
    }

    painter.end();
    update(this->rect());
}

void Histogram::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    painter.begin(this);
    painter.drawPicture(0, 0, picture);
    painter.end();
}
