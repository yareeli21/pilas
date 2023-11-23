#include<stdio.h>
#include "p5.h"
#include<stdlib.h>

void manejaMsg(int);
void mostrarExp(Expediente);
Expediente leerExped();
void expMes(PILA S);
void agregaExped(PILA S);
void expPorFecha(PILA S);
void menu(PILA);
void liberarMem(PILA);

void main(){
	PILA P;
	P=crearPila();
	agregaExped(P);
	menu(P);
	//liberarMem(P);
}
void menu(PILA P){
	int op;

	do{
		printf("Bienvenido al menu:)\n");
		printf("1. Mostrar expedientes por mes a la pila.\n");
		printf("2. Mostrar expedientes por fecha a la pila.\n");
		printf("3. Salir del programa.\n");
		printf("Ingrese su opcion: ");
		scanf("%d",&op);

	switch(op){

		case 1: expMes(P);
		        break;
		case 2:expPorFecha(P);
		       break;
		case 3: printf("Saliendo del programa.\n");
		       break;
		default: printf("No esta esa opcion:(\n");
		         break;
	}
	}while(op!=3);
	liberarMem(P);
}
//función para leer el expediente, dar los datos a cada apartado del expediente
Expediente leerExped(){
	Expediente exp;
	printf("Ingrese los datos del expediente:\n");
	printf("Numero: ");
	scanf("%d",&exp.numero);
	getchar();
	printf("Titular: ");
	scanf("%[^\n]",exp.titular);
	getchar();
	printf("Tramite: ");
	scanf("%[^\n]",exp.tramite);
	getchar();
	printf("Dia: ");
	scanf("%d",&exp.fec.dia);
	getchar();
	printf("Mes: ");
	scanf("%d",&exp.fec.mes);
	getchar();
	printf("Anio: ");
	scanf("%d",&exp.fec.anio);
	getchar();

	return exp;
}
//agregar un expediente
void agregaExped(PILA S){
	Expediente exp; //variable de tipo expediente que esto simulo como si fuera un número, etc...
   int e;
 do{
    printf("Ingrese 1 si desea agregar un expediente y 0 si ya no desea ingresar expedientes: ");
    scanf(" %d",&e);//el entero para confirmar que queremos agregar un nuevo expediente a la pila
    if(e==1){
       exp=leerExped();
       apilar(S,exp);
   }

 }while(e==1);

}
//agregar expediente por mes
void expMes(PILA S){
	int mes;
	printf("\tIngrese el mes del cual desea mostrar expedientes:\n");
	scanf("%d",&mes);
	PILA aux=crearPila();
	Expediente v;
	while(es_vaciaPila(S)!=TRUE){
		v=desapilar(S);
		apilar(aux,v);
		if(v.fec.mes==mes){
            mostrarExp(v);
		}
	}
	while(es_vaciaPila(aux)!=TRUE){
		apilar(S,desapilar(aux));
	}

}
//agregar expediente por fecha
void expPorFecha(PILA S){
	int d1,d2,m1,m2,a1,a2;
	Expediente exp;
	PILA aux=crearPila();
	printf("Ingrese la fecha inicial para mostrar expedientes:\n");
	printf("Dia: \n");
	scanf("%d",&d1);
	printf("Mes: \n");
	scanf("%d",&m1);
	printf("Anio: \n");
	scanf("%d",&a1);
	printf("Ingrese la fecha final para mostrar expedientes:\n");
	printf("Dia: \n");
	scanf("%d",&d2);
	printf("Mes: \n");
	scanf("%d",&m2);
	printf("Anio: \n");
	scanf("%d",&a2);
	printf("\tExpedientes del %d/%d/%d al %d/%d/%d\n",d1,m1,a1,d2,m2,a2);

	while(es_vaciaPila(S)!=TRUE){
		exp=desapilar(S);//en el primer while se tiene una variable exp ya que esa es la que se analizará
		apilar(aux,exp);
		if(exp.fec.dia >=d1 && exp.fec.dia <=d1){
			if(exp.fec.mes >=m1 && exp.fec.mes <=m2){
				if(exp.fec.anio >=a1 && exp.fec.anio <=a2){
					mostrarExp(exp);
				}
			}
		}
	}
	while(es_vaciaPila(aux)!=TRUE){
		apilar(S,desapilar(aux));//aquí se hace dierectamente porque no se busca analizar cada expediente
	}
}
void mostrarExp(Expediente exp){
	  printf("Numero: %d\n",exp.numero);
	  printf("Titular: %s\n",exp.titular);
	  printf("Tramite: %s\n",exp.tramite);
	  printf("Dia: %d\n",exp.fec.dia);
	  printf("Mes: %d\n",exp.fec.mes);
	  printf("Anio %d\n",exp.fec.anio);
}

void manejaMsg(int msg){
	char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  ","La Pila esta llena . . .","La Pila esta vacia . . ."};
	printf("%s", mensajes[msg] );
}

void liberarMem(PILA P){
	free(P);
	manejaMsg(1);
}
