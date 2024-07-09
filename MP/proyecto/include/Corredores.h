/***************************************************************************/
/***************************************************************************/
// 
// Fichero: Corredores.h
//
// Archivo de implementación--> Declaración de la clase almacén "Corredores".
//
// Proyecto. FASE 4.
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

/****************************************************************************/
/* Clase almacen Corredores-> Vector dinamico que almacena una UNICA copia de
 objetos Corredor.
*/
class Corredores {

private:

    // numero de casillas de memoria para añadir en cada redimensionamiento
    static const int TAM_BLOQUE = 20;

	// "datos" es un puntero a un array dinámico de datos "Corredor"
    Corredor * datos;

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
	/* Crea un vector con capacidad = TAM_BLOQUE. */
    Corredores (void);

    /********************************************************************/
	/* El valor del argumento "cap", será la capacidad inicial. 
	POST: La secuencia creada estará vacía (EstaVacia() = true)
    */
    Corredores (int cap);

    /********************************************************************/
    // Constructor de copia
    Corredores (const Corredores & otro);

    /********************************************************************/
    // Constructor de un solo elemento: Vector con un solo corredor
    Corredores (const Corredor & corredor);

    /********************************************************************/
    /* Constructor de fichero. Construye la coleccion a partir de la 
    información guardada en un fichero de texto llamado nombre.
    */
    Corredores (const string & nombre);

    /********************************************************************/
    // Destructor 
    ~Corredores (void);

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
    friend ostream & operator << (ostream & out, const Corredores & este);
    friend istream & operator >> (istream & in, Corredores & este);
    /********************************************************************/

    /********************************************************************/
    /*Método de escritura. Guarda un dato Corredores en un fichero de texto 
    llamado nombre.
        • Si el vector está vacío no se crea el fichero.
        • El vector no se modifica
    */
    void EscribirCorredores (const string & nombre) const;

    /********************************************************************/
    /*Método de lectura. Lee un dato Corredores de un fichero de texto 
    llamado nombre.
        • El vector siempre se modifica.
        • Si el fichero indicado no fuera un fichero del tipo esperado, 
        el vector quedará vacío.

    */
    void LeerCorredores (const string & nombre);
    /********************************************************************/

    /********************************************************************/
    // Compone un string con todos los elementos de la coleccion y lo devuelve.
    string ToString(string msg = "");

    /*************************************************************************/
    /*************************************************************************/



    /***********************************************************************/
    //OPERADORES
    /***********************************************************************/
    
    /********************************************************************/
    /* Operador de asignación para copia profunda.
    */
    Corredores & operator = (const Corredores & otro);

    /********************************************************************/
    /* Operadores combinados += y -= para aniadir o eliminar un elemento o 
    conjunto al original.
    */
    Corredores & operator += (const Corredores & coleccion);
    Corredores & operator += (const Corredor & elemento);
    Corredores & operator += (int num_dorsal);

    Corredores & operator -= (const Corredores & coleccion);
    Corredores & operator -= (const Corredor & elemento);
    Corredores & operator -= (int num_dorsal);
    /********************************************************************/


    /********************************************************************/
    /* Operador == y !=
    Dos colecciones serán iguales si contienen el mismo número de objetos y 
    todos sus objetos son iguales (misma clave primaria). 
    De lo contrario, serán diferentes (!=).

    //PRE: No hay elementos repetidos en ninguna coleccion.
    */
    bool operator == (const Corredores & otro) const;
    // Operador != 
    bool operator != (const Corredores & otro) const;
    /***********************************************************************/

    /***********************************************************************/
    /* Operadores >, >=, <, <=
    */
    /* Una coleccion sera mayor que otra si y solo si tiene mas elementos
    que la otra */
    bool operator > (const Corredores & otro) const;

    /* Una coleccion sera mayor o igual que otra si tiene mas o el mismo
    numero de elementos que la otra.*/
    bool operator >= (const Corredores & otro) const;

    /* Una coleccion sera menor que otra si y solo si tiene menos elementos
    que la otra.*/
    bool operator < (const Corredores & otro) const;

    /* Una coleccion sera mayor o igual que otra si tiene menos o el mismo
    numero de elementos que la otra.*/
    bool operator <= (const Corredores & otro) const;
    /***********************************************************************/


    /***********************************************************************/
    // Operador binario && para comprobar la pertenencia/inclusión de:

    //una coleccion(este) dentro de otra coleccion(otro)
    friend bool operator && (const Corredores & este, 
                                 const Corredores & otro);
    //un elemento dentro de una coleccion.
    friend bool operator && (const Corredores & coleccion, 
                                 const Corredor & elemento);
    friend bool operator && (const Corredor & elemento, 
                                 const Corredores & coleccion);
    //un elemento (representado por un int, clave primaria) en una colecion.
    friend bool operator && (const Corredores & coleccion, int clave_primaria);
    friend bool operator && (int clave_primaria, const Corredores & coleccion);
    /***********************************************************************/


