/***************************************************************************/
//Metodología de la Programación
//
//Implementación de Funciones sobre el tratamiento de cadenas de caracteres.
//
//Módulo de implementación
//
// Fichero: MiCadenaClasica.cpp
/***************************************************************************/
#include "MiCadenaClasica.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/

///////////////////////////////////////////////////////////////////////////////
/*Devuelve la longitud de la cadena "chain", sin contar el caracter nulo final
Imita el funcionamiento de strlen() de cstring
    const char * chain: cadena de caracteres
Imita el funcionamiento de strlen() de cstring
*/
int chainlen(const char * chain){
    int lenght=0;
    for (;*chain!=0; chain++, lenght++);
    return lenght;
}

///////////////////////////////////////////////////////////////////////////////
/*Elimina el caracter en la posición "index"
(si existe y no es el caracter terminal) de la cadena "chain"
    char * chain: cadena de caracteres
    unsigned int index: posición del caracter a eliminar
Devuelve true si se eliminó el caracter, false de lo contrario
*/
bool charremove(char * chain, unsigned int index){
    char * p_chain=chain+index;
    unsigned int chain_lenght=chainlen(chain);

    if (index >= chain_lenght){
        return false;
    }

    while (p_chain<chain+chain_lenght-1){
        *p_chain=*(p_chain+1);
        p_chain++;
    }
    *p_chain=0;

    return true;
}

///////////////////////////////////////////////////////////////////////////////
/*Elimina el o los caracteres "character" de la cadena "chain"
    char * chain: cadena de caracteres
    char character: caracter a eliminar
Devuelve la cadena modificada
*/
char * chaindelete(char * chain, char character){
    char * p_chain=chain;
    int chain_lenght=chainlen(chain);

    for(int i=0; i<=chain_lenght; i++, p_chain++){
        if (*p_chain==character)
            charremove(chain,i);
    }
    return chain;
}

///////////////////////////////////////////////////////////////////////////////
/*Añade la cadena "chain_added" al final de la cadena "chain"
    char * chain: cadena de caracteres
    const char * chain_added: cadena de caracteres a añadir
Devuelve la cadena modificada chain
*/
char * chainappend(char * chain, const char * chain_added){
    unsigned int chain_added_lenght= chainlen(chain_added);
    char * p_chain=chain+chainlen(chain);     //apunta al final de la cadena

    for (int i=0; i<chain_added_lenght; i++, p_chain++, chain_added++)
        *p_chain=*chain_added;
    
    *(p_chain)=0;

    return chain;
}

///////////////////////////////////////////////////////////////////////////////
/*Compara las cadenas "chain1" y "chain2". 
    const char * chain1: cadena de caracteres
    const char * chain2: cadena de caracteres
Devuelve:
    0 si son iguales, 
    1 si "chain1" es mayor que "chain2" y
    -1 si "chain1" es menor que "chain2"
Imita el funcionamiento de strcmp() de cstring
*/
int chaincmp(const char * chain1, const char * chain2){
    
    //compara los caracteres de ambas cadenas hasta el fin 
    //o hasta que sean diferentes
    for (;*chain1==*chain2 && *chain1!=0 && chain2!=0; chain1++, chain2++);

    //en funcion de los caracteres desiguales, devuelve 1, -1 o 0
    if (*chain1 > *chain2)
        return 1;
    else if (*chain1 < *chain2)
        return (-1);
    return 0;
}

///////////////////////////////////////////////////////////////////////////////
/*Copia la cadena "c_original" en la cadena "c_copia"
El uso del parametro opcional exception hace que se omitan caracteres
especificados en la copia
    char * c_copia: cadena de caracteres donde se copiará la cadena original
    const char * c_original: cadena de caracteres a copiar
    char exception: caracter a omitir en la copia
Devuelve la cadena modificada c_copia
*/
char * copiar_cadena(char * c_copia, const char * c_original,char exception=0){
    char * p_copia=c_copia;

    //el uso de exception hace que se omitan caracteres específicos en la copia
    for (;*c_original!=0; c_original++){
        if (*c_original!=exception){
            *p_copia=*c_original;
            p_copia++;
        }
    }
    *p_copia=0;

    return c_copia;
}


