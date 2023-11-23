#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    char elementos[MAX_SIZE];
    int tope;
} PILA;

// Función para crear una pila vacía
PILA crearPila() {
    PILA pila;
    pila.tope = -1;
    return pila;
}

// Función para verificar si la pila está vacía
int es_vaciaPila(PILA pila) {
    return pila.tope == -1;
}

// Función para apilar un elemento en la pila
void apilar(PILA *pila, char elemento) {
    if (pila->tope < MAX_SIZE - 1) {
        pila->elementos[++(pila->tope)] = elemento;
    } else {
        printf("Error: Pila llena\n");
        exit(EXIT_FAILURE);
    }
}

// Función para desapilar un elemento de la pila
char desapilar(PILA *pila) {
    if (!es_vaciaPila(*pila)) {
        return pila->elementos[(pila->tope)--];
    } else {
        printf("Error: Pila vacía\n");
        exit(EXIT_FAILURE);
    }
}

// Función para copiar una pila a otra
void copiarPila(PILA original, PILA *copia) {
    // Crear una pila temporal para preservar el orden de los elementos
    PILA temp = crearPila();

    // Desapilar y apilar elementos para copiar la pila original a la temporal
    while (!es_vaciaPila(original)) {
        char elemento = desapilar(&original);
        apilar(&temp, elemento);
    }

    // Desapilar y apilar elementos nuevamente para copiar de la temporal a la copia
    while (!es_vaciaPila(temp)) {
        char elemento = desapilar(&temp);
        apilar(copia, elemento);
    }
}

int main() {
    PILA pilaOriginal = crearPila();
    apilar(&pilaOriginal, 'A');
    apilar(&pilaOriginal, 'B');
    apilar(&pilaOriginal, 'C');

    PILA pilaCopia = crearPila();

    // Copiar la pila original a la pila de copia
    copiarPila(pilaOriginal, &pilaCopia);

    // Imprimir la pila original
    printf("Pila Original:\n");
    while (!es_vaciaPila(pilaOriginal)) {
        printf("%c ", desapilar(&pilaOriginal));
    }

    printf("\n");

    // Imprimir la pila de copia
    printf("Pila Copia:\n");
    while (!es_vaciaPila(pilaCopia)) {
        printf("%c ", desapilar(&pilaCopia));
    }

    return 0;
}
