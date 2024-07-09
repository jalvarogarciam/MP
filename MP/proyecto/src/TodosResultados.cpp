/******************************************************************************/
/******************************************************************************/
// 
// Fichero: Resultados.cpp
//
// Archivo de implementación--> Definición de los métodos de la clase almacén
//                              "Resultados".
//
// Proyecto. FASE 4. 
//
/******************************************************************************/
/******************************************************************************/

#include "Resultados.h"
#include "TodosResultados.h"

#include "Constantes.h"

#include <iomanip>
#include <sstream>


using namespace std;


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*****************************************************************************/
//CONSTRUCTORES Y DESTRUCTOR
/*****************************************************************************/

/************************************************************************/
/*Constructor sin argumentos
 Crea un vector con capacidad = TAMANIO. */
TodosResultados::TodosResultados (void) : TodosResultados(TAMANIO) {}

/************************************************************************/
/* El valor del argumento "cap", será la capacidad inicial. 
POST: La secuencia creada estará vacía (EstaVacia() = true)
*/
TodosResultados::TodosResultados (int cap) : capacidad(cap), usados(0)
{
    ReservaMemoria(cap);
}

/************************************************************************/
// Constructor de un solo elemento: Vector con un solo resultado
TodosResultados::TodosResultados (const Resultados & resultado) 
                : TodosResultados(1)
{
    Aniade(resultado);
}

/************************************************************************/
// Constructor de copia
TodosResultados::TodosResultados (const TodosResultados & otro) 
                : TodosResultados(otro.Capacidad())
{
    CopiaDatos(otro);
}

/************************************************************************/
// Destructor 
TodosResultados::~TodosResultados (void)
{
    LiberaMemoria();
}

/************************************************************************/
/* "Vacía" completamente el vector.
POST: Capacidad() == 0.
POST: EstaVacia() == true 
*/
void TodosResultados::EliminaTodos()
{
    LiberaMemoria();
}
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
// ENTRADA/SALIDA
/*****************************************************************************/

/************************************************************************/
/*Operadores de inserción (>>) y extracción sobre flujos (<<)
La entrada tiene el mismo formato que la salida: campo * campo * ... *
siendo '*' un delimitador.
*/
ostream & operator << (ostream & out, const TodosResultados & este)
{
    //Ajusto las preferencias del flujo
    out.setf(ios::showpoint);
    out.setf(ios::fixed);
    out.precision(NC_DEC); //numero de cifras decimales a mostrar

    for (int i = 0; i < este.usados; i++)
        out << este.datos[i] << endl;

    return (out);
}

istream & operator >> (istream & in, TodosResultados & este)
{
    //vacía el vector manteniendo la capacidad
    este = TodosResultados(este.capacidad); 

    Resultados resultados;

    in >> resultados;

	while (!in.eof()) {
		// Añade el elemento leido a la colección  
		este += resultados;
        in >> resultados;
	}

    este += resultados; //para el ultimo

    return in; // devuelve referencia al objeto istream
}
/************************************************************************/

/************************************************************************/
/* Compone un string con todos los elementos de la coleccion y lo devuelve.*/
string TodosResultados::ToString(string msg)
{
    ostringstream oss;  //flujo de salida asociado a string

    //Ajusto las preferencias del flujo
    oss.setf(ios::showpoint);
    oss.setf(ios::fixed);
    oss.precision(NC_DEC); //numero de cifras decimales a mostrar

    if (msg != "" ) oss << "\n" + (msg) + "\n\n";

    string delimitador(20,'=');


    for (int i = 1; i <= usados; i++){

        //"CABECERA"
        /*
        ====================
        CARRERA: 1
        ====================
        */
        oss << delimitador << endl;
        oss << " CARRERA:    " << setfill (' ') << setw(7) << left << i << endl;
        oss << delimitador << endl;


        //RESULTADOS
        oss << (*this)[i].ToString();

        oss << "Total participantes =    " << (*this)[i].Usados() << endl;
        oss << endl;
    }

    oss << delimitador << endl ;

	return (oss.str());
}
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
//OPERADORES
/*****************************************************************************/

