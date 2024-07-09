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
7. Escriba un programa que reciba el nombre de un fichero PGM a través de la 
línea de órdenes y muestre la información de su cabecera. Puede suponer que se 
trata de un fichero PGM correcto.

PGM es el acrónimo de Portable Gray Map file format. Una imagen PGM almacena
una imagen de niveles de gris, es decir, un valor numérico que indica la 
luminosidad para cada píxel. Un valor de luminosidad viene determinado por un 
número entero en el rango [0, 255]. Por lo tanto, un único byte será suficiente 
para almacenar el contenido de un píxel. 
PGM es un buen ejemplo de formato de almacenamiento de imágenes con cabecera. 
Podemos considerar dos partes en un fichero PGM:

a)  CABECERA. sigue el siguiente formato:
P5                                          -> cadena magica de identificacion.
# Comentarios de linea completa 
# iniciados por el caracter "#". 
# Su longitud máxima es de 70 caracteres.
c f                                         -> numero de columnas y filas.
M                                           -> valor maximo de gris.

b)  CONTENIDO DE LA IMAGEN. Esta en formato binario. Corresponde a una 
secuencia de f × c valores de luminosidad (uno por pixel). El primero 
corresponde al píxel de la esquina superior izquierda, el segundo al de su 
derecha, etc. (el último byte corresponde al píxel de la esquina inferior 
derecha de la imagen): almacenamiento por filas.
Si se emplea un byte (8 bits) por pixel disponemos de 2 8 = 256 valores de
luminosidad por pixel donde 0 corresponde al negro y 255 al blanco.
*/
/***************************************************************************/
/***************************************************************************/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>

#include "Utils_ES.h"


using namespace std;

/***************************************************************************/
/***************************************************************************/
int main(int argc, char ** argv)
{
    	// Comprobar numero de argumentos  

	if (argc != 2) {
		cerr << "Error: Numero de argumentos incorrecto." << endl;
		cerr << "Formato: "<< argv[0] <<" <ficheroPGM> "<< endl;
		exit (1);

	}else{

        if (!ExisteFichero(argv[1])){
            cerr << "Error: " << argv[1] << " no existe o no es un fichero." \
                 << endl;
            exit(2);
        }
    }


    //Longitud maxima de las lineas de comentarios
    const unsigned int MAX_TAM_LINEA = 70;

    //Numero de filas, columnas y valor maximo de gris
    int fils, cols, max_gris;

    //Tamanio en bytes del contenido de la imagen, sin contar la cabecera 
    double tamanio; 

    string tipo_fichero;    //cadena mágica que identifica el tipo de fichero.
    
    //Flujo de salida asociado a string que almacenará los comentarios
    ostringstream comentarios;   

    ifstream ifs(argv[1]);  //Flujo de entrada asociado al fichero (existe)

    string linea;   //string auxiliar para almacenar el contenido de cada linea



    /***********************************************************************/
    //Lectura de datos
    /***********************************************************************/
    // PRIMERA PARTE: CABECERA
    getline(ifs,linea);

    //Guarda el tipo de fichero
    istringstream(linea) >> tipo_fichero;   //(es una sola palabra)

    //Guarda los comentarios
    while (ifs.peek() == '#')
    {
        getline(ifs,linea);

        comentarios << linea << endl;
    }

    //Guarda los parámetros de la imagen
    ifs >> fils;
    ifs >> cols;
    ifs >> max_gris;

    /***********************************************************************/



    /***********************************************************************/
    //Procesamiento de datos
    /***********************************************************************/

    //El tamanio en bits del contenido de la imagen es el numero de bits 
    //que necesita para 1 pixel por el numero de pixeles en total
    long int bitsXpixel = max_gris != 0 ? int(log2(max_gris)) + 1 : 1;
    tamanio = (bitsXpixel * fils * cols) / 8;

    //Posibles prefijos (tamanios) para una imagen en Bytes
    const char magnitudes[] = {' ', 'K', 'M', 'G'};
    int magnitud = 0;

    //Lo pasa a su magnitud más adecuada
    while (tamanio > 1024 && (magnitud < 3)){
        tamanio /= (pow (2,10));    
        magnitud++;
    }
    /***********************************************************************/


    /***********************************************************************/
    //salida
    /***********************************************************************/
    //Ajusta las preferencias para la representacion numerica.
    cout.setf (ios::showpoint);
    cout.setf (ios::fixed);
    cout.setf (ios::left);
    cout.precision(4);

    cout << setfill(' ')<<endl;
    cout << "--------------------------------------------------------" << endl;
    cout << setw(15) << "TIPO: " << tipo_fichero << endl;
    cout << setw(15) << "TAMANIO: " << tamanio << " " \
         << magnitudes[magnitud]<<"B" << endl;
    cout << setw(15) << "RESOLUCION: " << fils << " x " << cols << endl;
    cout << setw(15) << "CODIFICACION: " << max_gris << " bits  (" \
         << max_gris+1 << " niveles de gris)" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout<< endl << "info: "<<endl \
         << comentarios.str() << endl << endl;
    /***********************************************************************/



    ifs.close();
    return 0;
}
/***************************************************************************/
/***************************************************************************/