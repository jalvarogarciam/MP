/***************************************************************************/
//Declaración de Funciones de tratamiento de vectores dinámicos.
//
//Archivo de cabecera
//
// Fichero: FuncsVectorDinamico.h
/***************************************************************************/

#ifndef FUNCSVECTORDINAMICO
#define FUNCSVECTORDINAMICO


#include <cstring>
#include <string>

using namespace std;


///////////////////////////////////////////////////////////////////////////////
//ESTRUCTURA DE DATOS VECTORDINAMICO
///////////////////////////////////////////////////////////////////////////////

// Capacidad inicial
const int TAM_INICIAL = 10;

// Tamanio del bloque para redimensionar (modalidad Bloque)
const int TAM_BLOQUE = 5;

// Tipo de los datos almacenados (en este caso, int)
typedef int T;  //==>he cambiado TipoBase por T

// Tipo enumerado para representar tipos de redimensionamiento
enum class TipoRedimension {Unitario, Bloque, Doble};

typedef struct {
    T * datos; // Puntero para acceder a los datos
    
    int usados; // Num. casillas usadas
    int capacidad; // Num. casillas reservadas

    TipoRedimension tipo_redim; // Modelo de crecimiento

} VectorDinamico;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//METODOS
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/*Es el "constructor" de los datos VectorDinamico.
Parametros:
    - cap_inic: capacidad inicial del vector (por defecto, TAM_INICIAL)
    - tipo: tipo de redimensionamiento (por defecto, Bloque)
*/
VectorDinamico CreaVectorDinamico (int cap_inic=TAM_INICIAL, \
                                  TipoRedimension tipo=TipoRedimension::Bloque);


///////////////////////////////////////////////////////////////////////////////
/*Inicializa el vector dinámico, sustituyendo el contenido de todas las
casillas usadas por el valor "valor".
Parametros:
    - v: vector dinámico a rellenar
    - valor: valor a almacenar en todas las casillas
*/
void EcualizaVectorDinamico (VectorDinamico & v, const T valor);


///////////////////////////////////////////////////////////////////////////////
/*Hace una copia profunda de origen en destino.
Parametros:
    - destino: vector dinámico en el que se copiará
    - origen: vector dinámico a copiar
*NOTA: origen no puede ser const para que se pueda usar la funcion sobre un 
mismo vector. De lo contrario, no se modificarán los datos de origen, por lo que
es seguro.
*/
void ClonaVectorDinamico (VectorDinamico & destino, VectorDinamico & origen);


///////////////////////////////////////////////////////////////////////////////
/*Libera la memoria dinámica reservada para los datos de un vector dinámico.
Lo deja inutilizable, borrando el acceso a los datos.
Parametros:
    - v: vector dinámico a destruir
*/
void DestruyeVectorDinamico (VectorDinamico & v);


///////////////////////////////////////////////////////////////////////////////
/*Elimina, a nivel usuario, todos los datos del vector dinámico, 
pero mantiene la capacidad.
Parametros:
    - v: vector dinámico a vaciar
*/
void EliminaTodosVectorDinamico (VectorDinamico & v);


///////////////////////////////////////////////////////////////////////////////
/*Reajusta la capacidad del vector dinámico a la cantidad de casillas usadas
para que no haya espacio libre.
Parametros:
    - v: vector dinámico a reajustar
*/
void ReajustaVectorDinamico (VectorDinamico &v);


///////////////////////////////////////////////////////////////////////////////
/*
Redimensiona un vector dinámico de acuerdo al tipo de redimensión registrado 
en el dato VectorDinamico.
Parametros:
    - v: vector dinámico a redimensionar
*/
void RedimensionaVectorDinamico (VectorDinamico &v);


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
                            const int num_casilla);


///////////////////////////////////////////////////////////////////////////////
/*Añade un valor al final del vector dinámico. Si el vector
dinámico estuviera lleno se tiene que redimensionar (de acuerdo al tipo de
redimensión establecido) para poder acoger al nuevo valor.
Parametros:
    - v: vector dinámico a modificar
    - valor: valor a añadir
*/
void AniadeVectorDinamico (VectorDinamico &v, const T valor);


///////////////////////////////////////////////////////////////////////////////
/*Elimina un valor en una posición dada. Los valores que están desde la
posición siguiente hasta la última se “desplazan” una posición hacia índices
menores.
Parametros:
    - v: vector dinámico a modificar
    - num_casilla: posición donde se eliminará el valor
PRE: 0<=num_casilla<UsadosVectorDinamico(v)
*/
void EliminaVectorDinamico (VectorDinamico &v, const int num_casilla);


///////////////////////////////////////////////////////////////////////////////
/*Crea un string que contiene los valores del vector dinámico. 
El objetivo es conseguir un formato agradable y compacto para poder
mostrar/transmitir el contenido del vector.
Parametros:
    - v: vector dinámico a serializar.
*/
string ToString ( /*const*/ VectorDinamico & v);


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
T & ValorVectorDinamico (VectorDinamico & v, const int num_casilla);


///////////////////////////////////////////////////////////////////////////////
/* Devuelve el número de casillas usadas en un vector dinámico 
(el valor del campo usados).
Parametros:
    - v: vector dinámico a consultar
*/
int UsadosVectorDinamico (const VectorDinamico & v);


///////////////////////////////////////////////////////////////////////////////
/* Devuelve el número de casillas usadas en un vector dinámico 
(el valor del campo usados).
Parametros:
    - v: vector dinámico a consultar
*/
int CapacidadVectorDinamico (const VectorDinamico & v);


///////////////////////////////////////////////////////////////////////////////
/*. Devuelve true si el vector dinámico está vacío (no tiene datos).
Parametros:
    - v: vector dinámico a consultar
*/
bool EstaVacioVectorDinamico (const VectorDinamico & v);


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
void EliminaRepetidosVectorDinamico(VectorDinamico &v, int algoritmo=0);


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



#endif