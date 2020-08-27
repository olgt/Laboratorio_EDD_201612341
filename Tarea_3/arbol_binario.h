#ifndef ARBOL_BINARIO_H
#define ARBOL_BINARIO_H
#include "nodoarbol.h"
#include <stdbool.h>
#include <iostream>
using namespace std;

class Arbol_Binario
{
    private:
        NodoArbol* raiz;

        void Delete(NodoArbol* raiz);
        NodoArbol* insertar(NodoArbol* raiz, int dato);


    public:
        Arbol_Binario();
        ~Arbol_Binario();

        NodoArbol* getRaiz();



        void insertar(int valor);
        void generar();
        void recorrerPreorden(NodoArbol* raiz);
        void recorrerInorden(NodoArbol* raiz);
        void recorrerPostorden(NodoArbol* raiz);
};

#endif // ARBOL_BINARIO_H
