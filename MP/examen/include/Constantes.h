/***************************************************************************/
/***************************************************************************/
// 
// Fichero: Constantes.h
//
// Archivo de cabeceras--> Declaración de constantes del proyecto.
//
// Proyecto. FASE 4.
/***************************************************************************/
/***************************************************************************/

#ifndef CONSTANTES
#define CONSTANTES

using namespace std;


const char DELIMITADOR = '*';   //Carácter delimitador de campos
const int MAX_TAM_LINEA = 256;   //numero máximo de caracteres por linea


const unsigned int NC_INT=5;   //Número de casillas para un entero
const unsigned int NC_DOUBLE=6;   //Número de casillas para un double
const unsigned int NC_STRING=7;   //Número de casillas para un string
const unsigned int NC_DEC=3; //Número de cifras decimales para un double

//  Numero de casillas para el nombre de los corredores
const unsigned int NC_NOMBRE = 30;

//número de chars para la denominación
//la mas larga es ABSOLUTA o MASTER X
const unsigned int NC_DENOM_CAT=8;


//número de chars para la denominac.
const unsigned int NC_DENOM_CAR=41;

#endif