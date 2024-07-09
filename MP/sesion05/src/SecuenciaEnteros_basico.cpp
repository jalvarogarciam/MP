/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// Fichero: SecuenciaEnteros_basico.cpp
//
/***************************************************************************/
#include "SecuenciaEnteros_basico.h"
#include <cstring>
using namespace std;


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

/***********************************************************************/
// Constructor sin argumentos

SecuenciaEnteros::SecuenciaEnteros (void) : total_utilizados (0)
{}


/***********************************************************************/
// Construye una secuencia con "n_datos" valores
// PRE: 0 <= n_datos <= TAMANIO
// PRE: A partir de "p" hay "n_datos" valores

SecuenciaEnteros:: SecuenciaEnteros (int * p, int n_datos){
    total_utilizados = 0;

    for (int i=0; i<n_datos; i++)
        Aniade(*(p+i));
}

/***********************************************************************/
// Construye una secuencia con "n_datos" valores iguales
// PRE: 0 <= n_datos <= TAMANIO
SecuenciaEnteros:: SecuenciaEnteros (int n_datos, int valor){
    total_utilizados = 0;

    for (int i=0; i<n_datos; i++)
        Aniade(valor);
}

/***********************************************************************/
// Construye una secuencia con "n_datos" valores aleatorios
// PRE: 0 <= n_datos <= TAMANIO
SecuenciaEnteros:: SecuenciaEnteros (int n_datos, int min_aleat, int max_aleat){
    total_utilizados = 0;

    GeneradorAleatorioEnteros generador(min_aleat, max_aleat);

    for (int i=0; i<n_datos; i++)
        Aniade(generador.Siguiente());

}

/***********************************************************************/
// Devuelve el número de casillas ocupadas

int SecuenciaEnteros:: TotalUtilizados (void)
{
    return (total_utilizados);
}

/***********************************************************************/
// Devuelve el número de casillas disponibles

int SecuenciaEnteros:: Capacidad (void)
{
    return (TAMANIO);
}

/***********************************************************************/
// Añade un elemento ("nuevo") al vector.
// PRE: total_utilizados < TAMANIO
// 		La adición se realiza si hay alguna casilla disponible.
// 		El nuevo elemento se coloca al final del vector.
// 		Si no hay espacio, no se hace nada.

void SecuenciaEnteros:: Aniade (int nuevo)
{
    if (total_utilizados < TAMANIO){
        vector_privado[total_utilizados] = nuevo;
        total_utilizados++;
    }
}

/***********************************************************************/
// Inserta un entero en la posición "indice"
// PRE: 0 <= indice <= total_utilizados

void SecuenciaEnteros::Inserta(int indice, int nuevo){
    
    if (total_utilizados < TAMANIO){    //comprueba que no se desborde

        memmove(vector_privado+indice+1, vector_privado+indice, \
                (total_utilizados-indice)*sizeof(int));

        *(vector_privado+indice)=nuevo;

        total_utilizados++;
    }
}

/***********************************************************************/
// Devuelve el elemento de la casilla "indice"
// PRE: 0 <= indice < total_utilizados

int SecuenciaEnteros:: Elemento (int indice)
{
    return (vector_privado[indice]);
}

/***********************************************************************/
// Modifica el valor de la casilla "indice"
// PRE: 0 <= indice < total_utilizados
void SecuenciaEnteros:: Modifica (int nuevo, int indice){
    *(vector_privado+indice) = nuevo;
}

/***********************************************************************/
// Devuelve una ref. al elemento de la casilla "indice"
// PRE: 0 <= indice < total_utilizados
int & SecuenciaEnteros:: Valor (int indice){
    return (*(vector_privado+indice));
}

/***********************************************************************/
// Eliminar el carácter de la posición dada por "indice".
// Realiza un borrado físico (desplazamiento y sustitución).
// PRE: 0 <= indice < total_utilizados

void SecuenciaEnteros:: Elimina (int indice)
{   memmove(vector_privado+indice, vector_privado+indice+1, \
            (total_utilizados-indice-1)*sizeof(int));
    total_utilizados--;
}
 
/***********************************************************************/
// Compone un string con todos los valores que están
// almacenados en la secuencia y lo devuelve.

string SecuenciaEnteros :: ToString()
{
    string cadena = "{";

	if (total_utilizados > 0) {

        for (int i=0; i<total_utilizados-1; i++)
        	cadena = cadena + to_string(vector_privado[i])+", ";

			// Añadie el último seguido de '}'
        cadena = cadena + to_string(vector_privado[total_utilizados-1]);
	}

    cadena = cadena + "}";

    return (cadena);
}

/*******************************************************/
// Devuelve true si la secuencia implícita es igual a "otra"

bool SecuenciaEnteros :: EsIgualA (const SecuenciaEnteros & otra){

    //coprueba que al menos temgan el mismo tamaño
    if (total_utilizados != otra.total_utilizados) 
        return false;
    
    //comprueba que todos los elementos sean iguales
    for (int i=0; i<total_utilizados; i++)
        if (vector_privado[i] != otra.vector_privado[i])
            return false;
    
    return true;
}

/***********************************************************************/

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////