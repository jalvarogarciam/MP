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
// Constructor de copia
Corredores::Corredores (const Corredores & otro) : Corredores(otro.Capacidad())
{
    Clona(otro);
}


/***********************************************************************/
// Destructor 
Corredores::~Corredores (void)
{
    LiberaMemoria();
}

/***********************************************************************/


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
POST: Capacidad() == TAMANIO.
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
    for (size_t i=0; i < usados; i++)
        datos[i].Clona(corredor);
}


/***********************************************************************/
/*Devuelve una referencia al elemento de la casilla "indice"
Parámetros: 
    indice, Numero de casilla a la que se accede. 
PRE: 1 <= indice <= TotalUtilizados()
*/
Corredor & Corredores::Valor (const int indice)
{
    return (el_valor(indice));
}
Corredor & Corredores::Valor (const int indice) const
{
    return (el_valor(indice));
}


/***********************************************************************/
/* Copia profunda.
Parámetros: 
    otro (referencia), objeto que sirve de modelo para la copia. 
*/
void Corredores::Clona (const Corredores & otro)
{
    LiberaMemoria();

    capacidad = otro.capacidad;

    ReservaMemoria(capacidad);

    CopiaDatos(otro);

    usados = otro.usados;
}


/***********************************************************************/
/* Añade un Corredor ("nuevo") al vector al final (posicion usados+1).
Parámetros: 
    nuevo, valor que se añade a la secuencia.

El nuevo elemento se coloca al final del vector.

Se redimensionará el vector dinámico de datos si no tuviera suficiente 
espacio disponible.
*/
void Corredores::Aniade (const Corredor nuevo)
{
    Inserta(usados+1,nuevo);
}


/***********************************************************************/
/* Inserta el valor "nuevo" en la posición dada por "indice".
Parámetros: 
    nuevo, Corredor que se añade al vector. 

"Desplaza" todos los enteros una posición a la derecha antes de copiar en 
"indice" el nuevo corredor

PRE: 1 <= indice < TotalUtilizados()
*/
void Corredores::Inserta (int indice, Corredor nuevo)
{
    // Comprueba que haya suficiente espacio
    if (usados + 1 > capacidad)
        Redimensiona();
    
	// Desplaza los corredores desde la casilla "indice" hasta el ultimo 
	// una posición a la derecha
	memmove (datos+indice, datos+indice-1, (usados-indice+1)*sizeof(Corredor)); 

    // Copia "nuevo" en la posicion indice 
    datos[indice-1].Clona(nuevo);

    usados++;   // Actualiza el numero de corredores
}


/***********************************************************************/
/* Eliminar el contenido de la "casilla" cuya posición es "indice".
Parámetros: 
    indice, Numero de casilla que se elimina. 
PRE: 1 <= indice < TotalUtilizados()
*/
void Corredores::Elimina (int indice)
{
    // Desplaza los corredores desde el ultimo hasta la casilla "indice"
    // una posición a la izquierda
    memmove (datos+indice, datos+indice+1, (usados-indice+1)*sizeof(Corredor)); 
    
    usados--;   // Actualiza el numero de corredores
}

/***********************************************************************/
// Compone un string con todos los caracteres que están
// almacenados en la secuencia y lo devuelve.

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
    for (size_t i = 1; i <= usados; i++)

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
PRE: 0 <= num_casillas
*/
void Corredores::ReservaMemoria (const int num_casillas)
{
    datos = new Corredor [num_casillas];

    capacidad = num_casillas;
}

/***********************************************************************/
/* Libera memoria dinámica reservada para los datos */
void Corredores::LiberaMemoria (void)
{
    if (datos){

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
    memcpy(datos, otro.datos, otro.usados*sizeof(Corredor));
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

    // Copiar los datos 
	memcpy (tmp, datos, usados*sizeof(Corredor)); 

    //Libera la memoria del vector en deshuso 
    delete [] datos;

    // Actualiza el puntero de datos
    datos = tmp;
}

/***********************************************************************/
/* Método PRIVADO compartido por: 
        Corredor & Valor (const int indice);
        Corredor & Valor (const int indice) const;
para evitar la duplicidad de código.

Devuelve una referencia a un dato Corredor del vector dada su posición. 

PRE: 1 <= indice <= NumCorredores()
*/
Corredor & Corredores::el_valor (int indice) const
{
    return (datos[indice-1]);
}

/***********************************************************************/
/***********************************************************************/



/////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////