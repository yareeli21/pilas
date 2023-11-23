#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "p4.h"

void menu(PILA);
void agregarElem(PILA S);
void quitarElem(PILA S);
int elemPila(PILA S);
void mostrarPila(PILA S);
void manejaMsg(int e);
void liberar(PILA);


/*Programa Principal*/
void main(){
	PILA S;
  S = crearPila( );
  menu(S);
  liberar(S);
}

/* Lee una cadena */
void menu(PILA S){
    int op,numElem;

    do{
        printf("\nBienvenido al menu.\n");
        printf("1. Introducir un elemento a la cesta.\n");
        printf("2. Saca un elemento de la cesta.\n");
        printf("3. Imprimir los elementos que tiene la cesta.\n");
        printf("4. Salir del programa jeje:)\n");
        printf("Seleccione una opcion:\n");
        scanf("%d",&op);

        switch(op){

            case 1: if(elemPila(S)<10){
                    agregarElem(S);
                   }
                   else{
                       printf("Cesto lleno:(.\n");
                }
                    break;
            case 2: quitarElem(S);
                    break;
            case 3: mostrarPila(S);
                    break;
            default: printf("Saliendo del programa...:)\n");
        }
    }while(op!=4);
}
void agregarElem(PILA S){
   char producto[20];
   getchar();
    printf("Ingrese datos un producto al cesto:\n");
    scanf("%[^\n]",&producto);
    apilar(S,producto);
    printf("Ya se agrego %s al cesto.\n",producto);
}
//esta función quita el ultimo elemento
void quitarElem(PILA S){
    char tope[20];
    if(es_vaciaPila(S)!=TRUE){
    //tope=elemTope(S);
    strcpy(tope,desapilar(S));
    printf("El elemento que se elimino fue: %s\n",tope);
    }
    else{
        printf("El cesto esta vacio.:(\n");
    }
}
//imprimir los elementos de la cesta
void mostrarPila(PILA S){
    PILA aux=crearPila();
    char v[20];
 while(es_vaciaPila(S)!=TRUE){
    strcpy(v,desapilar(S));
    printf("%s\n",v);
    apilar(aux,v);
 }
 while(es_vaciaPila(aux)!=TRUE){
     apilar(S,desapilar(aux));
    }
}
//cuenta cuantos elementos tiene la pila
int elemPila(PILA S){
    int cont=0;
    PILA aux=crearPila();
    while(es_vaciaPila(S)!=TRUE){
        apilar(aux,desapilar(S));
        cont ++;
    }
    while(es_vaciaPila(aux)!=TRUE){
        apilar(S,desapilar(aux));
    }
    return cont;
}
void liberar(PILA S){
    free(S);
    manejaMsg(4);
}

void manejaMsg(int e){
  char * errores[]={"No hay memoria disponible\n","Pila Llena\n", "Pila Vacia\n", "\n\n Division por CERO\n", "\nMemoria Liberada ..."};
  printf("%s", errores[e]);
}
