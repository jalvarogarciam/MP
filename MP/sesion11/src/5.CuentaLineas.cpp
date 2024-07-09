/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// JOSÉ ÁLVARO GARCÍA MÁRQUEZ
// 1º Ingenieria Informática (Grupo B1)
//
// Sesión 11
//
// Fichero:  CuentaLineas.cpp
//
//////////////////////////////////////////////////////////////////////////////
/*5. Escribir un programa que lea una secuencia indefinida de caracteres 
de la entrada estándar y muestre en la salida estándar el el número de líneas: 
    a) total, b) vacías y c) no vacías.
*/
/***************************************************************************/
/***************************************************************************/

#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

int main (void)
{

    string linea;

    int total=0, vacias=0, no_vacias=0;



    while ( cin.peek() != EOF)
    {
        getline(cin,linea);

        istringstream iss;  //flujo asociado a un string
        iss.str(linea); // Asocia cada linea al flujo "iss"

        string basura;  //  String con contenido no relevante

        /*si el contenido son espaciadores, la cuenta como vacía porque no hay
        palabras para el operador >>*/
        if (!(iss>>basura)) vacias++;

        else no_vacias++;

        getline(cin, linea);
    }

    total = vacias + no_vacias;

    cout<<endl;
    cout<<setw(20)<<setfill('-')<<' '<<endl<<setfill(' ');
    cout<< setw(14) << "Nº DE LINEAS: "<< setw(4) << total <<endl;
    cout<< setw(14) << " vacias: "<< setw(4) << vacias <<endl;
    cout<< setw(14) << "no vacias: "<< setw(4) << no_vacias <<endl;
    cout<<setw(20)<<setfill('-')<<' '<<endl;
    cout<<endl;

    return 0;
}