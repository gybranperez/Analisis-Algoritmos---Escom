//*****************************************************************
/*Elaborado por:
	Pérez Juarez Carlos Gybran
	Pérez Sereno Ricardo Erick
	Ramirez Flores Juan
*/
//M. EN C. EDGARDO ADRIÁN FRANCO MARTÍNEZ
//Curso: Análisis de algoritmos
//ESCOM-IPN
//Ejemplo de medición de tiempo en C y recepción de parametros en C bajo UNIX
//Compilación: "gcc main.c tiempo.c
//Ejecución: "./script.sh
//*****************************************************************
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
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
//********************************************************************************
//DECLARACION DE ESTRUCTURAS
//********************************************************************************

//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//*****************************************************************
int busquedaFibonacci(int A[], int n, int x);
//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************

//*****************************************************************
//PROGRAMA PRINCIPAL
//*****************************************************************
int main(int argc, char *argv[])
{
	//******************************************************************
	//Variables del main
	//******************************************************************
	int n;				   //n determina el tamaño del algorito dado por argumento al ejecutar
	int i, j, bandera = 0; //Variables para loops
	int *A;
    float suma = 0, promedio = 0;
	int numeros[20] = {322468, 14700764, 3128036, 6337399, 61396, 10393545, 2147445644, 129539003, 450057883, 187645041, 1980098116, 152503, 5000, 1493283650, 214826, 1843349527, 1360839354, 2109248666, 2147470852, 0};
	n = atoi(argv[1]);

	int encontrados;
	//******************************************************************
	//Recepción y decodificación de argumentos
	//******************************************************************
	A = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
    printf("Busqueda Fibonacci n = %d\n", n);
	printf("Num Buscado,Nums Arreglo,Encontrado,Real,CPU,E/S,CPU/Wall\n");
	
	//******************************************************************
	//Algoritmo
	//******************************************************************
	for (i = 0; i < 20; i++)
	{
		double utime0, stime0, wtime0, utime1, stime1, wtime1; //Variables para medición de tiempos
		uswtime(&utime0, &stime0, &wtime0);
		encontrados = busquedaFibonacci(A, n - 1, numeros[i]);
		//******************************************************************
		//Evaluar los tiempos de ejecución
		//******************************************************************
		uswtime(&utime1, &stime1, &wtime1);
    if(encontrados != -1)
        printf("%d,%d,SI,%.15e,%.15e,%.15e,%.8f %%\n",numeros[i],n,wtime1-wtime0,utime1-utime0,stime1-stime0,100.0*(utime1-utime0+stime1-stime0));
    else
        printf("%d,%d,NO,%.15e,%.15e,%.15e,%.8f %%\n",numeros[i],n,wtime1-wtime0,utime1-utime0,stime1-stime0,100.0*(utime1-utime0+stime1-stime0));
    
	//Terminar programa normalmente
	suma = suma + wtime1 - wtime0;
    //Terminar programa normalmente
	}
    printf("\nPromedio Tiempo Total: %.20f s\n\n", suma/20);
	//******************************************************************
	return 0;
}

//************************************************************************
//Busqueda Fibonacci, busca el valor de x en el arreglo
//Esta función recibe un arreglo de enteros, un numero a buscar y el tamaño del arreglo
//Devuelve -1 si no se encontro el numero.
//************************************************************************
int busquedaFibonacci(int A[], int n, int x)
{
	/* Inicializamos los numeros de fibonacci*/
	int fibMMm2 = 0;			  // (m-2)'th número de fibonacci
	int fibMMm1 = 1;			  // (m-1)'th número de fibonacci
	int fibM = fibMMm2 + fibMMm1; // m número de fibonacci

	/* fibM Almacenara el menor número de fib.*/
	while (fibM < n)
	{
		fibMMm2 = fibMMm1;
		fibMMm1 = fibM;
		fibM = fibMMm2 + fibMMm1;
	}

	// se marca el rango de eliminacion.
	int offset = -1;

	/* SI bien hay elementos que serán inspeccionados.
    se copara a[fibMm2] con x. cuando fibM se convierte en 1, fibMm2 se 	convierte en 0 */
	while (fibM > 1)
	{
		// Checa si fibMm2 es una ubicación valida
		int i = MIN(offset + fibMMm2, n - 1);

		/* Comprueba si fibMm2 es valido*/
		if (A[i] < x)
		{
			fibM = fibMMm1;
			fibMMm1 = fibMMm2;
			fibMMm2 = fibM - fibMMm1;
			offset = i;
		}

		/* si x es mayor que el indice de fibMm2,se corta el subarreglo i+1  */
		else if (A[i] > x)
		{
			fibM = fibMMm2;
			fibMMm1 = fibMMm1 - fibMMm2;
			fibMMm2 = fibM - fibMMm1;
		}

		/* elemento encontrado, retorna indice*/
		else
			return i;
	}

	/* compara el último elemento con x*/
	if (fibMMm1 && A[offset + 1] == x)
		return offset + 1;

	/*si no encuentra el elemento retorna -1*/
	return -1;
}
