#include "menueditarnivel2.h"

menuEditarNivel2::menuEditarNivel2(NodoArbol* proyecto, Arbol_Binario* arbolObjetos, int idProyecto)
{
    this->proyecto = proyecto;
    this->arbolObjetos = arbolObjetos;
    this->idProyecto = idProyecto;
}


void menuEditarNivel2::mostrarNiveles(){

    imprimirEspacios(5);
    Lista_Niveles* listaNIvelesActual = this->proyecto->getListaNiveles();

    listaNIvelesActual->imprimirNiveles();

    imprimirEspacios(5);

    int idNivel;

    cout << "Ingrese Nivel a Editar: ";
    cin >> idNivel;
    graficarNivel(idNivel);
    Nodo_Nivel* nivelActual = this->proyecto->getListaNiveles()->getNodo(idNivel);

    imprimirEspacios(10);

    string opciones[] = {"3.1. Agregar Objeto", "3.2. Eliminar Objeto", "3.3. Eliminar Pared",
                         "3.4. Copiar Nivel", "3.5. Crear cantidad pisos", "3.6. Mover Objeto", "3.7 Salir"};

    bool isContinue = true;
    int opcion = 0;

    while(isContinue != false){
        imprimirEspacios(5);
        for(int i = 0; i < 7 ; i++){
            cout << opciones[i] << endl;
        }

        cout << "Escoja su opcion: ";

        cin >> opcion;

        if(opcion == 1){

            agregarObjeto(nivelActual);

            imprimirEspacios(10);
        }
        if(opcion == 2){

            imprimirEspacios(10);
        }
        if(opcion == 3){
            int idNivel;
            imprimirEspacios(10);

        }
        if(opcion == 3){


            imprimirEspacios(10);

        }
        if(opcion == 5){
        }
        if(opcion == 6){
        }
        if(opcion == 7){
            isContinue = false;
        }
        graficarNivel(idNivel);

    }

}


void menuEditarNivel2::graficarNivel(int id){
    string nombre = "Proyecto_" + this->proyecto->getName() + "_Nivel" + to_string(id);
    this->proyecto->getListaNiveles()->getNodo(id)->getMatriz()->crearGrafica(nombre);
}

