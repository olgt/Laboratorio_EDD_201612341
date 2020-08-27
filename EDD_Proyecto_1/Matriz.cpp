#include "Matriz.h"

Matriz::Matriz()
{
    this->horizontal = NULL;
    this->vertical = NULL;
}

Matriz::~Matriz(){
    Nodo_Matriz *aux, *aux2, *tmp, *tmp2, *extra, *extra2;

    aux=this->vertical;
    tmp=this->horizontal;
    while(aux!=NULL){
        extra = aux->getAbajo();
        aux2 = aux->getDerecha();
        while(aux2!=NULL){
            extra2 = aux->getDerecha();
            delete aux2;
            aux2 = extra2;
        }
        delete aux;
        aux = extra;
    }
    while(tmp!=NULL){
        tmp2 = tmp->getDerecha();
        delete tmp;
        tmp =  tmp2;
    }
}

Cabecera* Matriz::crearHorizontal(int y){
    if(this->horizontal == NULL){
        Cabecera* nueva = new Cabecera(y);
        this->horizontal = nueva;
        return nueva;
    }
    Cabecera* aux = this->horizontal;
    cout << "Acutal: " << aux->getPos() << endl;;
    if(y <= aux->getPos()){
         cout << "Caso requerido" << endl;
         Cabecera* nueva = new Cabecera(y);
         nueva->setDerecha(aux);
         this->horizontal->setIzquierda(nueva);
         this->horizontal = nueva;
         return nueva;
    }
    while(aux->getDerecha() != NULL){
        if(y <= aux->getPos() && y <= (((Cabecera*)aux->getDerecha())->getPos())){
            Cabecera* nueva =new Cabecera(y);
            Cabecera* tmp = (Cabecera*)aux->getDerecha();

            tmp->setIzquierda(nueva);
            nueva->setDerecha(tmp);
            aux->setDerecha(nueva);
            nueva->setIzquierda(aux);

            return nueva;
        }
        aux=(Cabecera*)aux->getDerecha();
    }

    Cabecera* nueva = new Cabecera(y);
    aux->setDerecha(nueva);
    nueva->setIzquierda(aux);
    return nueva;

}

Cabecera* Matriz::crearVertical(int x){
    if(this->vertical== NULL){
        Cabecera* nueva = new Cabecera(x);
        this->vertical = nueva;
        return nueva;
    }
    Cabecera* aux = this->vertical;
    if(x <= aux->getPos()){
         Cabecera* nueva = new Cabecera(x);
         nueva->setAbajo(aux);
         this->vertical->setAbajo(nueva);
         this->vertical = nueva;
         return nueva;
    }
    while(aux->getAbajo() != NULL){
        if(x <= aux->getPos() && x <= ((Cabecera*)aux->getAbajo())->getPos()){
            Cabecera* nueva =new Cabecera(x);
            Cabecera* tmp = (Cabecera*)aux->getAbajo();

            tmp->setArriba(nueva);
            nueva->setAbajo(tmp);
            aux->setAbajo(nueva);
            nueva->setArriba(aux);

            return nueva;
        }
        aux=(Cabecera*)aux->getAbajo();
    }

    Cabecera* nueva = new Cabecera(x);
    aux->setAbajo(nueva);
    nueva->setArriba(aux);

    return nueva;
}

Nodo_Matriz* Matriz::obtenerUltimoHorizontal(Cabecera* cabecera, int y){
    if(cabecera->getDerecha() == NULL){return cabecera;}
    Nodo_Matriz* aux = cabecera->getDerecha();
    while(aux->getDerecha() != NULL){
        if(y <= (((Nodo_Objeto*)aux)->getY())){
               return aux;
        }
        aux=aux->getDerecha();
    }
    if(y <= (((Nodo_Objeto*)aux)->getY())){
        return aux->getIzquierda();
    }
    return aux;

}

Nodo_Matriz* Matriz::obtenerUltimoVertical(Cabecera* cabecera, int x){
    if(cabecera->getAbajo() == NULL){return cabecera;}
    Nodo_Matriz* aux = cabecera->getAbajo();
    while(aux->getAbajo() != NULL){
        if(x <= ((Nodo_Objeto*)aux)->getX()){
               return aux;
        }
        aux=aux->getAbajo();
    }
    if(x <= ((Nodo_Objeto*)aux)->getX()){
        return aux->getArriba();
    }
    return aux;
}


Cabecera* Matriz::getVertical(int x){
    if(this->vertical == NULL){return NULL;}
    Cabecera* aux = this->vertical;
    while(aux != NULL){
        if(aux->getPos() == x){
            return aux;
        }
        aux = (Cabecera*)aux->getAbajo();
    }
    return NULL;
}

Cabecera* Matriz::getHorizontal(int y){
    if(this->vertical == NULL){return NULL;}
    Cabecera* aux = this->horizontal;
    while(aux != NULL){
        if(aux->getPos() == y){
            cout << "Aux valor: " << aux->getPos() << endl;
            cout << "Y valor: " << y << endl;
            return aux;
        }
        aux = (Cabecera*)aux->getDerecha();
    }
    return NULL;
}


