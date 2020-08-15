#include "Nodo_ProyectoAVL.h"

Nodo_ProyectoAVL::Nodo_ProyectoAVL(string nombre, Lista_Niveles *listaNiveles)
{
    this->nombre = nombre;
    this->niveles = listaNiveles;
    this->codigo = sumarCaracteres();

}

int Nodo_ProyectoAVL::sumarCaracteres(){

    int codigo = 0;
    string nombre = this->nombre;
    int n = nombre.length();

    char char_array[n+1];
    strcpy(char_array, nombre.c_str()); //Metodo agrega los caracteres al array

    for(int i = 0; i < n; i++){
        codigo += (int)char_array[i];
    }

    return codigo;
}

int Nodo_ProyectoAVL::getCodigo(){
    return this->codigo;
}

string Nodo_ProyectoAVL::getName(){
    return this->nombre;
}

