#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "funciones.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    pFile=fopen("data.csv", "r");
    parser_EmployeeFromText(pFile, pArrayListEmployee);
    fclose(pFile);

    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile = fopen(path, "rb");
    int estado=0;
    if (pFile != NULL)
    {
        estado = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
    }

    return estado;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
   int estado = 0;
   char auxId[10];
   char auxName[51];
   char auxWorkedHours[51];
   char auxSalary[10];

   Employee* newEmployee;

   if(pArrayListEmployee != NULL)
   {
       getStringNumeros("Ingresar ID del empleado: \n", auxId);
       getValidString("Ingresar el nombre del empleado: ", "Error. Nombre invalido",auxName);
       getStringNumeros("Ingresar horas trabajadas del empleado: ",  auxWorkedHours);
       getStringNumeros("Ingresar el salario del empleado: ",  auxSalary);
       newEmployee = employee_newParametros(auxId, auxName, auxWorkedHours, auxSalary);
       ll_add(pArrayListEmployee, newEmployee);

       estado = 1;
   }
    return estado;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int estado = 0;
    int list = ll_len(pArrayListEmployee);
    int i;
    if(list>0)
    {
        for(i=0;i<list;i++)
        {
            pEmployee=(Employee*)ll_get(pArrayListEmployee, i);
            printf("ID: %d NOMBRE: %s HORAS TRABAJADAS: %d SUELDO: %d\n", pEmployee->id,pEmployee->nombre,pEmployee->horasTrabajadas,pEmployee->sueldo);
        }
    }
    return estado;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

