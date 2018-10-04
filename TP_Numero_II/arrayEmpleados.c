#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"
#include "arrayEmpleados.h"

int menuOptions()
{
    int menuOption;
    fflush(stdin);
    printf("\n\n***MENU***\n\n -1 Dar de Alta Empleado: \n -2 Modificar Empleado: \n -3 Dar de Baja Empleado: \n -4 Lista\n -5 Presione (5) para salir: \n");
    fflush(stdin);
    scanf("%d", &menuOption);
    return menuOption;
}

int initEmployees(sEmployee* arrayEmployees, int lenght)
{
    int ret = EMPTY;
    int i;
    if(arrayEmployees != NULL && lenght!= 0)
    {
        ret = NOTEMPTY;
        for(i=0; i<lenght; i++)
        {
            arrayEmployees[i].isEmpty = ACTIVE;
        }
    }
    return ret;
}

int searchFreeSlot(sEmployee* arrayEmployees, int lenght)
{
    int ret = EMPTY;
    int i;
    if(lenght > 0 && arrayEmployees != NULL)
    {
        for(i=0; i<lenght; i++)
        {
            if(arrayEmployees[i].isEmpty == ACTIVE)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

/** \brief Devuelve el ID que fue ingresado
 *
 * \return el int del ID
 *
 */

 static int newID()
{
    static int id=MAX;

    id ++;

    return id;
}

int findEmployeeById(sEmployee* arrayEmployees, int lenght, int id)
{
    int i;
    for(i=0; i<lenght; i++)
    {
        if(arrayEmployees[i].id == id && arrayEmployees[i].isEmpty == 0)
        {
            return i;
            break;
        }
    }
    return EMPTY;
}

int addEmployee(sEmployee* arrayEmployees, int lenght, int auxID, char auxName[], char auxLastName[], float auxSalary, int auxSector)
{
    int id=MAX;
    int ret = EMPTY;
    int index = searchFreeSlot(arrayEmployees,lenght);
    int j = findEmployeeById(arrayEmployees, MAX, index);

    if(lenght > 0 && arrayEmployees != NULL)
    {
        if(index != EMPTY)
        {
            if(arrayEmployees[j].isEmpty==0)
            {
                id = newID();
            }
            arrayEmployees[index].id=newID();
            strcpy(arrayEmployees[index].name, auxName);
            strcpy(arrayEmployees[index].lastName, auxLastName);
            arrayEmployees[index].salary = auxSalary;
            arrayEmployees[index].sector = auxSector;
            arrayEmployees[index].isEmpty = NOTEMPTY;
            ret = NOTEMPTY;

            printf("Se ha registrado el usuario.- \n");
            system("pause");
            system("cls");
        }
    }
    return ret;
}

void modifyEmployee(sEmployee* arrayEmployees, int lenght)
{
    char auxName[51];
    char auxLastName[51];
    float auxSalary;
    int auxSector;
    char option;
    int auxId;

    printf("\n Para modificar datos, ingrese el ID del empleado:  \n");
    scanf("%d", &auxId);
    int idEmployee=findEmployeeById(arrayEmployees, MAX, auxId);
    if (idEmployee>0)
    {
        printf("\n Se ha encontrado el ID, modifique a continuacion: \n");

        printf("\n Ingrese nombre: \n");
        scanf("%s", auxName);
        printf("\n Ingrese  apellido: \n");
        scanf("%s", auxLastName);
        printf("\n Ingrese sueldo: \n");
        scanf("%f", &auxSalary);
        printf("\n Ingrese sector: \n");
        scanf("%d", &auxSector);
        printf("\n Confirmar Cambios: s/n (s si, n no)\n");
        option=getChar("");
        switch(option)
        {
        case 's':
            strcpy(arrayEmployees[idEmployee].name, auxName);
            strcpy(arrayEmployees[idEmployee].lastName, auxLastName);
            arrayEmployees[idEmployee].salary = auxSalary;
            arrayEmployees[idEmployee].sector = auxSector;
            printf("\n La modificacion se ha realizado con exito.\n");
            system("pause");
            system("cls");
            break;
        case 'n':
            printf("\n Se ha cancelado el proceso.\n");
            system("pause");
            system("cls");
            break;
        default:
            printf("\n Error. Ingrese una opcion valida.\n");
            break;
        }
    }
    else
    {
        printf ("\n Error. ID no existente.- \n");
        system ("pause");
        system("cls");
    }
}

int sortEmployees(sEmployee* arrayEmployees, int quantity)
{
    int retorno = EMPTY;
    sEmployee aux;
    int i;
    int j;
    if(quantity > 0 && arrayEmployees != NULL)
    {
        for(i=0; i<quantity -1 ; i++)
        {
            for(j=i+1; j<quantity; j++)
            {
                if(strcmp(arrayEmployees[j].lastName, arrayEmployees[i].lastName) < 0)
                {
                    aux = arrayEmployees[i];
                    arrayEmployees[i] = arrayEmployees[j];
                    arrayEmployees[j] = aux;
                }
                else if(strcmp(arrayEmployees[j].lastName, arrayEmployees[i].lastName) == 0 && arrayEmployees[j].sector < arrayEmployees[i].sector)
                {
                    aux = arrayEmployees[i];
                    arrayEmployees[i] = arrayEmployees[j];
                    arrayEmployees[j] = aux;
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}

int printEmployees(sEmployee* arrayEmployees, int quantity)
{
    int ret = EMPTY;
    int i;
    printf("\n%3s %11s %10s %15s %15s \n", "ID","NOMBRE","APELLIDO","SUELDO","SECTOR");
    for(i = 0; i < quantity; i++)
    {
        if(arrayEmployees[i].isEmpty == 0)
        {
            printf("%3d %10s %10s %15.2f %12d\n", arrayEmployees[i].id, arrayEmployees[i].name, arrayEmployees[i].lastName, arrayEmployees[i].salary, arrayEmployees[i].sector);
        }
    }
    ret = NOTEMPTY;
    return ret;
}

void averageSalary(sEmployee arrayEmployees[], int lenght)
{
    float average = 0;
    float total = 0;
    int accountEmployees = 0;
    int highestSalary = 0;
    int i;

    for(i=0; i<lenght; i++)
    {
        if(arrayEmployees[i].isEmpty == 0)
        {
            accountEmployees++;
            total= total + arrayEmployees[i].salary;
        }
    }
    average = total/accountEmployees;

    for(i=0; i<lenght; i++)
    {
        if(arrayEmployees[i].isEmpty == 0)
        {
            if(arrayEmployees[i].salary > average)
            {
                highestSalary++;
            }
        }
    }
    printf("\n SALARIOS: \n");
    printf("\n TOTAL: %.2f\n", total);
    printf("\n PROMEDIO: %.2f\n", average);
    printf("\n Cantidad de empleados que superan el salario promedio: %d\n", highestSalary);
}

 int removeEmployee(sEmployee* arrayEmployees, int lenght, int id)
 {
    int ret = EMPTY;
    int auxId;
    char opcion;

    printf("\n Ingrese el ID del empleado a dar de baja: \n");
    scanf("%d", &auxId);
    int idEmployee=findEmployeeById(arrayEmployees, MAX, auxId);
    if (idEmployee>=0)
    {
        printf("\n Confirmar baja de empleado: s/n (s si, n no)\n");
        opcion=getChar("");
        switch(opcion)
        {
        case 's':
            arrayEmployees[idEmployee].isEmpty = 1;
            printf("\n La baja se ha realizado satisfactoriamente.\n");
            system("pause");
            system("cls");
            break;
        case 'n':
            printf("\n Se ha cancelado la funcion de baja. \n");
            system("pause");
            system("cls");
            break;
        default:
            printf("\n Error. La opcion ingresada es invalida.\n");
            break;
        }
    }
    else
    {
        printf ("\n El ID ingresado es invalido.\n");
        system ("pause");
        system("cls");
    }

    return ret;
}
