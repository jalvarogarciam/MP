/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// JOSÉ ÁLVARO GARCÍA MÁRQUEZ
// 1º Ingenieria Informática (Grupo B1)
//
// Sesión 11
//
// Fichero:  Cabecera.cpp
//
//////////////////////////////////////////////////////////////////////////////
/*15. Implementar un programa similar a head para mostrar las primeras líneas 
de una secuencia de caracteres, tal como se encuentran en el fichero.
*/
/***************************************************************************/
/***************************************************************************/

#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

int main (int argc, char ** argv)
{
    //COMPROBACION DE PARAMETROS
    if (argc != 2)
    {
        cerr<<"NUMERO INCORRECTO DE PARAMETROS, "\
            << "EL NUMERO DE LINEAS A MOSTRAR"<<endl;
        exit(1);
    }

    int cantidad = - atoi(argv[1]);

    string linea;


    for (int i = 0; i < cantidad && ; i++)
    {
        cout<<linea<<endl;
        getline(cin,linea);

    }



    return 0;
}

