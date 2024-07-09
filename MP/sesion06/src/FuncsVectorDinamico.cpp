/***************************************************************************/
//Declaración de Funciones de tratamiento de VectoresDinámicos.
//
//Archivo de implementacion
//
// Fichero: FuncsVectorDinamico.cpp
/***************************************************************************/


#include "FuncsVectorDinamico.h"
#include "ProcesamientoArray.h"
using namespace std;

typedef int T;
///////////////////////////////////////////////////////////////////////////////
/*Es el "constructor" de los datos VectorDinamico. Devuelve un VectorDinamico
Parametros:
    - cap_inic: capacidad inicial del vector (por defecto, TAM_INICIAL)
    - tipo: tipo de redimensionamiento (por defecto, Bloque)
*/
VectorDinamico CreaVectorDinamico (int cap_inic, TipoRedimension tipo){
    
    VectorDinamico v;

    //Inicializa los atributos el nuevo VectorDinamico
    v.datos= new T [cap_inic];   //reserva cap_inic casillas de T
    v.capacidad=cap_inic;
    v.usados=0;     //inicialmente está vacío
    v.tipo_redim=tipo;

    return v;
}


///////////////////////////////////////////////////////////////////////////////
/*Inicializa el vector dinámico, sustituyendo el contenido de todas las 
casillas usadas por el valor "valor".
Parametros:
    - v: vector dinámico a rellenar
    - valor: valor a almacenar en todas las casillas
*/
void EcualizaVectorDinamico (VectorDinamico & v, const T valor){
    for (int i = 0; i < v.usados; i++) {
        ValorVectorDinamico(v,i) = valor;
    }
}


///////////////////////////////////////////////////////////////////////////////
/*Hace una copia profunda de origen en destino.
Parametros:
    - destino: vector dinámico en el que se copiará
    - origen: vector dinámico a copiar
*NOTA: origen no puede ser const para que se pueda usar la funcion sobre un 
mismo vector. De lo contrario, no se modificarán los datos de origen, por lo que
es seguro.
*/

//ARREGLAR: NO PERMITIR QUE DESTINO=ORIGEN
void ClonaVectorDinamico (VectorDinamico & destino, VectorDinamico & origen){
    
    T * ptr_datos=origen.datos; //puntero a los datos de origen

    bool autoasignacion=false;  //comprueba si se está autoasignando
    if (&destino==&origen)
        autoasignacion=true;
    else
        delete [] destino.datos;
    

    destino=origen; //copia superficial de origen en destino

    //reservo memoria dinamica para los datos de destino
    destino.datos= new T [origen.capacidad];

    //copia profunda de los datos de origen en destino
    memcpy(destino.datos, ptr_datos, sizeof(T)*origen.usados);

    if (autoasignacion)
        delete [] ptr_datos; //libera la memoria inicial de origen
}


///////////////////////////////////////////////////////////////////////////////
/*Libera la memoria dinámica reservada para los datos de un vector dinámico.
Lo deja inutilizable, borrando el acceso a los datos.
Parametros:
    - v: vector dinámico a destruir
*/
void DestruyeVectorDinamico (VectorDinamico &v){

    delete [] v.datos;   //libera las casillas ocupadas
    v.datos=nullptr;    //borra el acceso a la zona de memoria

    v.capacidad=0;  //vuelve a estar vacío
    v.usados=0;

}


///////////////////////////////////////////////////////////////////////////////
/*Elimina, a nivel usuario, todos los datos del vector dinámico, 
pero mantiene la capacidad.
Parametros:
    - v: vector dinámico a vaciar
*/
void EliminaTodosVectorDinamico (VectorDinamico & v){

    v.usados=0;     //vacía el vector a nivel superficial
}


///////////////////////////////////////////////////////////////////////////////
/*Reajusta la capacidad del vector dinámico a la cantidad de casillas usadas
para que no haya espacio libre.
Parametros:
    - v: vector dinámico a reajustar
*/
void ReajustaVectorDinamico (VectorDinamico &v){
    
    v.capacidad=v.usados;
    
    ClonaVectorDinamico(v,v);
}


///////////////////////////////////////////////////////////////////////////////
/*
Redimensiona un vector dinámico de acuerdo al tipo de redimensión registrado 
en el dato VectorDinamico.
Parametros:
    - v: vector dinámico a redimensionar
*/
void RedimensionaVectorDinamico (VectorDinamico &v){

    //Actualiza el atributo capacidad en funcion del tipo de redimensión
    if (v.tipo_redim==TipoRedimension::Unitario)
        v.capacidad++;              //Aniade una casilla
    
    else if (v.tipo_redim==TipoRedimension::Bloque)
        v.capacidad+=TAM_BLOQUE;    //Aniade un bloque de TAM_BLOQUE casillas
    
    else if (v.tipo_redim==TipoRedimension::Doble)
        v.capacidad*=2;             //Duplica la capacidad

    //Actualiza la capacidad práctica en funcion del atributo capacidad
    ClonaVectorDinamico(v,v);
}


///////////////////////////////////////////////////////////////////////////////
/*Inserta un valor en una posición dada. Los valores que están desde esa 
posición (incluida) hasta la última se “desplazan” una posición hacia índices 
mayores. 
Si el vector dinámico estuviera lleno se tiene que redimensionar (de acuerdo 
al tipo de redimensión establecido) para poder acoger al nuevo valor
Parametros:
    - v: vector dinámico a modificar
    - valor: valor a añadir
    - num_casilla: posición donde se añadirá el valor
PRE: 0<=num_casilla<UsadosVectorDinamico(v)
*/
void InsertaVectorDinamico (VectorDinamico &v, const T valor,\
                            const int num_casilla){
    
    if (num_casilla<=v.usados){

        if (v.usados==v.capacidad)
            RedimensionaVectorDinamico(v);

        memmove(v.datos+num_casilla+1, v.datos+num_casilla, \
                sizeof(T)*(v.usados-(num_casilla)));

        ValorVectorDinamico(v, num_casilla)=valor;

        v.usados++;
    }
}


