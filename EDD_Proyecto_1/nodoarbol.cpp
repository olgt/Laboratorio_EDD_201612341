#include "nodoarbol.h"

NodoArbol::NodoArbol(string nombre) //Poner lista de niveles
{
    this->nombre = nombre;
    //this->niveles = niveles;
    this->codigo = sumarCaracteres();
}


int NodoArbol::sumarCaracteres(){

    int codigo = 0;
    string nombre = this->nombre;
    int n = nombre.length();

    char char_array[n+1];
    strcpy(char_array, nombre.c_str()); //Metodo agrega los caracteres al array

    for(int i = 0; i < n; i++){
        codigo += (int)char_array[i];
    }

    return codigo;
}

int NodoArbol::getCodigo(){
    return this->codigo;
}

string NodoArbol::getName(){
    return this->nombre;
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



//Para arbol AVL
void NodoArbol::setFactor(int factor){
    this->factorE = factor;
}

int NodoArbol::getFactor(){
    return this->factorE;
}
