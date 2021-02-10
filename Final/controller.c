#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "estructuras.h"
#include "parser.h"


/** \brief ingresa los datos desde el .csv
 * \param path
 * \param pList
 * \return 0 error, 1 success
 */

int controller_deLaCanal_loadFromText(char* path, LinkedList* pList){
    int ok=0;

    FILE* f;
    if(path!=NULL && pList!=NULL){
        f=fopen(path,"r");
        if(f!=NULL){
            if(parser_loadFromText(f,pList)){
                printf("Lista Cargada con Exito!!\n\n");
                fclose(f);
                ok=1;
            }
            else{
                printf("ERROR!!!\n\n");
            }
        }
    }
    return ok;
}


/** \brief lista solo uno
 * \param eEstructura
 */

void listOne(eEstructura* e){
    if(e!=NULL){
        printf(" %2d %10s  %10s  %2d  %4d\n",e->id_corredor,e->apellido,e->tipo,e->promedio,e->tiempo);
    }
}


/** \brief imprime en el sistema los datos
 */
int controller_deLaCanal_listAll(LinkedList* pList){
    int ok=0;
    eEstructura* e;

    if(pList!=NULL){
        ok=1;
        system("cls");
        printf(" ID   APELLIDO   TIPO       PROMEDIO  TIEMPO\n");
        for(int i=0; i<ll_len(pList); i++){
            e=(eEstructura*)ll_get(pList,i);
            listOne(e);
        }
    }

    return ok;
}
/** \brief Asigna los valores del parametro tiempo
 */
int controller_deLaCanal_map(LinkedList* pList){
	int ok=0;

	pList=ll_map(pList, asignarTiempo);
	if(pList != NULL)
	{
		controller_deLaCanal_listAll(pList);
		ok=1;
	}

	return ok;
}

/** \brief guarda los datos en .csv
 */
int controller_deLaCanal_saveAsText(char* path , LinkedList* pList)
{

        FILE* file;
	    eEstructura* e;
	    int i;
	    int len = -1;
	    int id_carrera;
        int promedio;
        int tiempo;
        char apellido[50];
        char tipo[50];

	    int aux=0;

	    if(path != NULL && pList != NULL){
	        len = ll_len(pList);
	        if(len > 0){
	            file = fopen(path,"w");
	            if(file!=NULL){
	            	fprintf(file,"id_corredor,apellido,tipo,promedio,tiempo\n");
	                for(i=0;i<len;i++){
	                    e=(eEstructura*)ll_get(pList,i);
	                    getId(e,&id_carrera);
                        getApellido(e,apellido);
                        getTipo(e,tipo);
                        getPromedio(e,&promedio);
                        getTiempo(e,&tiempo);
	                    fprintf(file,"%d,%s,%s,%d,%d\n",id_carrera,apellido,tipo,promedio,tiempo);
	                }
	                fclose(file);
	                if(i == len){
	                    aux = 1;
	                }
	            }
	        }
	    }
	    if(aux == 1)
	    {
	         	printf("El archivo se ha cargado correctamente\n");
	    }
	    else
	    {
	        if(len == 0)
	        {
	        	printf("La lista está vacia!!");
	        }
	        else
	        {
	        	printf("Ups!, ocurrio un error al salvar los datos");
	        }
	    }
	    return aux;
}

