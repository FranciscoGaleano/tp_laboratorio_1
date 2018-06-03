#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "pelicula.h"

/** \brief Agrega un elemento de estructura Pelicula a un archivo
 *
 * \param pelicula Pelicula** Puntero al array de punteros de estructura Pelicula
 * \param indiceOcupado int* Puntero a la variable que otorga el maximo indice ocupado
 * \param sizeArray int Dimension del array
 * \param path char* Direccion del archivo con el que vamos a trabajar
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no lo hace
 *
 */
int funciones_generarPaginaWeb(Pelicula **pelicula, int *indiceOcupado, int sizeArray, char* path)
{
    int retorno = -1;
    int i;
    char titulo[100];
    char genero[50];
    int duracion;
    char descripcion[200];
    int puntaje;
    char link[200];
    FILE* pFile;
    pFile = fopen(path,"w");
    if(pFile != NULL && pelicula != NULL && sizeArray > 0 && *indiceOcupado >= 0 &&  sizeArray > *indiceOcupado)
    {
        retorno = 0;
        fprintf(pFile, "<!DOCTYPE html>\n");
        fprintf(pFile, "<!-- Template by Quackit.com -->\n");
        fprintf(pFile, "<html lang='en'>\n");
        fprintf(pFile, "<head>\n");
        fprintf(pFile, "<meta charset='utf-8'>\n");
        fprintf(pFile, "<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n");
        fprintf(pFile, "<meta name='viewport' content='width=device-width, initial-scale=1'>\n");
        fprintf(pFile, "<!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n");
        fprintf(pFile, "<title>Lista peliculas</title>\n");
        fprintf(pFile, "<!-- Bootstrap Core CSS -->\n");
        fprintf(pFile, "<link href='css/bootstrap.min.css' rel='stylesheet'>\n");
        fprintf(pFile, "<!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n");
        fprintf(pFile, "<link href='css/custom.css' rel='stylesheet'>\n");
        fprintf(pFile, "<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n");
        fprintf(pFile, "<!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n");
        fprintf(pFile, "<!--[if lt IE 9]>\n");
        fprintf(pFile, "<script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n");
        fprintf(pFile, "<script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n");
        fprintf(pFile, "<![endif]-->\n");
        fprintf(pFile, "</head>\n");
        fprintf(pFile, "<body>\n");
        fprintf(pFile, "<div class='container'>\n");
        fprintf(pFile, "<div class='row'>\n");
        fprintf(pFile, "<!-- Repetir esto para cada pelicula -->\n");
        fprintf(pFile, "<article class='col-md-4 article-intro'>\n");
        for(i = 0; i < *indiceOcupado; i++)
        {
            pelicula_getTitulo(pelicula[i], titulo);
            pelicula_getGenero(pelicula[i], genero);
            pelicula_getDescripcion(pelicula[i], descripcion);
            pelicula_getDuracion(pelicula[i], &duracion);
            pelicula_getPuntaje(pelicula[i], &puntaje);
            pelicula_getLink(pelicula[i], link);
            fprintf(pFile,"<a href='#'> <img class='img-responsive img-rounded' src='%s' alt=''> </a> \
                    <h3> <a href='#'>%s</a> </h3> <ul> <li>Genero:%s</li> <li>Puntaje:%d</li> <li>Duracion:%d</li> </ul> <p>%s</p>",
                    link, titulo, genero, puntaje, duracion, descripcion);
        }
        fprintf(pFile, "</article>\n");
        fprintf(pFile, "<!-- Repetir esto para cada pelicula -->\n");
        fprintf(pFile, "</div>\n");
        fprintf(pFile, "<!-- /.row -->\n");
        fprintf(pFile, "</div>\n");
        fprintf(pFile, "<!-- /.container -->\n");
        fprintf(pFile, "<!-- jQuery -->\n");
        fprintf(pFile, "<script src='js/jquery-1.11.3.min.js'></script>\n");
        fprintf(pFile, "<!-- Bootstrap Core JavaScript -->\n");
        fprintf(pFile, "<script src='js/bootstrap.min.js'></script>\n");
        fprintf(pFile, "<!-- IE10 viewport bug workaround -->\n");
        fprintf(pFile, "<script src='js/ie10-viewport-bug-workaround.js'></script>\n");
        fprintf(pFile, "<!-- Placeholder Images -->\n");
        fprintf(pFile, "<script src='js/holder.min.js'></script>\n");
        fprintf(pFile, "</body>\n");
        fprintf(pFile, "</html>\n");
    }
    fclose(pFile);
    return retorno;
}

