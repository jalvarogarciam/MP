/***************************************************************************/
//Implementación de Funciones relacionadas con el tratamiento de vectores de enteros.
// Fichero: ProcesamientoArrayInt.cpp
/***************************************************************************/
#include "ProcesamientoArrayInt.h"
#include "GeneradorAleatorioEnteros.h"

using namespace std;

void MuestraVector (const char *msg, int *p, int num_datos, int num_datos_linea){
	char separador;
    cout<<msg<<endl;
    for (int i=0; i<num_datos; i++) {
		if (((i+1)%num_datos_linea)==0)
            separador='\n';
        else
            separador=' ';
		cout <<setw(3)<< *(p+i) << separador;
	}
}
void MuestraVector (int *p, int num_datos){
	char separador;
    for (int i=0; i<num_datos; i++) {
		if (((i+1)%num_datos)==0)
            separador='\n';
        else
            separador=' ';
		cout <<setw(3)<< *(p+i) << separador;
	}
}
void IntercambiaEnteros(int *a , int *b){
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}
void RellenaVector (int *p, int num_datos, int min_aleat, int max_aleat){
    GeneradorAleatorioEnteros entero_aleatorio(min_aleat, max_aleat);
    for(int *pv=p; pv < p+num_datos; pv++){
        *pv=entero_aleatorio.Siguiente();
    }
}
void CopiaVector(int *p_original, int *p_copia, int num_datos){
    int *p_o=p_original;
    int *p_c=p_copia;
    for (int i=0; i < num_datos; i++, p_o++, p_c++){
        *p_c=*p_o;
    }
}
void MezclaVector(int *v1, int *v2, int *res, int tam_v1, int tam_v2, int tam_res){
    int * p_v1 = v1;
    int * p_v2 = v2;
    int * p_res = res;
    if(tam_v1+tam_v2<=tam_res){
        for (int i=0; i<tam_v1; i++,p_v1++,p_res++){
            *p_res=*p_v1;
        }
        for (int i=0; i<tam_v2; i++,p_v2++,p_res++){
            *p_res=*p_v2;
        }
    }
}
void OrdenaSeleccion (int *v, int pos_inic, int pos_fin){
    int * pv=v+pos_inic;
    int * p_menor, * primer_elemento;
    int num_ciclos=pos_fin-pos_inic;// uno menos que el nº de elementos
    for(int i=0; i<num_ciclos; i++){
        primer_elemento=v+pos_inic+i;
        pv=primer_elemento;
        p_menor=primer_elemento;
        for(int j=0; j<num_ciclos-i; j++){//resto i para mayor eficiencia
            pv++;
            if (*p_menor > *pv)
                p_menor=pv;
        }
        IntercambiaEnteros(primer_elemento,p_menor);
    }
}
void OrdenaInsercion (int *v, int pos_inic, int pos_fin){
    for(int *p_elemento=v+1, i=1; p_elemento <= v+pos_fin; p_elemento++,i++){
        int elemento=*p_elemento;
        int *pv;
        for(pv=p_elemento-1; pv>=v+pos_inic && *pv > elemento; pv--){
            *(pv+1)=*pv;
        }
        *(pv+1)=elemento;
    }
}
void OrdenaIntercambio (int *v, int pos_inic, int pos_fin){
    int *pv;
    int num_ciclos=pos_fin-pos_inic;// uno menos que el nº de elementos
    for (int i=0; i<num_ciclos; i++){
        pv=v+pos_inic;
        for (int j=0; j<num_ciclos-i; j++){//resto i para mayor eficiencia
            if(*(pv) > *(pv+1))
                IntercambiaEnteros(pv,pv+1);
            pv++;
        }
    }
}
