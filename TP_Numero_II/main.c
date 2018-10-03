#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"
#include "arrayEmpleados.h"



int main()
{
    char auxName[51];
    char auxLastName[51];
    float auxSalary;
    int auxId;
    int auxSector;
    int menuOption;
    int freeSlot;
    int validar=0;


    sEmployee arrayEmployees[MAX];
    initEmployees(arrayEmployees, MAX);

    /*addEmployee(arrayEmployees, MAX, auxId, "Lucas", "Liker", 15000.5, 1);
    addEmployee(arrayEmployees, MAX, auxId, "Pepito", "Pepin", 10000.7, 2);
    addEmployee(arrayEmployees, MAX, auxId, "Pablo", "Escobar", 50000.9, 3);
    addEmployee(arrayEmployees, MAX, auxId, "Violeta", "Pobre", 2000.7, 4);
    addEmployee(arrayEmployees, MAX, auxId, "Jorge", "Rodriguez", 15000.5, 5);
    addEmployee(arrayEmployees, MAX, auxId, "Brenda", "Perez", 21500.5, 6);
    addEmployee(arrayEmployees, MAX, auxId, "Adrian", "Socotroco", 16000.5, 6);*/

    while(menuOption != 5)
    {
        menuOption = menuOptions();
        switch(menuOption)
        {
            case 1:
            freeSlot=searchFreeSlot(arrayEmployees, MAX);
            validar++;
            if(freeSlot != EMPTY)
            {
                getString("\nIngrese el nombre del Empleado: \n", auxName);
                getString("\nIngrese el apellido del Empleado: \n", auxLastName);
                //getStringLetras("\nIngrese el nombre del Empleado: \n", auxName);
                //getStringLetras("\nAhora, ingrese el apellido: \n", auxLastName);
                auxSalary=getFloat("\nPor favor, ingrese el sueldo: \n");
                auxSector=getInt("\nPor ultimo, ingrese el sector: \n");

            }
            else
            {
                printf("\n No hay mas espacio para ingresar datos.- \n");
                 system("pause");
                 system("cls");
            }
            addEmployee(arrayEmployees, MAX, auxId, auxName, auxLastName, auxSalary, auxSector);
            break;
            case 2:
            if (validar > 0)
            {
                modifyEmployee(arrayEmployees, MAX);
                break;
            }
            else
            {
                printf("No hay datos para eliminar");
            }
            break;
            case 3:
            if(validar > 0)
            {
                removeEmployee(arrayEmployees, MAX, auxId);
            }
            else{
                printf("No hay datos para modificar");
            }
            break;
            case 4:
            if(validar > 0)
            {
                sortEmployees(arrayEmployees, MAX);
                printEmployees(arrayEmployees, MAX);
                averageSalary(arrayEmployees, MAX);
                system("pause");
                system("cls");
            }
            else
            {
                printf("No hay datos para mostrar");
            }
            break;
            case 5:
            printf("auf wiedersehen/Hasta Pronto...");
            break;
            default:
            printf("\n Error. Ingrese una opcion valida del 1 al 4 y 5 para salir. \n");
        }



    }
    return 0;
}
