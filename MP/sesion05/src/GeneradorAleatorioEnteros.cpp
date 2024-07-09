/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// Definición de la clase GeneradorAleatorioEnteros
//
// Fichero: GeneradorAleatorioEnteros.cpp
//
/*
	Sirve para generar números aleatorios enteros en un rango de valores.
	
	Hay crear un objeto de esta clase. Se dispone de dos constructores: 
	
	1) GeneradorAleatorioEnteros();
	   Se van a generar únicamente valotres binarios (ceros y unos).

	2) GeneradorAleatorioEnteros(int min, int max);
		El segundo tiene dos parámetros, "min" y "max" que delimitan el 
		rango correspondiente. 

	Una vez creado un objeto de la clase, la ejecución sobre él del método 
	
		int Siguiente()
	
	devolverá un valor aleatorio en el rango especificado en el constructor.
*/
/***************************************************************************/
/***************************************************************************/

#include "GeneradorAleatorioEnteros.h"  

using namespace std;

/************************************************************************/	
// Constructor sin argumentos: 
// Inicializa el generador para proporcionar nums. aleatorios entre 0 y 1

GeneradorAleatorioEnteros :: GeneradorAleatorioEnteros()
	:GeneradorAleatorioEnteros(0, 1)
{
}

/************************************************************************/  
// Constructor con argumentos: 
// Inicializa el generador para proporcionar nums. aleatorios entre "min" 
// y "max"

GeneradorAleatorioEnteros :: GeneradorAleatorioEnteros(int min, int max) 
{
	const int A_DESCARTAR = 70000;
	// ACM TOMS Volume 32 Issue 1, March 2006

	auto semilla = Nanosec();
	generador_mersenne.seed(semilla);
	generador_mersenne.discard(A_DESCARTAR);
	distribucion_uniforme = uniform_int_distribution<int> (min, max);
}

/************************************************************************/
// Devuelve un nuevo número aleatorio

int GeneradorAleatorioEnteros :: Siguiente()
{
	return (distribucion_uniforme(generador_mersenne));
}
/************************************************************************/

/************************************************************************/
// MÉTODOS PRIVADOS
/************************************************************************/

long long GeneradorAleatorioEnteros :: Nanosec()
{
  return (chrono::high_resolution_clock::now().
          time_since_epoch().count());
}
/************************************************************************/ 