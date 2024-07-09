/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// Pruebas sobre el tipo Matriz2D
//
// Matriz2D: Matriz 2D dinamica de datos "TipoBase" en la que cada 
//            fila es un vector dinamico independiente.
//
// Fichero: Demo-BasicoMatriz2D.cpp 
//
/***************************************************************************/

#include <iostream>

#include "Matriz2D.h"
#include "TipoBase.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	// .....................................................................
	// Creación de matrices vacias  

	Matriz2D vacia1 = CreaMatriz ();

	cout << endl;	
	cout << "Se ha creado una matriz \"CreaMatriz()\" de dimensiones: " 
	     << NumFilas (vacia1) << " x " << NumColumnas (vacia1) << endl;
	cout << "Vacia = " << (EstaVacia(vacia1) ? "SI": "NO") << endl;	
	cout << endl;	

	Matriz2D vacia2 = CreaMatriz (-1, 3);

	cout << "Se ha creado una matriz \"CreaMatriz(-1, 3)\" de dimensiones: " 
	     << NumFilas (vacia2) << " x " << NumColumnas (vacia2) << endl;
	cout << "Vacia = " << (EstaVacia(vacia2) ? "SI": "NO") << endl;	
	cout << endl;	

	Matriz2D vacia3 = CreaMatriz (1, -3);

	cout << "Se ha creado una matriz \"CreaMatriz(-1, 3)\" de dimensiones: " 
	     << NumFilas (vacia3) << " x " << NumColumnas (vacia3) << endl;
	cout << "Vacia = " << (EstaVacia(vacia3) ? "SI": "NO") << endl;	
	cout << endl;	

	// Destruye las matrices 

	DestruyeMatriz (vacia1);
	DestruyeMatriz (vacia2);
	DestruyeMatriz (vacia3);
	
	// .....................................................................
	// Creación de una matriz (todas las casillas a cero) y mostrala 

	Matriz2D m0 = CreaMatriz (3, 5);

	cout << "Se ha creado la matriz m0 \"CreaMatriz(3,5)\" de dimensiones: " 
	     << NumFilas (m0) << " x " << NumColumnas (m0) << endl;
	cout << "Vacia = " << (EstaVacia(m0) ? "SI": "NO") << endl;	
	cout << endl;	

	cout << "Matriz m0 -con todos 0-: ";
	cout << ToString (m0);


	// .....................................................................
	// Creación de una matriz (todas las casillas a 9) 

	Matriz2D m9 = CreaMatriz (4, 7, 9);

	cout << "Se ha creado la matriz m9 \"CreaMatriz(4,7,9)\" de dimensiones: " 
	     << NumFilas (m9) << " x " << NumColumnas (m9) << endl;
	cout << "Vacia = " << (EstaVacia(m9) ? "SI": "NO") << endl;	
	cout << endl;	

	cout << "Matriz m9 -con todos 9-: ";
	cout << ToString (m9);

	cout << "Iguales m0 y m9 = " << (SonIguales (m0, m9) ? "SI": "NO") << endl;	

	// Destruir matrices TipoBase_II_DemoMatriz2D

	DestruyeMatriz (m9);
	DestruyeMatriz (m0);


	// .....................................................................
	// Submatriz  

	cout << endl;	
	cout << "================================================" << endl;
	cout << endl;	

	Matriz2D grande = CreaMatriz (5, 5);

	for (int f=0; f<NumFilas(grande); f++) 
		for (int c=0; c<NumColumnas(grande); c++) 
			Valor(grande, f, c) = ((10*(f+1))+c+1);
		
	cout << "Matriz \"grande\": ";
	cout << ToString (grande);

	Matriz2D sub = CreaMatriz();


	// Copia exacta 

	cout << "Creando submatriz de \"grande\" desde (0, 0) y con " 
	     << NumFilas(grande) << " filas y " 
	     << NumColumnas(grande)<< " cols" << endl; 
	
	SubMatriz (sub, grande, 0, 0, NumFilas(grande), NumColumnas(grande));

	cout << endl;	
	cout << "Submatriz de \"grande\": " 
	     << NumFilas (sub) << " x " << NumColumnas (sub) << endl;
	cout << "Matriz \"sub\": ";
	cout << ToString (grande);


	// Posición inicial incorrecta

	cout << "Creando submatriz 2x3 de \"grande\" desde (-2, 2)" << endl; 
	
	SubMatriz (sub, grande, -2, 2, 2, 3);

	cout << endl;	
	cout << "Submatriz de \"grande\": " 
	     << NumFilas (sub) << " x " << NumColumnas (sub) << endl;
	cout << "Vacia = " << (EstaVacia(sub) ? "SI": "NO") << endl;	
	cout << "Matriz \"sub\": ";
	cout << ToString (sub);


	cout << "Creando submatriz 2x3 de \"grande\" desde (2, -2)" << endl; 
	
	SubMatriz (sub, grande, 2, -2, 2, 3);

	cout << endl;	
	cout << "Submatriz de \"grande\": " 
	     << NumFilas (sub) << " x " << NumColumnas (sub) << endl;
	cout << "Vacia = " << (EstaVacia(sub) ? "SI": "NO") << endl;	
	cout << "Matriz \"sub\": ";
	cout << ToString (sub);


	cout << "Creando submatriz 2x3 de \"grande\" desde (-3, -3)" << endl; 
	
	SubMatriz (sub, grande, -3, -3, 2, 3);

	cout << endl;	
	cout << "Submatriz de \"grande\": " 
	     << NumFilas (sub) << " x " << NumColumnas (sub) << endl;
	cout << "Vacia = " << (EstaVacia(sub) ? "SI": "NO") << endl;	
	cout << "Matriz \"sub\": ";
	cout << ToString (sub);


	// Exceso de filas

	cout << "Creando submatriz de \"grande\" desde (0, 0) y con " 
	     << NumFilas(grande)+5 << " filas y " 
	     << NumColumnas(grande)<< " cols" << endl; 
	
	SubMatriz (sub, grande, 0, 0, NumFilas(grande)+5, NumColumnas(grande));

	cout << endl;	
	cout << "Submatriz de \"grande\": " 
	     << NumFilas (sub) << " x " << NumColumnas (sub) << endl;
	cout << "Matriz \"sub\": ";
	cout << ToString (sub);


	// Demasiado grande desde (0,0) 

	// Exceso de filas

	cout << "Creando submatriz de \"grande\" desde (0, 0) y con " 
	     << NumFilas(grande)+5 << " filas y " 
	     << NumColumnas(grande)<< " cols" << endl; 
	
	SubMatriz (sub, grande, 0, 0, NumFilas(grande)+5, NumColumnas(grande));

	cout << endl;	
	cout << "Submatriz de \"grande\": " 
	     << NumFilas (sub) << " x " << NumColumnas (sub) << endl;
	cout << "Matriz \"sub\": ";
	cout << ToString (sub);

	// Exceso de columnas
	
	cout << "Creando submatriz de \"grande\" desde (0, 0) y con " 
	     << NumFilas(grande) << " filas y " 
	     << NumColumnas(grande)+5<< " cols" << endl; 
	
	SubMatriz (sub, grande, 0, 0, NumFilas(grande), NumColumnas(grande)+5);

	cout << endl;	
	cout << "Submatriz de \"grande\": " 
	     << NumFilas (sub) << " x " << NumColumnas (sub) << endl;
	cout << "Matriz \"sub\": ";
	cout << ToString (sub);

	// Exceso de filas y columnas

	cout << "Creando submatriz de \"grande\" desde (0, 0) y con " 
	     << NumFilas(grande)+5 << " filas y " 
	     << NumColumnas(grande)+5<< " cols" << endl; 
	
	SubMatriz (sub, grande, 0, 0, NumFilas(grande)+5, NumColumnas(grande)+5);

	cout << endl;	
	cout << "Submatriz de \"grande\": " 
	     << NumFilas (sub) << " x " << NumColumnas (sub) << endl;
	cout << "Matriz \"sub\": ";
	cout << ToString (sub);


	// Submatriz contenida desde (1,1) y tamaño 2x3

	cout << "Creando submatriz 2x3 de \"grande\" desde (1, 1)" << endl; 
	
	SubMatriz (sub, grande, 1, 1, 2, 3);

	cout << endl;	
	cout << "Submatriz de \"grande\": " 
	     << NumFilas (sub) << " x " << NumColumnas (sub) << endl;
	cout << "Matriz \"sub\": ";
	cout << ToString (sub);


	// Demasiado grande desde (2,2) 

	cout << "Creando submatriz de \"grande\" desde (2, 2) y con " 
	     << NumFilas(grande)+5 << " filas y " 
	     << NumColumnas(grande)+5<< " cols" << endl; 
	
	SubMatriz (sub, grande, 2, 2, NumFilas(grande)+5, NumColumnas(grande)+5);

	cout << endl;	
	cout << "Submatriz de \"grande\": " 
	     << NumFilas (sub) << " x " << NumColumnas (sub) << endl;
	cout << "Matriz \"sub\": ";
	cout << ToString (sub);


	DestruyeMatriz (sub);
	DestruyeMatriz (grande);


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

	Matriz2D m = CreaMatriz (num_filas, num_cols);

	// Consultar num. de filas y columnas

	cout << "Se ha creado una matriz \"m\" de dimensiones: " 
	     << NumFilas (m) << " x " << NumColumnas (m) << endl;
	cout << "Vacia = " << (EstaVacia(m) ? "SI": "NO") << endl;	
	cout << endl;	

	for (int f=0; f<NumFilas (m); f++) 
		for (int c=0; c<NumColumnas (m); c++) 
			Valor(m, f, c) = ((10*(f+1))+c+1);
		
	cout << "Matriz rellena: ";
	cout << ToString (m);

	// Clonar la matriz "m" en "clon_m"

	Matriz2D clon_m = CreaMatriz ();

	Clona (clon_m, m);

	cout << "Se ha clonado la matriz \"m\" en \"clon_m\": " 
	     << NumFilas (clon_m) << " x " << NumColumnas (clon_m) << endl;
	cout << "Vacia = " << (EstaVacia(clon_m) ? "SI": "NO") << endl;	
	cout << "Iguales = " << (SonIguales (m, clon_m) ? "SI": "NO") << endl;	
	cout << endl;	
		
	cout << "Matriz \"clon_m\": ";
	cout << ToString (clon_m);


	// Ecualizar matriz m

	Ecualiza (m, 99);

	cout << "Matriz ecualizada a 99: ";
	cout << ToString (m);

	// Volver a clonar la matriz "m" en "clon_m"

	Clona (clon_m, m);

	cout << "Se ha vuelto a clonar la matriz \"m\" en \"clon_m\": " 
	     << NumFilas (clon_m) << " x " << NumColumnas (clon_m) << endl;
	cout << "Vacia = " << (EstaVacia(clon_m) ? "SI": "NO") << endl;	
	cout << endl;	
		
	cout << "Matriz \"clon_m\": ";
	cout << ToString (clon_m);


	// Modificar la diagonal principal de "m" (Escribir un 0) y guardar 
	// una copia (clon) en "diagonal" y "otra_diagonal"

	int min_filas_cols = (NumFilas(m) < NumColumnas(m)) ? 
		                  NumFilas(m) : NumColumnas(m); 
		                  
	for (int d=0; d<min_filas_cols; d++) 
			Valor(m, d, d) = 0;

	cout << "Matriz \"m\" con diagonal a 0: ";
	cout << ToString (m);

	Matriz2D diagonal = CreaMatriz ();
	Clona (diagonal, m);

	Matriz2D otra_diagonal = CreaMatriz ();
	Clona (otra_diagonal, m);


	// Eliminar fila 0

	EliminaFila (m, 0);

	cout << "Eliminada fila 0 de \"m\": " 
	     << NumFilas (m) << " x " << NumColumnas (m) << endl;
	cout << "Vacia = " << (EstaVacia(m) ? "SI": "NO") << endl;	
	cout << endl;	
		
	cout << "Matriz \"m\": ";
	cout << ToString (m);

	// Eliminar filas hasta dejar la matriz vacía. 
	// Basta con ir borrando la fila 0 repetidamente

	while (!EstaVacia (m)) {

		EliminaFila (m, 0);

		cout << "Eliminada fila 0 de \"m\": " 
		     << NumFilas (m) << " x " << NumColumnas (m) << endl;
		cout << "Vacia = " << (EstaVacia(m) ? "SI": "NO") << endl;	
		cout << endl;	
			
		cout << "Matriz \"m\": ";
		cout << ToString (m);
	}


	// Eliminar columnas hasta dejar la matriz "diagonal" vacía. 
	// Basta con ir borrando la columna 0 repetidamente

	cout << "Matriz \"diagonal\". Vamos a borrar columna a columna: ";
	cout << ToString (diagonal);

	while (!EstaVacia (diagonal)) {

		EliminaColumna (diagonal, NumColumnas(diagonal)-1);

		cout << "Eliminada ultima columna de \"diagonal\": " 
		     << NumFilas (diagonal) << " x " << NumColumnas (diagonal) << endl;
		cout << "Vacia = " << (EstaVacia(diagonal) ? "SI": "NO") << endl;	
		cout << endl;	
			
		cout << "Matriz \"diagonal\": ";
		cout << ToString (diagonal);
	}


	// .....................................................................
	// Espejos horizontal y vertical   

	cout << "Matriz \"otra_diagonal\": ";
	cout << ToString (otra_diagonal);

	EspejoHorizontal (otra_diagonal); 

	cout << "Matriz \"otra_diagonal\" despues de espejo horizontal: ";
	cout << ToString (otra_diagonal);

	EspejoVertical (otra_diagonal); 

	cout << "Matriz \"otra_diagonal\" despues de espejo vertical: ";
	cout << ToString (otra_diagonal);

	// .....................................................................
	// Destruye las matrices

	DestruyeMatriz (m);
	DestruyeMatriz (clon_m);
	DestruyeMatriz (diagonal);
	DestruyeMatriz (otra_diagonal);


	return 0; 
}

/***************************************************************************/
/***************************************************************************/