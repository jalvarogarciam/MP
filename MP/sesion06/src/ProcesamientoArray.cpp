/***************************************************************************/
//Implementacion de Funciones de tratamiento de vectores de enteros.
//
//Archivo de implementación
//
// Fichero: ProcesamientoArrayInt.cpp
/***************************************************************************/
#include "ProcesamientoArray.h"
#include "GeneradorAleatorioEnteros.h"
#include <cstring>

#include <iostream>
#include <iomanip>

using namespace std;


///////////////////////////////////////////////////////////////////////////////
/*Muestra por terminal el contenido de un vector de enteros con un formato
determinado por setw() y el número de datos por línea.
Parametros:
    - array: puntero al primer elemento del vector
    - num_data: número de datos a mostrar
    - num_data_line: número de datos por línea
    - msg: mensaje a mostrar antes de los datos
*/
void print_array\
(T *array, int num_data, int num_data_line, const char *msg){
	if (num_data_line==0)   //num_data_line=num_data por defecto
        num_data_line=num_data;

    cout<<endl<<msg<<endl<<endl;

    for (int i=0; i<num_data; i++) {
        char separador = (((i+1)%num_data_line)==0) ? '\n':' ';

		cout <<setw(4)<< *(array+i) << separador;
	}
    cout<<endl;
}

///////////////////////////////////////////////////////////////////////////////
/*Intercambia el contenido de dos variables enteras a y b.
*/
void swp(T *a , T *b){
    T tmp=*a;
    *a=*b;
    *b=tmp;
}

///////////////////////////////////////////////////////////////////////////////
/*Rellena un vector de enteros con números aleatorios en un rango determinado.
Parametros:
    - array: puntero al primer elemento del vector
    - num_data: número de datos a rellenar
    - min_rand: valor mínimo del rango
    - max_rand: valor máximo del rango
Solo funciona para enteros.
*/ 
T *random_fill_array (T *array, int num_data, int min_rand, int max_rand){
    GeneradorAleatorioEnteros random_integer(min_rand, max_rand);
    
    for(T *p=array; p < array+num_data; p++){
        *p=random_integer.Siguiente();
    }
    return array;
}

///////////////////////////////////////////////////////////////////////////////
/*Copia el contenido de un vector de enteros en otro.
Parametros:
    - p_original: puntero al primer elemento del vector original
    - p_copy: puntero al primer elemento del vector copia
    - num_data: número de datos a copiar
*/
T *copy_array(T *p_copy, T *p_original, int num_data){
    
    memcpy(p_copy, p_original, sizeof(T)*num_data);

    return p_copy;
}


///////////////////////////////////////////////////////////////////////////////
/*Elimina un entero de un vector de enteros.
Parametros:
    - array: puntero al primer elemento del vector
    - index: posición del entero a eliminar
    - size: número de datos del vector
*/
void rmv(T * array, int index, int size){
    
    memmove(array+index, array+index+1, size-index-1);
}


///////////////////////////////////////////////////////////////////////////////
/*Elimina los elementos duplicados de un vector de enteros. Usa el algoritmo de 
los dos apuntadores. (posicion_lectura=reading_pos y 
posicion_escritura= writing_pos)
Parametros:
    - array: puntero al primer elemento del vector
    - size: número de datos del vector
Devuelve la talla del vector
*/
int remove_duplicates(T * array, int size){

    int writing_pos = 0;

    for (int reading_pos = 0; reading_pos < size; reading_pos++){
        
        // Comprueba si array[reading_pos] está duplicado entre 0 y reading_pos
        bool is_duplicate = false;
        T * p_lectura=array+reading_pos;
        for (int i = 0; i < writing_pos && !is_duplicate; i++) {
            if (*(array+i) == *p_lectura)
                is_duplicate = true;
        }

        // Si no está duplicado, copia el elemento a array[writing_pos] 
        //y avanza writing_pos
        if (!is_duplicate) {
            *(array+writing_pos) = *p_lectura;
            writing_pos++;
        }
    }

    //writing_pos es el número de elementos únicos
    return writing_pos;
}



