#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"

eEstructura* e_new(){
    eEstructura* e=(eEstructura*) malloc(sizeof(eEstructura));

    if(e!=NULL){
        e->id_corredor=0;
        e->promedio=0;
        e->tiempo=0;
        strcpy(e->apellido," ");
        strcpy(e->tipo," ");
    }

    return e;
}

eEstructura* newParam(char* id_corredorStr, char* apellidoStr, char* tipoStr, char* promedioStr, char* tiempoStr){
    eEstructura* e=e_new();

    if(id_corredorStr!=NULL && apellidoStr!=NULL && tipoStr!=NULL && promedioStr!=NULL && tiempoStr!=NULL){
        setId(e,atoi(id_corredorStr));
        setPromedio(e,atoi(promedioStr));
        setTiempo(e,atoi(tiempoStr));
        setApellido(e,apellidoStr);
        setTipo(e,tipoStr);
    }

    return e;
}

int setId(eEstructura* e, int id_corredor){
    int ok=0;

    if(e!=NULL && id_corredor>0){
        e->id_corredor=id_corredor;
        ok=1;
    }
    return ok;
}
int getId(eEstructura* e, int* id_corredor){
    int ok=0;

    if(e!=NULL && id_corredor!=NULL){
        *id_corredor=e->id_corredor;
        ok=1;
    }
    return ok;
}

int setPromedio(eEstructura* e, int promedio){
    int ok=0;

    if(e!=NULL && promedio>0){
        e->promedio=promedio;
        ok=1;
    }
    return ok;
}
int getPromedio(eEstructura* e, int* promedio){
    int ok=0;

    if(e!=NULL && promedio!=NULL){
        *promedio=e->promedio;
        ok=1;
    }
    return ok;
}

int setTiempo(eEstructura* e, int tiempo){
    int ok=0;

    if(e!=NULL && tiempo>=0){
        e->tiempo=tiempo;
        ok=1;
    }
    return ok;
}
int getTiempo(eEstructura* e, int* tiempo){
    int ok=0;

    if(e!=NULL && tiempo!=NULL){
        *tiempo=e->tiempo;
        ok=1;
    }
    return ok;
}

int setApellido(eEstructura* e, char* apellido){
    int ok=0;

    if(e!=NULL && strlen(apellido)>0){
        strcpy(e->apellido, apellido);
        ok=1;
    }
    return ok;
}
int getApellido(eEstructura* e, char* apellido){
    int ok=0;

    if(e!=NULL && apellido!=NULL){
        strcpy(apellido, e->apellido);
        ok=1;
    }
    return ok;
}

int setTipo(eEstructura* e, char* tipo){
    int ok=0;

    if(e!=NULL && strlen(tipo)>0){
        strcpy(e->tipo, tipo);
        ok=1;
    }
    return ok;
}
int getTipo(eEstructura* e, char* tipo){
    int ok=0;

    if(e!=NULL && tipo!=NULL){
        strcpy(tipo, e->tipo);
        ok=1;
    }
    return ok;
}


void* asignarTiempo(void* tiempo){
    eEstructura* aux=NULL;
    int promedios;


    if(tiempo!=NULL){
        aux=(eEstructura*)tiempo;
        getPromedio((eEstructura*)aux,&promedios);
        aux->tiempo=promedios*1.2;
    }
    return aux;
}
