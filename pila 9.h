
#ifndef _pila_
#define _pila_
#define TAMPILA 100
#define TRUE 1
#define FALSE 0

typedef struct{
   int pila[TAMPILA];
   int tope;
   } pila;
typedef pila * PILA;

PILA crearPila();
void apilar(PILA S, int elem);
int desapilar(PILA S);
int es_vacioPila(PILA S);
int elemTope(PILA S);
#endif // _pila_

