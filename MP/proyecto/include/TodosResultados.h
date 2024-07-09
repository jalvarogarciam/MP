/***************************************************************************/
/***************************************************************************/
// 
// Fichero: TodosResultados.h
//
// Archivo de implementación--> Declaración de la clase almacén "TodosResultados".
//
// Proyecto. FASE 04. 
//
/***************************************************************************/
/***************************************************************************/

#ifndef TODOSRESULTADOS
#define TODOSRESULTADOS

#include <string>


#include "Resultados.h"

using namespace std;

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

/****************************************************************************/
/* Clase almacen TodosResultados-> Vector dinamico NO REDIMENSIONABLE
que almacena una UNICA copia de objetos Resultados's. 
Guarda resultados de varias carreras.
*/
class TodosResultados {

private:

    // numero de casillas de memoria para añadir en cada redimensionamiento
    static const int TAMANIO = 20;

	// "datos" es un puntero a un array dinámico de datos "Resultados"
    Resultados * datos;

    // PRE: 0 <= capacidad
    int capacidad; // Núm.casillas ocupadas

    // PRE: 0 <= total_utilizados <= capacidad
    int usados; // Núm.casillas ocupadas


public:
    /*************************************************************************/
    //CONSTRUCTORES Y DESTRUCTOR
    /*************************************************************************/
    
    /********************************************************************/
    // Constructor sin argumentos
	/* Crea un vector con capacidad = TAMANIO. */
    TodosResultados (void);

    /********************************************************************/
	/* El valor del argumento "cap", será la capacidad inicial. 
	POST: La secuencia creada estará vacía (EstaVacia() = true)
    */
    TodosResultados (int cap);

    /********************************************************************/
    // Constructor de copia
    TodosResultados (const TodosResultados & otro);

    /********************************************************************/
    // Constructor de un solo elemento: Vector con un solo resultado
    TodosResultados (const Resultados & resultado);

    /********************************************************************/
    // Destructor 
    ~TodosResultados (void);

    /********************************************************************/
    /* "Vacía" completamente el vector.
	POST: Capacidad() == 0.
	POST: EstaVacia() == true 
    */
	void EliminaTodos();
    /*************************************************************************/
    /*************************************************************************/


    /*************************************************************************/
    //ENTRADA/SALIDA
    /*************************************************************************/

    /********************************************************************/
    /*Operadores de inserción (>>) y extracción sobre flujos (<<)
    La entrada tiene el mismo formato que la salida: campo * campo * ... *
    siendo '*' un delimitador.
    */
    friend ostream & operator << (ostream & out, const TodosResultados & este);
    friend istream & operator >> (istream & in, TodosResultados & este);
    /********************************************************************/

    /********************************************************************/
    // Compone un string con todos los elementos de la coleccion y lo devuelve.
    string ToString(string msg = "");

    /*************************************************************************/
    /*************************************************************************/


    /*************************************************************************/
    //OPERADORES
    /*************************************************************************/
    
    /********************************************************************/
    /* Operador de asignación para copia profunda.
    */
    TodosResultados & operator = (const TodosResultados & otro);

    /********************************************************************/
    /* Operadores combinados += y -= para aniadir o eliminar un elemento o 
    conjunto al original.
    */
    TodosResultados & operator += (const TodosResultados & coleccion);
    TodosResultados & operator += (const Resultados & elemento);

    TodosResultados & operator -= (const TodosResultados & coleccion);
    TodosResultados & operator -= (const Resultados & elemento);
    /********************************************************************/


    /********************************************************************/
    /* Operador == y !=
    Dos colecciones serán iguales si contienen el mismo número de objetos y 
    todos sus objetos son iguales (misma clave primaria). 
    De lo contrario, serán diferentes (!=).

    //PRE: No hay elementos repetidos en ninguna coleccion.
    */
    bool operator == (const TodosResultados & otro) const;
    // Operador != 
    bool operator != (const TodosResultados & otro) const;
    /********************************************************************/


    /********************************************************************/
    // Operador binario && para comprobar la pertenencia/inclusión de:

    //una coleccion(este) dentro de otra coleccion(otro)
    friend bool operator && (const TodosResultados & este, 
                                 const TodosResultados & otro);
    //un elemento dentro de una coleccion.
    friend bool operator && (const TodosResultados & coleccion, 
                                 const Resultados & elemento);
    friend bool operator && (const Resultados & elemento, 
                                 const TodosResultados & coleccion);
    friend bool operator && (int clave_primaria, \
                                 const TodosResultados & coleccion);
    /********************************************************************/


    /********************************************************************/
    // Operaciones de conjuntos (union, diferencia e interseccion)

    /* Operador binario * para la INTERSECCION de dos colecciones.
    Devuelve una coleccion con los elementos comunes entre las dos colecciones.
    */
    TodosResultados operator* (const TodosResultados & otro) const;


