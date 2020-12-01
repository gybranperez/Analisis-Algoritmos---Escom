//*****************************************************************
//AUTORES:
// 	Pérez Sereno Ricardo Erick
//	Pérez Juarez Carlos Gybrán
// 	Ramirez Flores Juan
//
//Practica 2: Análisis temporal y notación de orden (Algoritmos de búsqueda)
//Compilación:
//	gcc tiempo.c -c
//	gcc Lineal.c tiempo.o -o Lineal
//
//Ejecución: "./Lineal 10000000 <ordenados.txt" (Linux)
//*****************************************************************

//*****************************************************************
//Librerias incluidas
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

//*****************************************************************
//Busqueda Lineal
//*****************************************************************
//Descripción: Función que implementa el algoritmo de busqueda Lineal
//Recibe: Un arreglo de enteros, el tamaño del arreglo y un entero a buscar
//Devuelve: -1 si no encontro el dato, o la posicion en el arreglo del dato
//*****************************************************************
int Lineal(int A[], int n, int dato)
{
	int posicion = 0;
	while(posicion < n)
	{
		if(dato == A[posicion])
			return posicion;
		posicion++;
	}
	return -1;
}

int main(int argc, char *argv[])
{
	//Obtenemos n como parametro del main y creamos una arreglo dinamico
	int n = atoi(argv[1]), i = 0, j = 0;
	float suma = 0, promedio = 0;
	int *arreglo = (int*)calloc(n,sizeof(int));
	int datos[20] = {322486, 14700764, 3128036, 6337399, 61396,
	10393545, 2147445644, 1295390003, 450057883, 187645041,
	1980098116, 152503, 5000, 1493283650, 214826, 1843349527,
	1360839354, 2109248666 , 2147470852, 0};

	//Agregamos los n valores del txt al arreglo
	for(i = 0; i < n; i++)
		fscanf(stdin, "%d", &arreglo[i]);
	printf("Busqueda Lineal n = %d\n", n);
	printf("Num Buscado,Nums Arreglo,Encontrado,Real,CPU,E/S,CPU/Wall\n");
	//Buscamos los valores solicitados en la lista de 10 millones
	for(j = 0; j < 20; j++)
	{
		double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
		uswtime(&utime0, &stime0, &wtime0);

		int s = Lineal(arreglo, n, datos[j]);

		uswtime(&utime1, &stime1, &wtime1);
		
		//if(j == 17)// para 2109248666
		//{
			/*if(s != -1)
				printf("\n\n%d SI : %d ", datos[j], s);
			else
				printf("\n\n%d NO : --- ", datos[j]);
			*/
			//Cálculo del tiempo de ejecución del programa
			/*
			printf("\n");
			printf("Total %.15e \n",  wtime1 - wtime0); //Tiempo Real
			printf("CPU %.15e \n",  utime1 - utime0); //Tiempo CPU
			printf("E/S %.15e \n",  stime1 - stime0); //Tiempo E/S
			printf("CPU/Wall %.8f %% ",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0)); //CPU Wall
			printf("\n");
			*/
			if(s != -1)
				printf("%d,%d,SI,%.15e,%.15e,%.15e,%.8f %%\n",datos[j],n,wtime1-wtime0,utime1-utime0,stime1-stime0,100.0*(utime1-utime0+stime1-stime0));
			else
				printf("%d,%d,NO,%.15e,%.15e,%.15e,%.8f %%\n",datos[j],n,wtime1-wtime0,utime1-utime0,stime1-stime0,100.0*(utime1-utime0+stime1-stime0));
			
		//}
		suma = suma + wtime1 - wtime0;
	}
	printf("\nPromedio Tiempo Total: %.20f s\n\n", suma/20);
	return 0;	
}