void Matriz::add(Nodo_Objeto *nuevo){
    Cabecera* vertical = this->getVertical(nuevo->getX());
    Cabecera* horizontal = this->getHorizontal(nuevo->getY());

    if(vertical == NULL){
        vertical = crearVertical(nuevo->getX());
    }
    if(horizontal == NULL){
        horizontal = crearHorizontal(nuevo->getY());
    }
    Nodo_Matriz *izquierda = this->obtenerUltimoHorizontal(vertical, nuevo->getY());
    Nodo_Matriz *superior = this->obtenerUltimoVertical(horizontal, nuevo->getX());

    if(izquierda->getDerecha() == NULL){
        izquierda->setDerecha(nuevo);
        nuevo->setIzquierda(izquierda);
    }else{
        Nodo_Matriz* tmp = izquierda->getDerecha();
        izquierda->setDerecha(nuevo);
        nuevo->setIzquierda(izquierda);
        tmp->setIzquierda(nuevo);
        nuevo->setDerecha(tmp);
    }
    if(superior->getAbajo()==NULL){
        superior->setAbajo(nuevo);
        nuevo->setArriba(superior);
    } else {
        Nodo_Matriz* tmp = superior->getAbajo();
        superior->setAbajo(nuevo);
        nuevo->setArriba(superior);
        tmp->setArriba(nuevo);
        nuevo->setAbajo(tmp);
    }
}

void Matriz::imprimirCabeceraX(){
    Nodo_Matriz* aux = this->vertical;
    while(aux != NULL){
        cout << "Cabecera X: ";
        cout << ((Cabecera*)aux)->getPos();
        cout << ", ";
        aux = aux->getAbajo();
    }
    cout << endl;
}

void Matriz::imprimirCabeceraY(){
    Nodo_Matriz* aux = this->horizontal;
    while(aux != NULL){
        cout << "Cabecera Y: ";
        cout << ((Cabecera*)aux)->getPos();
        cout << ", ";
        aux = aux->getDerecha();
    }
}

void Matriz::imprimirMatriz(){
    Nodo_Matriz *aux = this->vertical;
    Nodo_Matriz *aux2 = this->vertical;

    while(aux2 != NULL){
        aux = aux->getDerecha();
        while(aux!=NULL){
            cout << ((Nodo_Objeto*)aux)->getObjeto();

            if(aux->getDerecha() == NULL){cout << "; \n";}
            else { cout << ", ";}

            aux = aux->getDerecha();
        }
        aux = aux2->getAbajo();
        aux2 = aux2->getAbajo();
    }
}


void Matriz::crearGrafica(){
    Nodo_Matriz *vertical = this->vertical;
    Nodo_Matriz *horizontal = this->horizontal;

    Nodo_Matriz *aux = this->vertical;
    Nodo_Matriz *aux2 = this->vertical;

    Nodo_Matriz *tmp1 = this->vertical;
    Nodo_Matriz *tmp2 = this->vertical;


        ofstream MyFile("MatrizGrafica.gv");
        MyFile << "digraph G {";
        MyFile << "\n";
        MyFile << "rankdir = TB; \n";
        MyFile << "node [shape=box, width=.1, height=.1]; \n";
        MyFile << "node0 [label = \"Matriz\"] \n";

        //Poniendo ranks en nodo cabecera X (Columnas se ponen automatica mente de arriba-abajo
        MyFile << "{ \n";
        MyFile << "rank=same; ";

        while(horizontal != NULL){
          MyFile << "nodeY" << ((Cabecera*)horizontal)->getPos();

          if(horizontal->getDerecha() == NULL){MyFile << "; \n";}
          else { MyFile << ", ";}

          horizontal = horizontal->getDerecha();
        }
        MyFile << "} \n";
        horizontal = this->horizontal;

        //Poniendo ranks de nodos matriz X (Columnas se ponen automatica mente de arriba-abajo
          while(aux2 != NULL){
              MyFile << "{ \n";
              MyFile << "rank=same; ";
              aux = aux->getDerecha();

              while(aux!=NULL){
                  MyFile << "node" << ((Nodo_Objeto*)aux)->getId();

                  if(aux->getDerecha() == NULL){MyFile << "; \n";}
                  else { MyFile << ", ";}

                  aux = aux->getDerecha();
                  noNodo++;
              }
              aux = aux2->getAbajo();
              aux2 = aux2->getAbajo();
              MyFile << "} \n";

          }
          aux2 = this->vertical;
          aux = this->vertical;


        //Creando Nodos de cabeceras, vamos aumentando en x, luego pasamos al siguiente Y y se comienza desde x again
          while(horizontal != NULL){
            MyFile << "nodeY" << ((Cabecera*)horizontal)->getPos() << "[label = \"" << ((Cabecera*)horizontal)->getPos() << "\"]; \n";
            horizontal = horizontal->getDerecha();
          }
          while(vertical != NULL){
              MyFile << "nodeX" << ((Cabecera*)vertical)->getPos()  << "[label = \"" << ((Cabecera*)vertical)->getPos() << "\"]; \n";
              vertical = vertical->getAbajo();
          }


        //Creando Nodos de Matriz, aumentando x, pasamos y y de vuelta aumentar x
          while(aux2 != NULL){
              aux = aux->getDerecha();
              while(aux!=NULL){
                  MyFile << "node" << ((Nodo_Objeto*)aux)->getId() << "[label = \"" << ((Nodo_Objeto*)aux)->getObjeto() << "\"]; \n";
                  aux = aux->getDerecha();
              }
              aux = aux2->getAbajo();
              aux2 = aux2->getAbajo();
          }
          cout<< "LISTO Primera Parte";


          //Asignar flechas de anterior
          while(tmp1 != NULL){

          }

        MyFile << "}";
        MyFile.close();
        try {
            cout << "Creating" << endl;
            system("dot -Tps DoubleLinkedList.gv -o DoubleLinkedList.ps");
        } catch (exception e) {
            cout << "error occurred" << endl;
        }
}
