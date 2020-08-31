
#include <iostream>
#include <nlohmann/json.hpp>
#include "ordenamiento.h"
using namespace std;

int main()
{
    ordenamiento* nuevo = new ordenamiento();

    string a[] = {"a", "abc", "ab", "abcde", "abcd", "abcdef"};

    int length = sizeof(a)/sizeof(a[0]);

    //nuevo->burbuja(a, length);
    nuevo->seleccion(a, length);
    nuevo->imprimir(a, length);

    delete nuevo;

    return 0;
}
