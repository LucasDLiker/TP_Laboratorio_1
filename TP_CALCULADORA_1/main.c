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
        break;
        case 2:
        printf("Ingrese el segundo numero: ");
        scanf("%d", &operadorB);
        break;
        case 3:
        suma=sumar(operadorA, operadorB);
        resta=restar(operadorA, operadorB);
        multiplicacion=multiplicar(operadorA, operadorB);
        division=dividir(operadorA, operadorB);
        factorial=factorialMainA(operadorA);
        factorialOperadorB=factorialMainB(operadorB);

        printf("Calculando resultados... Elija la opcion 4 para mostrarlos.");

        break;
        case 4:
        printf("\n El resultado de la suma es: %d \n", suma);
        printf("\n El resultado de la resta es: %d \n", resta);
        printf("\n El resultado de la multiplicacion es: %d \n", multiplicacion);
        printf("\n El resultado de la division es: %f \n", division);
        printf("\n El resultado del factorial de A es: %d \n", factorial);
        printf("\n El resultado del factorial de B es: %d \n", factorialOperadorB);

        break;
        case 5:
        printf("auf wiedersehen/Hasta Pronto...");
        break;
        default:
            printf("\n Error. Ingrese una opcion valida del 1 al 7 y 8 para salir. \n");
        }

    system("pause");
    system("cls");
    }while (opcion != 5);



    return 0;
}
