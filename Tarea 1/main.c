#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ListaC.h"
#include "NodoC.h"

int main(){
    NodoA* a=newNodoC(1);
    NodoA* b=newNodoC(2);
    NodoC* c=newNodoC(3);
    NodoC* d=newNodoC(4);
    NodoC* e=newNodoC(5);
    NodoC* f=newNodoC(6);
    NodoC* g=newNodoC(7);
    NodoC* h=newNodoC(8);
    NodoC* i=newNodoC(9);
    NodoC* j=newNodoC(10);

    ListaC* l=nuevaLista();

    add(l,a);
    add(l,b);
    add(l,c);
    add(l,d);
    add(l,e);
    add(l,f);
    add(l,g);
    add(l,h);
    add(l,i);
    add(l,j);

    borrarNodo(l, 3);
    getNodo(l, 4);

    imprimir(l);
    generar(l);
    Liberar(l);
    free(l);
    return 0;
}
