//*****************************************************************
//	AUTORES:
// 	Pérez Sereno Ricardo Erick
//	Pérez Juarez Carlos Gybrán
// 	Ramirez Flores Juan
// ****************************************************************
//	Practica 2: Análisis temporal y notación de orden (Algoritmos de búsqueda)
//	Compilación:
//	gcc tiempo.c -c
//	gcc ABB.c tiempo.o -o ABB
//
//	Ejecución: "./ABB 10000000 <desordenados.txt" (Linux)
//	***************************************************************

//	***************************************************************
//						Librerias incluidas
//	***************************************************************
#include <stdio.h>
#include <stdlib.h>
#include "Arbin.h"
#include "tiempo.h"

//	***************************************************************
//						Insertar
//	***************************************************************
//	Descripción: Inserta un arreglo de números en un ABB
//	Recibe: Un ABB vacio y un entero
//	Devuelve: Nada, pero construye el arbol binario
//	***************************************************************
void Insertar(Arbin *a, int e)
{
	Arbin *apu_a = a; // Declaramos un apuntador para recorrer el árbol
	while (*apu_a != NULL)
	{	
		if (e > ((*apu_a) -> raiz)) 
			apu_a = &((*apu_a) -> der);
		else
			apu_a = &((*apu_a) -> izq);	
	}
	*apu_a = (NodoA *)malloc(sizeof(NodoA)); 
	(*apu_a) -> raiz = e;			// En el nodo colocaremos el elemento a introducir en el árbol
	(*apu_a) -> izq = NULL;		// Nos aseguramos de que ambos hijos estén apuntando a un valor NULL
	(*apu_a) -> der = NULL;
}

//	***************************************************************
//						ABB
//	***************************************************************
//	Descripción: Busca si existe un elemento en el arbol
//	Recibe: Un arbol binario y el elemento a buscar
//	Devuelve: 0 si existe el elemento, -1 si no existe
//	***************************************************************

int ABB(Arbin *a, int elemento)
{
	// Declaramos un apuntador auxiliar para viajar por el árbol
	posicion a_aux = *a; 
	int numero; // Auxiliar para comparar
	do
	{ 
		numero = a_aux -> raiz; 
		// Ese nodo dira cual es el numero en ese momento, posteriormente moveremos el índice un lugar más					
		//printf("Compara: Arbol-%d , elemento-%d \n", numero, elemento);
		if(numero == elemento)
		{
			a_aux = NULL;
			return 0;
		}
		else if(numero < elemento)
		{
			// Si el elemento es mayor a la raiz, vamos al lado derecho del subarbol
			a_aux = a_aux -> der;		
		}
		else
		{
			// Si el elemento es menor a la raiz, vamos al lado izquierdo del subarbol
			a_aux = a_aux -> izq; 		
		}
	} 
	while (a_aux != NULL); // Apuntador nulo

	return -1;
}

int main(int argc, char *argv[])
{
	//Obtenemos n como parametro del main y creamos una arreglo dinamico
	int n = atoi(argv[1]), i = 0, j = 0, k = 0;
	int *arreglo = (int*)calloc(n,sizeof(int));
	float suma = 0, promedio = 0;
	// DECLARO UN ARREGLO PARA LOS DATOS QUE VAMOS A BUSCAR EN EL ARBOL
	int datos[20] = {322486, 14700764, 3128036, 6337399, 61396,
	10393545, 2147445644, 1295390003, 450057883, 187645041,
	1980098116, 152503, 5000, 1493283650, 214826, 1843349527,
	1360839354, 2109248666 , 2147470852, 0};

	
	//Con este for vamos agregando los n valores del txt al arreglo
	for(k = 0; k < n; k++)
	{
		fscanf(stdin, "%d", &arreglo[k]);
	}

	/*AGREGA AL ARBOL LOS NUMEROS DEL TXT*/
	Arbin ArbolBinBusqueda;
	consA(&ArbolBinBusqueda); //Asignamos el valor NULL al apuntador del ABB
	
	for(i = 0; i < n; i++)
	{
		Insertar(&ArbolBinBusqueda, arreglo[i]);
	}

	/*
		BUSCA EN EL ARBOL CADA NUMERO DEL ARREGLO DATOS
	*/
	printf("\nArbol de Busqueda Binaria n = %d\n", n);
	printf("Num Buscado,Nums Arreglo,Encontrado,Real,CPU,E/S,CPU/Wall\n");
	
	for(j = 0; j < 20; j++)
	{
		double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
		uswtime(&utime0, &stime0, &wtime0);

		int s = ABB(&ArbolBinBusqueda, datos[j]);
		// La funcion recibe el arbol, numero de datos y el dato

		uswtime(&utime1, &stime1, &wtime1);
		/*
		if(j == 17)// para 2109248666
		{
			if(s != -1)
				printf("\n\n%d SI : %d ", datos[j], s);
			else
				printf("\n\n%d NO : --- ", datos[j]);

			//Cálculo del tiempo de ejecución del programa
			printf("\n");
			printf("Total %.15e \n",  wtime1 - wtime0); //Tiempo Real
			printf("CPU %.15e \n",  utime1 - utime0); //Tiempo CPU
			printf("E/S %.15e \n",  stime1 - stime0); //Tiempo E/S
			printf("CPU/Wall %.8f %% ",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0)); //CPU Wall
			printf("\n");
		}
		*/
		if(s != -1)
			printf("%d,%d,SI,%.15e,%.15e,%.15e,%.8f %%\n",datos[j],n,wtime1-wtime0,utime1-utime0,stime1-stime0,100.0*(utime1-utime0+stime1-stime0));
		else
			printf("%d,%d,NO,%.15e,%.15e,%.15e,%.8f %%\n",datos[j],n,wtime1-wtime0,utime1-utime0,stime1-stime0,100.0*(utime1-utime0+stime1-stime0));
			
		suma = suma + wtime1 - wtime0;
	}

	destruir(&ArbolBinBusqueda);	

	printf("\nPromedio Tiempo Total: %.20f s\n\n", suma/20);
	

	return 0;
}

