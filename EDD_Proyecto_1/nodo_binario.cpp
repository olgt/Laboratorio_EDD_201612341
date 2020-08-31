#include "nodo_binario.h"

Nodo_Binario::Nodo_Binario(int id, string nombre, char letra, string color, Lista_Puntos* xy)
{
    this->id = id;
    this->nombre = nombre;
    this->letra = letra;
    this->color = color;
    this->xy = xy;
}

void Nodo_Binario::setIzquierda(Nodo_Binario* izq){
    this->hijoIzquierdo = izq;
}

void Nodo_Binario::setDerecha(Nodo_Binario* der){
    this->hijoDerecho = der;
}

Nodo_Binario* Nodo_Binario::getDerecha(){
    return this->hijoDerecho;

}
Nodo_Binario* Nodo_Binario::getIzquierda(){
    return this->hijoIzquierdo;
}

int Nodo_Binario::getId(){
    return this->id;
}

string Nodo_Binario::getName(){
    return this->nombre;
}

char Nodo_Binario::getLetra(){
    return this->letra;
}

string Nodo_Binario::getColor(){
    return this->color;
}

int Nodo_Binario::getX(){
    return this->x;
}

int Nodo_Binario::getY(){
    return this->y;
}

void Nodo_Binario::setId(int id){
    this->id = id;
}
void Nodo_Binario::setName(string nombre){
    this->nombre = nombre;
}

void Nodo_Binario::setLetra(char letra){
    this->letra = letra;
}
void Nodo_Binario::setColor(string color){
    this->color = color;
}