    /* Operador binario + para la UNION de dos colecciones.
    Devuelve una coleccion con los elementos presentes en uno o en otro.
    */
    //dos colecciones
    friend TodosResultados operator + (const TodosResultados & este, \
                                    const TodosResultados & otro);

    //una coleccion y un elemento (coleccion de un solo elemento)
    friend TodosResultados operator + (const Resultados & elemento, \
                                    const TodosResultados & coleccion);
    friend TodosResultados operator + (const TodosResultados & coleccion, \
                                    const TodosResultados & elemento);

    /* Operador binario - para la DIFERENCIA de dos colecciones.
    Devuelve una coleccion con los elementos presentes en el primero y 
    no presentes en el segundo.
    NOTA: la diferencia no es conmutativa.
    */
    //dos colecciones
    friend TodosResultados operator - (const TodosResultados & este, \
                                        const TodosResultados & otro);
    
    //una coleccion y un elemento (coleccion de un solo elemento)
    friend TodosResultados operator - (const Resultados & elemento, \
                                        const TodosResultados & coleccion);
    friend TodosResultados operator - (const TodosResultados & coleccion, \
                                        const Resultados & elemento);
    /********************************************************************/

    /********************************************************************/
    /* Sobrecarga de los operadores () y [] para el acceso al
    elemento de la casilla "num_casilla".
    Consulta ó modifica el valor de una casilla dada:
        Si se utiliza como rvalue se emplea para consultar el
            valor de la casilla "num_casilla".
        Si se utiliza como lvalue se emplea para modificar el
            valor de la casilla "num_casilla".
    
    PRE: 1 <= num_casilla <= Usados()
    */
    Resultados & operator() (const int num_casilla);
    Resultados & operator() (const int num_casilla) const;
    Resultados & operator[] (const int num_casilla);
    Resultados & operator[] (const int num_casilla) const;

    /* Operador () para el acceso al elemento de la casilla "num_resultado" de
    la coleccion num_carrera.
    */
    Resultado & operator() (const int num_carrera, \
                                                const int num_resultado);

    Resultado & operator() (const int num_carrera, \
                                            const int num_resultado) const;
    /********************************************************************/

    /*************************************************************************/
    /*************************************************************************/



    /*************************************************************************/
    // Getters
    /*************************************************************************/
    
    /********************************************************************/
    /* Devuelve el número de casillas ocupadas, o lo que es lo mismo, el número
    de resultados.
    */
    int Usados (void) const;

    /********************************************************************/
    /* Devuelve el número de casillas disponibles */
    int Capacidad (void) const;

    /********************************************************************/
    /* Devuelve "true" si la secuencia está vacía (usados == 0) */
	bool EstaVacia (void) const;

    /*************************************************************************/
    /* Busca la posición de un resultado pasado como argumento. 

    Devuelve la posición del primer elemento coincidente (debe ser unico), 
    o -1 si no se encuentra.

    Posiciones: 1, 2, ..., Usados()
    */
    int Busca (const Resultados & coleccion_resultados) const;

    /*************************************************************************/
    /*************************************************************************/



    /*************************************************************************/
    //Operadores de manejo
    /*************************************************************************/

    /********************************************************************/
    /* Inserta el elemento "nuevo" en la posición dada por "indice".

    "Desplaza" todos los elementos una posición a la derecha antes de copiar en
    "indice" el nuevo elemento

	PRE: 0 <= indice < Usados()
    PRE: hay suficiente capacidad en la coleccion
    */
	void Inserta (int indice, const Resultados & nuevo);

    /********************************************************************/
    /* Eliminar el contenido de la "casilla" cuya posición es "indice".

    PRE: 1 <= indice <= Usados()
    */
    void Elimina (int indice);

    /*************************************************************************/
    /*************************************************************************/



private:

    /********************************************************************/
	/* Pide memoria para guardar "num_casillas" datos	
    PRE: 0 <= num_casillas
    */
	void ReservaMemoria (const int num_casillas);

    /********************************************************************/
	/* Libera memoria dinámica reservada para los datos */
	void LiberaMemoria (void);

    /********************************************************************/
	/* Copia datos desde otro objeto de la clase
	 PRE: Se ha reservado memoria para los datos
    */
	void CopiaDatos (const TodosResultados & otro); 

    /********************************************************************/
    /*Devuelve una referencia al elemento de la casilla "indice"

    PRE: 0 <= indice < Usados()
    */
    Resultados & Valor (const int indice) const;


    /********************************************************************/
    /* Aniade un elemento ("nuevo") al final de la coleccion (pos usados+1).
    PRE: hay suficiente capacidad en la coleccion
    */
    void Aniade (const Resultados & nuevo);

    /*************************************************************************/
    /*************************************************************************/

};

/////////////////////////////////////////////////////////////////////////////

#endif