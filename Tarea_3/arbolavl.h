#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include <iostream>
#include "nodoarbol.h"
#include <stdbool.h>
using namespace std;

class ArbolAVL
{

private:
    NodoArbol* raiz;
    NodoArbol* insertar(NodoArbol* raiz, int dato, bool &hc);

    NodoArbol* rotacionII(NodoArbol* n, NodoArbol* n1);
    NodoArbol* rotacionDD(NodoArbol* n, NodoArbol* n1);
    NodoArbol* rotacionID(NodoArbol* n, NodoArbol* n1);
    NodoArbol* rotacionDI(NodoArbol* n, NodoArbol* n1);
    void Delete(NodoArbol* raiz);

public:
    ArbolAVL();
    ~ArbolAVL();

    NodoArbol* getRaiz();

    void insertar(int valor);
    void generar();
};

#endif // ARBOLAVL_H
