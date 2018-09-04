#include <stdio.h>
#include <stdlib.h>
#include "Nombres.h"

int sumar(int, int);
int restar(int, int);
int multiplicar(int, int);
float dividir(int, int);
int factorialMainA(int);
int factorialMainB(int);



int main()
{
    int operadorA=0;
    int operadorB=0;
    int opcion;
    int suma;
    int resta;
    int multiplicacion;
    float division;
    int factorial;
    int factorialOperadorB;
    int verificadorUno=0;
    int verificadorDos=0;

    printf("\n Calculadora de enteros. Ingrese una de las siguientes opciones: \n");
    system ("pause");

    do
    {
        printf("\n 1.- Ingresar el operador A= %d \n", operadorA);
        printf("\n 2.- Ingresar el operador B= %d \n", operadorB);
        printf("\n 3.- Calcular todas las operaciones) \n");
        printf("\n Sumar (A+B) \n");
        printf("\n Restar (A-B) \n");
        printf("\n Multiplicación (A * B) \n");
        printf("\n División (A / B) \n");
        printf("\n Factorial de A y B (!N) \n");
        printf("\n 4.- Informar resultados: ");
        printf("\n 5.- Salir de la calculadora.- \n");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
        printf("Ingrese el primer numero: ");
        scanf("%d", &operadorA);
        verificadorUno++;
        break;
        case 2:
        printf("Ingrese el segundo numero: ");
        scanf("%d", &operadorB);
        verificadorDos++;
        break;
        case 3:
        if (verificadorUno == 0 || verificadorDos == 0)
        {
            printf("Error. Ingrese numeros validos.");
        }
        else
        {
        suma=sumar(operadorA, operadorB);
        resta=restar(operadorA, operadorB);
        multiplicacion=multiplicar(operadorA, operadorB);
        division=dividir(operadorA, operadorB);
        factorial=factorialMainA(operadorA);
        factorialOperadorB=factorialMainB(operadorB);
        printf("\n Calculando resultados...\n");
        }
        break;
        case 4:
            if (verificadorUno == 0 || verificadorDos == 0)
        {
            printf("Error. Ingrese numeros validos.");
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
        printf("\n El resultado de %d / %d es: %f \n",operadorA, operadorB, division);
            }
        if (operadorA < 0 || operadorB < 0)
            {
            printf("\n No se puede sacar el factorial de un numero negativo\n");
            }
        else
            {
        printf("\n El resultado del factorial de %d es: %d \n", operadorA, factorial);
        printf("\n El resultado del factorial de %d es: %d \n", operadorB, factorialOperadorB);
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
