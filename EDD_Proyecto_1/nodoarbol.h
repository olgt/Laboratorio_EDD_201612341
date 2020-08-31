#ifndef NODOARBOL_H
#define NODOARBOL_H

#include <Lista_Niveles.h>
#include <bits/stdc++.h>


class NodoArbol
{
private:
    NodoArbol *hijoDerecho;
    NodoArbol *hijoIzquierdo;

    string nombre;
    int codigo;
    Lista_Niveles *niveles;

    int factorE;


public:
    NodoArbol(string nombre); //Debo Poner *Lista de Niveles como parametro

    void setCodigo(string nombre);
    int sumarCaracteres();
    int getCodigo();

    string getName();

    void setIzquierda(NodoArbol* izq);
    void setDerecha(NodoArbol* der);

    NodoArbol* getDerecha();
    NodoArbol* getIzquierda();

    void setFactor(int factor);
    int getFactor();

};


#endif // NODOARBOL_H