///////////////////////////////////////////////////////////////////////////////
/*Añade un valor al final del vector dinámico. Si el vector
dinámico estuviera lleno se tiene que redimensionar (de acuerdo al tipo de
redimensión establecido) para poder acoger al nuevo valor.
Parametros:
    - v: vector dinámico a modificar
    - valor: valor a añadir
*/
void AniadeVectorDinamico (VectorDinamico &v, const T valor){

    if (v.usados==v.capacidad)  //Garantiza la disponibilidad de espacio
        RedimensionaVectorDinamico(v);

    *(v.datos+v.usados)=valor;  //Aniade el dato en la ultima posicion
    v.usados++;
}


///////////////////////////////////////////////////////////////////////////////
/*Elimina un valor en una posición dada. Los valores que están desde 
la posición siguiente a la dada hasta la última se “desplazan” una posición 
hacia índices menores.
Parametros:
    - v: vector dinámico a modificar
    - num_casilla: posición donde se eliminará el valor
PRE: 0<=num_casilla<UsadosVectorDinamico(v)
*/
void EliminaVectorDinamico (VectorDinamico & v, const int num_casilla){

    if (num_casilla<v.usados){

        memmove(v.datos+num_casilla, v.datos+num_casilla+1, \
                sizeof(T)*(v.usados-(num_casilla+1)));

        v.usados--;
    }
}


///////////////////////////////////////////////////////////////////////////////
/*Crea un string que contiene los valores del vector dinámico. 
El objetivo es conseguir un formato agradable y compacto para poder
mostrar/transmitir el contenido del vector.
Parametros:
    - v: vector dinámico a serializar.
*/
string ToString ( /*const*/ VectorDinamico & v){

    string cad;

	cad += "Capacidad = " + to_string(v.capacidad); 
	cad += "  Ocupadas  = " + to_string(v.usados) + "\n";

	if (v.usados > 0)  {

		cad += "Valores almacenados en el vector: \n"; 

		cad += "[ ";

		for (int i=0; i<v.usados-1; i++) 
			cad += to_string(ValorVectorDinamico(v, i)) + ", "; 

		cad += to_string(ValorVectorDinamico (v, v.usados-1)); 
		cad += " ]";
	}
	else 
		cad += "Vector vacio";

	cad += "\n\n";

	return (cad);
}


///////////////////////////////////////////////////////////////////////////////
/*
Si se utiliza como rvalue se usa para consultar el valor de la casilla. 
Si se utiliza como lvalue se usa para modificar el valor de la casilla.
Se establece la precondición:
Parametros:
    - v: vector dinámico a consultar
    - num_casilla: casilla a consultar
PRE: 0<=num_casilla<UsadosVectorDinamico(v)
*/
T & ValorVectorDinamico (VectorDinamico & v, const int num_casilla){

    T &valor=*(v.datos+num_casilla); //referencia a la casilla.

    return valor;
}


///////////////////////////////////////////////////////////////////////////////
/* Devuelve el número de casillas usadas en un vector dinámico 
(el valor del campo usados).
Parametros:
    - v: vector dinámico a consultar
*/
int UsadosVectorDinamico (const VectorDinamico & v){

    return v.usados;
}


///////////////////////////////////////////////////////////////////////////////
/* Devuelve el número de casillas usadas en un vector dinámico 
(el valor del campo usados).
Parametros:
    - v: vector dinámico a consultar
*/
int CapacidadVectorDinamico (const VectorDinamico & v){

    return v.capacidad;
}


///////////////////////////////////////////////////////////////////////////////
/*. Devuelve true si el vector dinámico está vacío (no tiene datos).
Parametros:
    - v: vector dinámico a consultar
*/
bool EstaVacioVectorDinamico (const VectorDinamico & v){
    
    return v.usados==0;
}


///////////////////////////////////////////////////////////////////////////////
/*
Dos Algoritmos para eliminar los elementos repetidos de un VectorDinamico:
0) Borrado “físico”, con desplazamientos. Si una componente está repetida, 
se borrará del vector.
1) Algoritmo de los dos apuntadores. Usaremos dos variables, pos_lectura y 
pos_escritura, que van indicando, en cada momento, la posición del dato que
se está leyendo y el sitio dónde tiene que escribirse.

Parametros:
    - v: vector dinámico a modificar
    - algoritmo: si es 0, tiene lugar el primer algoritmo, y si es 1, el segundo
                por defecto es 0;
*/
void EliminaRepetidosVectorDinamico(VectorDinamico &v, int algoritmo){

    if (algoritmo==0){

        for (int i=0; i<v.usados; i++){

            //Para cada elemento, recorre el subvector restante
            //para eliminar los duplicados
            for (int j=i+1; j<v.usados; j++){

                if (ValorVectorDinamico(v,i)==ValorVectorDinamico(v,j)){

                    EliminaVectorDinamico(v,j);
                    j--;
                }
            }
        }

    }else if (algoritmo==1){
        
        v.usados=remove_duplicates(v.datos,v.usados);
    }
    
    ReajustaVectorDinamico(v);
}









