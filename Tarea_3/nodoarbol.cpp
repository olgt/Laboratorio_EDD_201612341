#include "nodoarbol.h"

NodoArbol::NodoArbol(int data)
{
    this->data = data;

}


void NodoArbol::setData(int dato){
    this->data = dato;
}


void NodoArbol::setIzquierda(NodoArbol* izq){
    this->hijoIzquierdo = izq;
}

void NodoArbol::setDerecha(NodoArbol* der){
    this->hijoDerecho = der;
}

NodoArbol* NodoArbol::getDerecha(){
    return this->hijoDerecho;
}

NodoArbol* NodoArbol::getIzquierda(){
    return this->hijoIzquierdo;
}

int NodoArbol::getData(){
    return this->data;
}


//Para arbol AVL
void NodoArbol::setFactor(int factor){
    this->factorE = factor;
}

int NodoArbol::getFactor(){
    return this->factorE;
}
