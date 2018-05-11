#include <stdio.h>
#include <stdlib.h>
#include "avisos.h"
#include "clientes.h"


int avi_crear(Aviso * arrayDeAvisos, int sizeArray)
{
    int retorno = -1;
    int i = 0;
    if(sizeArray > 0 && arrayDeAvisos != NULL)
    {
        for(i = 0; i < sizeArray; i++)
        {
            arrayDeAvisos[i].isEmpty = 1;
            retorno = 0;
        }
    }
    return retorno;
}

int avi_alta(Aviso * arrayDeAvisos, int sizeArray, Cliente * arrayDeClientes, int sizeCliente)
{
    int retorno = -1;
    int i;
    int aux;
    int mostrar;
    if(sizeArray > 0 && arrayDeAvisos != NULL)
    {
        for(i = 0; i < sizeArray; i++)
        {
            if(arrayDeAvisos[i].idCliente > -1)
            {
                mostrar = clte_mostrar(arrayDeClientes, sizeCliente);
                printf("Ingrese el ID del cliente.\n");
                scanf("%d", &aux);
                if(arrayDeClientes[i].idCliente == aux)
                {
                    printf("Ingrese el rubro del aviso.\n");
                    fflush(stdin);
                    scanf("%d", arrayDeAvisos[aux].rubro);
                    printf("Ingrese el texto del aviso.\n");
                    fflush(stdin);
                    gets(arrayDeAvisos[aux].texto);
                    arrayDeAvisos[i].idAviso = i;
                    arrayDeAvisos[i].isEmpty = 0;
                    retorno = 0;
                }
                else{
                    while(arrayDeAvisos[i].isEmpty == 0)
                    {
                        break;
                    }
                }
            }
        }
    return retorno;
}

int avi_mostrar(Aviso * arrayDeAvisos,int sizeArray)
{
    int retorno = -1;
    int i;
    if(sizeArray > 0 && arrayDeAvisos != NULL)
    {
        for(i = 0; i < sizeArray; i++)
        {
            if(arrayDeAvisos[i].isEmpty == 0)
            {
                 printf("El texto del aviso es %s y el rubro $d, con ID %d\n", arrayDeAvisos[i].texto,
                        arrayDeAvisos[i].rubro, arrayDeAvisos[i].idAviso);
                        retorno = 0;
            }
        }
    }
    return retorno;
}


int avi_baja(Aviso * arrayDeAvisos, int sizeArray, int * AvisoId)
{
    int retorno = -1;
    int aux;
    aux = *AvisoId;

    printf("Que aviso quiere dar de baja?\n");
    scanf("%d", &aux);
    if(sizeArray > 0 && arrayDeAvisos != NULL)
    {
        if(aux > sizeArray)
            {
                printf("Ese numero supera la dimmension de la lista. Intente de nuevo.\n");
                printf("Que aviso quiere dar de baja?\n");
                scanf("%d", &aux);
            }
        while(arrayDeAvisos[aux].isEmpty == 1)
            {
                printf("Ese aviso ya esta vacio. Intente de nuevo.\n");
                printf("Que aviso desea dar de baja?\n");
                scanf("%d", &aux);
            }
        if(aux < sizeArray && arrayDeAvisos[aux].isEmpty == 0)
            {
                arrayDeAvisos[aux].isEmpty = 1;
                printf("Se dio de baja el aviso con el ID %d, del rubro %d con el texto %s.\n", arrayDeAvisos[aux].idAviso,
                       arrayDeAvisos[aux].rubro, arrayDeAvisos[aux].texto);
                       retorno = 0;
            }
    }
        return retorno;
}

int avi_modificar(Aviso * arrayDeAvisos, int sizeArray)
{
    int retorno = -1;
    int aux;
    char respuesta = 's';
    int menu;
    int mostrar;
    int i;
    if(sizeArray > 0 && arrayDeAvisos != NULL)
    {
        for(i = 0; i < sizeArray-1; i++)
        {
            if(arrayDeAvisos[i].isEmpty == 0)
            {
                mostrar = avi_mostrar(arrayDeAvisos, sizeArray);
            }
        }
        printf("Ingrese el ID del aviso a modificar.\n");
        scanf("%d", &aux);
        while(aux > sizeArray || arrayDeAvisos[aux].isEmpty == 1)
        {
            printf("Ingrese un ID valido.\n");
            scanf("%d", &aux);
        }

        do
        {
            printf("Que desea modificar?\n");
            printf("Pausar un aviso      -> Ingrese 1\n");
            printf("Reanudar un aviso    -> Ingrese 2\n");
            scanf("%d", &menu);
            switch(menu)
            {
                case 1:
                    if(arrayDeAvisos[aux].estado == 1)
                    {
                        arrayDeAvisos[aux].estado = 0;
                    }
                    else{
                        printf("Ese aviso ya esta pausado.\n");
                    }
                    printf("Desea continuar? S/N\n");
                    scanf("%c", &respuesta);
                    break;
                case 2:
                    if(arrayDeAvisos[aux].estado == 0)
                    {
                        arrayDeAvisos[aux].estado = 1;
                    }
                    else{
                        printf("Ese aviso ya fue reanudado.\n");
                    }
                    printf("Desea continuar? S/N\n");
                    scanf("%c", &respuesta);
                    break;
                default:
                    printf("Ingrese una opcion valida.\n");
                    break;
            }

        }while(respuesta == 's');
    retorno = 0;
        }
    }
    return retorno;
}
