#include "cargador_proyectos.h"

Cargador_Proyectos::Cargador_Proyectos()
{


}


Arbol_AVL* Cargador_Proyectos::cargarNuevo(string nombreArchivo, Arbol_Binario* arbolBinario){
    int numeroProyectos = 0;
    int numeroNiveles = 0;

    Arbol_AVL* nuevo = new Arbol_AVL();
    Arbol_Binario* abbActual = arbolBinario;

    json j;


    try {
        string archivo= "./" + nombreArchivo + ".json";
        ifstream reader(archivo);
        reader>>j;
        reader.close();
        cout << endl << "Proyectos Cargados exitosamente" << endl;
    } catch (exception e) {
        cout << e.what();
        cout << endl << "Archivo no Encontrado" << endl;
    }

    numeroProyectos = j["proyectos"].size();
    cout << "Proyectos: " << numeroProyectos << endl;

    for(int i = 0; i < numeroProyectos; i++){//i = numero de proyecto

        //Cargar Niveles
        Lista_Niveles* nuevaListaNiveles = cargarNiveles(j, i, abbActual);


        //Insertar Nodo Proyectos
        cout << "Insertando: " << (j["proyectos"][i]["nombre"]) << endl;
        nuevo->insertar(j["proyectos"][i]["nombre"], nuevaListaNiveles, i, abbActual);
        cout << "Done" << endl;
    }

    return nuevo;

}

Lista_Niveles* Cargador_Proyectos::cargarNiveles(json jasonFile, int numeroProyecto, Arbol_Binario* abbActual){

    //****Imprimimos cantidad de Niveles
    int numeroNiveles = jasonFile["proyectos"][numeroProyecto]["niveles"].size();
    cout << "Niveles:" << numeroNiveles << endl;
    //****Imprimimos cantidad de Niveles

    Lista_Niveles* listaNiveles = new Lista_Niveles();

    numeroNiveles = jasonFile["proyectos"][numeroProyecto]["niveles"].size();

    for(int j = 0; j < numeroNiveles; j++){ // j = numero nivel
        //Cargar Arbol Binario
        if(abbActual == NULL){
            abbActual = cargarLibreriasNivel(jasonFile, numeroProyecto, j);
        } else {
            //Comparar si tenemos los mismo objetos, si no los tenemos, agregarlo al abbActual
            agregarObjetosExtra(jasonFile, abbActual, numeroProyecto, j); //j = numero nivel
        }

        Matriz* nuevaMatriz = crearMatriz(jasonFile, numeroProyecto, j);

        Nodo_Nivel* nodoNivel = new Nodo_Nivel(j, nuevaMatriz, abbActual);

        cout << "Insertando Nivel: " << jasonFile["proyectos"][numeroProyecto]["niveles"][j]["nivel"] << endl;

        listaNiveles->addNode(nodoNivel);
    }
    return listaNiveles;
}


Matriz* Cargador_Proyectos::crearMatriz(json jasonFile, int numeroProyecto, int numeroNivel){
    int numeroParedes = jasonFile["proyectos"][numeroProyecto]["niveles"][numeroNivel]["paredes"].size();
    Matriz* nuevaMatriz = new Matriz();

    //Coordenadas de Inicio
    for(int i = 0; i<numeroParedes; i++){
        int xInicial = jasonFile["proyectos"][numeroProyecto]["niveles"][numeroNivel]["paredes"][i]["inicio"][0];
        int yInicial = jasonFile["proyectos"][numeroProyecto]["niveles"][numeroNivel]["paredes"][i]["inicio"][1];

        int xFinal = jasonFile["proyectos"][numeroProyecto]["niveles"][numeroNivel]["paredes"][i]["final"][0];
        int yFinal = jasonFile["proyectos"][numeroProyecto]["niveles"][numeroNivel]["paredes"][i]["final"][1];

        string color = jasonFile["proyectos"][numeroProyecto]["niveles"][numeroNivel]["paredes"][i]["color"];

        //int actualX = x;
        //int actualY = y;

        if(xInicial < xFinal){
            for(int x = xInicial; x< xFinal+1; x++){
                Nodo_Objeto *nuevo = new Nodo_Objeto((i+1)*10000+x, "Pared", 'P', color, x, yInicial);
                nuevaMatriz->add(nuevo);
            }
        } else if (xInicial > xFinal){
            for(int x = xInicial; x< xFinal-1; x--){
                Nodo_Objeto *nuevo = new Nodo_Objeto((i+1)*10000+x, "Pared", 'P', color, x, yInicial);
                nuevaMatriz->add(nuevo);
            }
        }    //Lista_Niveles* getListaNiveles();


        if(yInicial < yFinal){
            for(int y = yInicial; y< yFinal+1; y++){
                Nodo_Objeto *nuevo = new Nodo_Objeto((i+1)*20000+y, "Pared", 'P', color, xInicial, y);
                nuevaMatriz->add(nuevo);
            }
        } else if (yInicial > yFinal){
            for(int y = yInicial; y< yFinal-1; y--){
                Nodo_Objeto *nuevo = new Nodo_Objeto((i+1)*20000+y, "Pared", 'P', color, xInicial, y);
                nuevaMatriz->add(nuevo);
            }
        }
    }
    return nuevaMatriz;
}