void menuEditarNivel2::agregarObjeto(Nodo_Nivel* nivelActual){

    this->arbolObjetos->recorrerInorden(this->arbolObjetos->getRaiz());

    int x, y, id, grados, xInicialObjeto, yInicialObjeto, idObjeto;
    string objeto, color;
    char letra;

    cout << "Seleccione Objeto a agregar: ";
    cin >> id;
    Nodo_Binario* nodoAgregar = this->arbolObjetos->getObjeto(id, this->arbolObjetos->getRaiz());

    cout << "Inserte posicion X: ";
    cin >> x;
    imprimirEspacios(1);
    cout << "Inserte posicion Y: ";
    cin >> y;
    imprimirEspacios(1);
    cout << "Inserte grados (0/45/90): ";
    cin >> grados;
    imprimirEspacios(1);


    int size = nodoAgregar->getListaPuntos()->getSizeNodos();
    Lista_Puntos* listaActualPuntos = nodoAgregar->getListaPuntos();
    xInicialObjeto = listaActualPuntos->gethead()->getX();
    yInicialObjeto = listaActualPuntos->gethead()->getY();
    objeto = nodoAgregar->getName();
    color = nodoAgregar->getColor();
    letra = nodoAgregar->getLetra();
    int posX = 0;
    int posY = 0;
    int posNuevaX45;
    int posNuevaY45;


    if(grados == 0){
        //Agregar Nodos en X
        for(int i = 0; i < size; i++){
            if(xInicialObjeto-listaActualPuntos->getPunto(i)->getX() <= xInicialObjeto){
                posX = x + (xInicialObjeto-listaActualPuntos->getPunto(i)->getX())*-1;
            } else{
                posX = x - xInicialObjeto-listaActualPuntos->getPunto(i)->getX();
            }

            if(yInicialObjeto-listaActualPuntos->getPunto(i)->getY() <= yInicialObjeto){
                posY = y + (yInicialObjeto-listaActualPuntos->getPunto(i)->getY())*-1;
            } else{
                posY = y - yInicialObjeto-listaActualPuntos->getPunto(i)->getY();
            }
            Nodo_Objeto* nodoAgregado = new Nodo_Objeto(id, objeto, letra, color, posX, posY);

            nivelActual->getMatriz()->add(nodoAgregado);

        }
    } else if (grados == 45){
        for(int i = 0; i < size; i++){
            if(xInicialObjeto-listaActualPuntos->getPunto(i)->getX() <= xInicialObjeto){
                posX = x + (xInicialObjeto-listaActualPuntos->getPunto(i)->getX())*-1;
            } else{
                posX = x - xInicialObjeto-listaActualPuntos->getPunto(i)->getX();
            }

            if(yInicialObjeto-listaActualPuntos->getPunto(i)->getY() <= yInicialObjeto){
                posY = y + (yInicialObjeto-listaActualPuntos->getPunto(i)->getY())*-1;
            } else{
                posY = y - yInicialObjeto-listaActualPuntos->getPunto(i)->getY();
            }

            if(i != 0){
                int diferenciaX = listaActualPuntos->getPunto(i)->getX() - xInicialObjeto;
                int diferenciaY = listaActualPuntos->getPunto(i)->getY() - yInicialObjeto;

                //Rotaciones cuando esta inclinado 45 grados
                if(abs(diferenciaX) == abs(diferenciaY)){
                    if(diferenciaY > 0){
                        if(diferenciaX > 0){
                            posNuevaY45 = y;
                            posNuevaX45 = x + diferenciaX;
                        }
                        if(diferenciaX < 0){
                            posNuevaX45 = x;
                            posNuevaY45 = y + abs(diferenciaY);
                        }

                    }
                    if(diferenciaY < 0){
                        if(diferenciaX > 0){
                            posNuevaY45 = y - abs(diferenciaY);
                            posNuevaX45 = x;
                        }
                        if(diferenciaX < 0){
                            posNuevaX45 = x - abs(diferenciaX);
                            posNuevaY45 = y;
                        }
                    }

                }
                //Rotaciones cuando esta en algun plano x o y
                else if(diferenciaX == 0){
                    if(diferenciaY > 0){
                        posNuevaY45 = y + abs(diferenciaY);
                        posNuevaX45 = x + abs(diferenciaY);
                    }
                    if(diferenciaY < 0){
                        posNuevaX45 = x - abs(diferenciaY);
                        posNuevaY45 = y - abs(diferenciaY);
                    }
                }
                else if(diferenciaY == 0){
                    if(diferenciaX > 0){
                        posNuevaY45 = y - abs(diferenciaX);
                        posNuevaX45 = x + abs(diferenciaX);
                    }
                    if(diferenciaX < 0){
                        posNuevaX45 = x - abs(diferenciaX);
                        posNuevaY45 = y + abs(diferenciaX);
                    }
                }


            } else {
                posNuevaX45 = posX;
                posNuevaY45 = posY;
            }

            Nodo_Objeto* nodoAgregado = new Nodo_Objeto(id, objeto, letra, color, posNuevaX45, posNuevaY45);

            nivelActual->getMatriz()->add(nodoAgregado);

        }
    }

    this->proyecto->getListaNiveles()->aumentarObjetos(1);

    //RM[x+y+1][-x+y+n] n=no columns
}


void menuEditarNivel2::eliminarObjeto(){

}
void menuEditarNivel2::eliminarPared(){

}
void menuEditarNivel2::copiarNivel(){
    Nodo_Nivel* nivelACopiar;
    Nodo_Nivel* nivelASobrescribir;

    int idNivelACopiar = 0;
    int idNivelASobreEscribir = 0;

    this->proyecto->getListaNiveles()->imprimirNiveles();

    cout << "Ingrese Nivel a Copiar: " ;
    cin >> idNivelACopiar;
    imprimirEspacios(2);

    nivelACopiar= this->proyecto->getListaNiveles()->getNodo(idNivelACopiar);
    Matriz* matrizCopiada = nivelACopiar->getMatriz()->copiarMatriz();

    this->proyecto->getListaNiveles()->imprimirNiveles();
    cout << "En que nivel quiere copiarlo? ";
    cin >> idNivelASobreEscribir;

    nivelASobrescribir = this->proyecto->getListaNiveles()->getNodo(idNivelASobreEscribir);




}
void menuEditarNivel2::crearCantidadPisos(){

}
void menuEditarNivel2::moveObjeto(){

}

void menuEditarNivel2::mostrarOpciones(){


}
