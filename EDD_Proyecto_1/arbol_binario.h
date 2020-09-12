#ifndef ARBOL_BINARIO_H
#define ARBOL_BINARIO_H


#include "nodo_binario.h"
#include "lista_puntos.h"
#include <stdbool.h>
#include <iostream>
#include <fstream>
#include "string.h"
using namespace std;

class Arbol_Binario
{
    private:
        Nodo_Binario* raiz;

        void Delete(Nodo_Binario* raiz);
        Nodo_Binario* insertar(Nodo_Binario* raiz, int id, string nombre, char letra, string color, Lista_Puntos *xy);

    public:
        Arbol_Binario();
        ~Arbol_Binario();

        Nodo_Binario* getRaiz();

        void insertar(int id, string nombre, char letra, string color, Lista_Puntos* xy);
        void crearGrafica();
        void crearGraficaRamas(ofstream &file, Nodo_Binario* raiz);

        void recorrerPreorden(Nodo_Binario* raiz);
        void recorrerInorden(Nodo_Binario* raiz);
        void recorrerPostorden(Nodo_Binario* raiz);
};

#endif // ARBOL_BINARIO_H
