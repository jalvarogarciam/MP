/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// 1º GRADO EN INGENIERÍA INFORMÁTICA, GRUPO B1
//
// JOSÉ ÁLVARO GARCÍA MÁRQUEZ
//
// Pruebas sobre la clase Matriz2D
//
// Matriz2D: Matriz 2D dinamica de datos "TipoBaseMatriz2D" en la los datos
//           se almacenan en un vector de filas*columnas casillas
//
// Fichero: Demo-BasicoMatriz2D.cpp 
//
/***************************************************************************/

#include <iostream>

#include "Matriz2D.h"
#include "Secuencia.h"
#include "TipoBase_Matriz2D.h"
#include "TipoBase_Secuencia.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	// .....................................................................
	// Creación de matrices vacias  

	Matriz2D vacia1;

	cout << endl;	
	cout << "Se ha creado una matriz \"CreaMatriz()\" de dimensiones: " 
	     << vacia1.NumFilas() << " x " << vacia1.NumColumnas() << endl;
	cout << "Vacia = " << (vacia1.EstaVacia() ? "SI": "NO") << endl;	
	cout << endl;	

	Matriz2D vacia2(-1,3);

	cout << "Se ha creado una matriz \"CreaMatriz(-1, 3)\" de dimensiones: " 
	     << vacia2.NumFilas() << " x " << vacia2.NumColumnas() << endl;
	cout << "Vacia = " << (vacia2.EstaVacia() ? "SI": "NO") << endl;	
	cout << endl;

	Matriz2D vacia3(1,-3);

	cout << "Se ha creado una matriz \"CreaMatriz(1, -3)\" de dimensiones: " 
	     << vacia3.NumFilas() << " x " << vacia3.NumColumnas() << endl;
	cout << "Vacia = " << (vacia3.EstaVacia() ? "SI": "NO") << endl;	
	cout << endl;

	// Destruye las matrices 

	vacia1.EliminaTodos();
	vacia2.EliminaTodos();
	vacia3.EliminaTodos();
	
	// .....................................................................
	// Creación de una matriz (todas las casillas a cero) y mostrala 

	Matriz2D m0(3, 5);

	cout << "Se ha creado la matriz m0 \"CreaMatriz(3,5)\" de dimensiones: " 
	     << m0.NumFilas() << " x " << m0.NumColumnas() << endl;
	cout << "Vacia = " << (m0.EstaVacia() ? "SI": "NO") << endl;	
	cout << endl;

	cout << "Matriz m0 -con todos 0-: ";
	cout << m0.ToString();


	// .....................................................................
	// Creación de una matriz (todas las casillas a 9) 

	Matriz2D m9(4,7,9);

	cout << "Se ha creado la matriz m9 \"CreaMatriz(4,7,9)\" de dimensiones: " 
	     << m9.NumFilas() << " x " << m9.NumColumnas() << endl;
	cout << "Vacia = " << (m9.EstaVacia() ? "SI": "NO") << endl;	
	cout << endl;	

	cout << "Matriz m9 -con todos 9-: ";
	cout << m9.ToString();

	cout << "Iguales m0 y m9 = " << (m0.EsIgualA(m9) ? "SI": "NO") << endl;	

	// Destruir matrices TipoBase_II_DemoMatriz2D

	m9.EliminaTodos();
	m0.EliminaTodos();


	// .....................................................................
	// Submatriz  

	cout << endl;	
	cout << "================================================" << endl;
	cout << endl;	

	Matriz2D grande(5);

	for (int f=0; f<grande.NumFilas(); f++) 
		for (int c=0; c<grande.NumColumnas(); c++) 
			grande.Valor(f, c) = ((10*(f+1))+c+1);
		
	cout << "Matriz \"grande\": ";
	cout << grande.ToString()<<endl;



	// Copia exacta 

	cout << "Creando submatriz de \"grande\" desde (0, 0) y con " 
	     << grande.NumFilas() << " filas y " 
	     << grande.NumColumnas()<< " cols" << endl; 
	
	Matriz2D sub(grande.SubMatriz \
							(0, 0, grande.NumFilas(), grande.NumColumnas()));

	cout << endl;	
	cout << "Submatriz de \"grande\": " 
	     << sub.NumFilas() << " x " << sub.NumColumnas() << endl;
	cout << "Matriz \"sub\": ";
	cout << grande.ToString();


	// Posición inicial incorrecta

	cout << "Creando submatriz 2x3 de \"grande\" desde (-2, 2)" << endl; 
	
	sub.Clona(grande.SubMatriz(-2, 2, 2, 3));

	cout << endl;	
	cout << "Submatriz de \"grande\": " 
	     << sub.NumFilas() << " x " << sub.NumColumnas() << endl;
	cout << "Vacia = " << (sub.EstaVacia() ? "SI": "NO") << endl;	
	cout << "Matriz \"sub\": ";
	cout << sub.ToString()<< endl;


	cout << "Creando submatriz 2x3 de \"grande\" desde (2, -2)" << endl; 
	
	sub.Clona(grande.SubMatriz(2, -2, 2, 3));

	cout << endl;	
	cout << "Submatriz de \"grande\": " 
	     << sub.NumFilas() << " x " << sub.NumColumnas() << endl;
	cout << "Vacia = " << (sub.EstaVacia() ? "SI": "NO") << endl;	
	cout << "Matriz \"sub\": ";
	cout << sub.ToString()<< endl;



	cout << "Creando submatriz 2x3 de \"grande\" desde (-3, -3)" << endl; 

	sub.Clona(grande.SubMatriz(-3, -3, 2, 3));

	cout << endl;	
	cout << "Submatriz de \"grande\": " 
	     << sub.NumFilas() << " x " << sub.NumColumnas() << endl;
	cout << "Vacia = " << (sub.EstaVacia() ? "SI": "NO") << endl;	
	cout << "Matriz \"sub\": ";
	cout << sub.ToString()<<endl ;

	
	// Demasiado grande desde (0,0) 

	// Exceso de filas

	cout << "Creando submatriz de \"grande\" desde (0, 0) y con " 
	     << grande.NumFilas()+5 << " filas y " 
	     << grande.NumColumnas()<< " cols" << endl; 
	cout<<sub.SubMatriz(0,0, grande.NumFilas()+5, grande.NumColumnas()).ToString();
	
	sub.Clona(grande.SubMatriz(0,0, grande.NumFilas()+5, grande.NumColumnas()));

	cout << endl;	
	cout << "Submatriz de \"grande\": " 
	     << sub.NumFilas() << " x " << sub.NumColumnas() << endl;
	cout << "Vacia = " << (sub.EstaVacia() ? "SI": "NO") << endl;	
	cout << "Matriz \"sub\": ";
	cout << sub.ToString();


	// Exceso de columnas
	
	cout << "Creando submatriz de \"grande\" desde (0, 0) y con " 
	     << grande.NumFilas() << " filas y " 
	     << grande.NumColumnas()+5<< " cols" << endl; 
	
	sub.Clona(grande.SubMatriz(0,0, grande.NumFilas(), grande.NumColumnas()+5));

	cout << endl;	
	cout << "Submatriz de \"grande\": " 
	     << sub.NumFilas() << " x " << sub.NumColumnas() << endl;
	cout << "Vacia = " << (sub.EstaVacia() ? "SI": "NO") << endl;	
	cout << "Matriz \"sub\": ";
	cout << sub.ToString();


	// Exceso de filas y columnas

	cout << "Creando submatriz de \"grande\" desde (0, 0) y con " 
	     << grande.NumFilas()+5 << " filas y " 
	     << grande.NumColumnas()+5<< " cols" << endl; 
	
	sub.Clona(grande.SubMatriz( \
							0, 0, grande.NumFilas()+5, grande.NumColumnas()+5));

	cout << endl;	
	cout << "Submatriz de \"grande\": " 
	     << sub.NumFilas() << " x " << sub.NumColumnas() << endl;
	cout << "Vacia = " << (sub.EstaVacia() ? "SI": "NO") << endl;	
	cout << "Matriz \"sub\": ";
	cout << sub.ToString();


	// Submatriz contenida desde (1,1) y tamaño 2x3

	cout << "Creando submatriz 2x3 de \"grande\" desde (1, 1)" << endl; 
	
	sub.Clona(grande.SubMatriz(1, 1, 2, 3));


	cout << endl;	
	cout << "Submatriz de \"grande\": " 
	     << sub.NumFilas () << " x " << sub.NumColumnas () << endl;
	cout << "Matriz \"sub\": ";
	cout << sub.ToString ();


	// Demasiado grande desde (2,2) 

	cout << "Creando submatriz de \"grande\" desde (2, 2) y con " 
	     << grande.NumFilas()+5 << " filas y " 
	     << grande.NumColumnas()+5<< " cols" << endl; 
	
	sub.Clona(grande.SubMatriz( \
							2, 2, grande.NumFilas()+5, grande.NumColumnas()+5));

	cout << endl;	
	cout << "Submatriz de \"grande\": " 
	     << sub.NumFilas() << " x " << sub.NumColumnas() << endl;
	cout << "Vacia = " << (sub.EstaVacia() ? "SI": "NO") << endl;	
	cout << "Matriz \"sub\": ";
	cout << sub.ToString();

	sub.EliminaTodos();
	grande.EliminaTodos();


	// .....................................................................
	// Lectura de las dimensiones de la matriz

	cout << endl;	
	cout << "================================================" << endl;
	cout << endl;	

	int num_filas, num_cols; 

	do  {
		cout << endl;
		cout << "Introduzca num. filas de la matriz: ";
		cin >> num_filas; 
	} while (num_filas <= 0);	

	do  {
		cout << endl;
		cout << "Introduzca num. columnas de la matriz: ";
		cin >> num_cols; 
	} while (num_cols <= 0);	

	cout << endl << endl;

	// .....................................................................
	// Creación de una matriz y rellenar sus casillas, clones y eliminación 
	// de filas y columnas  

	Matriz2D m(num_filas, num_cols);

	// Consultar num. de filas y columnas

	cout << "Se ha creado una matriz \"m\" de dimensiones: " 
	     << m.NumFilas() << " x " << m.NumColumnas() << endl;
	cout << "Vacia = " << (m.EstaVacia() ? "SI": "NO") << endl;	
	cout << endl;	

	for (int f=0; f<m.NumFilas (); f++) 
		for (int c=0; c<m.NumColumnas (); c++) 
			m.Valor(f, c) = ((10*(f+1))+c+1);
		
	cout << "Matriz rellena: ";
	cout << m.ToString();

	// Clonar la matriz "m" en "clon_m"

	Matriz2D clon_m(m);

	cout << "Se ha clonado la matriz \"m\" en \"clon_m\": " 
	     << clon_m.NumFilas() << " x " << clon_m.NumColumnas() << endl;
	cout << "Vacia = " << (clon_m.EstaVacia() ? "SI": "NO") << endl;	
	cout << "Iguales = " << (clon_m.EsIgualA(m) ? "SI": "NO") << endl;	
	cout << endl;	
		
	cout << "Matriz \"clon_m\": ";
	cout << clon_m.ToString();


	// Ecualizar matriz m

	m.Ecualiza (99);

	cout << "Matriz ecualizada a 99: ";
	cout << m.ToString();

	// Volver a clonar la matriz "m" en "clon_m"

	clon_m.Clona (m);

	cout << "Se ha vuelto a clonar la matriz \"m\" en \"clon_m\": " 
	     << clon_m.NumFilas () << " x " << clon_m.NumColumnas () << endl;
	cout << "Vacia = " << (clon_m.EstaVacia() ? "SI": "NO") << endl;	
	cout << endl;	
		
	cout << "Matriz \"clon_m\": ";
	cout << clon_m.ToString ();


	// Modificar la diagonal principal de "m" (Escribir un 0) y guardar 
	// una copia (clon) en "diagonal" y "otra_diagonal"

	int min_filas_cols = (m.NumFilas() < m.NumColumnas()) ? 
		                  m.NumFilas() : m.NumColumnas(); 
		                  
	for (int d=0; d<min_filas_cols; d++) 
			m.Valor(d, d) = 0;

	cout << "Matriz \"m\" con diagonal a 0: ";
	cout << m.ToString();

	Matriz2D diagonal(m);

	Matriz2D otra_diagonal(m);


	// Eliminar fila 0

	m.EliminaFila (0);

	cout << "Eliminada fila 0 de \"m\": " 
	     << m.NumFilas () << " x " << m.NumColumnas () << endl;
	cout << "Vacia = " << (m.EstaVacia() ? "SI": "NO") << endl;	
	cout << endl;	
		
	cout << "Matriz \"m\": ";
	cout << m.ToString();

	// Eliminar filas hasta dejar la matriz vacía. 
	// Basta con ir borrando la fila 0 repetidamente

	while (!m.EstaVacia()) {

		m.EliminaFila (0);

		cout << "Eliminada fila 0 de \"m\": " 
		     << m.NumFilas () << " x " << m.NumColumnas () << endl;
		cout << "Vacia = " << (m.EstaVacia() ? "SI": "NO") << endl;	
		cout << endl;	
			
		cout << "Matriz \"m\": ";
		cout << m.ToString ();
	}


	// Eliminar columnas hasta dejar la matriz "diagonal" vacía. 
	// Basta con ir borrando la columna 0 repetidamente

	cout << "Matriz \"diagonal\". Vamos a borrar columna a columna: ";
	cout << diagonal.ToString ();

	while (!diagonal.EstaVacia ()) {

		diagonal.EliminaColumna ( diagonal.NumColumnas()-1);

		cout << "Eliminada ultima columna de \"diagonal\": " 
		     << diagonal.NumFilas() << " x " << diagonal.NumColumnas() << endl;
		cout << "Vacia = " << (diagonal.EstaVacia() ? "SI": "NO") << endl;	
		cout << endl;	
			
		cout << "Matriz \"diagonal\": ";
		cout << diagonal.ToString ();
	}


	// .....................................................................
	// Espejos horizontal y vertical   

	cout << "Matriz \"otra_diagonal\": ";
	cout << otra_diagonal.ToString ();

	otra_diagonal.EspejoHorizontal (); 

	cout << "Matriz \"otra_diagonal\" despues de espejo horizontal: ";
	cout << otra_diagonal.ToString ();

	otra_diagonal.EspejoVertical (); 

	cout << "Matriz \"otra_diagonal\" despues de espejo vertical: ";
	cout << otra_diagonal.ToString ();


	// .....................................................................
	// Destruye las matrices

	m.EliminaTodos();
	clon_m.EliminaTodos();
	diagonal.EliminaTodos();
	otra_diagonal.EliminaTodos();


	// .....................................................................
	// Aniade e Inserta filas en una matriz

	Matriz2D matriz(3, 5, 9);


	// Consultar num. de filas y columnas

	cout << "Se ha creado una matriz \"matriz\" de dimensiones: " 
	     << matriz.NumFilas() << " x " << matriz.NumColumnas() << endl;
	cout << "Vacia = " << (matriz.EstaVacia() ? "SI": "NO") << endl;	
	cout << endl;	

	for (int f=0; f < matriz.NumFilas (); f++) 
		for (int c=0; c < matriz.NumColumnas (); c++) 
			matriz.Valor(f, c) = ((10*(f+1))+c+1);
		
	cout << "Matriz rellena: ";
	cout << matriz.ToString()<<endl;

	Secuencia sec(5);

	cout << "Se ha creado una secuencia \"sec\"de "<< sec.Capacidad() \
			<<" elementos." << endl;

	for (int i=1; i<=matriz.NumColumnas(); i++)	//Rellenamos la secuencia
		sec.Aniade(i*10);

	cout << "Secuencia \"sec\": ";
	cout << sec.ToString()<<endl<<endl;


	cout << "Añadiendo la secuencia \"sec\" a la matriz \"matriz\"." << endl;
	
	matriz.Aniade(sec);
	
	cout << matriz.ToString()<<endl;


	cout << "Insertando la secuencia \"sec\" en la fila 2 de la " \
		 <<" matriz \"matriz\"." << endl;
	
	matriz.Inserta(2, sec);


	cout << matriz.ToString()<<endl;


	// .....................................................................
	// Consultar filas y columnas de la matriz

	cout << "Representacion de la matriz como sucesion de Secuencias:" \
			<<endl<< endl;

	for (int i=0; i<matriz.NumFilas(); i++)
		cout << "Fila " << i << ": " << matriz.Fila(i).ToString()<<endl;
	cout << endl<<endl;

	cout << "Obtenemos la traspuesta de la matriz \"matriz\":" << endl<<endl;
	for (int i=0; i<matriz.NumColumnas(); i++)
		cout << "Columna " << i << ": " << matriz.Columna(i).ToString()<<endl;
	cout << endl;

	// .....................................................................
	// Finalización del programa

	return 0; 
}


/***************************************************************************/
/***************************************************************************/