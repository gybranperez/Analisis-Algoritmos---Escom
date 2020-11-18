#include<stdlib.h>
#include<stdio.h>

typedef struct nodoA
{
	struct nodoA *iz;
	struct nodoA *de;
	int raiz;
} nodoA;

typedef nodoA *pos;
typedef	pos arbol;

void construir(arbol *a)
{
	*a = NULL;
}

void destruir(arbol *a)
{
	if(*a != NULL)
		{
		if((*a)->iz != NULL)
			destruir(&((*a)->iz));
		}
		if((*a)->de != NULL)
		{
		destruir(&((*a)->de));
		}
		free(*a);
}
