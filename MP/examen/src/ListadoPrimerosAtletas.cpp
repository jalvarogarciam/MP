/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// JOSÉ ÁLVARO GARCÍA MÁRQUEZ
// 1º Ingenieria Informática (Grupo B1)
//
// DNI: 20608505E
//
// ETIQUETA ORDENADOR: EI140171
//
// Proyecto Fase 4
//
// Fichero: ListadoPrimerosAtletas.cpp
//
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
/*
Muestra el listado de los n primeros atletas de cada carrera del circuito.
El programa recibirá el nombre  del fichero de configuracion (ruta desde el 
directorio en el que se ejecute), el numero de atletas en el que estamos
interesados en el listado (int) y si es hombre  (char valor H) o si es 
mujer (char valor M).

MODO DE EJECUCION: 
  % ListadoPrimerosAtletas <Fichero.conf> <numero_de_atletas> <sexo_de_atletas>
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


int main(int argc, char ** argv)
{
	// Comprobar numero de argumentos  
	if (argc != 4) {
		cerr << "Error: Numero de argumentos incorrecto." << endl;
		cerr << "Formato: "<< argv[0]<<" <Fichero.conf> " \
			<< "<numero_de_atletas> <sexo_de_atletas>"<<endl;
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

	//char que representa el sexo de cada atleta
	char sexo = *argv[3];
	
	//entero que representa el numero de atletas a listar por cada carrera
	int num_atletas = atoi(argv[2]);
	

	//.........................................................................
	//.........................................................................
	// LECTURA DE DATOS DEL CIRCUITO
	//.........................................................................
	//.........................................................................

	//......................................................................
	// DATOS GENERALES 
	//......................................................................

	//Flujo de entrada asociado al fichero de configuracion del circuito.
	ifstream ifs(fich_cfg);	
	prepara_flujo_datos(ifs,"CIRCUITO");
	
	getline(ifs, linea);  	

	int num_carreras_circuito;	
	ifs >> num_carreras_circuito;
 
	int num_carreras_minimo;	
	ifs >> num_carreras_minimo; 

	int num_carreras_disputadas;	
	ifs >> num_carreras_disputadas;


	//......................................................................
	// CARRERAS
	//......................................................................
	
	ifs >> linea;	// extrae el nombre del fichero
	
	// Crear colección a partir del fichero de datos
	Carreras coleccion_carreras(ruta + linea); 
	
	//......................................................................
	// CORREDORES
	//......................................................................

	ifs >> linea;	// extrae el nombre del fichero
	
	// Crear colección a partir del fichero de datos
	Corredores coleccion_corredores(ruta + linea);


	//......................................................................
	// CATEGORIAS
	//......................................................................

	ifs >> linea;	// extrae el nombre del fichero
	
	// Crear colección a partir del fichero de datos
	Categorias coleccion_categorias(ruta + linea);

	
	//......................................................................
	// RESULTADOS Y COLECCION DE RESULTADOS
	//......................................................................
	 
	// Almacen de los resultados de todas las carreras 
	// Se reserva espacio para todas las carreras aunque alguna 
	// no se haya disputado. 

	TodosResultados todos_resultados (num_carreras_circuito); 


	// Para cada carrera disputada

	for (int i=1; i<=num_carreras_disputadas; i++) {

		// Para almacenar la clasificación de la carrera "i" 
		ifs >> linea;	// extrae el nombre del fichero

		// Crear colección a partir del fichero de datos
		Resultados resultados_carrera_i(ruta + linea);

		Carrera carrera_actual = coleccion_carreras[i]; 
		// Operator [] de "Carreras"

		// Añadir "coleccion_resultados" a "todos_resultados"
		todos_resultados += resultados_carrera_i;
	}





	//.........................................................................
	//.........................................................................
	// MUESTREO DE LOS num_atletas PRIMEROS ATLETAS DE CADA CARRERA
	//.........................................................................
	//.........................................................................
	
	cout << endl;
	
	//RECORRE LA COLECCION DE TODOS LOS RESULTADOS
	for (int i=1; i<=num_carreras_disputadas; i++) {
		
		//Muestra el nombre de cada carrera
		cout << "Carrera" << setw(3) << right << i << " : " \
			<< coleccion_carreras[i].GetNombre() << endl;
		
		// Muestra los atletas
		int k = 0;
		for \
		(int j=1; j <= num_atletas && j+k <todos_resultados[i].Usados(); j++)
		{
			//Filtra por sexo
			bool es_sexo = false;
			int indice;
			
			while (!es_sexo && j+k < todos_resultados[i].Usados()) {
			
				// Busca el dorsal del atleta numero k de la clasificacion
				int el_dorsal = todos_resultados[i].Dorsal_por_Posicion(j+k);
				
				// Busca el atleta que posee dicho dorsal
				indice = coleccion_corredores.Busca(el_dorsal);
				
				//comprueba que es del sexo que buscamos
				es_sexo = coleccion_corredores[indice].GetSexo() == sexo;
				
				if (!es_sexo) k++;
			}
			
			// Muestra el atleta
			if (es_sexo)
				cout << setw(3) << left << j << " : " \
					<< coleccion_corredores[indice].ToString() << endl;
		}
		
		cout<<endl;
	}
	
	ifs.close();
	return 0;
}

