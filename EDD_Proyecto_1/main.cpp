#include <QCoreApplication>

#include <menuprincipal.h>

#include <iostream>
#include "Matriz.h"
#include "Nodo_Matriz.h"
#include "Cabecera.h"
#include "Nodo_Objeto.h"
#include "Arbol_AVL.h"
#include "nodoarbol.h"
#include "arbol_binario.h"
#include "lista_puntos.h"

using namespace std;

MenuPrincipal nuevoMenuPrincipal;

int main()
{
    //nuevoMenuPrincipal.imprimirMenu();

    /*
    Matriz* nuevaMatriz = new Matriz();

    Nodo_Objeto* a = new Nodo_Objeto(1, "1", 'a', "NA", 1, 2);
    Nodo_Objeto* c = new Nodo_Objeto(3, "3", 'a', "NA", 1, 3);
    Nodo_Objeto* b = new Nodo_Objeto(2, "2", 'a', "NA", 2, 1);
    Nodo_Objeto* d = new Nodo_Objeto(4, "4", 'a', "NA", 2, 4);
    Nodo_Objeto* e = new Nodo_Objeto(5, "5", 'a', "NA", 3, 5);
    Nodo_Objeto* f = new Nodo_Objeto(6, "6", 'a', "NA", 1, 4);


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
    */

    Arbol_AVL *nuevo = new Arbol_AVL();

    nuevo->insertar("hola"); //420
    nuevo->insertar("que"); //331
    nuevo->insertar("yes"); //337

    nuevo->insertar("no"); //231
    nuevo->insertar("tri"); //335
    nuevo->insertar("tra"); //327

    nuevo->insertar("cuatro"); //654
    nuevo->insertar("cuat"); //543

    nuevo->crearGrafica();

    Arbol_Binario* nuevoBinario = new Arbol_Binario();
    Lista_Puntos* nuevaLista = new Lista_Puntos();

    nuevoBinario->insertar(4, "hola", 'a', "negro", nuevaLista);
    nuevoBinario->insertar(6, "hola", 'a', "negro", nuevaLista);
    nuevoBinario->insertar(2, "hola", 'a', "negro", nuevaLista);
    nuevoBinario->insertar(3, "hola", 'a', "negro", nuevaLista);
    nuevoBinario->insertar(1, "hola", 'a', "negro", nuevaLista);
    nuevoBinario->insertar(0, "hola", 'a', "negro", nuevaLista);
    nuevoBinario->insertar(10, "hola", 'a', "negro", nuevaLista);
    nuevoBinario->insertar(8, "hola", 'a', "negro", nuevaLista);
    nuevoBinario->insertar(9, "hola", 'a', "negro", nuevaLista);

    nuevoBinario->crearGrafica();


    return 0;
}
