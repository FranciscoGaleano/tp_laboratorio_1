#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "pelicula.h"
#include "validaciones.h"
#define QTY 100
int main()
{
    Pelicula *arrayPelicula[QTY];
    char seguir = 's';
    int opcion = 0;
    int indiceOcupado = 0;
    int id;
    int resultado;
    funciones_peliculaCargar(arrayPelicula, &indiceOcupado, QTY, "Datos/datos.txt");
    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                pelicula_alta(arrayPelicula, &indiceOcupado);
                printf("Desea continuar? S/N\n");
                fflush(stdin);
                scanf("%c", &seguir);
                system("cls");
                break;
            case 2:
                pelicula_mostrar(arrayPelicula, indiceOcupado);
                getValidInt("Ingrese el ID de la pelicula a borrar\n", "Ingese un ID valido. Intente de nuevo\n", &id, 0, 100, 5);
                pelicula_baja(arrayPelicula, &indiceOcupado, id);
                printf("Desea continuar? S/N\n");
                fflush(stdin);
                scanf("%c", &seguir);
                system("cls");
                break;
            case 3:
                pelicula_mostrar(arrayPelicula, indiceOcupado);
                getValidInt("Ingrese el ID de la pelicula a modificar\n", "Ingrese un ID valido. Intente de nuevo\n", &id, 0, 100, 5);
                pelicula_modificar(arrayPelicula, &indiceOcupado, id);
                printf("Desea continuar? S/N\n");
                fflush(stdin);
                scanf("%c", &seguir);
                system("cls");
                break;
            case 4:
                resultado = funciones_generarPaginaWeb(arrayPelicula, &indiceOcupado, QTY, "Pagina Web/index.html");
                if(resultado == 0)
                {
                    printf("La pagina web se genero con exito.\n");
                }
                else
                {
                    printf("La pagina web no se pudo generar.\n");
                }
                printf("Desea continuar? S/N\n");
                fflush(stdin);
                scanf("%c", &seguir);
                system("cls");
                break;
            case 5:
                seguir = 'n';
                break;
            default :
                printf("Opcion invalida. Intente de nuevo.\n");
                break;
        }
    }
    funciones_peliculaBajar(arrayPelicula, &indiceOcupado, QTY, "Datos/datos.txt");

    return 0;
}
