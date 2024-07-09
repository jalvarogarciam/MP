/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// JOSÉ ÁLVARO GARCÍA MÁRQUEZ
// 1º Ingenieria Informática (Grupo B1)
//
// Sesión 11
//
// Fichero: elimina_comentarios(c++).cpp
//
//////////////////////////////////////////////////////////////////////////////
/*
8. Escribir un programa que lea una secuencia indefinida de caracteres de la 
entrada estándar que contiene un programa sintácticamente correcto en C++ y 
copie en la salida estándar un programa equivalente resultado de eliminar 
todos los comentarios.
*/
/***************************************************************************/
/***************************************************************************/


#include <sstream>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

/***************************************************************************/
/*ignora todos los caracteres de un flujo contenidos en un comentario largo
de c++ (formato '/'*...*'/'). 
El único parámetro es una referencia a un flujo de la clase istream.
*/
void ignora_comentario_acotado(istream & in);
/***************************************************************************/


int main()
{
    const int TAM_MAX_LINEA = 80;   // Máxima longitud de cada linea
    
    char c = '\n';

    cout << "Introduzca el codigo del programa (en c++): "<<endl;

    while (cin.peek() != EOF){
        
        //ELIMINA LOS COMENTARIOS
        bool comentario = cin.peek() == '/';
        while (comentario){

            cin.ignore(1);  // elimina el '/'
        
            if (cin.peek() == '/' || cin.peek() == '*')
            {
                cin.ignore(1);  // elimina el '/' o el '*'

                // elimina el comentario acotado
                if (cin.peek() == '*')  ignora_comentario_acotado(cin);

                // elimina el resto de linea
                else    cin.ignore(TAM_MAX_LINEA, '\n');  

                /*Devuelve el '\n' eliminado en caso de que toda la linea 
                no sea un comentario*/
                if ( c != '\n') cin.putback('\n');
            }

            // Excepcion del uso del caracter '/'
            else
            {
                comentario = false;
                cin.putback('/');   //devuelve el '/'
            }

            comentario &= cin.peek() == '/';
        }

        // Lee un caracter y lo manda a cout.
        c = cin.get();

        cout << c;//cuando c sea \n se liberará el buffer de salida

    }

    cout<<endl;




}


/***************************************************************************/
void ignora_comentario_acotado(istream & in)
{
    char c = in.get();

    // no reviso in.eof() porque se supone que el programa está bien escrito
    // y por tanto, los comentarios estan cerrados siempre
    while ((c != '*' || in.peek() != '/'))
    {
        c = in.get();
    }
    

    in.ignore(1);   //ignora el '/'
    switch (in.peek())
    {
        case EOF:   in.putback('\0');
        break;

        case '\n':  in.ignore(1);   //borra el \n del final.
        break;

        default: break;
    }

}
/***************************************************************************/