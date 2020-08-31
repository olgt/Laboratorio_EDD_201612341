#include "lista_puntos.h"

Lista_Puntos::Lista_Puntos()
{
    this->head = NULL;
    this->tail = NULL;

};


void Lista_Puntos::addNode(Nodo_Puntos *nuevo){
    if(this->head == NULL){
        this->head = nuevo;
        this->tail = nuevo;

    } else {
        this->tail->setSiguiente(nuevo);
        this->tail = nuevo;

    }
    //printLinkedList();

}

/*void Lista_Puntos::searchNode(int id){
    Nodo_Puntos *aux = this->head;
    while(aux != NULL){
        if(aux->getId() == id){
            cout << "Nodos Encontrados: " << endl;
            cout << aux->getName();
            cout << ",";
        }
        aux = aux->getSiguiente();
    }
}*/

void Lista_Puntos::deleteNode(int x, int y){
    Nodo_Puntos *aux = this->head;
    Nodo_Puntos *temp = this->head;
    while(aux != NULL){
        if(aux->getX() == x && aux->getY() == y){
            if(aux == this->head){
                this->head = this->head->getSiguiente();
            } else if (aux == this->tail){
                temp->setSiguiente(NULL);
                this->tail = temp;
            }
            else{
                temp->setSiguiente(aux->getSiguiente());
            }
        }
        aux = aux->getSiguiente();
        if(temp != aux && temp->getSiguiente() != aux){
            temp = temp->getSiguiente();
        }
    }
}

