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
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief hace un parse de los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee){
    Employee* pEmployee;
    char auxID[50], auxNombre[50], auxHoras[50], auxSueldo[50];
    int cant, i = 0;
    cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxID, auxNombre, auxHoras, auxSueldo);
    while(!feof(pFile)){
    cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxID, auxNombre, auxHoras, auxSueldo);
    if(cant == 4)
        {
        pEmployee = employee_newParametros(auxID, auxNombre, auxHoras, auxSueldo);
        ll_add(pArrayListEmployee,pEmployee);
        i++;
        }else
        {
            if(feof(pFile)){
                printf("\n Se han leido los bytes %d", i);
                system("pause");
                break;
            }
        }
    }
    printf("Datos cargados correctamente.\n");
    fclose(pFile);
    return i;
}

/** \brief hace un parse de los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee employee;
    int cant, i = 0;

    cant = fread(&employee, sizeof(Employee), 1, pFile);
    while(!feof(pFile)){
        Employee* pEmployee = employee_new();
        employee_setId(pEmployee,employee.id);
        employee_setHorasTrabajadas(pEmployee,employee.horasTrabajadas);
        employee_setNombre(pEmployee,employee.nombre);
        employee_setSueldo(pEmployee,employee.sueldo);
    if(cant == 1){
            ll_add(pArrayListEmployee, pEmployee);
            fread(&employee, sizeof(Employee), 1, pFile);
            i++;
    }else{
            if(!feof(pFile)){
                printf("\n Se produjo un error con el archivo.");
                system("pause");
                break;
            }else{
                printf("\n Se han leido los bytes %d", i);
            }
        }
    }
    printf("Los datos han sido cargados correctamente.\n");
    fclose(pFile);
    return i;
}
