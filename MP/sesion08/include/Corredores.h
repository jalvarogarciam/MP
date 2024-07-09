/***************************************************************************/
/***************************************************************************/
// 
// Fichero: Corredores.h
//
// Archivo de implementación--> Declaración de la clase almacén "Corredores".
//
// Proyecto. FASE 02. 
//
/***************************************************************************/
/***************************************************************************/

#ifndef CORREDORES
#define CORREDORES

#include <string>


#include "Corredor.h"

using namespace std;

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////


class Corredores {

private:

    // numero de casillas de memoria para añadir en cada redimensionamiento
    static const int TAM_BLOQUE = 100;

	// "datos" es un puntero a un array dinámico de datos "Corredor"
    Corredor * datos;

    // PRE: 0 <= capacidad
    int capacidad; // Núm.casillas ocupadas

    // PRE: 0 <= total_utilizados <= capacidad
    int usados; // Núm.casillas ocupadas

public:

    /***********************************************************************/
    // Constructor sin argumentos
	/* Crea un vector con capacidad = TAM_BLOQUE. */
    Corredores (void);


    /***********************************************************************/
	/* El valor del argumento "cap", será la capacidad inicial. 
	POST: La secuencia creada estará vacía (EstaVacia() = true)
    */
    Corredores (int cap);

	
    /***********************************************************************/
    // Constructor de copia
    Corredores (const Corredores & otro);


    /***********************************************************************/
    // Destructor 
    ~Corredores (void);

    /***********************************************************************/


    /***********************************************************************/
    /* Devuelve el número de casillas ocupadas, o lo que es lo mismo, el número
    de corredores.
    */
    int Usados (void) const;


    /***********************************************************************/
    /* Devuelve el número de casillas disponibles */
    int Capacidad (void) const;


    /***********************************************************************/
    /* Devuelve "true" si la secuencia está vacía (total_utilizados == 0) */
	bool EstaVacia (void) const;


    /***********************************************************************/
    /* "Vacía" completamente el vector.
	POST: Capacidad() == TAMANIO.
	POST: EstaVacia() == true 
    */
	void EliminaTodos();


    /***********************************************************************/
    /* Inicializa todas las casillas del vector a un corredor dado.
    */
    void Ecualiza (const Corredor & corredor);


    /***********************************************************************/
    /*Devuelve una referencia al elemento de la casilla "indice"
    Parámetros: 
        indice, Numero de casilla a la que se accede. 
    PRE: 1 <= indice <= TotalUtilizados()
    */
    Corredor & Valor (const int indice);
    Corredor & Valor (const int indice) const;


    /***********************************************************************/
    /* Copia profunda.
    Parámetros: 
        otra (referencia), objeto que sirve de modelo para la copia. 
    */
    void Clona (const Corredores & otra);


    /***********************************************************************/
    /* Añade un Corredor ("nuevo") al vector al final (posicion usados+1).
    Parámetros: 
        nuevo, valor que se añade a la secuencia.
    
    El nuevo elemento se coloca al final del vector.

    Se redimensionará el vector dinámico de datos si no tuviera suficiente 
    espacio disponible.
    */
    void Aniade (const Corredor nuevo);


    /***********************************************************************/
    /* Inserta el valor "nuevo" en la posición dada por "indice".
    Parámetros: 
        nuevo, Corredor que se añade al vector. 
    
    "Desplaza" todos los enteros una posición a la derecha antes de copiar en 
    "indice" el nuevo corredor

	PRE: 0 <= indice < TotalUtilizados()
    */
	void Inserta (int indice, Corredor nuevo);


    /***********************************************************************/
    /* Eliminar el contenido de la "casilla" cuya posición es "indice".
    Parámetros: 
        indice, Numero de casilla que se elimina. 
    PRE: 0 <= indice < TotalUtilizados()
    */
    void Elimina (int indice);

    /***********************************************************************/
    // Compone un string con todos los caracteres que están
    // almacenados en la secuencia y lo devuelve.

    string ToString();

    /***********************************************************************/

private:

    /***********************************************************************/
	/* Pide memoria para guardar "num_casillas" datos	
    PRE: 0 <= num_casillas
    */

	void ReservaMemoria (const int num_casillas);

    /***********************************************************************/
	/* Libera memoria dinámica reservada para los datos */
	void LiberaMemoria (void);

    /***********************************************************************/
	/* Copia datos desde otro objeto de la clase
	 PRE: Se ha reservado memoria para los datos
    */
	void CopiaDatos (const Corredores & otro); 

	/***********************************************************************/
	/* Redimensiona el vector dinámico y copia los datos en el nuevo almacén.  
	Pedirá memoria adicional si el número de casillas a usar es superior 
	a la capacidad actual. El número de casillas adicionales será "TAM_BLOQUE".
    */
	void Redimensiona (void);

    /***********************************************************************/
    /* Método PRIVADO compartido por: 
          Corredor & Valor (const int indice);
          Corredor & Valor (const int indice) const;
    para evitar la duplicidad de código.

    Devuelve una referencia a un dato Corredor del vector dada su posición. 

    PRE: 1 <= indice <= NumCorredores()
    */
    Corredor & el_valor (int indice) const;

    /***********************************************************************/
    /***********************************************************************/

};

/////////////////////////////////////////////////////////////////////////////

#endif
