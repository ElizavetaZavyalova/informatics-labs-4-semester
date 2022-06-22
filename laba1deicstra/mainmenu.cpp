#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <qmessagebox.h>
#include <QFile>
#include <QTextStream>



MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    this->setFixedSize(1000,1000);

    scene = new QGraphicsScene(this);

    ui->graphicsView->setGeometry(5,60,800,800);
    ui->graphicsView->resize(800,800);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    scene->setSceneRect(0,0,800,800);
    QGraphicsRectItem *rect = new QGraphicsRectItem();
    rect->setPen(QPen(Qt::red));
    rect->setRect(scene->sceneRect());
    scene->addItem(rect);

    on_Random_clicked();

}

MainMenu::~MainMenu()
{
    delete ui;
}


void MainMenu::on_Start_clicked()
{
    dialog_random.setFixedSize(150,100);
    dialog_random.exec();
    if(dialog_random.w>game.field->size()-2||dialog_random.h>(*(game.field))[0]->size()-2){
        QMessageBox msgBox;
        msgBox.setText("Некоректный Старт");
        msgBox.exec();
    }
    else{
         if(!(game.start[0]==-1)){
       (*(*(*game.field)[game.start[0]])[game.start[1]]).set_color(100);

        (*(*(*game.field)[game.start[0]])[game.start[1]]).max=1000;}
    game.start[0]=dialog_random.w;
    game.start[1]=dialog_random.h;
     (*(*(*game.field)[game.start[0]])[game.start[1]]).max=0;
       if(!(game.finish[0]==-1)){
     (*(*(*game.field)[game.finish[0]])[game.finish[1]]).color=QColor(237,60,202,255);}
    (*(*(*game.field)[game.start[0]])[game.start[1]]).color= QColor(237,60,255,255);
    }



}

void MainMenu::on_Finish_clicked()
{
    dialog_random.setFixedSize(150,100);
    dialog_random.exec();
    if(dialog_random.w>game.field->size()-2||dialog_random.h>(*game.field)[0]->size()-2){
        QMessageBox msgBox;
        msgBox.setText("Некоректный Финиш");
        msgBox.exec();
    }
    else{
    if(!(game.finish[0]==-1)){
    (*(*(*game.field)[game.finish[0]])[game.finish[1]]).set_color(100);}
    game.finish[0]=dialog_random.w;
    game.finish[1]=dialog_random.h;
     if(!(game.start[0]==-1)){
     (*(*(*game.field)[game.start[0]])[game.start[1]]).color=QColor(237,60,255,255);}
     (*(*(*game.field)[game.finish[0]])[game.finish[1]]).color=QColor(237,60,202,255);
    }

}

void MainMenu::on_Searf_clicked()
{
    if(game.start[0]==game.finish[0]&&game.start[1]==game.finish[1]){
        QMessageBox msgBox;
        msgBox.setText("Старт и Финиш совподают");
        msgBox.exec();
    }
  else{

        game.new_game();
        game.found_way();
        game.show_way();
    }



}

void MainMenu::on_Upload_clicked()
{
    file_open.setFixedSize(300,100);
    file_open.exec();
     QFile file(file_open.str);

    if(!file.open(QFile::ReadOnly |QFile::Text))
        {
            QMessageBox::information(this,"Ошибка","Файл не был прочитан!");
            return;
        }
    QTextStream stream(&file);
    int w, h;
    stream>>w>>h;
    Stick::w=(800)/(w+2);
    Stick::h=(800)/(h+2);
     int w1=0;
      int h1=0;


    QVector<QVector<Stick*>*>* Field;
    Field=new QVector<QVector<Stick*>*>;
    for(int i=0;i<dialog_random.w+2;i++){
         QVector<Stick*>* Row;
         Row=new QVector<Stick*>;
        for(int j=0; j<dialog_random.h+2; j++){
            Stick* stick=new Stick(this);
            if(i==0||j==0||i==dialog_random.w+1||j==dialog_random.h+1){
                ((stick->size=0));
                stick->grany=1;
            }
            else{
                (stream>>(stick->size));}
            Row->push_back(stick);
            stick->setPos(w1,h1);
          scene->addItem(stick);
          h1+=Stick::h;
          stick->set_color(100);
        }
         h1=0;
          w1+=Stick::w;
          Field->push_back(Row);

    }
    file.close();
    game.clien_field();
    game.field=Field;
    game.start[0]=-1;
    game.start[1]=-1;
    game.finish[0]=-1;
    game.finish[1]=-1;




}
void Game::clien_field(){
    if(this->field!=nullptr){
        for(auto i=field->begin(); i!=field->end();i++){

            for(auto j=(**i).begin(); j!=(**i).end();j++){
                delete (*j);
            }
            delete (*i);
        }
        delete field;
        field=nullptr;
    }

}


