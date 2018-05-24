#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "aviso.h"

/** \brief Crea un array de Avisos, establece el campo "isEmpty" en 0
 *
 * \param arrayDeAvisos Aviso* Puntero al array de Avisos donde vamos a trabajar
 * \param sizeArray int Dimension del array
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no funciona
 *
 */
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

/** \brief Nos muestra una lista de los avisos cuyo campo "isEmpty" es 0 y "estado" es 1
 *
 * \param arrayDeAvisos Aviso* Puntero al array de Avisos donde vamos a trabajar
 * \param sizeArray int Dimension del array
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no funciona
 *
 */
int avi_mostrarActivos(Aviso * arrayDeAvisos, int sizeArray)
{
    int retorno = -1;
    int i;
    if(sizeArray > 0 && arrayDeAvisos != NULL)
    {
        for(i = 0; i < sizeArray; i++)
        {
            if(arrayDeAvisos[i].isEmpty == 0 && arrayDeAvisos[i].estado == 1)
            {
                printf("TEXTO: %s - RUBRO: %d -  ID: %d\n", arrayDeAvisos[i].texto,
                        arrayDeAvisos[i].rubro, i);
                        retorno = 0;
            }
        }
    }
    return retorno;
}

/** \brief Nos muestra una lista de avisos cuyo campo "isEmpty" es 0 y "estado" es 0
 *
 * \param arrayDeAvisos Aviso* Puntero al array de Avisos donde vamos a trabajar
 * \param sizeArray int Dimension del array
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no funciona
 *
 */
int avi_mostrarPausados(Aviso * arrayDeAvisos, int sizeArray)
{
    int retorno = -1;
    int i;
    if(sizeArray > 0 && arrayDeAvisos != NULL)
    {
        for(i = 0; i < sizeArray; i++)
        {
            if(arrayDeAvisos[i].isEmpty == 0 && arrayDeAvisos[i].estado == 0)
            {
                 printf("TEXTO: %s - RUBRO: %d -  ID: %d\n", arrayDeAvisos[i].texto,
                        arrayDeAvisos[i].rubro, i);
                        retorno = 0;
            }
        }
    }
    return retorno;
}

/** \brief Da de baja un aviso, establece el campo "isEmpty" a 1
 *
 * \param arrayDeAvisos Aviso* Puntero al array de Avisos donde vamos a trabajar
 * \param sizeArray int Dimension del array
 * \param AvisoId int* Puntero a la variable de la ID del aviso con cual trabajar
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no funciona
 *
 */
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

/** \brief Da de alta un aviso, establece el campo "isEmpty" a 0 y "estado" a 1
 *
 * \param arrayDeAvisos Aviso* Puntero al array de avisos donde vamos a trabajar
 * \param sizeArray int Dimension del array de Avisos
 * \param arrayDeClientes Cliente* Puntero al array de Clientes con el que vamos a trabajar
 * \param sizeCliente int Dimension del array de Clientes
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no funciona
 *
 */
int avi_alta(Aviso * arrayDeAvisos, int sizeArray, Cliente * arrayDeClientes, int sizeCliente)
{
    int retorno = -1;
    int mostrar;
    int i;
    int id;
    int aux;
    int indice;

    if(sizeArray > 0 && arrayDeAvisos != NULL && sizeCliente > 0 && arrayDeClientes != NULL)
    {
        mostrar = clte_mostrar(arrayDeClientes, sizeCliente);
        printf("Ingrese el ID del cliente.\n");
        scanf("%d", &id);
        indice = clte_obtenerID(arrayDeClientes, sizeCliente, id);
        if(arrayDeClientes[indice].idCliente == indice)
        {
            for(i = 0; i < sizeArray; i++)
            {
                if(arrayDeAvisos[i].isEmpty == 1)
                {
                    do
                    {
                        printf("Ingrese el rubro del aviso. [1/2/3/4]\n");
                        scanf("%d", &aux);
                    }while(aux != 1 && aux != 2 && aux != 3 && aux != 4);
                    printf("Ingrese el texto del aviso.\n");
                    fflush(stdin);
                    gets(arrayDeAvisos[i].texto);
                    arrayDeAvisos[i].isEmpty = 0;
                    arrayDeAvisos[i].estado = 1;
                    arrayDeAvisos[i].rubro = aux;
                    arrayDeAvisos[i].idAviso = i;
                    arrayDeAvisos[i].idCliente = indice;
                    retorno = 0;
                    break;
                }
                else
                {
                    continue;
                }
            }
        }
        else
        {
            printf("Ese ID no pertenece a un cliente existente.\n");
        }
    }
    return retorno;
}

