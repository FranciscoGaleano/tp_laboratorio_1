#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"

/** \brief Declara el campo "estado" de la estructura Persona como 1, para indicar que esta vacío y se puede usar
 *
 * \param arrayDePersonas Persona* Array de estructura Persona donde se van a ingresar datos
 * \param sizeArray int Tamaño límite del array
 * \return int Devuelve -1 si hubo un error, 0 si funcionó de manera correcta
 *
 */
int per_crear(Persona * arrayDePersonas, int sizeArray)
{
    int retorno = -1;
    int i = 0;
    for(i = 0; i < sizeArray; i++)
    {
        arrayDePersonas[i].estado = 1;
        retorno = 0;
    }
    return retorno;
}

/** \brief Recorre un array de estructura Persona y nos dice si hay lugares libres donde cargar datos
 *
 * \param arrayDePersonas Persona* Array de estructura Persona que va a ser recorrido
 * \param sizeArray int Tamaño límite del array
 * \return int Devuelve -1 si hubo un error, 0 si funcionó de manera correcta
 *
 */
int per_buscarLibre(Persona * arrayDePersonas, int sizeArray)
{
    int retorno = -1;
    int i;
    for(i = 0; i < sizeArray; i++)
    {
        if(arrayDePersonas[i].estado == 1)
        {
            printf("La posicion %d esta libre para usarse.\n", i);
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief De encontrarse un lugar vacio en un array de estructura Persona, ingresamos los datos necesarios
 *
 * \param arrayDePersonas Persona* Array de estructura Persona donde se van a ingresar datos
 * \param sizeArray int Tamaño límite del array
 * \return int Devuelve -1 si hubo un error, 0 si funcionó de manera correcta
 *
 */
int per_alta(Persona * arrayDePersonas, int sizeArray)
{
    int retorno = -1;
    int i;
    for(i = 0; i < sizeArray; i++)
    {
        if(arrayDePersonas[i].estado == 1)
        {
            printf("Ingrese el nombre de la persona.\n");
            fflush(stdin);
            gets(arrayDePersonas[i].nombre);
            printf("Ingrese la edad de la persona.\n");
            fflush(stdin);
            scanf("%d", &arrayDePersonas[i].edad);
            printf("Ingrese el DNI de la persona.\n");
            fflush(stdin);
            scanf("%d", &arrayDePersonas[i].dni);
            arrayDePersonas[i].estado = 0;
            retorno = 0;
            break;
        }
        else{
            while(arrayDePersonas[i].estado == 0)
            {
                break;
            }
        }
    }
    return retorno;
}

/** \brief De encontrarse un lugar ocupado en un array de estructura Persona, nos muestra los datos que fueron ingresados
 *
 * \param arrayDePersonas Persona* Array de estructura Persona que va a ser recorrido
 * \param sizeArray int Tamaño límite del array
 * \return int Devuelve -1 si hubo un error, 0 si funcionó de manera correcta
 *
 */
int per_mostrar(Persona * arrayDePersonas,int sizeArray)
{
    int retorno = -1;
    int i;
    for(i = 0; i < sizeArray; i++)
    {
        if(arrayDePersonas[i].estado == 0)
        {
             printf("Nombre: %s Edad: %d DNI: %d Ubicacion: %d\n", arrayDePersonas[i].nombre, arrayDePersonas[i].edad, arrayDePersonas[i].dni, i);
             retorno = 0;
        }
        else
        {
            printf("Esta ubicacion [%d] se encuentra vacia.\n", i);
        }
    }
    return retorno;
}

/** \brief Modifica el valor del campo "estado" en la estructura Persona de 0 a 1, de ocupado a libre
 *
 * \param arrayDePersonas Persona* Array de estructura Persona donde vamos a modificar datos
 * \param sizeArray int Tamaño límite del array
 * \param personaIndice int* Puntero que nos indica el indice del array donde vamos a modificar datos
 * \return int Devuelve -1 si hubo un error, 0 si funcionó de manera correcta
 *
 */
int per_baja(Persona * arrayDePersonas, int sizeArray, int * personaIndice)
{
    int retorno = -1;
    int aux;
    aux = *personaIndice;

    if(arrayDePersonas != NULL && sizeArray > 0)
    {
        printf("A quien desea dar de baja? Ingrese el numero de la ubicacion de la persona que desea eliminar.\n");
        scanf("%d", &aux);
        while(aux > sizeArray)
        {
            printf("El numero supera el limite de la lista. Intente de nuevo.\n");
            printf("A quien desea dar de baja? Ingrese el numero de la ubicacion de la persona que desea eliminar.\n");
            scanf("%d", &aux);
        }
        while(arrayDePersonas[aux].estado == 1)
            {
                printf("Ese usuario ya esta vacio. Intente de nuevo.\n");
                printf("A quien desea dar de baja?\n");
                scanf("%d", &aux);
            }
        if(arrayDePersonas[aux].estado == 0)
        {
            arrayDePersonas[aux].estado = 1;
            printf("Nombre: %s Edad: %d DNI: %d HA SIDO DADO DE BAJA--\n", arrayDePersonas[aux].nombre, arrayDePersonas[aux].edad, arrayDePersonas[aux].dni);
            retorno = 0;
        }
    }
    if(arrayDePersonas == NULL)
    {
        printf("No hay una lista creada aún. Inicialice una y luego podra dar bajas.\n");
    }

    return retorno;
}

/** \brief Recorre un array de estructura Persona y lo re-ordena en base a el campo "nombre"
 *
 * \param arrayDePersonas Persona* Array de estructura Persona que va a ser recorrido
 * \param sizeArray int Tamaño límite del array
 * \return int Devuelve -1 si hubo un error, 0 si funcionó de manera correcta
 *
 */
int per_ordenarAlfabeticamente(Persona * arrayDePersonas, int sizeArray)
{
    int retorno = -1;
    int i;
    int j;
    int flag;
    Persona auxiliar;


    if(arrayDePersonas != NULL && sizeArray > 0)
    {
        do
        {
            flag = 0;
            for(i = 0; i < sizeArray; i++)
            {
                j = i + 1;
                if(arrayDePersonas[i].estado == 0 && arrayDePersonas[j].estado == 0)
                    {
                        if(j > 0 && (strcmp(arrayDePersonas[i].nombre, arrayDePersonas[j].nombre) > 0))
                        {
                            auxiliar = arrayDePersonas[i];
                            arrayDePersonas[i] = arrayDePersonas[j];
                            arrayDePersonas[j] = auxiliar;
                            flag = 1;
                        }
                    }
            }
        }while(flag == 1);
        retorno = 0;
	}
    return retorno;
}

/** \brief Realiza un grafico en base al campo "edad" de la estructura Persona
 *
 * \param arrayDePersonas Persona* Array de estructura Persona que va a ser recorrido
 * \param sizeArray int Tamaño límite del array
 * \return int Devuelve -1 si hubo un error, 0 si funcionó de manera correcta
 *
 */
int per_graficarEdades(Persona * arrayDePersonas, int sizeArray)
{
    int retorno = -1;
    int i;
    int flag = -1;
    int mayoresContador = 0;
    int mediosContador = 0;
    int menoresContador = 0;

    if(arrayDePersonas != NULL && sizeArray > 0)
    {
        retorno = -2;
        for(i=0; i < sizeArray-1; i++)
        {
            if(arrayDePersonas[i].estado == 0)
            {
                if(arrayDePersonas[i].edad < 19)
                {
                    menoresContador++;
                }
                else if((arrayDePersonas[i].edad > 18) && (arrayDePersonas[i].edad < 36))
                {
                    mediosContador++;
                }
                else if(arrayDePersonas[i].edad > 35)
                {
                    mayoresContador++;
                }
            }
        }
    }
    while(flag == -1)
    {
        if(menoresContador > mediosContador && menoresContador > mayoresContador)
        {
            printf(" *\n");
            menoresContador--;
        }
        else if(menoresContador < mediosContador && mediosContador > mayoresContador)
        {
            printf("      *\n");
            mediosContador--;
        }
        else if(menoresContador < mayoresContador && mediosContador < mayoresContador)
        {
            printf("           *\n");
            mayoresContador--;
        }
        else if(menoresContador == 0 && mediosContador == 0 && mayoresContador == 0)
        {
            printf("<18 19-35 <35\n");
            flag = 0;
        }
        else if(menoresContador == mediosContador && mediosContador > mayoresContador)
        {
            printf(" *    *\n");
            menoresContador--;
            mediosContador--;
        }
        else if(menoresContador == mayoresContador &&  mayoresContador > mediosContador)
        {
            printf(" *         *\n");
            menoresContador--;
            mayoresContador--;
        }
        else if(mediosContador == mayoresContador &&  mediosContador > menoresContador)
        {
            printf("      *    *\n");
            mediosContador--;
            mayoresContador--;
        }
        else if(menoresContador == mediosContador && mediosContador == mayoresContador)
        {
            printf(" *    *    *\n");
            menoresContador--;
            mediosContador--;
            mayoresContador--;
        }
    }
    return retorno;
}
