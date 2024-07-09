/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// Fichero: Demo-Matriz2D_sesion10.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

#include "TipoBase_Matriz2D.h"
#include "Matriz2D.h"

using namespace std; 

/**********************************************************************/
/**********************************************************************/

int main (void)
{

	Matriz2D m1;	// Constructor sin argumentos

	if (m1.EstaVacia())
		cout << "Matriz m1 esta vacia" << endl;
	else 
		cout << "Matriz m1 NO esta vacia" << endl;
	cout << endl << endl;


	Matriz2D m2(5); // Constructor con un argumento --> matriz cuadrada

	if (m2.EstaVacia())
		cout << "Matriz m2 (5x5) esta vacia" << endl;
	else 
		cout << "Matriz m2 (5x5) NO esta vacia" << endl;
	cout << endl << endl;

	cout << m2.ToString ("m2 (5x5)") << endl;
	cout << endl;

	m2 = 3;

	cout << m2.ToString ("m2 tras m2 = 3") << endl;
	cout << endl;

	
	Matriz2D m7(5,5,7); // Constructor con un argumento --> matriz cuadrada

	if (m2.EstaVacia())
		cout << "Matriz m7 (5x5) esta vacia" << endl;
	else 
		cout << "Matriz m7 (5x5) NO esta vacia" << endl;
	cout << endl << endl;

	cout << m7.ToString ("m7 (5x5)") << endl;
	cout << endl;


	m7 += m2;

	if (m7.EstaVacia())
		cout << "Matriz m7 (5x5) esta vacia" << endl;
	else 
		cout << "Matriz m7 (5x5) NO esta vacia" << endl;
	cout << endl << endl;

	cout << m7.ToString ("m7 tras m7 += m2") << endl;
	cout << endl;

	m7 + 500; //no se modifica m7

	m7 -= 2;

	if (m7.EstaVacia())
		cout << "Matriz m7 (5x5) esta vacia" << endl;
	else 
		cout << "Matriz m7 (5x5) NO esta vacia" << endl;
	cout << endl << endl;

	cout << m7.ToString ("m7 tras m7 -= 2") << endl;
	cout << endl;

	m7 -= Matriz2D(5,5,41);

	if (m7.EstaVacia())
		cout << "Matriz m7 (5x5) esta vacia" << endl;
	else 
		cout << "Matriz m7 (5x5) NO esta vacia" << endl;
	cout << endl << endl;

	cout << m7.ToString ("m7 tras m7 -= Matriz2D(5,5,41)") << endl;
	cout << endl;


	cout << (-m7).ToString ("La opuesta de m7") << endl;
	cout << endl;





	// Modifica los valores de la diagonal

	for (int f=0; f<m2.NumFilas(); f++)
		m2 (f, f) = (TipoBaseMatriz2D) 1;

	cout << m2.ToString ("m2 diagonal a 1") << endl;
	cout << endl;

	Matriz2D m3 (2, 5); // Const. con dos argumentos --> matriz rectangular

	if (m3.EstaVacia())
		cout << "Matriz m3 (2x5) esta vacia" << endl;
	else 
		cout << "Matriz m3 (2x5) NO esta vacia" << endl;
	cout << endl << endl;

	m3 = 33;

	cout << m3.ToString ("m3 (2x5) tras m3 = 33") << endl;
	cout << endl;


	Matriz2D m4 (6, 3, 9); // Constructor con tres argumentos --> matriz 
							 // rectangular inicializada de manera expl�cita

	if (m4.EstaVacia())
		cout << "Matriz m4 (6x3) esta vacia" << endl;
	else 
		cout << "Matriz m4 (6x3) NO esta vacia" << endl;
	cout << endl << endl;

	cout << m4.ToString ("m4 (6x3) creada e inicializada a 9") << endl;
	cout << endl;


    // "m5" se construye como copia de "m4"
   
	Matriz2D m5 (m4);		// Constructor de copia
	
	cout << m5.ToString ("m5 creada como copia de m4") << endl;
	cout << endl;

	m5(1,1) = (TipoBaseMatriz2D) 77;
	m5(3,0) = (TipoBaseMatriz2D) 22;

	cout << m5.ToString ("m5 modificada filas 1 y 3") << endl;
	cout << endl;


	m5.EliminaFila (1);

	cout << m5.ToString ("m5 eliminada fila 1") << endl;
	cout << endl;

	m5.EliminaFila (2);

	cout << m5.ToString ("m5 eliminada fila 2") << endl;
	cout << endl;

	m5(0,1) = (TipoBaseMatriz2D) 111;
	m5(3,1) = (TipoBaseMatriz2D) 222;
	m5(2,0) = (TipoBaseMatriz2D) 333;

	cout << m5.ToString ("m5 modificada columnas 0 y 1") << endl;
	cout << endl;


	m5.EliminaColumna (1);

	cout << m5.ToString ("m5 eliminada columna 1") << endl;
	cout << endl;

	m5.EliminaColumna (0);

	cout << m5.ToString ("m5 eliminada columna 0") << endl;
	cout << endl;

	/***********************************************************/

	return (0);
}

/**********************************************************************/
/**********************************************************************/
