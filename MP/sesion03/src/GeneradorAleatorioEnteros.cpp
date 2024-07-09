/***************************************************************************/
// Clase: GeneradorAleatorioEnteros
/*
	Sirve para generar n�meros aleatorios enteros en un rango de valores.
	
	Hay crear un objeto de esta clase. Se dispone de dos constructores: 
	1) GeneradorAleatorioEnteros()
	   		El primero no tiene par�metros y establece que �nicamente se 
			van a generar ceros y unos (este constructor llama al segundo). 
	2) GeneradorAleatorioEnteros(int min, int max)
		El segundo tiene dos par�metros, "min" y "max" que delimitan el 
		rango correspondiente. 

	Finalmente, el m�todo 
	
		int Siguiente()
	
	devolver� un valor aleatorio en el rango especificado en el constructor.
*/
/***************************************************************************/

#include "GeneradorAleatorioEnteros.h"
using namespace std;

/////////////////////////////////////////////////////////////////////////////
/************************************************************************/
		
	GeneradorAleatorioEnteros::GeneradorAleatorioEnteros() : GeneradorAleatorioEnteros(0, 1) { }
	
	/************************************************************************/  
	GeneradorAleatorioEnteros::GeneradorAleatorioEnteros(int min, int max) {
	
		const int A_DESCARTAR = 70000;
		// ACM TOMS Volume 32 Issue 1, March 2006
		auto semilla = Nanosec();
		generador_mersenne.seed(semilla);
		generador_mersenne.discard(A_DESCARTAR);
		distribucion_uniforme = uniform_int_distribution<int> (min, max);
	}
	
	/************************************************************************/
	
	int GeneradorAleatorioEnteros:: Siguiente(){
	  return (distribucion_uniforme(generador_mersenne));
	}
	
	/************************************************************************/

	long long GeneradorAleatorioEnteros::Nanosec()
	{
		return chrono::high_resolution_clock::now().time_since_epoch().count();
	}

	/************************************************************************/
/////////////////////////////////////////////////////////////////////////////