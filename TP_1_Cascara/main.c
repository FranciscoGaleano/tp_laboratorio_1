#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define MINIMOFLOAT -3.4E+38
#define MAXIMOFLOAT 3.4E+38

int main()
{
    char seguir ='s';
    int opcion = 0;
    float primerNumero;
    float segundoNumero;
    double resultado;

    while(seguir == 's')
    {
    printf("1- Ingresar 1er operando (A=x)\n");
    printf("2- Ingresar 2do operando (B=y)\n");
    printf("3- Calcular la suma (A+B)\n");
    printf("4- Calcular la resta (A-B)\n");
    printf("5- Calcular la division (A/B)\n");
    printf("6- Calcular la multiplicacion (A*B)\n");
    printf("7- Calcular el factorial (A!)\n");
    printf("8- Calcular todas las operaciones\n");
    printf("9- Salir\n");

    do
    {
    printf("Ingrese la opcion que desea realizar\t");
    scanf("%d",&opcion);
    switch(opcion)
        {
        case 1:
            getNumber("Ingrese el primer numero\t", "Ingrese un numero valido\t", 5, MINIMOFLOAT, MAXIMOFLOAT, &primerNumero);
            system("cls");
            printf("1- Ingresar 1er operando (A=%.2f)\n", primerNumero);
            printf("2- Ingresar 2do operando (B=y)\n");
            printf("3- Calcular la suma (A+B)\n");
            printf("4- Calcular la resta (A-B)\n");
            printf("5- Calcular la division (A/B)\n");
            printf("6- Calcular la multiplicacion (A*B)\n");
            printf("7- Calcular el factorial (A!)\n");
            printf("8- Calcular todas las operaciones\n");
            printf("9- Salir\n");
            break;
        case 2:
            getNumber("Ingrese el segundo numero\t", "Ingrese un numero valido\t", 5, MINIMOFLOAT, MAXIMOFLOAT, &segundoNumero);
            system("cls");
            printf("1- Ingresar 1er operando (A=%.2f)\n", primerNumero);
            printf("2- Ingresar 2do operando (B=%.2f)\n", segundoNumero);
            printf("3- Calcular la suma (A+B)\n");
            printf("4- Calcular la resta (A-B)\n");
            printf("5- Calcular la division (A/B)\n");
            printf("6- Calcular la multiplicacion (A*B)\n");
            printf("7- Calcular el factorial (A!)\n");
            printf("8- Calcular todas las operaciones\n");
            printf("9- Salir\n");
            break;
        case 3:
            sumar(&primerNumero, &segundoNumero, &resultado);
            break;
        case 4:
            restar(&primerNumero, &segundoNumero, &resultado);
            break;
        case 5:
            dividir(&primerNumero, &segundoNumero, &resultado);
            break;
        case 6:
            multiplicar(&primerNumero, &segundoNumero, &resultado);
            break;
        case 7:
            obtenerFactorial(&primerNumero, MAXIMOFLOAT, &resultado);
            break;
        case 8:
            sumar(&primerNumero, &segundoNumero, &resultado);
            restar(&primerNumero, &segundoNumero, &resultado);
            dividir(&primerNumero, &segundoNumero, &resultado);
            multiplicar(&primerNumero, &segundoNumero, &resultado);
            obtenerFactorial(&primerNumero, MAXIMOFLOAT, &resultado);
            break;
        case 9:
            seguir = 'n';
            break;
        default:
            printf("Es opcion no es valida. Intentelo de nuevo.\n");
        }
    }while(seguir == 's');
    }
    return 0;
}
