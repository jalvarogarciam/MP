/***************************************************************************/
/***************************************************************************/
// 
// Fichero: Tiempo.h
//
// Archivo de cabeceras--> Declaración de la clase Tiempo. (V4)
// Modelo de datos para la gestión de tiempos. (horas, minutos y segundos)
//
/***************************************************************************/
/***************************************************************************/

#ifndef TIEMPO
#define TIEMPO

#include <string>
#include <iostream>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class Tiempo
{  
private:
	
    int horas;
    int minutos;
    int segundos;
    time_t tiempo;    //Tiempo total en segundos (duracion).
    
public:
    /*************************************************************************/
    // Constructores
    /*************************************************************************/
	
    /********************************************************************/
    /* Constructor sin argumentos: 
	 Inicializa el tiempo con el tiempo actual
    */
	Tiempo();


    /********************************************************************/
	/* Constructor manual:
     Inicializa el tiempo con los valores dados:
        h: horas
        m: minutos
        s: segundos
    */
	Tiempo(int h, int m, int s);


    /********************************************************************/
	/* Constructor automático: 
	 Inicializa el tiempo a partir de un objero time_t "t"
    */
	Tiempo(time_t t);

    
    /********************************************************************/
	/* Constructor formato cadena: 
	 Inicializa el tiempo a partir de una cadena con formato hh:mm:ss
    */
	Tiempo(string cadena);
    
    /*************************************************************************/
    /*************************************************************************/
    


    /*************************************************************************/
    // setters y getters 
    /*************************************************************************/

    //Establece las horas a través de un entero "h"
    void SetHoras(int h);

    //Establece los minutos a través de un entero "m"
    void SetMinutos(int m);

    //Establece los segundos a través de un entero "s"
    void SetSegundos(int s);

    //Devuelve las horas
    int GetHoras();

    //Devuelve los minutos
    int GetMinutos();

    //Devuelve los segundos
    int GetSegundos();

    //Devuelve el tiempo en formato time_t
    time_t GetTiempo();

    //Devuelve el tiempo en formato cadena
    string ToString();

    /*************************************************************************/
    /*************************************************************************/



    /*************************************************************************/
    /*Operadores de comparación == != > < <= >=*/

    //Una tiempo es igual (==) que otro si comparten horas, dias y segundos
    bool operator == (const Tiempo & otro) const;
    bool operator != (const Tiempo & otro) const;

    //Un tiempo es mayor cuanto más lejano sea al instante 00 : 00 : 00
    bool operator >= (const Tiempo & otro) const;
    bool operator > (const Tiempo & otro) const;
    bool operator <= (const Tiempo & otro) const;
    bool operator < (const Tiempo & otro) const;

    /*************************************************************************/



    /*************************************************************************/
    /*Operadores de inserción (>>) y extracción sobre flujos (<<)
    La entrada tiene el mismo formato que la salida: hh:mm:ss.
    */
    friend ostream & operator << (ostream & out, const Tiempo & este);
    friend istream & operator >> (istream & in, Tiempo & este);
    /*************************************************************************/

private:

    /*************************************************************************/
    /*Actualiza el tiempo en segundos segun la referencia temporal, 
    horas, minutos y segundos.*/
    void update_tiempo();
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

#endif
