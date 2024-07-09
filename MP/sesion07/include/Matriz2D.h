/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// 1º GRADO EN INGENIERÍA INFORMÁTICA, GRUPO B1
//
// JOSÉ ÁLVARO GARCÍA MÁRQUEZ
//
// Archivo de cabeceras de las funciones de gestión de matrices dinámicas de 
// tipo TipoBase (T);
//
// Fichero: Matriz2D.h
//
/***************************************************************************/

#ifndef MATRIZ2D
#define MATRIZ2D

#include "TipoBase.h"
#include <string>
using namespace std;


///////////////////////////////////////////////////////////////////////////////
// Definicion de la estructura Matriz2D
///////////////////////////////////////////////////////////////////////////////
typedef struct {

    T ** datos;     // Puntero a vector de punteros a los datos
    int fils;       // Numero de filas
    int cols;       // Numero de columnas

} Matriz2D;
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// Declaracion de funciones auxiliares
///////////////////////////////////////////////////////////////////////////////

/*****************************************************************************/
/* Crea una matriz dinámica con "nfils" filas y "ncols" cols.
El contenido de las "fils"x"cols" casillas se inicializa a un valor común, 
el indicado en el parámetro "valor"
Parámetros: 
    nfils: número de filas (por defecto 0).
    ncols: número de columnas (por defecto 0).
    valor: valor común inicial (por defecto 0).
Devuelve: un dato de tipo Matriz2D.

PRE: nfils >= 0 && ncols >= 0
*/
Matriz2D CreaMatriz (int nfils=0, int ncols=0, int valor=VALOR_DEF);


/*****************************************************************************/
/* "Destruye" una matriz dinámica y la deja vacía.
Parámetros: 
    matriz (referencia): la matriz que va a "destruirse".
*/
void DestruyeMatriz (Matriz2D & matriz);


/*****************************************************************************/
/*Devuelve el número de filas de la matriz.
*/
int NumFilas (const Matriz2D & matriz);


/*****************************************************************************/
/*Devuelve el número de columnas de la matriz.
*/
int NumColumnas (const Matriz2D & matriz);


/*****************************************************************************/
/*Devuelve true si la matriz está vacía.
*/
bool EstaVacia (const Matriz2D & matriz);


/*****************************************************************************/
/*Descarta todos los valores de la matriz. Deja la matriz en estado “vacía”.
La matriz sigue “activa”. 
Use esta función si tiene previsto seguir usando la matriz.
*/
void EliminaTodos (Matriz2D & matriz);


/*****************************************************************************/
/* Cambia todos los todos valores de la matriz por valor.
Parámetros: 
    matriz (referencia), la matriz que va a modificarse.
    valor, el valor que se va a asignar a todas las casillas de la matriz.
*/
void Ecualiza (Matriz2D & matriz, T valor);


/*****************************************************************************/
/*Devuelve un string con el resultado de “serializar” una matriz.
Parámetros: 
    matriz (referencia), la matriz que va a serializarse.
*/
string ToString (const Matriz2D & matriz);



/*****************************************************************************/
/*Consulta ó modifica el valor de una casilla dada. 
    Si se utiliza como rvalue se emplea para consulta. 
    Si se utiliza como lvalue se emplea para modificación.
Parámetros: 
    matriz (referencia), la matriz. 
	num_fila, número de fila.
	num_columna, número de columna.
PRE: 0<=num_fila<NumFilas(matriz)
PRE: 0<=num_columna<NumColumnas(matrinz)
*/
T & Valor (const Matriz2D & matriz, int num_fila, int num_columna);


/*****************************************************************************/
/*Hace una copia profunda de origen en destino.
Parámetros: 
    destino: la matriz que va a copiarse.
    origen: la matriz que va a copiarse.
PRE: destino se ha inicializado previamente.
*/
void Clona (Matriz2D & destino, const Matriz2D & origen);


/*****************************************************************************/
/*Devuelve true si las matrices son iguales.
Paeámetros: 
    una, otra: las matrices a comparar.
*/
bool SonIguales (const Matriz2D & una, const Matriz2D & otra);


/*****************************************************************************/
/*Elimina la fila numero "index" de la matriz.
*/
void EliminaFila (Matriz2D & matriz, size_t index);


/*****************************************************************************/
/*Elimina la columna numero "index" de la matriz.
*/
void EliminaColumna (Matriz2D & matriz, size_t index);


/*****************************************************************************/
/*
*/
void SubMatriz (Matriz2D & resultado, const Matriz2D & original, \
                int fila_inic, int col_inic, int num_filas, int num_cols);


/*****************************************************************************/
/*Cambia de orden las filas de matriz (la primera
pasa a ser la última y la última la primera, la segunda la penúltima y la
penúltima la segunda, etc.).
Parametros:
    matriz (referencia): la matriz que va a modificarse.
*/
void EspejoHorizontal (Matriz2D & matriz);



/*****************************************************************************/
/*Cambia de orden las columnas de matriz (la primera
pasa a ser la última y la última la primera, la segunda la penúltima y la
penúltima la segunda, etc.).
Parametros:
    matriz (referencia): la matriz que va a modificarse.
*/
void EspejoVertical (Matriz2D & matriz);


#endif

