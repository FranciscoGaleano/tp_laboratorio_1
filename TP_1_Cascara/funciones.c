/** \brief Genero un n�mero flotante el cual va a ser validado
 *
 * \param mensaje char* Creo un mensaje donde le pido al usuario que ingrese un n�mero
 * \param mensajeError char* Creo un mensaje donde le pido al usuario que ingrese un n�mero dentro de los par�metros
 * \param reintentos int N�mero de reintentos que se tiene para ingresar un n�mero dentro de los par�metros
 * \param minimo int N�mero m�nimo que puede ingresar el usuario
 * \param maximo int N�mero m�ximo que puede ingresar el usuario
 * \param numeroObtenido float* Espacio de memoria donde se va a guardar el n�mero despu�s de ser validado
 * \return float N�mero el cual ya fue validado
 *
 */
float getNumber(char* mensaje, char* mensajeError, int reintentos, float minimo, float maximo, float *numeroObtenido)
{
    int retorno = -1;
    float datoRequerido;
    printf("%s", mensaje);
    scanf("%f", &datoRequerido);
    while(reintentos > 0)
    {
        reintentos--;
        if((datoRequerido > minimo && datoRequerido < maximo) || datoRequerido == 0)
        {
            *numeroObtenido = datoRequerido;
            retorno = 0;
            break;
        }
        else if(datoRequerido < minimo)
        {
            retorno = -1;
        }
        else
        {
            retorno = -2;
        }
        printf("%s", mensajeError);
        scanf("%f", &datoRequerido);
    }
    return retorno;
}


/** \brief Toma dos n�meros flotantes ya validados y los suma
 *
 * \param primerNumero float* Espacio de memoria donde se encuentra el primer n�mero flotante
 * \param segundoNumero float* Espacio de memoria donde se encuentra el segundo n�mero flotante
 * \param resultado double* Espacio de memoria donde se va a guardar el resultado de la suma
 * \return double Es el nuevo numero resultado de la suma
 *
 */
double sumar(float * primerNumero, float * segundoNumero, double * resultado)
{
    float primerSumando;
    float segundoSumando;
    double auxiliarResultado;
    primerSumando = *primerNumero;
    segundoSumando = * segundoNumero;
    auxiliarResultado = primerSumando + segundoSumando;
    *resultado = auxiliarResultado;
    printf("El resultado de la suma es %.2f\n", *resultado);
}

/** \brief Toma dos n�meros flotantes ya validados y los resta
 *
 * \param primerNumero float* Espacio de memoria donde se encuntra el primer n�mero flotante
 * \param segundoNumero float* Espacio de memoria donde se encuentra el segundo n�mero flotante
 * \param resultado double* Espacio de memoria donde se va a guardar el resultado de la resta
 * \return double Es el nuevo n�mero resultado de la resta
 *
 */
double restar(float * primerNumero, float * segundoNumero, double * resultado)
{
    float primerRestando;
    float segundoRestando;
    double auxilirResultado;
    primerRestando = *primerNumero;
    segundoRestando = *segundoNumero;
    auxilirResultado = primerRestando - segundoRestando;
    *resultado = auxilirResultado;
    printf("EL resultado de la resta es %.2f\n", *resultado);
}

/** \brief Toma dos n�meros flotantes ya validados y los divide
 *
 * \param primerNumero float* Espacio de memoria donde se encuentra el n�mero flotante que ser� el dividendo
 * \param segundoNumero float* Espacio de memoria donde se encuentra el n�mero flotante que ser� el divisor
 * \param resultado double* Espacio de memoria donde se va a guardar el resultado de la division
 * \return double Es el nuevo numero resultado de la division
 *
 */
double dividir(float * primerNumero, float * segundoNumero, double * resultado)
{
    float dividendo;
    float divisor;
    double auxiliarResultado;
    dividendo = *primerNumero;
    divisor = *segundoNumero;
    while(divisor == 0)
    {
        printf("No se puede dividir por 0. Intente de nuevo.\nIngrese un nuevo numero\t");
        scanf("%f", &divisor);
    }
    auxiliarResultado = dividendo / divisor;
    *resultado = auxiliarResultado;
    printf("El resultado de la division es %.2f\n", *resultado);
}

/** \brief Toma dos n�meros flotantes ya validados y los multiplica
 *
 * \param primerNumero float* Es el espacio de memoria donde se encuentra el primer n�mero flotante
 * \param segundoNumero float* Es el espacio de memoria donde se encuentra el segundo n�mero flotante
 * \param resultado double* Es el espacio de memoria donde se va a guardar el resultado de la multiplicacion
 * \return double Es el nuevo n�mero resultado de la multuplicacion
 *
 */
double multiplicar(float * primerNumero, float * segundoNumero, double * resultado)
{
    float primerMultiplicador;
    float segundoMultiplicador;
    double auxiliarResultado;
    primerMultiplicador = *primerNumero;
    segundoMultiplicador = *segundoNumero;
    auxiliarResultado = primerMultiplicador * segundoMultiplicador;
    *resultado = auxiliarResultado;
    printf("El resultado de la multiplicacion es %.2f\n", *resultado);
}

/** \brief Toma un n�mero flotante ya validado para obtener su factorial
 *
 * \param numeroBase float* Es el espacio de memoria donde se encuentra el n�mero flotante a obtener su factorial
 * \param double maximoFactorial Es el n�mero flotante m�ximo al cual el factorial puede llegar
 * \param numeroFactorial double* Es el espacio de memoria donde se va a guardar el factorial obtenido
 * \return double Es el factorial obtenido a partir del n�mero base
 *
 */
double obtenerFactorial(float * numeroBase, double maximoFactorial, double * numeroFactorial)
{
    float a = *numeroBase;
    float b = a;
    double factorial = 1;
    for(b = a; b > 1; b--)
    {
        factorial = factorial * b;
        *numeroFactorial = factorial;
    }
    if(*numeroFactorial > maximoFactorial)
    {
        printf("El factorial de %.2f es muy grande, se excede del maximo.\n", a);
    }
    else
    {
    printf("El factorial de %.2f es %.2f\n", a, *numeroFactorial);
    }
}
