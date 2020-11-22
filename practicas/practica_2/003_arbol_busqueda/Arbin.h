
//*****************************************************************
//	AUTORES:
// 	Pérez Sereno Ricardo Erick
//	Pérez Juarez Carlos Gybrán
// 	Ramirez Flores Juan
// ****************************************************************
//	Practica 2: Análisis temporal y notación de orden (Algoritmos de búsqueda)
//	***************************************************************

//	***************************************************************
//			Librerias
//	***************************************************************

#include "stdlib.h"

//Defimos la estructura de un arbol binario
//Consiste en una raiz, un nodo izquierdo y un bodo derecho
typedef struct NodoA 
{
	struct NodoA *izq;
	struct NodoA *der;
	int raiz;
} NodoA;

typedef NodoA *posicion;	// La posición será la dirección hacia un NodoA específico
typedef posicion Arbin; // El árbol binario será simplemente una posición de un NodoA

//	***************************************************************
//						consA
//	***************************************************************
//	Descripción: Construye un arbol binario
//	Recibe: Un apuntador al arbol binario
//	Devuelve: 
//	***************************************************************
void consA(Arbin *a)
{
	*a = NULL; // El apuntador enviado por el usuario se coloca en un valor NULL
}

//	***************************************************************
//						destruir
//	***************************************************************
//	Descripción: Elimina de la memoria un arbol binario
//	Recibe: Un apuntador al arbol binario
//	Devuelve: 
//	***************************************************************
void destruir(Arbin *a)
{
	if (*a != NULL) // Veirficamos no estar apuntando a un valor nulo en el árbol enviado
	{
		if ((*a) -> izq != NULL)		// Verificamos si el árbol izquierdo existe, para eliminarlo primero
			destruir(&((*a) -> izq));	// Llamamos recursivamente la función por el lado izquierdo
		if ((*a) -> der != NULL)		// Posteriormente eliminamos el lado derecho del árbol verificando que existe
			destruir(&((*a) -> der)); // Llamamos recursivamente la función por el lado derecho
		free(*a);									// Liberamos el nodo una vez que ya no tiene hijos
	}
}