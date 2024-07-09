/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// JOSÉ ÁLVARO GARCÍA MÁRQUEZ
// 1º Ingenieria Informática (Grupo B1)
//
// Sesión 11
//
// Fichero: CopiaLineasSinAlmohadilla.cpp
//
//////////////////////////////////////////////////////////////////////////////
/*7. Escribir un programa que lea una secuencia indefinida de caracteres de 
la entrada estándar y copie en la salida estándar las líneas que no comiencen 
por el carácter #
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


    while ( cin.peek() != EOF)
    {
        //Primero elimina las lineas que comienzan por '#'
        while (cin.peek() == '#') cin.ignore(TAM_LINEA,'\n');

        //Envia el contenido a cout
        getline(cin,linea);
        cout<<linea<<endl;


    }

    cout<< endl;

}