void Game::new_game(){
    for(auto i=field->begin(); i!=field->end();i++){

        for(auto j=(**i).begin(); j!=(**i).end();j++){
            (*j)->go=0;
            (*j)->max=1000;
            (*j)->set_color(100);
            (*j)->last[0]=-2;
            (*j)->last[1]=-2;
            (*j)->evristic=0;
        }
    }
    (*(*(*field)[start[0]])[start[1]]).color=QColor(237,60,255,255);
    (*(*(*field)[finish[0]])[finish[1]]).color=QColor(237,60,202,255);
    (*(*(*field)[start[0]])[start[1]]).max=0;
}


void MainMenu::on_Random_clicked()
{

     dialog_random.setFixedSize(150,100);
     dialog_random.exec();

     Stick::w=(800)/(dialog_random.w+2);
     Stick::h=(800)/(dialog_random.h+2);
      int w1=0;
       int h1=0;

  QVector<QVector<Stick*>*>* Field;
  Field=new QVector<QVector<Stick*>*>;
  for(int i=0;i<dialog_random.w+2;i++){
       QVector<Stick*>* Row;
       Row=new QVector<Stick*>;
      for(int j=0; j<dialog_random.h+2; j++){
          Stick* stick=new Stick(this);
          if(i==0||j==0||i==dialog_random.w+1||j==dialog_random.h+1){
              ((stick->size=0));
              stick->grany=1;
          }
          else{
              (stick->size=(rand()%8)*10);}

          Row->push_back(stick);
          stick->setPos(w1,h1);
        scene->addItem(stick);
        h1+=Stick::h;
        stick->set_color(100);
      }
       h1=0;
        w1+=Stick::w;
        Field->push_back(Row);

  }
  game.clien_field();
  game.field=Field;
  game.start[0]=-1;
  game.start[1]=-1;
  game.finish[0]=-1;
  game.finish[1]=-1;


}



void MainMenu::on_Blue_clicked()
{
    this->color=QColor(0,0,255,100);

      num=40;
}

void MainMenu::on_White_clicked()
{
    this->color=QColor(255,255,255,100);

   num=60;

}

void MainMenu::on_Red_clicked()
{
   this->color=QColor(255,0,0,100);
    num=70;
}

void MainMenu::on_NoStick_clicked()
{
    this->color=QColor(128,128,128,100);
    num=00;
}

void MainMenu::on_Yellow_clicked()
{


   this->color=QColor(255,255,0,100);
     num=20;

}

void MainMenu::on_Green_clicked()
{
    this->color=QColor(0,255,0,100);

       num=10;
}

void MainMenu::on_Forest_clicked()
{
    this->color=QColor(0,128,0,100);


     num=30;
}

void MainMenu::on_Brown_clicked()
{
    this->color=QColor(210,105,30,100);
   num=50;

}

void MainMenu::on_star_clicked()
{
    if(game.start[0]==game.finish[0]&&game.start[1]==game.finish[1]){
        QMessageBox msgBox;
        msgBox.setText("Старт и Финиш совподают");
        msgBox.exec();
    }
  else{

        game.new_game();
        game.found_way(1);
        game.show_way();
    }
}