///////////////////////////////////////////////////////////////////////////////
/*Busca un entero en un vector de enteros y devuelve un puntero a su posición.
Parametros:
    - element: entero a buscar
    - array: puntero al primer elemento del vector
    - array_size: número de datos del vector
    - init_pos: posición inicial del subconjunto a buscar
    - last_pos: posición final del subconjunto a buscar
PRE: init_pos >= 0
PRE: last_pos < array_size
*/
T * search\
(T element, T *array, int array_size, int init_pos, int last_pos){
    
    if (last_pos==0 || last_pos>=array_size)//reajuste del parametro por defecto
        last_pos=array_size;

    array+=init_pos;    //reajuste para tratarlo como subconjunto

    T const *p_last=array+(last_pos-init_pos);  //último elemento válido

    for (T *p_array=array; p_array<=p_last; p_array++){
        
        if (*p_array==element){

            return p_array; //si lo encuentra devuelve un puntero a su posicion
        }
    }

    return nullptr; //si no lo encuentra devuelve un puntero nulo
}


///////////////////////////////////////////////////////////////////////////////
/*Ordena un vector de enteros mediante el algoritmo de selección.
Parametros:
    - v: puntero al primer elemento del vector
    - init_pos: posición inicial del subconjunto a ordenar
    - last_pos: posición final del subconjunto a ordenar
*/
T * selection_sort(T *v, T init_pos, T last_pos){
    
    if (last_pos<init_pos)   //reajuste de posiciones
        swp(&init_pos,&last_pos);

    v+=int(init_pos);    //reajuste para tratarlo como subconjunto

    T const *p_last=v+int(last_pos-init_pos);  //último elemento válido
    
    T * p_min=v;  // Para entrar

    for (T *p_first=v; p_first<p_last; p_first++, p_min=p_first){

        for(T *pv=p_first; pv<=p_last; pv++){

            if (*p_min > *pv)
                p_min=pv;   //actualiza el minimo
        }
        swp(p_first,p_min);    //intercambia el minimo por el primero
    }

    return v-=int(init_pos); //reajuste para devolver la posicion inicial
}

///////////////////////////////////////////////////////////////////////////////
/*Ordena un vector de enteros mediante el algoritmo de selección.
Parametros:
    - v: puntero al primer elemento del vector
    - size: número de datos a ordenar
*/
T * selection_sort(T *v, int size){
    return selection_sort(v, 0, size-1);
}

///////////////////////////////////////////////////////////////////////////////
/*Ordena un vector de enteros mediante el algoritmo de inserción.
Parametros:
    - v: puntero al primer elemento del vector
    - init_pos: posición inicial del subconjunto a ordenar
    - last_pos: posición final del subconjunto a ordenar
*/
T * insertion_sort(T *v, T init_pos, T last_pos){
    if (last_pos<init_pos)   //reajuste de posiciones
        swp(&init_pos,&last_pos);

    v+=int(init_pos);    //reajuste para tratarlo como subconjunto

    T const *p_last=v+int(last_pos-init_pos);  //último elemento válido

    T *pv;    //puntero de movimiento

    for(T *p_element=v+1, i=1; p_element <= p_last; p_element++,i++){
        
        T element=*p_element;   //para guardar su valor inicial

        for(pv=p_element-1; pv>=v && *pv > element; pv--){
            *(pv+1)=*pv;
        }
        *(pv+1)=element;   //inserta el elemento
    }

    return v-=int(init_pos);
}

///////////////////////////////////////////////////////////////////////////////
/*Ordena un vector de enteros mediante el algoritmo de inserción.
Parametros:
    - v: puntero al primer elemento del vector
    - size: número de datos a ordenar
*/
T * insertion_sort(T *v, int size){
    return insertion_sort(v, 0, size-1);
}

