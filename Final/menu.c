#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

/** \brief menu del sistema
 */
int menu(){
    int option;
    printf("Bienvenido!!!\n\n");
    printf("1. Subir\n");
    printf("2. Imprimir\n");
    printf("3. Asignar Tiempos\n");
    printf("4. Guardar Posiciones\n");
    printf("5. Salir\n");
    printf("\nIngresar Opcion: ");
    scanf("%d",&option);

    return option;
}
