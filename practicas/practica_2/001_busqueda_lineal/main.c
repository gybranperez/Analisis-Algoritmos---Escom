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
		double utime0, stime0, wtime0, utime1, stime1, wtime1; //Variables para medición de tiempos
	int n; 	//n determina el tamaño del algorito dado por argumento al ejecutar
	int i,j,bandera=0; //Variables para loops
	int *A;
	int numeros[20]={322468,14700764,3128036,6337399,61396,10393545,2147445644,129539003,450057883,187645041,1980098116,152503,5000,1493283650,214826,1843349527,1360839354,2109248666,2147470852,0};
	n=atoi(argv[1]);
	//******************************************************************	
	//Recepción y decodificación de argumentos
	//******************************************************************	
	A=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	//******************************************************************	
	//Algoritmo
	//******************************************************************	
	for(i=0;i<20;i++)
	{
			utime0=0;
		stime0=0; 
		wtime0=0; 
		utime1=0; 
		stime1=0; 
		wtime1=0;
		bandera=0;

		uswtime(&utime0, &stime0, &wtime0); 
			for(j=0;j<n;j++)
			{
				if(A[j]==numeros[i]){
					printf("Se encontro el numero %d, en la posición %d\n",numeros[i],j);
					bandera = 1;
				}			
			}
			if(bandera == 0){
					printf("No se encontro el numero %d\n",numeros[i]);
				}
			//******************************************************************	
	//Evaluar los tiempos de ejecución 
	//******************************************************************
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
	printf("-------------------------------------------------------------------------------------------------------");
	//Terminar programa normalmente
	}
	//******************************************************************
return 0;
	
}

//************************************************************************
//DEFINICIÓN DE FUNCIONES 
//************************************************************************

