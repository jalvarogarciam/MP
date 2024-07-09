/***************************************************************************/
/***************************************************************************/
// 
// Fichero: Categorias.cpp
//
// Archivo de implementación--> Definición de los métodos de la clase almacén
//                              "Categorias".
//
// Proyecto. FASE 4. 
//
/***************************************************************************/
/***************************************************************************/

#include "Categoria.h"
#include "Categorias.h"

#include "Constantes.h"

#include "Utils.h"

#include <iomanip>
#include <sstream>
#include <fstream>


using namespace std;


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

/*****************************************************************************/
//CONSTRUCTORES Y DESTRUCTOR
/*****************************************************************************/

/***********************************************************************/
/*Constructor sin argumentos
 Crea un vector con capacidad = TAM_BLOQUE. */
Categorias::Categorias (void) : Categorias(TAM_BLOQUE) {}

/***********************************************************************/
/* El valor del argumento "cap", será la capacidad inicial. 
POST: La secuencia creada estará vacía (EstaVacia() = true)
*/
Categorias::Categorias (int cap) : capacidad(cap), usados(0)
{
    ReservaMemoria(cap);
}

/***********************************************************************/
// Constructor de un solo elemento: Vector con un solo categoria
Categorias::Categorias (const Categoria & categoria) : Categorias(1)
{
    Aniade(categoria);
}

/***********************************************************************/
// Constructor de copia
Categorias::Categorias (const Categorias & otro) : Categorias(otro.Capacidad())
{
    CopiaDatos(otro);
}

/***********************************************************************/
/* Constructor de fichero. Construye la coleccion a partir de la 
información guardada en un fichero de texto llamado nombre.
*/
Categorias::Categorias (const string & nombre) : Categorias()
{
    LeerCategorias(nombre);
}

/***********************************************************************/
// Destructor 
Categorias::~Categorias (void)
{
    LiberaMemoria();
}
/***********************************************************************/

/***********************************************************************/
/* "Vacía" completamente el vector.
POST: Capacidad() == 0.
POST: EstaVacia() == true 
*/
void Categorias::EliminaTodos()
{
    LiberaMemoria();
}
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
// ENTRADA/SALIDA
/*****************************************************************************/

/***********************************************************************/
/*Operadores de inserción (>>) y extracción sobre flujos (<<)
La entrada tiene el mismo formato que la salida: campo * campo * ... *
siendo '*' un delimitador.
*/
ostream & operator << (ostream & out, const Categorias & este)
{
    //Ajusto las preferencias del flujo
    out.setf(ios::showpoint);
    out.setf(ios::fixed);
    out.precision(NC_DEC); //numero de cifras decimales a mostrar

    for (int i = 0; i < este.usados; i++)
        out << este.datos[i] << endl;

    return (out);
}

istream & operator >> (istream & in, Categorias & este)
{

    este.LiberaMemoria();   //Libera la memoria actual

    string linea;

	getline(in, linea); // Lectura adelantada

	while (!in.eof()) {

		// Añade el elemento leido a la colección  
		este += Categoria(linea);

		// Leer la siguiente linea 
		getline(in, linea); 
	}

    return in; // devuelve referencia al objeto istream
}


/************************************************************************/
/*Método de escritura. Guarda un dato Corredores en un fichero de texto 
llamado nombre.
    • Si el vector está vacío no se crea el fichero.
    • El vector no se modifica
*/
void Categorias::EscribirCategorias (const string & nombre) const
{
    if (usados>0){  //si el vector no esta vacio...

        // flujo de entrada asociado a fichero
        ofstream ofs;

        ofs.open(nombre);   //sobreescribe el contenido

        if (ofs){

            cabecera_ficheros(ofs,"CATEGORIAS");

            ofs << *this;   // copia los elementos

            ofs.close();
        }
    }
}