/** \brief Establece el campo "estado" de un aviso en 0
 *
 * \param arrayDeAvisos Aviso* Puntero al array de Avisos con el que vamos a trabajar
 * \param sizeArray int Dimension del array de Avisos
 * \param arrayDeClientes Cliente* Putero al array de Clientes con el que vamos a trabajar
 * \param sizeCliente int Dimension del array de Clientes
 * \return int Devuelve 0 si funcina de manera correcta, -1 si no funciona
 *
 */
int avi_pausarPublicacion(Aviso * arrayDeAvisos, int sizeArray, Cliente * arrayDeClientes, int sizeCliente)
{
    int retorno = -1;
    int aux;
    int flag = 1;
    char respuesta;
    int mostrar;

    if(sizeArray > 0 && arrayDeAvisos != NULL && sizeCliente > 0 && arrayDeClientes != NULL)
    {
        mostrar = avi_mostrarActivos(arrayDeAvisos, sizeArray);
        if(flag == 1)
        {
            printf("Ingrese el ID del aviso a pausar.\n");
            scanf("%d", &aux);
            if(arrayDeAvisos[aux].estado == 1)
            {
                printf("Datos del propietario del aviso:\n");
                printf("NOMBRE: %s - APELLIDO: %s - CUIT: %s\n", arrayDeClientes[aux].nombre,
                       arrayDeClientes[aux].apellido, arrayDeClientes[aux].cuit);
                printf("Desea pausar este aviso? S/N\n");
                fflush(stdin);
                scanf("%c", &respuesta);
                if(respuesta == 's')
                {
                    arrayDeAvisos[aux].estado = 0;
                    printf("El aviso elegido fue pausado.\n");
                    flag = 0;
                }
                else
                {
                    printf("El aviso no fue pausado.\n");
                    flag = -1;
                }
            }
            else
            {
                printf("No existen avisos publicados para pausar con ese ID.\n");
                flag = -2;
            }
        }
        retorno = 0;
    }
    return retorno;
}

/** \brief Establece el campo "estado" de un aviso de nuevo en 1
 *
 * \param arrayDeAvisos Aviso* Puntero al array de Avisos con el que vamos a trabajar
 * \param sizeArray int Dimension del array de Avisos
 * \param arrayDeClientes Cliente* Putero al array de Clientes con el que vamos a trabajar
 * \param sizeCliente int Dimension del array de Clientes
 * \return int Devuelve 0 si funcina de manera correcta, -1 si no funciona
 *
 */
int avi_reanudarPublicacion(Aviso * arrayDeAvisos, int sizeArray, Cliente * arrayDeClientes, int sizeCliente)
{
    int retorno = -1;
    int aux;
    int i;
    int mostrarPausados;
    int flag = 1;
    char respuesta = 's';

    if(sizeArray > 0 && arrayDeAvisos != NULL && sizeCliente > 0 && arrayDeClientes != NULL)
    {
        printf("Los avisos pausados son los siguientes:\n");
        mostrarPausados = avi_mostrarPausados(arrayDeAvisos, sizeArray);
        if(flag == 1)
        {
            printf("Ingrese el ID del aviso a reanudar.\n");
            scanf("%d", &aux);
            if(arrayDeAvisos[aux].estado == 0)
            {
                printf("Datos del propietario del aviso:\n");
                printf("NOMBRE: %s - APELLIDO: %s - CUIT: %s\n", arrayDeClientes[aux].nombre,
                       arrayDeClientes[aux].apellido, arrayDeClientes[aux].cuit);
                printf("Desea reanudar este aviso? S/N\n");
                fflush(stdin);
                scanf("%c", &respuesta);
                if(respuesta == 's')
                {
                    arrayDeAvisos[aux].estado = 1;
                    printf("El aviso elegido fue reanudado.\n");
                    retorno = 0;
                    flag = 0;
                }
                else
                {
                    printf("El aviso no fue reanudado.\n");
                    flag = 0;
                }
            }
            else
            {
                printf("No existen avisos pausados con ese ID para reanudar.\n");
            }
        }
    }
    return retorno;
}

