/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// 1º GRADO EN INGENIERÍA INFORMÁTICA, GRUPO B1
//
// JOSÉ ÁLVARO GARCÍA MÁRQUEZ
//
// Implementación de las funciones de gestión de matrices dinámicas de 
// tipo TipoBase (T);
//
// Fichero: Matriz2D.cpp
//
/***************************************************************************/

#include "TipoBase.h"
#include "Matriz2D.h"

#include "utils.h"

#include <string>
#include <cstring>


using namespace std;

// Declaraciín de funciones "de ámbito privado" (sólo visibles en este fichero)
Matriz2D ReservaMemoria (int nfils, int ncols);
void LiberaMemoria (Matriz2D & matriz);

/*****************************************************************************/
/* Reserva memoria para los datos de una matriz dinámica con "nfils" filas y 
"ncols" columnas. El contenido es INDEFINIDO.
Parámetros: 
    nfils: número de filas de la matriz.
    ncols: número de columnas de la matriz.
Devuelve: un dato Matriz2D con memoria reservada.
PRE: nfils >= 0 && ncols >= 0
*/
Matriz2D ReservaMemoria (int nfils, int ncols)
{
    Matriz2D matriz;    // objeto local (se devolverá una copia)

    matriz.datos = nullptr;    // Por defecto, la matriz se inicializa vacia
    matriz.fils = 0;
    matriz.cols = 0;

    if (nfils>0 && ncols>0) {   // Reservar memoria -> matriz NO vacía
        
        // matriz.datos apuntará a un vector de punteros a las filas
        matriz.datos = new T * [nfils];

        // matriz.datos[i] apuntará a un vector de filas (objetos T (TipoBase))
        matriz.datos[0] = new T [nfils*ncols];

        // Inicializa el vector de punteros
        for (int i=1; i <nfils; i++)
            matriz.datos[i] = matriz.datos[0] + i*ncols;
        
        // "matriz.datos[f]" apuntará a un vector de datos int
        matriz.fils = nfils;
        matriz.cols = ncols;
    }

    return matriz;
}
/*****************************************************************************/


/*****************************************************************************/
/* Libera la memoria ocupada por una matriz dinámica, dejandola vacia
Parámetros: 
    matriz (referencia): la matriz que va a "liberarse".
*/
void LiberaMemoria (Matriz2D & matriz)
{
    if (matriz.datos) { // if (matriz.datos != nullptr)

        //Busca el puntero a la primera casilla de la memoria reservada
        T * ptr_inicio = matriz.datos[0];

        for (size_t i=1; i < matriz.fils; i++)

            if (matriz.datos[i] < ptr_inicio)
                ptr_inicio = matriz.datos[i];

        delete [] ptr_inicio;      // Libera el vector de datos
    
        delete [] matriz.datos;         // Libera el vector de punteros

        matriz.datos = nullptr;     // Elimina el acceso al vector de punteros
        matriz.fils = matriz.cols = 0;  // Actualiza los "atributos"
    }
}
/*****************************************************************************/



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

Matriz2D CreaMatriz (int nfils, int ncols, int valor)
{
    // Pedir memoria para los datos
    Matriz2D matriz = ReservaMemoria (nfils, ncols);
    
    // Inicializa las casillas de la matriz a "valor"
    Ecualiza (matriz, valor);
    
    
    return matriz;
}
/*****************************************************************************/


/*****************************************************************************/
/* "Destruye" una matriz dinámica y la deja vacía.
Parámetros: 
    matriz (referencia): la matriz que va a "destruirse".
*/
void DestruyeMatriz (Matriz2D & matriz)
{
    LiberaMemoria (matriz);
}
/*****************************************************************************/


/*****************************************************************************/
/*Devuelve el número de filas de la matriz.
*/
int NumFilas (const Matriz2D & matriz)
{
    return matriz.fils;
}
/*****************************************************************************/

/*****************************************************************************/
/*Devuelve el número de columnas de la matriz.
*/
int NumColumnas (const Matriz2D & matriz)
{
    return matriz.cols;
}
/*****************************************************************************/

