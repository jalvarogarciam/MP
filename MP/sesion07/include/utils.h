/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// 1º GRADO EN INGENIERÍA INFORMÁTICA, GRUPO B1
//
// JOSÉ ÁLVARO GARCÍA MÁRQUEZ
//
// Fichero de cabecera asociado a las funciones de utilidad para la gestión de
// matrices dinámicas de tipo TipoBase.
//
// Fichero: utils.h
//
/***************************************************************************/

#ifndef UTILS
#define UTILS

#include "TipoBase.h"

using namespace std;

/*****************************************************************************/
/*Intercambia los valores de dos punteros a punteros a objetos de tipo T.
*/
void swp( T ** & uno, T  ** & otro);

/*****************************************************************************/
/*Intercambia los valores de dos punteros a objetos de tipo T.
*/
void swp( T * & uno, T * & otro);
/*****************************************************************************/

/*****************************************************************************/
/*Intercambia los valores de dos objetos de tipo T.
*/
void swp( T & uno, T & otro);
/*****************************************************************************/


#endif