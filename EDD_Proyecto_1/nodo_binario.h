#ifndef NODO_BINARIO_H
#define NODO_BINARIO_H

#include <iostream>
#include "string.h"
#include "lista_puntos.h"
using namespace std;

class Nodo_Binario
{
private:

    Nodo_Binario *hijoDerecho;
    Nodo_Binario *hijoIzquierdo;
    Lista_Puntos *xy;

    int id;
    string nombre;
    char letra;
    string color;
    int x;
    int y;


public:
    Nodo_Binario(int id, string nombre, char letra, string color, Lista_Puntos* xy);

    void setIzquierda(Nodo_Binario* izq);
    void setDerecha(Nodo_Binario* der);

    Nodo_Binario* getDerecha();
    Nodo_Binario* getIzquierda();

    int getId();
    string getName();
    char getLetra();
    string getColor();
    int getX();
    int getY();

    void setId(int id);
    void setName(string nombre);
    void setLetra(char letra);
    void setColor(string color);

};

#endif // NODO_BINARIO_H