/************************************************************************/
/*Método de lectura. Lee un dato Corredores de un fichero de texto 
llamado nombre.
    • El vector siempre se modifica.
    • Si el fichero indicado no fuera un fichero del tipo esperado, 
    el vector quedará vacío.
*/
void Categorias::LeerCategorias (const string & nombre)
{
    ifstream ifs(nombre);   // flujo de entrada asociado al fichero nombre

    if (!ifs)   EliminaTodos();
    else
    {
        //OMISION DE CONTENIDO SUPERFLUO
        prepara_flujo_datos(ifs,"CATEGORIAS");

        //LECTURA DE DATOS
        ifs >> *this ;
    }
    ifs.close();
}

/************************************************************************/
/* Compone un string con todos los elementos de la coleccion y lo devuelve.*/
string Categorias::ToString(string msg)
{
    ostringstream oss;  //flujo de salida asociado a string

    //Ajusto las preferencias del flujo
    oss.setf(ios::showpoint);
    oss.setf(ios::fixed);
    oss.precision(NC_DEC); //numero de cifras decimales a mostrar

    if (msg != "" ) oss << "\n" + (msg) + "\n\n";

    string delimitador(35,'.');

    //"CABECERA"
    /*
     NUM      CATEGORIA   NACIMIENTO
    ...................................
    ^ 6C ^^     16C      ^^    13C    ^
    */


    oss << " NUM ";

    //           __(4 espacios)_CATEGORIA_(3 espacios)__
    oss << setfill(' ') << setw(((NC_DENOM_CAT+8)/2)+5) << right << "CATEGORIA"\
        << setfill(' ') << setw(((NC_DENOM_CAT+8)/2)-5) << " ";

    oss << "  NACIMIENTO ";

    oss << endl << delimitador << endl;

    //CATEGORIAS
    for (int i = 1; i <= usados; i++)

        oss << (*this)[i].ToString() + '\n';

    oss << endl;

	return (oss.str());
}

/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
//OPERADORES
/*****************************************************************************/

/***********************************************************************/
/* Operador de asignación para copia profunda.
*/
Categorias & Categorias::operator = (const Categorias & otro)
{

    if (this != &otro){
    
        LiberaMemoria();   // Libera la memoria en deshuso

        ReservaMemoria(otro.capacidad); // Pide memoria para los datos

        CopiaDatos(otro);   // Copia los datos

    }

    return (*this);
}

/***********************************************************************/
/* Operadores combinados += y -= para aniadir o eliminar un elemento o conjunto
al original.
*/
Categorias & Categorias::operator += (const Categorias & coleccion)
{
    *this = (*this + coleccion);

    return *this;
}
Categorias & Categorias::operator += (const Categoria & elemento)
{
    /*Podría hacer la implementacion "canonica" *this += Categorias(elemento),
    Sin embargo, en los casos en los que elemento esté en la coleccion,
    haría liberaciones, reservas y copias de memoria innecesarias.
    */
    if (!(elemento&&(*this)))   //si elemento no está en la coleccion,
        Aniade(elemento);       // lo aniade
    
    return *this;
}
//elemento representado por su clave primaria, id_categoria
Categorias & Categorias::operator += (int id_categoria)
{
    return (*this) += Categoria(id_categoria);
}

Categorias & Categorias::operator -= (const Categorias & coleccion)
{
    *this = (*this - coleccion);

    return *this;
}
Categorias & Categorias::operator -= (const Categoria & elemento)
{
    /*Podría hacer la implementacion "canonica" *this -= Categorias(elemento),
    Sin embargo, en los casos en los que elemento esté en la coleccion,
    haría liberaciones, reservas y copias de memoria innecesarias.
    */
    int posicion = Busca(elemento);
    if (posicion != -1)     //si elemento está en la coleccion,
        Elimina(posicion);  // lo elimina
    
    return *this;
}
//elemento representado por su clave primaria, id_categoria
Categorias & Categorias::operator -= (int id_categoria)
{
    return (*this) -= Categoria(id_categoria);
}
/***********************************************************************/


/***********************************************************************/
/* Operador == y !=
Dos colecciones serán iguales si contienen el mismo número de objetos y todos
sus objetos son iguales (misma clave primaria). 
De lo contrario, serán diferentes (!=).
//PRE: No hay elementos repetidos en ninguna coleccion.
*/
bool Categorias::operator == (const Categorias & otro) const
{
    bool iguales = true;

    if ( usados != otro.usados ) // Compara las dimensiones.
        iguales = false;

    if (iguales){

        //Para cada elemento del primer conjunto, 
        //comprueba si está en el segundo.
        int i = 1;
        for (;(i < usados) && ((*this)[i]&&otro); i++);
        
        if (i != usados) iguales = false;
    }

    return iguales;
}
// Operador != 
bool Categorias::operator != (const Categorias & otro) const
{
    return !(*this == otro);
}

