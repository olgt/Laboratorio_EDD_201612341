#include "Lista_Niveles.h"

Lista_Niveles::Lista_Niveles()
{
    this->head = NULL;
    this->tail = NULL;
    this->size = 0;
}

Lista_Niveles::~Lista_Niveles(){
    Delete(this->getHead());
}

void Lista_Niveles::Delete(Nodo_Nivel* raiz){
    Nodo_Nivel* actual = raiz;
    Nodo_Nivel* next= raiz->getSiguiente();
    while(actual != NULL){
        actual->getMatriz()->~Matriz();
        delete actual;
        actual = NULL;
        if(next != NULL){
            next = next->getSiguiente();
        }
    }
}

void Lista_Niveles::addNode(Nodo_Nivel *nuevo){
    if(this->head == NULL){
            this->head = nuevo;
            this->tail = nuevo;
            this->size++;
        } else {
            this->tail->setSiguiente(nuevo);
            this->tail->getSiguiente()->setAnterior(this->tail);
            this->tail = nuevo;
            this->size++;
        }
}

void Lista_Niveles::searchNode(int id)
{
    Nodo_Nivel *aux = this->head;
        while(aux != NULL){
            if(aux->getId() == id){
                cout << "Nodos Encontrados: " << endl;
                cout << ",";
            }
            aux = aux->getSiguiente();
        }
}

void Lista_Niveles::deleteNode(int id){
    Nodo_Nivel *aux = this->head;
        while(aux != NULL){

            if(aux->getId() == id){
                if(aux == this->head){
                    if(aux->getSiguiente() == NULL){
                        this->head = NULL;
                    } else {
                        this->head = this->head->getSiguiente();
                        this->head->setAnterior(NULL);
                    }
                } else if (aux == this->tail){
                    this->tail = aux->getAnterior();
                    this->tail->setSiguiente(NULL);
                }
                else{
                    aux->getAnterior()->setSiguiente(aux->getSiguiente());
                    aux->getSiguiente()->setAnterior(aux->getAnterior());
                }
            }

            aux = aux->getSiguiente();
         }
}

void Lista_Niveles::graficarNiveles(string nombreProyecto){
    Nodo_Nivel* actual = this->getHead();
    while(actual != NULL){
        string nombreNivel = "Proyecto_" + nombreProyecto + "_Nivel" + to_string(actual->getId());
        actual->getMatriz()->crearGrafica(nombreNivel);
        actual = actual->getSiguiente();
    }
}

int Lista_Niveles::getSize(){
    return this->size;
}

Nodo_Nivel* Lista_Niveles::getHead(){
    return this->head;
}

Nodo_Nivel* Lista_Niveles::getTail(){
    return this->tail;
}

