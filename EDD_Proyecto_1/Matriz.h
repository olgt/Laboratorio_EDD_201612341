#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include "Nodo_Matriz.h"
#include "Nodo_Objeto.h"
#include "Cabecera.h"
#include <fstream>

using namespace std;

class Matriz
{
private:
    Cabecera* horizontal;
    Cabecera* vertical;
    Cabecera* getVertical(int x);
    Cabecera* getHorizontal(int y);
    Cabecera *crearHorizontal(int y);
    Cabecera *crearVertical(int x);

    Nodo_Matriz* obtenerUltimoVertical(Cabecera* , int);
    Nodo_Matriz* obtenerUltimoHorizontal(Cabecera* , int);

public:
    Matriz();
    ~Matriz();
    void add(Nodo_Objeto* nuevo);
    void codigo();

    void imprimirCabeceraX();
    void imprimirCabeceraY();
    void imprimirMatriz();


    void crearGrafica();
    void enlacesNodosMatrizHorizontal(ofstream &, Nodo_Matriz *horizontal);
    void enlacesNodosMatrizVertical(ofstream & MyFile, Nodo_Matriz* vertical);

};

#endif // MATRIZ_H
