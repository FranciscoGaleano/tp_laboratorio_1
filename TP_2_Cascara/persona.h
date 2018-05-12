#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;//donde 0 es ocupado y 1 es libre//
    int dni;

}Persona;

#endif // FUNCIONES_H_INCLUDED

int per_crear(Persona * arrayDePersonas, int sizeArray);
int per_buscarLibre(Persona * arrayDePersonas, int sizeArray);
int per_alta(Persona * arrayDePersonas, int sizeArray);
int per_graficarEdades(Persona * arrayDePersonas, int sizeArray);
int per_ordenarAlfabeticamente(Persona * arrayDePersonas, int sizeArray);
