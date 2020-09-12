#ifndef CARGADOR_PROYECTOS_H
#define CARGADOR_PROYECTOS_H

#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>
#include <string>

#include "Arbol_AVL.h"
#include "arbol_binario.h"
#include "Lista_Niveles.h"
#include "Nodo_Nivel.h"
#include "Matriz.h"
#include "Nodo_Matriz.h"
#include "Nodo_Objeto.h"
#include "nodo_binario.h"

using json=nlohmann::json;
using namespace std;

class Cargador_Proyectos
{
private:

public:
    Cargador_Proyectos();

    Arbol_AVL* cargarNuevo(string nombre, Arbol_Binario* arbolBinario);
    Lista_Niveles* cargarNiveles(json j, int numeroProyecto, Arbol_Binario* abb);

    Matriz* crearMatriz(json j, int numeroProyecto, int numeroNivel);

    Arbol_Binario* cargarLibrerias(string nombre);
    Lista_Puntos* cargarCoordenadas(json j, int indiceObjeto);
    Arbol_Binario* cargarLibreriasNivel(json j, int numeroProyecto, int numeroNivel);
    Lista_Puntos* cargarCoordenadasObjetosProyecto(json jasonFile, int indiceProyecto, int indiceNivel, int indiceObjeto);
    void agregarObjetosExtra(json j, Arbol_Binario* actualCreado, int indiceProyecto, int indiceNivel);

};

#endif // CARGADOR_PROYECTOS_H
