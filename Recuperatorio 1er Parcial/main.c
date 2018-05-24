#include <stdio.h>
#include <stdlib.h>
#include "aviso.h"
#include "cliente.h"

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

    strcpy(arrayDeClientes[0].nombre, "Francisco");
    strcpy(arrayDeClientes[0].apellido, "Galeano");
    strcpy(arrayDeClientes[0].cuit,"334567823");
    arrayDeClientes[0].idCliente = 0;
    arrayDeClientes[0].isEmpty = 0;

    strcpy(arrayDeClientes[1].nombre, "Martin");
    strcpy(arrayDeClientes[1].apellido, "Livolsi");
    strcpy(arrayDeClientes[1].cuit,"444567823");
    arrayDeClientes[1].idCliente = 1;
    arrayDeClientes[1].isEmpty = 0;

    strcpy(arrayDeClientes[2].nombre, "Matias");
    strcpy(arrayDeClientes[2].apellido, "Asnard");
    strcpy(arrayDeClientes[2].cuit,"224567823");
    arrayDeClientes[2].idCliente = 2;
    arrayDeClientes[2].isEmpty = 0;

    arrayDeAvisos[0].rubro = 1;
    strcpy(arrayDeAvisos[0].texto, "Vendo Cosas De Oro");
    arrayDeAvisos[0].idAviso = 0;
    arrayDeAvisos[0].isEmpty = 0;
    arrayDeAvisos[0].estado = 1;
    arrayDeAvisos[0].idCliente = 0;

    arrayDeAvisos[1].rubro = 1;
    strcpy(arrayDeAvisos[1].texto, "Compro Vegetales");
    arrayDeAvisos[1].idAviso = 1;
    arrayDeAvisos[1].isEmpty = 0;
    arrayDeAvisos[1].estado = 1;
    arrayDeAvisos[1].idCliente = 0;

    arrayDeAvisos[2].rubro = 1;
    strcpy(arrayDeAvisos[2].texto, "Alquilo Cocheras");
    arrayDeAvisos[2].idAviso = 2;
    arrayDeAvisos[2].isEmpty = 0;
    arrayDeAvisos[2].estado = 1;
    arrayDeAvisos[2].idCliente = 0;

    arrayDeAvisos[3].rubro = 2;
    strcpy(arrayDeAvisos[3].texto, "Compro Cable Inalambrico");
    arrayDeAvisos[3].idAviso = 3;
    arrayDeAvisos[3].isEmpty = 0;
    arrayDeAvisos[3].estado = 1;
    arrayDeAvisos[3].idCliente = 1;

    arrayDeAvisos[4].rubro = 2;
    strcpy(arrayDeAvisos[4].texto, "Permuto Celulares");
    arrayDeAvisos[4].idAviso = 4;
    arrayDeAvisos[4].isEmpty = 0;
    arrayDeAvisos[4].estado = 1;
    arrayDeAvisos[4].idCliente = 1;

    arrayDeAvisos[5].rubro = 3;
    strcpy(arrayDeAvisos[5].texto, "Compro Chispas Para Bujia");
    arrayDeAvisos[5].idAviso = 5;
    arrayDeAvisos[5].isEmpty = 0;
    arrayDeAvisos[5].estado = 1;
    arrayDeAvisos[5].idCliente = 2;

    do
    {
        printf("Que accion le gustaria realizar?\n");
        printf("1) Dar de alta un cliente.\n");
        printf("2) Modificar datos de un cliente.\n");
        printf("3) Dar de baja un cliente.\n");
        printf("4) Realizar una publicacion.\n");
        printf("5) Pausar una publicacion.\n");
        printf("6) Reanudar una publicaion.\n");
        printf("7) Impirmir lista de clientes.\n");
        printf("8) Imprimir lista de publicaciones.\n");
        printf("9) Informar clientes.\n");
        printf("10) Informar publicaciones.\n\n");
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
                clte_baja(arrayDeClientes, QTY, auxiliarId);
                fflush(stdin);
                printf("Desea continuar? S/N\n");
                scanf("%c", &respuesta);
                system("cls");
                break;
            case 4:
                avi_alta(arrayDeAvisos, LEN_AVISO, arrayDeClientes, QTY);
                fflush(stdin);
                printf("Desea continuar? S/N\n");
                scanf("%c", &respuesta);
                system("cls");
                break;
            case 5:
                avi_pausarPublicacion(arrayDeAvisos, LEN_AVISO, arrayDeClientes, QTY);
                fflush(stdin);
                printf("Desea continuar? S/N\n");
                scanf("%c", &respuesta);
                system("cls");
                break;
            case 6:
                avi_reanudarPublicacion(arrayDeAvisos, LEN_AVISO, arrayDeClientes, QTY);
                fflush(stdin);
                printf("Desea continuar? S/N\n");
                scanf("%c", &respuesta);
                system("cls");
                break;
            case 7:
                informar_listarClientes(arrayDeClientes, QTY, arrayDeAvisos, LEN_AVISO);
                fflush(stdin);
                printf("Desea continuar? S/N\n");
                scanf("%c", &respuesta);
                system("cls");
                break;
            case 8:
                informar_avisosActivos(arrayDeClientes, QTY, arrayDeAvisos, LEN_AVISO);
                fflush(stdin);
                printf("Desea continuar? S/N\n");
                scanf("%c", &respuesta);
                system("cls");
                break;
            case 9:
                informar_seleccionDeInformeDeClientes(arrayDeClientes, QTY, arrayDeAvisos, LEN_AVISO);
                fflush(stdin);
                printf("Desea continuar? S/N\n");
                scanf("%c", &respuesta);
                system("cls");
                break;
            case 10:
                informar_seleccionDeInformeDeRubros(arrayDeAvisos, LEN_AVISO);
                fflush(stdin);
                printf("Desea continuar? S/N\n");
                scanf("%c", &respuesta);
                system("cls");
                break;
            default:
                printf("Ingrese una opcion que sea valida.\n");
                fflush(stdin);
                printf("Desea continuar? S/N\n");
                scanf("%c", &respuesta);
                system("cls");
                break;
        }

    }while(respuesta == 's');

    return 0;
}
