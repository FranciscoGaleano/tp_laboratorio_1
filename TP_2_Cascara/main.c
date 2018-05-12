#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#define QTY 20


int main()
{
    char seguir = 's';
    int opcion = 0;
    Persona listaDePersonas[QTY];
    int personaIndice;
    per_crear(listaDePersonas, QTY);

    /*strcpy(listaDePersonas[0].nombre,"Gerardo");
    strcpy(listaDePersonas[1].nombre,"Mateo");
    strcpy(listaDePersonas[2].nombre,"Ernesto");
    strcpy(listaDePersonas[3].nombre,"Eliana");
    strcpy(listaDePersonas[4].nombre,"Paula");
    strcpy(listaDePersonas[5].nombre,"Zoe");
    strcpy(listaDePersonas[6].nombre,"Alejandra");
    strcpy(listaDePersonas[7].nombre,"Federico");
    strcpy(listaDePersonas[8].nombre,"Martin");
    strcpy(listaDePersonas[9].nombre,"Facundo");
    strcpy(listaDePersonas[10].nombre,"Morena");
    strcpy(listaDePersonas[11].nombre,"Pablo");
    strcpy(listaDePersonas[12].nombre,"Karen");
    strcpy(listaDePersonas[13].nombre,"Carla");
    strcpy(listaDePersonas[14].nombre,"Oscar");

    listaDePersonas[0].dni=23456756;
    listaDePersonas[1].dni=23456764;
    listaDePersonas[2].dni=33000984;
    listaDePersonas[3].dni=23765789;
    listaDePersonas[4].dni=12345433;
    listaDePersonas[5].dni=43234565;
    listaDePersonas[6].dni=43456543;
    listaDePersonas[7].dni=45334543;
    listaDePersonas[8].dni=26366329;
    listaDePersonas[9].dni=14345643;
    listaDePersonas[10].dni=30474394;
    listaDePersonas[11].dni=64389427;
    listaDePersonas[12].dni=68343123;
    listaDePersonas[13].dni=24375432;
    listaDePersonas[14].dni=13243445;

    listaDePersonas[0].edad=34;
    listaDePersonas[1].edad=66;
    listaDePersonas[2].edad=13;
    listaDePersonas[3].edad=39;
    listaDePersonas[4].edad=13;
    listaDePersonas[5].edad=23;
    listaDePersonas[6].edad=24;
    listaDePersonas[7].edad=44;
    listaDePersonas[8].edad=22;
    listaDePersonas[9].edad=56;
    listaDePersonas[10].edad=10;
    listaDePersonas[11].edad=30;
    listaDePersonas[12].edad=34;
    listaDePersonas[13].edad=56;
    listaDePersonas[14].edad=11;

    listaDePersonas[0].estado=0;
    listaDePersonas[1].estado=0;
    listaDePersonas[2].estado=0;
    listaDePersonas[3].estado=0;
    listaDePersonas[4].estado=0;
    listaDePersonas[5].estado=0;
    listaDePersonas[6].estado=0;
    listaDePersonas[7].estado=0;
    listaDePersonas[8].estado=0;
    listaDePersonas[9].estado=0;
    listaDePersonas[10].estado=0;
    listaDePersonas[11].estado=0;
    listaDePersonas[12].estado=0;
    listaDePersonas[13].estado=0;
    listaDePersonas[14].estado=0;*/

    do
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n\n");
        printf("Que tarea desea realizar?\n\n");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                per_buscarLibre(listaDePersonas, QTY);
                per_alta(listaDePersonas, QTY);
                printf("Desea continuar? S/N\n");
                fflush(stdin);
                scanf("%c", &seguir);
                system("cls");
                break;
            case 2:
                printf("Aqui tiene la lista de personas ingresadas\n");
                per_mostrar(listaDePersonas, QTY);
                per_baja(listaDePersonas, QTY, &personaIndice);
                printf("Desea continuar? S/N\n");
                fflush(stdin);
                scanf("%c", &seguir);
                system("cls");
                break;
            case 3:
                printf("Ordenados alfabeticamente, la lista seria:\n");
                per_ordenarAlfabeticamente(listaDePersonas, QTY);
                per_mostrar(listaDePersonas, QTY);
                printf("Desea continuar? S/N\n");
                fflush(stdin);
                scanf("%c", &seguir);
                system("cls");
                break;
            case 4:
                per_graficarEdades(listaDePersonas, QTY);
                printf("Desea continuar? S/N\n");
                fflush(stdin);
                scanf("%c", &seguir);
                system("cls");
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("Ingrese una opcion valida.\n");
                printf("Desea continuar? S/N\n");
                fflush(stdin);
                scanf("%c", &seguir);
                system("cls");
                break;
        }
    }while(seguir == 's');

    return 0;
}
