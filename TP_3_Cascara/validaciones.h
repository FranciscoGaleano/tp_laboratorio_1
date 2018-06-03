#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED



#endif // VALIDACIONES_H_INCLUDED

float getFloat(char * mensaje);

int getInt(char * mensaje);

char getChar(char * mensaje);

char getNumeroAleatorio(int desde, int hasta, int iniciar);

int isValidFloat(char string[]);

int isValidInt(char string[]);

int isValidString(char* string);

int esAlfaNumerico(char string[]);

int esTelefono(char string[]);

char getString(char mensaje[], char input[]);

int getStringLetras(char mensaje[], char input[]);

int getStringURL(char mensaje[], char input[]);

int getStringNumeros(char mensaje[], char input[]);

int getStringNumerosFlotantes(char mensaje[], char input[]);

int getValidInt(char requestMessage[], char errorMessage[], int* input, int minimo, int maximo, int attemps);

int getValidFloat(char requestMessage[],char errorMessage[], float* input, float minimo, float maximo, int attemps);

int getValidString(char requestMessage[], char errorMessage[], char mensajeDimensionError[], char input[], int dimension, int attemps);

int getValidUrl(char requestMessage[], char errorMessage[], char mensajeDimensionError[], char input[], int dimension, int attemps);


