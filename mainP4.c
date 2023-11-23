#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "p3.h"

void menu(PILA);
void datosEntrada(PILA S);
int elemPila(PILA S);
char fondoElem(PILA S);
PILA copiarPila(PILA S);
void mostrarPila(PILA S);
void mostrarCopia(PILA S);
void manejaMsg(int e);
void liberar(PILA);


/*Programa Principal*/
void main(){
	PILA S;
  S = crearPila( );
  datosEntrada(S);
  menu(S);
  liberar(S);
}

/* Lee una cadena */
void menu(PILA S){
    int op,numElem;
    char fondo;
    PILA OTRA=crearPila();
    do{
        printf("\nBienvenido al menu.\n");
        printf("1. Se calcula el numero de elementos de la pila.\n");
        printf("2. Se consulta el elemento del fondo de la pila.\n");
        printf("3. Se copia una la pila a otra.\n");
        printf("4. Salir del programa jeje:)\n");
        printf("Seleccione una opcion:\n");
        scanf("%d",&op);

        switch(op){

            case 1: numElem=elemPila(S);
                    printf("La pila tiene %d elementos.\n",numElem);
                    break;
            case 2: fondo=fondoElem(S);
                    printf("El elemento del fondo es: %c\n",fondo);
                    break;
            case 3: OTRA=copiarPila(S);
                    printf("La pila copiada es:\n");
                    mostrarPila(OTRA);
                    break;
            default: printf("Saliendo del programa...:)\n");
        }
    }while(op!=4);
    liberar(OTRA);
}
void datosEntrada(PILA S){
   char v;
 do{
    printf("Ingrese datos para agregar a la pila(0 para detener):\n");
    scanf(" %c",&v);
    int c;
    //while (c=getchar()!='\0');
    if(v!='0'){
       apilar(S,v);
   }

 }while(v != '0');

}
int elemPila(PILA S){
    int cont=0;
    PILA aux=crearPila();
    while(es_vaciaPila(S)!=TRUE){
        apilar(aux,desapilar(S));
        cont ++;
    }
    while(es_vaciaPila(aux)!=TRUE){
        apilar(S,desapilar(aux));
    }
    return cont;
}
char fondoElem(PILA S){
    PILA AUX=crearPila();
    char elem;
    while(es_vaciaPila(S)!=TRUE){
        apilar(AUX,desapilar(S));
    }
    elem=elemTope(AUX);
    while(es_vaciaPila(AUX)!=TRUE){
        apilar(S,desapilar(AUX));
    }
    return elem;
}
PILA copiarPila(PILA S){
    int v;
    PILA copia=crearPila();
    //creamos una pila auxiliar para que no sufran cambios los datos de la pila original y quede igual
    PILA aux=crearPila();
    while(es_vaciaPila(S)!=TRUE){
        apilar(aux,desapilar(S));
    }
    while(es_vaciaPila(aux)!=TRUE){
        v=desapilar(aux);
        apilar(copia,v);//pila copia
        apilar(S,v);//pila original
    }
   liberar(aux);
    return copia;
}


void mostrarPila(PILA S){
 while(es_vaciaPila(S)!=TRUE){
    char v;
    v=desapilar(S);
    printf("%c\n",v);
 }
}

void liberar(PILA S){
    free(S);
    manejaMsg(4);
}

void manejaMsg(int e){
  char * errores[]={"No hay memoria disponible\n","Pila Llena\n", "Pila Vacia\n", "\n\n Division por CERO\n", "\nMemoria Liberada ..."};
  printf("%s", errores[e]);
}
