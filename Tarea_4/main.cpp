
#include <iostream>
#include <nlohmann/json.hpp>
#include "ordenamiento.h"
using namespace std;

int main()
{
    ordenamiento* nuevo = new ordenamiento();

    string a[]={"Hola como estas","Yo bien gracias","ESTE ES UN MENSAJE","Vamos a ganar EDD todos juntos","!!!!Vamos a sacar 100","$$$$$$$$$#$$$$$","Este es el ultimo mensaje del dia de hoy*45"};

    int length = sizeof(a)/sizeof(a[0]);

    //nuevo->burbuja(a, length);
    nuevo->seleccion(a, length);
    nuevo->imprimir(a, length);

    delete nuevo;

    return 0;
}
