/*7. Escriba un programa que rellene aleatoriamente un vector 
(completamente o una parte, pero siempre desde el principio) y 
lo ordene (usando los tres algoritmos conocidos)
entre dos posiciones dadas. El programa pedirá:
    a) el número de casillas que se van a rellenear con números aleatorios,
    b) las posiciones entre las que se va a ordenar el vector.                 
Considere todas las situaciones de error que puedan ocurrir y busque 
soluciones razonables antes que abortar la ejecución del programa.
Implemente tres funciones para la ordenación:
void OrdenaSeleccion (int *v, int pos_inic, int pos_fin);
void OrdenaInsercion (int *v, int pos_inic, int pos_fin);
void OrdenaIntercambio (int *v, int pos_inic, int pos_fin);
*/

#include <iostream>

#include "GeneradorAleatorioEnteros.cpp"
#include "ProcesamientoArrayInt.h"

using namespace std;


int main(){
    const int TOPE = 100;
    int vector [TOPE];
    GeneradorAleatorioEnteros entero_aleatorio(-100, 100);
    int izda,dcha,tamanio;

    //datos de entrada
    do{
        cout<<"Con cuantos enteros aleatorios desea rellenar el vector? \
        (max 100)"<<endl;
        cin>>tamanio;
        if (tamanio>TOPE||tamanio<=0)
            cout<<"dato proporcionado incompatible, vuelva a introducirlo."\
            <<endl;
    }while(tamanio>TOPE||tamanio<=0);
    cout<<endl;
    
    //mezclo esta parte con los datos de entrada porque el usuario debe ver el vector para decidir donde lo quiere ordenar
    //genero el vector
    RellenaVector(vector,tamanio,0,100);//he decidido que sea entre 0 y 100 (no lo pregunta)
    MuestraVector("vector original: ",vector,tamanio,tamanio);
    
    do{
        cout<<"Cual es la posicion a partir de la cual desea ordenar el vector"<<endl;
        cin>>izda;
        if (izda<0||izda>=tamanio-1)
            cout<<"dato proporcionado incompatible, vuelva a introducirlo."<<endl;
    }while(izda<0||izda>=tamanio-1);
    do{
        cout<<"Cual es la posicion hasta la que desea ordenar el vector"<<endl;
        cin>>dcha;
        if (dcha<=izda||dcha>tamanio-1)
            cout<<"dato proporcionado incompatible, vuelva a introducirlo."<<endl;
    }while(dcha<=izda||dcha>tamanio-1);


    int vector_selec[100];
    CopiaVector(vector,vector_selec,100);
    OrdenaSeleccion(vector_selec,izda,dcha);
    MuestraVector("Ordenacion por seleccion: ",vector_selec,tamanio,tamanio);
    cout<<endl;

    int vector_inter[100];
    CopiaVector(vector,vector_inter,100);
    OrdenaIntercambio(vector_inter,izda,dcha);
    MuestraVector("Ordenacion por intercambio: ",vector_inter,tamanio,tamanio);
    cout<<endl;
    
    int vector_inser[100];
    CopiaVector(vector,vector_inser,100);
    OrdenaInsercion(vector_inser,izda,dcha);
    MuestraVector("Ordenacion por insercion: ",vector_inser,tamanio,tamanio);
    cout<<endl;
}
