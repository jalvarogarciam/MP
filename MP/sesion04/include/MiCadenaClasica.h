/***************************************************************************/
//Metodología de la Programación
//
//Declaración de Funciones sobre el tratamiento de cadenas de caracteres.
//
//Archivo de cabecera
//
// Fichero: MiCadenaClasica.h
/***************************************************************************/
#ifndef MICADENACLASICA
#define MICADENACLASICA

#include <cctype>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
/*Devuelve la longitud de la cadena "chain", sin contar el caracter nulo final
    const char * chain: cadena de caracteres
Imita el funcionamiento de strlen() de cstring
*/
int chainlen(const char * chain);

///////////////////////////////////////////////////////////////////////////////
/*Elimina el caracter en la posición "index" 
(si existe y no es el caracter terminal) de la cadena "chain"
    char * chain: cadena de caracteres
    unsigned int index: posición del caracter a eliminar
Devuelve true si se eliminó el caracter, false de lo contrario
*/
bool charremove(char * chain, unsigned int index);

///////////////////////////////////////////////////////////////////////////////
/*Elimina el o los caracteres "character" de la cadena "chain"
    char * chain: cadena de caracteres
    char character: caracter a eliminar
Devuelve la cadena modificada
*/
char * chaindelete(char * chain, char character);

///////////////////////////////////////////////////////////////////////////////
/*Añade la cadena "chain_added" al final de la cadena "chain"
    char * chain: cadena de caracteres
    const char * chain_added: cadena de caracteres a añadir
Devuelve la cadena modificada chain
*/
char * chainappend(char * chain, const char * chain_added);

///////////////////////////////////////////////////////////////////////////////
/*Compara las cadenas "chain1" y "chain2". 
    const char * chain1: cadena de caracteres
    const char * chain2: cadena de caracteres
Devuelve:
    0 si son iguales, 
    1 si "chain1" es mayor que "chain2" y
    -1 si "chain1" es menor que "chain2"
Imita el funcionamiento de strcmp() de cstring
*/
int chaincmp(const char * chain1, const char * chain2);

///////////////////////////////////////////////////////////////////////////////
/*Copia la cadena "c_original" en la cadena "c_copia"
El uso del parametro opcional exception hace que se omitan caracteres 
especificados en la copia
    char * c_copia: cadena de caracteres donde se copiará la cadena original
    const char * c_original: cadena de caracteres a copiar
    char exception: caracter a omitir en la copia
Devuelve la cadena modificada c_copia
*/
char * copiar_cadena(char * c_copia, const char * c_original,char exception);

///////////////////////////////////////////////////////////////////////////////
/*Devuelve la subcadena de "origen" que comienza en la posición "p" y 
tiene longitud "l".
    char * resultado: cadena de caracteres donde se copiará la subcadena
    const char * origen: cadena de caracteres original
    int p: posición de inicio de la subcadena
    int l: longitud de la subcadena
Devuelve la cadena modificada resultado
*/
char * extraer_subcadena (char * subcadena, const char * origen, int p, int l);

///////////////////////////////////////////////////////////////////////////////
/*Copia la cadena Origen en la cadena Resultado, eliminando los blancos 
iniciales.
    char * resultado: cadena de caracteres donde se copiará la cadena original
    const char * origen: cadena de caracteres a copiar
Devuelve la cadena modificada resultado
*/
char * eliminar_blancos_iniciales(char * resultado, const char * origen);

///////////////////////////////////////////////////////////////////////////////
/*Copia la cadena Origen en la cadena Resultado, eliminando los blancos finales.
    char * resultado: cadena de caracteres donde se copiará la cadena original
    const char * origen: cadena de caracteres a copiar
Devuelve la cadena modificada resultado
*/
char * eliminar_blancos_finales(char * resultado, const char * origen);

///////////////////////////////////////////////////////////////////////////////
/*Copia la cadena Origen en la cadena Resultado, eliminando los blancos 
iniciales y finales.
    char * resultado: cadena de caracteres donde se copiará la cadena original
    const char * origen: cadena de caracteres a copiar
Devuelve la cadena modificada resultado
*/
char * eliminar_blancos_extremos(char * resultado, const char * origen);

///////////////////////////////////////////////////////////////////////////////
/*Copia la cadena Origen en la cadena Resultado, eliminando los 
blancos intermedios.
    char * resultado: cadena de caracteres donde se copiará la cadena original
    const char * origen: cadena de caracteres a copiar
Devuelve la cadena modificada resultado
*/
char * eliminar_blancos_intermedios(char * resultado, const char * origen);

///////////////////////////////////////////////////////////////////////////////
/*Copia la cadena Origen en la cadena Resultado, eliminando todos los blancos.
    char * resultado: cadena de caracteres donde se copiará la cadena original
    const char * origen: cadena de caracteres a copiar
Devuelve la cadena modificada resultado
Eliminar_blancos_intermedios+eliminar_blancos_extremos
*/
char * eliminar_todos_blancos(char * resultado, const char * origen);

#endif