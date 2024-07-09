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

#include "TipoBase_Matriz2D.h"

#include "Secuencia.h"
#include <string>

using namespace std;


///////////////////////////////////////////////////////////////////////////////
// Definicion de la estructura Matriz2D
///////////////////////////////////////////////////////////////////////////////
class Matriz2D {
private:

    TipoBaseMatriz2D ** datos;     // Puntero a vector de punteros a los datos

    int fils;       // Numero de filas

    int cols;       // Numero de columnas

public:

    /*************************************************************************/
    /* Constructor sin argumentos
    Crea una matriz dinámica vacía.
    */
    Matriz2D (void);

    /*************************************************************************/
    /* Constructor con un argumento
    Crea una matriz dinámica cuadrada de dimension "dim", cuyo contenido
    está indefinido. 
    PRE: dim >= 0
    */
    Matriz2D (int dim);


    /*************************************************************************/
    /* Constructor con dos argumentos
    Crea una matriz dinámica con "nfils" filas y "ncols" columnas.
    El contenido de las "fils"x"cols" casillas está indefinido.
    PRE: nfils >= 0 && ncols >= 0
    */
    Matriz2D (int nfils, int ncols);


    /*************************************************************************/
    /* Constructor con tres argumentos
    Crea una matriz dinámica con "nfils" filas y "ncols" cols.
    El contenido de las "fils"x"cols" casillas se inicializa a un valor común, 
    el indicado en el parámetro "valor"

    PRE: nfils >= 0 && ncols >= 0 && valor de tipo TipoBaseMatriz2D
    */
    Matriz2D (int nfils, int ncols, int valor);



    /*************************************************************************/
    // Constructor de copia.
    Matriz2D (const Matriz2D & otra);


    /*************************************************************************/
    // Destructor
    ~Matriz2D (void);
    /*************************************************************************/


    /*************************************************************************/
    //Hace una copia profunda de "otra" en la matriz.
    void Clona (const Matriz2D & otra);

    /*************************************************************************/
    //Devuelve el número de filas de la matriz.
    int NumFilas (void) const;

    /*************************************************************************/
    //Devuelve el número de columnas de la matriz.
    int NumColumnas (void) const;

    /*************************************************************************/
    //Devuelve true si la matriz está vacía.
    bool EstaVacia (void) const;



    /*************************************************************************/
    //Devuelve un string con el resultado de “serializar” una matriz.
    string ToString () const;


    /*************************************************************************/
    /*Descarta todos los valores de la matriz. Deja la matriz en estado “vacía”.
    La matriz sigue “activa”. 
    Use esta función si tiene previsto seguir usando la matriz.
    POST: EstaVacia() == true 
    */
    void EliminaTodos ();


    /*************************************************************************/
    // Cambia todos los todos valores de la matriz por valor.
    void Ecualiza ( TipoBaseMatriz2D valor);



    /*************************************************************************/
    /*Consulta ó modifica el valor de una casilla dada. 
        Si se utiliza como rvalue se emplea para consulta. 
        Si se utiliza como lvalue se emplea para modificación.
    Parámetros: 
        num_fila, número de fila.
        num_columna, número de columna.
    PRE: 0<=num_fila<matriz.NumFilas()
    PRE: 0<=num_columna<matriz.NumColumnas()
    */
    TipoBaseMatriz2D & Valor (int num_fila, int num_columna);


    /*************************************************************************/
    /*Devuelve un objeto secuencia cuyos valores son la los valores de la fila nº
    "indice"
    NOTA: si el indice es incorrecto devolverá una secuencia vacía
    */
    Secuencia Fila (int indice);


    /*****************************************************************************/
    /*Devuelve un objeto secuencia cuyos valores son la los valores de la columna nº
    "indice"
    NOTA: si el indice es incorrecto devolverá una secuencia vacía
    */
    Secuencia Columna (int indice);


    /*************************************************************************/
    /*Devuelve true si las matrices son iguales.
    Paeámetros: 
        otra: las matriz a comparar con la implicita.
    */
    bool EsIgualA ( const Matriz2D & otra);

    /*************************************************************************/
    /*Añade una fila nueva a la matriz.
    Parámetros:
        fila_nueva: objeto secuencia cuyos valores son los de la fila a añadir.
    PRE: fila_nueva.NumValores() == NumColumnas()
    */
    void Aniade(const Secuencia & fila_nueva);


    /*****************************************************************************/
    /*Inserta una fila nueva a la matriz en la posición "indice".
    Parámetros:
        fila_nueva: objeto secuencia cuyos valores son los de la fila a insertar
        indice: posición en la que se insertará la fila.
    PRE: fila_nueva.NumValores() == NumColumnas()
    */
    void Inserta(int indice, const Secuencia & fila_nueva);

    /*************************************************************************/
    /*Elimina la fila numero "index" de la matriz.
    */
    void EliminaFila ( size_t index);


    /*************************************************************************/
    /*Elimina la columna numero "index" de la matriz.
    */
    void EliminaColumna ( size_t index);


    /*************************************************************************/
    /* Devuelve una Matriz2D submatriz de la matriz implícita.
    Parametros:
        fila_inic, col_inic : coordenada en la matriz a partir de la que empieza 
                                la submatriz
        num_filas, num_cols : numero de filas y columnas que tendrá la submatriz,
                                tendrá num_filas * num_cols casillas.
    Si las coordenadas no son correctas, devolverá una matriz vacía
    Si num_filas o num_columnas son demasiado grandes, se construirá con las filas o
    columnas disponibles.
    */

    Matriz2D SubMatriz ( int fila_inic, int col_inic, \
                                    int num_filas, int num_cols);



    /*************************************************************************/
    /*Cambia de orden las filas de matriz (la primera pasa a ser la última y 
    la última la primera, la segunda la penúltima y la penúltima la segunda, etc.).
    */
    void EspejoHorizontal ();



    /*************************************************************************/
    /*Cambia de orden las columnas de matriz (la primera pasa a ser la última y 
    la última la primera, la segunda la penúltima y la penúltima la segunda, etc.).
    */
    void EspejoVertical ();


private:
    /***************************************************************************/
    /* Reserva memoria para los datos de una matriz dinámica con "nfils" filas y 
    "ncols" columnas. El contenido es INDEFINIDO.
    Parámetros: 
        nfils: número de filas de la matriz.
        ncols: número de columnas de la matriz.
    PRE: nfils >= 0 && ncols >= 0
    */
    void ReservaMemoria (int nfils, int ncols);



    /*************************************************************************/
    // Libera la memoria ocupada por una matriz dinámica, dejandola vacia
    void LiberaMemoria ();


    /*************************************************************************/
    /* Copiar datos desde otro objeto de la clase
    PRE: Se ha reservado memoria para los datos
    */
    void CopiaDatos (const Matriz2D & otra);
};

#endif

