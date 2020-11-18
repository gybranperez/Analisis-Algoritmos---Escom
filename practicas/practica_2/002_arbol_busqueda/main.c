#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tiempo.h"
#include "arbol.h"
#include <math.h>

#define DIEZ_M 10000000

void insertar(arbol *a,int *e);
int buscar(arbol *a, int *e);

int main(int argc, char* argv[]){

    int n; 	//n determina el tamaño del algorito dado por argumento al ejecutar
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	int i;
	int p; //Variable para loops
	arbol ArbolBus;

	//******************************************************************	
	//Recepción y decodificación de argumentos
	//******************************************************************	

	//Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)
	if (argc!=2) 
	{
		printf("\nIndique el número a buscar - Ejemplo: [user@equipo]$ %s 40000\n",argv[0]);
		exit(1);
	} 
	//Tomar el segundo argumento como tamaño del algoritmo
	else
	{
		n=atoi(argv[1]);
	}
	/*p=malloc(n*sizeof(int));

	if(p==NULL)
		exit(1);*/
	
    uswtime(&utime0, &stime0, &wtime0);
	construir(&ArbolBus);

	for(i=0;i<DIEZ_M;i++)                       //Se construye el árbol
	{
		scanf("%d",&p);
		insertar(&ArbolBus, &p);
	}

	printf("%s %d\n", buscar(&ArbolBus, &n) ? "se ha encontrado":"no se ha encontrado", n);     //Se realiza la búsqueda en el árbol
    uswtime(&utime1, &stime1, &wtime1);

    //Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	
	//Mostrar los tiempos en formato exponecial
	printf("\n");
	printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	//******************************************************************
	printf("--------------------------------------\n");

	destruir(&ArbolBus);
    return 0;
}

//Se usa apuntador en el parámetro para optimizar la inserción de los 10M de números: sin *e tarda ~ 19 s; con *e tarda ~ 16 s
void insertar(arbol *a,int *e)  
{
	arbol *p=a;
    while(*p !=NULL)
    {
        if( *e > ((*p)->raiz))
            p= &((*p)->de);
        else
            p=&((*p)->iz);
    }
    *p = (nodoA *)malloc(sizeof(nodoA));
	if(p == NULL){
		printf("error\n");
		exit(1);
	}
    (*p)->raiz = *e;

    (*p)->iz = NULL;
    (*p)->de = NULL;
	//printf("%d", e);
}

int buscar(arbol *a, int *e){
    arbol *p=a;
	
    while (*p != NULL)
    {
        if(*e == ((*p)->raiz)){
            return 1;
        }else if(*e > ((*p)->raiz)){
            p=&((*p)->de);
        }
        else{
            p=&((*p)->iz);
        }
    }
    return 0;
    
}