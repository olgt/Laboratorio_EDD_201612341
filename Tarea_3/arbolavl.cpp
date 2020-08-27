#include "arbolavl.h"

ArbolAVL::ArbolAVL()
{
    this->raiz = NULL;
}

ArbolAVL::~ArbolAVL(){
    Delete(this->raiz);
}

void ArbolAVL::Delete(NodoArbol *raiz){
    if(raiz==NULL){return;}
    Delete(raiz->getIzquierda());
    Delete(raiz->getDerecha());
    delete raiz;
}

NodoArbol* ArbolAVL::rotacionII(NodoArbol *n, NodoArbol *n1){
    n->setIzquierda(n1->getDerecha());
    n1->setDerecha(n);
    if(n1->getFactor()==1){
        n->setFactor(0);
        n1->setFactor(0);
    } else {
        n->setFactor(-1);
        n1->setFactor(1);
    }
    return n1;
}

NodoArbol* ArbolAVL::rotacionDD(NodoArbol *n, NodoArbol *n1){
    n->setDerecha(n1->getIzquierda());
    n1->setIzquierda(n);
    if(n1->getFactor()==1){
        n->setFactor(0);
        n1->setFactor(0);
    } else {
        n->setFactor(1);
        n1->setFactor(-1);
    }
    return n1;
}

NodoArbol* ArbolAVL::rotacionID(NodoArbol *n, NodoArbol *n1){
    NodoArbol* n2=n1->getDerecha();
    n->setIzquierda(n2->getDerecha());
    n2->setDerecha(n);
    n1->setDerecha(n2->getIzquierda());

    n2->setIzquierda(n1);

    if(n2->getFactor()==1){
        n1->setFactor(-1);
    } else {
        n1->setFactor(0);
    }

    if(n2->getFactor()==-1){
        n->setFactor(1);
    } else {
        n->setFactor(0);
    }
    n2->setFactor(0);
    return n2;
}

NodoArbol* ArbolAVL::rotacionDI(NodoArbol *n, NodoArbol *n1){
    NodoArbol* n2=n1->getIzquierda();
    n->setDerecha(n2->getIzquierda());
    n2->setIzquierda(n);
    n1->setIzquierda(n2->getDerecha());
    n2->setDerecha(n1);

    if(n2->getFactor()==1){
        n->setFactor(-1);
    } else {
        n->setFactor(0);
    }
    if(n2->getFactor()==-1){
        n1->setFactor(1);
    } else {
        n1->setFactor(0);
    }
    n2->setFactor(0);
    return raiz;
}

NodoArbol* ArbolAVL::insertar(NodoArbol *raiz, int dato, bool &hc){
    NodoArbol* n1;
    if(raiz==NULL){
        raiz = new NodoArbol(dato);
        hc=true;
    } else if(dato<raiz->getData()){
        NodoArbol* izq = insertar(raiz->getIzquierda(), dato, hc);
        raiz->setIzquierda(izq);
        if(hc){
            switch(raiz->getFactor()){
                case 1:
                raiz->setFactor(0);
                hc=false;
                    break;
            case 0:
                raiz->setFactor(-1);
                break;

            case -1:
                n1=raiz->getIzquierda();
                if(n1->getFactor()==-1){
                    raiz=rotacionII(raiz, n1);
                } else {
                    raiz=rotacionID(raiz,n1);
                }


            }
        }
    } else if(dato>raiz->getData()){
        NodoArbol* der = insertar(raiz->getDerecha(), dato, hc);
        raiz->setDerecha(der);
        if(hc){
            switch(raiz->getFactor()){
            case 1:
                n1=raiz->getDerecha();
                if(n1->getFactor()==1){
                    raiz=rotacionDD(raiz,n1);
                } else {
                    raiz=rotacionDI(raiz, n1);
                }
                hc=false;
                break;
            case 0:
                raiz->setFactor(1);
                break;
            case -1:
                raiz->setFactor(0);
                hc=false;
                break;
            }
        }
    }
    return raiz;
}

void ArbolAVL::insertar(int valor){
    bool b=false;
    bool *a = &b;

    this->raiz=insertar(this->raiz,valor,*a);
}










