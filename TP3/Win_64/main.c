#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

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
    char seguir = 'y';
    int flagFile = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        switch(controller_menu())
        {
            case 1:
                if(controller_loadFromText("data.csv",listaEmpleados) == 1){
                    flagFile = 1;
                }
                break;
            case 2:
                if(controller_loadFromBinary("data.bin",listaEmpleados) == 1){
                    flagFile = 1;
                }
                break;
            case 3:
                if(controller_addEmployee(listaEmpleados) == 0){
                    flagFile = 1;
                }
                break;
            case 4:
                if(flagFile == 0){
                    printf("No hay empleados o datos cargados. \n");
                }else{
                    controller_editEmployee(listaEmpleados);
                }
                break;
            case 5:
                 if(flagFile == 0){
                    printf("No hay empleados o datos cargados. \n");
                }else{
                    controller_removeEmployee(listaEmpleados);
                }
                break;
            case 6:
                if(flagFile == 0){
                    printf("No hay empleados o datos cargados. \n");
                }else{
                    controller_ListEmployee(listaEmpleados);
                }
                break;
            case 7:
                 if(flagFile == 0){
                    printf("No hay empleados o datos cargados. \n");
                }else{
                    controller_sortEmployee(listaEmpleados);
                }
                break;
            case 8:
                 if(flagFile == 0){
                    printf("No hay empleados o datos cargados. \n");
                }else{
                    controller_saveAsText("data.csv",listaEmpleados);
                }
                break;
            case 9:
                 if(flagFile == 0){
                    printf("No hay empleados o datos cargados. \n");
                }else{
                    controller_saveAsBinary("data.bin",listaEmpleados);
                }
                break;
            case 10:
                seguir = 'n';
                printf("\nAprobame plox \n");
                break;
            default:
                printf("Opcion invalida, reingrese Opcion \n");
                break;
        }
      system("pause");
    }while(seguir != 'n');
    ll_deleteLinkedList(listaEmpleados);
    return 0;
}
