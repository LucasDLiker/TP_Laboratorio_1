
int sumar(int operadorA, int operadorB)
{

    int resultadoSuma;
    resultadoSuma= operadorA+operadorB;

    return resultadoSuma;
}

int restar(int operadorA, int operadorB)
{

    int resultadoResta;
    resultadoResta= operadorA-operadorB;

    return resultadoResta;
}

int multiplicar(int operadorA, int operadorB)
{

    int resultadoMultiplicacion;
    resultadoMultiplicacion=operadorA*operadorB;

    return resultadoMultiplicacion;
}

float dividir(int operadorA, int operadorB)
{

    float resultadoDivision;
    resultadoDivision= (float)operadorA/operadorB;

    return (float)resultadoDivision;
}

int factorialMainA(int operadorA)
{

    long long int resultadoFactorial=1;
    int i;

    for (i=operadorA; i>=1; i-- )
    {

        resultadoFactorial=resultadoFactorial*i;
    }

    return resultadoFactorial;

}

int factorialMainB(int operadorB)

{

    long long int resultadoFactorialOperadorB=1;
    int i;

    for (i=operadorB; i>=1; i-- )
    {

        resultadoFactorialOperadorB=resultadoFactorialOperadorB*i;
    }

    return resultadoFactorialOperadorB;

}
