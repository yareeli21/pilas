#ifndef _pila_
#define _pila_

#define TAMPILA 100
#define TRUE 1
#define FALSE 0

typedef struct {
	char pila[TAMPILA];
	int tope;
} Pila;

typedef Pila * PILA;


PILA crearPila();
void apilar(PILA S, char x);
int es_vaciaPila(PILA S);
char desapilar(PILA S);
int elemTope(PILA S);

#endif
