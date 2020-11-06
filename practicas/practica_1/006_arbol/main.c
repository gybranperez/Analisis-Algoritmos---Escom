//*****************************************************************
//M. EN C. EDGARDO ADRIÁN FRANCO MARTÍNEZ 
//Curso: Análisis de algoritmos
//(C) Enero 2013
//ESCOM-IPN
//Ejemplo de medición de tiempo en C y recepción de parametros en C bajo UNIX
//Compilación: "gcc main.c tiempo.x  -o main(teimpo.c si se tiene la implementación de la libreria o tiempo.o si solo se tiene el codigo objeto)"
//Ejecución: "./main n" (Linux y MAC OS)
//*****************************************************************

//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <stdio.h>
#include "tiempo.h"
#include <stdlib.h>
#include <math.h>
#include "arbol.h"

//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//*****************************************************************

void insertar(arbol *a,int e);
void guardarRecorrido(arbol *a,int A[], int n);
void Ordenar(int A[], int n);


//*****************************************************************
//PROGRAMA PRINCIPAL 
//*****************************************************************
int main (int argc, char* argv[])
{	
	//******************************************************************	
	//Variables del main
	//******************************************************************	
	int n; 	//n determina el tamaño del algorito dado por argumento al ejecutar
	int i;
	int *p; //Variables para loops

	//******************************************************************	
	//Recepción y decodificación de argumentos
	//******************************************************************	

	//Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)
	if (argc!=2) 
	{
		printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		exit(1);
	} 
	//Tomar el segundo argumento como tamaño del algoritmo
	else
	{
		n=atoi(argv[1]);
	}
	p=malloc(n*sizeof(int));

	if(p==NULL)
			exit(1);

	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	//******************************************************************
	
	//******************************************************************	
	//Algoritmo
	//******************************************************************	
	Ordenar(p,n);

	//******************************************************************

	//******************************************************************	
	//Evaluar los tiempos de ejecución 
	//******************************************************************
	
	//Terminar programa normalmente	
	exit (0);	
}

//************************************************************************
//DEFINICIÓN DE FUNCIONES 
//************************************************************************




void insertar(arbol *a,int e)
{
	arbol *p=a;
		while(*p !=NULL)
		{
			if( e > ((*p)->raiz))
				{
				p= &((*p)->de);
				}
			else{
				p=&((*p)->iz);
			}
		}
*p = (nodoA *)malloc(sizeof(nodoA));
(*p)->raiz = e;

(*p)->iz = NULL;
(*p)->de = NULL;

}

void guardarRecorrido(arbol *a,int A[], int n)
{
	pos aux = *a;
	nodoA **pila = (nodoA **)malloc(n*sizeof(arbol));
	int top = -1;
	int i = 0;
	do
	{
		while(aux != NULL)
		{
			pila[++top]=aux;
			aux=aux -> iz;

		}

	if(top >= 0)
	{
		aux = pila[top--];
		A[i++] = aux -> raiz;
		aux = aux -> de;
	}

	}while(aux != NULL || top >= 0);
free(pila);
	
	

}

void Ordenar(int A[], int n)
{
	double utime0, stime0, wtime0,utime1, stime1, wtime1; 
	uswtime(&utime0, &stime0, &wtime0);
	
	
	arbol ArbolBus;
	
	int i,j;
	
	construir(&ArbolBus);
	
	for(i=0; i<n ; i++)
	{
		insertar(&ArbolBus,A[i]);
	}
	guardarRecorrido(&ArbolBus,A,n);

	destruir(&ArbolBus);

	uswtime(&utime1, &stime1, &wtime1);
	
	for(i=0; i<n ; i++)
	{
		printf("\n%d",A[i]);
	}
	printf("\n\nArbol binario con %d numeros",n);
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

	printf("-----------------------------------------------------------------------------------\n");
	
}