/************************************************************************/
/* Operador de asignación para copia profunda.
*/
TodosResultados & TodosResultados::operator = (const TodosResultados & otro)
{

    if (this != &otro){
    
        LiberaMemoria();   // Libera la memoria en deshuso

        ReservaMemoria(otro.capacidad); // Pide memoria para los datos

        CopiaDatos(otro);   // Copia los datos

    }

    return (*this);
}

/************************************************************************/
/* Operadores combinados += y -= para aniadir o eliminar un elemento o conjunto
al original.
*/
TodosResultados & TodosResultados::operator += \
                                            (const TodosResultados & coleccion)
{
    *this = (*this + coleccion);

    return *this;
}
TodosResultados & TodosResultados::operator += (const Resultados & elemento)
{
    /*Podría hacer la implementacion "canonica" 
    *this += TodosResultados(elemento),
    Sin embargo, en los casos en los que elemento esté en la coleccion,
    haría liberaciones, reservas y copias de memoria innecesarias.
    */
    if (!(elemento&&(*this)))   //si elemento no está en la coleccion,
        Aniade(elemento);       // lo aniade
    
    return *this;
}

TodosResultados & TodosResultados::operator -= \
                                            (const TodosResultados & coleccion)
{
    *this = (*this - coleccion);

    return *this;
}
TodosResultados & TodosResultados::operator -= (const Resultados & elemento)
{
    /*Podría hacer la implementacion "canonica" *this -= Resultados(elemento),
    Sin embargo, en los casos en los que elemento esté en la coleccion,
    haría liberaciones, reservas y copias de memoria innecesarias.
    */
    int posicion = Busca(elemento);
    if (posicion != -1)     //si elemento está en la coleccion,
        Elimina(posicion);  // lo elimina
    
    return *this;
}
/************************************************************************/


/************************************************************************/
/* Operadores () y [] para el acceso al elemento de la casilla "num_casilla".

Consulta ó modifica el valor de una casilla dada:
    Si se utiliza como rvalue se emplea para consultar el
        valor de la casilla "num_casilla".
    Si se utiliza como lvalue se emplea para modificar el
        valor de la casilla "num_casilla".

PRE: 1 <= num_casilla <= Usados()
*/
Resultados & TodosResultados::operator() (const int num_casilla)
{
    return (*this)[num_casilla];
}
Resultados & TodosResultados::operator() (const int num_casilla) const
{
    return (*this)[num_casilla];
}
Resultados & TodosResultados::operator[] (const int num_casilla)
{
    return Valor(num_casilla-1);
}
Resultados & TodosResultados::operator[] (const int num_casilla) const
{
    return Valor(num_casilla-1);
}

/* Operador () para el acceso al elemento de la casilla "num_resultado" de
la coleccion num_carrera.
*/
Resultado & TodosResultados::operator() (const int num_carrera, \
                                                    const int num_resultado)
{
    return (*this)[num_carrera][num_resultado];
}

Resultado & TodosResultados::operator() (const int num_carrera, \
                                                const int num_resultado) const
{
    return (*this)[num_carrera][num_resultado];
}
/************************************************************************/

/************************************************************************/
/* Operador == y !=
Dos colecciones serán iguales si contienen el mismo número de objetos y todos
sus objetos son iguales (misma clave primaria). 
De lo contrario, serán diferentes (!=).
//PRE: No hay elementos repetidos en ninguna coleccion.
*/
bool TodosResultados::operator == (const TodosResultados & otro) const
{
    bool iguales = true;

    if ( usados != otro.usados ) // Compara las dimensiones.
        iguales = false;

    //Para cada elemento del primer conjunto, comprueba si está en el segundo.
    int i = 1;
    for (;(i < usados) && ((*this)[i]&&otro); i++);
    
    if (i != usados) iguales = false;

    return iguales;
}
// Operador != 
bool TodosResultados::operator != (const TodosResultados & otro) const
{
    return !(*this == otro);
}
/***********************************************************************/



/***********************************************************************/
// Operador binario && para comprobar la pertenencia/inclusión de:

//una coleccion(otro) dentro de otra coleccion(este)
bool operator && (const TodosResultados & este, const TodosResultados & otro)
{
    //Si este es de menor tamaño que el otro, este no lo puede incluir
    bool contiene = este.usados>=otro.usados ? true:false;

    //Comprueba si todos los elementos del otro estan en este
    if (contiene){

        int i = 1;
        for (; i <= otro.usados && este.Busca(otro[i]) != -1; i++ );

        //si no todos los elementos estan contenidos en este:
        if (i != otro.usados+1) contiene = false;
    }
    
    return contiene;
}

