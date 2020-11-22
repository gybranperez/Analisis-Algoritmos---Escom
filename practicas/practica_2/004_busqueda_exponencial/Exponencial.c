#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

#define MIN(a,b) (((a)<(b))?(a):(b))

int busquedaBinaria(int arr[], int l, int r, int x);
int busquedaExponencial(int arr[], int n, int x);

int main(int argc, char* argv[]) 
{ 
    int n, *p, i, result;
    int datos[20] = {322486, 14700764, 3128036, 6337399, 61396,
	10393545, 2147445644, 1295390003, 450057883, 187645041,
	1980098116, 152503, 5000, 1493283650, 214826, 1843349527,
	1360839354, 2109248666 , 2147470852, 0};

    //******************************************************************	
	//Recepción y decodificación de argumentos
	//******************************************************************	

	//Si no se introducen exactamente 3 argumentos (Cadena de ejecución, cadena=n y número a buscar = m)
	if (argc!=2) 
	{
		printf("\nIndique el número a buscar - Ejemplo: [user@equipo]$ %s 40000\n",argv[0]);
		exit(1);
	} 
	//Tomar el segundo argumento como tamaño del algoritmo
	else
	{
		n=atoi(argv[1]);
		//m=atoi(argv[2]);
	}

    p=malloc(n*sizeof(int));
    if(p==NULL) exit(1);

    double utime0, stime0, wtime0,utime1, stime1, wtime1;
	
    uswtime(&utime0, &stime0, &wtime0);
    for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}

    for (i = 0; i < 20; i++)
    {
        result = busquedaExponencial(p, n - 1, datos[i]);
        (result == -1) ? printf("Element is not present"
                            " in array") 
                   : printf("Element is present at "
                            "index %d", 
                            result); 
    }
    
    uswtime(&utime1, &stime1, &wtime1);

    

    printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU's) %.10f s\n",  utime1 - utime0);
	//printf("%d threads (Tiempo de procesamiento aproximado por cada thread en CPU) %.10f s\n", NumThreads,(utime1 - utime0)/NumThreads);	
	printf("sys (Tiempo en acciónes de E/S)  %.3f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");

    free(p);
    return 0; 
} 

/*int busquedaBinaria(int arr[], int l, int r, int x) 
{ 
    while (l <= r) { 
        int m = l + (r - l) / 2; 
  
        // Check if x is present at mid 
        if (arr[m] == x) 
            return m; 
  
        // If x greater, ignore left half 
        if (arr[m] < x) 
            l = m + 1; 
  
        // If x is smaller, ignore right half 
        else
            r = m - 1; 
    } 
  
    // if we reach here, then element was 
    // not present 
    return -1; 
} */
int busquedaExponencial(int arr[], int n, int x)
{
    // If x is present at firt location itself
    if (arr[0] == x)
        return 0;
 
    // Find range for binary search by
    // repeated doubling
    int i = 1;
    while (i < n && arr[i] <= x)
        i = i*2;
    int l = i/2, r = MIN(i, n);
    while (l <= r) { 
        int m = l + (r - l) / 2; 
  
        // Check if x is present at mid 
        if (arr[m] == x) 
            return m; 
  
        // If x greater, ignore left half 
        if (arr[m] < x) 
            l = m + 1; 
  
        // If x is smaller, ignore right half 
        else
            r = m - 1; 
    }
    return -1;
    //  Call binary search for the found range.
    //return busquedaBinaria(arr, i/2, MIN(i, n), x);
}