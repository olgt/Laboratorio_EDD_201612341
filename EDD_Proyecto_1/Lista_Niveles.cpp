#include "Lista_Niveles.h"

Lista_Niveles::Lista_Niveles()
{
    this->head = NULL;
    this->tail = NULL;
    this->size = 0;
}

//TODO:
void Lista_Niveles::imprimirNiveles(){
    imprimirEspacios(10);
    int opcion = 0;

    while(opcion != 3){
        cout << "Nivel 1" << endl;
        cout << "Nivel 2" << endl;
        cout << "3. Salir" << endl;
        cout << "Escoja su opcion: ";

        cin >> opcion;
        imprimirEspacios(10);
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

int Lista_Niveles::getSize(){
    return this->size;
}
