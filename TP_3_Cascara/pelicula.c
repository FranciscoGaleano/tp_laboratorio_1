#include "pelicula.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

static int pelicula_setId(Pelicula *this, int id);

/** \brief Guarda espacio de memoria para la estructura Pelicula
 *
 * \return Pelicula* Un espacio de memoria para la estructura Pelicula
 *
 */
Pelicula* pelicula_new()
{
    return (Pelicula*) malloc(sizeof(Pelicula));
}

/** \brief Elimina el espacio de memoria que se habia guardado para la estructura Pelicula
 *
 * \param this Pelicula* array de Peliculas con el que trabajamos
 * \return void
 *
 */
void pelicula_delete(Pelicula* this)
{
    free(this);
}

/** \brief Establece los campos de la estructura Pelicula a un elemento de esa estructura que fue creado
 *
 * \param titulo char* Valor que se asignara al campo Titulo
 * \param genero char* Valor que se asignara al campo Genero
 * \param duracion int Valor que se asignara al campo Duracion
 * \param descripcion char* Valor que se asignara al campo Descripcion
 * \param puntaje int Valor que se asignara al campo Puntaje
 * \param link char* Valor que se asignara al campo Link
 * \return Pelicula* Elemento de la estructura Pelicula con los campos establecidos
 *
 */
Pelicula* pelicula_newAlta(char* titulo, char* genero,int duracion,char* descripcion,int puntaje,char* link)
{
    Pelicula *auxArray = pelicula_new();
    pelicula_setTitulo(auxArray, titulo);
    pelicula_setDescripcion(auxArray, descripcion);
    pelicula_setDuracion(auxArray, duracion);
    pelicula_setGenero(auxArray, genero);
    pelicula_setLink(auxArray, link);
    pelicula_setId(auxArray, -1);
    pelicula_setPuntaje(auxArray, puntaje);
    return auxArray;
}

/** \brief Da de alta un elemento perteneciente a la estructura Pelicula
 *
 * \param arrayPelicula Pelicula** Puntero al array de punteros de estructura Pelicula con el que vamos a trabajar
 * \param sizeArray int* dimension del array
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no lo hace
 *
 */
