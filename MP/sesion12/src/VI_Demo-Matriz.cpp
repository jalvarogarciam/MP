/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// JOSÉ ÁLVARO GARCÍA MÁRQUEZ
// 1º Ingenieria Informática (Grupo B1)
//
// Sesión 12
//
// Fichero: NumeraLineas_Ampliacion.cpp
//
//////////////////////////////////////////////////////////////////////////////
/*
10. Ampliar la clase Matriz2D con los siguientes métodos para leer/escribir 
de/a un fichero de texto:

	• Matriz2D (const char * nombre);
	Constructor que recibe el nombre de un fichero de texto y crea una matriz
	y la rellena con los datos contenidos en el fichero de texto nombre.

	• void EscribirMatriz2D (const char * nombre) const;
	Guarda en el fichero de texto nombre el contenido de la matriz. Si el
	fichero ya existiera, se reemplaza su contenido por el de la matriz. La
	matriz no se modifica. Escribe los datos por filas, esto es, cada línea
	de salida contiene los valores de una fila de la matriz delimitados por
	separadores.

	• void LeerMatriz2D (const char * nombre);
	Sustituye el contenido de la matriz por los valores que están en el fichero
	de texto nombre.

Los ficheros de texto válidos tienen el siguiente formato: 
	la primera línea contiene únicamente la palabra MATRIZ2D. 
	Después aparecen las dimensiones y los los valores
	(ver ejercicio 20 de la Relación de Problemas IV).
*/
/***************************************************************************/
/***************************************************************************/

#include "Matriz2D.h"

#include <iostream>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main(int argc, char ** argv) 
{
	// Comprobar numero de argumentos  

	if (argc != 2) {
		cerr << "Error: Numero de argumentos incorrecto." << endl;
		cerr << "Formato: "<< argv[0] <<" <fich_in> "<< endl;
		exit (1);

	}

	Matriz2D m(argv[1]);

	cerr << "Matriz m leida de " << argv[1] << ':' << endl; 
	cerr << "Dimensiones de m = " << m.NumFilas() << " x " 
	     << m.NumColumnas() << endl;
	cerr << m.ToString() << endl; 

	if (m.EstaVacia())
		cerr << "Matriz m esta vacia." << endl;
	else 
		cerr << "Matriz m NO esta vacia." << endl;
	cerr << endl; 

	cerr << "Enviando matriz m a cout" << endl;
	cerr << endl; 

	cerr << "Aniadiendo una fila a la matriz" << endl;

	Secuencia s;
	for (int i = 1; i <= m.NumColumnas(); i++)	s += (33);

	m.Aniade(s);
	
	cerr << s.ToString("nueva fila:");

	cerr << endl; 

	cerr << "Enviando m a cout: "<< endl;
	cout << m << endl;	

	cerr << endl; 

	cerr << "Actualizando los datos de m en el fichero: "<< argv[1] << endl;

	if (m.EscribirMatriz2D(argv[1])) cerr<<"actualizados"<< endl;
	else cerr << "algo ha fallado" << endl;

	
	

	return 0;
}

/***************************************************************************/
/***************************************************************************/
