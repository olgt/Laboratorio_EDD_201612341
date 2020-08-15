#ifndef NODO_CONSTRUCCION_H
#define NODO_CONSTRUCCION_H

#include <Nodo_Nivel.h>
#include <iostream>
#include <stdlib.h>
#include <utilities.h>
using namespace std;


class Lista_Niveles
{

private:
    Nodo_Nivel *head;
    Nodo_Nivel *tail;
    int size;


public:
    Lista_Niveles();

    void addNode(Nodo_Nivel *nuevo);
    void searchNode(int id);
    void deleteNode(int id);
    int getSize();
    int getId();
    void imprimirNiveles();

};

#endif // NODO_CONSTRUCCION_H
