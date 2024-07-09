/*6.Escribir una función que recibe un vector de números enteros y dos valores enteros
(que indican las posiciones de los extremos de un intervalo sobre ese vector). 
La función devuelve un puntero al elemento mayor dentro de ese intervalo.
La función tendrá como prototipo:
    int * Maximo (int *pv, int izda, int dcha);
donde pv contiene la dirección de memoria de una casilla del vector e izda y dcha
son los extremos del intervalo entre los que se realiza la búsqueda del elemento mayor.
Considere la siguiente declaración:
    const int TOPE = 100;
    int vector [TOPE];
Escriba un programa que rellene aleatoriamente el vector (completamente o una parte, pero siempre desde el principio) 
y que calcule el mayor valor entre dos posiciones dadas. El programa pedirá:
    a) el número de casillas que se van a rellenear con números aleatorios,
    b) las posiciones entre las que se va a calcular el mayor valor.
Considere todas las situaciones de error que puedan ocurrir y busque soluciones razonables antes que abortar la ejecución del programa*/
#include <iostream>

#include "GeneradorAleatorioEnteros.cpp"
#include "ProcesamientoArrayInt.h"

using namespace std;

int * Maximo (int *pv, int izda, int dcha){//es una función que solo uso en este ejercicio, por lo que no la añado a "ProcesamientoArrayInt.cpp"
    int *entero_mayor=pv+izda;
    int *const p_dcha=pv+dcha;
    while(pv<=p_dcha){
        if (*pv>*entero_mayor)
            entero_mayor=pv;
        pv++;
    }
    return entero_mayor;
}

int main(){
    const int TOPE = 100;
    int vector [TOPE];
    int *pv=vector;
    GeneradorAleatorioEnteros entero_aleatorio(-100, 100);
    int izda,dcha,tamanio;
    int *p_maximo_entero;

    //datos de entrada
    do{
        cout<<"Con cuantos enteros aleatorios desea rellenar el vector? (max 100)"<<endl;
        cin>>tamanio;
        if (tamanio>TOPE||tamanio<=0)
            cout<<"dato proporcionado incompatible, vuelva a introducirlo."<<endl;
    }while(tamanio>TOPE||tamanio<=0);
    cout<<endl;
    
    
    //genero el vector
    RellenaVector(vector,tamanio,-100,100);//mezclo esta parte con los datos de entrada porque el usuario debe ver el vector para decidir donde lo quiere ordenar
    
    MuestraVector("Los elementos de su vector son los siguientes: ", vector, tamanio, tamanio);
    cout<<endl;
    
    do{
        cout<<"Cual es la posicion inicial a partir de la cual desea analizar el vector segun el criterio establecido?"<<endl;
        cin>>izda;
        if (izda<0||izda>=tamanio-1)
            cout<<"dato proporcionado incompatible, vuelva a introducirlo."<<endl;
    }while(izda<0||izda>=tamanio-1);
    do{
        cout<<"Cual es la posicion final hasta la que desea analizar el vector segun el criterio establecido?"<<endl;
        cin>>dcha;
        if (dcha<=izda||dcha>tamanio-1)
            cout<<"dato proporcionado incompatible, vuelva a introducirlo."<<endl;
    }while(dcha<=izda||dcha>tamanio-1);
    

    //calculo el mayor
    p_maximo_entero=Maximo(vector,izda,dcha);
    pv=vector;
    

    cout<<"el maximo valor del vector de enteros aleatorios entre la posicion "<<\
        izda<<" y la posicion "<<dcha<<" es "<<*p_maximo_entero<<endl;

}