///////////////////////////////////////////////////////////////////////////////
/*Ordena un vector de enteros mediante el algoritmo de burbuja.
Parametros:
    - v: puntero al primer elemento del vector
    - init_pos: posición inicial del subconjunto a ordenar
    - last_pos: posición final del subconjunto a ordenar
*/
T * bubble_sort(T *v, T init_pos, T last_pos){
    if (last_pos<init_pos)   //reajuste de posiciones
        swp(&init_pos, &last_pos);

    v+=int(init_pos);    //reajuste del inicio para tratarlo como subconjunto
    
    bool change = true; // Para entrar

    for (T *last_element=v+int(last_pos-init_pos); change==true; last_element--)
    {
        //En cada recorrido principal, se reestablece "change" a false
        //solo retornará a true si y solo si ha habido cambios
        change=false;
        
        for (T* pv=v; (pv+1)<=last_element; pv++){

            if(*(pv) > *(pv+1)){

                swp(pv,pv+1);  //intercambio

                change=true;    //hubo al menos un cambio
            }
        }
    }

    return v-int(init_pos);  //reajuste para devolver la posicion inicial
}

///////////////////////////////////////////////////////////////////////////////
/*Ordena un vector de enteros mediante el algoritmo de burbuja.
Parametros:
    - v: puntero al primer elemento del vector
    - size: número de datos a ordenar
*/
T *bubble_sort(T *v, int size){
    return bubble_sort(v, 0, size-1);
}


///////////////////////////////////////////////////////////////////////////////
/*Suma el contenido de dos vectores de enteros y lo almacena en un tercero.
Parametros:
    - v1: puntero al primer elemento del primer vector
    - v2: puntero al primer elemento del segundo vector
    - res: puntero al primer elemento del vector resultante
    - v1_size: número de datos del primer vector
    - v2_size: número de datos del segundo vector
    - res_size: número de datos del vector resultado
*/
//ES IGUAL QUE MezclaVectoresCompleta(int mezcla[], int v1[]...) (ejercicio 29)
int mix_array(T *res, T *v1, int v1_size, T *v2, int v2_size){
    T * p_res = res;  //puntero de movimiento

    //se copia por completo el contenido del primer array en el resultado
    copy_array(res,v1,v1_size);
    p_res+=v1_size;

    //se copia por completo el contenido del segundo array en el resultado
    copy_array(p_res,v2,v2_size);
    p_res+=v2_size;

    bubble_sort(res,p_res-res);  //ordena el vector resultado

    return p_res-res;   //devuelve el número de datos del vector resultado
}


///////////////////////////////////////////////////////////////////////////////
/*Mezcla de forma ordenada el contenido de dos vectores de enteros en un 
tercero, eliminando los elementos repetidos.
Parametros:
    - v1: puntero al primer elemento del primer vector
    - v2: puntero al primer elemento del segundo vector
    - res: puntero al primer elemento del vector resultante
    - v1_size: número de datos del primer vector
    - v2_size: número de datos del segundo vector
    - res_size: número de datos del vector resultado
PRE: res_size >= v1_size + v2_size
*/
//ES IGUAL QUE MezclaVectoresSelectiva(int mezcla[], int v1[]...) (ejercicio 29)
int mix_array_union(T *res, T *v1, int v1_size, T *v2, int v2_size){
    int res_size=mix_array(res, v1, v1_size, v2, v2_size); //mezcla los vectores
    
    res_size=remove_duplicates(res, res_size);  //elimina los elementos rep.

    return res_size;    //devuelve el número de datos del vector resultado
}


///////////////////////////////////////////////////////////////////////////////
/*Engloba las funciones mix_array y mix_array_union en una sola función.
Parametros:
    - mezcla: puntero al primer elemento del vector resultante
    - util_mezcla: número de datos del vector resultante
    - v1: puntero al primer elemento del primer vector
    - util_v1: número de datos del primer vector
    - v2: puntero al primer elemento del segundo vector
    - util_v2: número de datos del segundo vector
    - selectiva: indica si se deben eliminar los elementos repetidos
PRE: util_mezcla >= util_v1 + util_v2
*/
void MezclaVectores (T mezcla[], int & util_mezcla,\
                    T v1[], int util_v1, T v2[], int util_v2,\
                    const char * selectiva){

    if (strcmp(selectiva,"si")==0 || strcmp(selectiva,"SI")==0 || \
        strcmp(selectiva,"Si")==0 || strcmp(selectiva,"sI")==0){
            
        util_mezcla=mix_array_union(mezcla, v1, util_v1, v2, util_v2);

    }else{
        
        mix_array(mezcla, v1, util_v1, v2, util_v2);
        util_mezcla=util_v1+util_v2;
    }
}
