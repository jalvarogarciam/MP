/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// JOSÉ ÁLVARO GARCÍA MÁRQUEZ
// 1º Ingenieria Informática (Grupo B1)
//
// Proyecto Fase 4
//
// Fichero: main_MP_Proyecto_Fase4.cpp
//
//////////////////////////////////////////////////////////////////////////////
/*
Demostracion del funcionamiento de las clases principales del proyecto.
Asociacion de datos en ficheros independientes.
*/
/***************************************************************************/
/***************************************************************************/

#include <iomanip>
#include <cstring>
#include <fstream>
#include <sstream>

#include "Utils.h"

#include "Fecha.h"
#include "Tiempo.h"

#include "Carrera.h"
#include "Corredor.h"
#include "Categoria.h"
#include "Resultado.h"

#include "Carreras.h"
#include "Corredores.h"
#include "Categorias.h"
#include "Resultados.h"

#include "TodosResultados.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/

string Cabecera (const char * titulo);

/***************************************************************************/
/***************************************************************************/

int main(int argc, char ** argv)
{
	// Comprobar numero de argumentos  

	if (argc != 2) {
		cerr << "Error: Numero de argumentos incorrecto." << endl;
		cerr << "Formato: "<< argv[0]<<" <Fichero.cfg> "<<endl;
		exit (1);
	}
    cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales


	// Cada linea se lee en un dato string. 
	string linea;

	//string que almacena la ruta en el sistema al directorio de los datos
	string fich_cfg(argv[1]);

	//string que almacena la ruta al directorio donde se encuentran los datos.
	string ruta = Extrae_Ruta(argv[1]);


	ruta += ruta.size() == 0 ? "" : "/";	//aniade la / por simplicidad

	cout << endl; 
	cout << "Hoy es " << Fecha().ToString(true) 
	     << " - " << Tiempo().ToString() << endl; 
	cout << endl; 

	
	//......................................................................
	//......................................................................
	// DATOS GENERALES 
	//......................................................................
	//......................................................................

	cout << Cabecera ("DATOS GENERALES:");
	cout << endl; 


	//Flujo de entrada asociado al fichero de configuracion del circuito.
	ifstream ifs(fich_cfg);	
	prepara_flujo_datos(ifs,"CIRCUITO");
	
	getline(ifs, linea); 
	cout << "CIRCUITO: " << linea << endl; 
	cout << endl; 	

	int num_carreras_circuito;	ifs >> num_carreras_circuito;
	cout << "Carreras:   " << num_carreras_circuito << endl; 
 
	int num_carreras_minimo;	ifs >> num_carreras_minimo;
	cout << "Minimo:     " << num_carreras_minimo << endl; 

	int num_carreras_disputadas;	ifs >> num_carreras_disputadas;
	cout << "Disputadas: " << num_carreras_disputadas << endl; 

	cout<<endl<<endl;


	//......................................................................
	//......................................................................
	// CARRERAS
	//......................................................................
	//......................................................................
	
	cout << Cabecera ("CARRERAS:");
	
	ifs >> linea;	// extrae el nombre del fichero
	
	// Crear colección a partir del fichero de datos
	Carreras coleccion_carreras(ruta + linea); 

	cout << "Escribiendo las carreras en el fichero "<< ruta + linea \
		 <<" ..."<<endl;

	coleccion_carreras.EscribirCarreras(ruta + linea);
	
	cout << "escritas"<<endl<<endl;
	
	cout<<endl<<endl;

	//......................................................................
	//......................................................................
	// CORREDORES
	//......................................................................
	//......................................................................
	
	cout << Cabecera ("CORREDORES:");


	ifs >> linea;	// extrae el nombre del fichero
	// Crear colección a partir del fichero de datos
	Corredores coleccion_corredores(ruta + linea);

	cout << "Escribiendo los corredores en el fichero "<< ruta + linea \
		 <<" ..."<<endl;

	coleccion_corredores.EscribirCorredores(ruta + linea);
	
	cout << "escritos"<<endl<<endl;

	cout<<endl<<endl;

	//......................................................................
	//......................................................................
	// CATEGORIAS
	//......................................................................
	//......................................................................
	
	cout << Cabecera ("CATEGORIAS:");

	ifs >> linea;	// extrae el nombre del fichero
	// Crear colección a partir del fichero de datos
	Categorias coleccion_categorias(ruta + linea);

	cout << "Escribiendo las categorias en el fichero "<< ruta + linea \
		 <<" ..."<<endl;

	coleccion_categorias.EscribirCategorias(ruta + linea);
	
	cout << "escritas"<<endl<<endl;
	
	cout<<endl<<endl;
	
	//......................................................................
	//......................................................................
	// RESULTADOS Y COLECCION DE RESULTADOS
	//......................................................................
	//......................................................................
	 
	// Almacen de los resultados de todas las carreras 
	// Se reserva espacio para todas las carreras aunque alguna 
	// no se haya disputado. 

	TodosResultados todos_resultados (num_carreras_circuito); 


	cout << Cabecera ("RESULTADOS:")<<endl;


	// Para cada carrera disputada

	for (int i=1; i<=num_carreras_disputadas; i++) {

		// Para almacenar la clasificación de la carrera "i" 
		ifs >> linea;	// extrae el nombre del fichero

		// Crear colección a partir del fichero de datos
		Resultados resultados_carrera_i(ruta + linea);

		Carrera carrera_actual = coleccion_carreras[i]; 
		// Operator [] de "Carreras"

		cout << "Guardados los resultados de la carrera " <<setfill(' ') \
			<<setw(2)<<i <<" [ "<< carrera_actual.GetNombre() << " ] " << endl;
		     
		cout << "Total finalizados = "
		     << setw(3) << resultados_carrera_i.Usados() << endl << endl; 


		cout << "Escribiendo los resultados en el fichero "<< ruta + linea \
			<<" ..."<<endl;

		resultados_carrera_i.EscribirResultados(ruta + linea);
		
		cout << "escritos"<<endl<<endl;

		cout<<endl<<endl;

		// Añadir "coleccion_resultados" a "todos_resultados"
		todos_resultados += resultados_carrera_i;
	}

	ifs.close();
	return 0;
}

/***************************************************************************/
/***************************************************************************/

string Cabecera (const char * titulo)
{
	const int TAM_GUIONES = 70; 
	char guiones[TAM_GUIONES]; 

	memset (guiones, '-', TAM_GUIONES-1); 
	guiones[TAM_GUIONES-1] = '\0'; 

	string cad_guiones (guiones); 

	string cad;

	cad = cad + cad_guiones + "\n";
	cad = cad + titulo + "\n";
	cad = cad + cad_guiones + "\n";

	return cad; 
}

/***************************************************************************/
/***************************************************************************/
