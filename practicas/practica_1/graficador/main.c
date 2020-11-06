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
#include <math.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//*****************************************************************
void Burbuja(long p[],long n);
void BurbujaOptimizada(long p[],long n);
void insercion(long p[],long n);
void Seleccion(long A[], long n);
void shell(long A[],long n);

void guardarMediciones(char name_csv [], long n,double utime0, double stime0, double wtime0, double utime1, double stime1, double wtime1);


//*****************************************************************
//PROGRAMA PRINCIPAL 
//*****************************************************************
int main (int argc, char* argv[])
{	
	//******************************************************************	
	//Variables del main
	//******************************************************************	
	long n; 	//n determina el tamaño del algorito dado por argumento al ejecutar
    long m;  //m determina el id de la función a ejecutarse
	long i;
	long *p; //Variables para loops

	//******************************************************************	
	//Recepción y decodificación de argumentos
	//******************************************************************	

	//Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)
	if (argc!=3) 
	{
		printf("\nIndique tamanio del algoritmo e id de algoritmo - Ejemplo: [user@equipo]$ %s 100 1\n",argv[0]);
        printf("id algoritmos:\n1.- Burbuja\n2.- Burbuja optimizada\n3. Insercion\n4. Seleccion\n5. shell\n6. Arbol binario\n");
		exit(1);
	} 
	//Tomar el segundo argumento como tamaño del algoritmo
	
    n=atol(argv[1]);
    m=atol(argv[2]);
	
    
    if (m<0 && m>6)
    {
        printf("\nIds algoritmos:\n1.- Burbuja\n2.- Burbuja optimizada\n3. Insercion\n4. Seleccion\n5. shell\n6. Arbol binario\n");
        exit(1);
    }
    
	p=malloc(n*sizeof(long));

	if(p==NULL)
		exit(1);

	for(i=0;i<n;i++)
	{
		scanf("%ld",&p[i]);
	}
	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	//******************************************************************
	
	//******************************************************************	
	//Algoritmo
	//******************************************************************	
    switch (m)
    {
        case 1:
            Burbuja(p,n);
            break;
    
        case 2:
            BurbujaOptimizada(p,n);
            break;

        case 3:
            insercion(p,n);
            break;
    
        case 4:
            Seleccion(p, n);
            break;
        
        case 5:
            shell(p,n);
            break;
    
        case 6:
            break;
    }
	
	/*for(i=0;i<n;i++)
	{
		printf("%ld\n",p[i]);
	}*/

	//******************************************************************

	//******************************************************************	
	//Evaluar los tiempos de ejecución 
	//******************************************************************
	
	//Terminar programa normalmente	
	free(p);
	return 0;	
}

//************************************************************************
//DEFINICIÓN DE FUNCIONES 
//************************************************************************
void Burbuja(long p[],long n)
{
    double utime0, stime0, wtime0, utime1, stime1, wtime1; //Variables para medición de tiempos
    char name_csv[] = "burbuja.csv"; 
    int csv;

	int i, j, aux;
		uswtime(&utime0, &stime0, &wtime0);
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

    guardarMediciones(name_csv, n,utime0, stime0, wtime0, utime1, stime1, wtime1); 
	//printf("\n");
	//printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	//printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	//printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	//printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
    //printf("\n");
    
}

void BurbujaOptimizada(long p[],long n)
{
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	//bool cambios=true;
    char name_csv[] = "burbujaOpt.csv";
	int i=0,j,aux,cambios=1;
		
        uswtime(&utime0, &stime0, &wtime0);
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

	//	printf("\n");
    guardarMediciones(name_csv, n, utime0, stime0, wtime0, utime1, stime1, wtime1); 
	//printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	//printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	//printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	//printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	//printf("\n");

		/*for(i=0;i<n;i++)
		{
			printf("%d\n",p[i]);
		}*/

}

void insercion(long p[], long n)
{
	//Variables para medición de tiempos
	double utime0, stime0, wtime0,utime1, stime1, wtime1;
    char name_csv[] = "insercion.csv";
	uswtime(&utime0, &stime0, &wtime0);

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
    guardarMediciones(name_csv, n, utime0, stime0, wtime0, utime1, stime1, wtime1); 
	//		printf("Insercion\n");
	//printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	//printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	//printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	//printf("CPU/Wall   %.10e %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	//printf("\n");
/*
		for(i=0;i<n;i++)
		{
			printf("%d\n",p[i]);
		}
		*/
}

void Seleccion(long A[], long n)
{
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	int i,j,k,p,temp;
    char name_csv[] = "seleccion.csv";

	uswtime(&utime0, &stime0, &wtime0);
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

    guardarMediciones(name_csv, n, utime0, stime0, wtime0, utime1, stime1, wtime1); 
     
	//printf("Seleccion\n");
	//printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	//printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	//printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	//printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	//printf("\n");

    
/*
		for(i=0;i<n;i++)
		{
			printf("%d\n",A[i]);
		}
*/		
}

void shell(long A[],long n)
{
    double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	int k=trunc(n/2);
	int b=0,i=0,temp=0;
    char name_csv[] = "shell.csv";

    uswtime(&utime0, &stime0, &wtime0);
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
    guardarMediciones(name_csv, n,utime0, stime0, wtime0, utime1, stime1, wtime1); 

		/*for(i=0;i<n;i++)
		{
			printf("%d\n",A[i]);
		}*/

}


void guardarMediciones(char name_csv [], long n,double utime0, double stime0, double wtime0, double utime1, double stime1, double wtime1)
{
    int csv;
    char buf[60];
    char cab_csv[] = "n,real,user,sys,CPU/Wall\n"; 	//cabecera para el archivo csv

    csv = open(name_csv, O_WRONLY, S_IROTH | S_IWOTH | S_IRUSR | S_IWUSR);  //abre un archivo csv para escribirlo
    if(csv == -1)
    {
		//printf("no existe el archivo");
        csv = open(name_csv, O_WRONLY | O_CREAT , S_IROTH | S_IWOTH | S_IRUSR | S_IWUSR);   //si el archivo no existe, crea uno con una nueva cabecera
        if (csv == -1)
        {
            printf("Error al crear el archivo");
            exit(1);
        }
        write(csv, cab_csv, strlen(cab_csv));	//Escribe la cabecera para el archivo csv
    }
	lseek(csv,0,SEEK_END);			//apunta al final del archivo

    sprintf(buf, "%ld,%.10f,%.10f,%.10f,%.10f\n", n,wtime1 - wtime0, utime1 - utime0, stime1 - stime0, (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0)); //ajusta los datos en el formato csv
    write(csv, buf, strlen(buf));	//escribe dentro del archivo
    close(csv);						//cierra el archivo

}