#include "cliente.h"
#ifndef AVISO_H_INCLUDED
#define AVISO_H_INCLUDED
typedef struct
    {
        int rubro;
        char texto[64];
        int idAviso;
        int isEmpty;
        int estado; //1 para activo, 0 para pausado//
        int idCliente;
    }Aviso;
#endif // AVISO_H_INCLUDED
int avi_crear(Aviso * arrayDeAvisos, int sizeArray);
int avi_alta(Aviso * arrayDeAvisos, int sizeArray, Cliente * arrayDeClientes, int sizeCliente);
int avi_mostrarActivos(Aviso * arrayDeAvisos, int sizeArray);
int avi_mostrarPausados(Aviso * arrayDeAvisos, int sizeArray);
int avi_baja(Aviso * arrayDeAvisos, int sizeArray, int * AvisoId);
int avi_modificar(Aviso * arrayDeAvisos, int sizeArray);
int avi_pausarPublicacion(Aviso * arrayDeAvisos, int sizeArray, Cliente * arrayDeClientes, int sizeCliente);
int avi_reanudarPublicacion(Aviso * arrayDeAvisos, int sizeArray, Cliente * arrayDeClientes, int sizeCliente);
int avi_buscarAvisosPorId(Aviso * arrayDeAvisos , int sizeArray, int * idCliente);
int avi_contarActivosPorId(Aviso * arrayDeAvisos, int limiteA, int idCliente);
int avi_buscarAvisosPorRubro(Aviso * arrayDeAvisos , int sizeArray, int rubro);