    /***********************************************************************/
    // Operaciones de conjuntos (union, diferencia e interseccion)

    /* Operador binario * para la INTERSECCION de dos colecciones.
    Devuelve una coleccion con los elementos comunes entre las dos colecciones.
    */
    Corredores operator* (const Corredores & otro) const;


    /* Operador binario + para la UNION de dos colecciones.
    Devuelve una coleccion con los elementos presentes en uno o en otro.
    */
    //dos colecciones
    friend Corredores operator + (const Corredores & este, \
                                    const Corredores & otro);

    //una coleccion y un elemento (coleccion de un solo elemento)
    friend Corredores operator + (const Corredor & elemento, \
                                    const Corredores & coleccion);
    friend Corredores operator + (const Corredores & coleccion, \
                                    const Corredores & elemento);
    friend Corredores operator + (const Corredores & coleccion, int num_dorsal);

    /* Operador binario - para la DIFERENCIA de dos colecciones.
    Devuelve una coleccion con los elementos presentes en el primero y 
    no presentes en el segundo.
    NOTA: la diferencia no es conmutativa.
    */
    //dos colecciones
    friend Corredores operator - (const Corredores & este, \
                                    const Corredores & otro);
    
    //una coleccion y un elemento (coleccion de un solo elemento)
    friend Corredores operator - (const Corredor & elemento, \
                                    const Corredores & coleccion);
    friend Corredores operator - (const Corredores & coleccion, \
                                    const Corredor & elemento);
    friend Corredores operator - (const Corredores & coleccion, int num_dorsal);
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
    Corredor & operator() (const int num_casilla);
    Corredor & operator() (const int num_casilla) const;
    Corredor & operator[] (const int num_casilla);
    Corredor & operator[] (const int num_casilla) const;
    /********************************************************************/

    /*************************************************************************/
    /*************************************************************************/




    /*************************************************************************/
    //Getters
    /*************************************************************************/

    /********************************************************************/
    /* Devuelve el número de casillas ocupadas, o lo que es lo mismo, el número
    de corredores.
    */
    int Usados (void) const;

    /********************************************************************/
    /* Devuelve el número de casillas disponibles */
    int Capacidad (void) const;

    /********************************************************************/
    /* Devuelve "true" si la secuencia está vacía (usados == 0) */
	bool EstaVacia (void) const;

    /********************************************************************/
    /* Busca la posición de un corredor. 

        -Si el argumento es de tipo Corredor (corredor), buscará el corredor 
        en la coleccion por su dorsal (clave primaria)
        -Si el argumento es de tipo int (num_dorsal), buscará el corredor que 
        tenga dicho numero de dorsal.
        -Si el argumento es de tipo string (DNI), buscará el corredor que tenga
        un DNI coincidente.

    Devuelve la posición del primer elemento coincidente (debe ser unico), 
    o -1 si no se encuentra.

    Posiciones: 1, 2, ..., Usados()
    */
    int Busca (const Corredor & corredor) const;
    int Busca (const int dorsal) const;
    int Busca (const string el_DNI_buscado) const;
    /*************************************************************************/
    /*************************************************************************/



    /************************************************************************/
    //Metodos de manejo
    /************************************************************************/

    /********************************************************************/
    /* Inserta el elemento "nuevo" en la posición dada por "indice".

	PRE: 0 <= indice < Usados()
    */
	void Inserta (int indice, const Corredor & nuevo);

    /********************************************************************/
    /* Eliminar el contenido de la "casilla" cuya posición es "indice".

    PRE: 1 <= indice <= Usados()
    */
    void Elimina (int indice);

    /***********************************************************************/
    /*Devuelve una subcoleccion de la implicita desde la posicion "pos" con 
    "n" elementos.
    Si el numero de elementos es demasiado grande, devuelve una coleccion vacia.
    PRE: 1<=pos<=Usados()
    PRE: pos+n-1<=Usados()
    */
    Corredores SubColeccion (int pos, unsigned int cantidad) const;
    /***********************************************************************/

    /********************************************************************/
    /*Ordena la coleccion mediante el algoritmo de burbuja.
    
    *SE COMPARAN LAS CLAVES PRIMARIAS DE LOS ELEMENTOS*

    *NOTA: normalmente los datos estan ordenados, por ello, el algoritmo de 
    burbuja es el mas adecuado.
    */
    void Sort ();

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
    /*Devuelve una referencia al elemento de la casilla "indice"

    PRE: 0 <= indice < Usados()
    */
    Corredor & Valor (const int indice) const;


    /***********************************************************************/
    /* Aniade un elemento ("nuevo") al final de la coleccion (pos usados+1).
    
    Se redimensionará el vector dinámico de datos si no tuviera suficiente 
    espacio disponible.
    */
    void Aniade (const Corredor & nuevo);

    /***********************************************************************/
    /***********************************************************************/

};

/////////////////////////////////////////////////////////////////////////////

#endif
