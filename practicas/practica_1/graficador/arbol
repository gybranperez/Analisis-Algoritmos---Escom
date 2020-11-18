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
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tiempo.h"
#include <stdlib.h>
#include <math.h>
#include "arbol.h"

//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//*****************************************************************
void Burbuja(int p[],int n);
void BurbujaOptimizada(int p[],int n);
void insercion(int p[],int n);
void Seleccion(int A[], int n);
void shell(int A[],int n);
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


void shell(int A[],int n)
{
	int k=trunc(n/2);
	int b=0,i=0,temp=0;
		while(k>=1)
		{
			b=1;
			while(b!=0)
			{
               b=0;
               	for(i=k;i<=(n-1);i++)
               	{
               		if(A[i-k] > A[i])
               		{
               			temp=A[i];
               			A[i]=A[i-k];
               			A[i-k]=temp;
               			b=b+1;
               		}
               	}
			}
			k=trunc(k/2);
		}
		for(i=0;i<n;i++)
		{
			printf("%d\n",A[i]);
		}
}

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
	nodoA **pila = (nodoA **)malloc(n* sizeof(arbol));
	int top = -1;
	int i = 0;

	do
	{
		while(aux != NULL)
		{
			pila[top++]=aux;
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
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	int i,j;
	arbol ArbolBus;
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
		printf("%d\n",A[i]);
	}

}

