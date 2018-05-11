#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct
    {
        char nombre[50];
        char apellido[50];
        char cuit[40];
        int idCliente;
        int isEmpty;
    }Cliente;
#endif // CLIENTES_H_INCLUDED

/** \brief Crea un array donde vamos a guardar la informacion de los clientes
 *
 * \param arrayDeClientes Cliente* le pasamos por puntero el array
 * \param sizeArray int le pasamos el tamaño del array
 * \return int devuelve 0 si esta bien, -1 si hay error
 *
 */
int clte_crear(Cliente * arrayDeClientes, int sizeArray);

int clte_alta(Cliente * arrayDeClientes, int sizeArray);
int clte_mostrar(Cliente * arrayDeClientes,int sizeArray);
int clte_baja(Cliente * arrayDeClientes, int sizeArray, int * ClienteId);
int clte_modificar(Cliente * arrayDeClientes, int sizeArray);
