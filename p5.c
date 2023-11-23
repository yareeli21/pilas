#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "p5.h"

void manejaMsg(int e);

//Creacion de una pila vacia
PILA crearPila( ){
	PILA S;
	S = (PILA)malloc(sizeof(Pila));
	if (S == NULL){
	manejaMsg(0);
	exit(0);

	}
	S->tope =-1;
	return S;
}

/* Anadir un elemento a la Pila*/
void apilar(PILA S, Expediente exp){
	if (S -> tope == TAMPILA -1){
	manejaMsg(3); // Pila llena
	exit(0);
	}
S -> tope++;
S->pila[S->tope]= exp;

}
int es_vaciaPila(PILA S){
    if(S->tope<0)
		return 1;
    return 0;
}

/* Sacar un elemento de la Pila */
Expediente desapilar(PILA S){
	Expediente exp;
	if(es_vaciaPila(S)==TRUE){
		manejaMsg(4);//PILA VACIA
		exit(0);
		}
	exp =S->pila[S->tope];
	S -> tope --;
	return exp;
}
Expediente elemTope(PILA S){
	Expediente exp;
   if(es_vaciaPila(S)==TRUE){
     manejaMsg(2);
     exit(0);
   }
   exp=desapilar(S);
   apilar(S,exp);
   return exp;
}
