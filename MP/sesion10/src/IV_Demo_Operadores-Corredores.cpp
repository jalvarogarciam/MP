/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
// 
// Fichero: III_Demo-Corredores.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

#include "Corredor.h"
#include "Corredores.h"

using namespace std;


/***************************************************************************/
/***************************************************************************/

string Cabecera (const char * titulo);

/***************************************************************************/
/***************************************************************************/


/***************************************************************************/
/***************************************************************************/

int main()
{
    cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales


	// Cada linea se lee en un dato string. 
	string linea;

	// Terminador para los datos leidos/escritos 
	const string TERMINADOR = "FIN";

		//......................................................................
	//......................................................................
	// CORREDORES
	//......................................................................
	//......................................................................
	 
	Corredores coleccion_corredores; // Crear colección (vacía)


	getline(cin, linea); // Lectura adelantada

	while (linea != TERMINADOR) {
					
		Corredor un_corredor (linea);

		// Añadir el dato "Corredor" leido a la colección 
		coleccion_corredores += un_corredor; // Operator += 

		// Leer la siguiente linea 
		getline(cin, linea); 
		
	} // while (linea != TERMINADOR)


	cout << Cabecera ("CORREDORES:");

	cout << endl;
	cout << coleccion_corredores.ToString(); 
	cout << endl;

	cout << "Total corredores del circuito = "<<setw(3) 
	     << coleccion_corredores.Usados() << endl; 
	cout << endl; 


	//......................................................................
	//......................................................................
	// PRUEBAS DE LOS OPERADORES VARIOS SOBRE CORREDORES/CORREDOR
	//......................................................................
	//......................................................................
	 

	cout << Cabecera ("PRUEBAS DE OPS. VARIOS:");

	Corredores primeros_cinco; // Crear colección (vacía)

	for (int pos=1; pos<=5; pos++) 
		primeros_cinco += coleccion_corredores[pos]; // [Corredores]+=[Corredor] 

	cout << endl;
	cout << primeros_cinco.ToString("Primeros cinco"); 
	cout << "Total corredores = "<<setw(3) << primeros_cinco.Usados() << endl; 
	cout << endl; 

	Corredores ultimos_cinco; // Crear colección (vacía)

	for (int pos=coleccion_corredores.Usados()-4; 
		     pos<=coleccion_corredores.Usados(); pos++) 
		ultimos_cinco += coleccion_corredores[pos]; // [Corredores]+=[Corredor]

	cout << endl;
	cout << ultimos_cinco.ToString("Ultimos cinco"); 
	cout << "Total corredores = "<<setw(3) << ultimos_cinco.Usados() << endl; 
	cout << endl; 


	Corredores primera_mitad; // Crear colección (vacía)

	for (int pos=1; pos<=coleccion_corredores.Usados()/2; pos++) 
		primera_mitad += coleccion_corredores[pos]; // [Corredores]+=[Corredor]

	cout << endl;
	cout << primera_mitad.ToString("Primera mitad"); 
	cout << "Total corredores = "<<setw(3) << primera_mitad.Usados() << endl; 
	cout << endl; 
	
	Corredores segunda_mitad; // Crear colección (vacía)

	for (int pos=(coleccion_corredores.Usados()/2)+1; 
		     pos<=coleccion_corredores.Usados(); pos++) 
		segunda_mitad += coleccion_corredores[pos]; // [Corredores]+=[Corredor]

	cout << endl;
	cout << segunda_mitad.ToString("Segunda mitad"); 
	cout << "Total corredores = "<<setw(3) << segunda_mitad.Usados() << endl; 
	cout << endl; 

	//......................................................................
	// [Corredores] + [Corredores] 

	cout << endl;
	cout << (primera_mitad+segunda_mitad).ToString("1_mitad+2_mitad"); 
	cout << "Total corredores = "<< setw(3) 
	     << (primera_mitad+segunda_mitad).Usados() << endl; 
	cout << endl; 

	//......................................................................
	// [Corredor] + [Corredores] 

	string mensaje;

	mensaje = "primeros_cinco[1]+primeros_cinco (REPETIDO)";
	
	cout << endl;
	cout << (primeros_cinco[1]+primeros_cinco).ToString(mensaje); 
	cout << "Total corredores = "<< setw(3) 
	     << (primeros_cinco[1]+primeros_cinco).Usados() << endl; 
	cout << endl; 

	mensaje = "ultimos_cinco[1]+primeros_cinco (NO REPETIDO)";
	
	cout << endl;
	cout << (ultimos_cinco[1]+primeros_cinco).ToString(mensaje); 
	cout << "Total corredores = "<< setw(3) 
	     << (ultimos_cinco[1]+primeros_cinco).Usados() << endl; 
	cout << endl; 

	//......................................................................
	// [Corredores] *  [Corredores] 
	// [Corredores] && [Corredores] 

	cout << endl; 
	cout << "primeros_cinco*ultimos_cinco = " << boolalpha 
		 << (primeros_cinco*ultimos_cinco).Usados() << endl; 
	cout << "primeros_cinco*primeros_cinco = " << boolalpha 
		 << (primeros_cinco*primeros_cinco).Usados() << endl; 
	cout << endl; 


	mensaje = "primeros_cinco*coleccion_corredores";

	cout << "primeros_cinco*coleccion_corredores = " << boolalpha 
		 << (primeros_cinco*coleccion_corredores).Usados() << endl;
	cout << (primeros_cinco*coleccion_corredores).ToString(mensaje) << endl;
	cout << "primeros_cinco&&coleccion_corredores = " 
	     << boolalpha << (primeros_cinco&&coleccion_corredores) << endl; 
	cout << endl; 


	mensaje = "coleccion_corredores*primeros_cinco";

	cout << "coleccion_corredores*primeros_cinco = " << boolalpha 
		 << (coleccion_corredores*primeros_cinco).Usados() << endl; 
	cout << (coleccion_corredores*primeros_cinco).ToString(mensaje) << endl;
	cout << "coleccion_corredores && primeros_cinco = " 
	     << boolalpha << (coleccion_corredores && primeros_cinco) << endl; 
	cout << endl; 


	//......................................................................
	// [Corredores] && [Corredor] 
	// [Corredor] && [Corredores] 

	cout << "coleccion_corredores[1] && coleccion_corredores = " << boolalpha 
		 << (coleccion_corredores[1] && coleccion_corredores) << endl; 
	cout << "coleccion_corredores && coleccion_corredores[1] = " << boolalpha 
		 << (coleccion_corredores && coleccion_corredores[1]) << endl; 
	cout << endl; 

	//......................................................................
	// [Corredores] == [Corredores] 

	cout << endl; 
	cout << "primeros_cinco == ultimos_cinco --> " << boolalpha 
		 << (primeros_cinco == ultimos_cinco) << endl; 	
	cout << "primeros_cinco != ultimos_cinco --> " << boolalpha 
		 << (primeros_cinco != ultimos_cinco) << endl; 	
	cout << endl; 

	cout << "primeros_cinco == primeros_cinco --> " << boolalpha 
		 << (primeros_cinco == primeros_cinco) << endl; 	
	cout << "primeros_cinco != primeros_cinco --> " << boolalpha 
		 << (primeros_cinco != primeros_cinco) << endl; 	
	cout << endl; 


	// Comparaciones con iguales contenidos pero en otro orden
	Corredores otro_orden_primeros_cinco = primeros_cinco;

	Intercambia (otro_orden_primeros_cinco[1], otro_orden_primeros_cinco[5]);
	Intercambia (otro_orden_primeros_cinco[1], otro_orden_primeros_cinco[2]);

	cout << endl;
	cout << (otro_orden_primeros_cinco).ToString("otro_orden_primeros_cinco"); 
	cout << "Total corredores = "<< setw(3) 
	     << (otro_orden_primeros_cinco).Usados() << endl; 
	cout << endl; 
	
	cout << endl; 
	cout << "primeros_cinco == otro_orden_primeros_cinco --> " << boolalpha 
		 << (primeros_cinco == otro_orden_primeros_cinco) << endl; 	
	cout << "primeros_cinco != otro_orden_primeros_cinco --> " << boolalpha 
		 << (primeros_cinco != otro_orden_primeros_cinco) << endl; 	
	cout << endl; 


	cout << endl; 
	cout << "segunda_mitad + primera_mitad == coleccion_corredores --> " 
	     << boolalpha << (segunda_mitad+primera_mitad == coleccion_corredores); 
	cout << endl; 
	cout << endl; 


	//PROBANDO EL OPERADOR - Y -= (NO LO PIDE)

	mensaje = "primeros_cinco - primeros_cinco[1] (REPETIDO)";

	cout << endl;
	cout << (primeros_cinco - primeros_cinco[1]).ToString(mensaje); 
	cout << "Total corredores = "<< setw(3) 
	     << (primeros_cinco - primeros_cinco[1]).Usados() << endl; 
	cout << endl; 


	mensaje = "(coleccion_corredores - primeros_cinco) - ultimos_cinco";

	cout << endl;
	cout << ((coleccion_corredores - primeros_cinco) - ultimos_cinco)\
			.ToString(mensaje); 
	cout << "Total corredores = "<< setw(3) 
	     << ((primeros_cinco - primeros_cinco)-ultimos_cinco).Usados() << endl; 
	cout << endl; 


	cout << endl; 
	cout << "primeros_cinco - ultimos_cinco  == primeros_cinco --> " 
	     << boolalpha << (primeros_cinco - ultimos_cinco  == primeros_cinco); 
	cout << endl; 
	cout << endl; 


	cout << endl; 
	cout << "ultimos_cinco - primeros_cinco == ultimos_cinco --> " 
	     << boolalpha << (ultimos_cinco - primeros_cinco == ultimos_cinco); 
	cout << endl; 
	cout << endl; 


	cout << endl; 
	cout << "primeros_cinco - primeros_cinco = " << boolalpha 
		 << (primeros_cinco - primeros_cinco).Usados() << endl; 



	mensaje = "primeros_cinco -= primeros_cinco[";

	cout << endl;
	cout << primeros_cinco.ToString("Primeros cinco"); 
	cout << "Total corredores = "<<setw(3) << primeros_cinco.Usados() << endl; 
	cout << endl; 

	cout << endl;
	cout << endl;
	cout<<"Eliminando primeros_cinco corredor a corredor"<<endl;

	for (int i = 1; i<= 5; i++){

		primeros_cinco -= primeros_cinco[1];

		cout << endl;
		cout << (primeros_cinco).ToString(mensaje+to_string(i)+']'); 
		cout << "Total corredores = "<< setw(3) 
			<< (primeros_cinco).Usados() << endl; 
	}
	cout<<endl;


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