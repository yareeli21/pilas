#ifndef _pila_
#define _pila_

#define TAMPILA 100
#define TRUE 1
#define FALSE 0

typedef struct {
	char pila[TAMPILA][20];
	int tope;
} Pila;

typedef Pila * PILA;


PILA crearPila();
void apilar(PILA S, char e[]);
int es_vaciaPila(PILA S);
char *desapilar(PILA S);
char *elemTope(PILA S);

#endif
