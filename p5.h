#ifndef _pila_
#define _pila_

#define TAMPILA 100
#define TRUE 1
#define FALSE 0
typedef struct{
    int dia;
    int mes;
    int anio;
}Fecha;
typedef struct{
    int numero;
    char titular[25];
    char tramite[25];
    Fecha fec;
}Expediente;

typedef struct {
	Expediente pila[TAMPILA];
	int tope;
} Pila;

typedef Pila * PILA;


PILA crearPila();
void apilar(PILA S, Expediente e);
int es_vaciaPila(PILA S);
Expediente desapilar(PILA S);
Expediente elemTope(PILA S);

#endif
