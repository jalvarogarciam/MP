/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// JOSÉ ÁLVARO GARCÍA MÁRQUEZ
// 1º Ingenieria Informática (Grupo B1)
//
// Sesión 11
//
// Fichero: Cuenta_palabras_por_linea.cpp
//
//////////////////////////////////////////////////////////////////////////////
/*17. Escriba un programa que muestre cuántas palabras hay en cada línea del 
fichero. La información se muestra línea a línea.
*/
/***************************************************************************/
/***************************************************************************/

#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

int main (void)
{
    const int TAM_LINEA = 100;

    string linea;

    int palabras = 0;   //numero de palabras de cada linea


    for (int fila = 1; cin.peek() != EOF; fila++, palabras = 0)
    {

        getline(cin,linea);

        istringstream iss;  //flujo asociado a un string
        iss.str(linea); // Asocia cada linea al flujo "iss"

        string basura;  //  String con contenido no relevante

        /*si el contenido son espaciadores, la cuenta como vacía porque no hay
        palabras para el operador >>*/
        while (iss >> basura) palabras++;

        
        cout<< "Linea "<< setw(6) << fila << ": " << setw(5) << palabras \
            <<" palabras"<<endl;

    }

    cout<< endl;

}