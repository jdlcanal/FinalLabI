#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "LinkedList.h"
#include "controller.h"

int main()
{
    char ans='n';

    LinkedList* pList=ll_newLinkedList();
    if(pList==NULL){
        printf("ERROR!!!\n\n");
        exit(EXIT_FAILURE);
    }

    do{
        system("cls");
        switch(menu()){
        case 1:
            if(ll_isEmpty(pList)==1){
                system("cls");
                controller_deLaCanal_loadFromText("AutosCarrera.csv",pList);
            }
            else{
                system("cls");
                printf("Lista Ya Subida!!!\n\n");
            }
            break;
        case 2:
            if(ll_isEmpty(pList)==0){
                system("cls");
                controller_deLaCanal_listAll(pList);
            }
            else{
                system("cls");
                printf("Primero debes subir la lista!!\n\n");
            }
            break;
        case 3:
            if(ll_isEmpty(pList)==0){
                system("cls");
                controller_deLaCanal_map(pList);
            }
            break;
        case 4:
            if(ll_isEmpty(pList)==0){
                system("cls");
                controller_deLaCanal_saveAsText("AutosCarreraGuardado.csv",pList);
            }
            else{
                system("cls");
                printf("Error!!!\n\n");
            }
            break;
        case 5:
            printf("\nSeguro que desea salir?? s/n  ");
            fflush(stdin);
            scanf("%c",&ans);
            if(ans=='s'){
                printf("\n\nSee you later!!\n\n");
            }
            break;
        default:
            printf("Ingrese una opcion valida!!\n\n");
            break;
        }
        system("pause");
    }while(ans=='n');

    return 0;
}
