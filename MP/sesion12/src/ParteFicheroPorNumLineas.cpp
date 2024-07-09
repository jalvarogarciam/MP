/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// JOSÉ ÁLVARO GARCÍA MÁRQUEZ
// 1º Ingenieria Informática (Grupo B1)
//
// Sesión 12
//
// Fichero: ParteFicheroPorNumLineas.cpp
//
//////////////////////////////////////////////////////////////////////////////
/*
17. Construir un programa que divida un fichero de texto en diferentes 
ficheros indicando como argumentos el nombre del fichero original y el máximo 
número de líneas que contendrá cada fichero resultante.

Se creará un fichero de control que contendrá con los datos necesario para 
la reconstrucción del fichero original.
*/
/***************************************************************************/
/***************************************************************************/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>

#include "Utils_ES.h"


using namespace std;

/***************************************************************************/
/***************************************************************************/
int main(int argc, char **argv)
{
	// Comprobar numero de argumentos  

	if (argc != 3) {
		cerr << "Error: Numero de argumentos incorrecto." << endl;
		cerr << "Formato: "<< argv[0] <<" <fich_in> <numero de lineas> "<< endl;
		exit (1);

	}else{

        if (!ExisteFichero(argv[1])){
            cerr << "Error: " << argv[1] << "no existe o no es un fichero." \
                 << endl;
            exit(2);
        }

        bool es_numero = true;
        for (int i = 0; i < strlen(argv[2]) && es_numero; i++){
            if (!isdigit(argv[2][i]))   
                es_numero = false;
        }
        
        if (!es_numero){
            cerr << "Error: \"" << argv[2] << "\" no es un número." << endl;
            exit (3);
        }
    }

    int tamanio = atoi(argv[2]);   //Numero de lineas que tendra cada particion

    ifstream ifs(argv[1]);  //Flujo de entrada asociado al fichero

    string linea;   //string que almacena cada linea leida del flujo

    getline(ifs, linea);    //lectura adelantada

    int num_particiones = 1;
    bool problemas = ifs.eof();
    while (!problemas)
    {
        //Flujo de salida asociado a cada fichero particion
        ofstream ofs(string(string(argv[1]) + "_"+to_string(num_particiones)));
        //El nombre de cada particion es "(nombre del fichero)_(indice)"


        if (!ofs.fail()){   //Si se ha podido crear el fichero

            ofs << linea << endl;   //envia a ofs la linea ya leida 

            getline(ifs, linea);    //lectura adelantada
            for (int i = 1; i < tamanio && !ifs.eof(); i++){
                ofs << linea << endl;
                getline(ifs, linea);    //lectura adelantada
            }

            num_particiones++;

            ofs.close();

        }else{

            cerr << "ha habido un problema creando la particion nº " \
                 << num_particiones << endl;
            
            //considero que si no se han podido hacer todas las particiones no, 
            //se deberian borrar todas.
            /*
            cerr << "Borrando las particiones creadas..." << endl;
            for (int i=1; i<=num_particiones; i++)
            {
                remove(string(string(argv[1]) + "_"+ to_string(i)).c_str());
                cerr << setw(5)<< " "<< "particion " << i << " borrada"<< endl;
            }
            */
            

           exit(4);
        }

        problemas = ifs.eof() || ofs.fail();
    }

    ofstream ofs(string("." + string(argv[1]) + ".ctrl"));

    if (!ofs){
        cerr<<"no se ha podido crear el archivo resumen"<<endl;
        exit(5);
    }

    ofs << argv[1] << endl << num_particiones-1 << endl;

    ofs.close();
    ifs.close();
	return 0;
}
/***************************************************************************/
/***************************************************************************/