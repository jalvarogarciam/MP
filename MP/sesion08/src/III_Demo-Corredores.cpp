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



	Corredores coleccion_corredores(60); // Crear colección (vacía)
	
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

	return 0;
}

/***************************************************************************/
/***************************************************************************/
