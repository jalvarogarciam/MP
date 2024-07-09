/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// Declaración de la clase GeneradorAleatorioEnteros
//
// Fichero: GeneradorAleatorioEnteros.h
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

#ifndef GENERADORALEATORIOENTEROS
#define GENERADORALEATORIOENTEROS

#include<cstdlib>
#include<cctype>

#include <random>  
#include <chrono>  

using namespace std;

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class GeneradorAleatorioEnteros
{  
private:
	
   mt19937 generador_mersenne;    // Mersenne twister
   uniform_int_distribution<int>  distribucion_uniforme;
   
public:
	
	/************************************************************************/	
	// Constructor sin argumentos: 
	// Inicializa el generador para proporcionar nums. aleatorios entre 0 y 1

	GeneradorAleatorioEnteros();
   
  	/************************************************************************/  
	// Constructor con argumentos: 
	// Inicializa el generador para proporcionar nums. aleatorios entre "min" 
	// y "max"
	
	GeneradorAleatorioEnteros(int min, int max);
   
	/************************************************************************/
	// Devuelve un nuevo número aleatorio

	int Siguiente();

	/************************************************************************/

private: 

    /************************************************************************/
	// Métodos privados de la clase
    /************************************************************************/

	long long Nanosec();

   /************************************************************************/ 

};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

#endif