/***********************************************************************/
/* Operadores >, >=, <, <=
*/
/* Una coleccion sera mayor que otra si y solo si tiene mas elementos
que la otra */
bool Categorias::operator > (const Categorias & otro) const
{
    return (usados > otro.usados);
}

/* Una coleccion sera mayor o igual que otra si tiene mas o el mismo
numero de elementos que la otra.*/
bool Categorias::operator >= (const Categorias & otro) const
{
    return !((*this) < otro);
}

/* Una coleccion sera menor que otra si y solo si tiene menos elementos
que la otra.*/
bool Categorias::operator < (const Categorias & otro) const
{
    return (usados < otro.usados);
}

/* Una coleccion sera mayor o igual que otra si tiene menos o el mismo
numero de elementos que la otra.*/
bool Categorias::operator <= (const Categorias & otro) const
{
    return !((*this) > otro);
}
/***********************************************************************/

/***********************************************************************/
// Operador binario && para comprobar la pertenencia/inclusión de:

//una coleccion(otro) dentro de otra coleccion(este)
bool operator && (const Categorias & este, const Categorias & otro)
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
bool operator && (const Categorias & coleccion, const Categoria & elemento)
{
    return coleccion&&Categorias(elemento);
}
bool operator && (const Categoria & elemento, const Categorias & coleccion)
{
    return coleccion&&Categorias(elemento);
}

//un elemento (representado por un int, clave primaria) en una coleccion.
bool operator && (const Categorias & coleccion, int clave_primaria)
{
    return coleccion&&Categorias(Categoria(clave_primaria));
}
bool operator && (int clave_primaria, const Categorias & coleccion)
{
    return coleccion&&Categorias(Categoria(clave_primaria));
}
/***********************************************************************/


/***********************************************************************/
// Operaciones de conjuntos (union, diferencia e interseccion)

