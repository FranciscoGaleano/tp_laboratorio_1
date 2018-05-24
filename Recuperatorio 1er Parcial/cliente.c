#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "aviso.h"

/** \brief Crea un array de clientes, establece el campo "isEmpty" igual en "0"
 *
 * \param arrayDeClientes Cliente* Puntero al array de clientes donde vamos a trabajar
 * \param sizeArray int Dimension del array
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no funciona
 *
 */
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

/** \brief Crea un cliente, nos permite ingresas sus datos
 *
 * \param arrayDeClientes Cliente* Puntero al array con el que vamos a trabajar
 * \param sizeArray int Dimension del array
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no funciona
 *
 */
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
        printf("Se dio de alta a %s %s.\n", arrayDeClientes[i].nombre, arrayDeClientes[i].apellido);
    }
    return retorno;
}

/** \brief Da de baja un cliente, establece el campo "isEmpty" en "1"
 *
 * \param arrayDeClientes Cliente* Puntero al array con el que vamos a trabajar
 * \param sizeArray int Dimension del array
 * \param ClienteId int* Puntero a la variable del ID del cliente que daremos de baja
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no funciona
 *
 */
int clte_baja(Cliente * arrayDeClientes, int sizeArray, int * ClienteId)
{
    int retorno = -1;
    int aux;
    int mostrar;
    int aviso;
    aux = *ClienteId;

    printf("A quien desea dar de baja? Ingrese el ID que observa en la siguiente lista de clientes.\n");
    mostrar = clte_mostrar(arrayDeClientes, sizeArray);
    printf("Ingrese el ID.\n");
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

/** \brief Nos muestra una lista de los clientes cuyo campo "isEmpty" es 0
 *
 * \param arrayDeClientes Cliente* Puntero al array de clientes donde vamos a trabajar
 * \param sizeArray int Dimension del array
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no funciona
 *
 */
int clte_mostrar(Cliente * arrayDeClientes, int sizeArray)
{
    int retorno = -1;
    int i;
    if(sizeArray > 0 && arrayDeClientes != NULL)
    {
        for(i = 0; i < sizeArray; i++)
        {
            if(arrayDeClientes[i].isEmpty == 0)
            {
                printf("Se puede trabajar con el cliente %s %s, con ID %d\n", arrayDeClientes[i].nombre,
                        arrayDeClientes[i].apellido, arrayDeClientes[i].idCliente);
            }
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Nos permite modificar alguno de los campos de la estructura Cliente
 *
 * \param arrayDeClientes Cliente* Puntero al array de clientes donde vamos a trabajar
 * \param sizeArray int Dimension del array
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no funciona
 *
 */
int clte_modificar(Cliente * arrayDeClientes, int sizeArray)
{
    int retorno = -1;
    int aux;
    char respuesta = 's';
    int menu;
    int mostrar;
    if(sizeArray > 0 && arrayDeClientes != NULL)
    {
        mostrar = clte_mostrar(arrayDeClientes, sizeArray);
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
                    break;
                default:
                    printf("Ingrese una opcion valida.\n");
                    break;
            }
        }while(respuesta == 's');
    }
    return retorno;
}


/** \brief Nos permite leer el ID de un cliente para trabajar con ella
 *
 * \param arrayDeClientes Cliente* Puntero al array de Clientes donde vamos a trabajar
 * \param sizeArray int Dimension del array
 * \param idCliente int Variable de la ID del Cliente con la que vamos a trabajar
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no funciona
 *
 */
int clte_obtenerID(Cliente * arrayDeClientes, int sizeArray, int idCliente)
{
    int i;
    int auxiliar;
    if(sizeArray > 0 && arrayDeClientes != NULL)
    {
        for(i = 0; i < sizeArray; i++)
        {
            if(arrayDeClientes[i].isEmpty == 0 && arrayDeClientes[i].idCliente == idCliente)
            {
                auxiliar = idCliente;
            }
        }
    }
    return auxiliar;
}
