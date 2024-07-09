/***************************************************************************/
//Declaración de Funciones relacionadas con el tratamiento de vectores de enteros.
//Archivo de cabecera
// Fichero: ProcesamientoArrayInt.h
/***************************************************************************/

#include <iomanip>
#include <iostream>

#include "GeneradorAleatorioEnteros.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////
/*Muestra el mensaje "msg\n" a continuación del vector/matriz.
int *p=dirección de memoria del primer elemento
int num_datos= cantidad de elementos total
num_datos_linea= numero de datos mostrados por linea */
void MuestraVector (const char *msg, int *p, int num_datos, int num_datos_linea);

//////////////////////////////////////////////////////////////////////////////////////
/*Versión abreviada de MuestraVector. Solo requiere el puntero al primer elemento del 
vector y la cantidad de elementos.
int *p=dirección de memoria del primer elemento
int num_datos= cantidad de elementosto total
*/
void MuestraVector (int *p, int num_datos);

//////////////////////////////////////////////////////////////////////////////////////
/*el valor de b pasa a ser el valor de a y el valor de a pasa a ser el antiguo valor de b
*/
void IntercambiaEnteros(int *a , int *b);

//////////////////////////////////////////////////////////////////////////////////////
/*Rellena un vector con números aleatorios de la clase GeneradorAleatorioEnteros
int *p=dirección de memoria del primer elemento del vector
int num_datos= cantidad de elementos total
los enteros aleatorios estarán en el rango (int min_aleat, int max_aleat)
*/
void RellenaVector (int *p, int num_datos, int min_aleat, int max_aleat);

//////////////////////////////////////////////////////////////////////////////////////
/*copia los elementos de un vector a otro vector (v_copia=v_original)
int *p_original=dirección de memoria del primer elemento del vector original
int *p_original=dirección de memoria del primer elemento del vector copia
int num_datos= cantidad de elementos total del vector original
*/
void CopiaVector(int *p_original, int *p_copia, int num_datos);

//////////////////////////////////////////////////////////////////////////////////////
/*Mezcla 2 vectores v1 y v2 en un nuevo vector res: 
los primeros tam_v1 elementos son del vector v1 y los restantes del v2.
int *v1, int *v2, int *res, son las direcciónes de memoria del primer elemento de cada vector
int tam_v1, int tam_v2, int tam_res son la cantidad de elementos de cada vector.
*/
void MezclaVector(int *v1, int *v2, int *res, int tam_v1, int tam_v2, int tam_res);

//////////////////////////////////////////////////////////////////////////////////////
/*Ordena un vector desde una posicion inicial (int pos_inic) hasta una posición final (int pos_fin) 
usando el algoritmo de Selección. MODIFICA EL VECTOR
int *v=dirección de memoria del primer elemento del vector a ordenar
(pv, en la implementación, es un puntero auxiliar entorno a los elementos de v)
*/
void OrdenaSeleccion (int *v, int pos_inic, int pos_fin);

//////////////////////////////////////////////////////////////////////////////////////
/*Ordena un vector desde una posicion inicial (int pos_inic) hasta una posición final (int pos_fin) 
usando el algoritmo de Insercion. MODIFICA EL VECTOR
int *v=dirección de memoria del primer elemento del vector a ordenar
(pv, en la implementación, es un puntero auxiliar entorno a los elementos de v)
*/
void OrdenaInsercion (int *v, int pos_inic, int pos_fin);

//////////////////////////////////////////////////////////////////////////////////////
/*Ordena un vector desde una posicion inicial (int pos_inic) hasta una posición final (int pos_fin) 
usando el algoritmo de Intercambio o burbuja. MODIFICA EL VECTOR
int *v=dirección de memoria del primer elemento del vector a ordenar
(pv, en la implementación, es un puntero auxiliar entorno a los elementos de v)
*/
void OrdenaIntercambio (int *v, int pos_inic, int pos_fin);