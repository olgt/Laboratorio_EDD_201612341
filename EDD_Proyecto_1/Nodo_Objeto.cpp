#include "Nodo_Objeto.h"

Nodo_Objeto::Nodo_Objeto(int id, string objeto, char letra, string color, int x, int y)
{
    this->id = id;
    this->letra = letra;
    this->color = color;
    this->x = x;
    this->y = y;
    this->objeto = objeto;

}

string Nodo_Objeto::getObjeto(){
    return this->objeto;
}

void Nodo_Objeto::setObjeto(string objeto){
    this->objeto = objeto;
}


void Nodo_Objeto::setX(int x){
    this->x = x;

}

int Nodo_Objeto::getX(){
    return this->x;
}

void Nodo_Objeto::setY(int y){
    this->y = y;
}

int Nodo_Objeto::getY(){
    return this->y;
}

int Nodo_Objeto::getId(){
    return this->id;
}
