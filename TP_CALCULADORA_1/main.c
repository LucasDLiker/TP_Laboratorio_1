#include <stdio.h>
#include <stdlib.h>
#include "Nombres.h"


int main()
{
    /*
    *Inicializacion de variables..
    OperadorA y operadorB son los numeros que se ingresan en la calculadora
    Los verificadores funcionan como banderas para poder invalidar datos erroneos como dividir por 0
    Las demas variables tienen el nombre de las distintas funciones de la calculadora para llamar cada resultado
    */

    int operadorA=0;
    int operadorB=0;
    int opcion;
    int suma;
    int resta;
    int multiplicacion;
    float division;
    long long int factorial;
    long long int factorialOperadorB;
    int verificadorUno=0;
    int verificadorDos=0;
    int casoTres=0;


    printf("\n Calculadora de enteros. Ingrese una de las siguientes opciones: \n");
    system ("pause");

    do
    {
        //El menu de la calculadora indicando que hace cada opcion

        printf("\n (1).- Ingresar el operador A= %d \n", operadorA);
        printf("\n (2).- Ingresar el operador B= %d \n", operadorB);
        printf("\n (3).- Calcular todas las operaciones) \n");
        printf("\n Sumar (A+B) \n");
        printf("\n Restar (A-B) \n");
        printf("\n Multiplicación (A * B) \n");
        printf("\n División (A / B) \n");
        printf("\n Factorial de A y B (!N) \n");
        printf("\n (4).- Informar resultados: ");
        printf("\n (5).- Salir de la calculadora.- \n");

        opcion=askOption();

        //Lo siguiente, usando switch es la codificacion del menu de opciones con sus respectivas funciones

        switch(opcion)
        {
        case 1:
        askNumber(&operadorA);
        verificadorUno++;
        break;
        case 2:
        askNumber(&operadorB);
        verificadorDos++;
        break;
        case 3:
            if (verificadorUno == 0 || verificadorDos == 0)
            {
            printf("Error. Ingrese numeros validos.");
            }
            else
            {

        //Sumar
        suma=sumar(operadorA, operadorB);
        //Restar
        resta=restar(operadorA, operadorB);
        //Multiplicacion
        multiplicacion=multiplicar(operadorA, operadorB);
        //Division
        division=dividir(operadorA, operadorB);
        //Factorial
        factorial=factorialMainA(operadorA);
        factorialOperadorB=factorialMainB(operadorB);
        casoTres++;


        printf("\n Calculando resultados...\n");
            }
        break;
        case 4:

            if (verificadorUno == 0 || verificadorDos == 0 || casoTres==0)
            {
            printf("Error. No ha ingresado la opcion 3 o no ha ingresado los datos");
            }
        else
        {
        printf("\n El resultado de %d + %d es: %d \n",operadorA, operadorB, suma);
        printf("\n El resultado de %d - %d es: %d \n",operadorA, operadorB, resta);
        printf("\n El resultado de %d * %d es: %d \n",operadorA, operadorB, multiplicacion);

            if (operadorA==0 || operadorB==0)
            {
            printf("\n Error. No se puede dividir por 0. Ingrese datos validos.\n");
            }
            else
            {
        printf("\n El resultado de %d / %d es: %.2f \n",operadorA, operadorB, division);
            }
            if (operadorA < 0)
            {
            printf("\n No se puede sacar el factorial de un numero negativo\n");
            }
            else
            {
        printf("\n El resultado del factorial de %d es: %lld \n", operadorA, factorial);
              }
            if (operadorB < 0)
             {
                printf("\n No se puede sacar el factorial de un numero negativo\n");
             }
             else
             {
                printf("\n El resultado del factorial de %d es: %lld \n", operadorB, factorialOperadorB);
             }




        }
        break;
        case 5:
        printf("auf wiedersehen/Hasta Pronto...");
        break;
        default:
            printf("\n Error. Ingrese una opcion valida del 1 al 4 y 5 para salir. \n");
        }

    system("pause");
    system("cls");
    }while (opcion != 5);



    return 0;
}
