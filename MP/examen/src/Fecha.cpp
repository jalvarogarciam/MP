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


#include <sstream>
#include <iomanip>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*****************************************************************************/
// Constructores
/*****************************************************************************/

/************************************************************************/
/* Constructor sin argumentos: 
 Inicializa la Fecha con el el dia, mes y año actuales.
*/
Fecha::Fecha():Fecha(time(nullptr)){}

/************************************************************************/
/* Constructor manual:
 Inicializa la Fecha con los valores dados:
    d: dia
    m: mes
    a: año
*/
Fecha::Fecha(int d, int m, int a)
{
    dia = d;
    mes = m;
    anio = a;

    update_fecha();
}

/************************************************************************/
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

/************************************************************************/
/* Constructor formato cadena: 
 Inicializa la Fecha a partir de una cadena con formato dd/mm/aaaa
*/
Fecha::Fecha (string cadena):Fecha(stoi(cadena.substr(0,2)),
                                    stoi(cadena.substr(3,2)),
                                    stoi(cadena.substr(6,4))){}

/************************************************************************/
/* Constructor de copia
*/
Fecha::Fecha (const Fecha & otro): dia(otro.dia), mes(otro.mes), \
                                    anio(otro.anio), fecha(otro.fecha){}
                            


/*****************************************************************************/
// setters y getters
/*****************************************************************************/

//Establece el dia a través de un entero "d"
void Fecha::SetDia(int d)
{
    dia = d;

    update_fecha(); //actualiza la fecha en formato time_t
}

//Establece el mes a través de un entero "m"
void Fecha::SetMes(int m)
{
    mes = m;

    update_fecha(); //actualiza la fecha en formato time_t
}

//Establece el año a través de un entero "a"
void Fecha::SetAnio(int a)
{
    anio = a;

    update_fecha(); //actualiza la fecha en formato time_t
}

//Devuelve el dia
int Fecha::GetDia(){return dia;}

//Devuelve el mes
int Fecha::GetMes(){return mes;}

//Devuelve el año
int Fecha::GetAnio(){return anio;}

//Devuelve la fecha en formato time_t
time_t Fecha::GetFecha(){return fecha;}


//Devuelve la fecha en formato cadena
// Si corto = true, el formato es dd Mmm(3 primeras letras) AAAA
// Si corto = false, el formato es dd Mes(sin abreviar) AAAA
string Fecha::ToString(bool corto)
{
    ostringstream oss;  //flujo de salida asociado a string

    oss << setfill('0') << setw(2) << dia << " ";   // 3c

    if (corto)      oss << meses_c[mes];
    else            oss << meses_l[mes];

    oss << setfill(' ') << setw(5) << right <<anio;

    return oss.str();
}
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*Operadores de comparación == != > < <= >=*/

//Una fecha es igual (==) que otra si comparten dia, mes y año, si no (!=)
bool Fecha::operator == (const Fecha & otro) const
{
    return (fecha == otro.fecha);
}
bool Fecha::operator != (const Fecha & otro) const
{
    return !((*this) == otro);
}

//Una fecha es mayor cuanto más lejana sea al 1 de enero de 1970
bool Fecha::operator >= (const Fecha & otro) const
{
    return ! ((*this) < otro) ; 
}
bool Fecha::operator > (const Fecha & otro) const
{
    return fecha > otro.fecha ; 
}
bool Fecha::operator <= (const Fecha & otro) const
{
    return ! ((*this) > otro) ; 
}
bool Fecha::operator < (const Fecha & otro) const
{
    return fecha < otro.fecha ; 
}
/*****************************************************************************/



/*****************************************************************************/
/*Operadores de inserción (>>) y extracción sobre flujos (<<)
La entrada tiene el mismo formato que la salida: dd/mm/aaaa.
*/
ostream & operator<< (ostream & out, const Fecha & este)
{
    out.setf (ios::right);

    out << setfill('0') << setw(2) << este.dia << '/' << setw(2) << este.mes \
        << '/' << setw(4) << este.anio;
    
    return (out);
}
istream & operator>> (istream & in, Fecha & este)
{
    string cadena;
    in >> cadena;   //paso a un string la fecha (en texto)
    //NOTA: Se supone que no hay espacios dentro de las fechas ej: dd/  mm...
    //Reinicializa el objeto

    este = Fecha(cadena);
    return in; // devuelve referencia al objeto istream
}
/*****************************************************************************/
/*****************************************************************************/


/*****************************************************************************/
//Metodos privados
/*****************************************************************************/

/*****************************************************************************/
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
/*****************************************************************************/


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

