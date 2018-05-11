#ifndef AVISOS_H_INCLUDED
#define AVISOS_H_INCLUDED
typedef struct
{
    int rubro;
    char texto[64];
    int idAviso;
    int isEmpty;
    int estado; //1 para activo, 0 para pausado//
    //-------------//
    int idCliente;
}Aviso;


#endif // AVISOS_H_INCLUDED

int avi_crear(Aviso * arrayDeAvisos, int sizeArray);
//int avi_alta(Aviso * arrayDeAvisos, int sizeArray, Cliente* arrayDeClientes, int sizeCliente);
int avi_mostrar(Aviso * arrayDeAvisos,int sizeArray);
int avi_baja(Aviso * arrayDeAvisos, int sizeArray, int * AvisoId);
int avi_modificar(Aviso * arrayDeAvisos, int sizeArray);
