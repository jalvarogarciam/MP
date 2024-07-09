/***************************************************************************/
/***************************************************************************/
// 
// Fichero: utils.h
//
// Archivo de cabeceras--> Declaración de funciones auxiliares.
//
/***************************************************************************/
/***************************************************************************/
#ifndef UTILS
#define UTILS

#include <string>


using namespace std;

///////////////////////////////////////////////////////////////////////////////
/*Tipo enumerado que contiene los valores posibles para la alineación de un 
string.
*/
enum class TipoAlineacion {Izquierda, Centro, Derecha};

///////////////////////////////////////////////////////////////////////////////
/*Convierte el parámetro la_cadena a un string con num_casillas casillas,
rellenando (si procede) con el carácter relleno.
Parametros:
    - Alineacion: indica la justificación de la_cadena. Su valor es uno de los 
    proporcionados por el tipo enumerado TipoAlineacion. (por defecto Izquierda)
    -num_casillas: el numero de caracteres que ocupará el string devuelto.
    -relleno: el carácter que se usará para rellenar los huecos.
    -la_cadena: la cadena a convertir.
PRE: num_casillas > la_cadena.size().
*/
string FormatString (string la_cadena, int num_casillas, char relleno= ' ', 
                    TipoAlineacion alineacion = TipoAlineacion::Izquierda);


///////////////////////////////////////////////////////////////////////////////
/*Convierte el dato numero a un string con num_casillas casillas, que contiene 
el valor textual de numero. Si num_casillas es mayor que el número de dígitos 
de entero se rellena (por la izquierda) con el carácter relleno. 
Parametros:
    -numero: el número a convertir.
    -num_casillas: el número de caracteres que ocupará el string devuelto.
    -relleno: el carácter que se usará para rellenar los huecos.
PRE: num_casillas > cifras del numero.
*/
string FormatInt (int numero, int num_casillas, char relleno=' ');


///////////////////////////////////////////////////////////////////////////////
/*Convierte el dato numero a un string que contiene el valor textual de numero
de acuerdo con el formato indicado según los valores de num_casillas y
num_dec. Si hiciera falta, rellena los huecos con el carácter relleno.
Parametros:
    -numero: el número a convertir.
    -num_casillas: el número de caracteres que ocupará el string devuelto.
    -num_dec: el número de decimales que se mostrarán.
    -relleno: el carácter que se usará para rellenar los huecos.
PRE: num_casillas > cifras del numero + 1 (el punto decimal).
*/
string FormatDouble (double numero, int num_casillas, \
                        int num_dec, char relleno=' ');



///////////////////////////////////////////////////////////////////////////////
/*Elimina los espacios en blanco iniciales y finales de la cadena.
Parametros:
    -cadena: la cadena a modificar.
Devuelve la cadena modificada.
*/
string & elimina_espacios_extremos(string & cadena);

///////////////////////////////////////////////////////////////////////////////
/*Extrae un campo de una cadena de texto delimitado por un carácter.
Parametros:
    -linea: la cadena de texto de la que se extraerá el campo.
            ej: "campo1*campo2*campo3"
    -delimitador: el carácter que delimita los campos.
    -pos: la posición en la que se encuentra el  inicio del campo en la cadena.
Devuelve el campo extraído y actualiza la posición pos.
*/
string extrae_campo(const string linea, const char delimitador, size_t & pos);


#endif