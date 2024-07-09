/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// JOSÉ ÁLVARO GARCÍA MÁRQUEZ
// 1º Ingenieria Informática (Grupo B1)
//
// Sesión 11
//
// Fichero: CuentaPalabrasLongitudConcreta.cpp
//
//////////////////////////////////////////////////////////////////////////////
/*14. Escribir un programa que lea una secuencia indefinida de caracteres de 
la entrada estándar y reciba como argumento desde la línea de órdenes un dato
de tipo char. El programa mostrará en la salida estándar el número de 
caracteres leidos de la entrada estándar iguales al argumento suministrado.
*/
/***************************************************************************/
/***************************************************************************/

#include <sstream>
#include <iomanip>
#include <cstring>
#include <iostream>

using namespace std;

int main(int argc, char ** argv)
{
    //COMPROBACION DE PARAMETROS
    if (argc != 2)
    {
        cerr<<"NUMERO INCORRECTO DE PARAMETROS, "\
            << "PROPORCIONA UNA PALABRA"<<endl;
        exit(1);
    }
    
    size_t longitud = strlen((argv[1]));

    string basura;

    cin>>basura;

    int cantidad = (basura.size() == longitud) ? 1:0;

    while ( cin >> basura )

        if (basura.size() == longitud)    cantidad++;


    cout<< "Hay "<<cantidad<<" palabras con la misma longitud proporcionada (" \
        << longitud <<')'<< endl;

}