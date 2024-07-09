/***************************************************************************/
//Metodología de la Programación
//
//Ejercicio 23: Escribir un programa que lea una cadena de caracteres, encuentre
// y registre el inicio de cada palabra, y finalmente muestre el primer 
//carácter de cada palabra.
//
//Archivo main
//
// Fichero: I_EncuentraInicioPalabras.cpp
/***************************************************************************/
/*
PUNTUALIZACIÓN: Considero que una palabra, en éste ámbito, es una secuencia de 
caracteres que no contiene espaciadores. Cada palabra está separada por uno o
varios espaciadores.
*/

#include <iostream>
#include "MiCadenaClasica.cpp"
using namespace std;

//......................................................................
//Estructura de datos InfoPalabras
struct InfoPalabras {
    static const int MAX_PALABRAS=100;
    int num_palabras; // núm. palabras
    const char * palabras[MAX_PALABRAS]; // inicio de palabras
};

//......................................................................
//Función que encuentra el inicio de cada palabra en la cadena "cadena"
InfoPalabras encuentra_palabras (const char * cadena){
    InfoPalabras info;
    info.num_palabras=0;
    const char * p_cadena=cadena;
    
    //Añade la primera inicial en el caso de que no sea un espacio
    if (!isspace(*p_cadena)){
        info.palabras[info.num_palabras]=p_cadena;
        info.num_palabras++;
        p_cadena++;
    }

    //Encuentra el inicio de cada palabra
    for (;*p_cadena!=0; p_cadena++){
        if (!isspace(*p_cadena) && isspace(*(p_cadena-1))){
            info.palabras[info.num_palabras]=p_cadena;
            info.num_palabras++;
        }
    }

    return info;
}

/***************************************************************************/
/***************************************************************************/
int main(){
    InfoPalabras info;
    info.num_palabras=0;
    const unsigned int TAMANIO=2000;
    char cadena[TAMANIO];
    char * p_cadena=cadena;
    
    //.......................................................................
    // Lectura con filtro de la cadena
    cout<<"Introduce una cadena de caracteres (maximo "<<info.MAX_PALABRAS\
        <<" palabras o "<<TAMANIO<<" caracteres en total)."<<endl;
    do{
        cout<<"--> ";
        cin.getline(cadena,TAMANIO);
    }while(chainlen(cadena)==0 || chainlen(cadena)>=TAMANIO-1);

    //.......................................................................
    // Búsqueda de las iniciales de las palabras
    info=encuentra_palabras(p_cadena);

    //.......................................................................
    // Muestreo de las iniciales de las palabras
    cout<<"Las iniciales de las palabras son: "<<endl;
    for (int i=0; i<info.num_palabras; i++){
        cout<<**(info.palabras+i)<<" ";
    }
    cout<<endl<<endl;
}
/***************************************************************************/
/***************************************************************************/