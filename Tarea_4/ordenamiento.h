#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <iostream>
#include <string>
using namespace  std;
#include <bits/stdc++.h>

class ordenamiento
{
public:

    ordenamiento();
    void burbuja(int *a, int length);
    void seleccion(string *a, int length);
    void insercion(int *a, int length);
    void quickSort(int*a, int length);
    void imprimir(string *a, int length);
    int sumarCaracteres(string nombre);


private:
    void QuickSort(int *a, int start, int end);
    int particion(int *a, int start, int end);
};

#endif // ORDENAMIENTO_H
