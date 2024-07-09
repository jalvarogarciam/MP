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

#include "TipoBase_Matriz2D.h"
#include "Matriz2D.h"

#include "Secuencia.h"


#include <iomanip>
#include <sstream>
#include <fstream>
#include <iostream>


using namespace std;


/*****************************************************************************/
/*Funcion auxiliar
Intercambia los valores de dos objetos de tipo TipoBaseMatriz2D.
*/
void swp( TipoBaseMatriz2D & uno, TipoBaseMatriz2D & otro)
{
    TipoBaseMatriz2D tmp = uno;
    uno = otro;
    otro = tmp;
}



/***********************************************************************/
//CONSTRUCTORES Y DESTRUCTOR
/***********************************************************************/

/*****************************************************************************/
/* Constructor sin argumentos
Crea una matriz dinámica vacía.
*/
Matriz2D::Matriz2D () : fils(0), cols(0), datos(nullptr){}

/*****************************************************************************/
/* Constructor con un argumento
Crea una matriz dinámica cuadrada de dimension "dim", cuyo contenido
está indefinido. 
PRE: dim >= 0
*/
Matriz2D::Matriz2D (int dim) : Matriz2D(dim,dim){}


/*****************************************************************************/
/* Constructor con dos argumentos
Crea una matriz dinámica con "nfils" filas y "ncols" columnas.
El contenido de las "fils"x"cols" casillas está indefinido.
PRE: nfils > 0 && ncols > 0
*/
Matriz2D::Matriz2D (int nfils, int ncols)
{
    ReservaMemoria (nfils, ncols);
    Ecualiza(VALOR_DEF);
}


/*****************************************************************************/
/* Constructor con tres argumentos
Crea una matriz dinámica con "nfils" filas y "ncols" cols.
El contenido de las "fils"x"cols" casillas se inicializa a un valor común, 
el indicado en el parámetro "valor"

PRE: nfils > 0 && ncols > 0 && valor de tipo TipoBaseMatriz2D
*/
Matriz2D::Matriz2D (int nfils, int ncols, int valor)
{
    ReservaMemoria (nfils, ncols);
    Ecualiza (valor);
}

/*****************************************************************************/
// Constructor de copia.
Matriz2D::Matriz2D (const Matriz2D & otra)
{
    ReservaMemoria(otra.fils, otra.cols);
    CopiaDatos(otra);
}

/*****************************************************************************/
/*Constructor que recibe el nombre de un fichero de texto y crea una matriz
y la rellena con los datos contenidos en el fichero de texto nombre.
*/
Matriz2D::Matriz2D (const char * nombre) : Matriz2D()
{
    LeerMatriz2D(nombre);
}


/*****************************************************************************/
// Destructor
Matriz2D::~Matriz2D ()
{
    LiberaMemoria();
}
/*****************************************************************************/

/*****************************************************************************/
/*Descarta todos los valores de la matriz. Deja la matriz en estado “vacía”.
La matriz sigue “activa”. 
Use esta función si tiene previsto seguir usando la matriz.
POST: EstaVacia() == true 
*/
void Matriz2D::EliminaTodos ()
{
    LiberaMemoria();  //La matriz queda vacía
}


/***********************************************************************/
//OPERADORES
/***********************************************************************/

/*****************************************************************************/
// Operador de asignación desde otro dato Matriz2D
Matriz2D & Matriz2D::operator=(const Matriz2D & otra)
{
    if (this != &otra){ // Evita la autoasignación

        LiberaMemoria();  //Libera la memoria ocupada de la matriz implicita

        ReservaMemoria(otra.fils, otra.cols); //reserva la memoria necesaria

        CopiaDatos(otra);   //copia los datos de la otra
    }

    return *this;
}

/* Operador de asignación desde un dato de tipo TipoBaseMatriz2D.
Asigna el valor "valor" a todas las casillas de la matriz.
*/
Matriz2D & Matriz2D::operator=(const TipoBaseMatriz2D & valor)
{
    Ecualiza(valor);

    return *this;
}
/***********************************************************************/

