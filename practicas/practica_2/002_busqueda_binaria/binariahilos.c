//*****************************************************************
//AUTORES:
// 	Pérez Sereno Ricardo Erick
//	Pérez Juarez Carlos Gybrán
// 	Ramirez Flores Juan
//
//Practica 2: Análisis temporal y notación de orden (Algoritmos de búsqueda)
//Compilación:
//	gcc tiempo.c -c
//	gcc -lm BinariaHilos.c tiempo.o -lpthread -o BinariaHilos
//Ejecución: "./BinariaHilos 4 10000000 <ordenados.txt"
//*****************************************************************

//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"

//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************
int NumThreads, N, indice = 0, encontrado = -1, s = 0;
//Variables del tamaño de problema, numeros de hilos, y auxiliares para
//recorrer nuestro arreglo de numeros a buscar
int *arreglo;//Arreglo de los numeros de entrada del TXT
int datos[20] = {322486, 14700764, 3128036, 6337399, 61396,
10393545, 2147445644, 1295390003, 450057883, 187645041,
1980098116, 152503, 5000, 1493283650, 214826, 1843349527,
1360839354, 2109248666 , 2147470852, 0};//Arreglo de numeros a buscar

//*****************************************************************
//BinariaHilos
//*****************************************************************
//Descripción: Hilo que procesa el algoritmo de busqueda binaria
//Recibe: Un indice de tipo void que indica el numero de hilo
//Devuelve: Nada, pero indica si el dato a buscar esta o no en el 
//arreglo de numeros ordenados
//*****************************************************************
void* BinariaHilos(void* id)
{	
	int n_thread=(int)id, inicio, fin;

	//Revisar la parte de los datos a procesar	
	inicio=(n_thread*N)/NumThreads;
	if(n_thread==NumThreads-1)	
		fin=N-1;
	else
		fin=((n_thread+1)*N)/NumThreads-1;

	//***************************************************************
	//Implementacion del algoritmo Busqueda binaria
	//***************************************************************
	int centro, inf = inicio, sup = fin;
	while(inf <= sup)
	{
		centro = ((sup + inf)/2);
		if(arreglo[centro] == datos[indice])
		{
			encontrado = 1;
			s = centro;
			break;
		}
		else if (datos[indice] < arreglo[centro])
			sup = centro - 1;
		else
			inf = centro + 1;
	}
}

//*****************************************************************
//PROGRAMA PRINCIPAL 
//*****************************************************************
int main (int argc, char *argv[])
{	
	int i, k; 	//Variables auxiliares para loops
	float suma = 0, promedio = 0;
	NumThreads = atoi(argv[1]);
	N = atoi(argv[2]);
	arreglo = (int*)calloc(N,sizeof(int));

	//Con este for vamos agregando los n valores del txt al arreglo
	for(k = 0; k < N; k++)
		fscanf(stdin, "%d", &arreglo[k]);
	printf("\nBusqueda Binaria Hilos n = %d\n\n", N);

	//Con este for vamos buscando cada numero en el arreglo
	for(indice = 0; indice < 20; indice++)
	{
		//******************************************************************	
		//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
		//******************************************************************	
		double utime0, stime0, wtime0,utime1, stime1, wtime1;
		uswtime(&utime0, &stime0, &wtime0);
		encontrado = -1;
		s = 0;

		//********************************************************************************
		//Obtener el número de threads a usar y el arreglo para la identificacion de los mismos
		//********************************************************************************
		pthread_t *thread;
		thread = calloc(NumThreads,sizeof(pthread_t));

		//******************************************************************************
		//Procesar desde cada hilo "BinariaHilos"
		//*******************************************************************************
		//Crear los threads con el comportamiento "segmentar"
		for (i = 1; i < NumThreads; i++) 
		{
			if (pthread_create(&thread[i], NULL, BinariaHilos,(void*)i) != 0 ) 
			{
				perror("El hilo no pudo crearse");
				exit(-1);
			}
		}
		
		//El main ejecuta el hilo 0
		BinariaHilos(0);
		
		//Esperar a que terminen los hilos
		for (i = 1; i < NumThreads; i++)
			pthread_join (thread[i], NULL);

		free(thread);
		//******************************************************************	
		//Evaluar los tiempos de ejecución 
		//******************************************************************
		uswtime(&utime1, &stime1, &wtime1);

		//Cálculo del tiempo de ejecución del programa
		if(indice == 17)// para 2109248666
		{
			if(encontrado != -1)
				printf("\n%d SI : %d ", datos[indice], s);
			else
				printf("\n%d NO : --- ", datos[indice]);

			printf("\n");
			printf("Total  %.15e\n",  wtime1 - wtime0);
			printf("CPU's %.15e\n",  utime1 - utime0);
			printf("Hilo %.15e\n", (utime1 - utime0)/NumThreads);	
			printf("E/S %.15e\n",  stime1 - stime0);
			printf("CPU/Wall %.8f %%\n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
			printf("\n");
		}
		suma = suma + wtime1 - wtime0;

		//******************************************************************
	}
	printf("\nPromedio Tiempo Total: %.20f s\n\n", suma/20);
	
	printf("------------------------------------\n");
	
	//Terminar programa normalmente	
	exit (0);	
}
