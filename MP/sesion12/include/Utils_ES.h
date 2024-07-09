/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// JOSÉ ÁLVARO GARCÍA MÁRQUEZ
// 1º Ingenieria Informática (Grupo B1)
//
// Sesión 12
//
// Fichero: Utils_ES.cpp
//
//////////////////////////////////////////////////////////////////////////////
/*
Modulo de funciones utiles para el manejo de flujos de entrada/salida
*/
/***************************************************************************/
/***************************************************************************/

#include <sstream>
#include <fstream>


using namespace std;

/***************************************************************************/
/* Extrae todos los caracteres del flujo de entrada "in" y los manda al flujo
de salida "out". Engloba a todos los tipos de flujo derivados de la clase
iostream (por herencia).

Si "numerado" es true, numerara cada linea del flujo in enviada a cout.
Por defecto numerado = false
*/
ostream & in_out (istream & in, ostream & out, bool numerado = false);
/***************************************************************************/

/***************************************************************************/
/* Comprueba la  existencia y disponibilidad de un fichero
*/
bool ExisteFichero (const string & nombre);
/***************************************************************************/

