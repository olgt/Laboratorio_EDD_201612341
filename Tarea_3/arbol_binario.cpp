
#include "arbol_binario.h"

Arbol_Binario::Arbol_Binario()
{
    this->raiz = NULL;
}


void Arbol_Binario::Delete(NodoArbol *raiz){
    if(raiz==NULL){return;}
    Delete(raiz->getIzquierda());
    Delete(raiz->getDerecha());
    delete raiz;
}

NodoArbol* Arbol_Binario::getRaiz(){
    return this->raiz;
}

NodoArbol* Arbol_Binario::insertar(NodoArbol *raiz, int dato){
    if(raiz==NULL){
        raiz = new NodoArbol(dato);
    } else if(dato<raiz->getData()){
        NodoArbol* izq = insertar(raiz->getIzquierda(), dato);
        raiz->setIzquierda(izq);

    } else if(dato>raiz->getData()){
        NodoArbol* der = insertar(raiz->getDerecha(), dato);
        raiz->setDerecha(der);
    }
    return raiz;
}

void Arbol_Binario::recorrerPostorden(NodoArbol *raiz){

    if(raiz->getIzquierda() != NULL){
        recorrerPostorden(raiz->getIzquierda());
    }
    if(raiz->getDerecha() != NULL){
        recorrerPostorden(raiz->getDerecha());
    }

    cout << "Dato: " << raiz->getData() << endl;
}

void Arbol_Binario::recorrerPreorden(NodoArbol *raiz){

    cout << "Dato: " << raiz->getData() << endl;

    if(raiz->getIzquierda() != NULL){
        recorrerPreorden(raiz->getIzquierda());
    }
    if(raiz->getDerecha() != NULL){
        recorrerPreorden(raiz->getDerecha());
    }
}

void Arbol_Binario::recorrerInorden(NodoArbol *raiz){

    if(raiz == NULL){
        return;
    }

    recorrerInorden(raiz->getIzquierda());
    cout << "Dato: " << raiz->getData() << endl;;
    recorrerInorden(raiz->getDerecha());

}

void Arbol_Binario::insertar(int valor){
    this->raiz=insertar(this->raiz,valor);
}
