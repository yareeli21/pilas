#include<stdio.h>
#include<stdlib.h>
#include "pila 9.h"

void manejaMsg(int);
void liberarMem(PILA);
void datosEntrada(int *);
PILA conv(PILA C, int n);
void mostrarPila(PILA);

 void main(){
    PILA C, aux,a;
    int en;
      C=crearPila();
      aux=crearPila();
      datosEntrada(&en); //lo manda por referencia
      aux=conv(C,en);
     mostrarPila(aux);
     liberarMem(C);
}
void manejaMsg(int msg){
     char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  ","PILA vacia...","PILA llena..."};
     printf("%s", mensajes[msg] );
}
void liberarMem(PILA S){
    free(S);
    manejaMsg(1);
}
void datosEntrada(int *en) {
    printf ("Digite el numero decimal a convertir en hexadecimal:");
    scanf("%i",en);
}

PILA conv(PILA C, int n){
    while(n!=0){

        if((n%16)>9) // si es diferente a 0, checa si el modulo es mayor que 9
        switch (n%16)
        {
            case 10:
            apilar(C,'A');
            break;
            case 11:
            apilar(C,'B');
            break;
            case 12:
            apilar(C,'C');
            break;
            case 13:
            apilar(C,'D');
            break;
            case 14:
            apilar(C,'E');
            break;
            case 15:
            apilar(C,'F');
            break;
            default:
                apilar(C,n%16);
}
n/=16;
    }
  return C;
    }

void mostrarPila(PILA m){
    int a;
    while(es_vacioPila(m)!=TRUE){
        printf("%i\n mi resultado esta en ASCII :c\n",desapilar(m));
    }
   manejaMsg(2);

}

