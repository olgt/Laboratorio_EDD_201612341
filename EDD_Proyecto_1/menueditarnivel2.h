#ifndef MENUEDITARNIVEL2_H
#define MENUEDITARNIVEL2_H

#include <Arbol_AVL.h>
#include <arbol_binario.h>
#include <nodo_binario.h>
#include <nodoarbol.h>
#include <Nodo_Matriz.h>
#include <Nodo_Nivel.h>
#include <Nodo_Objeto.h>
#include <Lista_Niveles.h>
#include <cargador_proyectos.h>
#include <stdbool.h>


class menuEditarNivel2
{
private:
    NodoArbol* proyecto;
    Arbol_Binario* arbolObjetos;
    int idProyecto;

public:
    menuEditarNivel2(NodoArbol* proyecto, Arbol_Binario* arbolObjetos, int idProyecto);

    void mostrarNiveles();
    void mostrarOpciones();
    void graficarNivel(int id);

    void agregarObjeto(Nodo_Nivel* nivelActual);
    void eliminarObjeto();
    void eliminarPared();
    void copiarNivel();
    void crearCantidadPisos();
    void moveObjeto();

};

#endif // MENUEDITARNIVEL2_H
