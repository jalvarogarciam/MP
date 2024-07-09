/******************************************************************************/
/******************************************************************************/
// 
// Fichero: Categoria.cpp
//
// Archivo de implementación--> Definición de los métodos de la clase Categoria.
//
// Proyecto. FASE 4. 
//
/******************************************************************************/
/******************************************************************************/

#include "Categoria.h"

#include "Constantes.h"


#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;


/*****************************************************************************/
/*Funcion auxiliar para intercambiar dos categorias (swap) */
void Intercambia (Categoria & c1, Categoria & c2)
{
    Categoria tmp = c1;
    c1 = c2;
    c2 = tmp;
}
/*****************************************************************************/


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*****************************************************************************/
//  CONSTRUCTOR sin Argumentos
/* Inicializa la categoria con valores por defecto:
    IdCategoria=0, Denominacion="", Sexo=' ', FechaInicial y FechaFinal actual
*/
Categoria::Categoria() 
            : IdCategoria(0), Denominacion(""), Sexo(' '), \
                FechaInicial(Fecha()), FechaFinal(Fecha()) {}

/*****************************************************************************/
//  CONSTRUCTOR por clave primaria -> un argumento int (id)
/* Inicializa la carrera con valores por defecto:
    Denominacion="", Sexo = ' ', FechaInicial y FechaFinal actual
    y IdCategoria=(id)
*/
Categoria::Categoria(int id) : Categoria() { IdCategoria = id;}

/*****************************************************************************/
//  CONSTRUCTOR con argumento string
/* Inicializa la Categoria leyendo los datos de una cadena con formato:
    IdCategoria*Denominacion*Sexo*FechaInicial*FechaFinal*
*/
Categoria::Categoria(string linea, char delimitador)
{
    //flujo asociado a la cadena que contiene los datos
    istringstream iss(linea);
    string cadenaux;    //sting auxiliar para operar con el flujo

    //IdCategoria
    getline(iss, cadenaux, delimitador);
    IdCategoria = stoi(cadenaux);

    //Denominacion
    getline(iss, cadenaux, delimitador);
    istringstream issaux(cadenaux); //flujo auxiliar asociado a la cadena (aux)
    while (issaux >> cadenaux)  Denominacion += cadenaux + " ";
    Denominacion.pop_back(); // elimina el ultimo espacio

    //Sexo
    getline(iss, cadenaux, delimitador);
    istringstream(cadenaux) >> Sexo;    // puede haber espacios

    //FechaInicial
    getline(iss, cadenaux, delimitador);
    istringstream(cadenaux) >> FechaInicial;

    //FechaFinal
    getline(iss, cadenaux, delimitador);
    istringstream(cadenaux) >> FechaFinal;
}

/*****************************************************************************/
//  CONSTRUCTOR de copia
/* Inicializa la categoría con los mismos valores que "otra" categoría
*/
Categoria::Categoria(const Categoria &otra)
            : IdCategoria(otra.IdCategoria), Denominacion(otra.Denominacion), \
            Sexo(otra.Sexo), FechaInicial(otra.FechaInicial), \
            FechaFinal(otra.FechaFinal){}
/*****************************************************************************/




/*****************************************************************************/
// Setters y Getters
/*****************************************************************************/

// Establece el IdCategoria a través de un entero "id"
void Categoria::SetIdCategoria(int id) {IdCategoria = id;}

// Establece la Denominacion a través de una cadena de caracteres "nombre"
void Categoria::SetDenominacion(string nombre) {Denominacion = nombre;}

// Establece el Sexo a través de un caracter "sexo"
void Categoria::SetSexo(char sexo) {Sexo = sexo;}

// Establece la FechaInicial a través de una Fecha "fecha"
void Categoria::SetFechaInicial(Fecha fecha) {FechaInicial = fecha;}

// Establece la FechaFinal a través de una Fecha "fecha"
void Categoria::SetFechaFinal(Fecha fecha) {FechaFinal = fecha;}

// Devuelve el IdCategoria
int Categoria::GetIdCategoria() {return IdCategoria;}

// Devuelve la Denominacion
string Categoria::GetDenominacion() {return Denominacion;}

// Devuelve el Sexo
char Categoria::GetSexo() {return Sexo;}

// Devuelve la FechaInicial
Fecha Categoria::GetFechaInicial() {return FechaInicial;}

// Devuelve la FechaFinal
Fecha Categoria::GetFechaFinal() {return FechaFinal;}
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*Operador ==
Dos Categorias son iguales si tienen el mismo id, si no, desiguales (!=)
*/
bool Categoria::operator == (Categoria & otro) const
{
    return (IdCategoria==otro.IdCategoria);
}
bool Categoria::operator != (Categoria & otro) const
{
    return !(*(this) == otro);
}
/*****************************************************************************/



/*****************************************************************************/
/*Operadores de inserción (>>) y extracción sobre flujos (<<)
La entrada tiene el mismo formato que la salida: campo * campo * ... *
siendo '*' un delimitador.
*/
ostream & operator<< (ostream & out, const Categoria & este)
{
    //Ajusto las preferencias del flujo
    out.setf(ios::showpoint);
    out.setf(ios::fixed);
    out.precision(NC_DEC); //numero de cifras decimales a mostrar

    //*NOTA: añado espacio entre cada delimitador para mejorar su legibilidad

    //IdCategoria
    out <<setfill(' ')<<setw(NC_INT-2) << este.IdCategoria << ' ' \
        << DELIMITADOR<< ' ';

    //Denominacion
    out <<setfill(' ')<<setw(NC_DENOM_CAT)<< left \
        << este.Denominacion << ' '<< DELIMITADOR<< ' ';

    //Sexo
    out << este.Sexo << ' '<< DELIMITADOR<< ' ';

    //FechaInicial
    out << este.FechaInicial << ' '<< DELIMITADOR << ' ';

    //FechaFinal
    out << este.FechaFinal << ' '<< DELIMITADOR;

    return (out);
}
istream & operator>> (istream & in, Categoria & este)
{
    string cadena;
    getline(in,cadena,'\n');   //paso el flujo a un string


    //Reinicializa el objeto
    este = Categoria(cadena);

    return in; // devuelve referencia al objeto istream
}
/*****************************************************************************/

/*****************************************************************************/
// TOSTRING
/* Devuelve una cadena con los datos de la categoría con los siguientes datos:

            idCategoria Denominacion Sexo [FechaInicial-FechaFinal]
*/
string Categoria::ToString ()
{
    ostringstream oss;  //flujo de salida asociado a string

    //Ajusto las preferencias del flujo
    oss.setf(ios::showpoint);
    oss.setf(ios::fixed);
    oss.precision(NC_DEC); //numero de cifras decimales a mostrar

    oss << setfill(' ') << setw(NC_INT-2) << IdCategoria << "   ";   // 6C

    // Denominacion (just. dcha)
    string sexo = Sexo == 'H' ? " HOMBRE " : " MUJER  ";
    oss << setfill(' ') << setw(NC_DENOM_CAT+8) << right \
        << (Denominacion + sexo);                                   //16 char

    oss << "[" << FechaInicial.GetAnio() <<" - "<< FechaFinal.GetAnio() << "]";
                                                                    // 13 C


    return oss.str();

    //TOTAL-> 35 CARACTERES
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////