#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED
typedef struct{
    char titulo[100];
    char genero[50];
    int duracion;
    char descripcion[200];
    int puntaje;
    char link[200];
    int id;
}Pelicula;
#endif // PELICULA_H_INCLUDED

void pelicula_delete(Pelicula* this);

Pelicula* pelicula_new();

Pelicula* pelicula_newLoad(char* titulo, char* genero,int duracion,char* descripcion,int puntaje,char* link, int id);

int pelicula_getId(Pelicula *this, int* id);

int pelicula_setTitulo(Pelicula *this, char* titulo);

int pelicula_getTitulo(Pelicula *this, char* titulo);

int pelicula_setGenero(Pelicula *this, char* genero);

int pelicula_getGenero(Pelicula *this, char* genero);

int pelicula_setDuracion(Pelicula *this, int duracion);

int pelicula_getDuracion(Pelicula *this, int* duracion);

int pelicula_setDescripcion(Pelicula *this, char* descripcion);

int pelicula_getDescripcion(Pelicula *this, char* descripcion);

int pelicula_setLink(Pelicula *this, char* link);

int pelicula_getLink(Pelicula *this, char* link);

int pelicula_setPuntaje(Pelicula *this, int puntaje);

int pelicula_getPuntaje(Pelicula *this, int* puntaje);

Pelicula* pelicula_newAlta(char* titulo, char* genero,int duracion,char* descripcion,int puntaje,char* link);

int pelicula_alta(Pelicula **arrayPelicula, int *sizeArray);

int pelicula_baja(Pelicula **arrayPelicula, int *sizeArray, int id);

int pelicula_modificar(Pelicula **arrayPeliculas, int *sizeArray, int idPelicula);

int pelicula_mostrar(Pelicula** pelicula, int sizeArray);
