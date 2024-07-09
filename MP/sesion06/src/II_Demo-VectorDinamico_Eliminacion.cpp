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
	
	VectorDinamico v = CreaVectorDinamico (TAM_INICIAL); 
	VectorDinamico v_copia = CreaVectorDinamico (TAM_INICIAL); 

	cout << "vector v:" << endl; 
	cout << "vacio = " << boolalpha << EstaVacioVectorDinamico(v) << endl; 
	cout << "casillas usadas    = " << UsadosVectorDinamico(v) << endl; 
	cout << "casillas reservadas= " << CapacidadVectorDinamico(v) << endl; 
	cout << endl;


	// Se han reservado TAM casillas y se est�n usando 0.


	// ......................................................................
	// Leer valores y guardarlos en el vector din�mico. 
	// El redimensionamiento se produce cuanddo no hay espacio para 
	// un nuevo dato. 

	const int TAM_CAD = 20;
	char  valor[TAM_CAD];


	cout << endl; 
	cout << "Introducir valores del vector" << endl; 

	// Primera lectura
	cout << "Introducir un valor (Negativo para finalizar): "; 
	cin.getline (valor, TAM_CAD);


	while (atoi(valor)>=0) {

		// A�adir "valor". Si no cabe se redimensiona 

		AniadeVectorDinamico (v, atoi(valor));

		cout << "vacio = " << boolalpha << EstaVacioVectorDinamico(v) << endl; 
		cout << "casillas usadas    = " << UsadosVectorDinamico(v) << endl; 
		cout << "casillas reservadas= " << CapacidadVectorDinamico(v) << endl; 


		// Nueva lectura
		cout << "Introducir un valor (Negativo para finalizar): "; 
		cin.getline (valor, TAM_CAD);
	}

    ClonaVectorDinamico(v_copia,v);

	// ......................................................................
	// Muestra los vectores

	cout << endl; 
	cout << "----------------------------------------" << endl; 
	cout << endl; 

	cout << endl;
	cout << "vector: " << endl;
	cout << ToString (v);
	cout << endl;


	cout << "----------------------------------------" << endl; 
	cout << endl; 

    // ......................................................................
	// Elimina los elementos repetidos del vector con el algoritmo físico

    EliminaRepetidosVectorDinamico(v_copia,0);
    
    cout << endl;
    cout << "Vector sin elementos repetidos (algoritmo fisico):"<<endl;
	cout << ToString (v_copia);
	cout << endl;

    ClonaVectorDinamico(v_copia,v); //Deshace los cambios

    // ......................................................................
	// Elimina los elementos repetidos del vector con el algoritmo de los 
    // dos apuntadores

    EliminaRepetidosVectorDinamico(v_copia,1);
    
    cout << endl;
    cout << "Vector sin elementos repetidos (algoritmo de los 2 apuntadores):" \
		<<endl;
	cout << ToString (v_copia);
	cout << endl;

    ClonaVectorDinamico(v_copia,v); //Deshace los cambios


	return 0;
}

/***************************************************************************/
/***************************************************************************/
