/***************************************************************************/
/***************************************************************************/
// 
// Fichero: Tiempo.cpp
//
// Archivo de implementación--> Definición de los métodos de la clase Tiempo.
// Modelo de datos para la gestión de Tiempos. (horas, minutos y segundos)
//
/***************************************************************************/
/***************************************************************************/

#include "Tiempo.h"


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
    Inicializa el tiempo con el tiempo actual
*/
Tiempo::Tiempo():Tiempo(time(nullptr)){SetHoras(horas);} //Tiempo actual.

/************************************************************************/
/* Constructor manual:
    Inicializa el tiempo con los valores dados:
        h: horas
        m: minutos
        s: segundos
*/
Tiempo::Tiempo(int h, int m, int s)
{
    horas = h;
    minutos = m;
    segundos = s;

    update_tiempo();
}

/************************************************************************/
/* Constructor automático: 
    Inicializa el tiempo a partir de un objero time_t "t"
*/
Tiempo::Tiempo(time_t t)
{
    tiempo = t%(24*3600) + 3600*2; //Ajuste horario de verano en España (UTC+2)

    horas = tiempo/3600;
    minutos = (tiempo%3600)/60;
    segundos = (tiempo%3600)%60;
}

/************************************************************************/
/* Constructor formato cadena: 
    Inicializa el tiempo a partir de una cadena con formato hh:mm:ss
*/
Tiempo::Tiempo(string cadena): Tiempo(stoi(cadena.substr(0,2)),
                                        stoi(cadena.substr(3,2)),
                                        stoi(cadena.substr(6,4))){}
/*****************************************************************************/
/*****************************************************************************/


/*****************************************************************************/
// setters y getters
/*****************************************************************************/

//Establece las horas a través de un entero "h"
void Tiempo::SetHoras(int h)
{
    horas = h;

    update_tiempo();    //Actualiza el miembro tiempo (time_t)
}

//Establece los minutos a través de un entero "m"
void Tiempo::SetMinutos(int m)
{
    minutos = m;

    update_tiempo();    //Actualiza el miembro tiempo (time_t)
}

//Establece los segundos a través de un entero "s"
void Tiempo::SetSegundos(int s)
{
    segundos = s;

    update_tiempo();    //Actualiza el miembro tiempo (time_t)
}

//Devuelve las horas
int Tiempo::GetHoras(){return horas;}

//Devuelve los minutos
int Tiempo::GetMinutos(){return minutos;}

//Devuelve los segundos
int Tiempo::GetSegundos(){return segundos;}

//Devuelve el tiempo en formato time_t
time_t Tiempo::GetTiempo(){return tiempo;}

//Devuelve el tiempo en formato cadena
string Tiempo::ToString()
{
    ostringstream oss;  //flujo de salida asociado a string

    oss << setfill('0') << setw(2) << horas << ":" << setw(2) << minutos \
        << ":" << setw(2) << segundos;
    
    return oss.str();
}
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*Operadores de comparación == != > < <= >=*/

//Una tiempo es igual (==) que otro si comparten horas, dias y segundos
bool Tiempo::operator == (const Tiempo & otro) const
{
    return (tiempo == otro.tiempo);
}
bool Tiempo::operator != (const Tiempo & otro) const
{
    return !((*this) == otro);
}

//Un tiempo es mayor cuanto más lejano sea al instante 00 : 00 : 00
bool Tiempo::operator >= (const Tiempo & otro) const
{
    return ! ((*this) < otro) ; 
}
bool Tiempo::operator > (const Tiempo & otro) const
{
    return tiempo > otro.tiempo ; 
}
bool Tiempo::operator <= (const Tiempo & otro) const
{
    return ! ((*this) > otro) ; 
}
bool Tiempo::operator < (const Tiempo & otro) const
{
    return tiempo < otro.tiempo ; 
}
/*****************************************************************************/



/*****************************************************************************/
/*Operadores de inserción (>>) y extracción sobre flujos (<<)
La entrada tiene el mismo formato que la salida: hh:mm:ss.
*/
ostream & operator<< (ostream & out, const Tiempo & este)
{
    out << setfill('0') << setw(2) << este.horas << ':' \
        << setw(2) << este.minutos << ':' << setw(2) << este.segundos;
    
    return (out);
}

istream & operator>> (istream & in, Tiempo & este)
{
    string cadena;
    in >> cadena;   //paso a un string la fecha (en texto)
    //NOTA: Se supone que no hay espacios dentro de las fechas ej: hh :  mm:...

    //Reinicializa el objeto
    este = Tiempo(cadena);

    return in; // devuelve referencia al objeto istream
}
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
// Metodos privados
/*****************************************************************************/

/*****************************************************************************/
/*Actualiza el tiempo en segundos segun la referencia temporal, 
horas, minutos y segundos.
*/
void Tiempo::update_tiempo()
{
    tiempo = horas*3600 + minutos*60 + segundos;
}
/*****************************************************************************/


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