/*****************************************************************************/
/*Devuelve true si la matriz está vacía.
Parámetros: 
    matriz (referencia), la matriz.
*/
bool EstaVacia (const Matriz2D & matriz)
{
    return (matriz.datos == nullptr);
}
/*****************************************************************************/

/*****************************************************************************/
/*Descarta todos los valores de la matriz. Deja la matriz en estado “vacía”.
La matriz sigue “activa”. 
Use esta función si tiene previsto seguir usando la matriz.
*/
void EliminaTodos (Matriz2D & matriz)
{
    DestruyeMatriz(matriz);
}
/*****************************************************************************/

/*****************************************************************************/
/* Cambia todos los todos valores de la matriz por valor.
*/
void Ecualiza (Matriz2D & matriz, T valor)
{
    /* Con memset seria mas eficiente pero dependería de la interpretacion
     de la matriz en memoria
    memset(matriz.datos[0], valor, sizeof(T)*matriz.fils*matriz.cols);*/
    if (matriz.datos){ // if (matriz.datos != nullptr)
        
        for (int f=0; f<matriz.fils; f++){
            
            for (int c=0; c<matriz.cols; c++){
                
                matriz.datos[f][c] = valor;
            }
        }
    }
}

/*****************************************************************************/


/*****************************************************************************/
/*Devuelve un string con el resultado de “serializar” una matriz.
Parámetros: 
    matriz (referencia), la matriz que va a serializarse.
*/
string ToString (const Matriz2D & matriz)
{
    if (matriz.datos == nullptr) 
        return "Matriz vacía\n";
    
	string cad;

	string delimitador = "..................................";

	cad = "\n" + delimitador + "\n";

	cad = cad + "Filas = " + to_string(matriz.fils) + 
	      ", Columnas = " + to_string (matriz.cols) + "\n\n";

	for (int f=0; f<matriz.fils; f++) {
		
        cad = cad + "Fila " + to_string(f) + " --> ";
		
		for (int c=0; c<matriz.cols; c++) 
			cad = cad + to_string(matriz.datos[f][c]) + "  ";
		
        cad = cad + "\n";
	}
	
    cad = cad + delimitador + "\n\n";

	return (cad);
}

/*****************************************************************************/

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
T & Valor (const Matriz2D & matriz, int num_fila, int num_columna) 
{
	return (matriz.datos[num_fila][num_columna]);
}
/*****************************************************************************/


/*****************************************************************************/
/*Hace una copia profunda de origen en destino.
Parámetros: 
    destino: la matriz que va a copiarse.
    origen: la matriz que va a copiarse.
PRE: destino se ha inicializado previamente.
*/
void Clona (Matriz2D & destino, const Matriz2D & origen)
{
    LiberaMemoria(destino);

    destino.cols = origen.cols;
    destino.fils = origen.fils;

    destino = ReservaMemoria(destino.fils, destino.cols);

    /* Con memcpy seria mas eficiente pero dependería de la interpretacion
     de la matriz en memoria
    memcpy(destino.datos[0], origen.datos[0],sizeof(T)*origen.cols*origen.fils);
    */
    for (int f=0; f<origen.fils; f++)
        for (int c=0; c<origen.cols; c++)
            destino.datos[f][c] = origen.datos[f][c];
}
/*****************************************************************************/


/*****************************************************************************/
/*Devuelve true si las matrices son iguales.
Paeámetros: 
    una, otra: las matrices a comparar.
*/
bool SonIguales (const Matriz2D & una, const Matriz2D & otra)
{
    // Compara el tamaño de las matrices para evitar errores de acceso
    if (una.fils != otra.fils || una.cols != otra.cols)
        return false;
    
    // Compara los datos de las matrices
    /*Con memcmp seria mas eficiente pero dependería de la interpretacion
     de la matriz en memoria
    memcmp(una.datos[0], otra.datos[0], sizeof(T)*una.fils*una.cols)== 0; */
    bool iguales = true;
    for (int f=0; f<una.fils && iguales; f++)
        for (int c=0; c<una.cols && iguales; c++)
            if (una.datos[f][c] != otra.datos[f][c])
                iguales = false;
    
    return iguales;
}
/*****************************************************************************/


