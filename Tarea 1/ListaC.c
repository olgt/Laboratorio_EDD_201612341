#include "ListaC.h"

    void add(ListaC* l,NodoC* nuevo){
    if(l->head==NULL){
        l->head=nuevo;
    }else if(nuevo->val<=l->head->val){
        nuevo->derecha=l->head;
        l->head->izquierda=nuevo;
        l->head=nuevo;
    }else{
        NodoC* aux=l->head;
        while(aux->derecha!=NULL){
            if(aux->val>nuevo->val){
                    NodoC* ant=aux->izquierda;
                    ant->derecha=nuevo;
                    nuevo->izquierda=ant;
                    nuevo->derecha=aux;
                    aux->izquierda=nuevo;
                    return;
                }else if(nuevo->val<=aux->derecha->val){
                    NodoC *siguiente=aux->derecha;
                    aux->derecha=nuevo;
                    nuevo->derecha=aux;
                    nuevo->derecha=siguiente;
                    siguiente->izquierda=nuevo;
                    return;
                }
            aux=aux->derecha;
        }
        aux->derecha=nuevo;
        nuevo->izquierda=aux;
    }
}

void Liberar(ListaC* l){
    NodoA* aux=l->head;
    NodoA* tmp;
    while(aux!=NULL){
        tmp=aux->derecha;
        free(aux);
        aux=tmp;
    }
}

void imprimir(ListaC* l){
    NodoA* aux=l->head;
    while(aux!=NULL){
        printf("El valor es %i \n",aux->val);
        aux=aux->derecha;
    }
    printf("\n");
}
ListaC* nuevaLista(){
    ListaC* nueva=(ListaC*) malloc(sizeof(ListaC));
    nueva->head=NULL;
    return nueva;
}
void generar(ListaC* l){
    FILE * fp;
    fp=fopen("./codigo.gv","w");
    if(fp==NULL){
        printf("Error");
        return;
    }
    char cad[1024];
    sprintf(cad,"digraph G{ \n node[shape=\"box\", style=filled, color=\".7 .3 1.0\"];\n");
    fputs(cad,fp);
    NodoC* aux;
    aux=l->head;
    guardarRecursivo(aux,fp,cad);
    sprintf(cad,"}\n");
    fputs(cad,fp);
    fclose(fp);
    system("dot -Tps codigo.gv -o codigo.ps");

}

void guardarRecursivo(NodoC* aux,FILE* fp,char c[]){
    if(aux==NULL){
        return;
    }else{
        if(aux->derecha!=NULL){
            sprintf(c,"node%p[label=\"%i\"]\n",&(*aux),aux->val);
            fputs(c,fp);
            sprintf(c,"node%p[fillcolor = red]\n",&(*aux), aux->val);
            fputs(c,fp);
            sprintf(c,"node%p[arrowhead = diamond]\n",&(*aux), aux->val);
            fputs(c,fp);
            guardarRecursivo(aux->derecha,fp,c);
            sprintf(c,"node%p->node%p;\n node%p->node%p;\n",&(*aux),&(*aux->derecha),&(*aux->derecha),&(*aux));
            fputs(c,fp);
        }else{
            sprintf(c,"node%p[label=\"%i\"]\n",&(*aux),aux->val);
            fputs(c,fp);
        }
    }
}

void borrarNodo(ListaC* l, int posicionLista){
    NodoC* aux = l->head;
    int posicionActual = 1;

    while(aux != NULL){
        if(posicionActual == posicionLista && aux != NULL){
            if(aux == l->head){
                l->head = aux->derecha;
                aux->derecha = NULL;
                aux = NULL;
                printf("Nodo Encontrado Borrado: ");
                printf("%d \n", posicionActual);
                break;
            }
            else if(aux->derecha == NULL){
                aux->izquierda->derecha = NULL;
                aux=NULL;
                printf("Nodo Encontrado Borrado: ");
                printf("%d \n", posicionActual);
                break;
            }
            else {
                aux->izquierda->derecha = aux->derecha;
                aux->derecha->izquierda = aux->izquierda;
                aux = NULL;
                printf("Nodo Encontrado Borrado: ");
                printf("%d \n", posicionActual);
                break;
            }
        }
        posicionActual++;
        aux = aux->derecha;
    }
}

void getNodo(ListaC* l, int valorNodo){
    NodoC* aux = l->head;
    int valorActual = aux->val;

    while(aux != NULL){
        if(aux->val == valorNodo){
            printf("Valor Encontrado: %d \n", valorNodo);
            break;
        }
        aux = aux->derecha;
    }
}
