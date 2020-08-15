#include "menuprincipal.h"

MenuPrincipal::MenuPrincipal(){

}

Lista_Niveles *nuevaListaNiveles = new Lista_Niveles();


void MenuPrincipal::imprimirMenu(){

    string opciones[] = {"1. Ver Proyectos", "2. Editar Proyectos", "3. Cargar Proyectos",
                         "4. Graficar Proyectos", "5. Guardar Proyectos", "6. Cargar Librerias", "7. Salir"};
    bool isContinue = true;
    int opcion = 0;

    while(isContinue != false){
        imprimirEncabezado();
        for(int i = 0; i < 7 ; i++){
            cout << opciones[i] << endl;
        }
        cout << "Escoja su opcion: ";

        cin >> opcion;

        if(opcion == 1){
            nuevaListaNiveles->imprimirNiveles();
        }
        if(opcion == 2){

        }
        if(opcion == 3){

        }
        if(opcion == 4){

        }
        if(opcion == 5){

        }
        if(opcion == 6){

        }
        if(opcion == 7){
            isContinue = false;
            cout << endl;
            cout << "Saliendo de sistema... ";
        }

    }

}
