#include "clientes.h"
#include "avisos.h"
#include <stdio.h>
#include <stdlib.h>

int infomar_imprimirClientes(Cliente * arrayDeClientes, int limiteC, Aviso * arrayDeAvisos, int limiteA)
{
    int retorno = -1;
    int i;
    int contadorPublicacion = 0;

    if(limiteA > 0 && arrayDeAvisos != NULL)
    {
        for(i = 0; i < limiteA; i++)
        {
            if(arrayDeAvisos[i].isEmpty == 0)
            {
                if(arrayDeClientes[i].idCliente == arrayDeClientes[i+1].idCliente)
                {
                    contadorPublicacion++;
                }
                printf("NOMBRE: %s - APELLIDO: %s - CUIT: %s - AVISOS: %d\n", arrayDeClientes[i].nombre,
                       arrayDeClientes[i].apellido, arrayDeClientes[i].cuit, contadorPublicacion);
            }
        }
        retorno = 0;
    }
    return retorno;
}

int informar_imprimirAvisos(Aviso * arrayDeAvisos, int limiteA, Cliente * arrayDeClientes, int limiteC)
{
    int retorno = -1;
    int i;

    if(limiteA > 0 && arrayDeAvisos != NULL)
    {
        for(i = 0; i < limiteA; i++)
        {
            if(arrayDeAvisos[i].isEmpty == 0)
            {
                if(arrayDeAvisos[i].estado == 1)
                {
                    printf("RUBRO: %d - TEXTO: %s - CUIT CLIENTE: %s\n", arrayDeAvisos[i].rubro,
                    arrayDeAvisos[i].texto, arrayDeClientes[i].cuit);
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}

int informar_datosDeClientes(Cliente * arrayDeClientes, int limiteC, Aviso * arrayDeAvisos, int limiteA)
{
    int retorno = -1;
    int i;
    int menu;
    int contadorPublicacion = 0;
    if(limiteA > 0 && arrayDeAvisos != NULL)
    {
        for(i = 0; i < limiteC; i++)
        {
            if(arrayDeAvisos[i].isEmpty == 0)
            {
                contadorPublicacion++;
            }
        }
    }





    return retorno;
}
