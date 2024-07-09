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


/***********************************************************************/
/*Funcion auxiliar para intercambiar dos corredores (swap) */
void Intercambia (Corredor & c1, Corredor & c2)
{
    Corredor tmp = c1;
    c1 = c2;
    c2 = tmp;
}

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
//  CONSTRUCTOR con un argumento int (dorsal)
/* Inicializa el corredor con valores por defecto:
    DNI="", Nombre="", Apellidos="", FechaNacimiento->actual, Sexo=' '
    y el y Dorsal = "dorsal"
*/
Corredor::Corredor(int dorsal) 
            : Dorsal(dorsal), DNI(""), Nombre(""), Apellidos(""), \
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
// Sets y Gets
/************************************************************************/

// Establece el numero del dorsal a través de un entero
void Corredor::SetDorsal(int numero){Dorsal = numero;}

// Establece el DNI a través de un string "dni"
void Corredor::SetDNI(string dni){DNI = dni;}

// Establece el nombre a través de un string "nombre"
void Corredor::SetNombre(string nombre){Nombre = nombre;}

// Establece los apellidos a través de un string "apellidos"
void Corredor::SetApellidos(string apellidos){Apellidos = apellidos;}

// Establece la fecha de nacimiento a través de un objeto Fecha "fecha"
void Corredor::SetFechaNacimiento(Fecha fecha){FechaNacimiento = fecha;}

// Establece el sexo a través de un char "sexo"
void Corredor::SetSexo(char s){Sexo = s;}

// Devuelve el numero del dorsal
int Corredor::GetDorsal(){return Dorsal;}

// Devuelve el DNI
string Corredor::GetDNI(){return DNI;}

// Devuelve el nombre
string Corredor::GetNombre(){return Nombre;}

// Devuelve los apellidos
string Corredor::GetApellidos(){return Apellidos;}

// Devuelve la fecha de nacimiento
Fecha Corredor::GetFechaNacimiento(){return FechaNacimiento;}

// Devuelve el sexo
char Corredor::GetSexo(){return Sexo;}


/************************************************************************/
/*Operador ==
Dos corredores son iguales si tienen el mismo dorsal o el mismo DNI, 
si no, desiguales (!=)
NOTA: dos corredores no pueden tener el mismo dorsal ni el mismo dni
*/
bool Corredor::operator == (Corredor & otro) const
{
    return (Dorsal==otro.Dorsal || DNI == otro.DNI);
}
bool Corredor::operator != (Corredor & otro) const
{
    return !(*(this) == otro);
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