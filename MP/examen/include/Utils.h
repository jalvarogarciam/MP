/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// JOSÉ ÁLVARO GARCÍA MÁRQUEZ
// 1º Ingenieria Informática (Grupo B1)
//
// Proyecto Fase 4
//
// Fichero: Utils.h
//
//////////////////////////////////////////////////////////////////////////////
/*
Modulo de funciones utiles para otras partes del proyecto.
*/
/***************************************************************************/
/***************************************************************************/

#ifndef UTILS
#define UTILS


#include <iomanip>
#include <cstring>
#include <fstream>
#include <sstream>


using namespace std;



/****************************************************************************/
/*Comprueba que el fichero al cual esta asociado el flujo proporcionado
como argumento, es correcto (la palabra magica coincide con el string "palabra"
proporcionado como argumento) y omite los comentarios, dejando
el flujo preparado para proporcionar solo los datos.

Devuelve true si el fichero es correcto
*/
bool prepara_flujo_datos(istream & in, string palabra);

/****************************************************************************/
/*Envia la palabra magica proporcionada como argumento (palabra), al flujo out,
Además de la fecha y hora actuales en un comentario
*/
void cabecera_ficheros(ostream & out, string palabra);

/****************************************************************************/
/* Apartir de un string que representa el nombre de un fichero desde 
cierto directorio a un fichero (con su respectiva ruta), extrae devuelve dicha
ruta.   ej: titulo= "./proyecto/datos/circuito.cfg" --> "./proyecto/datos"
*/
string Extrae_Ruta (const string & titulo);

#endif