/***********************************************************************/
/* Operadores binarios += y -=
    -Si el argumento es una matriz, suma/resta a la matriz implicita la matriz 
    "otro" (implicita = implicita +/- otro)
    -Si el argumento es de tipo TipoBaseMatriz2D lo suma/resta a cada elemento 
PRE: tienen las mismas dimensiones
*/
Matriz2D & Matriz2D::operator += (const Matriz2D & otro)
{
    //para no vaciar la matriz en caso de tener diferente dimension (operator+)
    if (fils == otro.fils && cols == otro.cols)
        *this = *this + otro;

    return (*this);
}
Matriz2D & Matriz2D::operator -= (const Matriz2D & otra)
{   
    *this += - otra ;
    return *this;
}

Matriz2D & Matriz2D::operator += (const TipoBaseMatriz2D & valor)
{
    *this += Matriz2D( fils, cols, valor );

    return *this;
}
Matriz2D & Matriz2D::operator -= (const TipoBaseMatriz2D & valor)
{
    *this += -1*valor;
    return *this;
}
/*****************************************************************************/


/*****************************************************************************/
/* Operador de acceso ().
Dado un par de índices de fila "f" y columna "c", devuelve una referencia al
valor de la casilla correspondiente.
    PRE: 0<=f<fils && 0<=c<cols
*/
TipoBaseMatriz2D & Matriz2D::operator()(int f, int c)
{
    return Valor(f,c);
}
TipoBaseMatriz2D & Matriz2D::operator()(int f, int c) const
{
    return Valor(f,c);
}
/*****************************************************************************/


/***********************************************************************/
/* Operador == y !=
Dos datos Secuencia son iguales si tienen el mismo número de casillas 
y los cobntenidos son iguales y en las mismas posiciones. 
De lo contrario, son diferentes (!=)
*/
bool Matriz2D::operator == (const Matriz2D & otra) const
{
    return EsIgualA(otra);
}

bool Matriz2D::operator != (const Matriz2D & otra) const
{
    return !(*this == otra);
}
/***********************************************************************/


/***********************************************************************/
// Operadores unarios + y -

//Devuelve una copia de la matriz sin cambiar el signo de los valores 
Matriz2D Matriz2D::operator + (void) const
{
    return (*this);     //Actúa el constructor de copia
}

//Devuelve una copia de la matriz cambiando el signo de los valores 
Matriz2D Matriz2D::operator - (void) const
{
    // Matriz2D local, para el resultado.
    Matriz2D opuesta(*this); //Se inicializa con una copia del objeto implícito.

    //cambio el signo de los elementos
    for (int i = 0; i < fils; i++)

        for (int j = 0; j < cols; j++)

            opuesta.datos[i][j] = -datos[i][j]; //operador - de TipoBaseMatriz2D
    
    return (opuesta);     //Actúa el constructor de copia
}
/***********************************************************************/


/***********************************************************************/
/* Operadores binarios + y -
    -Si el argumento es una Matriz2D, devuelve una copia de la matriz 
    resultante de la suma/resta matemática de las dos matrices.
    PRE: tienen las mismas dimensiones

    -Si el argumento es de tipo TipoBaseMatriz2D devuelve una 
    copia de la matriz resultante de sumarlo/restarlo a cada elemento de la 
    matriz.
*/
Matriz2D Matriz2D::operator + (const Matriz2D & otra) const
{
    // Matriz2D local, para el resultado.
    Matriz2D res;
    
    if (fils == otra.fils && cols == otra.cols){
        
        res = *this;     // Se inicializa con una copia del objeto implícito.

        //suma los elementos
        for (int i = 0; i < fils; i++)

            for (int j = 0; j < cols; j++)

                res(i,j) += otra(i, j); //operador += de TipoBaseMatriz2D
    }

    return (res);     //Actúa el constructor de copia
}

