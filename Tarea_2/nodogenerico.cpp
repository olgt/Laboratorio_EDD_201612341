#include "nodogenerico.h"

template<class T>
NodoGenerico<T>::NodoGenerico(T valor){
    this->valor=valor;
    this->siguiente=NULL;
}

template<class T>
T NodoGenerico<T>::getValue(){
    return this->valor;
}


template<class T>
void NodoGenerico<T>::setValue(T valor){
    this->valor=valor;
}

template <class T>
void NodoGenerico<T>::setSiguiente(NodoGenerico* siguiente){
    this->siguiente=siguiente;
}

template<class T>
NodoGenerico<T>* NodoGenerico<T>::getSiguiente(){
    return  this->siguiente;
}
