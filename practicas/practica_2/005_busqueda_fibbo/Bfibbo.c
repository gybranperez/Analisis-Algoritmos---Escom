#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"
#define MIN(a,b) (((a)<(b))?(a):(b))

int fibMonaccianSearch(int arr[], int x, int n) ;

int main(int argc, char* argv[]){
    int n, *p, result, i;
    int datos[20] = {322486, 14700764, 3128036, 6337399, 61396,
	10393545, 2147445644, 1295390003, 450057883, 187645041,
	1980098116, 152503, 5000, 1493283650, 214826, 1843349527,
	1360839354, 2109248666 , 2147470852, 0};
    double utime0, stime0, wtime0, utime1, stime1, wtime1;

    if (argc!=2) {
		printf("\nIndique el número a buscar - Ejemplo: [user@equipo]$ %s 40000 500000\n",argv[0]);
		exit(1);
	} 
    
	n=atoi(argv[1]);

    p=malloc(n*sizeof(int));
    if(p==NULL) exit(1);
    
    uswtime(&utime0, &stime0, &wtime0);
    for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}

    for  (i = 0; i < 20; i++)
    {
        result = fibMonaccianSearch(p, datos[i], n);
        (result == -1) ? printf("Element is not present"
                            " in array\n") 
                   : printf("Element is present at "
                            "index %d\n", 
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

int fibMonaccianSearch(int arr[], int x, int n) 
{ 
    /* Initialize fibonacci numbers */
    int fibMMm2 = 0;   // (m-2)'th Fibonacci No. 
    int fibMMm1 = 1;   // (m-1)'th Fibonacci No. 
    int fibM = fibMMm2 + fibMMm1;  // m'th Fibonacci 
  
    /* fibM is going to store the smallest Fibonacci 
       Number greater than or equal to n */
    while (fibM < n) 
    { 
        fibMMm2 = fibMMm1; 
        fibMMm1 = fibM; 
        fibM  = fibMMm2 + fibMMm1; 
    } 
  
    // Marks the eliminated range from front 
    int offset = -1; 
  
    /* while there are elements to be inspected. Note that 
       we compare arr[fibMm2] with x. When fibM becomes 1, 
       fibMm2 becomes 0 */
    while (fibM > 1) 
    { 
        // Check if fibMm2 is a valid location 
        int i = MIN(offset+fibMMm2, n-1); 
  
        /* If x is greater than the value at index fibMm2, 
           cut the subarray array from offset to i */
        if (arr[i] < x) 
        { 
            fibM  = fibMMm1; 
            fibMMm1 = fibMMm2; 
            fibMMm2 = fibM - fibMMm1; 
            offset = i; 
        } 
  
        /* If x is greater than the value at index fibMm2, 
           cut the subarray after i+1  */
        else if (arr[i] > x) 
        { 
            fibM  = fibMMm2; 
            fibMMm1 = fibMMm1 - fibMMm2; 
            fibMMm2 = fibM - fibMMm1; 
        } 
  
        /* element found. return index */
        else return i; 
    } 
  
    /* comparing the last element with x */
    if(fibMMm1 && arr[offset+1]==x)return offset+1; 
  
    /*element not found. return -1 */
    return -1; 
} 