//un elemento dentro de una coleccion.
bool operator && (const TodosResultados & coleccion, const Resultados & elemento)
{
    return coleccion&&TodosResultados(elemento);
}
bool operator && (const Resultados & elemento, const TodosResultados & coleccion)
{
    return coleccion&&TodosResultados(elemento);
}

//un elemento (representado por un int, clave primaria) en una coleccion.
bool operator && (const TodosResultados & coleccion, int clave_primaria)
{
    return coleccion&&TodosResultados(Resultados(clave_primaria));
}
bool operator && (int clave_primaria, const TodosResultados & coleccion)
{
    return coleccion&&TodosResultados(Resultados(clave_primaria));
}
/***********************************************************************/


/***********************************************************************/
// Operaciones de conjuntos (union, diferencia e interseccion)

/* Operador binario * para la INTERSECCION de dos colecciones.
Devuelve una coleccion con los elementos comunes entre las dos colecciones.
*/
TodosResultados TodosResultados::operator* (const TodosResultados & otro) const
{
    TodosResultados resultado;   //El tamaño minimo de la interseccion es 0

    //El tamanio maximo de la interseccion sera el del conjunto mas pequeño
    const TodosResultados * conjunto_menor= usados>otro.usados ? &otro:this;

    //conjunto mayor apunta al que no apunta conjunto menor
    const TodosResultados * conjunto_mayor= conjunto_menor == this ? &otro:this;

    //Aniade los elementos al resultado
    for (int i = 1; i <= (*conjunto_menor).usados; i++)

        //si está en uno y está en otro
        if (((*conjunto_menor)[i]&&(*conjunto_mayor)))

            resultado += (*conjunto_menor)[i];

    return resultado;
}

/* Operador binario + para la UNION de dos colecciones.
Devuelve una coleccion con los elementos presentes en uno o en otro.
*/
//dos colecciones
TodosResultados operator + (const TodosResultados & este, const TodosResultados & otro)
{
    //El tamanio maximo de la union sera el del conjunto mayor
    const TodosResultados * conjunto_mayor= este.usados<otro.usados ? &otro:&este;

    //conjunto menor apunta al que no apunta conjunto mayor
    const TodosResultados * conjunto_menor= conjunto_mayor == &este ? &otro:&este;

    // La union tendrá como mínimo todos los elementos del mayor
    TodosResultados resultado(*conjunto_mayor);

    for (int i = 1; i<=(*conjunto_menor).usados; i++)

        if (!((*conjunto_menor)[i]&&resultado)) //Si no está ya aniadido

            resultado.Aniade((*conjunto_menor)[i]);

    return resultado;
}
//una coleccion y un elemento (coleccion de un solo elemento)
TodosResultados operator + (const Resultados & elemento, const TodosResultados & coleccion)
{
    return coleccion+TodosResultados(elemento);
}
TodosResultados operator + (const TodosResultados & coleccion, const Resultados & elemento)
{
    return coleccion+TodosResultados(elemento);
}

/* Operador binario - para la DIFERENCIA de dos colecciones.
Devuelve una coleccion con los elementos presentes en la primera y
no presentes en la segunda.
NOTA: la diferencia no es conmutativa.
*/
//dos colecciones este-otro
TodosResultados operator - (const TodosResultados & este, \
                            const TodosResultados & otro)
{
    TodosResultados resultado;   //El tamaño minimo de la diferencia es 0

    for (int i = 1; i<=este.usados; i++)

        if (!(este[i]&&otro)) //Si no está en el otro

            resultado.Aniade(este[i]);

    return resultado;
}
//una coleccion y un elemento (coleccion de un solo elemento)
TodosResultados operator - (const Resultados & elemento, \
                            const TodosResultados & coleccion)
{
    return TodosResultados(elemento) - coleccion;
}
TodosResultados operator - (const TodosResultados & coleccion, \
                            const Resultados & elemento)
{
    return coleccion - TodosResultados(elemento);
}
/***********************************************************************/

/*****************************************************************************/
/*****************************************************************************/






