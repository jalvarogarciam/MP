/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// Clase "Secuencia"
//
// Representación: array dinámico para alojar los datos en el Heap.
// Los datos son de tipo "TipoBaseSecuencia"
//
// Declaración de la clase Secuencia (versión 1).
// Definiciones en Secuencia.cpp
//
// Incluye: 
//		* constructor de copia
//		* destructor
// 
// Fichero: Secuencia.h
//
/***************************************************************************/

#ifndef CLASS_SECUENCIA_TIPOBASE
#define CLASS_SECUENCIA_TIPOBASE

//#define DEBUG_SECUENCIA

#include "TipoBase_Secuencia.h"

#include <string>
using namespace std;

/////////////////////////////////////////////////////////////////////////////

class Secuencia {

private:
 
	// Núm.casillas disponibles (capacidad) por defecto
    static const int TAMANIO = 50; 

	// Si el porcentaje de casillas usadas > PORC_PETICION --> Crecimiento
    static const int PORC_PETICION = 75; 
	// La capacidad aumenta PORC_CRECIMIENTO sobre la capacida actual
    static const int PORC_CRECIMIENTO = 10; 
	// El valor mínimo de casillas para el crecimiento será MIN_CRECIMIENTO
    static const int MIN_CRECIMIENTO = 5; 

	// Si el porcentaje de casillas usadas < PORC_REDUCCION --> Decrecimiento
    static const int PORC_REDUCCION = 50; 
	// La capacidad queda PORC_EXTRA sobre la ocupación actual
    static const int PORC_EXTRA = 20; 


	// "vector_privado" es un puntero a un array dinámico de 
	// datos "TipoBaseSecuencia"
    TipoBaseSecuencia * vector_privado;

    // PRE: 0 <= capacidad
    int capacidad; // Núm.casillas ocupadas

    // PRE: 0 <= total_utilizados <= capacidad
    int total_utilizados; // Núm.casillas ocupadas

public:

    /***********************************************************************/
    // Constructores
	// Si se llama sin argumentos crea una secuencia con capacidad = TAMANIO.
	// Si se llama con un argumento, su valor será la capacidad inicial. 
	// POST: La secuencia creada estará vacía (EstaVacia()== true)

    Secuencia (int la_capacidad=TAMANIO);

	
    /***********************************************************************/
    // Constructor de copia

    Secuencia (const Secuencia & otro);

    /***********************************************************************/
    // Destructor 

    ~Secuencia (void);

    /***********************************************************************/


    /***********************************************************************/
    // Devuelve el número de casillas ocupadas

    int TotalUtilizados (void) const;

    /***********************************************************************/
    // Devuelve el número de casillas disponibles

    int Capacidad (void) const;

    /***********************************************************************/
    // Devuelve "true" si la secuencia está vacía (total_utilizados == 0)

	bool EstaVacia (void) const;

    /***********************************************************************/
    // "Vacía" completamente la secuencia
	// POST: Capacidad() == TAMANIO.
	// POST: EstaVacia() == true 

	void EliminaTodos();

    /***********************************************************************/
    // Devuelve una referencia al elemento de la casilla "indice"
    // Parámetros: 
    //      indice, Numero de casilla a la que se accede. 
    // PRE: 0 <= indice < TotalUtilizados()
    // (NUEVA) PRE: 1 <= indice <= TotalUtilizados()

    TipoBaseSecuencia & Valor (const int indice);
    TipoBaseSecuencia & Valor (const int indice) const;

    /***********************************************************************/
    // Copia profunda.
    // Parámetros: 
    //      otra (referencia), objeto que sirve de modelo para la copia. 

    void Clona (const Secuencia & otra);

    /***********************************************************************/
    // Añade un elemento ("nuevo") a la secuencia.
    // Parámetros: 
    //      nuevo, valor que se añade a la secuencia.
    // El nuevo elemento se coloca al final del vector.
    // Se redimensionará el vector dinámico de datos si no tuviera suficiente 
    // espacio disponible.

    void Aniade (const TipoBaseSecuencia nuevo);

    /***********************************************************************/
    // Inserta el valor "nuevo" en la posición dada por "indice".
    // Parámetros: 
    //      nuevo, valor que se añade a la secuencia. 
    // "Desplaza" todos los enteros una posición a la derecha antes de 
	// copiar en "indice" en valor "nuevo".
	// PRE: 0 <= indice < TotalUtilizados()

	void Inserta (int indice, TipoBaseSecuencia nuevo);
	     
    /***********************************************************************/
    // Eliminar el contenido de la "casilla" cuya posición es "indice".
    // Parámetros: 
    //      indice, Numero de casilla que se elimina. 
    // PRE: 0 <= indice < TotalUtilizados()

    void Elimina (int indice);

    /***********************************************************************/
    // Compone un string con todos los caracteres que están
    // almacenados en la secuencia y lo devuelve.

    string ToString();

    /***********************************************************************/

private:

    /***********************************************************************/
	// Pide memoria para guardar "num_casillas" datos	
    // PRE: 0 <= num_casillas

	void ReservarMemoria (const int num_casillas);

    /***********************************************************************/
	// Libera memoria

	void LiberarMemoria (void);

    /***********************************************************************/
	// Copiar datos desde otro objeto de la clase
	// PRE: Se ha reservado memoria para los datos

	void CopiarDatos (const Secuencia & otro); 

	/***********************************************************************/
	// Redimensiona el vector dinámico y copia los datos en el nuevo almacén.  
	//
	// Pedirá memoria adicional si el número de casillas usadas es superior 
	// al "PROC_PETICION" de la capacidad actual. El número de casillas 
	// adicionales será el "PORC_CRECIMIENTO" de la capacidad actual.

	void Redimensionar (void);

    /***********************************************************************/
    // Método PRIVADO compartido por: 
    //      TipoBaseSecuencia & Valor (const int indice);
    //      TipoBaseSecuencia & Valor (const int indice) const;
    // para evitar la duplicidad de código.
    // 
    // Devuelve una referencia a un dato TipoBaseSecuencia de la secuencia.
    // dado su posición. 
    //
    // PRE: 0 <= indice < total_utilizados
    // (NUEVA) PRE: 1 <= indice <= TotalUtilizados()

    TipoBaseSecuencia & el_valor (int indice) const;

    /***********************************************************************/
    /***********************************************************************/

};

/////////////////////////////////////////////////////////////////////////////

#endif
