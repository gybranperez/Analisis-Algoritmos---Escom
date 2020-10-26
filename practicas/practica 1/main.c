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
//*****************************************************************
//DEFINICION DE CONSTANTES DEL PROGRAMA
//*****************************************************************

//********************************************************************************
//DECLARACION DE ESTRUCTURAS
//********************************************************************************

//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//*****************************************************************
void Burbuja(int p[],int n);
void BurbujaOptimizada(int p[],int n);
void insercion(int p[],int n);
void Seleccion(int A[], int n);
//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************

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
	insercion(p,n);


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
void Burbuja(int p[],int n)
{
		double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos


	int i, j, aux;
		for(i = 0; i <= n-1;i++)
				{
					for(j=0 ; j <= (n-2)-i ; j++)
							if(p[j] > p[j+1]){
								aux=p[j];
								p[j]=p[j+1];
								p[j+1]= aux;
								}

				}
				uswtime(&utime1, &stime1, &wtime1);
				//Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
}

void BurbujaOptimizada(int p[],int n)
{
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	//bool cambios=true;
	int i=0,j,aux,cambios=1;
		
		while((i<n-1) && (cambios != 0))
		{
			cambios=0;
			for(j=0;j<=(n-2)-i;j++)
			{
				if(p[j] > p[j+1])
				{
					aux=p[j];
					p[j]=p[j+1];
					p[j+1]=aux;
					cambios=1;
				}
			}
			i=i+1;
		}
		uswtime(&utime1, &stime1, &wtime1);
				//Cálculo del tiempo de ejecución del programa

		printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");

		for(i=0;i<n;i++)
		{
			printf("%d\n",p[i]);
		}

}

void insercion(int p[], int n)
{
	//Variables para medición de tiempos
	double utime0, stime0, wtime0,utime1, stime1, wtime1;
	uswtime(&utime1, &stime1, &wtime1);

	int i,j,temp;

	for(i=0 ; i <= n-1 ;i++)
	{
		j=i;
		temp=p[i];
		while((j>0) && (temp<p[j-1]))
			{
				p[j]=p[j-1];
				j--;
			}
			p[j]=temp;
	}
	uswtime(&utime1, &stime1, &wtime1);
				//Cálculo del tiempo de ejecución del programa

			printf("Insercion\n");
	printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10e %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
/*
		for(i=0;i<n;i++)
		{
			printf("%d\n",p[i]);
		}
		*/
}

void Seleccion(int A[], int n)
{
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	int i,j,k,p,temp;

	uswtime(&utime1, &stime1, &wtime1);
				//Cálculo del tiempo de ejecución del programa
	for (k=0; k <= n-2 ;k++)
	{
		p=k;
			for(i=k+1; i <= n-1 ;i++)
			{
				if(A[i]<A[p])
				{
					p=i;
				}
			} 
			temp = A[p];
			A[p] = A[k];
			A[k] = temp;

	}
	uswtime(&utime1, &stime1, &wtime1);
		printf("Seleccion\n");
	printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
/*
		for(i=0;i<n;i++)
		{
			printf("%d\n",A[i]);
		}
*/		
}