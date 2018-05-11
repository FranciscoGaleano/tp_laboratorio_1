#ifndef INFORMAR_H_INCLUDED
#define INFORMAR_H_INCLUDED
#include "clientes.h"
#include "avisos.h"

int infomar_imprimirClientes(Cliente * arrayDeClientes, int limiteC, Aviso * arrayDeAvisos, int limiteA);

int informar_imprimirAvisos(Aviso * arrayDeAvisos, int limiteA, Cliente * arrayDeClientes, int limiteC);

int informar_datosDeClientes(Cliente * arrayDeClientes, int limiteC, Aviso * arrayDeAvisos, int limiteA);

#endif // INFORMAR_H_INCLUDED


