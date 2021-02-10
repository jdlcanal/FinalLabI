#include "LinkedList.h"

#ifndef MUSIC_ARTISTS_H_INCLUDED
#define MUSIC_ARTISTS_H_INCLUDED

typedef struct{
    int id_corredor;
    char apellido[50];
    char tipo[50];
    int promedio;
    int tiempo;
}eEstructura;

#endif // MUSIC_ARTISTS_H_INCLUDED

eEstructura* e_new();
eEstructura* newParam(char* id_corredorStr, char* apellidoStr, char* tipoStr, char* promedioStr, char* tiempoStr);

int setId(eEstructura* e, int id_corredor);
int getId(eEstructura* e, int* id_corredor);

int setPromedio(eEstructura* e, int promedio);
int getPromedio(eEstructura* e, int* promedio);

int setTiempo(eEstructura* e, int tiempo);
int getTiempo(eEstructura* e, int* tiempo);

int setApellido(eEstructura* e, char* apellido);
int getApellido(eEstructura* e, char* apellido);

int setTipo(eEstructura* e, char* tipo);
int getTipo(eEstructura* e, char* tipo);

void* asignarTiempo(void* tiempo);

