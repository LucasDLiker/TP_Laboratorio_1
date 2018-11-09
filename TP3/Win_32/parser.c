#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;

    char id[11];
    char nombre[51];
    char horasTrabajadas[11];
    char sueldo [20];

    while(!feof(pFile))
    {
        auxEmployee=employee_new();
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id, nombre, horasTrabajadas, sueldo);
        auxEmployee=employee_newParametros(id,nombre,horasTrabajadas,sueldo);
        ll_add(pArrayListEmployee, auxEmployee);
        printf("%d %s %d %d\n", auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
    }
    free(pFile);
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee auxEmployee;
    int i = 0;
    fread(&auxEmployee, sizeof(Employee), 1, pFile);///Al ser archivo binario lo abr con fread
    while(!feof(pFile))
    {
        Employee* empleado = employee_new();
        employee_setId(empleado,auxEmployee.id);
        employee_setHorasTrabajadas(empleado,auxEmployee.horasTrabajadas);
        employee_setNombre(empleado,auxEmployee.nombre);
        employee_setSueldo(empleado,auxEmployee.sueldo);

        i ++;
        ll_add(pArrayListEmployee, empleado);
        fread(&auxEmployee, sizeof(Employee), 1, pFile);
    }

    printf("Empleados cargados: %d\n", i);
    return 1;
}

