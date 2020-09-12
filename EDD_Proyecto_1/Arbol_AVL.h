#ifndef ARBOL_AVL_H
#define ARBOL_AVL_H


#include <iostream>
#include "nodoarbol.h"
#include <stdbool.h>
#include <fstream>
#include "arbol_binario.h"

using namespace std;

class Arbol_AVL
{
private:
    NodoArbol* raiz;
    NodoArbol* insertar(NodoArbol* raiz, string name, bool &hc, Lista_Niveles* niveles, int id, Arbol_Binario* abb);

    NodoArbol* rotacionII(NodoArbol* n, NodoArbol* n1);
    NodoArbol* rotacionDD(NodoArbol* n, NodoArbol* n1);
    NodoArbol* rotacionID(NodoArbol* n, NodoArbol* n1);
    NodoArbol* rotacionDI(NodoArbol* n, NodoArbol* n1);
    void Delete(NodoArbol* raiz);

public:
    Arbol_AVL();
    ~Arbol_AVL();

    NodoArbol* getRaiz();

    void insertar(string nombre, Lista_Niveles* niveles, int id, Arbol_Binario* abb);
    void generar();
    int sumarCaracteres(string name);

    void crearGrafica();
    void crearGraficaRamas(ofstream &file, NodoArbol* raiz);
    void recorrerArbol(NodoArbol *raiz);
    void graficarProyecto(NodoArbol *raiz, int id);
    void graficarTodosProyectos(NodoArbol *raiz);

    void imprimirListaArboles();
};

#endif // ARBOL_AVL_H
