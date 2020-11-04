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


//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//*****************************************************************
void shell(int A[],int n);


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
	shell(p,n);

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
double utime0, stime0, wtime0,utime1, stime1, wtime1; 
	uswtime(&utime0, &stime0, &wtime0);
	
	
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
			uswtime(&utime1, &stime1, &wtime1);
	
	printf("\n\nShell con %d numeros",n);
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

	printf("--------------------------------------------------------------------------------------------------\n");

}


