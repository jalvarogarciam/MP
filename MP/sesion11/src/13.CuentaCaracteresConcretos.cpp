/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// JOSÉ ÁLVARO GARCÍA MÁRQUEZ
// 1º Ingenieria Informática (Grupo B1)
//
// Sesión 11
//
// Fichero: CuentaCaracteresConcretos.cpp
//
//////////////////////////////////////////////////////////////////////////////
/*13. Escribir un programa que lea una secuencia indefinida de caracteres de 
la entrada estándar y reciba como argumento desde la línea de órdenes un dato
de tipo char. El programa mostrará en la salida estándar el número de 
caracteres leidos de la entrada estándar iguales al argumento suministrado.
*/
/***************************************************************************/
/***************************************************************************/

#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char ** argv)
{
    //COMPROBACION DE PARAMETROS
    if (argc != 2)
    {
        cerr<<"NUMERO INCORRECTO DE PARAMETROS, "\
            << "PROPORCIONA EL CARACTER A CONTAR"<<endl;
        exit(1);
    }
    
    char caracter = char (*(argv[1]));
    int cantidad = (cin.get() == caracter) ? 1:0;

    while ( !cin.eof())

        if (cin.get() == caracter)    cantidad++;


    cout<< "el caracter "<<char(caracter)<<" aparece "<< cantidad \
        << " veces."<< endl;

}