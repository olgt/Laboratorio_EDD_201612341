#include <QCoreApplication>

#include <menuprincipal.h>

#include <iostream>
#include "Matriz.h"
#include "Nodo_Matriz.h"
#include "Cabecera.h"
#include "Nodo_Objeto.h"

using namespace std;

MenuPrincipal nuevoMenuPrincipal;

int main()
{
    //nuevoMenuPrincipal.imprimirMenu();


    Matriz* nuevaMatriz = new Matriz();

    Nodo_Objeto* a = new Nodo_Objeto(1, "Pared x=1", 'a', "NA", 1, 2);
    Nodo_Objeto* c = new Nodo_Objeto(3, "Silla x=1", 'a', "NA", 1, 3);
    Nodo_Objeto* b = new Nodo_Objeto(2, "Sillon x =2", 'a', "NA", 2, 1);
    Nodo_Objeto* d = new Nodo_Objeto(4, "Pared x=2", 'a', "NA", 2, 4);
    Nodo_Objeto* e = new Nodo_Objeto(5, "Sillon x=3", 'a', "NA", 3, 5);
    Nodo_Objeto* f = new Nodo_Objeto(6, "Sillon x=1", 'a', "NA", 1, 4);


    nuevaMatriz->add(a);
    nuevaMatriz->add(b);
    nuevaMatriz->add(c);
    nuevaMatriz->add(d);
    nuevaMatriz->add(e);
    nuevaMatriz->add(f);

    nuevaMatriz->imprimirCabeceraX();
    nuevaMatriz->imprimirCabeceraY();
    imprimirEspacios(10);

    nuevaMatriz->crearGrafica();
    imprimirEspacios(10);

    nuevaMatriz->imprimirMatriz();

    return 0;
}
