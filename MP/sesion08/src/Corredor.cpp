/***************************************************************************/
/***************************************************************************/
// 
// Fichero: Corredor.cpp
//
// Archivo de implementación--> Definición de los métodos de la clase Corredor.
//
// Proyecto. FASE 01. 
//
/***************************************************************************/
/***************************************************************************/
#include "Corredor.h"

#include "Constantes.h"

#include "utils.h"
#include "Fecha.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////


/************************************************************************/
//  CONSTRUCTOR sin Argumentos
/* Inicializa el corredor con valores por defecto:
    Dorsal=0, DNI="", Nombre="", Apellidos="", FechaNacimiento->actual, Sexo=' '
*/
Corredor::Corredor() 
            : Dorsal(0), DNI(""), Nombre(""), Apellidos(""), \
                FechaNacimiento(Fecha()), Sexo(' '){}

/************************************************************************/
//  CONSTRUCTOR con argumento string
/* Inicializa el corredor leyendo los datos de una cadena con formato:
    dorsal*DNI*Nombre*Apellidos*FechaNacimiento*Sexo
*/
Corredor::Corredor(string linea, char delimitador)
{
    size_t pos = 0;


    // extrae_campo(linea, delimitador, pos) extrae cada campo de la cadena

    Dorsal = stoi(extrae_campo(linea, delimitador, pos));

    DNI = extrae_campo(linea, delimitador, pos);

    Nombre = extrae_campo(linea, delimitador, pos);

    Apellidos = extrae_campo(linea, delimitador, pos);

    FechaNacimiento = Fecha(extrae_campo(linea, delimitador, pos));

    Sexo = extrae_campo(linea, delimitador, pos)[0];
}


/************************************************************************/
//  CONSTRUCTOR de copia
/* Inicializa el corredor con los datos de otro corredor "otro"
*/
Corredor::Corredor(const Corredor &otro)
            : Dorsal(otro.Dorsal), DNI(otro.DNI), Nombre(otro.Nombre), \
            Apellidos(otro.Apellidos), FechaNacimiento(otro.FechaNacimiento), \
            Sexo(otro.Sexo){}
/************************************************************************/

/************************************************************************/
/* Copia los datos de un corredor dado*/
void Corredor::Clona(const Corredor &otro)
{
    Dorsal = otro.Dorsal;
    DNI = otro.DNI;
    Nombre = otro.Nombre;
    Apellidos = otro.Apellidos;
    FechaNacimiento = otro.FechaNacimiento;
    Sexo = otro.Sexo;
}


/************************************************************************/
// Sets y Gets
/************************************************************************/

// Establece el numero del dorsal a través de un entero
void Corredor::setDorsal(int numero)
{
    Dorsal = numero;
}

// Establece el DNI a través de un string "dni"
void Corredor::setDNI(string dni)
{
    DNI = dni;
}

// Establece el nombre a través de un string "nombre"
void Corredor::setNombre(string nombre)
{
    Nombre = nombre;
}

// Establece los apellidos a través de un string "apellidos"
void Corredor::setApellidos(string apellidos)
{
    Apellidos = apellidos;
}

// Establece la fecha de nacimiento a través de un objeto Fecha "fecha"
void Corredor::setFechaNacimiento(Fecha fecha)
{
    FechaNacimiento = fecha;
}

// Establece el sexo a través de un char "sexo"
void Corredor::setSexo(char s)
{
    Sexo = s;
}

// Devuelve el numero del dorsal
int Corredor::getDorsal()
{
    return Dorsal;
}

// Devuelve el DNI
string Corredor::getDNI()
{
    return DNI;
}

// Devuelve el nombre
string Corredor::getNombre()
{
    return Nombre;
}

// Devuelve los apellidos
string Corredor::getApellidos()
{
    return Apellidos;
}

// Devuelve la fecha de nacimiento
Fecha Corredor::getFechaNacimiento()
{
    return FechaNacimiento;
}

// Devuelve el sexo
char Corredor::getSexo()
{
    return Sexo;
}


/************************************************************************/
// TOSTRING
/* Devuelve una cadena con los datos del corredor con el siguiente formato:
    dorsal Apellidos, Nombre DNI FechaCarrera Sexo
    donde:
        dorsal: número entero de NUM_CASILLAS_FINT dígitos
        Apellidos, Nombre:cadena de caracteres de NUM_CASILLAS_NOMBRE caracteres
        DNI: cadena de caracteres de 9 caracteres
        FechaCarrera: cadena con formato d m(3 iniciales) aaaa
        Sexo: cadena de caracteres de 6 caracteres

*/
string Corredor::ToString ()
{
    string cadena="";

    cadena += " " + FormatInt(Dorsal, NUM_CASILLAS_FINT, ' ') + "  ";   // 000
    cadena += FormatString(Apellidos + ", " + Nombre, NUM_CASILLAS_NOMBRE, ' ')\
                + "  ";  //Apellidos, Nombre (just. izq)
    cadena += DNI + "  ";                           //ABCDEFGH0
    cadena += FechaNacimiento.ToString() + "  ";  // d m(3 iniciales) aaaa
    cadena += Sexo == 'H' ? "HOMBRE" : "MUJER";

    return cadena;
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////