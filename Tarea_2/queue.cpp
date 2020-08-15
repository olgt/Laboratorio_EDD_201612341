#include "queue.h"

template<class T>
Queue<T>::Queue()
{
    this->top=NULL;
    this->bottom=NULL;
}

template<class T>
Queue<T>::~Queue(){
    NodoGenerico<T>*aux=this->top;
    NodoGenerico<T>*tmp=NULL;
    while(aux!=NULL){
        tmp=aux->getSiguiente();
        delete aux;
        aux=tmp;
    }
}


template<class T>
void Queue<T>::enqueue(T valor){
    if(this->top==NULL){
        NodoGenerico<T> *nuevo=new NodoGenerico<T>(valor);
        this->top=nuevo;
        this->bottom=nuevo;
    }else{
        NodoGenerico<T>*nuevo=new NodoGenerico<T>(valor);
        NodoGenerico<T>*aux=this->bottom;
        aux->setSiguiente(nuevo);
        this->bottom=nuevo;
    }
}

template <class T>
NodoGenerico<T>* Queue<T>::dequeue(){
    if(top==NULL){return NULL;}
    NodoGenerico<T>*aux=top;
    top=top->getSiguiente();
    return aux;
}

template<class T>
void Queue<T>::vaciar(){
    NodoGenerico<T>*aux=this->top;
    NodoGenerico<T>*tmp;
    while(aux!=NULL){
        //cout<<aux->getValue()<<"\n";
        tmp=aux->getSiguiente();
        delete aux;
        aux=tmp;
    }
}

template<class T>
void Queue<T>::insertar(T persona){
    bool cambiarTmp = false;
    NodoGenerico<T> *nuevo = new NodoGenerico<T>(persona);
    if(this->top==NULL){
        this->top = nuevo;
        this->bottom = nuevo;
    } else {
        NodoGenerico<T> *aux1 = this->top;
        NodoGenerico<T> *tmp = aux1;
        while(aux1 != NULL){
            if(nuevo->getValue() >= aux1->getValue()){
                cout << "Valor nuevo" ;
                cout << nuevo->getValue() << endl;
                cout << "Valor aux:" ;
                cout << aux1->getValue() << endl;
                if(aux1 == this->top){
                    nuevo->setSiguiente(this->top);
                    this->top = nuevo;
                    break;
                } else if(aux1 == this->bottom){
                    nuevo->setSiguiente(this->bottom);
                    tmp->setSiguiente(nuevo);
                    break;
                } else{
                    nuevo->setSiguiente(aux1);
                    tmp->setSiguiente(nuevo);
                    break;
                }
            }else if (aux1 == this->bottom){
                aux1->setSiguiente(nuevo);
                this->bottom=nuevo;
                break;
            }
            if(cambiarTmp == true){
                tmp = tmp->getSiguiente();
            }
            aux1 = aux1->getSiguiente();
            cambiarTmp = true;
        }

    }
}


template<class T>
void Queue<T>::showList(){
    NodoGenerico<T> *aux = this->top;
    while(aux != NULL){
        cout << aux->getValue() << endl;
        aux = aux->getSiguiente();
    }
}
