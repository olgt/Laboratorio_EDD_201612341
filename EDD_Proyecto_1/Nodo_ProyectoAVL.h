#ifndef NODO_PROYECTOAVL_H
#define NODO_PROYECTOAVL_H

#include <iostream>
#include <Lista_Niveles.h>
#include <bits/stdc++.h>
using namespace std;

class Nodo_ProyectoAVL
{
private:
    string nombre;
    int codigo;
    Lista_Niveles *niveles;

public:
    Nodo_ProyectoAVL(string nombre, Lista_Niveles *niveles);

    int sumarCaracteres();
    int getCodigo();
    string getName();

};

#endif // NODO_PROYECTOAVL_H
