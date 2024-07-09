/******************************************************************************/
/******************************************************************************/
// 
// Fichero: Corredor.h
//
// Archivo de cabeceras--> Declaración de la clase Corredor.
//
// Proyecto. FASE 4. 
//
/******************************************************************************/
/******************************************************************************/

#ifndef CORREDOR
#define CORREDOR

#include <string>

#include "Fecha.h"
#include "Constantes.h"

using namespace std;



//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

class Corredor 
{
private:
    int Dorsal;                 //Numero del dorsal. CLAVE PRIMARIA
    string DNI;                 //Identificador administrativo
    string Nombre;
    string Apellidos;
    Fecha FechaNacimiento;
    char Sexo;                  //Valores permitidos: 'H' o 'M'


public:

    /*************************************************************************/
    //  CONSTRUCTOR sin Argumentos
    /* Inicializa el corredor con valores por defecto:
    Dorsal=0, DNI="", Nombre="", Apellidos="", FechaNacimiento->actual, Sexo=' '
    */
    Corredor();

    /*************************************************************************/
    //  CONSTRUCTOR por clave primaria -> un argumento int (dorsal)
    /* Inicializa el corredor con valores por defecto:
        DNI="", Nombre="", Apellidos="", FechaNacimiento->actual, Sexo=' '
        y el y Dorsal = "dorsal"
    */
    Corredor(int dorsal);

    /*************************************************************************/
    //  CONSTRUCTOR con argumento string
    /*
    Inicializa el corredor leyendo los datos de una cadena con formato:
        dorsal*DNI*Nombre*Apellidos*FechaNacimiento*Sexo*
    */
    Corredor(string linea, char delimitador=DELIMITADOR);

    /*************************************************************************/
    //  CONSTRUCTOR de copia
    /* Inicializa el corredor con los datos de otro corredor "otro"
    */
    Corredor(const Corredor &otro);
    /*************************************************************************/



    /*************************************************************************/
    // Setters y Geters
    /*************************************************************************/

    // Establece el numero del dorsal a través de un entero
    void SetDorsal(int numero);

    // Establece el DNI a través de un string "dni"
    void SetDNI(string dni);

    // Establece el nombre a través de un string "nombre"
    void SetNombre(string nombre);

    // Establece los apellidos a través de un string "apellidos"
    void SetApellidos(string apellidos);

    // Establece la fecha de nacimiento a través de un objeto Fecha "fecha"
    void SetFechaNacimiento(Fecha fecha);

    // Establece el sexo a través de un char "sexo"
    void SetSexo(char s);


    // Devuelve el numero del dorsal
    int GetDorsal();

    // Devuelve el DNI
    string GetDNI();

    // Devuelve el nombre
    string GetNombre();

    // Devuelve los apellidos
    string GetApellidos();

    // Devuelve la fecha de nacimiento
    Fecha GetFechaNacimiento();

    // Devuelve el sexo
    char GetSexo();
    /*************************************************************************/
    /*************************************************************************/



    /*************************************************************************/
    /*Operador ==
    Dos corredores son iguales si tienen el mismo dorsal o el mismo DNI, 
    si no, desiguales (!=)
    */
    bool operator == (Corredor & otro) const;
    bool operator != (Corredor & otro) const;
    /*************************************************************************/



    /*************************************************************************/
    /*Operadores de inserción (>>) y extracción sobre flujos (<<)
    La entrada tiene el mismo formato que la salida: campo * campo * ... *
    siendo '*' un delimitador.
    */
    friend ostream & operator << (ostream & out, const Corredor & este);
    friend istream & operator >> (istream & in, Corredor & este);
    /*************************************************************************/

    /*************************************************************************/
    // TOSTRING
    /* Devuelve una cadena con los datos del corredor con el siguiente formato:

                dorsal Apellidos, Nombre DNI FechaCarrera Sexo
    */
    string ToString ();
    /*************************************************************************/

};

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


/*****************************************************************************/
/*Funcion auxiliar para intercambiar dos corredores (swap) */
void Intercambia (Corredor & c1, Corredor & c2);
/*****************************************************************************/


#endif