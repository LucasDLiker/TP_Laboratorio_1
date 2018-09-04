/*
*Funciones:
*En esta página estan codificados las funciones matematicas
que van a ser llamadas desde el main.c.-
*/

//Funcion de suma
int sumar(int operadorA, int operadorB)
{

    int resultadoSuma;
    resultadoSuma= operadorA+operadorB;

    return resultadoSuma;
}
//Funcion de resta
int restar(int operadorA, int operadorB)
{

    int resultadoResta;
    resultadoResta= operadorA-operadorB;

    return resultadoResta;
}
//Funcion de multiplicacion
int multiplicar(int operadorA, int operadorB)
{

    int resultadoMultiplicacion;
    resultadoMultiplicacion=operadorA*operadorB;

    return resultadoMultiplicacion;
}
//funcion de division
float dividir(int operadorA, int operadorB)
{

    float resultadoDivision;
    resultadoDivision= (float)operadorA/operadorB;

    return (float)resultadoDivision;
}
//funcion de factorial
long long int factorialMainA(int operadorA)
{

    long long int resultadoFactorial=1;
    int i;

    for (i=operadorA; i>=1; i-- )
    {

        resultadoFactorial=resultadoFactorial*i;
    }

    return resultadoFactorial;

}

long long int factorialMainB(int operadorB)

{

    long long int resultadoFactorialOperadorB=1;
    int i;

    for (i=operadorB; i>=1; i-- )
    {

        resultadoFactorialOperadorB=resultadoFactorialOperadorB*i;
    }

    return resultadoFactorialOperadorB;

}
