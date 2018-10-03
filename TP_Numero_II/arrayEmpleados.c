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

/** \brief Funcion que indica que todas las posiciones del vector estan vacias
 *
 * \param sEmployee* es un puntero al vector de empleados
 * \param lenght es el largo del vector
 * \return (-1) si el puntero (NULL) o la lenght tienen error. 0 (NOTEMPTY) si no hay error
 *
 */



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

/** \brief Funcion que obtiene un espacio libre del vector que servira en la funcion de alta
 *
 * \param sEmployee* es un puntero al vector de empleados
 * \param lenght es el largo del vector
 * \return (-1) si el puntero (NULL) o la lenght tienen error. Retorna (i) si no hay error
 */


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
    static int id= MAX;

    id ++;

    return id;
}

/** \brief Funcion que sirve para encontrar un empleado via id
 *
 * \param sEmployee* es un puntero al vector de empleados
 * \param lenght es el largo del vector
 * \param recibe el parametro del id
 * \return la posicion del empleado
 *
 */

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

/** \brief Agrega en un array de empleados existente los valores recibidos como parámetro en la primer
posición libre.
 *
 * \param sEmployee* es un puntero al vector de empleados
 * \param lenght es el largo del vector
 * \param recibe un auxiliar de ID
 * \param recibe un auxiliar de Nombre
 * \param recibe un auxiliar de Apellido
 * \param recibe un auxiliar de Salario
 * \param recibe un auxiliar de Sector
 * \return (-1) si el puntero (NULL) o la lenght tienen error. 0 (NOTEMPTY) si no hay error
 *
 */


int addEmployee(sEmployee* arrayEmployees, int lenght, int auxID, char auxName[], char auxLastName[], float auxSalary, int auxSector)
{
    int id;
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
            arrayEmployees[index].id=id;
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

/** \brief Busca un ID existente para modificar los datos que el usuario quiera
 *
 * \param arrayEmployees
 * \param lenght
 * \return void
 *
 */


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
    if (idEmployee>=0)
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
        printf("Desea confirmar los cambios? S/N\n");
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

/** \brief Funcion que ordena los empleados por apellido
 *
 * \param recibe el vector
 * \param recibe la cantidad
 * \return (-1) si el puntero (NULL) o la lenght tienen error. 0 (NOTEMPTY) si no hay error
 *
 */


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

/** \brief Muestra la lista de empleados con sus respectivos sueldos, sectores e IDS
 *
 * \param recibe el vector
 * \param recibe la cantidad
 * \return (-1) si el puntero (NULL) o la lenght tienen error. 0 (NOTEMPTY) si no hay error
 *
 */


int printEmployees(sEmployee* arrayEmployees, int quantity)
{
    int ret = EMPTY;
    int i;
    printf("\n%5s %25s %25s %8s %3s \n", "ID","NOMBRE","APELLIDO","SUELDO","SECTOR");
    for(i = 0; i < quantity; i++)
    {
        if(arrayEmployees[i].isEmpty == 0)
        {
            printf("%5d %25s %25s %8.2f %3d\n", arrayEmployees[i].id, arrayEmployees[i].name, arrayEmployees[i].lastName, arrayEmployees[i].salary, arrayEmployees[i].sector);
        }
    }
    ret = NOTEMPTY;
    return ret;
}

/** \brief Funcion que calcula el promedio de salarios
 *
 * \param vector de empleados
 * \param largo del vector
 * \return void
 *
 */

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

    printf("\n El total de salarios es: %.2f\n", total);
    printf("\n El promedio de los salarios es: %.2f\n", average);
    printf("\n La cantidad de Empleados que superan el promedio: %d\n", highestSalary);
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 int removeEmployee(sEmployee* arrayEmployees, int lenght, int id)
 {
    int ret = EMPTY;
    int auxId;
    char opcion;

    printf("Ingrese el ID a buscar: \n");
    scanf("%d", &auxId);
    int idEmployee=findEmployeeById(arrayEmployees, MAX, auxId);
    if (idEmployee>=0)
    {
        printf("Confirma la baja? S/N\n");
        opcion=getChar("");
        switch(opcion)
        {
        case 's':
            arrayEmployees[idEmployee].isEmpty = 1;
            printf("Baja realizada con exito.\n");
            system("pause");
            system("cls");
            break;
        case 'n':
            printf("Se cancelo la baja.\n");
            system("pause");
            system("cls");
            break;
        default:
            printf("Ingrese una opcion valida.\n");
            break;
        }
    }
    else
    {
        printf ("ID vacio, intente nuevamente.\n");
        system ("pause");
        system("cls");
    }

    return ret;
}