/** \brief Busca cuantos avisos totales comparten la misma ID de Cliente
 *
 * \param arrayDeAvisos Aviso* Puntero al array de Avisos con el que vamos a trabajar
 * \param sizeArray int Dimension del array
 * \param idCliente int Variable de la ID del Cliente
 * \return int Devuelve el numero de avisos que tiene esa ID
 *
 */
int avi_buscarAvisosPorId(Aviso * arrayDeAvisos , int sizeArray, int * idCliente)
{
    int i;
    int contadorPublicaciones = 0;
    if(sizeArray > 0 && arrayDeAvisos != NULL)
    {
        for(i = 0; i < sizeArray; i++)
        {
            if(arrayDeAvisos[i].isEmpty == 0 && arrayDeAvisos[i].idCliente == * idCliente)
            {
               contadorPublicaciones++;
            }
            else if(arrayDeAvisos[i].isEmpty == 0 && arrayDeAvisos[i].idCliente != * idCliente)
            {
                continue;
            }
        }
    }
    return contadorPublicaciones;
}


/** \brief Busca cuantos avisos donde el campo "estado" es 1 comparten el mismo ID de Cliente
 *
 * \param arrayDeAvisos Aviso* Puntero al array de Avisos con el que vamos a trabajar
 * \param limiteA int Dimension del array
 * \param idCliente int Variable donde se encuentra el ID de Cliente
 * \return int Devuelve el numero de avisos activos que tiene ese ID
 *
 */
int avi_contarActivosPorId(Aviso * arrayDeAvisos, int limiteA, int idCliente)
{
    int i;
    int contadorActivos = 0;
    if(limiteA > 0 && arrayDeAvisos != NULL)
    {
        for(i = 0; i < limiteA; i++)
        {
            if(arrayDeAvisos[i].isEmpty == 0 && arrayDeAvisos[i].estado == 1 && arrayDeAvisos[i].idCliente == idCliente)
            {
               contadorActivos++;
            }
            else if(arrayDeAvisos[i].isEmpty == 0 && arrayDeAvisos[i].estado == 1 && arrayDeAvisos[i].idCliente != idCliente)
            {
                continue;
            }
        }
    }
    return contadorActivos;
}

/** \brief Busca cuantos avisos comparten el mismo valor en el campo "rubro"
 *
 * \param arrayDeAvisos Aviso* Puntero al array de Avisos con el que vamos a trabajar
 * \param limiteA int Dimension del array
 * \param rubro int Variable donde se encuentra el valor del campo "rubro" con el que vamos a trabajar
 * \return int Devuelve el numero de avisos que comparten el mismo rubro
 *
 */
int avi_buscarAvisosPorRubro(Aviso * arrayDeAvisos , int sizeArray, int rubro)
{
    int i;
    int contadorPublicaciones = 0;
    if(sizeArray > 0 && arrayDeAvisos != NULL)
    {
        for(i = 0; i < sizeArray; i++)
        {
            if(arrayDeAvisos[i].isEmpty == 0 && arrayDeAvisos[i].estado == 1 && arrayDeAvisos[i].rubro == rubro)
            {
               contadorPublicaciones++;
            }
            else if(arrayDeAvisos[i].isEmpty == 0 && arrayDeAvisos[i].estado == 1 && arrayDeAvisos[i].rubro != rubro)
            {
                continue;
            }
        }
    }
    return contadorPublicaciones;
}
