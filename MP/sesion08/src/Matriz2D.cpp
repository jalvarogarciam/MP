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


#include <string>
#include <cstring>


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



/*****************************************************************************/
/* Constructor sin argumentos
Crea una matriz dinámica vacía.
*/
Matriz2D::Matriz2D () : Matriz2D(0,0){}

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
PRE: nfils >= 0 && ncols >= 0
*/
Matriz2D::Matriz2D (int nfils, int ncols)
{
    ReservaMemoria (nfils, ncols);
}


/*****************************************************************************/
/* Constructor con tres argumentos
Crea una matriz dinámica con "nfils" filas y "ncols" cols.
El contenido de las "fils"x"cols" casillas se inicializa a un valor común, 
el indicado en el parámetro "valor"

PRE: nfils >= 0 && ncols >= 0 && valor de tipo TipoBaseMatriz2D
*/
Matriz2D::Matriz2D (int nfils, int ncols, int valor) : Matriz2D(nfils, ncols) 
{
    Ecualiza (valor);
}


/*****************************************************************************/
// Constructor de copia.
Matriz2D::Matriz2D (const Matriz2D & otra) : Matriz2D(otra.fils, otra.cols)
{
    CopiaDatos(otra);
}


/*****************************************************************************/
// Destructor
Matriz2D::~Matriz2D ()
{
    LiberaMemoria();
}
/*****************************************************************************/


/*****************************************************************************/
//Hace una copia profunda de "otra" en la matriz.
void Matriz2D::Clona (const Matriz2D & otra)
{   
    if (fils != otra.fils || cols != otra.cols){
        
        LiberaMemoria();    //Libera la memoria ocupada de la matriz implicita

        ReservaMemoria(otra.fils, otra.cols);  //reserva la memoria necesaria
    }

    CopiaDatos(otra);   //copia los datos de la otra
}

/*****************************************************************************/
//Devuelve el número de filas de la matriz.
int Matriz2D::NumFilas (void) const
{
    return fils;
}
/*****************************************************************************/

/*****************************************************************************/
//Devuelve el número de columnas de la matriz.
int Matriz2D::NumColumnas (void) const
{
    return cols;
}

/*****************************************************************************/
//Devuelve true si la matriz está vacía.
bool Matriz2D::EstaVacia (void) const
{
    return (datos == nullptr);
}


/*****************************************************************************/
//Devuelve un string con el resultado de “serializar” una matriz.
string Matriz2D::ToString () const
{
    if (EstaVacia()) 
        return "Matriz vacía\n";
    
	string cad;

	string delimitador = "..................................";

	cad = "\n" + delimitador + "\n";

	cad = cad + "Filas = " + to_string(fils) + 
	      ", Columnas = " + to_string (cols) + "\n\n";

	for (int f=0; f<fils; f++) {
		
        cad = cad + "Fila " + to_string(f) + " --> ";
		
		for (int c=0; c<cols; c++) 
			cad = cad + to_string(datos[f][c]) + "  ";
		
        cad = cad + "\n";
	}
	
    cad = cad + delimitador + "\n\n";

	return (cad);
}

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



/*****************************************************************************/
// Cambia todos los todos valores de la matriz por valor.
void Matriz2D::Ecualiza ( TipoBaseMatriz2D valor)
{  
    for (size_t i = 0; i<fils; i++)
        
        for (size_t j = 0; j<cols; j++)
        
            datos[i][j] = valor;
}


/*****************************************************************************/
/*Consulta ó modifica el valor de una casilla dada. 
    Si se utiliza como rvalue se emplea para consulta. 
    Si se utiliza como lvalue se emplea para modificación.
Parámetros: 
	num_fila, número de fila.
	num_columna, número de columna.
PRE: 0<=num_fila<matriz.NumFilas()
PRE: 0<=num_columna<matriz.NumColumnas()
*/
TipoBaseMatriz2D & Matriz2D::Valor (int num_fila, int num_columna) 
{
	return (datos[num_fila][num_columna]);
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
        sec.Aniade(datos[indice][i]);
    
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
    
    for(size_t i=0; i<fils; i++)
        sec.Aniade(datos[i][indice]);
    
    return sec;
}

