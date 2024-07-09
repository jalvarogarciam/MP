/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// JOSÉ ÁLVARO GARCÍA MÁRQUEZ
// 1º Ingenieria Informática (Grupo B1)
//
// Proyecto Fase 4
//
// Fichero: Utils.cpp
//
//////////////////////////////////////////////////////////////////////////////
/*
Modulo de funciones utiles para otras partes del proyecto.
*/
/***************************************************************************/
/***************************************************************************/

#include "Fecha.h"
#include "Tiempo.h"

#include <iomanip>
#include <cstring>
#include <fstream>
#include <sstream>

#include "Constantes.h"


using namespace std;

/****************************************************************************/
/*Comprueba que el fichero al cual esta asociado el flujo proporcionado
como argumento, es correcto (la palabra magica coincide con el string "palabra"
proporcionado como argumento) y omite los comentarios, dejando
el flujo preparado para proporcionar solo los datos.

Devuelve true si el fichero es correcto
*/
bool prepara_flujo_datos(istream & in, string palabra)
{
    string linea; //String con la que opera en el flujo.

    bool error = false;

    in >> linea;    //busca la palabra magica

    if (linea != palabra)   error = true;

    else
    {
        //salta el \n despues de la palabra magica
        in.ignore(1);

        //salta los comentarios
        while (in.peek() == '#') in.ignore(MAX_TAM_LINEA,'\n');
    }

    return error;
}

/****************************************************************************/
/*Envia la palabra magica proporcionada como argumento (palabra), al flujo out,
Además de la fecha y hora actuales en un comentario
*/
void cabecera_ficheros(ostream & out, string palabra)
{
    out << palabra << endl; //aniade la cabecera

    out << "# FECHA: "<< Fecha() << " " << Tiempo() << endl;

    out << '#'<< endl;
}

/****************************************************************************/
/* Apartir de un string que representa el nombre de un fichero desde 
cierto directorio a un fichero (con su respectiva ruta), extrae devuelve dicha
ruta.   ej: titulo= "./proyecto/datos/circuito.cfg" --> "./proyecto/datos"
*/
string Extrae_Ruta (const string & titulo)
{
	string ruta("");

	int pos = titulo.size()-1;
	
	//busca la posicion de la primera barra.
	while (titulo[pos] != '/' && pos >=0)	pos--;

	if (pos != 0)
		for (int i=0; i < pos; i++)	ruta += titulo[i];

	return ruta;
}
/****************************************************************************/