Matriz2D Matriz2D::operator - (const Matriz2D & otra) const
{
    return *this + (- otra);
}

Matriz2D Matriz2D::operator + (const TipoBaseMatriz2D & valor) const
{
    return (*this + Matriz2D(fils, cols, valor));
}

Matriz2D Matriz2D::operator - (const TipoBaseMatriz2D & valor) const
{
    return *this + (-1 * valor);
}
/***********************************************************************/

/***********************************************************************/
/***********************************************************************/
// Operator << Inserta en un flujo de texto un objeto "Matriz2D".
ostream & operator << (ostream & out, const Matriz2D & m)
{
	out.setf (ios::fixed);
	out.setf (ios::showpoint);


	out << setw(ANCHO_MATRIZ2D) << m.fils << " "\
        << setw(ANCHO_MATRIZ2D) << m.cols << endl; 

    for (int fil=0; fil < m.fils; fil++){
    
        for (int col=0; col < m.cols; col++) {

            TipoBaseMatriz2D valor = m.datos[fil][col];

            #ifdef INT
            out << setw(ANCHO_MATRIZ2D) << valor;
            #else
            #ifdef DOUBLE
            out << setw(ANCHO_MATRIZ2D) 
                << setprecision(DECIMALES_MATRIZ2D) << valor;	
            #endif
            #endif

            out << " ";
        }
        out << endl;
    }

	return (out);
}

/***********************************************************************/
/***********************************************************************/
/* Operator >> 
Lee los datos de un objeto "Matriz2D" desde un flujo de texto.
Suponemos que los datos leidos son correctos
*/
istream & operator >> (istream & in, Matriz2D & m)
{	
	// Limpiar el objeto: Liberar memoria reservada previamente
	m.LiberaMemoria();

    //Reserva memoria 
    in >> m.fils;
	in >> m.cols;	
	m.ReservaMemoria (m.fils, m.cols);

    for (int f=0; f<m.fils; f++) 

        for (int c=0; c<m.cols; c++) 

            in >> m.datos[f][c]; 

    return (in);

}

/***********************************************************************/
/***********************************************************************/
/* Métodos de E/S

DEVUELVEN FALSO SI HUBO ALGUN ERROR.
*/

/*Guarda en el fichero de texto "nombre" el contenido de la matriz. Si el
fichero ya existiera, se reemplaza su contenido por el de la matriz. La
matriz no se modifica. Escribe los datos por filas, esto es, cada línea
de salida contiene los valores de una fila de la matriz delimitados por
separadores
*/
bool Matriz2D:: EscribirMatriz2D (const char * nombre) const
{
    bool problemas = false;

	ofstream ofs (nombre, ios::out);

    if (!ofs) problemas = true;

    else {
        ofs << "MATRIZ2D" <<endl;

        ofs << (*this); 

        ofs.close();
    }

    return !problemas;
}

/***********************************************************************/
/* Sustituye el contenido de la matriz por los valores que están en el fichero
de texto nombre.

Este método NO es un constructor: el objeto sobre el que se aplica
ya existe, por lo tanto, lo primero que debe hacerse es "limpiarlo"
y después, leer los valores a guardar en la Secuencia de los datos 
almacenados en el fichero llamado "nombre"
*/
bool Matriz2D :: LeerMatriz2D (const char * nombre)
{
	// Limpiar el objeto: Liberar memoria reservada previamente
	LiberaMemoria ();

	// Leer los datos del fichero
	return RecuperaDatosDeFichero (nombre);
}

/***********************************************************************/
/***********************************************************************/

