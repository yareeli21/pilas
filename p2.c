#include <stdio.h>
#include<stdlib.h>
#include "p2.h"

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
void apilar(PILA S, char e){
	if (S -> tope == TAMPILA -1){
	manejaMsg(3); // Pila llena
	exit(0);
	}
S -> tope++;
S -> pila[S -> tope] = e;

}
int es_vaciaPila(PILA S){
    if(S->tope<0)
		return 1;
    return 0;
}

/* Sacar un elemento de la Pila */
char desapilar(PILA S){
	char v;
	if(es_vaciaPila(S)==TRUE){
		manejaMsg(4);//PILA VACIA
		exit(0);
		}
	v = S->pila[S->tope];
	S -> tope --;
	return v;
}
int elemTope(PILA S){
   int v;
   if(es_vaciaPila(S)==TRUE){
     manejaMsg(2);
     exit(0);
   }
   v=desapilar(S);
   apilar(S,v);
   return v;
}
