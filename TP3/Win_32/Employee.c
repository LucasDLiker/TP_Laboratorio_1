#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"


int menuOptions()
{
    int menuOption;
    fflush(stdin);
    printf("Menu:\n"
     "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
     "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
     "3. Alta de empleado\n"
     "4. Modificar datos de empleado\n"
     "5. Baja de empleado\n"
     "6. Listar empleados\n"
     "7. Ordenar empleados\n"
     "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
     "9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
    "10. Salir\n");
    fflush(stdin);
    scanf("%d", &menuOption);
    return menuOption;
}

Employee* employee_new()
{
    Employee* pEmployee;
    pEmployee=(Employee*)malloc(sizeof(Employee));

    if(pEmployee != NULL)
    {
        pEmployee->id = 0;
        strcpy(pEmployee->nombre , "sinNombre");
        pEmployee->horasTrabajadas = 0;
        pEmployee->sueldo = 0;
    }

    return pEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* auxEmployee;
    auxEmployee=(Employee*)malloc(sizeof(Employee));
    auxEmployee->id=atoi(idStr);
    strcpy(auxEmployee->nombre,nombreStr);
    auxEmployee->horasTrabajadas=atoi(horasTrabajadasStr);
    auxEmployee->sueldo=atoi(sueldoStr);

    return auxEmployee;
}