Arbol_Binario* Cargador_Proyectos::cargarLibreriasNivel(json jasonFile, int numeroProyecto, int numeroNivel){
    int numeroObjetos = 0;
    Arbol_Binario* nuevo = new Arbol_Binario();

    numeroObjetos = jasonFile["proyectos"][numeroProyecto]["niveles"][numeroNivel]["objetos"].size();
    cout << "Cantidad Objetos: " << numeroObjetos << endl;

    for(int indiceObjeto = 0; indiceObjeto < numeroObjetos; indiceObjeto++){ //i = indice De Objeto

        Lista_Puntos* nuevaListaPuntos = cargarCoordenadasObjetosProyecto(jasonFile, numeroProyecto, numeroNivel, indiceObjeto);

        int id = (jasonFile["proyectos"][numeroProyecto]["niveles"][numeroNivel]["objetos"][indiceObjeto]["identificador"]);
        string nombreObjeto = (jasonFile["proyectos"][numeroProyecto]["niveles"][numeroNivel]["objetos"][indiceObjeto]["nombre"]);
        string color = (jasonFile["proyectos"][numeroProyecto]["niveles"][numeroNivel]["objetos"][indiceObjeto]["color"]);

        string caracter = (jasonFile["proyectos"][numeroProyecto]["niveles"][numeroNivel]["objetos"][indiceObjeto]["letra"]);

        char letra[caracter.size() + 1];
        strcpy(letra, caracter.c_str()); //Convertimos string a char

        nuevo->insertar(id, nombreObjeto, letra[0], color, nuevaListaPuntos); //(int id, string nombre, char letra, string color, Lista_Puntos* xy

        cout << "Insertando: " << (jasonFile["proyectos"][numeroProyecto]["niveles"][numeroNivel]["objetos"][indiceObjeto]["nombre"]) << endl;
        cout << "Done" << endl;
    }

    return nuevo;
}

Lista_Puntos* Cargador_Proyectos::cargarCoordenadasObjetosProyecto(json jasonFile, int indiceProyecto, int indiceNivel, int indiceObjeto){

    //****Imprimimos cantidad de Coordenadas
    int numeroCoordenadas = jasonFile["proyectos"][indiceProyecto]["niveles"][indiceNivel]["objetos"][indiceObjeto]["puntos"].size();
    cout << "#Coordenadas:" << numeroCoordenadas << endl;
    //****Imprimimos cantidad de Coordenadas

    Lista_Puntos* nuevaListaPuntos = new Lista_Puntos();

    for(int j = 0; j < numeroCoordenadas; j++){

        int xEnJason = jasonFile["proyectos"][indiceProyecto]["niveles"][indiceNivel]["objetos"][indiceObjeto]["puntos"][j]["x"];
        int yEnJason = jasonFile["proyectos"][indiceProyecto]["niveles"][indiceNivel]["objetos"][indiceObjeto]["puntos"][j]["y"];

        Nodo_Puntos* nodoXY = new Nodo_Puntos(xEnJason, yEnJason);

        cout << "Insertando Coordenadas: " << xEnJason << ", " << yEnJason << endl;

        nuevaListaPuntos->addNode(nodoXY);
    }
    return nuevaListaPuntos;
}


