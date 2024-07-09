/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
// 
// Fichero: III_Demo-Corredores.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

#include "Corredor.h"
#include "Corredores.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/

int main()
{
    cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales


	// Cada linea se lee en un dato string. 
	string linea;

	// Terminador para los datos leidos/escritos 
	const string TERMINADOR = "FIN";




	Corredores coleccion_corredores; // Crear colección (vacía)

	getline(cin, linea); // Lectura adelantada

	while (linea != TERMINADOR) {
					
		Corredor un_corredor (linea);

		// Añadir el dato "Corredor" leido a la colección  
		coleccion_corredores.Aniade (un_corredor);

		// Leer la siguiente linea 
		getline(cin, linea); 
		
	} // while (linea != TERMINADOR)

	cout << endl;
	cout << coleccion_corredores.ToString(); 
	cout << endl;

	cout << "Total corredores del circuito = "<<setw(3) 
	     << coleccion_corredores.Usados() << endl; 
	cout << endl; 



	// Prueba del operador =

	Corredores nueva_coleccion; // Crear colección (vacía)

	nueva_coleccion = coleccion_corredores;

	cout << "nueva_coleccion tras asignacion:" << endl; 

	cout << endl;
	cout << coleccion_corredores.ToString(); 
	cout << endl;	



	// Prueba del operador []

	// Crear coleccion con dorsales pares

	Corredores corredores_dorsales_pares; // Crear colección (vacía)


	for (int pos=1; pos <= coleccion_corredores.Usados(); pos++) {

		Corredor un_corredor = coleccion_corredores[pos]; // operator []

		if (un_corredor.GetDorsal()%2 == 0) 
			corredores_dorsales_pares.Aniade(un_corredor);
	}

	cout << "Corredores con dorsales pares:" << endl; 

	cout << endl;
	cout << corredores_dorsales_pares.ToString(); 
	cout << endl;	

	cout << "Total corredores con dorsales pares = "<< setw(3) 
	     << corredores_dorsales_pares.Usados() << endl; 
	cout << endl; 



	for (int pos=1; pos <= corredores_dorsales_pares.Usados(); pos++) {

		Corredor un_corredor = corredores_dorsales_pares[pos]; // operator []

		int el_dorsal = un_corredor.GetDorsal();
		un_corredor.SetDorsal(el_dorsal+2);
 
		corredores_dorsales_pares(pos) = un_corredor; // operator ()
	}

	cout << "Corredores con dorsales pares modificados:" << endl; 

	cout << endl;
	cout << corredores_dorsales_pares.ToString(); 
	cout << endl;	

	cout << "Total corredores con dorsales pares = "<< setw(3) 
	     << corredores_dorsales_pares.Usados() << endl; 
	cout << endl; 

	return 0;
}

/***************************************************************************/
/***************************************************************************/
