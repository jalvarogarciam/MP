/***************************************************************************/
/***************************************************************************/
// METODOLOG�A DE LA PROGRAMACI�N
// 
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS 1
//
// Fichero: I_DemoSecuenciaEnteros.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>

#include "SecuenciaEnteros_basico.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	// Rellenar un vector 

	const int TAM = 100;

	int v[TAM] = {6, -7, 1, -1, -6, -9, 1, 5, 8, 6, -4, -6, 9, 6, 4};
	int util_v = 15; // N�mero de casillas �tiles 
	
	cout << endl; 
	cout <<"Vector con 15 casillas: ";
	
	for (int i=0; i<util_v; i++) 
		cout <<setw(4)<< v[i];
	cout << endl << endl;


	/***********************************************************************/
	// Constructor a partir de un vector (o parte de �l)

	cout << "------------------------------------------------------" << endl;
	cout << "PRUEBAS DE CONSTRUCTORES" << endl;
	cout << endl; 
	
	SecuenciaEnteros sec1 (v, 10);

	cout << "Secuencia desde 0 con tamanio 10:" << endl; 
	cout << sec1.ToString() << endl; 
	cout << "Num. casilas = " << setw(3) << sec1.TotalUtilizados() << endl; 	
	cout << endl; 


	SecuenciaEnteros sec2 (v+10, 5);

	cout << "Secuencia desde 10 con tamanio 5:" << endl; 
	cout << sec2.ToString() << endl; 
	cout << "Num. casilas = " << setw(3) << sec2.TotalUtilizados() << endl; 	
	cout << endl; 
	
	/***********************************************************************/
	// Constructor que inicia todas las casillas al mismo valor

	SecuenciaEnteros sec3 (15);

	cout << "Secuencia de 15 casillas a 0 -por defecto-:" << endl; 
	cout << sec3.ToString() << endl; 
	cout << "Num. casilas = " << setw(3) << sec3.TotalUtilizados() << endl; 	
	cout << endl; 


	SecuenciaEnteros sec4 (20, 5);

	cout << "Secuencia de 20 casillas a 5:" << endl; 
	cout << sec4.ToString() << endl; 
	cout << "Num. casilas = " << setw(3) << sec4.TotalUtilizados() << endl; 
	cout << endl; 

	/***********************************************************************/
	// Constructor de una secuencia con "n_datos" valores aleatorios 

	SecuenciaEnteros sec5 (10, -10, 10);

	cout << "Secuencia de 10 casillas con aleat entre -10 y 10:" << endl; 
	cout << sec5.ToString() << endl; 
	cout << endl; 


	/***********************************************************************/
	// M�todo Elimina

	cout << "------------------------------------------------------" << endl;
	cout << "PRUEBAS DE Elimina()" << endl;
	cout << endl; 


	cout << "Secuencia inicial:" << endl; 
	cout << sec5.ToString() << endl; 
	cout << "Num. casilas = " << setw(3) << sec5.TotalUtilizados() << endl; 
	cout << endl; 



	sec5.Elimina (1);

	cout << "Se elimina la casilla 1:" << endl; 
	cout << sec5.ToString() << endl; 
	cout << "Num. casilas = " << setw(3) << sec5.TotalUtilizados() << endl; 
	cout << endl; 

	sec5.Elimina (3);

	cout << "Se elimina la casilla 3:" << endl; 
	cout << sec5.ToString() << endl; 
	cout << "Num. casilas = " << setw(3) << sec5.TotalUtilizados() << endl; 
	cout << endl; 

	sec5.Elimina (5);

	cout << "Se elimina la casilla 5:" << endl; 
	cout << sec5.ToString() << endl;
	cout << "Num. casilas = " << setw(3) << sec5.TotalUtilizados() << endl; 
	cout << endl;  


	// Borrado total. En cada iteraci�n se borra el primer elemento

	cout << "Borrando casilla a casilla (la primera):" << endl; 

	for (int n=sec5.TotalUtilizados(); n>0; n--) {

		sec5.Elimina (0);

		cout << sec5.ToString() << " --> " 
		     << sec5.TotalUtilizados() << " casillas " << endl; 
	}
	cout << endl; 


	/***********************************************************************/
	// M�todo Valor

	cout << "------------------------------------------------------" << endl;
	cout << "PRUEBAS DE Valor()" << endl;
	cout << endl; 

	cout << "Secuencia inicial: " << endl; 
	cout << sec2.ToString() << endl; 
	cout << "Num. casilas = " << setw(3) << sec2.TotalUtilizados() << endl; 
	cout << endl; 
	
	cout << "Se muestra elemento a elemento (acceso para lectura):" << endl; 

	for (int pos=0; pos<sec2.TotalUtilizados(); pos++) {
		cout << "Casilla " << setw(2) << pos  << ": " 
		     << sec2.Valor(pos) << endl; 
	}
	
	// Modificamos TODOS los elementos

	for (int pos=0; pos<sec2.TotalUtilizados(); pos++) {
		sec2.Valor(pos) = -sec2.Valor(pos); 
	}

	cout << endl; 
	cout << "Modificada elemento a elemento (acceso para escritura): " << endl; 
	cout << sec2.ToString() << endl; 
	cout << "Num. casilas = " << setw(3) << sec2.TotalUtilizados() << endl; 
	cout << endl; 


	/***********************************************************************/
	// M�todo Inserta

	cout << "------------------------------------------------------" << endl;
	cout << "PRUEBAS DE Inserta()" << endl;
	cout << endl; 


	SecuenciaEnteros sec6 (5);

	cout << "Secuencia de 5 casillas a 0 -defecto-:" << endl; 
	cout << sec6.ToString() << endl; 
	cout << "Num. casilas = " << setw(3) << sec6.TotalUtilizados() << endl; 
	cout << endl; 

	sec6.Valor(0) = sec6.Valor(sec6.TotalUtilizados()-1) = -1; 

	cout << "Se ha marcado el inicio y el fin con -1:" << endl; 
	cout << sec6.ToString() << endl; 
	cout << "Num. casilas = " << setw(3) << sec6.TotalUtilizados() << endl; 
	cout << endl; 

	sec6.Inserta (0, 7);

	cout << "Se ha insertado 7 en pos. 0:" << endl; 
	cout << sec6.ToString() << endl; 
	cout << "Num. casilas = " << setw(3) << sec6.TotalUtilizados() << endl; 
	cout << endl; 

	sec6.Inserta (0, 9);

	cout << "Se ha insertado 9 en pos. 0:" << endl; 
	cout << sec6.ToString() << endl; 
	cout << "Num. casilas = " << setw(3) << sec6.TotalUtilizados() << endl; 
	cout << endl; 

	sec6.Inserta (1, 8);

	cout << "Se ha insertado 8 en pos. 1:" << endl; 
	cout << sec6.ToString() << endl; 
	cout << "Num. casilas = " << setw(3) << sec6.TotalUtilizados() << endl; 
	cout << endl; 


	/***********************************************************************/
	// M�todo EsIgualA

	cout << "------------------------------------------------------" << endl;
	cout << "PRUEBAS DE EsIgualA()" << endl;
	cout << endl; 

	SecuenciaEnteros sec7 (10, 0, 20);

	SecuenciaEnteros sec8 = sec7; // OPERADOR = (COPIA -SUPERFICIAL-)

	cout << "Secuencia de 10 casillas con aleat entre 0 y 20:" << endl; 
	cout << sec7.ToString() << endl; 
	cout << "Num. casilas = " << setw(3) << sec7.TotalUtilizados() << endl; 
	cout << endl; 

	cout << "Secuencia copia de la anterior:" << endl; 
	cout << sec8.ToString() << endl; 
	cout << "Num. casilas = " << setw(3) << sec8.TotalUtilizados() << endl; 
	cout << endl; 

	if (sec7.EsIgualA(sec8)) 
		cout << "COMPARACION ---> Son iguales";
	else 
		cout << "COMPARACION ---> No son iguales";
	cout << endl; 

	sec8.Valor(3) *= -1; // Modificamos un valor de "sec8"
	
	cout << endl; 
	cout << "Se ha modificado la casilla 3:" << endl; 
	cout << sec8.ToString() << endl;
	cout << "Num. casilas = " << setw(3) << sec8.TotalUtilizados() << endl; 
 	cout << endl; 

	if (sec7.EsIgualA(sec8)) 
		cout << "COMPARACION ---> Son iguales";
	else 
		cout << "COMPARACION ---> No son iguales";
	cout << endl; 

	cout << "------------------------------------------------------" << endl;
	cout << endl; 

	/***********************************************************************/

	return 0;
}

/***************************************************************************/
/***************************************************************************/