/***************************************************************************/
//Metodología de la Programación
//
//30. Modificar el proyecto realizado en el ejercicio 29 de manera que ahora 
//las funciones de mezcla quedan resumidas en una única función:
//  void MezclaVectores (int mezcla[], int &util_mezcla, int v1[], int util_v1,
//                       int v2[], int util_v2,const char * selectiva = "no");
//de manera que:
//• La referencia util_mezcla proporciona el número de casillas útiles de mezcla
//• El parámetro (opcional, con valor por defecto) selectiva indica a la 
//función si debe realizar una mezcla selectiva o no. El valor por defecto es no
// • La función realizará una ordenación selectiva si se llama con los valores 
//si, SI, Si ó sI. La mezcla será completa si se llama con cualquier otro valor 
//
//Archivo main
//
// Fichero: I_MezclaArrays_ref.cpp.
/***************************************************************************/

#include <iostream>

#include "GeneradorAleatorioEnteros.h"
#include "ProcesamientoArrayInt.h"

using namespace std;

/*****************************************************************************/
/*****************************************************************************/

int main(int argc,char *argv[]){
    const int TAM=100;
    int vector1[TAM];
    int vector2[TAM];
    int mezcla_simple[TAM*2];
    int mezcla_union[TAM*2];
    int tam_mezcla;
    int &util_mezcla=tam_mezcla;
    int utilv;
    int min_aleat;
    int max_aleat;

    if (argc==1){
        //Si el programa se ejecuta sin argumentos, los dos vectores de entrada 
        //se ocuparán completamente (TAM casillas) y se rellenarán, 
        //con valores aleatorios entre 1 y 200 (ambos incluidos).
        //*******************************************************************

        utilv=TAM;
        min_aleat=1;
        max_aleat=200;

    }else if (argc==2 && atoi(argv[1])>0){
        //Si el programa se ejecuta con un argumento, los dos vectores de
        //entrada se ocuparán parcialmente. El número de casillas ocupadas en  
        //ambos vectores será el valor que indiquemos con el único parámetro. 
        //Se generarán valores aleatorios entre 1 y 200 (ambos incluidos). 
        //*******************************************************************

        utilv=atoi(argv[1]);
        min_aleat=1;
        max_aleat=200;

    }else if (argc==3 && atoi(argv[1]) > 0 && atoi(argv[2]) > 1){
        //• Si se ejecuta con dos argumentos, los dos vectores de entrada se 
        //ocuparán parcialmente. El número de casillas ocupadas en ambos  
        //vectores será el valor que indiquemos en el primer argumento.  
        //El segundo argumento indica el mayor valor aleatorio permitido, por 
        //lo que se generarán valores aleatorios entre 1 y ese valor.
        //*******************************************************************

        utilv=atoi(argv[1]);
        min_aleat=1;
        max_aleat=atoi(argv[2]);

    }else if (argc==4 && atoi(argv[1]) > 0 && atoi(argv[3]) > atoi(argv[2])){
        //• Si se ejecuta con tres argumentos, los dos vectores de entrada se
        //ocuparán parcialmente. El número de casillas ocupadas en ambos 
        //vectores será el valor que indiquemos en el primer argumento.
        //Los otros dos argumentos indican el menor y mayor valor aleatorio
        //permitido (no necesariamente en este orden).
        //*******************************************************************
        
        utilv=atoi(argv[1]);
        min_aleat=atoi(argv[2]);
        max_aleat=atoi(argv[3]);
        if (min_aleat>max_aleat)
            swap_int(&min_aleat,&max_aleat);

    }else{
        exit(1);    //codigo de error 1
    }

    //***********************************************************************
    //Rellenamos los dos vectores con valores aleatorios
    //***********************************************************************
    random_fill_array(vector1,utilv,min_aleat,max_aleat);
    random_fill_array(vector2,utilv,min_aleat,max_aleat);


    //***********************************************************************
    //Ordenamos los dos vectores
    //***********************************************************************
    bubble_sort(vector1,utilv);
    bubble_sort(vector2,utilv);


    //***********************************************************************
    //Mostramos los dos vectores ordenados
    //***********************************************************************
    print_array_int(vector1,utilv,10,"Vector 1 ordenado");
    print_array_int(vector2,utilv,10,"Vector 2 ordenado");


    cout<<"............................................................."<<endl;
    //***********************************************************************
    //Mezclamos los dos vectores con repeticiones
    //***********************************************************************
    MezclaVectores(mezcla_simple, util_mezcla, \
                    vector1, utilv, vector2, utilv, "no");

    //***********************************************************************
    //Mostramos el vector mezcla con repeticiones
    //***********************************************************************
    print_array_int(mezcla_simple,util_mezcla,10,"Vector mezcla");

    //***********************************************************************
    //Mezclamos los dos vectores sin repeticiones
    //***********************************************************************
    MezclaVectores(mezcla_union, util_mezcla, \
                   vector1, utilv, vector2, utilv, "si");

    //***********************************************************************
    //Mostramos el vector mezcla sin repeticiones
    //***********************************************************************
    print_array_int\
    (mezcla_union,util_mezcla,10,"Vector mezcla sin repeticiones");

    return 0;
}

/*****************************************************************************/
/*****************************************************************************/