/***************************************************************************/
/***************************************************************************/
// 
// Fichero: Fecha.h
//
// Archivo de cabeceras--> Declaración de la clase Fecha. (V1.0)
// Modelo de datos para la gestión de Fechas. (dia, mes y año)
//
/***************************************************************************/
/***************************************************************************/


#ifndef FECHA
#define FECHA

#include <string>


using namespace std;

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class Fecha
{  
private:
    int dia;
    int mes;
    int anio;
    char meses[12][4] = {"Ene", "Feb", "Mar", "Abr", "May", "Jun",\
                                "Jul", "Ago", "Sep", "Oct", "Nov", "Dic"};
    //NOTA: el vector meses es no constante para poder hacer asignaciones 
    // sin necesidad de definir un operador de asignacion.

    time_t fecha;    //Duracion desde el origen (tiempo Unix).

    void update_fecha(); //Actualiza la fecha en formato time_t

public:
    /************************************************************************/
    // Constructores
    /************************************************************************/	
	/* Constructor sin argumentos: 
	 Inicializa la Fecha con el el dia, mes y año actuales.
    */
	Fecha();

    /************************************************************************/
    /* Constructor manual:
     Inicializa la Fecha con los valores dados:
        d: dia
        m: mes
        a: año
    */
    Fecha(int d, int m, int a);


    /************************************************************************/
    /* Constructor automático: 
     Inicializa la Fecha a partir de un objero time_t "t"
    */
    Fecha (time_t t);

    /************************************************************************/
    /* Constructor formato cadena: 
     Inicializa la Fecha a partir de una cadena con formato dd/mm/aaaa
    */
    Fecha (string cadena);


    
    /************************************************************************/
    // sets y gets 
    /************************************************************************/
    
    //Establece el dia a través de un entero "d"
    void setDia(int d);

    //Establece el mes a través de un entero "m"
    void setMes(int m);

    //Establece el año a través de un entero "a"
    void setAnio(int a);

    //Devuelve el dia
    int getDia();

    //Devuelve el mes
    int getMes();

    //Devuelve el año
    int getAnio();

    //Devuelve la fecha en formato time_t
    time_t getFecha();

    //Devuelve la fecha en formato cadena
    string ToString();

};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

#endif
