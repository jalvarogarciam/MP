/******************************************************************************/
/******************************************************************************/
// 
// Fichero: Carrera.h
//
// Archivo de cabeceras--> Declaración de la clase Carrera.
//
// Proyecto. FASE 4. 
//
/******************************************************************************/
/******************************************************************************/

#ifndef CARRERA
#define CARRERA

#include <string>

#include "Fecha.h"
#include "Constantes.h"


using namespace std;

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

class Carrera 
{
private:
    int IdCarrera;          //Número identificador. CLAVE PRIMARIA
    string Denominacion;    //Nombre de la carrera
    Fecha FechaCarrera;     //Fecha de la carrera
    double Distancia;       //Distancia (en km) de la carrera

public:

    /*************************************************************************/
    //  CONSTRUCTOR sin Argumentos
    /* Inicializa la carrera con valores por defecto:
        IdCarrera=0, Denominacion="", Distancia=0.0, FechaCarrera->actual
    */   
    Carrera();

    /*************************************************************************/
    //  CONSTRUCTOR por clave primaria -> un argumento int (id)
    /* Inicializa la carrera con valores por defecto:
        Denominacion="", Distancia=0.0, FechaCarrera->actual
        y IdCarrera=(id)
    */
    Carrera(int id);

    /*************************************************************************/
    //  CONSTRUCTOR sin Argumentos
    /* Inicializa la carrera leyendo los datos de una cadena con formato:
        idCarrera*distancia*fechaCarrera*denominacion*
    */
    Carrera(string linea, char delimitador=DELIMITADOR);


    /*************************************************************************/
    //  CONSTRUCTOR de copia
    /* Inicializa la carrera con los datos de otra carrera "otra"
    */
    Carrera(const Carrera &otra);
    

    /*************************************************************************/
    // Setters y Getters
    /*************************************************************************/

    // Establece el idCarrera a través de un entero "id"
    void SetIdCarrera(int id);

    // Establece la denominacion a través de una cadena "den"
    void SetDenominacion(string den);

    // Establece la fechaCarrera a través de un objeto Fecha "f"
    void SetFechaCarrera(Fecha f);

    // Establece la distancia a través de un número real "d"
    void SetDistancia(double d);

    // Devuelve el idCarrera
    int GetIdCarrera();

    // Devuelve la denominacion
    string GetNombre();

    // Devuelve la fechaCarrera
    Fecha GetFechaCarrera();

    // Devuelve la distancia
    double GetDistancia();
    /*************************************************************************/
    /*************************************************************************/


    /*************************************************************************/
    /*Operador ==
    Dos carreras son iguales si tienen el mismo id, si no, desiguales (!=)
    */
    bool operator == (Carrera & otro) const;
    bool operator != (Carrera & otro) const;
    /*************************************************************************/



    /*************************************************************************/
    /*Operadores de inserción (>>) y extracción sobre flujos (<<)
    La entrada tiene el mismo formato que la salida: campo * campo * ... *
    siendo '*' un delimitador.
    */
    friend ostream & operator << (ostream & out, const Carrera & este);
    friend istream & operator >> (istream & in, Carrera & este);
    /*************************************************************************/

    /*************************************************************************/
    // TOSTRING
    /* Devuelve una cadena con los datos de la carrera con el siguiente formato:

                idCarrera denominacion distancia fechaCarrera
    */
    string ToString ();
    /*************************************************************************/
};

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


/*****************************************************************************/
/*Funcion auxiliar para intercambiar dos carreras (swap) */
void Intercambia (Carrera & c1, Carrera & c2);
/*****************************************************************************/

#endif