/* Operador binario * para la INTERSECCION de dos colecciones.
Devuelve una coleccion con los elementos comunes entre las dos colecciones.
*/
Categorias Categorias::operator* (const Categorias & otro) const
{
    Categorias resultado;   //El tamaño minimo de la interseccion es 0

    //El tamanio maximo de la interseccion sera el del conjunto mas pequeño
    const Categorias * conjunto_menor= usados>otro.usados ? &otro:this;

    //conjunto mayor apunta al que no apunta conjunto menor
    const Categorias * conjunto_mayor= conjunto_menor == this ? &otro:this;

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
Categorias operator + (const Categorias & este, const Categorias & otro)
{
    //El tamanio maximo de la union sera el del conjunto mayor
    const Categorias * conjunto_mayor= este.usados<otro.usados ? &otro:&este;

    //conjunto menor apunta al que no apunta conjunto mayor
    const Categorias * conjunto_menor= conjunto_mayor == &este ? &otro:&este;

    // La union tendrá como mínimo todos los elementos del mayor
    Categorias resultado(*conjunto_mayor);

    for (int i = 1; i<=(*conjunto_menor).usados; i++)

        if (!((*conjunto_menor)[i]&&resultado)) //Si no está ya aniadido

            resultado.Aniade((*conjunto_menor)[i]);

    return resultado;
}
//una coleccion y un elemento (coleccion de un solo elemento)
Categorias operator + (const Categoria & elemento, const Categorias & coleccion)
{
    return coleccion+Categorias(elemento);
}
Categorias operator + (const Categorias & coleccion, const Categoria & elemento)
{
    return coleccion + Categorias(elemento);
}

//una coleccion y un elemento (int id_categoria) (coleccion de un solo elemento)
Categorias operator + (const Categorias & coleccion, int id_carrera)
{
    return coleccion + Categoria(id_carrera);
}


/* Operador binario - para la DIFERENCIA de dos colecciones.
Devuelve una coleccion con los elementos presentes en la primera y
no presentes en la segunda.
NOTA: la diferencia no es conmutativa.
*/
//dos colecciones este-otro
Categorias operator - (const Categorias & este, const Categorias & otro)
{
    Categorias resultado;   //El tamaño minimo de la diferencia es 0

    for (int i = 1; i<=este.usados; i++)

        if (!(este[i]&&otro)) //Si no está en el otro

            resultado.Aniade(este[i]);

    return resultado;
}
//una coleccion y un elemento (coleccion de un solo elemento)
Categorias operator - (const Categoria & elemento, const Categorias & coleccion)
{
    return Categorias(elemento) - coleccion;
}
Categorias operator - (const Categorias & coleccion, const Categoria & elemento)
{
    return coleccion - Categorias(elemento);
}
//una coleccion y un elemento (int id_categoria)(coleccion de un solo elemento)
Categorias operator - (const Categorias & coleccion, int id_categoria)
{
    return coleccion - Categoria(id_categoria);
}
/***********************************************************************/


/***********************************************************************/
/* Operadores () y [] para el acceso al elemento de la casilla "num_casilla".

Consulta ó modifica el valor de una casilla dada:
    Si se utiliza como rvalue se emplea para consultar el
        valor de la casilla "num_casilla".
    Si se utiliza como lvalue se emplea para modificar el
        valor de la casilla "num_casilla".

PRE: 1 <= num_casilla <= Usados()
*/
Categoria & Categorias::operator() (const int num_casilla)
{
    return (*this)[num_casilla];
}
Categoria & Categorias::operator() (const int num_casilla) const
{
    return (*this)[num_casilla];
}
Categoria & Categorias::operator[] (const int num_casilla)
{
    return Valor(num_casilla-1);
}
Categoria & Categorias::operator[] (const int num_casilla) const
{
    return Valor(num_casilla-1);
}
/***********************************************************************/

/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
//Getters
/*****************************************************************************/

// Devuelve el número de casillas ocupadas.
int Categorias::Usados (void) const {return usados;}

// Devuelve el número de casillas disponibles
int Categorias::Capacidad (void) const {return capacidad;}

// Devuelve "true" si la secuencia está vacía (total_utilizados == 0)
bool Categorias::EstaVacia (void) const {return usados == 0;}

/***************************************************************************/
/* Busca la posición de un categoria. 

    -Si el argumento es de tipo Categoria (categoria), buscará el categoria 
    en la coleccion por su id (clave primaria)
    -Si el argumento es de tipo int (id_categoria), buscará el categoria 
    que tenga dicho numero de categoria.

Devuelve la posición del primer elemento coincidente (debe ser unico), 
o -1 si no se encuentra.

Posiciones: 1, 2, ..., Usados()
*/
int Categorias::Busca (const Categoria & categoria) const
{
    int posicion= -1;

    int i = 1;
    for (;i <= usados && categoria != (*this)[i]; i++);
    
    if (i != usados+1) {posicion = i;}

    return posicion;
}
int Categorias::Busca (const int id_categoria) const
{
    return Busca(Categoria(id_categoria));
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
*/
void Categorias::Inserta (int indice, const Categoria & nuevo)
{
    int posicion = Busca(nuevo);

    if (posicion == -1){//si no está en la coleccion

        // Comprueba que haya suficiente espacio
        if (usados + 1 > capacidad)
            Redimensiona();
        
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


/************************************************************************/
/* Eliminar el contenido de la "casilla" cuya posición es "indice".

PRE: 1 <= indice <= Usados()
*/
void Categorias::Elimina (int indice)
{
    // Desplaza los elementos desde el ultimo hasta la casilla "indice"
    // una posición a la izquierda
    for (int i = indice; i < usados; i++)
        datos[i-1] = datos[i];

    usados--;   // Actualiza el numero de elementos
}


/************************************************************************/
/*Devuelve una subcoleccion de la implicita desde la posicion "pos" con 
"n" elementos.
Si el numero de elementos es demasiado grande, devuelve una coleccion vacia.
PRE: 1<=pos<=Usados()
PRE: pos+n-1<=Usados()
*/
Categorias Categorias::SubColeccion (int pos, unsigned int n) const
{
    Categorias subcoleccion;    //subcoleccion por defecto vacia

    if (pos + n <= usados + 1 && n>0 && pos>0)

        //copia los datos en la subcoleccion
        for (int i = 0; i < n; i++)  subcoleccion += datos[pos-1+i];

    //else -> la subcoleccion queda vacia

    return subcoleccion;
}

/***************************************************************************/
/*Ordena la coleccion mediante el algoritmo de burbuja.

    *SE COMPARAN LAS CLAVES PRIMARIAS DE LOS ELEMENTOS*

*NOTA: normalmente los datos estan ordenados, por ello, el algoritmo de 
burbuja es el mas adecuado.
*/
void Categorias::Sort ()
{
    bool cambio = true; // Para entrar

    for (int pos_ultimo = usados-1; cambio == true; pos_ultimo--){

        /*En cada recorrido principal, se reestablece "cambio" a false
        solo retornará a true si y solo si hubo cambios*/
        cambio=false;

        for (int i = 0; i < pos_ultimo; i++)
        {
            if (datos[i].GetIdCategoria() > datos[i+1].GetIdCategoria()){
                Intercambia(datos[i], datos[i+1]);
                cambio = true;
            }
        }
    }
}
/************************************************************************/

/****************************************************************************/
/****************************************************************************/



/****************************************************************************/
/****************************************************************************/
// MÉTODOS PRIVADOS DE LA CLASE Categorias
/***************************************************************************/
/***************************************************************************/

/************************************************************************/
/* Pide memoria para guardar "num_casillas" datos.
PRE: haber liberado memoria previamente.
PRE: 0 <= Usados()
*/
void Categorias::ReservaMemoria (const int num_casillas)
{
    datos = new Categoria [num_casillas];

    capacidad = num_casillas;

    usados = 0;
}

/************************************************************************/
/* Libera memoria dinámica reservada para los datos
*/
void Categorias::LiberaMemoria (void)
{
    if (datos != nullptr){

        delete [] datos;

        datos = nullptr;

        capacidad = usados = 0;
    }
}

/************************************************************************/
/* Copia datos desde otro objeto de la clase
    PRE: Se ha reservado memoria para los datos
*/
void Categorias::CopiaDatos (const Categorias & otro)
{
	// Actualiza el numero de elementos y la capacidad
	usados = otro.usados;
    capacidad = otro.capacidad;

	// Copiar los valores de los datos
    for (int i = 0; i < usados; i++)
        datos[i] = otro.datos[i];
}

/************************************************************************/
/* Redimensiona el vector dinámico y copia los datos en el nuevo almacén.  
Pedirá memoria adicional si el número de casillas a usar es superior 
a la capacidad actual. El número de casillas adicionales será "TAM_BLOQUE".
*/
void Categorias::Redimensiona (void)
{   
    capacidad += TAM_BLOQUE;
    
    // Pide memoria para el nuevo vector
    Categoria * tmp = new Categoria[capacidad] ;

	// Copiar los valores de los datos
    for (int i = 0; i < usados; i++)
        tmp[i] = datos[i];

    //Libera la memoria del vector en deshuso 
    delete [] datos;

    // Actualiza el puntero de datos
    datos = tmp;
}


/************************************************************************/
/*Devuelve una referencia al elemento de la casilla "indice"
Parámetros: 
    indice, Numero de casilla a la que se accede. 
PRE: 0 <= indice < Usados()
*/
inline Categoria & Categorias::Valor (const int indice) const
{
    return (datos[indice]);
}

/************************************************************************/
/* Aniade un elemento ("nuevo") al final de la coleccion (posicion usados+1).

Se redimensionará el vector dinámico de datos si no tuviera suficiente 
espacio disponible.
*/
void Categorias::Aniade (const Categoria & nuevo)
{
    if (usados + 1 > capacidad)
        Redimensiona();
    
    datos[usados] = nuevo;  //Aniade el nuevo objeto.

    usados++;   // Actualiza el numero de elementos
}

/*****************************************************************************/
/*****************************************************************************/



/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////