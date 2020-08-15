#ifndef NODONIVEL_H
#define NODONIVEL_H

#include <iostream>
#include <utilities.h>
using namespace std;

class Nodo_Nivel
{
private:
    int id;
    string matriz;
    string abb;
    Nodo_Nivel *siguiente;
    Nodo_Nivel *anterior;

public:
    Nodo_Nivel(int id, string matriz, string abb);

    void imprimirOpciones();

    void setSiguiente(Nodo_Nivel *n);
    void setAnterior(Nodo_Nivel *n);
    Nodo_Nivel * getSiguiente();
    Nodo_Nivel * getAnterior();
    int getId();

};

#endif // NODONIVEL_H
