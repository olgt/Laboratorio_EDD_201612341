#include "Nodo_Nivel.h"

Nodo_Nivel::Nodo_Nivel(int id, Matriz* matriz, Arbol_Binario* abb)
{
    this->id = id;
    this->matriz = matriz;
    this->abb = abb;
    this->siguiente = NULL;
    this->anterior = NULL;
}


Nodo_Nivel* Nodo_Nivel::getSiguiente(){
    return this->siguiente;
}

Nodo_Nivel* Nodo_Nivel::getAnterior(){
    return this->anterior;
}

void Nodo_Nivel::setSiguiente(Nodo_Nivel *n){
    this->siguiente = n;
}

void Nodo_Nivel::setAnterior(Nodo_Nivel *n){
    this->anterior = n;
}

void Nodo_Nivel::imprimirOpciones(){
    int opcion = 0;
    imprimirEspacios(10);

    while(opcion != 5){
        string opciones[] = {"1. Agregar Nivel", "2. Editar Nivel", "3. Eliminar Nivel",
                             "4. Eliminar Proyecto", "5. Salir"};

        for(int i = 0; i < 6; i++){
            cout << opciones[i] << endl;
        }

        cout << "Escoja su opcion: ";
        cin >> opcion;
    }
}

int Nodo_Nivel::getId(){
    return this->id;
}

Matriz* Nodo_Nivel::getMatriz(){
    return this->matriz;
}

void Nodo_Nivel::setABB(Arbol_Binario* abb){
    this->abb = abb;
}
