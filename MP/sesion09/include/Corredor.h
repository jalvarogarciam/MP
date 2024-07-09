/***************************************************************************/
/***************************************************************************/
// 
// Fichero: Corredor.h
//
// Archivo de cabeceras--> Declaración de la clase Corredor.
//
// Proyecto. FASE 01. 
//
/***************************************************************************/
/***************************************************************************/

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
    int Dorsal; //número del dorsal. CLAVE PRIMARIA
    string DNI;
    string Nombre;
    string Apellidos;
    Fecha FechaNacimiento;
    char Sexo;  //Valores permitidos: 'H' o 'M'


public:

        /************************************************************************/
        //  CONSTRUCTOR sin Argumentos
        /* Inicializa el corredor con valores por defecto:
        Dorsal=0, DNI="", Nombre="", Apellidos="", FechaNacimiento->actual, Sexo=' '
        */
    Corredor();

    /************************************************************************/
    //  CONSTRUCTOR con argumento string
    /*
    Inicializa el corredor leyendo los datos de una cadena con formato:
        dorsal*DNI*Nombre*Apellidos*FechaNacimiento*Sexo
    */
    Corredor(string linea, char delimitador=DELIMITADOR);

    /************************************************************************/
    //  CONSTRUCTOR de copia
    /* Inicializa el corredor con los datos de otro corredor "otro"
    */
    Corredor(const Corredor &otro);

    ~Corredor();
    /************************************************************************/


    /************************************************************************/
    /* Copia los datos de un corredor dado*/
    void Clona(const Corredor &otro);


    /************************************************************************/
    // Sets y Gets
    /************************************************************************/

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
    void setSexo(char s);


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

    /************************************************************************/
    // TOSTRING
    /* Devuelve una cadena con los datos del corredor con el siguiente formato:
        dorsal Apellidos, Nombre DNI FechaCarrera Sexo
        donde:
            dorsal: número entero de NUM_CASILLAS_FINT dígitos
            Apellidos, Nombre:cadena de caracteres de NUM_CASILLAS_NOMBRE caracteres
            DNI: cadena de caracteres de 9 caracteres
            FechaCarrera: cadena con formato d mmm aaaa
            Sexo: HOMBRE o MUJER
    */
    string ToString ();
};

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
#endif