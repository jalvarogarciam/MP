/******************************************************************************/
/******************************************************************************/
// 
// Fichero: Resultado.cpp
//
// Archivo de implementación--> Definición de los métodos de la clase Resultado.
//
// Proyecto. FASE 4. 
//
/******************************************************************************/
/******************************************************************************/

#include "Resultado.h"

#include "Constantes.h"


#include <iomanip>
#include <sstream>

using namespace std;

/*****************************************************************************/
/*Funcion auxiliar para intercambiar dos resultados (swap) */
void Intercambia (Resultado & r1, Resultado & r2)
{
    Resultado tmp = r1;
    r1 = r2;
    r2 = tmp;
}
/*****************************************************************************/


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*****************************************************************************/
//  CONSTRUCTOR sin Argumentos
/* Inicializa el resultado con valores por defecto:
    Dorsal=0, Posicion=0, TiempoCarrera actual
*/
Resultado::Resultado() 
            : Dorsal(0), Posicion(0), TiempoCarrera(Tiempo()) {}

/*****************************************************************************/
//  CONSTRUCTOR con un argumento int (dorsal)
/* Inicializa el resultado con valores por defecto:
    Posicion = 0, TiempoCarrera actual y Dorsal = "dorsal"
*/
Resultado::Resultado(int dorsal) : Resultado() { Dorsal = dorsal;}

/*****************************************************************************/
//  CONSTRUCTOR con argumento string
/* Inicializa el resultado leyendo los datos de una cadena con formato:
            Dorsal*TiempoCarrera*Posicion*
*/
Resultado::Resultado(string linea, char delimitador)
{
    //flujo asociado a la cadena que contiene los datos
    istringstream iss(linea);
    string cadenaux;    //sting auxiliar para operar con el flujo

    getline(iss, cadenaux, delimitador);
    Dorsal = stoi(cadenaux);

    getline(iss, cadenaux, delimitador);
    istringstream(cadenaux) >> TiempoCarrera;

    iss >> Posicion;    //es el ultimo campo.
}

/*****************************************************************************/
//  CONSTRUCTOR de copia
/* Inicializa el resultado con los mismos valores que "otro" resultado
*/
Resultado::Resultado(const Resultado &otro)
            : Dorsal(otro.Dorsal), Posicion(otro.Posicion), \
            TiempoCarrera(otro.TiempoCarrera){}
/*****************************************************************************/



/*****************************************************************************/
// Setters y Getters
/*****************************************************************************/

// Establece el Dorsal a través de un entero "dorsal"
void Resultado::SetDorsal(int dorsal) {Dorsal = dorsal;}

// Establece la Posicion a través de un entero "posicion"
void Resultado::SetPosicion(int posicion) {Posicion = posicion;}

// Establece el TiempoCarrera a través de un objeto Tiempo "tiempo"
void Resultado::SetTiempoCarrera(Tiempo tiempo) {TiempoCarrera = tiempo;}

// Devuelve el Dorsal
int Resultado::GetDorsal() {return Dorsal;}

// Devuelve la Posicion
int Resultado::GetPosicion() {return Posicion;}

// Devuelve el TiempoCarrera
Tiempo Resultado::GetTiempoCarrera() {return TiempoCarrera;}
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*Operador ==
Dos resultados son iguales si tienen el mismo dorsal, si no, desiguales (!=)
*/
bool Resultado::operator == (Resultado & otro) const
{
    return (Dorsal==otro.Dorsal);
}
bool Resultado::operator != (Resultado & otro) const
{
    return !(*(this) == otro);
}
/*****************************************************************************/
/*Operadores > y <
un resultado es mayor que otro si su puesto es menor, y sera menor que otro 
si su puesto es mayor (no son posibles los casos <= y >=)
*/
bool Resultado::operator < (Resultado & otro) const
{
    return (Posicion > otro.Posicion);
}
bool Resultado::operator > (Resultado & otro) const
{
    return (Posicion < otro.Posicion);
}
/*****************************************************************************/



/*****************************************************************************/
/*Operadores de inserción (>>) y extracción sobre flujos (<<)
La entrada tiene el mismo formato que la salida: campo * campo * ... *
siendo '*' un delimitador.
*/
ostream & operator<< (ostream & out, const Resultado & este)
{
    //Ajusto las preferencias del flujo
    out.setf(ios::showpoint);
    out.setf(ios::fixed);
    out.precision(NC_DEC); //numero de cifras decimales a mostrar

    //*NOTA: añado espacio entre cada delimitador para mejorar su legibilidad

    //Dorsal
    out <<setfill(' ')<<setw(NC_INT)<< este.Dorsal <<' '<< DELIMITADOR<< ' ';

    //TiempoCarrera
    out << este.TiempoCarrera << ' '<< DELIMITADOR<< ' ';

    //Posicion
    out <<setfill(' ')<<setw(NC_INT-1) << este.Posicion << ' '<< DELIMITADOR;

    return (out);
}
istream & operator>> (istream & in, Resultado & este)
{
    string cadena;
    getline(in,cadena,'\n');   //paso el flujo a un string

    //Reinicializa el objeto
    este = Resultado(cadena);

    return in; // devuelve referencia al objeto istream
}
/*****************************************************************************/

/*****************************************************************************/
// TOSTRING
/* Devuelve una cadena con los datos del resultado para cada corredor con 
   el siguiente formato:

            Posicion Dorsal TiempoCarrera
*/
string Resultado::ToString ()
{
    ostringstream oss;  //flujo de salida asociado a string

    //Ajusto las preferencias del flujo
    oss.setf(ios::showpoint);
    oss.setf(ios::fixed);
    oss.precision(NC_DEC); //numero de cifras decimales a mostrar

    oss << setfill(' ') << setw(NC_INT-1) << Posicion << " ";   // 5C

    oss << setfill(' ') << setw(NC_INT) << Dorsal << "  ";  // 7C

    oss << TiempoCarrera.ToString();  // Tiempo hh:mm:ss  8C

    return oss.str();

    //TOTAL -> 20;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////