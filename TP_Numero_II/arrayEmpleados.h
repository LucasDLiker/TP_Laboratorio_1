#ifndef arrayEmpleados

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}sEmployee;
#endif //arrayEmpleados

int menuOptions();
int initEmployees(sEmployee* arrayEmployees, int lenght);
int searchFreeSlot(sEmployee* arrayEmployees, int lenght);
int findEmployeeById(sEmployee* arrayEmployees, int lenght, int id);
int addEmployee(sEmployee* arrayEmployees, int lenght, int auxID, char auxName[], char auxLastName[], float auxSalary, int auxSector);
void modifyEmployee(sEmployee* arrayEmployees, int lenght);
int sortEmployees(sEmployee* arrayEmployees, int quantity);
int printEmployees(sEmployee* arrayEmployees, int quantity);
void averageSalary(sEmployee arrayEmployees[], int lenght);
int removeEmployee(sEmployee* arrayEmployees, int lenght, int id);

