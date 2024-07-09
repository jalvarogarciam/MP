/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// JOSÉ ÁLVARO GARCÍA MÁRQUEZ
// 1º Ingenieria Informática (Grupo B1)
//
// Sesión 12
//
// Fichero: NumeraLineas_Ampliacion.cpp
//
//////////////////////////////////////////////////////////////////////////////
/*
1. Escribir un programa que reciba los nombres de dos ficheros de texto de la 
línea de órdenes. El programa creará un fichero (cuyo nombre se especifica en 
el segundo argumento) a partir de un fichero existente (cuyo nombre se 
especifica en el primer argumento) copiando su contenido y añadiendo al 
principio de cada línea, su número.

2. Amplíe la funcionalidad del ejercicio 1 para que permita que los flujos 
de entrada y salida puedan ser, además de flujo asociados a ficheros, 
los flujos cin y cout respectivamente. El programa se puede ejecutar:
    % NumeraLineas_Ampliacion
        Copia desde cin en cout
    % NumeraLineas_Ampliacion fichero
        Copia desde fichero en cout
    % NumeraLineas_Ampliacion fichero1 fichero2
        Copia desde fichero1 en fichero2
*/
/***************************************************************************/
/***************************************************************************/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "Utils_ES.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (int argc, char **argv)
{
	// Comprobar numero de argumentos  

	if (argc <= 3) {

        //ECHO  (cin)
        if (argc == 1)  in_out(cin, cout, true);

        else{
            ifstream ifs (argv[1]); //flujo de entrada asociado a fichero

            if (!ifs) {
                cerr << "Error: No pudo abrirse " << argv[1] << endl;
                exit (2);
            }

            //MORE (fichero)
            if (argc == 2)  in_out(ifs, cout, true);

            //MORE (fichero1) >> (fichero2)
            else{

                ofstream ofs (argv[2]);

                if (!ofs) {
                    cerr << "Error: No pudo crearse " << argv[2] << endl;
                    exit (3);
                }

                in_out(ifs, ofs, true);

                ofs.close();
            }
            ifs.close();

        	// finalizacion: cierre de flujos
        }
	}else{
		cerr << "Error: Numero de argumentos incorrecto. Formatos: " << endl;
		cerr << setw(8)<< "3->  " << argv[0] << " <fich_in> <fich_out> " \
             <<"para copiar el contenido de <fich_in> en <fich_out>" << endl;
        cerr << setw(8)<< "2->  " << argv[0] << " <fich_in> para mostrar el " \
             << "contenido de <fich_in> en la salida estandar" << endl;
		cerr << setw(8)<< "1->  " << argv[0] <<" para enviar el contenido de " \
             << "los datos enviados por la entrada estandar (cin) " \
             << "a la salida estandar (cout)" << endl;
		exit (1);
    }

	return 0;
}

/***************************************************************************/
/***************************************************************************/

