/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// 1º GRADO EN INGENIERÍA INFORMÁTICA, GRUPO B1
//
// JOSÉ ÁLVARO GARCÍA MÁRQUEZ
//
// Implementación de las funciones de utilidad para la gestión de
// matrices dinámicas de tipo TipoBase.
//
// Fichero: utils.cpp
//
/***************************************************************************/

#include "utils.h"
#include "TipoBase.h"

using namespace std;

/*****************************************************************************/
/*Intercambia los valores de dos punteros a punteros a objetos de tipo T.
*/
void swp( T ** & uno, T  ** & otro)
{
    T ** tmp = uno;
    uno = otro;
    otro = tmp;
}
/*****************************************************************************/

/*****************************************************************************/
/*Intercambia los valores de dos punteros a objetos de tipo T.
*/
void swp( T * & uno, T * & otro)
{
    T * tmp = uno;
    uno = otro;
    otro = tmp;
}
/*****************************************************************************/

/*****************************************************************************/
/*Intercambia los valores de dos objetos de tipo T.
*/
void swp( T & uno, T & otro)
{
    T tmp = uno;
    uno = otro;
    otro = tmp;
}
/*****************************************************************************/