/*****************************************************************************/
/*Añade una fila nueva a la matriz.
Parámetros:
    fila_nueva: un objeto secuencia cuyos valores son los de la fila a añadir.
PRE: fila_nueva.TotalUtilizados() == NumColumnas()
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
PRE: 0<=indice<=fils
*/
void Matriz2D::Inserta(int indice, const Secuencia & fila_nueva)
{
    indice += 1;    //para poder abarcar el caso del indice 0

    //Crea una matriz copia de la implicita
    Matriz2D copia(*this);

    LiberaMemoria(); //Libera la memoria de la matriz implicita

    ReservaMemoria(copia.fils+1, copia.cols); //reserva la memoria necesaria

    //copia las filas iniciales
    /*for (int i=0; i < indice-1; i++) //copia las filas anteriores a la nueva
        for (int j=0; j < cols; j++)
            datos[i][j] = copia.datos[i][j];
    */
    memcpy(datos[0],copia.datos[0], (indice-1)*cols*sizeof(TipoBaseMatriz2D));

    for (int j=0; j < cols; j++) //copia la fila nueva en la posicion indice
        datos[indice-1][j] = fila_nueva.Valor(j+1);


    //copia las filas restantes
    /*for (int i=indice-1; i < fils-1; i++)
        for (int j=0; j < cols; j++)
            datos[i+1][j] = copia.datos[i][j];
    */
    memcpy(datos[indice], copia.datos[indice-1], \
                        (copia.fils-indice+1)*cols*sizeof(TipoBaseMatriz2D));

    //Se destruye la matriz copia
}


/*****************************************************************************/
/*Devuelve true si las matrices son iguales.
Paeámetros: 
    otra: las matriz a comparar con la implicita.
*/
bool Matriz2D::EsIgualA ( const Matriz2D & otra)
{
    // Compara el tamaño de las matrices para evitar errores de acceso
    if (fils != otra.fils || cols != otra.cols)
        return false;
    
    // Compara los datos de las matrices
    bool iguales = memcmp(datos[0], otra.datos[0], \
                            sizeof(TipoBaseMatriz2D)*fils*cols) == 0;
    
    return iguales;
}


/*****************************************************************************/
/*Elimina la fila numero "index" de la matriz.
*/
void Matriz2D::EliminaFila ( size_t index)
{
    //Crea una matriz con una fila menos que la inicial
    Matriz2D nueva = Matriz2D(fils-1, cols);

    //Copia el contenido de la matriz en la nueva matriz (omitiendo la fila)
    for (size_t i=0, d=0; i < fils; i++){
        if (i != index)

            for (size_t j=0; j < cols; j++)

                nueva.datos[i-d][j] = datos[i][j];

        else   //Si se ha llegado a la fila a eliminar, no se copian.
            d=1;    //se tiene en cuenta el desfase entre nueva y matriz
    }

    //Libera la memoria de la matriz inicial
    LiberaMemoria();

    //Clona la matriz "nueva" en la implicita
    Clona(nueva);

    //Aquí se destruye automáticamente la matriz auxiliar "nueva"
}

/*****************************************************************************/
/*Elimina la columna numero "index" de la matriz.
*/
void Matriz2D::EliminaColumna ( size_t index)
{
    //Crea una matriz con una columna menos que la inicial
    Matriz2D nueva(fils, cols-1);

    //Copia el contenido de la matriz en la nueva matriz (omitiendo la fila)
    for (size_t i=0; i < fils; i++)

        for (size_t j=0, d=0; j < cols; j++){

            if (j != index)

                nueva.datos[i][j-d] = datos[i][j];

            else   //Si se ha llegado a la columna a eliminar, no se copian.
                d=1;    //se tiene en cuenta el desfase entre nueva y matriz
        }

    //Libera la memoria de la matriz implicita
    LiberaMemoria();

    //Clona la matriz "nueva" en la implicita
    Clona(nueva);

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
    for (size_t i=0, fil = fila_inic; i < num_filas; i++, fil++)
    
        for (size_t j=0, col = col_inic; j < num_cols; j++, col++)

            resultado.datos[i][j] = datos[fil][col]; 
    
    

    return resultado;
}



/*****************************************************************************/
/*Cambia de orden las filas de matriz (la primera pasa a ser la última y 
la última la primera, la segunda la penúltima y la penúltima la segunda, etc.).
*/
void Matriz2D::EspejoHorizontal ()
{
    for (size_t i=0; i < fils/2; i++)

        for (size_t j=0; j < cols; j++)
        
            swp(datos[i][j], datos[fils-1-i][j]);
}


/*****************************************************************************/
/*Cambia de orden las columnas de matriz (la primera pasa a ser la última y 
la última la primera, la segunda la penúltima y la penúltima la segunda, etc.).
*/
void Matriz2D::EspejoVertical ()
{
    for (size_t i=0; i < fils; i++)
       
        for (size_t j=0; j < cols/2; j++)
           
            swp(datos[i][j], datos[i][cols-1-j]);
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

void Matriz2D::LiberaMemoria ()
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
    if (!otra.EstaVacia())  // si otra.datos != nullptr -> tiene datos
        memcpy (datos[0], otra.datos[0], \
                                otra.fils*otra.cols*sizeof(TipoBaseMatriz2D));
}
