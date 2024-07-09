/*8. En este ejercicio se combinan las soluciones de los ejercicios 4 y 7.
Con estas declaraciones:
    const int TOPE = 100;
    int v1 [TOPE], int v2 [TOPE], int res [2*TOPE];
    int tam_v1, tam_v2; // 0 <= tam_v1, tam_v2 < TOPE
    int tam_res; // 0 <= tam_res < 2*TOPE
Escriba un programa que pida el número de casillas que se van a ocupar de los vectores v1 y v2,
los rellene aleatoriamente (completamente o una parte, pero siempre desde el principio), 
los ordene y finalmente los mezcle sobre el vector res.
Considere todas las situaciones de error que puedan ocurrir y busque soluciones razonables antes que 
abortar la ejecución del programa. Use funciones (al menos para mostrar, ordenar y mezclar los vectores).*/

#include <iostream>


#include "GeneradorAleatorioEnteros.h"
#include "ProcesamientoArrayInt.h"

using namespace std;

int main(){
    const int TOPE = 100;
    int v1 [TOPE], v2 [TOPE], res [2*TOPE];
    int tam_v1, tam_v2; // 0 <= tam_v1, tam_v2 < TOPE
    int tam_res; // 0 <= tam_res < 2*TOPE
    
    //datos de entrada
    
    do{//nº elementos v1
        cout<<"Con cuantos enteros aleatorios desea rellenar el primer vector? (max 100)"<<endl;
        cin>>tam_v1;
        if (tam_v1>TOPE||tam_v1<=0)
            cout<<"dato proporcionado incompatible, vuelva a introducirlo."<<endl;
    }while(tam_v1>TOPE||tam_v1<=0);

    do{//nº elementos v2
        cout<<"Con cuantos enteros aleatorios desea rellenar el segundo vector? (max 100)"<<endl;
        cin>>tam_v2;
        if (tam_v2>TOPE||tam_v2<=0)
            cout<<"dato proporcionado incompatible, vuelva a introducirlo."<<endl;
    }while(tam_v2>TOPE||tam_v2<=0);
    
    tam_res=tam_v1+tam_v2;

    RellenaVector(v1,tam_v1,0,100);
    MuestraVector("Primer Vector: ", v1, tam_v1, tam_v1);

    RellenaVector(v2,tam_v2,0,100);
    MuestraVector("Segundo Vector: ", v2, tam_v2, tam_v2);
    
    OrdenaSeleccion(v1,0,tam_v1-1);
    OrdenaSeleccion(v2,0,tam_v2-1);
    MezclaVector(v1,v2,res,tam_v1,tam_v2,tam_res);
    MuestraVector("Vector Mezcla del primer y segundo vector (ordenado):",res,tam_res,tam_res);
    
}
