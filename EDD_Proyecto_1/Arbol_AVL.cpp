#include "Arbol_AVL.h"

Arbol_AVL::Arbol_AVL()
{
    this->raiz = NULL;
}

Arbol_AVL::~Arbol_AVL(){
    Delete(this->raiz);
}

void Arbol_AVL::Delete(NodoArbol *raiz){
    if(raiz==NULL){return;}
    Delete(raiz->getIzquierda());
    Delete(raiz->getDerecha());
    raiz->getListaNiveles()->~Lista_Niveles();
    delete raiz;
}

NodoArbol* Arbol_AVL::rotacionII(NodoArbol *n, NodoArbol *n1){
    n->setIzquierda(n1->getDerecha());
    n1->setDerecha(n);
    if(n1->getFactor()==-1){
        n->setFactor(0);
        n1->setFactor(0);
    } else {
        n->setFactor(-1);
        n1->setFactor(1);
    }
    return n1;
}

NodoArbol* Arbol_AVL::rotacionDD(NodoArbol *n, NodoArbol *n1){
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

NodoArbol* Arbol_AVL::rotacionID(NodoArbol *n, NodoArbol *n1){
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

NodoArbol* Arbol_AVL::rotacionDI(NodoArbol *n, NodoArbol *n1){
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
    return n2;
}

NodoArbol* Arbol_AVL::insertar(NodoArbol *raiz, string name, bool &hc, Lista_Niveles* niveles, int id, Arbol_Binario* abb){
    int dato = sumarCaracteres(name);
    NodoArbol* n1;
    if(raiz==NULL){
        raiz = new NodoArbol(name, niveles, id);
        hc=true;
    } else if(dato<raiz->getCodigo()){
        NodoArbol* izq = insertar(raiz->getIzquierda(), name, hc, niveles, id, abb);
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
    } else if(dato>raiz->getCodigo()){
        NodoArbol* der = insertar(raiz->getDerecha(), name, hc, niveles, id, abb);
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

void Arbol_AVL::insertar(string name, Lista_Niveles* niveles, int id, Arbol_Binario* abb){
    bool b=false;
    bool *a = &b;

    this->raiz=insertar(this->raiz, name,*a, niveles, id, abb);
}


int Arbol_AVL::sumarCaracteres(string nombre){

    int codigo = 0;
    int n = nombre.length();

    char char_array[n+1];
    strcpy(char_array, nombre.c_str()); //Metodo agrega los caracteres al array

    for(int i = 0; i < n; i++){
        codigo += (int)char_array[i];
    }

    return codigo;
}

void Arbol_AVL::recorrerArbol(NodoArbol *raiz){

    if(this->getRaiz() == NULL){
        imprimirEspacios(20);
        cout << "No hay proyectos guardados";
        imprimirEspacios(5);
    }
    else {
        if(raiz->getIzquierda() != NULL){
            recorrerArbol(raiz->getIzquierda());
        }

        cout << "Proyecto: " << raiz->getName() << " Id: "<< raiz->getId() << endl;

        if(raiz->getDerecha() != NULL){
            recorrerArbol(raiz->getDerecha());
        }
    }
}

void Arbol_AVL::graficarProyecto(NodoArbol* raiz, int id){

        if(raiz->getIzquierda() != NULL){
            graficarProyecto(raiz->getIzquierda(), id);
        }

        if(raiz->getDerecha() != NULL){
            graficarProyecto(raiz->getDerecha(), id);
        }

        if(id == raiz->getId()){
            raiz->getListaNiveles()->graficarNiveles(raiz->getName());
        }

}

void Arbol_AVL::graficarTodosProyectos(NodoArbol *raiz){
    if(raiz->getIzquierda() != NULL){
        graficarTodosProyectos(raiz->getIzquierda());
    }

    if(raiz->getDerecha() != NULL){
        graficarTodosProyectos(raiz->getDerecha());
    }

    raiz->getListaNiveles()->graficarNiveles(raiz->getName());
}

//void Arbol_AVL::imprimirListaArboles(){
//    while()
//}

NodoArbol* Arbol_AVL::getRaiz(){
    return this->raiz;
}

void Arbol_AVL::crearGrafica(){
    NodoArbol* aux = this->raiz;

    ofstream MyFile("AVLGrafica.gv");
    MyFile << "digraph G {";
    MyFile << "\n";
    MyFile << "rankdir = TB; \n";
    MyFile << "node [shape=record, width=.1, height=.1]; \n";

    crearGraficaRamas(MyFile, aux);


    cout << "Done";
    MyFile << "}";
    MyFile.close();
    try {
        cout << "Creating" << endl;
        system("dot -Tps AVLGrafica.gv -o AVLGrafica.ps");
    } catch (exception e) {
        cout << "error occurred" << endl;
    }
}

void Arbol_AVL::crearGraficaRamas(ofstream &file, NodoArbol* aux){

    if(aux->getIzquierda() != NULL){
        file << "node" << aux->getCodigo() << "->" << "node" << aux->getIzquierda()->getCodigo() <<  "; \n";
        crearGraficaRamas(file, aux->getIzquierda());
    }

    cout << "CodigoNodo: " << aux->getCodigo() << endl;

    if(aux->getDerecha() != NULL){
        file << "node" << aux->getCodigo() << "->" << "node" << aux->getDerecha()->getCodigo() <<  "; \n";
        crearGraficaRamas(file, aux->getDerecha());
    }
}

