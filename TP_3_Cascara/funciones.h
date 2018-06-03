#include "pelicula.h"
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


#endif // FUNCIONES_H_INCLUDED

int funciones_GenerarPaginaWeb(Pelicula **pelicula, int *indiceOcupado, int sizeArray, char* path);

int funciones_peliculaCargar(Pelicula** pelicula, int* indiceOcupado, int sizeArray, char* path);

int funciones_peliculaBajar(Pelicula** pelicula, int* indiceOcupado, int sizeArray, char* path);