///////////////////////////////////////////////////////////////////////////////
/*Devuelve la subcadena de "origen" que comienza en la posición "p" y
tiene longitud "l"
    char * resultado: cadena de caracteres donde se copiará la subcadena
    const char * origen: cadena de caracteres original
    int p: posición de inicio de la subcadena
    int l: longitud de la subcadena
Devuelve la cadena modificada resultado
*/
char * extraer_subcadena (char * subcadena, const char * origen, int p, int l){
    char * p_subcad=subcadena;
    const char * fin=origen+l;
    
    //copia los caracteres desde origen+p hasta el caracter l-ésimo
    for (;origen+p<=origen+l && *(origen+p)!=0; p++, p_subcad++)
        *p_subcad=*(origen+p);
    *p_subcad=0;

    return subcadena;
}


///////////////////////////////////////////////////////////////////////////////
/*Copia la cadena Origen en la cadena Resultado, eliminando los blancos
iniciales
    char * resultado: cadena de caracteres donde se copiará la cadena original
    const char * origen: cadena de caracteres a copiar
Devuelve la cadena modificada resultado
*/
char * eliminar_blancos_iniciales (char * resultado, const char * origen){
    const char * p_origen=origen;

    //avanza el inicio de la cadena hasta encontrar un caracter no espaciador
    for (;isspace(*p_origen); p_origen++);

    //copia en resultado el origen a partir del primer caracter no espaciador
    return copiar_cadena(resultado,p_origen);
}


///////////////////////////////////////////////////////////////////////////////
/*Copia la cadena Origen en la cadena Resultado, eliminando los blancos finales
    char * resultado: cadena de caracteres donde se copiará la cadena original
    const char * origen: cadena de caracteres a copiar
Devuelve la cadena modificada resultado
*/
char * eliminar_blancos_finales (char * resultado, const char * origen){
    char * pr=copiar_cadena(resultado,origen);

    for (;*(pr+1)!=0;pr++);  //busca el final de la cadena

    for (;isspace(*pr); pr--)    //sustituye cada espacio por terminadores
        *pr=0;
    
    return resultado;
}


///////////////////////////////////////////////////////////////////////////////
/*Copia la cadena Origen en la cadena Resultado, eliminando los blancos
iniciales y finales
    char * resultado: cadena de caracteres donde se copiará la cadena original
    const char * origen: cadena de caracteres a copiar
Devuelve la cadena modificada resultado
*/
char * eliminar_blancos_extremos (char * resultado, const char * origen){
    
    eliminar_blancos_iniciales(resultado,origen);
    eliminar_blancos_finales(resultado,resultado);
    
    return resultado;
}


///////////////////////////////////////////////////////////////////////////////
/*Copia la cadena Origen en la cadena Resultado, eliminando los blancos
intermedios
    char * resultado: cadena de caracteres donde se copiará la cadena original
    const char * origen: cadena de caracteres a copiar
Devuelve la cadena modificada resultado
*/
char * eliminar_blancos_intermedios (char * resultado, const char * origen){
    const char *p_origen=origen;
    const char *p_fin_origen;
    char *p_resultado=resultado;

    //copia los primeros espacios en el resultado
    for(;isspace(*p_origen); p_origen++, p_resultado++)
        *p_resultado=*p_origen;

    //ignora los últimos espacios
    p_fin_origen=origen+chainlen(origen)-1;
    while(isspace(*p_fin_origen)) //retrocede hasta omitir los espacios finales
        p_fin_origen--;
    
    //Copia el contenido de origen en resultado ignorando los espacios
    // hasta llegar a los espacios finales
    for(;p_origen<=p_fin_origen; p_origen++){
        if (!isspace(*p_origen)){
            *p_resultado=*p_origen;
            p_resultado++;
        }
    }

    //añade los espacios finales
    for(;*p_origen!=0; p_resultado++, p_origen++)
        *p_resultado=*p_origen;
    *p_resultado=0;
    
    return resultado;
}


///////////////////////////////////////////////////////////////////////////////
/*Copia la cadena Origen en la cadena Resultado, eliminando todos los blancos
    char * resultado: cadena de caracteres donde se copiará la cadena original
    const char * origen: cadena de caracteres a copiar
Eliminar_blancos_intermedios+eliminar_blancos_extremos
*/
char * eliminar_todos_blancos (char * resultado, const char * origen){
    
    eliminar_blancos_extremos(resultado, origen);

    return eliminar_blancos_intermedios(resultado, resultado);
}

/***************************************************************************/
/***************************************************************************/