Arbol_Binario* Cargador_Proyectos::cargarLibrerias(string nombreArchivo){
    int numeroObjetos = 0;
    int numeroCoordenadas = 0;
    Arbol_Binario* nuevo = new Arbol_Binario();
    json j;

    try {
        string archivo= "./" + nombreArchivo + ".json";
        ifstream reader(archivo);
        reader>>j;
        reader.close();
        cout << endl << "Objetos Cargados exitosamente" << endl;
    } catch (exception e) {
        cout << e.what();
        cout << endl << "Archivo no Encontrado" << endl;
    }

    numeroObjetos = j["Libreria"].size();
    cout << "Cantidad Objetos: " << numeroObjetos << endl;

    for(int i = 0; i < numeroObjetos; i++){ //i = indice De Objeto

        Lista_Puntos* nuevaListaPuntos = cargarCoordenadas(j, i);

        int id = (j["Libreria"][i]["identificador"]);
        string nombreObjeto = (j["Libreria"][i]["nombre"]);
        string color = (j["Libreria"][i]["color"]);


        string caracter = (j["Libreria"][i]["letra"]);


        char letra[caracter.size() + 1];
        strcpy(letra, caracter.c_str()); //Convertimos string a char

        nuevo->insertar(id, nombreObjeto, letra[0], color, nuevaListaPuntos); //(int id, string nombre, char letra, string color, Lista_Puntos* xy

        cout << "Insertando: " << (j["Libreria"][i]["nombre"]) << endl;
        cout << "Done" << endl;
    }

    return nuevo;

}

Lista_Puntos* Cargador_Proyectos::cargarCoordenadas(json jasonFile, int indiceObjeto){

    //****Imprimimos cantidad de Coordenadas
    int numeroCoordenadas = jasonFile["Libreria"][indiceObjeto]["puntos"].size();
    cout << "#Coordenadas:" << numeroCoordenadas << endl;
    //****Imprimimos cantidad de Coordenadas


    Lista_Puntos* nuevaListaPuntos = new Lista_Puntos();

    for(int j = 0; j < numeroCoordenadas; j++){

        int xEnJason = jasonFile["Libreria"][indiceObjeto]["puntos"][j]["x"];
        int yEnJason = jasonFile["Libreria"][indiceObjeto]["puntos"][j]["y"];

        Nodo_Puntos* nodoXY = new Nodo_Puntos(xEnJason, yEnJason);

        cout << "Insertando Coordenadas: " << xEnJason << ", " << yEnJason << endl;

        nuevaListaPuntos->addNode(nodoXY);
    }
    return nuevaListaPuntos;
}

void Cargador_Proyectos::agregarObjetosExtra(json jasonFile, Arbol_Binario* arbolActual, int indiceProyecto, int indiceNivel){
    int numeroObjetos = 0;

    numeroObjetos = jasonFile["proyectos"][indiceProyecto]["niveles"][indiceNivel]["objetos"].size();
    cout << "Cantidad Objetos: " << numeroObjetos << endl;

    for(int i = 0; i < numeroObjetos; i++){ //i = indice De Objeto

        Lista_Puntos* nuevaListaPuntos = cargarCoordenadasObjetosProyecto(jasonFile, indiceProyecto, indiceNivel, i);

        int id = (jasonFile["proyectos"][indiceProyecto]["niveles"][indiceNivel]["objetos"][i]["identificador"]);
        string nombreObjeto = (jasonFile["proyectos"][indiceProyecto]["niveles"][indiceNivel]["objetos"][i]["nombre"]);
        string color = (jasonFile["proyectos"][indiceProyecto]["niveles"][indiceNivel]["objetos"][i]["color"]);
        string caracter = (jasonFile["proyectos"][indiceProyecto]["niveles"][indiceNivel]["objetos"][i]["letra"]);

        char letra[caracter.size() + 1];
        strcpy(letra, caracter.c_str()); //Convertimos string a char

        //Agregar
        arbolActual->insertar(id, nombreObjeto, letra[0], color, nuevaListaPuntos); //(int id, string nombre, char letra, string color, Lista_Puntos* xy

        cout << "Insertando Extra: " << (jasonFile["proyectos"][indiceProyecto]["niveles"][indiceNivel]["objetos"][i]["nombre"]) << endl;
        cout << "Done" << endl;
    }

}
