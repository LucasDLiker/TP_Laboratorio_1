#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

int controller_menu(){
    int option = -1;
        system("cls");
        printf("\n\t -Trabajo Practico Nro 3: LinkedList- \n\t\tSelene Abraldez 1 A \n\n");
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto). \n");
        printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario). \n");
        printf("3. Alta de empleado \n");
        printf("4. Modificar datos de empleado \n");
        printf("5. Baja de empleado \n");
        printf("6. Listar empleados \n");
        printf("7. Ordenar empleados \n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto). \n");
        printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario). \n");
        printf("10. Salir \n");
        option = getValidInt("\n\t*Seleccione  una opcion: ", "Opcion no valida, reintente", 0, 10);
    return option;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    char crear = 'n';
    FILE* listaFT;
    if((listaFT=fopen(path, "r+")) == NULL){
        printf("No se ha encontrado el archivo. ");
        crear = getValidYesNoChar("Desea crealo? y/n: ", "Opcion invalida. ");
        if(crear == 'y'){
            if ((listaFT=fopen(path,"w+"))==NULL){
                printf(" Error, no se pudo abrir el archivo.\n");
                return retorno;
                exit(-1);
            }else{
                printf("El archivo ha sido creado sastisfactoriamente. ");
            }
        }else{
            printf("Volviendo al menu\n");
            return 0;
        }
    }else{
        printf("Se encontro el archivo. ");
        parser_EmployeeFromText(listaFT, pArrayListEmployee);
    }
    return 1;         //1 si se encontro y cargo
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
    int retorno = -1;
    char crear = 'n';
    FILE* listaFB;
    if((listaFB=fopen(path, "rb+")) == NULL){
        printf("No se ha encontrado el archivo. ");
        crear = getValidYesNoChar("Desea crealo? y/n: ", "Opcion invalida. ");
        if(crear == 'y'){
            if ((listaFB=fopen(path,"wb+"))==NULL){
                printf(" Error, no se pudo abrir el archivo.\n");
                return retorno;
                exit(-1);
            }else{
                printf("El archivo ha sido creado sastisfactoriamente. ");
            }
        }else{
            printf("Volviendo al menu\n");
            return 0;
        }
    }else{
        printf("Se ha encontrado el archivo. ");
        parser_EmployeeFromBinary(listaFB, pArrayListEmployee);
    }
    return 1;
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
    int retorno = -1;
    Employee* this;
    Employee* aux;
    char idStr[5], nombreStr[128], horasStr[7], sueldoStr[15];
    int idAux, horasAux, sueldoAux;
    int flagId = 0;

    if(pArrayListEmployee != NULL){
        this = employee_new();
        do{
            idAux = getValidInt("Ingrese nueva ID: ", "Dato invalido. ", 0, 10000);
            if((ll_len(pArrayListEmployee))>0){
                for(int j=0; j<ll_len(pArrayListEmployee); j++){
                    aux = (Employee*) ll_get(pArrayListEmployee, j);
                    if(idAux == aux->id){
                        printf("La ID que ha ingresado ya esta en uso, intente con otra.. \n");
                        flagId = 0;
                        break;
                    }else{
                        flagId = 1;
                    }
                }
            }else{
                flagId = 1;
            }
        }while(flagId == 0);
        itoa(idAux, idStr, 10);
        getValidStringLen("Ingrese el nombre: ", "Dato invalido. ", "El dato debe tener menos de 128 caracteres. ",nombreStr, 128);
        horasAux = getValidInt("Ingrese la cantidad de horas: ", "Dato invalido. ", 30, 350);
        itoa(horasAux, horasStr, 10);
        sueldoAux = getValidInt("Ingrese el sueldo: ", "Dato invalido. ", 9000, 9999999);
        itoa(sueldoAux, sueldoStr, 10);

        this = employee_newParametros(idStr, nombreStr, horasStr, sueldoStr);
        ll_add(pArrayListEmployee, this);
        retorno = 0;
    }

    return retorno;
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
    int idM;
    int option;
    char conM = 'n';
    Employee* this;
    Employee* aux;
    int idAux;
    char nombreAux[128];
    int horasAux;
    int sueldoAux;

    printf("Ingrese ID de empleado a modificar: ");
    scanf("%d", &idM);
    for(int i=0; i<ll_len(pArrayListEmployee); i++){
        this = (Employee*) ll_get(pArrayListEmployee, i);
        if(idM == this->id){
            printf("\n  Id\t    Nombre\t  Horas trabajadas\tSueldo\n");
            printf("%4d%14s\t\t%d\t\t%6d\n", this->id,this->nombre,this->horasTrabajadas,this->sueldo);

        do{
            printf("\nIngrese el dato a modificar: \n");
            printf("\t1- Id\n");
            printf("\t2- Nombre\n");
            printf("\t3- Horas trabajadas\n");
            printf("\t4- Sueldo\n");
            printf("\t5- Cancelar\n");
            scanf("%d", &option);

            switch(option){
            case 1:
                idAux = getValidInt("Ingrese nueva ID: ", "Dato invalido. ", 0, 10000);
                for(int j=0; j<ll_len(pArrayListEmployee); j++){
                    aux = (Employee*) ll_get(pArrayListEmployee, j);
                    if(idAux == aux->id){
                        printf("La ID que ha ingresado ya esta en uso. Ingrese otra ID \n");
                    }
                }
                employee_setId(this, idAux);
                printf("Desea seguir haciendo modificaciones sobre este empleado? ");
                conM = getValidYesNoChar("Ingrese y/n: ", "Opcion invalida");
                if(conM == 'n'){
                    return 0;
                }
                break;
            case 2:
                getValidStringLen("Ingrese nuevo nombre: ", "Dato invalido. ", "El dato debe tener menos de 128 caracteres. ", nombreAux, 128);
                employee_setNombre(this, nombreAux);
                printf("Desea seguir haciendo modificaciones sobre este empleado? ");
                conM = getValidYesNoChar("Ingrese y/n: ", "Opcion no valida");
                if(conM == 'n'){
                    return 0;
                }
                break;
            case 3:
                horasAux = getValidInt("Ingrese la nueva cantidad de horas: ", "Dato invalido. ", 30, 350);
                employee_setHorasTrabajadas(this, horasAux);
                printf("Desea seguir haciendo modificaciones sobre este empleado? ");
                conM = getValidYesNoChar("Ingrese y/n: ", "Opcion no valida");
                if(conM == 'n'){
                    return 0;
                }
                break;
            case 4:
                sueldoAux = getValidInt("Ingrese el nuevo sueldo: ", "Dato invalido. ", 9000, 9999999);
                employee_setSueldo(this, sueldoAux);
                printf("Desea seguir haciendo modificaciones sobre este empleado? ");
                conM = getValidYesNoChar("Ingrese y/n: ", "Opcion no valida");
                if(conM == 'n'){
                    return 0;
                }
                break;
            case 5:
                printf("Se ha cancelado la modificacion. \n");
                return 1;
                break;
            default:
                printf("Opcion no valida\n");
                break;
            }
        }while(conM == 'y');
        }
    }
    printf("No se han encontrado datos %s. \n", idM);
    return -1;
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
    int retorno = -1;
    int idEmployee;
    char conEmployee = 'n';
    Employee* this;

    printf("Ingrese el ID del empelado que desea eliminar: ");
    scanf("%d", &idEmployee);
    for(int i=0; i<ll_len(pArrayListEmployee); i++){
        this = (Employee*) ll_get(pArrayListEmployee, i);
        if(idEmployee == this->id){
            printf("\n  Id\t    Nombre\t  Horas trabajadas\tSueldo\n");
            printf("%4d%14s\t\t%d\t\t%6d\n", this->id,this->nombre,this->horasTrabajadas,this->sueldo);
            printf("\nDesea eliminar este empleado? ");
            conEmployee = getValidYesNoChar("Ingrese y/n: ", "Dato invalido. ");
            if(conEmployee != 'y'){
                printf("se ha cancelado la eliminacion\n");
                return 1;
            }else{
                ll_remove(pArrayListEmployee, i);
                printf("El empleado %d ha sido eliminado. \n", idEmployee);
                free(this);
                return 0;
            }
        }
    }
    printf("No se ha encontrado empleado con este ID %d. \n", idEmployee);
    return retorno;
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
    int retorno = -1;
    Employee* this;
    if((ll_len(pArrayListEmployee))>0){
        printf("\n**Id\t    Nombre\t  Horas trabajadas\tSueldo**\n\n");
        for(int i=0; i<ll_len(pArrayListEmployee); i++){
            this = ll_get(pArrayListEmployee, i);

            if(this != NULL){
                printf("%4d%14s\t\t%d\t\t%6d\n", this->id,this->nombre,this->horasTrabajadas,this->sueldo);
            }
        }
    }else{
        printf("El archivo tiene 0 empleados, Puede cargar un archivo (opciones 1, 2) o cargar un nuevo empleado (3). ");
    }
    printf("\n");
    return retorno;
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
    int retorno = -1;
    int option;

    printf("Seleeccionar ordenamiento por: \n");
    printf("\t1- Id\n");
    printf("\t2- Nombre\n");
    printf("\t3- Horas trabajadas\n");
    printf("\t4- Salario\n");
    scanf("%d", &option);

    switch(option){
    case 1:
        ll_sort(pArrayListEmployee, employeeSortById, 0);
        printf("Se han ordenado los empleados por el numero de ID\n");
        break;
    case 2:
        ll_sort(pArrayListEmployee, employeeSortByName, 0);
        printf("Se han ordenado los empleados por su Nombre\n");
        break;
    case 3:
        ll_sort(pArrayListEmployee, employeeSortByHours, 0);
        printf("Se han ordenado los empleados por cantidad de horas trabajadas!\n");
        break;
    case 4:
        ll_sort(pArrayListEmployee, employeeSortBySalary, 0);
        printf("Se han ordenado los empleados por salario\n");
        break;
    default:
        printf("Opcion invalida\n");
        break;
    }
    return retorno;
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
    int retorno = -1;
    Employee* this;
    FILE* lista = fopen(path, "w");

    if(lista==NULL){
        printf("Se produjo un error al guardar\n");
        return retorno;
    }
    fprintf(lista, "id,nombre,horasTrabajadas,sueldo\n");
    if(pArrayListEmployee!=NULL){
        for(int i=0; i<ll_len(pArrayListEmployee); i++){
            this = (Employee*)ll_get(pArrayListEmployee, i);
            fprintf(lista, "%d,%s,%d,%d\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
        }
        printf("El archivo se ha guardado sastisfactoriamente.\n");
        retorno = 1;
    }
    fclose(lista);
    return retorno;
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
    int retorno = -1;
    int len = ll_len(pArrayListEmployee);
    Employee* this;
    FILE* lista = fopen(path, "wb");

    if(lista==NULL){
        printf("Se produjo un error al guardar\n");
        return retorno;
    }
    if(pArrayListEmployee!=NULL){
        for(int i=0; i<len; i++){
            this = (Employee*)ll_get(pArrayListEmployee, i);
            fwrite(this,sizeof(Employee),1,lista);
        }
        printf("El archivo se ha guardado sastisfactoriamente\n");
        retorno = 1;
    }
    fclose(lista);
    return retorno;
}

