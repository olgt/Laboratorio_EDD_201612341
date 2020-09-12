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

void ordenamiento::insercion(int *a, int length){
    int aux, pos;

    for(int i = 0; i < length; i++){
        aux = a[i];
        pos = i;
        while((pos>0) &&a[pos-1]>aux){
            a[pos] = a[pos-1];
            pos--;
        }
        a[pos]=aux;
    }
}

void ordenamiento::quickSort(int *a, int length){
    QuickSort(a,0,length-1);
}

void ordenamiento::QuickSort(int *a, int start, int end){
    int part=particion(a, start, end);
    if(part - 1 > start){
       QuickSort(a, start, part-1);
    }
    if(part+1<end){
        QuickSort(a, part+1, end);
    }
}

int ordenamiento::particion(int *a, int start, int end){
    int pivot=a[end];
    for(int i = start; i < end; i++){
        if(a[i] < pivot){
            int tmp = a[start];
            a[start] = a[i];
            a[i] = tmp;
            start++;
        }
    }
    int tmp=a[start];
    a[start]=pivot;
    a[end]=tmp;
    return start;
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
