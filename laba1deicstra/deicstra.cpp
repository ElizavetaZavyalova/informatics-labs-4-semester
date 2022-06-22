#include "stick.h"
#include "mainmenu.h"
#include <QApplication>
#include <windows.h>
#include <QThread>
#include <iostream>
#include <cstdlib>
#include <QtAlgorithms>

bool sorting(const std::pair<std::pair<int, int>,Stick*> &v1, const std::pair<std::pair<int, int>,Stick*> &v2){

    return (v1.second->get_max()+v1.second->get_evristic())<(v2.second->get_max()+v2.second->get_evristic());

}

void Game::found_way(const bool Star){
    QList<std::pair<std::pair<int, int>,Stick*>> mas;
    std::pair<int,int> index(start[0], start[1]);
    if(Star){
    set_evristic(start[0], start[1]);}
    std::pair<std::pair<int, int>,Stick*> elem(index,(* (*field)[start[0]])[start[1]]);
    mas.push_back(elem);
     while(!mas.empty()){
      int i=mas.begin()->first.first;
       int j=mas.begin()->first.second;
       if(Star&&((i)==finish[0])&&((j)==finish[1])){
           return;
       }
        (*(* (*field)[i])[j]).visited=1;
       for(int w=-1;w<=1;w++)
       {
           for(int h=-1; h<=1; h++)
           {
               if( (!((*(* (*field)[i+w])[j+h]).visited))&&(*(* (*field)[i+w])[j+h]).size!=0)
               {
                   double counter=((w==0)||(h==0))?(1):(sqrt(2));
                   counter= (*(* (*field)[i+w])[j+h]).size*counter+(*(* (*field)[i])[j]).max;
                   if(((*(* (*field)[i+w])[j+h]).max)>(counter))
                   {
                       (*(* (*field)[i+w])[j+h]).max=counter;
                         (*(* (*field)[i+w])[j+h]).last[0]=i;
                        (*(* (*field)[i+w])[j+h]).last[1]=j;
                       if(!(((i+w)==finish[0])&&((j+h)==finish[1])))
                       {
                       (*(* (*field)[i+w])[j+h]).set_color(150);
                       }
                       Sleep(100);
                       QApplication::processEvents();
                       (*(* (*field)[i+w])[j+h]).update();


                  }
              }
          }
       }
    mas.pop_front();
    found(i, j, mas, Star);
     }
}

void Game::found(const int&i, const int&j,QList<std::pair<std::pair<int, int>,Stick*>>&mas, const bool Star){
      for(int w=-1;w<=1;w++){
          for(int h=-1; h<=1; h++){
               if((*(* (*field)[i+w])[j+h]).size!=0&&(!(*(* (*field)[i+w])[j+h]).visited)){
                std::pair<int,int> index(i+w, j+h);
                std::pair<std::pair<int, int>,Stick*> elem(index,(* (*field)[i+w])[j+h]);
                auto i=mas.begin();
                while(i!=mas.end()){
                    if((*i)==elem){
                        break;
                    }
                    i++;
                }
                if(i==mas.end()){
                    if(Star){
                    this->set_evristic(index.first, index.second);
                            }
                    mas.append(elem);

                }


               }
                  }

              }
      std::sort(mas.begin(), mas.end(), sorting);
}

void Game::show_way(){
    if((*(* (*field)[finish[0]])[finish[1]]).max!=1000){
         (*(* (*field)[finish[0]])[finish[1]]).go=1;
    int w=(*(* (*field)[finish[0]])[finish[1]]).last[0];
    int h=(*(* (*field)[finish[0]])[finish[1]]).last[1];
    (*(* (*field)[finish[0]])[finish[1]]).update();
    while(!(w==start[0]&&h==start[1])){
         (*(* (*field)[w])[h]).set_color(255);
        (*(* (*field)[w])[h]).go=1;
        Stick &stick=(*(* (*field)[w])[h]);
               w= stick.last[0];
               h=stick.last[1];
               Sleep(100);
               QApplication::processEvents();
               stick.update();
    }
   (*(* (*field)[w])[h]).go=1;
     (*(* (*field)[w])[h]).update();


    }
}
