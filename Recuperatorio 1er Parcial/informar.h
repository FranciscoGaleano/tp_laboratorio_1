#include "aviso.h"
#ifndef INFORMAR_H_INCLUDED
#define INFORMAR_H_INCLUDED



#endif // INFORMAR_H_INCLUDED

int informar_listarClientes(Cliente * arrayDeClientes, int limiteC, Aviso * arrayDeAvisos, int limeteA);

int informar_avisosActivos(Cliente * arrayDeClientes, int limiteC, Aviso * arrayDeAvisos, int limiteA);

int informar_cantidadAvisosPorCliente(Cliente * arrayDeClientes, int limiteC, Aviso * arrayDeAvisos, int limiteA);

int informar_clienteConMasAvisos(Cliente * arrayDeClientes, int limiteC, Aviso * arrayDeAvisos, int limiteA);

int informar_clienteConMasAvisosActivos(Cliente* arrayDeClientes,int limiteC, Aviso* arrayDeAvisos, int limiteA);

int informar_clienteConMasAvisosPausados(Cliente* arrayDeClientes, int limiteC, Aviso* arrayDeAvisos, int limiteA);

int informar_seleccionDeInformeDeClientes(Cliente * arrayDeClientes, int limiteC, Aviso * arrayDeAvisos, int limiteA);

int informar_cantidadAvisosPorRubro(Aviso* arrayDeAvisos, int limiteA);

int informar_rubroConMasAvisosActivos(Aviso* arrayDeAvisos, int limiteA, int limiteRubro);

int informar_rubroConMenosAvisosActivos(Aviso * arrayDeAvisos, int limiteA, int limiteRubro);

int informar_seleccionDeInformeDeRubros(Aviso * arrayDeAvisos, int limiteA);
