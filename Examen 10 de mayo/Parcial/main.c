#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "clientes.h"
#include "avisos.h"
#include "informar.h"

#define QTY 100
#define LEN_AVISO 1000


int main(void)
{

    Cliente arrayDeClientes[QTY];
    Aviso arrayDeAvisos[LEN_AVISO];
    int menu;
    char respuesta = 's';
    int auxiliarId;

    clte_crear(arrayDeClientes, QTY);

    avi_crear(arrayDeAvisos, LEN_AVISO);



    do
    {
        printf("Que accion le gustaria realizar?\n");
        printf("1) Dar de alta un cliente.\n");
        printf("2) Modificar datos de un cliente.\n");
        printf("3) Dar de baja un cliente.\n");
        printf("4) Realizar una publicacion.\n");
        printf("5) Pausar una publicacion.\n");
        printf("6) Reanudar una puclicaion.\n");
        printf("7) Impirmir lista de clientes.\n");
        printf("8) Imprimir lista de publicaciones.\n");
        printf("9) Informar clientes.\n");
        printf("10) Informar publicaciones.\n");
        scanf("%d", &menu);
        switch(menu)
        {
            case 1:
                clte_alta(arrayDeClientes, QTY);
                fflush(stdin);
                printf("Desea continuar? S/N\n");
                scanf("%c", &respuesta);
                system("cls");
                break;
            case 2:
                clte_modificar(arrayDeClientes, QTY);
                fflush(stdin);
                printf("Desea continuar? S/N\n");
                scanf("%c", &respuesta);
                system("cls");
                break;
            case 3:
                clte_baja(arrayDeClientes, QTY, &auxiliarId);
                fflush(stdin);
                printf("Desea continuar? S/N\n");
                scanf("%c", &respuesta);
                system("cls");
                break;
            case 4:
                avi_alta(arrayDeAvisos, LEN_AVISO);
                fflush(stdin);
                printf("Desea continuar? S/N\n");
                scanf("%c", &respuesta);
                system("cls");
                break;
            case 5:
                avi_modificar(arrayDeAvisos, LEN_AVISO);
                fflush(stdin);
                printf("Desea continuar? S/N\n");
                scanf("%c", &respuesta);
                system("cls");
                break;
            case 6:
                avi_modificar(arrayDeAvisos, LEN_AVISO);
                fflush(stdin);
                printf("Desea continuar? S/N\n");
                scanf("%c", &respuesta);
                system("cls");
                break;
            case 7:
                infomar_imprimirClientes(arrayDeClientes, QTY, arrayDeAvisos, LEN_AVISO);
                fflush(stdin);
                printf("Desea continuar? S/N\n");
                scanf("%c", &respuesta);
                system("cls");
                break;
            case 8:
                informar_imprimirAvisos(arrayDeAvisos, LEN_AVISO, arrayDeClientes, QTY);
                fflush(stdin);
                printf("Desea continuar? S/N\n");
                scanf("%c", &respuesta);
                system("cls");
                break;
            case 9:

                break;
            case 10:

                break;
            default:
                printf("Ingrese una opcion que sea valida.\n");
                break;
        }

    }while(respuesta == 's');

    return 0;
}