/*****************************************************************************/
//Devuelve un string con el resultado de “serializar” una matriz.
string Matriz2D::ToString (const char msg[]) const
{
    ostringstream oss;  //flujo de salida asociado a string

    //Ajusta las preferencias de representacion numerica
    oss.setf(ios::fixed);
    oss.setf(ios::showpoint);
    oss.precision(4);

    oss << msg;
    
    if (msg[0] != '\0') oss<<endl;


	string delimitador(34,'.');

	oss << endl << delimitador <<endl;

    if (EstaVacia()) 

        oss << "Matriz vacía" << endl;

    else{

        oss << "Filas = " << fils << ", Columnas = " << cols <<endl<<endl;

        for (int f=0; f<fils; f++) {
            
            oss << "Fila " << f << " --> ";
            
            for (int c=0; c<cols; c++) 
                oss << setfill (' ')<<setw(5)<< datos[f][c];
            
            oss << endl;
        }
        
    }

    oss << delimitador << endl;

	return (oss.str());
}
/*************************************************************************/


/*************************************************************************/
//Devuelve el número de filas de la matriz.
int Matriz2D::NumFilas (void) const {return fils;}

/*************************************************************************/
//Devuelve el número de columnas de la matriz.
int Matriz2D::NumColumnas (void) const {return cols;}

/*************************************************************************/
//Devuelve true si la matriz está vacía.
bool Matriz2D::EstaVacia (void) const {return (datos == nullptr);}

/*************************************************************************/
/*Devuelve true si las matrices son iguales.
Parametros: 
    otra: las matriz a comparar con la implicita.
*/
bool Matriz2D::EsIgualA ( const Matriz2D & otra) const
{
    bool iguales = true;

    if (fils != otra.fils || cols != otra.cols) // Compara las dimensiones
        iguales = false;
    

    if (iguales){    // Compara los datos de las matrices

        int i = 0;
        for (; i < fils && iguales; i++){

            int j = 0;
            for (;j < cols && datos[i][j] == otra.datos[i][j]; j++);
            
            if (j!=cols) iguales = false;
        }
    }

    return iguales;    
}



/*****************************************************************************/
// Cambia todos los todos valores de la matriz por valor.
void Matriz2D::Ecualiza ( TipoBaseMatriz2D valor)
{  
    for (int i = 0; i<fils; i++)
        
        for (int j = 0; j<cols; j++)
        
            Valor(i,j) = valor;
}


/*****************************************************************************/
/*Devuelve un objeto secuencia cuyos valores son la los valores de la fila nº
"indice"
PRE: 0<=indice<fils
*/
Secuencia Matriz2D::Fila (int indice)
{
    Secuencia sec(cols);
    
    for(size_t i=0; i<cols; i++)
        sec + Valor(indice,i);
    
    return sec;
}

/*****************************************************************************/
/*Devuelve un objeto secuencia cuyos valores son la los valores de la columna nº
"indice"
PRE: 0<=indice<cols
*/
Secuencia Matriz2D::Columna (int indice)
{
    Secuencia sec(fils);
    
    for(int i=0; i<fils; i++)
        sec + Valor(i, indice);
    
    return sec;
}


/*****************************************************************************/
/*Añade una fila nueva a la matriz.
Parámetros:
    fila_nueva: un objeto secuencia cuyos valores son los de la fila a añadir.
PRE: fila_nueva.TotalUtilizados() == NumColumnas()
PRE: 1<=indice<=fils
*/
void Matriz2D::Aniade(const Secuencia & fila_nueva)
{
    Inserta(fils,fila_nueva);
}


/*****************************************************************************/
/*Inserta una fila nueva a la matriz en la posición "indice".
Parámetros:
    fila_nueva: un objeto secuencia cuyos valores son los de la fila a añadir.
    indice: posición en la que se insertará la fila.
PRE: fila_nueva.TotalUtilizados() == NumColumnas()
PRE: 0<=indice<NumFilas()
*/
void Matriz2D::Inserta(int indice, const Secuencia & fila_nueva)
{
    indice +=1; //Para poder abarcar el caso indice = 0

    //Crea una matriz copia de la implicita
    Matriz2D copia(*this);

    LiberaMemoria(); //Libera la memoria de la matriz implicita

    ReservaMemoria(copia.fils+1, copia.cols); //reserva la memoria necesaria

    //Copia las filas iniciales
    for (int i=0; i < indice-1; i++) //copia las filas anteriores a la nueva
        
        for (int j=0; j < cols; j++)

            datos[i][j] = copia.datos[i][j];

    for (int j=0; j < cols; j++) //copia la fila nueva en la posicion indice
        
        datos[indice-1][j] = fila_nueva[j+1];


    //Copia las filas restantes
    for (int i=indice-1; i < fils-1; i++)
        
        for (int j=0; j < cols; j++)
        
            datos[i+1][j] = copia.datos[i][j];


    //Se destruye la matriz copia
}


