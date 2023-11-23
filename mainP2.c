#include<stdio.h>
#include<stdlib.h>
#include "p2.h"

//void mostrarSalida(char * ent, char ev);
void evalua(PILA S, char *ent);
void lee(char *ent);
void manejaMsg(int e);
void liberar(PILA);
int verificar(PILA A, PILA B);

/*Programa Principal*/
void main(){
	PILA S;
  //se está creando un arreglo de tamaño definido
  char ent[TAMPILA];
  int p;

  S = crearPila( );

  lee(ent);
  evalua(S, ent);
  //mostrar(p);
  liberar(S);
}

/* Lee una expresión en Postfija */
void lee(char *ent){

  int pos=0;

  printf("\n\tEvaluacion de expresiones Postfijas\n");
  printf("Operaciones Basicas: Suma, Resta, Producto, Division y Potencia\n\n");
  printf("\n\n Introduzca la expresion en Postfija: ");
  while( (ent[pos++] = getchar()) != '\n');
  ent[--pos]='\0';
}

/*Evalua la expresion*/
void evalua(PILA S, char *ent){
  char b;
  int pos=0;
  char op[1];
  PILA Aux1,Aux2;
  Aux1=crearPila();
  Aux2=crearPila();
  //aquí dice: "mientras que el arreglo ent con pos 0 (que irá aumentando) sea diferente de fin de cadena, la opción tomará el dato de la posición en la que va"
  while(ent[pos] != '\0'){
      *op = ent[pos++];

      switch(*op){

        case '(':
        case '[':
        case '{':
              apilar(Aux1,*op);
              break;
        case ')':
        case ']':
        case '}':
              apilar(Aux2,*op);
              break;

      default:
           printf("\nNo existen parentesis, llaves ni corchetes en la expresion\n");
             return;

      }
  }
 int v= verificar(Aux1,Aux2);
  if(v==TRUE){
    printf("\nLos simbolos estan equilibrados :)\n");
  }
  else
    printf("\nLos simbolos no estan equilibrados :(\n");
}
int verificar(PILA A, PILA B){
  //recorriendo una pila
    while(es_vaciaPila(A)!=TRUE && es_vaciaPila(B)!=TRUE){
      char apertura=desapilar(A);
      char cierre=desapilar(B);
      //se realiza el chequeo sobre si el de apertura es tal y el de cerradura es diferente al símbolo de cerrar
      if((apertura=='(' && cierre !=')') ||(apertura=='{' && cierre!='}') || (apertura=='[' && cierre!=']')){
        return 0;
      }

      }
      return (es_vaciaPila(A)&&es_vaciaPila(B));
    }
void liberar(PILA S){
    free(S);
    manejaMsg(4);
}

void manejaMsg(int e){
  char * errores[]={"No hay memoria disponible\n","Pila Llena\n", "Pila Vacia\n", "\n\n Division por CERO\n", "\nMemoria Liberada ..."};
  printf("%s", errores[e]);
}

