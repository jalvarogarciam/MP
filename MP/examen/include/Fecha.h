/***************************************************************************/
/***************************************************************************/
// 
// Fichero: Fecha.h
//
// Archivo de cabeceras--> Declaración de la clase Fecha. (V4)
// Modelo de datos para la gestión de Fechas. (dia, mes y año)
//
/***************************************************************************/
/***************************************************************************/


#ifndef FECHA
#define FECHA

#include <string>
#include <iostream>


using namespace std;

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class Fecha
{  
private:
    int dia;
    int mes;
    int anio;
/*
    static const char meses_c[12][4];   // meses en formato corto
    
    static const char meses_l[12][10];  //meses en formato largo

*/
    char meses_c[12][4] = {"Ene", "Feb", "Mar", "Abr", "May", \
                            "Jun", "Jul", "Ago", "Sep", "Oct", "Nov", "Dic"};

    char meses_l[12][11] = {"Enero", "Febrero", "Marzo", "Abril", \
                                    "Mayo", "Junio", "Julio", "Agosto", \
                            "Septiembre", "Octubre", "Noviembre", "Diciembe"};

    time_t fecha;    //Duracion desde el origen (tiempo Unix).

public:

    /*************************************************************************/
    // Constructores
    /*************************************************************************/

    /********************************************************************/
    /* Constructor sin argumentos: 
     Inicializa la Fecha con el el dia, mes y año actuales.
    */
	Fecha();

    /********************************************************************/
    /* Constructor manual:
     Inicializa la Fecha con los valores dados:
        d: dia
        m: mes
        a: año
    */
    Fecha(int d, int m, int a);

    /********************************************************************/
    /* Constructor automático: 
     Inicializa la Fecha a partir de un objero time_t "t"
    */
    Fecha (time_t t);

    /********************************************************************/
    /* Constructor formato cadena: 
     Inicializa la Fecha a partir de una cadena con formato dd/mm/aaaa
    */
    Fecha (string cadena);

    /********************************************************************/
    /* Constructor de copia
    */
    Fecha (const Fecha & otro);
    /*************************************************************************/
    /*************************************************************************/



    /*************************************************************************/
    // sets y gets 
    /*************************************************************************/
    
    //Establece el dia a través de un entero "d"
    void SetDia(int d);

    //Establece el mes a través de un entero "m"
    void SetMes(int m);

    //Establece el año a través de un entero "a"
    void SetAnio(int a);

    //Devuelve el dia
    int GetDia();

    //Devuelve el mes
    int GetMes();

    //Devuelve el año
    int GetAnio();

    //Devuelve la fecha en formato time_t
    time_t GetFecha();

    //Devuelve la fecha en formato cadena
    // Si corto = true, el formato es dd Mmm(3 primeras letras) AAAA
    // Si corto = false, el formato es dd Mes(sin abreviar) AAAA
    string ToString(bool corto = false);
    /*************************************************************************/
    /*************************************************************************/



    /*************************************************************************/
    /*Operadores de comparación == != > < <= >=*/

    //Una fecha es igual (==) que otra si comparten dia, mes y año, si no (!=)
    bool operator == (const Fecha & otro) const;
    bool operator != (const Fecha & otro) const;

    //Una fecha es mayor cuanto más lejana sea al 1 de enero de 1970
    bool operator >= (const Fecha & otro) const;
    bool operator > (const Fecha & otro) const;
    bool operator <= (const Fecha & otro) const;
    bool operator < (const Fecha & otro) const;

    /*************************************************************************/


    /*************************************************************************/
    /*Operadores de inserción (>>) y extracción sobre flujos (<<)
    La entrada tiene el mismo formato que la salida: dd/mm/aaa.
    */
    friend ostream & operator << (ostream & out, const Fecha & este);
    friend istream & operator >> (istream & in, Fecha & este);
    /*************************************************************************/

private:

    /*************************************************************************/
    /*Actualiza la fecha en formato time_t
    */
    void update_fecha();
    /*************************************************************************/

};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

#endif
