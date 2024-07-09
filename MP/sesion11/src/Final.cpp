/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// JOSÉ ÁLVARO GARCÍA MÁRQUEZ
// 1º Ingenieria Informática (Grupo B1)
//
// Sesión 11
//
// Fichero:  Final.cpp
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


const int TAM_MAX_LINEA = 256;


/***************************************************************************/
/*Elimina 'n' lineas desde la posicion 'indice' de un string con varias lineas 
(tiene tantas lineas como veces aparece en ella el caracter '\n')
*/
void erase_linea(string & cadena, int indice = 0, int n = 1);
/***************************************************************************/


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

    //vector dinamico donde se almacenan las 'cantidad' ultimas lineas
    string tail = "";

    //Construye el string texto.
    int num_lineas = 1;
    while (cin.peek()!=EOF)
    {
        getline(cin,linea);

        if (num_lineas>cantidad)    erase_linea(tail); 
        
        tail += (linea + "\n");

        num_lineas++;
    }

    cout<<endl;
    cout<<tail<<endl;


    return 0;

}

/*
int main (int argc, char ** argv)
{
    //COMPROBACION DE PARAMETROS
    if (argc != 2)
    {
        cerr<<"NUMERO INCORRECTO DE PARAMETROS, "\
            << "EL NUMERO DE LINEAS A MOSTRAR"<<endl;
        exit(1);
    }

    int cantidad = atoi(argv[1]);

    string texto = ""; //string donde se almacenará el texto

    string linea;

    //Construye el string texto y cuenta las lineas.
    int num_lineas = 0;
    while (cin.peek()!=EOF)
    {
        getline(cin,linea);

        texto += linea + '\n';

        num_lineas ++;
    }

    istringstream iss;
    iss.str(texto);     //Asocia el flujo iss al string texto

    //Ignora las primeras lineas (las que sobran)
    for (int i = 0; i < num_lineas-cantidad; i++)

        iss.ignore(TAM_MAX_LINEA, '\n');
    
    //Manda a cout las ultimas lineas
    for (int i = 0; i<cantidad; i++)
    {
        getline(iss, linea);
        cout<<linea<<endl;
    }


    return 0;

}
*/
/***************************************************************************/
/*Elimina 'n' lineas desde la posicion 'indice' de un string con varias lineas 
(tiene tantas lineas como veces aparece en ella el caracter '\n')
PRE: 0<=indice<=nº de lineas del string
PRE: 1<=n<=nº de lineas del string
*/
void Tail ( istream & in, int n)
{
    
}
/***************************************************************************/