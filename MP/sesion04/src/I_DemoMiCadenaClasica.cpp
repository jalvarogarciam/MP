/***************************************************************************/
//Metodología de la Programación
//
/*Ejercicio 23: Escribir un programa que lea una serie indeterminada de líneas 
(finaliza cuando lee una línea que contiene únicamente FIN).
El programa mostrará para cada línea leida:
• las dos mitades de cada cadena. Cada mitad se obtendrá al aplicar la 
función descrita en el ejercicio 19, y
• el resultado de aplicar las funciones escritas en el ejercicio 20.
    Importante: La cadena leida no se modificará por lo que necesitará realizar 
    copias (use la función de copia propuesta en el ejercicio 17).
Finalmente indicará el porcentaje de separadores presentes en el texto 
original completo. Realice este cálculo en la función main sin recorrer, 
casilla a casilla, las cadenas leidas.
*/
//Archivo main
//
// Fichero: I_DemoMiCadenaClasica.cpp
/***************************************************************************/
#include <iostream>
#include "MiCadenaClasica.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/
int main(){
    const int NUM_LINEAS=100;
    const int TAM_LINEAS=100;
    //reservo memoria para no acceder a zonas erroneas
    char texto[NUM_LINEAS][TAM_LINEAS];
    char cp_linea[TAM_LINEAS];         
    unsigned int total_caracteres=0;
    unsigned int num_caracteres_sin_sep=0;
    //puntero a cadenas de caracteres de tamaño TAM_LINEAS
    char (*p_texto)[TAM_LINEAS]=texto;
    char (*p_linea)[TAM_LINEAS]=p_texto-1;

    //.......................................................................
	// Lectura y filtrado de los valores criticos
    cout << "Introduce lineas de texto (maximo 100 lineas de 100 caracteres "\
    <<"cada una)."<<endl<<"Escribe FIN para terminar."<<endl;
    do{
        p_linea++;
        cin.getline(*p_linea,TAM_LINEAS);
    }while(chaincmp(*p_linea,"FIN")!=0 && chainlen(*p_linea)<=TAM_LINEAS-1);


    //.......................................................................
	// Muestreo de la información que se pide.
    while (chaincmp(*p_texto,"FIN")!=0){
        int mitad_cadena=int(chainlen(*p_texto)/2)-1;
        int longitud_cadena=chainlen(*p_texto);

	    // Primera parte: DIVISIÓN DE LA CADENA EN MITADES.--------------------
        cout<<"-----------------------LINEA"<<p_texto+1-texto\
        <<"----------------------------"<<endl;

        cout<<"\""<<*p_texto<<"\""<<endl;
       
        cout<<"primera mitad de la linea: "\
        <<extraer_subcadena(cp_linea,*p_texto,0,mitad_cadena)<<endl;
        
        cout<<"segunda mitad de la linea: "
        <<extraer_subcadena(cp_linea,*p_texto,mitad_cadena+1,longitud_cadena)\
        <<endl;


        // Segunda parte: ELIMINACIÓN DE SEPARADORES.--------------------------
        cout<<"     ...............................................     "<<endl;

        cout<<"Cadena sin blancos iniciales: "<<endl\
        <<'.'<<eliminar_blancos_iniciales(cp_linea,*(p_texto))<<"."<<endl;

        cout<<"Cadena sin blancos finales: "<<endl\
        <<'.'<<eliminar_blancos_finales(cp_linea,*p_texto)<<"."<<endl;

        cout<<"Cadena sin blancos extremos: "
        <<'.'<<eliminar_blancos_extremos(cp_linea,*p_texto)<<"."<<endl;

        cout<<"Cadena sin blancos intermedios: "
        <<'.'<<eliminar_blancos_intermedios(cp_linea,*p_texto)<<"."<<endl;
        
        cout<<"Cadena sin blancos: "
        <<'.'<<eliminar_todos_blancos(cp_linea,*p_texto)<<"."<<endl<<endl;

        //registro de la proporción de separadores-----------------------------
        total_caracteres+=chainlen(*p_texto);
        num_caracteres_sin_sep+=chainlen(cp_linea);
        p_texto++;
    }

        //Tercera parte: PORCENTAJE DE SEPARADORES PRESENTES EN EL TEXTO-------
    cout<<"-------------------------------------------------------"<<endl<<endl;
    cout<<"Porcentaje de separadores presentes en el texto original completo: "\
    <<(total_caracteres-num_caracteres_sin_sep)*100/total_caracteres<<"%"<<endl;
}
/***************************************************************************/
/***************************************************************************/