/******************************************************************************/
/******************************************************************************/
// 
// Fichero: Categoria.h
//
// Archivo de cabeceras--> Declaración de la clase Categoria.
//
// Proyecto. FASE 4. 
//
/******************************************************************************/
/******************************************************************************/

#ifndef CATEGORIA
#define CATEGORIA

#include <string>

#include "Fecha.h"
#include "Constantes.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

class Categoria 
{
private:
    int IdCategoria;     //Numero identificador de la categoría. CLAVE PRIMARIA
    string Denominacion; //Nombre de la categoría 
    char Sexo;           //Valores permitidos: 'H' o 'M'
    Fecha FechaInicial;  //Fecha mínima de nacimiento para la categoría
    Fecha FechaFinal;    //Fecha máxima de nacimiento para la categoría

public:

    /*************************************************************************/
    //  CONSTRUCTOR sin Argumentos
    /* Inicializa la categoria con valores por defecto:
    IdCategoria=0, Denominacion="", Sexo=' ', FechaInicial y FechaFinal actual
    */
    Categoria();

    /*************************************************************************/
    //  CONSTRUCTOR por clave primaria -> un argumento int (id)
    /* Inicializa la carrera con valores por defecto:
        Denominacion="", Sexo = ' ', FechaInicial y FechaFinal->actual
        y IdCategoria=(id)
    */
    Categoria(int id);

    /*************************************************************************/
    //  CONSTRUCTOR con argumento string
    /* Inicializa la Categoria leyendo los datos de una cadena con formato:
        IdCategoria*Denominacion*Sexo*FechaInicial*FechaFinal*
    */
    Categoria(string linea, char delimitador=DELIMITADOR);

    /*************************************************************************/
    //  CONSTRUCTOR de copia
    /* Inicializa la categoría con los datos de otra categoría "otra"
    */
    Categoria(const Categoria &otra);
    /*************************************************************************/



    /*************************************************************************/
    // Setters y Getters
    /*************************************************************************/

    // Establece el IdCategoria a través de un entero "id"
    void SetIdCategoria(int id);

    // Establece la Denominacion a través de una cadena de caracteres "nombre"
    void SetDenominacion(string nombre);

    // Establece el Sexo a través de un caracter "sexo"
    void SetSexo(char sexo);

    // Establece la FechaInicial a través de una Fecha "fecha"
    void SetFechaInicial(Fecha fecha);

    // Establece la FechaFinal a través de una Fecha "fecha"
    void SetFechaFinal(Fecha fecha);

    // Devuelve el IdCategoria
    int GetIdCategoria();

    // Devuelve la Denominacion
    string GetDenominacion();

    // Devuelve el Sexo
    char GetSexo();

    // Devuelve la FechaInicial
    Fecha GetFechaInicial();

    // Devuelve la FechaFinal
    Fecha GetFechaFinal();
    /*************************************************************************/
    /*************************************************************************/



    /*************************************************************************/
    /*Operador ==
    Dos categorias son iguales si tienen el mismo id, si no, desiguales (!=)
    */
    bool operator == (Categoria & otro) const;
    bool operator != (Categoria & otro) const;
    /*************************************************************************/



    /*************************************************************************/
    /*Operadores de inserción (>>) y extracción sobre flujos (<<)
    La entrada tiene el mismo formato que la salida: campo * campo * ... *
    siendo '*' un delimitador.
    */
    friend ostream & operator << (ostream & out, const Categoria & este);
    friend istream & operator >> (istream & in, Categoria & este);
    /*************************************************************************/

    /*************************************************************************/
    // TOSTRING
    /* Devuelve una cadena con los datos de la categoría con el siguiente 
    formato:

            idCategoria Denominacion Sexo [FechaInicial-FechaFinal]
    */
    string ToString ();

};
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

/*****************************************************************************/
/*Funcion auxiliar para intercambiar dos Categorias (swap) */
void Intercambia (Categoria & c1, Categoria & c2);
/*****************************************************************************/


#endif