/** \brief Carga los datos de un archivo a un elemento de la estructura Pelicula
 *
 * \param pelicula Pelicula** Puntero al array de punteros de estructura Pelicula
 * \param indiceOcupado int* Puntero a la variable que otorga el maximo indice ocupado
 * \param sizeArray int Dimension de array
 * \param path char* Direccion del archivo con el que vamos a trabajar
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no lo hace
 *
 */
int funciones_peliculaCargar(Pelicula** pelicula, int* indiceOcupado, int sizeArray, char* path)
{
    int retorno = -1;
    char bTitulo[256];
    char bGenero[256];
    char bDuracion[256];
    char bDescripcion[256];
    char bPuntaje[256];
    char bLink[256];
    char bIdPelicula[256];
    int duracion;
    int puntaje;
    int idpelicula;

    FILE* pFile;
    pFile = fopen(path,"r");
    if(pFile != NULL && pelicula != NULL && sizeArray > 0 && *indiceOcupado >= 0 &&  sizeArray > *indiceOcupado)
    {
        retorno = 0;
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^\n]\n",bTitulo, bGenero, bDuracion,
                   bDescripcion, bPuntaje, bLink, bIdPelicula);
            duracion = atoi(bDuracion);
            puntaje = atoi(bPuntaje);
            idpelicula = atoi(bIdPelicula);
            pelicula[*indiceOcupado] = pelicula_newLoad(bTitulo, bGenero, duracion, bDescripcion,
                                                        puntaje, bLink, idpelicula);
            (*indiceOcupado)++;
        }
    }
    fclose(pFile);
    return retorno;
}

/** \brief Crea un archivo con los datos de un elemento de la estructura Pelicula
 *
 * \param pelicula Pelicula** Puntero al array de punteros de estructura Pelicula
 * \param indiceOcupado int* Puntero a la variable que otorga el maximo indice ocupado
 * \param sizeArray int Dimension del array
 * \param path char* Direccion del archivo con el que vamos a trabajar
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no lo hace
 *
 */
int funciones_peliculaBajar(Pelicula** pelicula, int* indiceOcupado, int sizeArray, char* path)
{
    int retorno = -1;
    int i;
    char titulo[100];
    char genero[50];
    int duracion;
    char descripcion[200];
    int puntaje;
    char link[200];
    int idPelicula;
    FILE* pFile;
    pFile = fopen(path,"w");
    if(pFile != NULL && pelicula != NULL && sizeArray > 0 && *indiceOcupado >= 0 &&  sizeArray > *indiceOcupado)
    {
        retorno = 0;
        for(i = 0; i < *indiceOcupado; i++)
        {
            pelicula_getTitulo(pelicula[i], titulo);
            pelicula_getGenero(pelicula[i], genero);
            pelicula_getId(pelicula[i], &idPelicula);
            pelicula_getDescripcion(pelicula[i], descripcion);
            pelicula_getDuracion(pelicula[i], &duracion);
            pelicula_getLink(pelicula[i], link);
            pelicula_getPuntaje(pelicula[i], &puntaje);
            fprintf(pFile,"%s@%s@%d@%s@%d@%s@%d\n", titulo, genero, duracion,
                    descripcion, puntaje, link, idPelicula);
        }
    }
    fclose(pFile);
    return retorno;
}
