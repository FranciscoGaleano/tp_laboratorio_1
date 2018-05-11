#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"

int clte_crear(Cliente * arrayDeClientes, int sizeArray)
{
    int retorno = -1;
    int i = 0;
    if(sizeArray > 0 && arrayDeClientes != NULL)
    {
        for(i = 0; i < sizeArray; i++)
        {
            arrayDeClientes[i].isEmpty = 1;
            retorno = 0;
        }
    }
    return retorno;
}

int clte_alta(Cliente * arrayDeClientes, int sizeArray)
{
    int retorno = -1;
    int i;
    if(sizeArray > 0 && arrayDeClientes != NULL)
    {
        for(i = 0; i < sizeArray; i++)
        {
            if(arrayDeClientes[i].isEmpty == 1)
            {
                printf("Ingrese el nombre del cliente.\n");
                fflush(stdin);
                gets(arrayDeClientes[i].nombre);
                printf("Ingrese el apellido del cliente.\n");
                fflush(stdin);
                gets(arrayDeClientes[i].apellido);
                printf("Ingrese el CUIT del cliente.\n");
                fflush(stdin);
                gets(arrayDeClientes[i].cuit);
                arrayDeClientes[i].idCliente = i;
                arrayDeClientes[i].isEmpty = 0;
                retorno = 0;
                break;
            }
            else{
                while(arrayDeClientes[i].isEmpty == 0)
                {
                    break;
                }
            }
        }
    }
    return retorno;
}

int clte_mostrar(Cliente * arrayDeClientes,int sizeArray)
{
    int retorno = -1;
    int i;
    if(sizeArray > 0 && arrayDeClientes != NULL)
    {
        for(i = 0; i < sizeArray; i++)
        {
            if(arrayDeClientes[i].isEmpty == 0)
            {
                 printf("El cliente que puede modificar se llama %s %s, con ID %d\n", arrayDeClientes[i].nombre,
                        arrayDeClientes[i].apellido, arrayDeClientes[i].idCliente);
                        retorno = 0;
            }
        }
    }
    return retorno;
}


int clte_baja(Cliente * arrayDeClientes, int sizeArray, int * ClienteId)
{
    int retorno = -1;
    int aux;
    int mostrar;
    aux = *ClienteId;

    printf("A quien desea dar de baja?\n");
    mostrar = clte_mostrar(arrayDeClientes, sizeArray);
    scanf("%d", &aux);
    if(sizeArray > 0 && arrayDeClientes != NULL)
    {
        if(aux > sizeArray)
            {
                printf("Ese numero supera la dimmension de la lista. Intente de nuevo.\n");
                printf("A quien desea dar de baja?\n");
                scanf("%d", &aux);
            }
        while(arrayDeClientes[aux].isEmpty == 1)
            {
                printf("Ese Cliente ya esta vacio. Intente de nuevo.\n");
                printf("A quien desea dar de baja?\n");
                scanf("%d", &aux);
            }
        if(aux < sizeArray && arrayDeClientes[aux].isEmpty == 0)
            {
                arrayDeClientes[aux].isEmpty = 1;
                printf("Se dio de baja a %s %s, con el ID %d.\n", arrayDeClientes[aux].nombre,
                       arrayDeClientes[aux].apellido, arrayDeClientes[aux].idCliente);
                       retorno = 0;
            }
    }
        return retorno;
}

int clte_modificar(Cliente * arrayDeClientes, int sizeArray)
{
    int retorno = -1;
    int aux;
    char respuesta = 's';
    int menu;
    int mostrar;
    int i;
    if(sizeArray > 0 && arrayDeClientes != NULL)
    {
        for(i = 0; i < sizeArray-1; i++)
        {
            if(arrayDeClientes[i].isEmpty == 0)
            {
                mostrar = clte_mostrar(arrayDeClientes, sizeArray);
            }
        }
        printf("Ingrese el ID del Cliente a modificar.\n");
        scanf("%d", &aux);
        while(aux > sizeArray || arrayDeClientes[aux].isEmpty == 1)
        {
            printf("Ingrese un ID valido.\n");
            scanf("%d", &aux);
        }

        do
        {
            printf("Que desea modificar?\n");
            printf("Nombre      -> Ingrese 1\n");
            printf("Apellido    -> Ingrese 2\n");
            printf("CUIT        -> Ingrese 3\n");
            scanf("%d", &menu);
            switch(menu)
            {
                case 1:
                    printf("Ingrese el nuevo nombre.\n");
                    fflush(stdin);
                    gets(arrayDeClientes[aux].nombre);
                    printf("Desea continuar modificando? S/N\n");
                    scanf("%c", &respuesta);
                    break;
                case 2:
                    printf("Ingrese el nuevo apellido.\n");
                    fflush(stdin);
                    gets(arrayDeClientes[aux].apellido);
                    printf("Desea continuar modificando? S/N\n");
                    scanf("%c", &respuesta);
                    break;
                case 3:
                    printf("Ingrese el nuevo CUIT.\n");
                    fflush(stdin);
                    gets(arrayDeClientes[aux].cuit);
                    printf("Desea continuar modificando? S/N\n");
                    scanf("%c", &respuesta);
                default:
                    printf("Ingrese una opcion valida.\n");
                    break;
            }
        }while(respuesta == 's');

    }

    return retorno;
}
