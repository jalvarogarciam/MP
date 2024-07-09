/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 2
//
// Fichero: II_Demo-VectorDinamico.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

#include "FuncsVectorDinamico.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/
typedef int T;
int main (int argc, char ** argv)
{
	// ......................................................................
	// Comprobar validez de argumentos 

	if (argc != 1) {
		exit (1); 
	}

	// ......................................................................
	// Crear los vectores din�micos. 
	
	VectorDinamico v1 = CreaVectorDinamico (TAM_INICIAL); 
	VectorDinamico v2 = CreaVectorDinamico (TAM_INICIAL); 

	cout << "vector v1:" << endl; 
	cout << "vacio = " << boolalpha << EstaVacioVectorDinamico(v1) << endl; 
	cout << "casillas usadas    = " << UsadosVectorDinamico(v1) << endl; 
	cout << "casillas reservadas= " << CapacidadVectorDinamico(v1) << endl; 
	cout << endl;

	cout << "vector v2:" << endl; 
	cout << "vacio = " << boolalpha << EstaVacioVectorDinamico(v2) << endl; 
	cout << "casillas usadas    = " << UsadosVectorDinamico(v2) << endl; 
	cout << "casillas reservadas= " << CapacidadVectorDinamico(v2) << endl; 
	cout << endl;


	// Se han reservado TAM casillas y se est�n usando 0.


	// ......................................................................
	// Leer valores y guardarlos en el vector din�mico. 
	// El redimensionamiento se produce cuanddo no hay espacio para 
	// un nuevo dato. 

	const int TAM_CAD = 20;
	char  valor[TAM_CAD];


	cout << endl; 
	cout << "Introducir valores de v1" << endl; 

	// Primera lectura
	cout << "Introducir un valor (FIN para finalizar): "; 
	cin.getline (valor, TAM_CAD);


	while (strcmp(valor, "FIN")) {

		T el_valor = atoi(valor); 

		// A�adir "valor". Si no cabe se redimensiona 

		AniadeVectorDinamico (v1, el_valor);

		cout << "vacio = " << boolalpha << EstaVacioVectorDinamico(v1) << endl; 
		cout << "casillas usadas    = " << UsadosVectorDinamico(v1) << endl; 
		cout << "casillas reservadas= " << CapacidadVectorDinamico(v1) << endl; 


		// Nueva lectura
		cout << "Introducir un valor (FIN para finalizar): "; 
		cin.getline (valor, TAM_CAD);
	}

	cout << endl; 
	cout << "Introducir valores de v2" << endl; 

	// Primera lectura de v2
	cout << "Introducir un valor (FIN para finalizar): "; 
	cin.getline (valor, TAM_CAD);

	while (strcmp(valor, "FIN")) {

		T el_valor = atoi(valor); 

		// A�adir "valor". Si no cabe se redimensiona 

		AniadeVectorDinamico (v2, el_valor);

		cout << "vacio = " << boolalpha << EstaVacioVectorDinamico(v2) << endl; 
		cout << "casillas usadas    = " << UsadosVectorDinamico(v2) << endl; 
		cout << "casillas reservadas= " << CapacidadVectorDinamico(v2) << endl; 


		// Nueva lectura
		cout << "Introducir un valor (FIN para finalizar): "; 
		cin.getline (valor, TAM_CAD);
	}

	// ......................................................................
	// Muestra los vectores

	cout << endl; 
	cout << "----------------------------------------" << endl; 
	cout << endl; 

	cout << "Originales" << endl;
	cout << endl;


	cout << endl;
	cout << "v1: " << endl;
	cout << ToString (v1);
	cout << endl;

	cout << endl;
	cout << "v2: " << endl;
	cout << ToString (v2);
	cout << endl;


	cout << "----------------------------------------" << endl; 
	cout << endl; 

	// ......................................................................
	// Clonaci�n

	VectorDinamico v1_clonado = CreaVectorDinamico (); 

	cout << endl;
	cout << "v1_clonado RECIEN CREADO: " << endl;
	cout << ToString (v1_clonado);
	cout << endl;

	ClonaVectorDinamico (v1_clonado, v1);

	cout << endl;
	cout << "v1_clonado TRAS CLONACION: " << endl;
	cout << ToString (v1_clonado);
	cout << endl;


	// ......................................................................
	// Ecualizacion de v1_clonado

	EcualizaVectorDinamico (v1_clonado, 22); 

	cout << endl;
	cout << "v1_clonado tras ecualizar a 22: " << endl;
	cout << ToString (v1_clonado);
	cout << endl;

	// ......................................................................
	// Reajuste de v1_clonado

	ReajustaVectorDinamico (v1_clonado); 

	cout << endl;
	cout << "v1_clonado tras reajustar: " << endl;
	cout << ToString (v1_clonado);
	cout << endl;


	// ......................................................................
	// Insercion en v1_clonado

	InsertaVectorDinamico (v1_clonado, 1, 0); 
	InsertaVectorDinamico (v1_clonado, 1, UsadosVectorDinamico(v1_clonado)); 

	cout << endl;
	cout << "v1_clonado tras insertar 1 al principio y al final: " << endl;
	cout << ToString (v1_clonado);
	cout << endl;

	InsertaVectorDinamico (v1_clonado, 1, UsadosVectorDinamico(v1_clonado)/2); 

	cout << endl;
	cout << "v1_clonado tras insertar 1 en medio: " << endl;
	cout << ToString (v1_clonado);
	cout << endl;


	// ......................................................................
	// Eliminar la primera mitad de v1_clonado

	int mitad = UsadosVectorDinamico(v1_clonado)/2; 

	for (int i=1; i<=mitad; i++)
		EliminaVectorDinamico (v1_clonado, 0);

	cout << endl;
	cout << "v1_clonado tras eliminar " << mitad << " casillas:" << endl;
	cout << ToString (v1_clonado);
	cout << endl;


	// ......................................................................
	// Eliminar la �ltima casilla de v1_clonado

	EliminaVectorDinamico (v1_clonado, UsadosVectorDinamico(v1_clonado)-1);

	cout << endl;
	cout << "v1_clonado tras eliminar la ultima casilla:" << endl;
	cout << ToString (v1_clonado);
	cout << endl;


	// ......................................................................
	// Liberar memoria
	
	cout << "Liberando memoria y finalizando" << endl;
	cout << endl;

	DestruyeVectorDinamico (v1);
	DestruyeVectorDinamico (v2);
	DestruyeVectorDinamico (v1_clonado);

	return 0;
}

/***************************************************************************/
/***************************************************************************/
