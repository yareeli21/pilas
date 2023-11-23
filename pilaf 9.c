#include<stdio.h>
#include<stdlib.h>
#include "pila.h"
void manejaMsg(int msg){
     char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  ","PILA vacia...","PILA llena..."};
     printf("%s", mensajes[msg] );
}
PILA crearPila(){
    PILA S;
    S=(PILA)malloc(sizeof(pila));
    if(S==NULL){
       manejaMsg(0);
       exit(0);
       }
       S->tope=-1;
          return S;
       }

void apilar(PILA S, int elem){
   if(S->tope==TAMPILA -1){
      manejaMsg(4);
       exit(0);
       }
   S->tope++;
   S->pila[S->tope]=elem;
   }

int desapilar(PILA S){
  int v;
  if(es_vacioPila(S)==TRUE){
      manejaMsg(3);
       exit(0);
       }
   v=S->pila[S->tope];
   S->tope--;
      return v;
   }
int es_vacioPila(PILA S){
   if(S->tope<0)
      return TRUE;
   else
      return FALSE;
      }

int elemTope(PILA S){
   int v;
     if(es_vacioPila(S)==TRUE){
      manejaMsg(3);
       exit(0);
       }
   v= desapilar(S);
   apilar(S,v);
      return v;
   }