/*****************************************************************************/
/*Elimina la fila numero "index" de la matriz.
PRE: 0<=indice<NumFilas()
*/
void Matriz2D::EliminaFila ( int indice)
{
    //Crea una matriz con una fila menos que la inicial
    Matriz2D nueva = Matriz2D(fils-1, cols);

    //Copia el contenido de la matriz en la nueva matriz (omitiendo la fila)
    for (int i=0, d=0; i < fils; i++){
        
        if (i != indice)

            for (int j=0; j < cols; j++)

                nueva.Valor(i-d, j) = Valor(i, j);

        else   //Si se ha llegado a la fila a eliminar, no se copian.
            d=1;    //se tiene en cuenta el desfase entre nueva y matriz
    }

    //Libera la memoria de la matriz inicial
    LiberaMemoria();

    //Clona la matriz "nueva" en la implicita
    *this = nueva;

    //Aquí se destruye automáticamente la matriz auxiliar "nueva"
}

/*****************************************************************************/
/*Elimina la columna numero "index" de la matriz.
PRE: 0<=indice<NumColumnas()
*/
void Matriz2D::EliminaColumna ( int indice)
{
    //Crea una matriz con una columna menos que la inicial
    Matriz2D nueva(fils, cols-1);

    //Copia el contenido de la matriz en la nueva matriz (omitiendo la fila)
    for (int i=0; i < fils; i++)

        for (int j=0, d=0; j < cols; j++){

            if (j != indice)

                nueva.Valor(i, j-d) = Valor(i, j);

            else   //Si se ha llegado a la columna a eliminar, no se copian.
                d=1;    //se tiene en cuenta el desfase entre nueva y matriz
        }

    //Libera la memoria de la matriz implicita
    LiberaMemoria();

    //Clona la matriz "nueva" en la implicita
    *this = nueva;

    //Aquí se destruye automáticamente la matriz auxiliar "nueva"
}


/*****************************************************************************/
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
Matriz2D Matriz2D::SubMatriz ( int fila_inic, int col_inic, \
                                int num_filas, int num_cols)

{
    bool argumentos_correctos(true);

    //comprueba la validez de los datos
    if (fila_inic < 0 || col_inic < 0 || fila_inic >= fils || col_inic >= cols){

        argumentos_correctos = false;
        num_cols = num_filas = 0;   //dimensiones de una matriz vacia
    
    }else{

        if (cols-col_inic < num_cols)  //reajusta el numero de columnas
        
            num_cols = cols-col_inic;

        if (fils-fila_inic < num_filas)  //reajusta el numero de filas
        
            num_filas = fils-fila_inic;
    }

    //Inicializa resultado
    Matriz2D resultado(num_filas,num_cols);

    //Copia los datos de la submatriz en resultado
    for (int i=0, fil = fila_inic; i < num_filas; i++, fil++)
    
        for (int j=0, col = col_inic; j < num_cols; j++, col++)

            resultado.Valor(i, j) = Valor(fil, col); 
    
    return resultado;
}



/*****************************************************************************/
/*Cambia de orden las filas de matriz (la primera pasa a ser la última y 
la última la primera, la segunda la penúltima y la penúltima la segunda, etc.).
*/
void Matriz2D::EspejoHorizontal ()
{
    for (int i=0; i < fils/2; i++)

        for (int j=0; j < cols; j++)
        
            swp(Valor(i, j), Valor(fils-1-i, j));
}


