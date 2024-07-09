/***************************************************************************/
/***************************************************************************/
// 
// Fichero: Corredores.cpp
//
// Archivo de implementación--> Definición de los métodos de la clase almacén
//                              "Corredores".
//
// Proyecto. FASE 02. 
//
/***************************************************************************/
/***************************************************************************/

#include "Corredor.h"
#include "Corredores.h"

#include "utils.h"
#include "Constantes.h"

#include <string>
#include <cstring>

#include <iostream>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////



/***********************************************************************/
// Constructor sin argumentos
/* Crea un vector con capacidad = TAM_BLOQUE. */
Corredores::Corredores (void) : Corredores(TAM_BLOQUE) {}


/***********************************************************************/
/* El valor del argumento "cap", será la capacidad inicial. 
POST: La secuencia creada estará vacía (EstaVacia() = true)
*/
Corredores::Corredores (int cap) : capacidad(cap), usados(0)
{
    ReservaMemoria(cap);
}


/***********************************************************************/
// Constructor de un solo elemento: Vector con un solo corredor
Corredores::Corredores (const Corredor & corredor) : Corredores(1)
{
    Aniade(corredor);
}


/***********************************************************************/
// Constructor de copia
Corredores::Corredores (const Corredores & otro) : Corredores(otro.Capacidad())
{
    CopiaDatos(otro);
}


/***********************************************************************/
// Destructor 
Corredores::~Corredores (void)
{
    LiberaMemoria();
}

/***********************************************************************/



/***********************************************************************/
/* Sobrecarga del operador de asignación para copia profunda.
    Parámetros:
    otro (referencia), objeto que sirve de modelo.
*/
Corredores & Corredores::operator = (const Corredores & otro)
{

    if (this != &otro){
    
        LiberaMemoria();   // Libera la memoria en deshuso

        ReservaMemoria(otro.capacidad); // Pide memoria para los datos

        CopiaDatos(otro);   // Copia los datos

    }

    return (*this);
}


/***********************************************************************/
/* Sobrecarga de los operadores () y [] para el acceso al
elemento de la casilla "num_casilla".
Consulta ó modifica el valor de una casilla dada:
    Si se utiliza como rvalue se emplea para consultar el
        valor de la casilla "num_casilla".
    Si se utiliza como lvalue se emplea para modificar el
        valor de la casilla "num_casilla".
        
PRE: 1 <= num_casilla <= Usados()
*/
Corredor & Corredores::operator() (const int num_casilla)
{
    return Valor(num_casilla-1);
}
Corredor & Corredores::operator() (const int num_casilla) const
{
    return Valor(num_casilla-1);
}
Corredor & Corredores::operator[] (const int num_casilla)
{
    return Valor(num_casilla-1);
}
Corredor & Corredores::operator[] (const int num_casilla) const
{
    return Valor(num_casilla-1);
}


/***********************************************************************/
/* Devuelve el número de casillas ocupadas, o lo que es lo mismo, el número
de corredores.
*/
int Corredores::Usados (void) const
{
    return usados;
}


/***********************************************************************/
/* Devuelve el número de casillas disponibles */
int Corredores::Capacidad (void) const
{
    return capacidad;
}


/***********************************************************************/
/* Devuelve "true" si la secuencia está vacía (total_utilizados == 0) */
bool Corredores::EstaVacia (void) const
{
    return usados == 0;
}


/***********************************************************************/
/* "Vacía" completamente el vector.
POST: Capacidad() == 0.
POST: EstaVacia() == true 
*/
void Corredores::EliminaTodos()
{
    LiberaMemoria();
}


/***********************************************************************/
/* Inicializa todas las casillas del vector a un corredor dado.
*/
void Corredores::Ecualiza (const Corredor & corredor)
{
    for (int i=0; i < usados; i++)
        Valor(i) = corredor;
}


/***********************************************************************/
/* Devuelve una copia profunda del objeto implicito.
Parámetros: 
    otra (referencia), objeto que sirve de modelo para la copia. 
*/
Corredores Corredores::Clona (const Corredores & otra)
{
    return Corredores(*this);
}

/***********************************************************************/
/* Añade un Corredor ("nuevo") al vector al final (posicion usados+1).
Parámetros: 
    nuevo, valor que se añade a la secuencia.

El nuevo elemento se coloca al final del vector.

Se redimensionará el vector dinámico de datos si no tuviera suficiente 
espacio disponible.
*/
void Corredores::Aniade (const Corredor & nuevo)
{
    if (usados + 1 > capacidad)
        Redimensiona();
    
    Valor(usados) = nuevo;  //Aniade el nuevo objeto.

    usados++;   // Actualiza el numero de corredores
}


