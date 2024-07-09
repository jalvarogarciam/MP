/***************************************************************************/
//Declaración de Funciones de tratamiento de vectores de enteros.
//
//Archivo de cabecera
//
// Fichero: ProcesamientoArrayInt.h
/***************************************************************************/

#ifndef PROCESAMIENTOARRAYINT
#define PROCESAMIENTOARRAYINT

#include <iomanip>
#include <iostream>

#include "GeneradorAleatorioEnteros.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
/*Muestra por terminal el contenido de un vector de enteros con un formato
determinado por setw() y el número de datos por línea.
Parametros:
    - array: puntero al primer elemento del vector
    - num_data: número de datos a mostrar
    - num_data_line: número de datos por línea
    - msg: mensaje a mostrar antes de los datos
*/
void print_array_int\
(int *array, int num_data, int num_data_line=0, const char *msg="");


///////////////////////////////////////////////////////////////////////////////
/*Intercambia el contenido de dos variables enteras a y b.
*/
void swap_int(int *a , int *b);


///////////////////////////////////////////////////////////////////////////////
/*Rellena un vector de enteros con números aleatorios en un rango determinado.
Parametros:
    - array: puntero al primer elemento del vector
    - num_data: número de datos a rellenar
    - min_rand: valor mínimo del rango
    - max_rand: valor máximo del rango
PRE: min_rand <= max_rand
PRE: num_data > 0
*/
int *random_fill_array (int *array, int num_data, int min_rand, int max_rand);


///////////////////////////////////////////////////////////////////////////////
/*Copia el contenido de un vector de enteros en otro.
Parametros:
    - p_original: puntero al primer elemento del vector original
    - p_copy: puntero al primer elemento del vector copia
    - num_data: número de datos a copiar
PRE: num_data > 0
*/
int *copy_array(int *p_copy, int *p_original, int num_data);


///////////////////////////////////////////////////////////////////////////////
/*Elimina un entero de un vector de enteros.
Parametros:
    - array: puntero al primer elemento del vector
    - index: posición del entero a eliminar
    - size: número de datos del vector
*/
void remove_int(int * array, int index, int size);

///////////////////////////////////////////////////////////////////////////////
/*Busca un entero en un vector de enteros y devuelve un puntero a su posición.
Parametros:
    - integer: entero a buscar
    - array: puntero al primer elemento del vector
    - array_size: número de datos del vector
    - init_pos: posición inicial del subconjunto a buscar
    - last_pos: posición final del subconjunto a buscar
PRE: init_pos >= 0
PRE: last_pos < size
*/
int * search\
(int integer, int *array, int array_size, int init_pos=0, int last_pos=0);


///////////////////////////////////////////////////////////////////////////////
/*Elimina los elementos duplicados de un vector de enteros.
Parametros:
    - array: puntero al primer elemento del vector
    - size: número de datos del vector
*/
int remove_duplicates(int * array, int size);


///////////////////////////////////////////////////////////////////////////////
/*Suma el contenido de dos vectores de enteros y lo almacena en un tercero.
Parametros:
    - v1: puntero al primer elemento del primer vector
    - v2: puntero al primer elemento del segundo vector
    - res: puntero al primer elemento del vector resultante
    - v1_size: número de datos del primer vector
    - v2_size: número de datos del segundo vector
PRE: tener reservada memoria para el vector res al menos >=v1_size+v2_size
*/
int mix_array\
(int *res, int *v1, int v1_size, int *v2, int v2_size);


///////////////////////////////////////////////////////////////////////////////
/*Mezcla de forma ordenada el contenido de dos vectores de enteros en un 
tercero, eliminando los elementos repetidos.
Parametros:
    - v1: puntero al primer elemento del primer vector
    - v2: puntero al primer elemento del segundo vector
    - res: puntero al primer elemento del vector resultante
    - v1_size: número de datos del primer vector
    - v2_size: número de datos del segundo vector
PRE: tener reservada memoria para el vector res al menos >=v1_size+v2_size
*/
//ES IGUAL QUE MezclaVectoresSelectiva(int mezcla[], int v1[]...) (ejercicio 29)
int mix_array_union(int *res, int *v1, int v1_size, int *v2, int v2_size);


///////////////////////////////////////////////////////////////////////////////
/*Ordena un vector de enteros mediante el algoritmo de selección.
Parametros:
    - v: puntero al primer elemento del vector
    - init_pos: posición inicial del subconjunto a ordenar
    - last_pos: posición final del subconjunto a ordenar
PRE: init_pos >= 0
PRE: last_pos < size
*/
int * selection_sort(int *v, int init_pos, int last_pos);


///////////////////////////////////////////////////////////////////////////////
/*Ordena un vector de enteros mediante el algoritmo de selección.
Parametros:
    - v: puntero al primer elemento del vector
    - size: número de datos a ordenar
PRE: size > 0
*/
int * selection_sort(int *v, int size);


///////////////////////////////////////////////////////////////////////////////
/*Ordena un vector de enteros mediante el algoritmo de burbuja.
Parametros:
    - v: puntero al primer elemento del vector
    - init_pos: posición inicial del subconjunto a ordenar
    - last_pos: posición final del subconjunto a ordenar
PRE: init_pos >= 0
PRE: last_pos < size
*/
int * bubble_sort(int *v, int init_pos, int last_pos);


///////////////////////////////////////////////////////////////////////////////
/*Ordena un vector de enteros mediante el algoritmo de burbuja.
Parametros:
    - v: puntero al primer elemento del vector
    - size: número de datos a ordenar
PRE: size > 0
*/
int * bubble_sort(int *v, int size);


///////////////////////////////////////////////////////////////////////////////
/*Ordena un vector de enteros mediante el algoritmo de inserción.
Parametros:
    - v: puntero al primer elemento del vector
    - init_pos: posición inicial del subconjunto a ordenar
    - last_pos: posición final del subconjunto a ordenar
PRE: init_pos >= 0
PRE: last_pos < size

*/
int * insertion_sort(int *v, int init_pos, int last_pos);


///////////////////////////////////////////////////////////////////////////////
/*Ordena un vector de enteros mediante el algoritmo de inserción.
Parametros:
    - v: puntero al primer elemento del vector
    - size: número de datos a ordenar
PRE: size > 0
*/
int * insertion_sort(int *v, int size);


///////////////////////////////////////////////////////////////////////////////
/*Engloba las funciones mix_array y mix_array_union en una sola función.
Parametros:
    - mezcla: puntero al primer elemento del vector resultante
    - util_mezcla: número de datos del vector resultante
    - v1: puntero al primer elemento del primer vector
    - util_v1: número de datos del primer vector
    - v2: puntero al primer elemento del segundo vector
    - util_v2: número de datos del segundo vector
    - selectiva: indica si se deben eliminar los elementos repetidos
PRE: util_mezcla >= util_v1 + util_v2
*/
void MezclaVectores (int mezcla[], int &util_mezcla,\
                    int v1[], int util_v1, int v2[], int util_v2,\
                    const char * selectiva = "no");

#endif