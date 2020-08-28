#include <QCoreApplication>

#include "arbolavl.h"
#include "nodoarbol.h"
#include "arbol_binario.h"
#include <iostream>

int main()
{
    Arbol_Binario* nuevoArbolBinario = new Arbol_Binario();


    nuevoArbolBinario->insertar(10);
    nuevoArbolBinario->insertar(1);
    nuevoArbolBinario->insertar(20);
    nuevoArbolBinario->insertar(15);
    nuevoArbolBinario->insertar(8);
    nuevoArbolBinario->insertar(96);
    nuevoArbolBinario->insertar(23);
    nuevoArbolBinario->insertar(4);
    nuevoArbolBinario->insertar(7);
    nuevoArbolBinario->insertar(32);

    cout << "Recorrdigo Preorden:" << endl;
    nuevoArbolBinario->recorrerPreorden(nuevoArbolBinario->getRaiz());
    cout << "Recorrdigo PostOrden:" << endl;
    nuevoArbolBinario->recorrerPostorden(nuevoArbolBinario->getRaiz());

    cout << "Recorrdigo Inorden:" << endl;
    nuevoArbolBinario->recorrerInorden(nuevoArbolBinario->getRaiz());

    delete nuevoArbolBinario;

    return 0;
}
