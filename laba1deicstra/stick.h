#ifndef MOVEITEM_H
#define MOVEITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QTimer>
#include <qmath.h>

class Game;
class Stick : public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    int last[2]={-2,-2};
    double max=10000;
    int size=-1;
    bool visited=0;
    bool grany=0;
    QColor color;
    bool go=0;
    int evristic=0;
public:
    static int h;
    static int w;

public:
    explicit Stick(QObject *parent = 0);
    ~Stick();
    Stick(const Stick&){};
    int get_max()const{
        return this->max;
    }
    int get_evristic()const{
        return this->evristic;
    }
friend class MainMenu;
signals:

private:
    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void set_color(const int &t);
     std::pair<int,int> give_start();
    friend class Game;

public slots:

};

class Game {
    QVector<QVector<Stick*>*>* field=nullptr;
    int start[2]={-1,-1};
    int finish[2]={-1,-1};
    friend class MainMenu;
public:

        ~Game(){clien_field();};

public:
       void found_way(const bool Star=0);
         void found(const int&i, const int&j,QList<std::pair<std::pair<int, int>,Stick*>>&mas, const bool Star=0);
         void clien_field();
         void new_game();
         void show_way();
         void set_evristic(const int i, const int j){
             int evristic=(sqrt((finish[0]-i)*(finish[0]-i)+(finish[1]-j)*(finish[1]-j)))*10;
              (*(*field)[i])[j]->evristic=evristic;
         }



};


#endif // MOVEITEM\_H
