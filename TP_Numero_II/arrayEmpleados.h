#define EMPTY -1
#define NOTEMPTY 0
#define ACTIVE 1
#define INACTIVE 0
#define MAX 1000


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

/** \brief Funcion utilizada para seleccionar una opcion del menu

 * \return opcion elegida
 *
 */

int menuOptions();

/** \brief Funcion que indica que todas las posiciones del vector estan vacias
 *
 * \param sEmployee* es un puntero al vector de empleados
 * \param lenght es el largo del vector
 * \return (-1) si el puntero (NULL) o la lenght tienen error. 0 (NOTEMPTY) si no hay error
 *
 */

int initEmployees(sEmployee* arrayEmployees, int lenght);

/** \brief Funcion que obtiene un espacio libre del vector que servira en la funcion de alta
 *
 * \param sEmployee* es un puntero al vector de empleados
 * \param lenght es el largo del vector
 * \return (-1) si el puntero (NULL) o la lenght tienen error. Retorna (i) si no hay error
 */

int searchFreeSlot(sEmployee* arrayEmployees, int lenght);

/** \brief Funcion que sirve para encontrar un empleado via id
 *
 * \param sEmployee* es un puntero al vector de empleados
 * \param lenght es el largo del vector
 * \param recibe el parametro del id
 * \return la posicion del empleado
 *
 */

int findEmployeeById(sEmployee* arrayEmployees, int lenght, int id);

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

int addEmployee(sEmployee* arrayEmployees, int lenght, int auxID, char auxName[], char auxLastName[], float auxSalary, int auxSector);

/** \brief Busca un ID existente para modificar los datos que el usuario quiera
 *
 * \param arrayEmployees
 * \param lenght
 * \return void
 *
 */

void modifyEmployee(sEmployee* arrayEmployees, int lenght);

/** \brief Funcion que ordena los empleados por apellido
 *
 * \param recibe el vector
 * \param recibe la cantidad
 * \return (-1) si el puntero (NULL) o la lenght tienen error. 0 (NOTEMPTY) si no hay error
 *
 */

int sortEmployees(sEmployee* arrayEmployees, int quantity);

/** \brief Muestra la lista de empleados con sus respectivos sueldos, sectores e IDS
 *
 * \param recibe el vector
 * \param recibe la cantidad
 * \return (-1) si el puntero (NULL) o la lenght tienen error. 0 (NOTEMPTY) si no hay error
 *
 */

int printEmployees(sEmployee* arrayEmployees, int quantity);

/** \brief Funcion que calcula el promedio de salarios
 *
 * \param vector de empleados
 * \param largo del vector
 * \return void
 *
 */

void averageSalary(sEmployee arrayEmployees[], int lenght);

/** \brief Funcion que se utiliza para remover/dar de baja a un empleado
 *
 * \param vector
 * \param tamaño
 * \param id
 * \return espacio libre
 *
 */

int removeEmployee(sEmployee* arrayEmployees, int lenght, int id);

