#include "Matriz.h"

Matriz::Matriz()
{
    this->horizontal = NULL;
    this->vertical = NULL;
}

Matriz::~Matriz(){
    Nodo_Matriz *aux, *aux2, *tmp, *tmp2, *extra, *extra2;
//Estoy arreglando el constructor y luego probar cargar proyectos muchas veces para que no de error
    aux=this->vertical;
    tmp=this->horizontal;
    while(aux!=NULL){
        extra = aux->getAbajo();
        aux2 = aux->getDerecha();
        while(aux2!=NULL){
            extra2 = aux2->getDerecha();
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
    //cout << "Acutal: " << aux->getPos() << endl;;
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
            //cout << "Aux valor: " << aux->getPos() << endl;
            //cout << "Y valor: " << y << endl;
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

    int nodoNumeroX = ((Nodo_Objeto*)izquierda)->getX();
    int nodoNumeroY = ((Nodo_Objeto*)superior)->getY();


    if(izquierda->getDerecha() == NULL){

        /*Condicional && !(((Nodo_Objeto*)izquierda)->getX() == nuevo->getX() && ((Nodo_Objeto*)superior)->getY() == nuevo->getY()
                                            && izquierda->getIzquierda() != NULL)){*/

        izquierda->setDerecha(nuevo);
        nuevo->setIzquierda(izquierda);
    }else{
        /*if(((Nodo_Objeto*)izquierda)->getX() == nuevo->getX()
             && ((Nodo_Objeto*)superior)->getY() == nuevo->getY()){
            nuevo->setDerecha(izquierda->getDerecha());
            nuevo->setIzquierda(izquierda->getIzquierda());
            izquierda->getIzquierda()->setDerecha(nuevo);
            if(izquierda->getDerecha()!=NULL){
                izquierda->getDerecha()->setIzquierda(nuevo);
            }
        } else {*/
            Nodo_Matriz* tmp = izquierda->getDerecha();
            izquierda->setDerecha(nuevo);
            nuevo->setIzquierda(izquierda);
            tmp->setIzquierda(nuevo);
            nuevo->setDerecha(tmp);
    }
    if(superior->getAbajo()==NULL){

        /* condicional && !(((Nodo_Objeto*)superior)->getY() == nuevo->getY() && ((Nodo_Objeto*)izquierda)->getX() == nuevo->getX()
                                       && superior->getArriba() != NULL)){*/

        superior->setAbajo(nuevo);
        nuevo->setArriba(superior);
    } else {
        /*if(((Nodo_Objeto*)superior)->getY() == nuevo->getY() && ((Nodo_Objeto*)izquierda)->getX() == nuevo->getX()){
            nuevo->setAbajo(superior->getAbajo());
            nuevo->setArriba(superior->getArriba());
            superior->getArriba()->setAbajo(nuevo);
            if(superior->getAbajo() != NULL){
                superior->getAbajo()->setArriba(nuevo);
            }
        } else {*/
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


void Matriz::crearGrafica(string nombre){
    Nodo_Matriz *vertical = this->vertical;
    Nodo_Matriz *horizontal = this->horizontal;

    Nodo_Matriz *aux = this->vertical;
    Nodo_Matriz *aux2 = this->vertical;

    Nodo_Matriz *tmpH = this->horizontal;
    Nodo_Matriz *tmpV = this->vertical;

    string nombreArchivo = nombre + ".gv";
    string nombreGrafica = nombre + ".ps";

        ofstream MyFile(nombreArchivo);
        MyFile << "digraph G {";
        MyFile << "\n";
        MyFile << "rankdir = TB; \n";
        MyFile << "node [shape=box, width=.1, height=.1]; \n";
        MyFile << "node0 [label = \"Matriz\", group=-1] \n";

        //RANKS Nodos Cabecera Y
        MyFile << "{ \n";
        MyFile << "rank=same; ";
        MyFile << "node0, ";

        while(horizontal != NULL){
          MyFile << "nodeY" << ((Cabecera*)horizontal)->getPos();

          if(horizontal->getDerecha() == NULL){MyFile << "; \n";}
          else { MyFile << ", ";}

          horizontal = horizontal->getDerecha();
        }
        MyFile << "} \n";
        horizontal = this->horizontal;

          //RANKS Nodos Matris y Cabecera "Y"
          while(aux2 != NULL){
              MyFile << "{ \n";
              MyFile << "rank=same; ";
              MyFile << "nodeX" << ((Cabecera*)aux)->getPos() << ", ";
              aux = aux->getDerecha();

              while(aux!=NULL){
                  MyFile << "node" << ((Nodo_Objeto*)aux)->getId();

                  if(aux->getDerecha() == NULL){MyFile << "; \n";}
                  else { MyFile << ", ";}

                  aux = aux->getDerecha();
              }
              aux = aux2->getAbajo();
              aux2 = aux2->getAbajo();
              MyFile << "} \n";

          }

          aux2 = this->vertical;
          aux = this->vertical;


          //NODOS CABECERA Groups
          while(horizontal != NULL){
            MyFile << "nodeY" << ((Cabecera*)horizontal)->getPos() << "[label = \"" << ((Cabecera*)horizontal)->getPos() << "\""
                   << ", group=" << ((Cabecera*)horizontal)->getPos() << "]; \n";
            horizontal = horizontal->getDerecha();
          }
          while(vertical != NULL){
              MyFile << "nodeX" << ((Cabecera*)vertical)->getPos()  << "[label = \"" << ((Cabecera*)vertical)->getPos()
                     << "\""  << ", group=-1" << "]; \n";
              vertical = vertical->getAbajo();
          }


          //NODOS MATRIZ Propiedades
          while(aux2 != NULL){
              aux = aux->getDerecha();
              while(aux!=NULL){
                  MyFile << "node" << ((Nodo_Objeto*)aux)->getId() << "[label = \"" << ((Nodo_Objeto*)aux)->getObjeto()
                         << "\"" << ", group=" << ((Nodo_Objeto*)aux)->getY() << ", style=filled" << ", color=\""
                         << ((Nodo_Objeto*)aux)->getColor()  << "\"" << "]; \n";
                  aux = aux->getDerecha();
              }
              aux = aux2->getAbajo();
              aux2 = aux2->getAbajo();
          }

          //Creando Flechas de Matriz
          MyFile << "node0" << "->" <<  "nodeY" << ((Cabecera*)tmpH)->getPos() << "; \n";
          MyFile << "node0" << "->" << "nodeX" <<((Cabecera*)tmpV)->getPos() << "; \n";

          //FLECHAS CABECERA => MATRIZ & MATRIZ = MATRIZ
          while(tmpH != NULL){
              if(tmpH->getDerecha() != NULL){
                  MyFile << "nodeY" << ((Cabecera*)tmpH)->getPos() << "->" << "nodeY" << ((Cabecera*)tmpH->getDerecha())->getPos() << ";" << endl;
                  MyFile << "nodeY" << ((Cabecera*)tmpH->getDerecha())->getPos() << "->" << "nodeY" << ((Cabecera*)tmpH)->getPos() << ";" << endl;
                  MyFile << "nodeY" << ((Cabecera*)tmpH)->getPos() << "->" << "node" << ((Nodo_Objeto*)tmpH->getAbajo())->getId() << "; \n";
                  MyFile << "node" << ((Nodo_Objeto*)tmpH->getAbajo())->getId() << "->" << "nodeY" << ((Cabecera*)tmpH)->getPos() << "; \n";
                  enlacesNodosMatrizHorizontal(MyFile, tmpH->getAbajo());
              } else {
                  MyFile << "nodeY" << ((Cabecera*)tmpH)->getPos() << "->" << "node" << ((Nodo_Objeto*)tmpH->getAbajo())->getId() << "; \n";
                  MyFile << "node" << ((Nodo_Objeto*)tmpH->getAbajo())->getId() << "->" << "nodeY" << ((Cabecera*)tmpH)->getPos() << "; \n";
                  enlacesNodosMatrizHorizontal(MyFile, tmpH->getAbajo());
              }
              tmpH = tmpH->getDerecha();
          }

          while(tmpV != NULL){
              if(tmpV->getAbajo() != NULL){
                  MyFile << "nodeX" << ((Cabecera*)tmpV)->getPos() << "->" << "nodeX" << ((Cabecera*)tmpV->getAbajo())->getPos() << ";" << endl;
                  MyFile << "nodeX" << ((Cabecera*)tmpV->getAbajo())->getPos() << "->" << "nodeX" << ((Cabecera*)tmpV)->getPos() << ";" << endl;
                  MyFile << "nodeX" << ((Cabecera*)tmpV)->getPos() << "->" << "node" << ((Nodo_Objeto*)tmpV->getDerecha())->getId() << "; \n";
                  MyFile << "node" << ((Nodo_Objeto*)tmpV->getDerecha())->getId() << "->" << "nodeX" << ((Cabecera*)tmpV)->getPos() << "; \n";
                  enlacesNodosMatrizVertical(MyFile, tmpV->getDerecha());
              } else {
                  MyFile << "nodeX" << ((Cabecera*)tmpV)->getPos() << "->" << "node" << ((Nodo_Objeto*)tmpV->getDerecha())->getId() << "; \n";
                  MyFile << "node" << ((Nodo_Objeto*)tmpV->getDerecha())->getId() << "->" << "nodeX" << ((Cabecera*)tmpV)->getPos() << "; \n";
                  enlacesNodosMatrizVertical(MyFile, tmpV->getDerecha());
              }
              tmpV = tmpV->getAbajo();
          }


          //Lenar Espacios vacios


          //Asignando Flechas a Nodos
          tmpH = this->horizontal;
          tmpV = this->vertical;


        cout << "Done";
        MyFile << "}";
        MyFile.close();
        try {
            //"dot -Tps MatrizGrafica.gv -o MatrizGrafica.ps"
            cout << "Creating" << endl;
            system(("dot -Tps " + nombreArchivo + " -o " + nombreGrafica).c_str());


        } catch (exception e) {
            cout << "error occurred" << endl;
        }
}

void Matriz::enlacesNodosMatrizHorizontal(ofstream & MyFile, Nodo_Matriz* horizontal){

    Nodo_Matriz* actual = horizontal;
    //cout << ((Nodo_Objeto*)actual)->getId() << endl;

    while(actual->getAbajo() != NULL){
        //cout << "Aqui: "  <<  ((Nodo_Objeto*)actual)->getId()<< endl;

        MyFile << "node" << ((Nodo_Objeto*)actual)->getId() << "->" << "node" <<  ((Nodo_Objeto*)actual->getAbajo())->getId()  << "; \n";
        MyFile << "node" << ((Nodo_Objeto*)actual->getAbajo())->getId() << "->" << "node" << ((Nodo_Objeto*)actual)->getId() << "; \n";
        actual = actual->getAbajo();
    }
}

void Matriz::enlacesNodosMatrizVertical(ofstream & MyFile, Nodo_Matriz* vertical){

    Nodo_Matriz* actual = vertical;
    //cout << ((Nodo_Objeto*)actual)->getId() << endl;

    while(actual->getDerecha() != NULL){
        //cout << "Aqui: "  <<  ((Nodo_Objeto*)actual)->getId()<< endl;

        MyFile << "node" << ((Nodo_Objeto*)actual)->getId() << "->" << "node" <<  ((Nodo_Objeto*)actual->getDerecha())->getId()  << "; \n";
        MyFile << "node" << ((Nodo_Objeto*)actual->getDerecha())->getId() << "->" << "node" << ((Nodo_Objeto*)actual)->getId() << "; \n";
        actual = actual->getDerecha();
    }
}
