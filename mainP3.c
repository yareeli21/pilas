#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "p2.h"

void lee(char *ent);
void agregarCad(PILA S, char *ent);
void mostrarPila(PILA S);
void mostrarCad(PILA S);
void manejaMsg(int e);
void liberar(PILA);


/*Programa Principal*/
void main(){
	PILA S;
  //se está creando un arreglo de tamaño definido
  char ent[TAMPILA];
  int p;

  S = crearPila( );
  lee(ent);
  agregarCad(S,ent);
  mostrarCad(S);
  liberar(S);
}

/* Lee una cadena */
void lee(char *ent){
  printf("\n\n Introduce una cadena: ");
  scanf("%[^\n]",ent);
}
void agregarCad(PILA S, char *ent){
    int tam=strlen(ent);
    int i;
    for(i=0;i<tam;i++){
        apilar(S,ent[i]);
    }
}
void mostrarPila(PILA S){
   printf("La cadena es:\n");
 while(es_vaciaPila(S)!=TRUE){
    char v;
    v=desapilar(S);
    printf("%c\n",v);
}
}
void mostrarCad(PILA S){
    PILA AUX=crearPila();
    while(es_vaciaPila(S)!=TRUE){
        apilar(AUX,desapilar(S));
    }
    mostrarPila(AUX);
    liberar(AUX);
}

void liberar(PILA S){
    free(S);
    manejaMsg(4);
}

void manejaMsg(int e){
  char * errores[]={"No hay memoria disponible\n","Pila Llena\n", "Pila Vacia\n", "\n\n Division por CERO\n", "\nMemoria Liberada ..."};
  printf("%s", errores[e]);
}
