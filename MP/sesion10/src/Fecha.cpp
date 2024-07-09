/***************************************************************************/
/***************************************************************************/
// 
// Fichero: Fecha.cpp
//
// Archivo de implementación--> Definición de los métodos de la clase Fecha.
// Modelo de datos para la gestión de Fechas. (dia, mes y año)
//
/***************************************************************************/
/***************************************************************************/


#include "Fecha.h"

#include "utils.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/************************************************************************/
// Constructores
/************************************************************************/

/* Constructor sin argumentos: 
 Inicializa la Fecha con el el dia, mes y año actuales.
*/
Fecha::Fecha():Fecha(time(nullptr)){}

/* Constructor manual:
 Inicializa la Fecha con los valores dados:
    d: dia
    m: mes
    a: año
*/
Fecha::Fecha(int d, int m, int a)
{
    dia = d;
    mes = m-1;
    anio = a;

    update_fecha();
}

/* Constructor automático: 
 Inicializa la Fecha a partir de un objero time_t "t"
*/
Fecha::Fecha (time_t t)
{
    fecha = t;

    //Desde el time_t, Crea la estructura tm usando la funcion localtime().
    //recibe un puntero a time_t y devuelve un puntero a struct tm.
    tm tiempo= *localtime(&fecha);
    //obtiene el dia, mes y año del struct tm generado por la fecha Unix.
    dia= tiempo.tm_mday;
    mes= tiempo.tm_mon;  // van del 0 al 11
    anio= tiempo.tm_year + 1900;  //En el struct tm se cuentan desde 1900
    //el resto de campos son ignorados.
}

/* Constructor formato cadena: 
 Inicializa la Fecha a partir de una cadena con formato dd/mm/aaaa
*/
Fecha::Fecha (string cadena):Fecha(int(stoi(cadena.substr(0,2))),
                            int(stoi(cadena.substr(3,2))),
                            int(stoi(cadena.substr(6,4)))){}


/************************************************************************/
// sets y gets
/************************************************************************/

//Establece el dia a través de un entero "d"
void Fecha::setDia(int d){
    dia = d;

    update_fecha();
}

//Establece el mes a través de un entero "m"
void Fecha::setMes(int m){
    mes = m;

    update_fecha();
}

//Establece el año a través de un entero "a"
void Fecha::setAnio(int a){
    anio = a;

    update_fecha();
}

//Devuelve el dia
int Fecha::getDia(){
    return dia;
}

//Devuelve el mes
int Fecha::getMes(){
    return mes;
}

//Devuelve el año
int Fecha::getAnio(){
    return anio;
}

//Devuelve la fecha en formato time_t
time_t Fecha::getFecha(){
    return fecha;
}

//Devuelve la fecha en formato cadena d mmm aaaa
string Fecha::ToString(){
    return FormatInt(dia, 2)+' '+meses[mes]+ ' '+to_string(anio);
}



/******************************************************************************
//Metodos privados
/******************************************************************************/
//Actualiza la referencia temporal del atributo fecha.
void Fecha::update_fecha(){
    //Actualiza la referencia temporal Unix.

    tm tiempo={0};   //Struct de la stl para almacenar fechas.
    //Inicializa el struct con la fecha dada.
    tiempo.tm_mday = dia;
    tiempo.tm_mon = mes - 1;  // van del 0 al 11
    tiempo.tm_year = anio - 1900;  //En el struct tm se cuentan desde 1900
    //el resto de campos, por la inicializacion ({0}) son 0.

    fecha = mktime(&tiempo);    //Convierte el struct tm a time_t.
    //mktime recibe un puntero a una estructura tm y devuelve un time_t.
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

