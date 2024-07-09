/******************************************************************************/
/******************************************************************************/
// 
// Fichero: Corredor.cpp
//
// Archivo de implementación--> Definición de los métodos de la clase Corredor.
//
// Proyecto. FASE 4. 
//
/******************************************************************************/
/******************************************************************************/
#include "Corredor.h"

#include "Constantes.h"

#include "Fecha.h"

#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;


/*****************************************************************************/
/*Funcion auxiliar para intercambiar dos corredores (swap) */
void Intercambia (Corredor & c1, Corredor & c2)
{
    Corredor tmp = c1;
    c1 = c2;
    c2 = tmp;
}
/*****************************************************************************/



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*****************************************************************************/
//  CONSTRUCTOR sin Argumentos
/* Inicializa el corredor con valores por defecto:
    Dorsal=0, DNI="", Nombre="", Apellidos="", FechaNacimiento->actual, Sexo=' '
*/
Corredor::Corredor() 
            : Dorsal(0), DNI(""), Nombre(""), Apellidos(""), \
                FechaNacimiento(Fecha()), Sexo(' '){}

/*****************************************************************************/
//  CONSTRUCTOR con un argumento int (dorsal)
/* Inicializa el corredor con valores por defecto:
    DNI="", Nombre="", Apellidos="", FechaNacimiento->actual, Sexo=' '
    y el y Dorsal = "dorsal"
*/
Corredor::Corredor(int dorsal) : Corredor() { Dorsal = dorsal;}

/*****************************************************************************/
//  CONSTRUCTOR con argumento string
/* Inicializa el corredor leyendo los datos de una cadena con formato:
    dorsal*DNI*Nombre*Apellidos*FechaNacimiento*Sexo*
*/
Corredor::Corredor(string linea, char delimitador)
{
    //flujo asociado a la cadena que contiene los datos
    istringstream iss(linea);
    string cadenaux;    //sting auxiliar para operar con el flujo

    //DORSAL
    getline(iss, cadenaux, delimitador);
    Dorsal = stoi(cadenaux);

    //usa el operador >> para deshacerse de los espacios innecesarios

    //DNI
    getline(iss, cadenaux, delimitador);
    istringstream(cadenaux)>>DNI;

    //Nombre
    getline(iss, cadenaux, delimitador);
    istringstream issaux(cadenaux); //flujo auxiliar asociado a la cadena (aux)
    while (issaux >> cadenaux)  Nombre += cadenaux + " ";
    Nombre.pop_back();   // elimina el ultimo espacio

    //Apellidos
    getline(iss, cadenaux, delimitador);
    issaux.clear();     //restablezco el flujo auxiliar vacio y lo reutilizo
    issaux.str(cadenaux);
    while (issaux >> cadenaux)  Apellidos += cadenaux + " "; 
    Apellidos.pop_back();   // elimina el ultimo espacio

    //FechaNacimiento
    getline(iss, cadenaux, delimitador);
    istringstream(cadenaux) >> FechaNacimiento;
    
    //Sexo
    iss >> Sexo;
    // El siguiente caracter siempre es el sexo (operator >>)
}

/*****************************************************************************/
//  CONSTRUCTOR de copia
/* Inicializa el corredor con los datos de otro corredor "otro"
*/
Corredor::Corredor(const Corredor &otro)
            : Dorsal(otro.Dorsal), DNI(otro.DNI), Nombre(otro.Nombre), \
            Apellidos(otro.Apellidos), FechaNacimiento(otro.FechaNacimiento), \
            Sexo(otro.Sexo){}
/*****************************************************************************/




/*****************************************************************************/
// Setters y Getters
/*****************************************************************************/

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
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*Operador ==
Dos corredores son iguales si tienen el mismo dorsal o el mismo DNI, 
si no, desiguales (!=)
*/
bool Corredor::operator == (Corredor & otro) const
{
    return (Dorsal==otro.Dorsal || DNI == otro.DNI);
}
bool Corredor::operator != (Corredor & otro) const
{
    return !(*(this) == otro);
}
/*****************************************************************************/



/*****************************************************************************/
/*Operadores de inserción (>>) y extracción sobre flujos (<<)
La entrada tiene el mismo formato que la salida: campo * campo * ... *
siendo '*' un delimitador.
*/
ostream & operator<< (ostream & out, const Corredor & este)
{
    //Ajusto las preferencias del flujo
    out.setf(ios::showpoint);
    out.setf(ios::fixed);
    out.precision(NC_DEC); //numero de cifras decimales a mostrar

    //*NOTA: añado espacio entre cada delimitador para mejorar su legibilidad

    //Dorsal
    out <<setfill(' ')<<setw(NC_INT) << este.Dorsal << ' '<< DELIMITADOR<< ' ';

    //DNI
    out << este.DNI << ' '<< DELIMITADOR<< ' ';

    //Nombre
    out <<setfill(' ')<<setw(15) << este.Nombre << ' '<< DELIMITADOR<< ' ';

    //Apellidos
    out <<setfill(' ')<<setw(20) << este.Apellidos << ' '<< DELIMITADOR << ' ';

    //FechaNacimiento
    out << este.FechaNacimiento << ' '<< DELIMITADOR << ' ';

    //Sexo
    out << este.Sexo << ' '<< DELIMITADOR;

    return (out);
}

istream & operator>> (istream & in, Corredor & este)
{
    string cadena;
    getline(in,cadena,'\n');   //paso el flujo a un string


    //Reinicializa el objeto
    este = Corredor(cadena);

    return in; // devuelve referencia al objeto istream
}
/*****************************************************************************/

/*****************************************************************************/
// TOSTRING
/* Devuelve una cadena con los datos del corredor con el siguiente formato:

            dorsal Apellidos, Nombre DNI FechaCarrera Sexo
*/
string Corredor::ToString ()
{
    ostringstream oss;  //flujo de salida asociado a string

    //Ajusto las preferencias del flujo
    oss.setf(ios::showpoint);
    oss.setf(ios::fixed);
    oss.precision(NC_DEC); //numero de cifras decimales a mostrar

    oss << " " << setfill(' ') << setw(NC_INT) << Dorsal << "   ";   // 9C

    oss << setfill(' ') << setw(NC_NOMBRE) <<left<< (Apellidos + ", " + Nombre);
                                            //Apellidos, Nombre (just. izq) 30C

    oss << setfill(' ') << setw(12) << left << DNI;   //ABCDEFGH0    12C
                                                                  //000.000 12C

    oss << FechaNacimiento.ToString(true);   //d m(3 iniciales) aaaa 12C
    oss<<" ";

    if (Sexo == 'H')    oss << "HOMBRE";
    else                oss << "MUJER ";    // 6C

    return oss.str();
    //TOTAL ->69 CARACTERES
}
/*****************************************************************************/

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