/*****************************************************************************/
/*Elimina la fila numero "index" de la matriz.
*/
void EliminaFila (Matriz2D & matriz, size_t index)
{
    if (matriz.datos){

        //Crea una matriz con una fila menos que la inicial
        Matriz2D nueva = CreaMatriz(matriz.fils-1, matriz.cols);

        //Copia el contenido de la matriz en la nueva matriz (omitiendo la fila)
        for (size_t i=0, d=0; i < matriz.fils; i++){
            if (i != index)

                for (size_t j=0; j < matriz.cols; j++)

                    nueva.datos[i-d][j] = matriz.datos[i][j];

            else   //Si se ha llegado a la fila a eliminar, no se copian.
                d=1;    //se tiene en cuenta el desfase entre nueva y matriz
        }

        //Libera la memoria de la matriz inicial
        DestruyeMatriz(matriz);

        //Asigna de forma literal el contenido de la nueva matriz a la original
        matriz = nueva;
    }

}
/*****************************************************************************/

/*****************************************************************************/
/*Elimina la columna numero "index" de la matriz.
*/
void EliminaColumna (Matriz2D & matriz, size_t index)
{
    if (matriz.datos){

        //Crea una matriz con una columna menos que la inicial
        Matriz2D nueva = CreaMatriz(matriz.fils, matriz.cols-1);

        //Copia el contenido de la matriz en la nueva matriz (omitiendo la fila)
        for (size_t i=0; i < matriz.fils; i++)

            for (size_t j=0, d=0; j < matriz.cols; j++){

                if (j != index)

                    nueva.datos[i][j-d] = matriz.datos[i][j];

                else   //Si se ha llegado a la columna a eliminar, no se copian.
                    d=1;    //se tiene en cuenta el desfase entre nueva y matriz
            }

        //Libera la memoria de la matriz inicial
        DestruyeMatriz(matriz);

        //Asigna de forma literal el contenido de la nueva matriz a la original
        matriz = nueva;
    }

}
/*****************************************************************************/

/*****************************************************************************/
/*
*/
#include <iostream>
void SubMatriz (Matriz2D & resultado, const Matriz2D & original, \
                int fila_inic, int col_inic, int num_filas, int num_cols)
{
    //comprueba la validez de los datos
    if (original.cols <= col_inic || col_inic < 0 || \
            original.fils <= fila_inic || fila_inic < 0){
        
        num_cols = 0;
        num_filas = 0;
    
    }else{

        if (original.cols-col_inic < num_cols)  //reajusta el numero de columnas
        
            num_cols = original.cols-col_inic;

        if (original.fils-fila_inic < num_filas)  //reajusta el numero de filas
        
            num_filas = original.fils-fila_inic;
    }
    
    //Si resultado esta inicializado, lo destruirá
    DestruyeMatriz(resultado);

    //Inicializa resultado
    resultado = CreaMatriz(num_filas, num_cols);
    
    //Copia los datos de la submatriz en resultado
    for (size_t i=0, fil = fila_inic; i < resultado.fils; i++, fil++)
        for (size_t j=0, col = col_inic; j < resultado.cols; j++, col++)
            resultado.datos[i][j] = original.datos[fil][col]; 
    
        
}
/*****************************************************************************/



/*****************************************************************************/
/*Cambia de orden las filas de matriz (la primera pasa a ser la última y 
la última la primera, la segunda la penúltima y la penúltima la segunda, etc.).
Parametros:
    matriz (referencia): la matriz que va a modificarse.
*/
void EspejoHorizontal (Matriz2D & matriz)
{
    for (size_t i=0; i < matriz.fils/2; i++)
        swp(matriz.datos[i], matriz.datos[matriz.fils-1-i]);
}
/*****************************************************************************/


/*****************************************************************************/
/*Cambia de orden las columnas de matriz (la primera pasa a ser la última y 
la última la primera, la segunda la penúltima y la penúltima la segunda, etc.).
Parametros:
    matriz (referencia): la matriz que va a modificarse.
*/
void EspejoVertical (Matriz2D & matriz)
{
    if (matriz.datos)

        for (size_t i=0; i < matriz.fils; i++)
            
            for (size_t j=0; j < matriz.cols/2; j++)
                
                swp(matriz.datos[i][j], matriz.datos[i][matriz.cols-1-j]);
}
/*****************************************************************************/




