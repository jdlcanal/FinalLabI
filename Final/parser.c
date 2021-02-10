#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"

/** \brief parsea los datos del .csv
 */
int parser_loadFromText(FILE* pFile, LinkedList* pList){
    int ok=0;
    char buff[4][200];
    eEstructura* e=NULL;

    if(pFile!=NULL && pList!=NULL){
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buff[0],buff[1],buff[2],buff[3],buff[4]);
        do{
            if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buff[0],buff[1],buff[2],buff[3],buff[4])==5){
                e=newParam(buff[0],buff[1],buff[2],buff[3],buff[4]);

                if(e!=NULL){
                    ll_add(pList,e);
                    ok=1;
                }
            }
            else{
                ok=0;
                break;
            }
        }while(feof(pFile)==0);
    }

    return ok;
}

