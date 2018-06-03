#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "validaciones.h"


/**
 * \brief Solicita un número flotante al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat(char * mensaje)
{
    float auxiliar;
    printf("%s", mensaje);
    scanf("%f", &auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un número entero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char * mensaje)
{
    int auxiliar;
    printf("%s", mensaje);
    scanf("%d", &auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char * mensaje)
{
    char auxiliar;
    printf("%s", mensaje);
    clearStdin();
    scanf("%c", &auxiliar);
    return auxiliar;
}
/**
 * \brief Genera un número aleatorio
 * \param desde Número aleatorio mínimo
 * \param hasta Número aleatorio máximo
 * \param iniciar Indica si se trata del primer número solicitado, 1 indica que si
 * \return retorna el número aleatorio generado
 *
 */
char getNumeroAleatorio(int desde, int hasta, int iniciar)
{
    if(iniciar == 1)
    {
        srand (time(NULL));
    }
    return desde + (rand() % (hasta + 1 - desde));
}


/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param string Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int isValidFloat(char* string)
{
   int i = 0;
   int cantidadPuntos = 0;
   while(string[i] != '\0')
   {
       if(i == 0 && string[i] == '-')
       {
           i++;
           continue;
       }
       if(string[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;
       }
       if(string[i] < '0' || string[i] > '9')
       {
            return 0;
       }
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido es numérico
 * \param string Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int isValidInt(char* string)
{
   int i = 0;
   while(string[i] != '\0')
   {
       if (i == 0 && string[i] == '-')
       {
           i++;
           continue;
       }
       if(string[i] < '0' || string[i] > '9')
       {
           return 0;
       }
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param string Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int isValidString(char string[])
{
   int i = 0;
   while(string[i] != '\0')
   {
       if((string[i] != ' ') && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z'))
       {
           return 0;
       }
       i++;
   }
   return 1;
}

/** \brief Verifica si el valor recibido es un URL valido
 *
 * \param string[] char Array con la cadena a ser analizada
 * \return int 1 si es valido, 0 si no lo es
 *
 */
int isValidUrl(char *url)
{
    int retorno = -1;
    int size = strlen(url);
    int i;
    size = size - 4;
    if(!strncmp(url, "www.", 4) || !strncmp(url, "http://", 7) || !strncmp(url, "https://", 8))
    {
        if(url[size] == '.' && url[size+1] == 'j' && url[size+2] == 'p' && url[size+3] == 'g')
        {
            retorno = 0;
            for(i = 0; i < strlen(url); i++)
            {
                if(url[i] == '.' && url[i+1] == '.')
                {
                    retorno = -1;
                    break;
                }
            }
        }

    }
    return retorno;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param string Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char string[])
{
   int i = 0;
   while(string[i] != '\0')
   {
       if((string[i] != ' ') && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z') && (string[i] < '0' || string[i] > '9'))
       {
           return 0;
       }
       i++;
   }
   return 1;
}


/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param string Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char string[])
{
   int i = 0;
   int contadorGuiones = 0;
   while(string[i] != '\0')
   {
       if((string[i] != ' ') && (string[i] != '-') && (string[i] < '0' || string[i] > '9'))
       {
           return 0;
       }
       if(string[i] == '-')
       {
           contadorGuiones++;
       }
       i++;
   }
   if(contadorGuiones == 1) // debe tener un guion
   {
       return 1;
   }
   return 0;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostringado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
char getString(char mensaje[],char input[])
{
    printf("%s", mensaje);
    clearStdin();
    scanf("%[^\n]s", input);
    return input;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje, aux);
    if(isValidString(aux))
    {
        strcpy(input, aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un URL al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el URL es valido
 */
int getStringURL(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje, aux);
    if(isValidUrl(aux))
    {
        strcpy(input, aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje, aux);
    if(isValidInt(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje, aux);
    if(isValidFloat(aux))
    {
        strcpy(input, aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error
 * \param minimo Es el limite inferior aceptado
 * \param maximo Es el limite superior aceptado
 * \param input puntero al lugar donde se cargará el numero ingresado
 * \param attemps indica la cantidad de reintentos ante un error
 * \return 0 si consiguio el Numero -1 si no
 *
 */
int getValidInt(char requestMessage[], char errorMessage[], int* input, int minimo, int maximo, int attemps)
{
    char auxstring[256];
    int auxInt;
    int i;
    int retorno = -1;

    for(i = 0; i < attemps; i++)
    {
        if (!getStringNumeros(requestMessage, auxstring))
        {
            printf("%s", errorMessage);
            break;
            continue;
        }
        auxInt = atoi(auxstring);
        if(auxInt < minimo || auxInt > maximo)
        {
            printf ("%s", errorMessage);
            continue;
        }
        *input = auxInt;
        retorno = 0;
        break;
    }
    return retorno;
}


/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error de tipo
 * \param mensajeDimensionError Es el mensaje a ser mostrado en caso de error de longitud
 * \param input Array donde se cargará el texto ingresado
 * \param dimension int Longitud maxima del texto ingresado
 * \param attemps indica la cantidad de reintentos ante un error
 * \return 0 si consiguio el String -1 si no
 *
 */
int getValidString(char requestMessage[], char errorMessage[], char mensajeDimensionError[], char input[], int dimension, int attemps)
{
    int retorno = -1;
    char buffer[1024];
    int i;

    for(i = 0; i < attemps; i++)
    {
        if (!getStringLetras(requestMessage, buffer))
        {
            printf ("%s", errorMessage);
            continue;
        }
        if(strlen(buffer) >= dimension)
        {
            printf ("%s", mensajeDimensionError);
            continue;

        }
        retorno = 0;
        strcpy(input, buffer);
        break;
    }
    return retorno;
}

/**
 * \brief Solicita un URL
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error de tipo
 * \param mensajeDimensionError Es el mensaje a ser mostrado en caso de error de longitud
 * \param input Array donde se cargará el texto ingresado
 * \param dimension int Longitud maxima del texto ingresado
 * \param attemps indica la cantidad de reintentos ante un error
 * \return 0 si consiguio el URL -1 si no
 *
 */
 int getValidUrl(char *requestMessage,char *errorMessage, char *mensajeDimensionError,char *input, int dimension,int attemps)
{
    int i;
    int retorno=-1;
    char buffer[1024];

    for(i=0;i<attemps;i++)
    {
        if (!getString(requestMessage,buffer) && !isValidUrl(buffer))
        {
            printf ("%s",errorMessage);
            continue;
        }
        if(strlen(buffer) >= dimension)
        {
            printf ("%s",mensajeDimensionError);
            continue;

        }
        retorno=0;
        strcpy(input,buffer);
        break;
    }
    return retorno;
}

/**
 * \brief Solicita un numero flotante al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param minimo Es el limite inferior aceptado
 * \param maximo Es el limite superior aceptado
 * \param input puntero al lugar donde se cargará el numero ingresado
 * \param attemps indica la cantidad de reintentos ante un error
 * \return 0 si consiguio el Numero -1 si no
 *
 */
int getValidFloat(char requestMessage[],char errorMessage[], float* input, float minimo, float maximo, int attemps)
{
    char auxString[256];
    int i;
    int retorno = -1;
    float auxInt;

    for(i = 0; i < attemps; i++)
    {
        if (!getStringNumerosFlotantes(requestMessage, auxString))
        {
            printf ("%s",errorMessage);
            break;
            continue;

        }
        auxInt = atof(auxString);
        if(auxInt < minimo || auxInt > maximo)
        {
            printf ("%s",errorMessage);
            continue;

        }
        *input = auxInt;
        retorno = 0;
        break;

    }
    return retorno;

}


/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void clearStdin(void)
{
    setbuf(stdin,NULL);
}

/**
 * \brief Hace una pausa, similar al system("pause")
 * \param -
 * \return -
 *
 */
void pause(void)
{
    getChar("");
}

/**
 * \brief Hace un clear, similar al system("clear")
 * \param -
 * \return -
 *
 */
void clearScreen(void)
{
    system("clear"); //system("cls");
}
