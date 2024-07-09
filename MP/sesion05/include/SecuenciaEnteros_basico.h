/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// Declaración de la clase SecuenciaEnteros. Archivo de cabecera
//
// Fichero: SecuenciaEnteros_basico.cpp
//
/***************************************************************************/
#ifndef SECUENCIAENTEROS_BASICO
#define SECUENCIAENTEROS_BASICO

#include <iostream>
#include <string>

#include "GeneradorAleatorioEnteros.h"

using namespace std;


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class SecuenciaEnteros
{
private:

    static const int TAMANIO = 100; // Núm.casillas disponibles
    int vector_privado[TAMANIO];

    // PRE: 0 <= total_utilizados <= TAMANIO

    int total_utilizados; // Núm.casillas ocupadas

public:

    /***********************************************************************/
    // Constructor sin argumentos

    SecuenciaEnteros (void);

    /***********************************************************************/
    // Construye una secuencia con "n_datos" valores
    // PRE: 0 <= n_datos <= TAMANIO
    // PRE: A partir de "p" hay "n_datos" valores
    SecuenciaEnteros (int * p, int n_datos);

    /*******************************************************/
    // Construye una secuencia con "n_datos" valores iguales
    // PRE: 0 <= n_datos <= TAMANIO
    SecuenciaEnteros (int n_datos, int valor=0);

    /*******************************************************/
    // Construye una secuencia con "n_datos" valores aleatorios
    // PRE: 0 <= n_datos <= TAMANIO
    SecuenciaEnteros (int n_datos, int min_aleat, int max_aleat);


    /***********************************************************************/
    // Devuelve el número de casillas ocupadas

    int TotalUtilizados (void);
    

    /***********************************************************************/
    // Devuelve el número de casillas disponibles

    int Capacidad (void);

    /***********************************************************************/
    // Añade un elemento ("nuevo") al vector.
    // PRE: total_utilizados < TAMANIO
    // 		La adición se realiza si hay alguna casilla disponible.
    // 		El nuevo elemento se coloca al final del vector.
    // 		Si no hay espacio, no se hace nada.

    void Aniade (int nuevo);

    /***********************************************************************/
    // Inserta un entero en la posición "indice"
    // PRE: 0 <= indice <= total_utilizados
    void Inserta(int indice, int nuevo);

    /***********************************************************************/
    // Devuelve el elemento de la casilla "indice"
    // PRE: 0 <= indice < total_utilizados

    int Elemento (int indice);

    /***********************************************************************/
    // Modifica el valor de la casilla "indice"
    // PRE: 0 <= indice < total_utilizados
    void Modifica (int nuevo, int indice);

    /***********************************************************************/
    // Devuelve una ref. al elemento de la casilla "indice"
    // PRE: 0 <= indice < total_utilizados
    int & Valor (int indice);


    /***********************************************************************/
    // Eliminar el carácter de la posición dada por "indice".
    // Realiza un borrado físico (desplazamiento y sustitución).
    // PRE: 0 <= indice < total_utilizados

    void Elimina (int indice);
 
    /***********************************************************************/
    // Compone un string con todos los valores que están
    // almacenados en la secuencia y lo devuelve.

    string ToString();

    /*******************************************************/
    // Devuelve true si la secuencia implícita es igual a "otra"

    bool EsIgualA (const SecuenciaEnteros & otra);

	/***********************************************************************/
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/
/***************************************************************************/

#endif