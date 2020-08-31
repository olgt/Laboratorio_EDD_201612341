#include "arbol_binario.h"

Arbol_Binario::Arbol_Binario()
{
    this->raiz = NULL;
}

Arbol_Binario::~Arbol_Binario(){
    Delete(this->raiz);
}


void Arbol_Binario::Delete(Nodo_Binario *raiz){
    if(raiz==NULL){return;}
    Delete(raiz->getIzquierda());
    Delete(raiz->getDerecha());
    delete raiz;
}

Nodo_Binario* Arbol_Binario::getRaiz(){
    return this->raiz;
}

Nodo_Binario* Arbol_Binario::insertar(Nodo_Binario* raiz, int id, string nombre, char letra, string color, Lista_Puntos* xy){
    if(raiz==NULL){
        raiz = new Nodo_Binario(id, nombre, letra, color, xy);
        raiz->setDerecha(NULL);
        raiz->setIzquierda(NULL);
    } else if(id<raiz->getId()){
        Nodo_Binario* izq = insertar(raiz->getIzquierda(), id, nombre, letra, color, xy);
        raiz->setIzquierda(izq);

    } else if(id>raiz->getId()){
        Nodo_Binario* der = insertar(raiz->getDerecha(), id, nombre, letra, color, xy);
        raiz->setDerecha(der);
    }
    return raiz;
}

void Arbol_Binario::recorrerPostorden(Nodo_Binario *raiz){

    if(raiz->getIzquierda() != NULL){
        recorrerPostorden(raiz->getIzquierda());
    }
    if(raiz->getDerecha() != NULL){
        recorrerPostorden(raiz->getDerecha());
    }

    cout << "Dato: " << raiz->getId() << endl;
}

void Arbol_Binario::recorrerPreorden(Nodo_Binario *raiz){

    cout << "Dato: " << raiz->getId() << endl;

    if(raiz->getIzquierda() != NULL){
        recorrerPreorden(raiz->getIzquierda());
    }
    if(raiz->getDerecha() != NULL){
        recorrerPreorden(raiz->getDerecha());
    }
}

void Arbol_Binario::recorrerInorden(Nodo_Binario* raiz){

    if(raiz == NULL){
        return;
    }

    recorrerInorden(raiz->getIzquierda());
    cout << "Dato: " << raiz->getId() << endl;;
    recorrerInorden(raiz->getDerecha());

}

void Arbol_Binario::insertar(int id, string nombre, char letra, string color, Lista_Puntos* xy){
    this->raiz=insertar(this->getRaiz(), id, nombre, letra, color, xy);
}

void Arbol_Binario::crearGrafica(){
    Nodo_Binario* aux = this->getRaiz();

    cout << "ARBOL BINARIO" << endl;
    ofstream MyFile("BinarioGrafica.gv");
    MyFile << "digraph G {";
    MyFile << "\n";
    MyFile << "rankdir = TB; \n";
    MyFile << "node [shape=record, width=.1, height=.1]; \n";

    if(this->getRaiz()->getDerecha() == NULL && this->getRaiz()->getIzquierda() == NULL){
        MyFile << "node" << this->getRaiz()->getId() << "; \n";
    } else {
        try {
            crearGraficaRamas(MyFile, aux);
        } catch (exception e) {
            cout << e.what() << endl;
        }
    }

    cout << "Done";
    MyFile << "}";
    MyFile.close();
    try {
        cout << "Creating" << endl;
        system("dot -Tps BinarioGrafica.gv -o BinarioGrafica.ps");
    } catch (exception e) {
        cout << "Oscar error occurred" << endl;
    }

}

void Arbol_Binario::crearGraficaRamas(ofstream &file, Nodo_Binario* aux){

    cout << "Aqui" << endl;
    cout << "CodigoNodo: " << aux->getId() << endl;

    if(aux->getIzquierda() != NULL){
        file << "node" << aux->getId() << "->" << "node" << aux->getIzquierda()->getId() <<  "; \n";
        crearGraficaRamas(file, aux->getIzquierda());
    }


    if(aux->getDerecha() != NULL){
        file << "node" << aux->getId() << "->" << "node" << aux->getDerecha()->getId() <<  "; \n";
        crearGraficaRamas(file, aux->getDerecha());
    }
}