/***********************************************************************/
/* Inserta el valor "nuevo" en la posición dada por "indice".
Parámetros: 
    nuevo, Corredor que se añade al vector. 

"Desplaza" todos los enteros una posición a la derecha antes de copiar en 
"indice" el nuevo corredor

PRE: 1 <= indice < Usados()
*/
void Corredores::Inserta (int indice, const Corredor & nuevo)
{
    // Comprueba que haya suficiente espacio
    if (usados + 1 > capacidad)
        Redimensiona();
    
	// Desplaza los corredores desde la casilla "indice" hasta el ultimo 
	// una posición a la derecha
    for (int i = usados; i >= indice; i--)
        Valor(i)=Valor(i-1);

    // Copia "nuevo" en la posicion indice 
    Valor(indice-1) = nuevo;

    usados++;   // Actualiza el numero de corredores
}


/***********************************************************************/
/* Eliminar el contenido de la "casilla" cuya posición es "indice".
Parámetros: 
    indice, Numero de casilla que se elimina. 
PRE: 1 <= indice < Usados()
*/
void Corredores::Elimina (int indice)
{
    // Desplaza los corredores desde el ultimo hasta la casilla "indice"
    // una posición a la izquierda
    for (int i = indice; i < usados-indice+1; i++)
        Valor(i) = Valor(i+1);
    
    usados--;   // Actualiza el numero de corredores
}


/***********************************************************************/
/* Compone un string con todos los caracteres que están almacenados en 
la secuencia y lo devuelve.*/
string Corredores::ToString()
{
    string cadena = "\n";

    string delimitador(80,'.');

    //"CABECERA"
    /*
     DORSAL        NOMBRE              DNI         NACIMIENTO      SEXO
    .....................................................................
    */

    cadena += " DORSAL  ";

    cadena +=FormatString("NOMBRE", NUM_CASILLAS_NOMBRE, ' ', \
                                                TipoAlineacion::Centro) + "  ";

    cadena +=FormatString("DNI", 9, ' ', TipoAlineacion::Centro) + "  ";

    cadena += "NACIMIENTO  ";

    cadena += "SEXO ";

    cadena += '\n' + delimitador + '\n';

    int num_corredores = 0;
    
    //CORREDORES
    for (int i = 0; i < usados; i++)

        cadena += Valor(i).ToString() + '\n';    

	return (cadena);
}
/***********************************************************************/


/***************************************************************************/
/***************************************************************************/
// MÉTODOS PRIVADOS DE LA CLASE Corredores
/***************************************************************************/
/***************************************************************************/

/***********************************************************************/
/* Pide memoria para guardar "num_casillas" datos.
PRE: haber liberado memoria previamente.
PRE: 0 <= Usados()
*/
void Corredores::ReservaMemoria (const int num_casillas)
{
    datos = new Corredor [num_casillas];

    capacidad = num_casillas;

    usados = 0;
}

/***********************************************************************/
/* Libera memoria dinámica reservada para los datos */
void Corredores::LiberaMemoria (void)
{
    if (datos != nullptr){

        delete [] datos;

        datos = nullptr;

        capacidad = usados = 0;
    }
}

/***********************************************************************/
/* Copia datos desde otro objeto de la clase
    PRE: Se ha reservado memoria para los datos
*/
void Corredores::CopiaDatos (const Corredores & otro)
{
	// Actualiza el numero de corredores
	usados = otro.usados;

	// Copiar los valores de los datos
    for (int i = 0; i < usados; i++)
        Valor(i) = otro.Valor(i);
}

/***********************************************************************/
/* Redimensiona el vector dinámico y copia los datos en el nuevo almacén.  
Pedirá memoria adicional si el número de casillas a usar es superior 
a la capacidad actual. El número de casillas adicionales será "TAM_BLOQUE".
*/
void Corredores::Redimensiona (void)
{   
    capacidad += TAM_BLOQUE;
    
    // Pide memoria para el nuevo vector
    Corredor * tmp = new Corredor[capacidad] ;

	// Copiar los valores de los datos
    for (int i = 0; i < usados; i++)
        tmp[i] = Valor(i);

    //Libera la memoria del vector en deshuso 
    delete [] datos;

    // Actualiza el puntero de datos
    datos = tmp;
}


/***********************************************************************/
/*Devuelve una referencia al elemento de la casilla "indice"
Parámetros: 
    indice, Numero de casilla a la que se accede. 
PRE: 1 <= indice <= Usados()
*/
inline Corredor & Corredores::Valor (const int indice) const
{
    return (datos[indice]);
}

/***********************************************************************/
/***********************************************************************/



/////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////