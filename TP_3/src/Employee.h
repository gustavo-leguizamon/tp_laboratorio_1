
#include "LinkedList.h"

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(int id, char* name, int hoursWorked, float salary);
Employee* employee_newParametrosStr(char* idStr, char* nameStr, char* hoursWorkedStr, char* salaryStr);
int employee_delete(Employee* pEmployee);

int employee_setId(Employee* this, int id);
int employee_getId(Employee* this, int* pId);

int employee_setNombre(Employee* this, char* name);
int employee_getNombre(Employee* this, char* pName);

int employee_setHorasTrabajadas(Employee* this, int hoursWorked);
int employee_getHorasTrabajadas(Employee* this, int* pHoursWorked);

int employee_setSueldo(Employee* this, float salary);
int employee_getSueldo(Employee* this, float* pSalary);

void printHeaderEmployee();

int showEmployee(Employee* pEmployee);

int findHighestId(LinkedList* pArrayLinkedList, int* pId);



/**
 * @brief Charge data for new employee
 *
 * @param pName char*
 * @param pHoursWorked int*
 * @param pSalary float*
 * @return int 0: Error in parameters - 1: Ok
 */
int chargeDataEmployee(char* pName, int* pHoursWorked, float* pSalary);

/**
 * @brief Charge name for employee
 *
 * @param pName char*
 * @param len int
 * @return int 0: Error in parameters - 1: Ok
 */
int chargeName(char* pName, int len);


/**
 * @brief Charge hours worked for employee
 *
 * @param pHoursWorked int*
 * @return int 0: Error in parameters - 1: Ok
 */
int chargeHoursWorked(int* pHoursWorked);


/**
 * @brief Charge salary for employee
 *
 * @param pSalary float*
 * @return int 0: Error in parameters - 1: Ok
 */
int chargeSalary(float* pSalary);


/**
 * @brief Edit name of employee
 *
 * @param pEmployee Employee*
 * @param len int
 * @return int 0: Error in parameters - 1: Ok - 2: Error to get new name - 3: Error to set new name
 */
int employee_editName(Employee* pEmployee, int len);


/**
 * @brief Edit hours worked of employee
 *
 * @param pEmployee Employee*
 * @return int 0: Error in parameters - 1: Ok - 2: Error to get new hours - 3: Error to set new hours
 */
int employee_editHoursWorked(Employee* pEmployee);


/**
 * @brief Edit salary of employee
 *
 * @param pEmployee Employee*
 * @return int 0: Error in parameters - 1: Ok - 2: Error to get new salary - 3: Error to set new salary
 */
int employee_editSalary(Employee* pEmployee);


/**
 * @brief Order employees by name
 *
 * @param pEmployeeA void*
 * @param pEmployeeB void*
 * @return int -2: Error in parameters - -1: EmployeeA greater than EmployeeB - 0: EmployeeA equal to EmployeeB - 1: EmployeeB greater than EmployeeA
 */
int employee_orderByName(void* pEmployeeA, void* pEmployeeB);


/**
 * @brief Validate if exists an employee with id
 *
 * @param pArrayLinkedList LinkedList*
 * @param id int
 * @return int 0: Not exists - 1: Exists
 */
int employee_validateId(LinkedList* pArrayLinkedList, int id);
int validateName(char* name);
int validateSalary(float salary);
int validateHoursWorked(int hours);

#endif // employee_H_INCLUDED
