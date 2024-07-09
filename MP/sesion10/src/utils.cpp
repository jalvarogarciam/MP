/***************************************************************************/
/***************************************************************************/
// 
// Fichero: utils.h
//
// Archivo de Implementacion--> Definicion de funciones auxiliares.
//
/***************************************************************************/
/***************************************************************************/

#include "utils.h"

#include <cmath>

using namespace std;

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
string FormatInt (int numero, int num_casillas, char relleno){
    
    string cadena(num_casillas, relleno);

    int num_cifras = 1;
    if (numero>0)
        num_cifras= log10(numero) + 1 ;
    else if (numero<0)
        num_cifras = log10(-1*numero) + 1;
    
    //Convierte el número a string.
    cadena= to_string(numero);
    
    //Añade el relleno necesario.
    if (num_cifras < num_casillas){
        string espaciado(num_casillas-num_cifras, relleno);
        cadena= espaciado + cadena;
    }

    return cadena;
}

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
string FormatDouble (double numero, int num_casillas, int num_dec, char relleno)
{
    string cadena(num_casillas, relleno);

    //Si el nº es negativo, devolverá la cadena vacía. (pensado para distancias)
    if ( numero < 0 )
        return cadena;


    string parte_dec(num_dec+1, relleno);   //+1 para incluir el "."
    
    //Si el número de decimales requerido es cero, NO se muestra el punto.
    if (num_dec>0 && numero-int(numero)!=0){

        //Ajusta el nº de cifras decimales e ignora el 0.
        parte_dec= to_string(numero-int(numero)).substr(1,num_dec+1);

        //Si el número de decimales requerido es mayor que el que se necesita se
        //completa con ceros
        while (parte_dec.size() < num_dec)
            parte_dec+='0';
    }

    //crea la cadena requerida.
    cadena= to_string(int(numero)) + parte_dec;

    //Si el número de casillas solicitado es mayor que el que se necesita, se
    //completa el inicio de la parte entera con relleno.
    if (cadena.size() < num_casillas){
        string espaciado(num_casillas-cadena.size(), relleno);
        cadena= espaciado + cadena;
    }

    //prioriza las cifras enteras si el numero es demasiado grande
    while (cadena.size() > num_casillas)
        cadena.pop_back();
    
    return cadena;

}


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
string FormatString (string la_cadena, int num_casillas, char relleno, 
                    TipoAlineacion alineacion)
{
    //Si es demasiado grande, solo devolverá num_casillas elementos de la_cadena
    if (la_cadena.size() > num_casillas)
        return la_cadena.substr(0,num_casillas);
    
    string cadena, espaciado;
    
    if (alineacion==TipoAlineacion::Centro){

        //determina el relleno necesario.
        if (num_casillas > la_cadena.size())
            espaciado = string((int(num_casillas-la_cadena.size())/2), relleno);

        cadena= espaciado + la_cadena + espaciado;

        if (cadena.size() < num_casillas)  //por si la_cadena.size() es impar
            cadena+= relleno;

    }else{
        //determina el relleno necesario.
        if (num_casillas > la_cadena.size())
            espaciado = string(num_casillas-la_cadena.size(), relleno);
        
        if (alineacion==TipoAlineacion::Derecha){
            
            cadena= espaciado + la_cadena;

        }else{ //(alineacion = TipoAlineacion::Izquierda){
            
            cadena= la_cadena + espaciado;
        }
    }

    return cadena;

};


///////////////////////////////////////////////////////////////////////////////
/*Elimina los espacios en blanco iniciales y finales de la cadena.
Parametros:
    -cadena: la cadena a modificar.
Devuelve la cadena modificada.
*/
string & elimina_espacios_extremos(string & cadena){
    
    //elimina los espacios iniciales
    while(isspace(cadena[0]))
        cadena.erase(0,1);

    //elimina los espacios finales
    for (int i= cadena.size()-1; isspace(cadena[i]) && i > 0; i--)
        cadena.erase(i,1);

    return cadena;
}


///////////////////////////////////////////////////////////////////////////////
/*Extrae un campo de una cadena de texto delimitado por un carácter.
Parametros:
    -linea: la cadena de texto de la que se extraerá el campo.
            ej: "campo1*campo2*campo3"
    -delimitador: el carácter que delimita los campos.
    -pos: la posición en la que se encuentra el  inicio del campo en la cadena.
Devuelve el campo extraído y actualiza la posición pos.
*/
string extrae_campo(const string linea, const char delimitador, size_t & pos){
    string campo;

    if (linea[pos]==delimitador)  //Asegura que la posicion inicial sea correcta
        pos++;
    
    for (; linea[pos]!=delimitador; pos++)
        campo += linea[pos];

    elimina_espacios_extremos(campo);

    pos++;  //avanza la posición para el siguiente campo.

    return campo;
}

