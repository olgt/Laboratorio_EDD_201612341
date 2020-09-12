#include "menuprincipal.h"

MenuPrincipal::MenuPrincipal(){

}

Lista_Niveles *nuevaListaNiveles = NULL;
Arbol_AVL *arbolProyectos = NULL;
Arbol_Binario *arbolObjetos = NULL;

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
            if(arbolProyectos != NULL){
                arbolProyectos->recorrerArbol(arbolProyectos->getRaiz());
                int a;
                cout << "Ingrese id de proyecto a graficar: ";
                cin >> a;
                arbolProyectos->graficarProyecto(arbolProyectos->getRaiz(), a);
            } else {
                cout << "No Hay Proyectos Guardados" << endl;
            }

            imprimirEspacios(20);
        }
        if(opcion == 2){

        }
        if(opcion == 3){
            Cargador_Proyectos cargador;
            string nombreArchivo;

            if(arbolProyectos != NULL){
                arbolProyectos->~Arbol_AVL();
            }

            cout << endl << "Proporcione el nombre del archivo: ";
            cin >> nombreArchivo;
            arbolProyectos = cargador.cargarNuevo(nombreArchivo, arbolObjetos);
            arbolObjetos->crearGrafica();
        }
        if(opcion == 4){
            arbolProyectos->graficarTodosProyectos(arbolProyectos->getRaiz());
        }
        if(opcion == 5){
            //GuardarProyectos
        }
        if(opcion == 6){
            Cargador_Proyectos cargador;
            string nombreArchivo;

            if(arbolObjetos != NULL){
                arbolObjetos->~Arbol_Binario();
            }

            cout << endl << "Proporcione el nombre del archivo: ";
            cin >> nombreArchivo;
            arbolObjetos = cargador.cargarLibrerias(nombreArchivo);
            arbolObjetos->crearGrafica();
        }
        if(opcion == 7){
            isContinue = false;
            cout << endl;
            cout << "Saliendo de sistema... ";
        }

    }

}
