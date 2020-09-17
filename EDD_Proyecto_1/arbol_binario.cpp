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
    raiz->getListaPuntos()->~Lista_Puntos();
    delete raiz;
}

Nodo_Binario* Arbol_Binario::getObjeto(int id, Nodo_Binario* raiz){
    Nodo_Binario* actual = NULL;

    if(raiz->getIzquierda() != NULL){
        if(actual == NULL){
            actual = getObjeto(id, raiz->getIzquierda());
        }
    }

    if(raiz->getDerecha() != NULL){
        if(actual == NULL){
            actual = getObjeto(id, raiz->getDerecha());
        }
    }

    if(id == raiz->getId()){
        return raiz;
    } else {
        return actual;
    }
}

Nodo_Binario* Arbol_Binario::getRaiz(){
    return this->raiz;
}

Nodo_Binario* Arbol_Binario::insertar(Nodo_Binario* raiz, int id, string nombre, char letra, string color, Lista_Puntos* xy, Nodo_Binario* padre){
    if(raiz==NULL){
        raiz = new Nodo_Binario(id, nombre, letra, color, xy, padre);
        raiz->setDerecha(NULL);
        raiz->setIzquierda(NULL);
    } else if(id<raiz->getId()){
        Nodo_Binario* izq = insertar(raiz->getIzquierda(), id, nombre, letra, color, xy, raiz);
        if(izq->getId() != raiz->getId()){
            raiz->setIzquierda(izq);
        }
    } else if(id>raiz->getId()){
        Nodo_Binario* der = insertar(raiz->getDerecha(), id, nombre, letra, color, xy, raiz);
        if(der->getId() != raiz->getId()){
            raiz->setDerecha(der);
        }
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
    cout << "* " << raiz->getId() << ". " << raiz->getName()
         << "#X: " << raiz->getListaPuntos()->getSizeX() << "#Y: " << raiz->getListaPuntos()->getSizeY() << endl;;
    recorrerInorden(raiz->getDerecha());

}

Arbol_Binario* Arbol_Binario::copiarArbolInOrden(Arbol_Binario* arbolCopiado){



}

void Arbol_Binario::insertar(int id, string nombre, char letra, string color, Lista_Puntos* xy){
    this->raiz=insertar(this->getRaiz(), id, nombre, letra, color, xy, NULL);
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
        MyFile << "Objeto_" << this->getRaiz()->getName() << "; \n";
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

    cout << "CodigoNodo: " << aux->getId() << endl;

    if(aux->getIzquierda() != NULL){
        file << "Objeto_" << aux->getId() << aux->getName() << "->" << "Objeto_" << aux->getIzquierda()->getId() << aux->getIzquierda()->getName() <<  "; \n";
        crearGraficaRamas(file, aux->getIzquierda());
    }

    if(aux->getDerecha() != NULL){
        file << "Objeto_" << aux->getId() << aux->getName() << "->" << "Objeto_" << aux->getDerecha()->getId()<< aux->getDerecha()->getName() <<  "; \n";
        crearGraficaRamas(file, aux->getDerecha());
    }
}

//Funciones para EliminarNodoDeArbolBinario

void Arbol_Binario::eliminarNodo(Nodo_Binario* raiz, int id){
    if(this->getRaiz() == NULL){
        return;
    }
    else if(id < raiz->getId()){
        eliminarNodo(raiz->getIzquierda(), id);
    }
    else if(id > raiz->getId()){
        eliminarNodo(raiz->getDerecha(), id);
    }
    else if (id == raiz->getId()){
        eliminarNodoDeArbol(raiz);
    }
}

void Arbol_Binario::eliminarNodoDeArbol(Nodo_Binario *raizEliminar){
    if(raizEliminar->getIzquierda() && raizEliminar->getDerecha()){ //Si nodo tiene izq & der
        Nodo_Binario* menor = minimo(raizEliminar);
        raizEliminar->setId(menor->getId());
        raizEliminar->setName(menor->getName());
        raizEliminar->setColor(menor->getColor());
        raizEliminar->setLetra(menor->getLetra());
        raizEliminar->setListaPuntos(menor->getListaPuntos());

        eliminarNodoDeArbol(menor);
    }
    else if(raizEliminar->getIzquierda()){
        reemplazar(raizEliminar, raizEliminar->getIzquierda());
        destruir(raizEliminar);
    } else if (raizEliminar->getDerecha()){
        reemplazar(raizEliminar, raizEliminar->getDerecha());
        destruir(raizEliminar);
    } else{
        reemplazar(raizEliminar, NULL);
        destruir(raizEliminar);
    }
}

//Funcion Determina nodo mas izquierdo
Nodo_Binario* Arbol_Binario::minimo(Nodo_Binario* raiz){
    if(raiz == NULL){
        return NULL;
    }
    if(raiz->getIzquierda()){
        return minimo(raiz->getIzquierda());
    }
    else {
        return raiz;
    }
}

void Arbol_Binario::reemplazar(Nodo_Binario* nodoRemplazar, Nodo_Binario* nuevoNodo){
    if(nodoRemplazar->getPadre()){
        if(nodoRemplazar->getId() == nodoRemplazar->getPadre()->getIzquierda()->getId()){
            nodoRemplazar->getPadre()->setIzquierda(nuevoNodo);
        }
        else if(nodoRemplazar->getId() == nodoRemplazar->getPadre()->getDerecha()->getId()){
            nodoRemplazar->getPadre()->setDerecha(nuevoNodo);
        }
    }
    if(nuevoNodo){
        //asignar padre
        nuevoNodo->setPadre(nodoRemplazar->getPadre());

    }
}

void Arbol_Binario::destruir(Nodo_Binario *raizEliminar){
    raizEliminar->setIzquierda(NULL);
    raizEliminar->setDerecha(NULL);
    delete raizEliminar;
}

