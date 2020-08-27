#ifndef NODOARBOL_H
#define NODOARBOL_H


class NodoArbol
{
private:
    NodoArbol *hijoDerecho;
    NodoArbol *hijoIzquierdo;

    int data;

    //Para Nodos AVL
    int factorE;

public:
    NodoArbol(int dato);
    void setData(int dato);

    void setIzquierda(NodoArbol* izq);
    void setDerecha(NodoArbol* der);

    NodoArbol* getDerecha();
    NodoArbol* getIzquierda();

    int getData();

    //Para Nodos AVL
    void setFactor(int factor);
    int getFactor();

};

#endif // NODOARBOL_H
