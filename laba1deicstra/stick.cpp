#include "stick.h"
int Stick::w=300;
int Stick::h=300;



#include "mainmenu.h"

Stick::Stick(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

}



Stick::~Stick()
{

}

QRectF Stick::boundingRect() const
{
    return QRectF (0,0,800,800);
}
void Stick::set_color(const int&t){
    switch (size) {
    case 0:
        this->color=QColor(128,128,128,t);
        return;
    case 10:
         this->color=QColor(0,255,0,t);
        return ;
    case 20:
        this->color=QColor(255,255,0,t);
       return;
    case 30:
        this->color=QColor(0,128,0,t);
       return;
    case 40:
        this->color=QColor(0,0,255,t);
       return;
    case 50:
        this->color=QColor(210,105,30,t);
       return;
    case 60:
        this->color=QColor(255,255,255,t);
       return;
    case 70:
        this->color=QColor(255,0,0,t);
       return;

    }
}



void Stick::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setPen(Qt::black);
    painter->setBrush(QBrush(this->color));
    painter->drawRect(0,0,w,h);
     painter->drawText(3*w/4,3*h/4,QString::number(size));

     if(last[0]!=-2&&last[1]!=-2){

     painter->drawText(w/8,h*0.27,QString::number(last[0])+";"+QString::number(last[1]));
     }
     if(go){
       painter->setBrush(Qt::black);
      painter->drawEllipse(w/4,h/2, w/4,h/4);
     }

    Q_UNUSED(option);
    Q_UNUSED(widget);
}





void Stick::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    this->setCursor(QCursor(Qt::ClosedHandCursor));
    if(!grany){
    this->size=(reinterpret_cast<MainMenu*>(this->parent()))->num;
     this->color=(reinterpret_cast<MainMenu*>(this->parent()))->color;
     this->update();
    }

    Q_UNUSED(event);



}