int pelicula_alta(Pelicula **arrayPelicula, int *sizeArray)
{
    int retorno = -1;
    char auxTitulo[100];
    char auxGenero[50];
    int auxDuracion;
    char auxDescripcion[200];
    int auxPuntaje;
    char auxLink[500];
    if(arrayPelicula != NULL && *sizeArray > -1)
    {
        if(getString("Ingrese el titulo de la pelicula\n", auxTitulo))
        {
            if(getString("Ingrese el genero de la pelicula\n", auxGenero))
            {
                if(getString("Ingrese la descripcion de la pelicula\n", auxDescripcion))
                {
                    if(!getValidInt("Ingrese la duracion de la pelicula\n", "Error. Intente de nuevo\n", &auxDuracion, 30, 250, 2))
                    {
                        if(!getValidUrl("Ingrese el link de la imagen de la pelicula\n", "Error. El link no es de tipo valido. Intente de nuevo\n", "Excede la dimension. Intente de nuevo\n", auxLink, 500, 2))
                        {
                            if(!getValidInt("Ingrese un puntaje para la pelicula[entre 1 y 10]\n", "Error. Intente de nuevo\n", &auxPuntaje, 1, 10, 2))
                            {
                                arrayPelicula[*sizeArray] = pelicula_newAlta(auxTitulo, auxGenero, auxDuracion, auxDescripcion, auxPuntaje, auxLink);
                                *sizeArray = *sizeArray + 1;
                                retorno = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("Se acaba de dar de alta la pelicula: %s\n", auxTitulo);
    return retorno;
}

/** \brief Da de baja un element perteneciente a la estructura Pelicula
 *
 * \param arrayPelicula Pelicula** Puntero al array de punteros de la estructura Pelicula con el que vamos a trabajar
 * \param sizeArray int* dimension del array
 * \param id int ID de la pelicula que se quiere dar de baja
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no lo hace
 *
 */
int pelicula_baja(Pelicula **arrayPelicula, int *sizeArray, int id)
{
    int retorno = -1;
    int i;
    int j;
    int auxId;
    if(arrayPelicula != NULL && *sizeArray > 0)
    {
        if(id >= 0)
        {
            for(i = 0; i < *sizeArray; i++)
            {
                pelicula_getId(arrayPelicula[i], &auxId);
                if(auxId == id)
                {
                    retorno = 0;
                    printf("Se acaba de dar de baja la pelicula: %s\n", arrayPelicula[id]->titulo);
                    break;
                }
            }
            if(retorno == 0)
            {
                if(i < *sizeArray)
                {
                    for(j = i; i < *sizeArray; i++)
                    {
                        arrayPelicula[i] = arrayPelicula[i+1];
                    }
                }
                pelicula_delete(arrayPelicula[*sizeArray]);
                *sizeArray = *sizeArray - 1;
            }
        }
    }

    return retorno;
}

/** \brief Nos permite modificar los campos de un elemento de la estructura Pelicula
 *
 * \param arrayPeliculas Pelicula** Puntero al array de punteros de la estructura Pelicula con el que vamos a trabajar
 * \param sizeArray int* dimension del array
 * \param idPelicula int ID de la pelicula que se quiere modificar
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no lo hace
 *
 */
int pelicula_modificar(Pelicula **arrayPeliculas, int *sizeArray, int idPelicula)
{
    int retorno = -1;
    char auxiliarTitulo[100];
    char auxiliarGenero[50];
    int auxiliarDuracion;
    char auxiliarDescripcion[200];
    int auxiliarPuntaje;
    char auxiliarLinkImagen[200];
    int posicion;
    int i;
    int auxiliarId;

    if(arrayPeliculas != NULL && *sizeArray > 0)
    {
        if(idPelicula >= 0)
        {
            for(i = 0; i < *sizeArray; i++)
            {
                pelicula_getId(arrayPeliculas[i], &auxiliarId);
                if(auxiliarId == idPelicula)
                {
                    posicion = i;
                    retorno = 0;
                    break;
                }
            }
            if(retorno == 0)
            {
                if(getString("Ingrese el nuevo Titulo\n", auxiliarTitulo))
                {
                    if(getString("Ingrese el nuevo Genero\n", auxiliarGenero))
                    {
                        if(getString("Ingrese la nueva Descripcion\n", auxiliarDescripcion))
                        {
                            if(!getValidInt("Ingrese la nueva Duracion\n", "Error. Intente de nuevo\n", &auxiliarDuracion, 0, 250, 2))
                            {
                                if(!getValidUrl("Ingrese el nuevo Link de la imagen\n", "Error. El link no es de tipo valido.adp Intente de nuevo\n", "Error. Se excede la dimension. Intente de nuevo\n", auxiliarLinkImagen, 200, 2))
                                {
                                    if(!getValidInt("Ingrese el nuevo Puntaje[entre 1 y 10]\n", "Error. Intente de nuevo\n", &auxiliarPuntaje, 1, 10, 2))
                                    {
                                        arrayPeliculas[i] = pelicula_newAlta(auxiliarTitulo, auxiliarGenero, auxiliarDuracion, auxiliarDescripcion, auxiliarPuntaje, auxiliarLinkImagen);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return retorno;
}

/** \brief Establece el valor del campo Titulo dentro de la estructura Pelicula
 *
 * \param this Pelicula* Array de peliculas con el que vamos a trabajar
 * \param titulo char* Valor que se le establece al campo Titulo
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no lo hace
 *
 */
int pelicula_setTitulo(Pelicula *this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {
        strcpy(this->titulo, titulo);
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el valor del campo Titulo de un elemento de la estructura Pelicula
 *
 * \param this Pelicula* Array de peliculas con el que vamos a trabajar
 * \param titulo char* Variable donde se pondra el valor obtenido
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no lo hace
 *
 */
int pelicula_getTitulo(Pelicula *this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {
        strcpy(titulo, this->titulo);
        retorno = 0;
    }
    return retorno;
}

/** \brief Establece el valor del campo Genero dentro de la estructura Pelicula
 *
 * \param this Pelicula* Array de peliculas con el que vamos a trabajar
 * \param genero char* Valor que se le establece al campo Genero
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no lo hace
 *
 */
int pelicula_setGenero(Pelicula *this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL)
    {
        strcpy(this->genero, genero);
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el valor del campo Genero de un elemento de la estructura Pelicula
 *
 * \param this Pelicula* Array de peliculas con el que vamos a trabajar
 * \param genero char* Variable donde se pondra el valor obtenido
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no lo hace
 *
 */
int pelicula_getGenero(Pelicula *this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL)
    {
        strcpy(genero, this->genero);
        retorno = 0;
    }
    return retorno;
}

/** \brief Establece el valor del campo Duracion dentro de la estructura Pelicula
 *
 * \param this Pelicula* Array de peliculas con el que vamos a trabajar
 * \param duracion char* Valor que se le establece al campo Duracion
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no lo hace
 *
 */
int pelicula_setDuracion(Pelicula *this, int duracion)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->duracion = duracion;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el valor del campo Duracion de un elemento de la estructura Pelicula
 *
 * \param this Pelicula* Array de peliculas con el que vamos a trabajar
 * \param duracion char* Variable donde se pondra el valor obtenido
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no lo hace
 *
 */
int pelicula_getDuracion(Pelicula *this, int* duracion)
{
    int retorno = -1;
    if(this != NULL && duracion != NULL)
    {
        *duracion = this->duracion;
        retorno = 0;
    }
    return retorno;
}

/** \brief Establece el valor del campo Descripcion dentro de la estructura Pelicula
 *
 * \param this Pelicula* Array de peliculas con el que vamos a trabajar
 * \param descripcion char* Valor que se le establece al campo Descripcion
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no lo hace
 *
 */
int pelicula_setDescripcion(Pelicula *this, char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL)
    {
        strcpy(this->descripcion, descripcion);
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el valor del campo Descripcion de un elemento de la estructura Pelicula
 *
 * \param this Pelicula* Array de peliculas con el que vamos a trabajar
 * \param descripcion char* Variable donde se pondra el valor obtenido
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no lo hace
 *
 */
int pelicula_getDescripcion(Pelicula *this, char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL)
    {
        strcpy(descripcion, this->descripcion);
        retorno = 0;
    }
    return retorno;
}

/** \brief Establece el valor del campo Link dentro de la estructura Pelicula
 *
 * \param this Pelicula* Array de peliculas con el que vamos a trabajar
 * \param link char* Valor que se le establece al campo Link
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no lo hace
 *
 */
int pelicula_setLink(Pelicula *this, char* link)
{
    int retorno = -1;
    if(this != NULL && link != NULL)
    {
        strcpy(this->link, link);
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el valor del campo Link de un elemento de la estructura Pelicula
 *
 * \param this Pelicula* Array de peliculas con el que vamos a trabajar
 * \param link char* Variable donde se pondra el valor obtenido
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no lo hace
 *
 */
int pelicula_getLink(Pelicula *this, char* link)
{
    int retorno = -1;
    if(this != NULL && link != NULL)
    {
        strcpy(link, this->link);
        retorno = 0;
    }
    return retorno;
}

/** \brief Establece el valor del campo Puntaje dentro de la estructura Pelicula
 *
 * \param this Pelicula* Array de peliculas con el que vamos a trabajar
 * \param puntaje char* Valor que se le establece al campo Puntaje
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no lo hace
 *
 */
int pelicula_setPuntaje(Pelicula *this, int puntaje)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->puntaje = puntaje;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el valor del campo Puntaje de un elemento de la estructura Pelicula
 *
 * \param this Pelicula* Array de peliculas con el que vamos a trabajar
 * \param puntaje char* Variable donde se pondra el valor obtenido
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no lo hace
 *
 */
int pelicula_getPuntaje(Pelicula *this, int* puntaje)
{
    int retorno = -1;
    if(this != NULL && puntaje != NULL)
    {
        *puntaje = this->puntaje;
        retorno = 0;
    }
    return retorno;
}

/** \brief Establece una ID para una pelicula
 *
 * \param this Pelicula* array de Peliculas con el que vamos a trabajar
 * \param id int Variable donde se encuentra el valor de la ID
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no lo hace
 *
 */
static int pelicula_setId(Pelicula *this, int id)
{
    int retorno = -1;
    static int maximoId = -1;
    if(this != NULL)
    {
        retorno = 0;
        if(id >= 0)
        {
            if(id > maximoId)
                maximoId = id;
            this->id = id;
        }
        else
        {
            maximoId++;
            this->id = maximoId;
        }
    }
    return retorno;
}

/** \brief Obtiene el valor del campo ID de un elemento de la estructura Pelicula
 *
 * \param this Pelicula* Array de peliculas con el que vamos a trabajar
 * \param id int* Variable donde se pondra el valor obtenido
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no lo hace
 *
 */
int pelicula_getId(Pelicula *this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Establece los campos de la estructura Pelicula a un nuevo elemento de esa estructura
 *
 * \param titulo char* Valor que se asignara al campo Titulo
 * \param genero char* Valor que se asignara al campo Genero
 * \param duracion int Valor que se asignara al campo Duracion
 * \param descripcion char* Valor que se asignara al campo Descripcion
 * \param puntaje int Valor que se asignara al campo Puntaje
 * \param link char* Valor que se asignara al campo Link
 * \param id int Valor que se asignara al campo ID
 * \return Pelicula* Un elemento creado si es que no existia, NULL si ya existia
 *
 */
Pelicula* pelicula_newLoad(char* titulo, char* genero, int duracion, char* descripcion, int puntaje, char* link, int id)
{
    Pelicula* auxPelicula = pelicula_new();
    if(     !pelicula_setTitulo(auxPelicula, titulo)
       &&   !pelicula_setGenero(auxPelicula, genero)
       &&   !pelicula_setDuracion(auxPelicula, duracion)
       &&   !pelicula_setDescripcion(auxPelicula, descripcion)
       &&   !pelicula_setPuntaje(auxPelicula, puntaje)
       &&   !pelicula_setLink(auxPelicula, link)
       &&   !pelicula_setId(auxPelicula, id))
    {
        return auxPelicula;
    }
    pelicula_delete(auxPelicula);
    return NULL;
}

/** \brief Nos muestra un listado de los elementos de estructura Pelicula que existen
 *
 * \param pelicula Pelicula** Puntero al array de punteros de estructura Pelicula
 * \param sizeArray int Dimension del array
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no lo hace
 *
 */
int pelicula_mostrar(Pelicula** pelicula, int sizeArray)
{
    int retorno = -1;
    int i;
    char titulo[50];
    int id;
    if(pelicula != NULL && sizeArray > 0)
    {
        retorno = 0;
        for(i = 0; i < sizeArray; i++)
        {
            pelicula_getTitulo(pelicula[i], titulo);
            pelicula_getId(pelicula[i], &id);
            printf("Titulo: %s - ID: %d\n", titulo, id);
        }
    }
    return retorno;
}
