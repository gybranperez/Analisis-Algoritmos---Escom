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
#define MIN(a,b) (((a)<(b))?(a):(b))
//********************************************************************************
//DECLARACION DE ESTRUCTURAS
//********************************************************************************

//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//*****************************************************************
int busquedaExponencial(int A[], int n, int x);
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
	int i,j,bandera=0; //Variables para loops
	int *A;
	int numeros[20]={322468,14700764,3128036,6337399,61396,10393545,2147445644,129539003,450057883,187645041,1980098116,152503,5000,1493283650,214826,1843349527,1360839354,2109248666,2147470852,0};
	n=atoi(argv[1]);
    float suma = 0, promedio = 0;
	int encontrados;
	//******************************************************************	
	//Recepción y decodificación de argumentos
	//******************************************************************	
	A=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
    printf("Busqueda Exponencial n = %d\n", n);
	printf("Num Buscado,Nums Arreglo,Encontrado,Real,CPU,E/S,CPU/Wall\n");
	
	//******************************************************************	
	//Algoritmo
	//******************************************************************	
	for(i=0;i<20;i++)
	{
		double utime0, stime0, wtime0, utime1, stime1, wtime1; //Variables para medición de tiempos
		uswtime(&utime0, &stime0, &wtime0); 
		encontrados = busquedaExponencial(A, n - 1, numeros[i]);
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
	}
    printf("\nPromedio Tiempo Total: %.20f s\n\n", suma/20);
	//******************************************************************
return 0;
	
}

//************************************************************************
//Busqueda exponencial, busca el valor de x en el arreglo
//Esta función recibe un arreglo de enteros, un numero a buscar y el tamaño del arreglo
//Devuelve -1 si no se encontro el numero.
//************************************************************************
int busquedaExponencial(int A[], int n, int x)
{
    // SI esta presente en la primera posicion
    if (A[0] == x)
        return 0;
 
    //Encuentra el rango para la busqueda binaria duplicando repetidamente
    int i = 1;
    while (i < n && A[i] <= x)
        i = i*2;
    int l = i/2, r = MIN(i, n);
    while (l <= r) { 
        int m = l + (r - l) / 2; 
  
        // Checa si x esta presente en medio
        if (A[m] == x) 
            return m; 
  
        // SI X ES MAYOR, ignora la mitad de la izquierda
        if (A[m] < x) 
            l = m + 1; 
  
        // Si x es menor ignora la mitad de la derecha
        else
            r = m - 1; 
    }
    return -1;

}

