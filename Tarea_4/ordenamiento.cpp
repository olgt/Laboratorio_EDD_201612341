#include "ordenamiento.h"

ordenamiento::ordenamiento()
{

}

void ordenamiento::burbuja(int *a, int length){
    int aux;

    for(int i = 0; i< length-1; i++){
       for(int j=0; j<length-i-1;j++){
           if(a[j+1] < a[j]){
               aux=a[j+1];
               a[j+1]=a[j];
               a[j]=aux;
           }
       }
    }
}

void ordenamiento::imprimir(string *a, int length){
    for(int i = 0; i < length -1; i++){
        cout << a[i] << ", ";
    }
}

void ordenamiento::seleccion(string *a, int length){
    int min;
    string aux;

    for(int i = 0; i< length; i++){
        min = i;
        for(int j = i+1; j<length; j++){
            if(sumarCaracteres(a[j]) < sumarCaracteres(a[min])){
                    min = j;
            }
        }
        aux=a[i];
        a[i]=a[min];
        a[min] = aux;
    }
}

int ordenamiento::sumarCaracteres(string nombre){

    int codigo = 0;
    int n = nombre.length();

    char char_array[n+1];
    strcpy(char_array, nombre.c_str()); //Metodo agrega los caracteres al array

    for(int i = 0; i < n; i++){
        codigo += (int)char_array[i];
    }

    return codigo;
}
