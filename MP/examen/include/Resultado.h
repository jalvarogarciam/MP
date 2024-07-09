/******************************************************************************/
/******************************************************************************/
// 
// Fichero: Resultado.h
//
// Archivo de cabeceras--> Declaración de la clase Resultado.
//
// Proyecto. FASE 4. 
//
/******************************************************************************/
/******************************************************************************/


#ifndef RESULTADO
#define RESULTADO

#include <string>

#include "Tiempo.h"
#include "Constantes.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

class Resultado 
{
private:
    int Posicion;           // Posición en la que ha finalizado el corredor
    int Dorsal;             // Dorsal del corredor
    Tiempo TiempoCarrera;   // Tiempo en finalizar la carrera

public:

    /*************************************************************************/
    //  CONSTRUCTOR sin Argumentos
    /* Inicializa el resultado con valores por defecto:
        Dorsal=0, Posicion=0, TiempoCarrera actual
    */
    Resultado();

    /*************************************************************************/
    //  CONSTRUCTOR por clave primaria -> un argumento int (dorsal)
    /* Inicializa el resultado con valores por defecto:
        Posicion = 0, TiempoCarrera actual y Dorsal = "dorsal"
    */
    Resultado(int dorsal);

    /*************************************************************************/
    //  CONSTRUCTOR con argumento string
    /* Inicializa el resultado leyendo los datos de una cadena con formato:
                Dorsal*TiempoCarrera*Posicion*
    */
    Resultado(string linea, char delimitador=DELIMITADOR);

    /*************************************************************************/
    //  CONSTRUCTOR de copia
    /* Inicializa el resultado con los datos de otro resultado "otro"
    */
    Resultado(const Resultado &otro);
    /*************************************************************************/



    /*************************************************************************/
    // Setters y Getters
    /*************************************************************************/
    
    // Establece el Dorsal a través de un entero "dorsal"
    void SetDorsal(int dorsal);

    // Establece la Posicion a través de un entero "posicion"
    void SetPosicion(int posicion);

    // Establece el TiempoCarrera a través de un objeto Tiempo "tiempo"
    void SetTiempoCarrera(Tiempo tiempo);

    // Devuelve el Dorsal
    int GetDorsal();

    // Devuelve la Posicion
    int GetPosicion();

    // Devuelve el TiempoCarrera
    Tiempo GetTiempoCarrera();
    /*************************************************************************/
    /*************************************************************************/



    /*************************************************************************/
    /*Operador ==
    Dos resultados son iguales si tienen el mismo dorsal, si no, desiguales (!=)
    */
    bool operator == (Resultado & otro) const;
    bool operator != (Resultado & otro) const;
    /*************************************************************************/
    /*Operadores > y <
    un resultado es mayor que otro si su puesto es menor, y sera menor que otro 
    si su puesto es mayor (no son posibles los casos <= y >=)
    */
    bool operator < (Resultado & otro) const;
    bool operator > (Resultado & otro) const;
    /*************************************************************************/



    /*************************************************************************/
    /*Operadores de inserción (>>) y extracción sobre flujos (<<)
    La entrada tiene el mismo formato que la salida: campo * campo * ... *
    siendo '*' un delimitador.
    */
    friend ostream & operator << (ostream & out, const Resultado & este);
    friend istream & operator >> (istream & in, Resultado & este);
    /************************************************************************/

    /*************************************************************************/
    // TOSTRING
    /* Devuelve una cadena con los datos del resultado para cada corredor con 
        el siguiente formato:

            posicion. dorsal tiempo
    */
    string ToString ();
    /*************************************************************************/

};

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

/*****************************************************************************/
/*Funcion auxiliar para intercambiar dos resultados (swap) */
void Intercambia (Resultado & r1, Resultado & r2);
/*****************************************************************************/


#endif
