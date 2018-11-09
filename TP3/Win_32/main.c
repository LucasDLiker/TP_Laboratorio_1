#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaEmpleadosBinario = ll_newLinkedList();

    do{
        option = menuOptions();
        switch(option)
        {
            case 1:
                if (listaEmpleados==NULL)
                {
                  printf("Error. No se ha podido cargar la lista\n");
                }
                else
                {
                  controller_loadFromText("data.csv",listaEmpleados);
                  printf("\nLa carga de datos de los empleados (TEXTO) ha sido exitosa.\n");
                }
                break;
            case 2:
                if (listaEmpleadosBinario == NULL)
                {
                    printf("Error. No se ha podido cargar la lista\n");
                }
                else
                {
                   controller_loadFromBinary("data.bin", listaEmpleadosBinario);
                   //printf("\nLa carga de datos de los empleados (BINARIO) ha sido exitosa.\n");
                }

                break;
            case 3:
                    controller_addEmployee(listaEmpleados);
                break;
            case 4:

                break;
            case 5:

                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:

                break;
            case 8:

                break;
            case 9:

                break;
            case 10:
            printf("auf wiedersehen/Hasta Pronto...");
                break;
            default:
            printf("Error. Ingrese una opcion valida");
            break;
        }

            system("pause");
            system("cls");

    }while(option != 10);

    getch();
    return 0;
}
