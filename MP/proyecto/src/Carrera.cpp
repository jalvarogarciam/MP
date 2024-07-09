/******************************************************************************/
/******************************************************************************/
// 
// Fichero: Carrera.cpp
//
// Archivo de implementación--> Definición de los métodos de la clase Carrera.
//
// Proyecto. FASE 4. 
//
/******************************************************************************/
/******************************************************************************/

#include "Carrera.h"

#include "Constantes.h"


#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;


/*****************************************************************************/
/*Funcion auxiliar para intercambiar dos carreras (swap) */
void Intercambia (Carrera & c1, Carrera & c2)
{
    Carrera tmp = c1;
    c1 = c2;
    c2 = tmp;
}
/*****************************************************************************/


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


/*****************************************************************************/
//  CONSTRUCTOR sin Argumentos
/* Inicializa la carrera con valores por defecto:
    IdCarrera=0, Denominacion="", Distancia=0.0, FechaCarrera->actual
*/
Carrera::Carrera() 
            : IdCarrera(0), Denominacion(""), Distancia(0.0), \
                FechaCarrera(Fecha()) {}

/*****************************************************************************/
//  CONSTRUCTOR por clave primaria -> un argumento int (id)
/* Inicializa la carrera con valores por defecto:
    Denominacion="", Distancia=0.0, FechaCarrera->actual y IdCarrera=(id)
*/
Carrera::Carrera(int id) : Carrera() { IdCarrera = id; }

/*****************************************************************************/
//  CONSTRUCTOR con argumento string
/* Inicializa la carrera leyendo los datos de una cadena con formato:
    idCarrera*distancia*fechaCarrera*denominacion*
*/
Carrera::Carrera(string linea, char delimitador)
{
    //flujo asociado a la cadena que contiene los datos
    istringstream iss(linea);
    string cadenaux;    //sting auxiliar para operar con el flujo

    //IdCarrera
    getline(iss, cadenaux, delimitador);
    IdCarrera = stoi(cadenaux);

    //Distancia
    getline(iss, cadenaux, delimitador);
    Distancia = stod(cadenaux);

    //FechaCarrera
    getline(iss, cadenaux, delimitador);    
    istringstream(cadenaux) >> FechaCarrera;

    //Denominacion
    getline(iss, cadenaux, delimitador);
    istringstream issaux(cadenaux); //flujo auxiliar asociado a la cadena (aux)
    while (issaux >> cadenaux)  Denominacion += cadenaux + " ";
    Denominacion.pop_back();  // elimina el ultimo espacio
}

/*****************************************************************************/
//  CONSTRUCTOR de copia
/* Inicializa la carrera con los datos de otra carrera "otra"
*/
Carrera::Carrera(const Carrera &otra)
            : IdCarrera(otra.IdCarrera), Denominacion(otra.Denominacion), \
                Distancia(otra.Distancia), FechaCarrera(otra.FechaCarrera){}
/****************************************************************************/



/*****************************************************************************/
// Setters y Getters
/*****************************************************************************/

// Establece el idCarrera a través de un entero "id"
void Carrera::SetIdCarrera(int id){IdCarrera = id;}

// Establece la denominacion a través de una cadena "den"
void Carrera::SetDenominacion(string den){Denominacion = den;}

// Establece la distancia a través de un real "dist"
void Carrera::SetDistancia(double dist){Distancia = dist;}

// Establece la fecha de la carrera a través de un objeto Fecha "fecha"
void Carrera::SetFechaCarrera(Fecha date){Fecha FechaCarrera(date);}

// Devuelve el idCarrera
int Carrera::GetIdCarrera(){return IdCarrera;}

// Devuelve la denominacion
string Carrera::GetNombre(){return Denominacion;}

// Devuelve la distancia
double Carrera::GetDistancia(){return Distancia;}

// Devuelve la fecha de la carrera
Fecha Carrera::GetFechaCarrera(){return FechaCarrera;}
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*Operador ==
Dos carreras son iguales si tienen el mismo id, si no, desiguales (!=)
*/
bool Carrera::operator == (Carrera & otro) const
{
    return (IdCarrera==otro.IdCarrera);
}
bool Carrera::operator != (Carrera & otro) const
{
    return !(*(this) == otro);
}
/*****************************************************************************/



/*****************************************************************************/
/*Operadores de inserción (>>) y extracción sobre flujos (<<)
La entrada tiene el mismo formato que la salida: campo * campo * ... *
siendo '*' un delimitador.
*/
ostream & operator<< (ostream & out, const Carrera & este)
{
    //Ajusto las preferencias del flujo
    out.setf(ios::showpoint);
    out.setf(ios::fixed);
    out.precision(NC_DEC); //numero de cifras decimales a mostrar

    //*NOTA: añade espacio entre cada delimitador para mejorar su legibilidad

    out<<setfill(' ');

    //IdCarrera
    out <<setfill(' ')<<setw(3) << este.IdCarrera << ' '<< DELIMITADOR<< ' ';

    //Distancia
    out <<setfill(' ')<<setw(12) << este.Distancia << ' '<< DELIMITADOR<< ' ';

    //FechaCarrera
    out << este.FechaCarrera <<' '<< DELIMITADOR<< ' ';

    //Denominacion
    out <<setfill(' ')<< setw(NC_DENOM_CAR) << este.Denominacion << ' '\
        << DELIMITADOR;

    return (out);
}
istream & operator>> (istream & in, Carrera & este)
{
    string cadena;
    getline(in,cadena,'\n');   //paso el flujo a un string

    //Reinicializa el objeto
    este = Carrera(cadena);

    return in; // devuelve referencia al objeto istream
}
/*****************************************************************************/

/*****************************************************************************/
// TOSTRING
/* Devuelve una cadena con los datos de la carrera con el siguiente formato:

            idCarrera denominacion distancia fechaCarrera
*/
string Carrera::ToString ()
{
    ostringstream oss;  //flujo de salida asociado a string

    //Ajusto las preferencias del flujo
    oss.setf(ios::showpoint);
    oss.setf(ios::fixed);
    oss.precision(NC_DEC); //numero de cifras decimales a mostrar

    oss << setfill(' ') << setw(3) << IdCarrera << "  ";   // 000 5C

    oss << setfill(' ') << setw(NC_DENOM_CAR) <<left<< Denominacion;//Nombre41C

    oss << setfill(' ') << setfill(' ') << setw(NC_DOUBLE) \
        << Distancia << " Km   "; 
                                                            //00.000 km   12C

    oss << FechaCarrera.ToString(true);  // d m(3 iniciales) aaaa 11C

    return oss.str();

    //TOTAL ->69 CARACTERES
}
/*****************************************************************************/

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////