/*****************************************************************************/
//Getters
/*****************************************************************************/

/***********************************************************************/
// Devuelve el número de casillas ocupadas.
int TodosResultados::Usados (void) const {return usados;}

/***********************************************************************/
// Devuelve el número de casillas disponibles
int TodosResultados::Capacidad (void) const {return capacidad;}

/***********************************************************************/
/* Devuelve "true" si la secuencia está vacía (total_utilizados == 0) */
bool TodosResultados::EstaVacia (void) const {return usados == 0;}

/************************************************************************/
/* Busca la posición de un resultado pasado como argumento. 

Devuelve la posición del primer elemento coincidente (debe ser unico), 
o -1 si no se encuentra.

Posiciones: 1, 2, ..., Usados()
*/
int TodosResultados::Busca (const Resultados & coleccion_resultados) const
{
    int posicion= -1;

    int i = 1;
    for (;i <= usados && coleccion_resultados != (*this)[i]; i++);
    
    if (i != usados+1) {posicion = i;}

    return posicion;
}
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
//Metodos de manejo
/*****************************************************************************/

/***********************************************************************/
/* Inserta el valor "nuevo" en la posición dada por "indice".

"Desplaza" todos los elementos una posición a la derecha antes de copiar en 
"indice" el nuevo elemento

PRE: 1 <= indice <= Usados()
PRE: hay suficiente capacidad en la coleccion
*/
void TodosResultados::Inserta (int indice, const Resultados & nuevo)
{
    int posicion = Busca(nuevo);

    if (posicion == -1){//si no está en la coleccion
        
        // Desplaza los elementos desde la casilla "indice" hasta el ultimo 
        // una posición a la derecha
        for (int i = usados; i >= indice; i--)
            
            datos[i] = datos[i-1];

        // Copia "nuevo" en la posicion indice 
        datos[indice-1] = nuevo;

        usados++;   // Actualiza el numero de elementos
    
    }else{  //si está en la coleccion, lo inserta en el lugar indicado.

        (*this) -= nuevo;

        Inserta(indice, nuevo);
    }
}

/***********************************************************************/
/* Eliminar el contenido de la "casilla" cuya posición es "indice".

PRE: 1 <= indice <= Usados()
*/
void TodosResultados::Elimina (int indice)
{
    // Desplaza los elementos desde el ultimo hasta la casilla "indice"
    // una posición a la izquierda
    for (int i = indice; i < usados-indice+1; i++)
        datos[i-1] = datos[i];
    
    usados--;   // Actualiza el numero de elementos
}




/***************************************************************************/
/***************************************************************************/
// MÉTODOS PRIVADOS DE LA CLASE Resultados
/***************************************************************************/
/***************************************************************************/

/***********************************************************************/
/* Pide memoria para guardar "num_casillas" datos.
PRE: haber liberado memoria previamente.
PRE: 0 <= Usados()
*/
void TodosResultados::ReservaMemoria (const int num_casillas)
{
    datos = new Resultados [num_casillas];

    capacidad = num_casillas;

    usados = 0;
}

/***********************************************************************/
/* Libera memoria dinámica reservada para los datos
*/
void TodosResultados::LiberaMemoria (void)
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
void TodosResultados::CopiaDatos (const TodosResultados & otro)
{
	// Actualiza el numero de elementos y la capacidad
	usados = otro.usados;
    capacidad = otro.capacidad;

	// Copiar los valores de los datos
    for (int i = 0; i < usados; i++)
        datos[i] = otro.datos[i];
}


/***********************************************************************/
/*Devuelve una referencia al elemento de la casilla "indice"
Parámetros: 
    indice, Numero de casilla a la que se accede. 
PRE: 0 <= indice < Usados()
*/
inline Resultados & TodosResultados::Valor (const int indice) const
{
    return (datos[indice]);
}

/***********************************************************************/
/* Aniade un elemento ("nuevo") al final de la coleccion (posicion usados+1).

PRE: hay suficiente capacidad en la coleccion
*/
void TodosResultados::Aniade (const Resultados & nuevo)
{
    datos[usados] = nuevo;  //Aniade el nuevo objeto.

    usados++;   // Actualiza el numero de elementos
}

/***********************************************************************/
/***********************************************************************/



/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////