/*****************************************************************************/
/*Cambia de orden las columnas de matriz (la primera pasa a ser la última y 
la última la primera, la segunda la penúltima y la penúltima la segunda, etc.).
*/
void Matriz2D::EspejoVertical ()
{
    for (int i=0; i < fils; i++)
       
        for (int j=0; j < cols/2; j++)
           
            swp(Valor(i, j), Valor(i, cols-1-j));
}


/***************************************************************************/
/***************************************************************************/
// MÉTODOS PRIVADOS DE LA CLASE Matriz2D
/***************************************************************************/
/***************************************************************************/

/*****************************************************************************/
/* Reserva memoria para los datos de una matriz dinámica con "nfils" filas y 
"ncols" columnas. El contenido es INDEFINIDO.
Parámetros: 
    nfils: número de filas de la matriz.
    ncols: número de columnas de la matriz.
PRE: nfils >= 0 && ncols >= 0
*/
void Matriz2D::ReservaMemoria (int nfils, int ncols)
{
    datos = nullptr;    // Por defecto, la matriz se inicializa vacia
    fils = 0;
    cols = 0;

    if (nfils>0 && ncols>0) {   // Reservar memoria -> matriz NO vacía
        
        // matriz.datos apuntará a un vector de punteros a las filas
        datos = new TipoBaseMatriz2D * [nfils];

        // matriz.datos[i] apuntará a un vector de filas
        datos[0] = new TipoBaseMatriz2D [nfils*ncols];

        // Inicializa el vector de punteros
        for (int i=1; i <nfils; i++)
            datos[i] = datos[0] + i*ncols;
        
        // "matriz.datos[f]" apuntará a un vector de datos int
        fils = nfils;
        cols = ncols;
    }
}
/*****************************************************************************/


/*****************************************************************************/
// Libera la memoria ocupada por una matriz dinámica, dejandola vacia
inline void Matriz2D::LiberaMemoria ()
{
    if (datos) { // if (datos != nullptr)

        delete [] datos[0];      // Libera el vector de datos
    
        delete [] datos;         // Libera el vector de punteros

        datos = nullptr;     // Elimina el acceso al vector de punteros
        fils = cols = 0;  // Actualiza los "atributos"
    }
}


/***************************************************************************/
/* Copiar datos desde otro objeto de la clase
 PRE: Se ha reservado memoria para los datos
*/
void Matriz2D :: CopiaDatos (const Matriz2D & otra)
{   
    for (int i = 0; i < fils; i++)

        for (int j = 0; j < cols; j++)

            datos[i][j] = otra.datos[i][j];
}

/*************************************************************************/
/*Devuelve una referencia al valor de la matriz con coordenadas num_fila, 
num_columna
PRE: 0<=num_fila<NumFilas()
PRE: 0<=num_columna<NumColumnas()
*/
inline TipoBaseMatriz2D & Matriz2D::Valor (int num_fila, int num_columna) const
{
    return (datos[num_fila][num_columna]);
}


/***************************************************************************/
/*Rellena un dato "Matriz2D" con los datos guardados en el fichero de  
texto llamado "nombre".

Este método es usado por:
1) Constructor
    Matriz2D :: Matriz2D (const char * nombre);
2) Método
    void Matriz2D :: Matriz2D (const char * nombre);

DEVUELVE FALSO SI HUBO ALGUN ERROR

PRE: La Matriz2D está vacía
*/
bool Matriz2D :: RecuperaDatosDeFichero (const char * nombre)
{
    bool problemas = false;

    ifstream ifs (nombre);
    
    if (!ifs) problemas = true;
    
    else{

        string linea;

        getline(ifs, linea);	// Lectura palabra mágica

        if ( linea == "MATRIZ2D") {	// CORRECTO --> Seguir leyendo

            ifs >> (*this);
        }
        else    problemas = true;

        ifs.close();
    }

    return problemas;
}
