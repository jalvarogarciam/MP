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

#ifndef GENERADORALEATORIOENTEROS
# define GENERADORALEATORIOENTEROS

#include <random>  // para la generaci�n de n�meros pseudoaleatorios
#include <chrono>  // para la semilla
using namespace std;

class GeneradorAleatorioEnteros
{
private:
		mt19937 generador_mersenne;// Mersenne twister
		uniform_int_distribution<int>  distribucion_uniforme;
	/************************************************************************/
	
	long long Nanosec();
	
	/************************************************************************/ 

public:

	/************************************************************************/
		
	GeneradorAleatorioEnteros();
	
	/************************************************************************/  
	GeneradorAleatorioEnteros(int min, int max);
	
	/************************************************************************/
	
	int Siguiente();
	
	/************************************************************************/
};

#endif