
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

/**
 * @brief Generate a new struct Employee in memory
 *
 * @return Employee* pointer to employee or NULL if not has been created
 */
Employee* employee_new();


/**
 * @brief Generate a new struct Employee in memory passing parameters of fields
 *
 * @param id int
 * @param name char*
 * @param hoursWorked int
 * @param salary float
 * @return Employee* pointer to employee or NULL if not has been created
 */
Employee* employee_newParametros(int id, char* name, int hoursWorked, float salary);


/**
 * @brief Generate a new struct Employee in memory passing parameters of fields as strings
 *
 * @param idStr char*
 * @param nameStr char*
 * @param hoursWorkedStr char*
 * @param salaryStr char*
 * @return Employee* pointer to employee or NULL if not has been created
 */
Employee* employee_newParametrosStr(char* idStr, char* nameStr, char* hoursWorkedStr, char* salaryStr);


/**
 * @brief Destroy Employee from memory
 *
 * @param pEmployee Employee*
 * @return int 0: Error in parameters - 1: Ok
 */
int employee_delete(Employee* pEmployee);


/**
 * @brief Set a new id for an employee
 *
 * @param this Employee*
 * @param id int
 * @return int 0: Error in parameters - 1: Ok
 */
int employee_setId(Employee* this, int id);


/**
 * @brief Get value of id field from an employee
 *
 * @param this  Employee*
 * @param pId int*
 * @return int 0: Error in parameters - 1: Ok
 */
int employee_getId(Employee* this, int* pId);


/**
 * @brief Set a new name for an employee
 *
 * @param this Employee*
 * @param name char*
 * @return int 0: Error in parameters - 1: Ok
 */
int employee_setNombre(Employee* this, char* name);


/**
 * @brief Get value of name field from an employee
 *
 * @param this Employee*
 * @param pName char*
 * @return int 0: Error in parameters - 1: Ok
 */
int employee_getNombre(Employee* this, char* pName);


/**
 * @brief Set new hours worked for an employee
 *
 * @param this Employee*
 * @param hoursWorked int
 * @return int 0: Error in parameters - 1: Ok
 */
int employee_setHorasTrabajadas(Employee* this, int hoursWorked);


/**
 * @brief Get value of hours worked field from an employee
 *
 * @param this Employee*
 * @param pHoursWorked int*
 * @return int 0: Error in parameters - 1: Ok
 */
int employee_getHorasTrabajadas(Employee* this, int* pHoursWorked);


/**
 * @brief Set a new salary for an employee
 *
 * @param this Employee*
 * @param salary float
 * @return int 0: Error in parameters - 1: Ok
 */
int employee_setSueldo(Employee* this, float salary);


/**
 * @brief Get value of salary field from an employee
 *
 * @param this Employee*
 * @param pSalary float*
 * @return int 0: Error in parameters - 1: Ok
 */
int employee_getSueldo(Employee* this, float* pSalary);


/**
 * @brief Print in console the name of columns
 *
 */
void employee_printHeaderReport();


/**
 * @brief Print in console all values from fields in employee
 *
 * @param pEmployee Employee*
 * @return int 0: Error in parameters - 1: Ok
 */
int employee_showEmployee(Employee* pEmployee);


/**
 * @brief Print in console all employees
 *
 * @param pArrayLinkedList LinkedList*
 * @return int 0: Error in parameters - 1: Ok
 */
int employee_showEmployees(LinkedList* pArrayLinkedList);


/**
 * @brief Search the highest id in the LikedList
 *
 * @param pArrayLinkedList LinkedList*
 * @param pId int*
 * @return int 0: Error in parameters - 1: Ok
 */
int employee_findHighestId(LinkedList* pArrayLinkedList, int* pId);



/**
 * @brief Charge data for new employee
 *
 * @param pName char*
 * @param pHoursWorked int*
 * @param pSalary float*
 * @return int 0: Error in parameters - 1: Ok
 */
int employee_chargeData(char* pName, int* pHoursWorked, float* pSalary);


/**
 * @brief Charge name for employee
 *
 * @param pName char*
 * @param len int
 * @return int 0: Error in parameters - 1: Ok
 */
int employee_chargeName(char* pName, int len);


/**
 * @brief Charge hours worked for employee
 *
 * @param pHoursWorked int*
 * @return int 0: Error in parameters - 1: Ok
 */
int employee_chargeHoursWorked(int* pHoursWorked);


/**
 * @brief Charge salary for employee
 *
 * @param pSalary float*
 * @return int 0: Error in parameters - 1: Ok
 */
int employee_chargeSalary(float* pSalary);


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
 * @brief Function that compares employees by id
 *
 * @param pEmployeeA void*
 * @param pEmployeeB void*
 * @return int -2: Error in parameters - -1: EmployeeA greater than EmployeeB - 0: EmployeeA equal to EmployeeB - 1: EmployeeB greater than EmployeeA
 */
int employee_compareById(void* pEmployeeA, void* pEmployeeB);


/**
 * @brief Function that compares employees by name
 *
 * @param pEmployeeA void*
 * @param pEmployeeB void*
 * @return int -2: Error in parameters - -1: EmployeeA greater than EmployeeB - 0: EmployeeA equal to EmployeeB - 1: EmployeeB greater than EmployeeA
 */
int employee_compareByName(void* pEmployeeA, void* pEmployeeB);


/**
 * @brief Function that compares employees by hours worked
 *
 * @param pEmployeeA void*
 * @param pEmployeeB void*
 * @return int -2: Error in parameters - -1: EmployeeA greater than EmployeeB - 0: EmployeeA equal to EmployeeB - 1: EmployeeB greater than EmployeeA
 */
int employee_compareByHoursWorked(void* pEmployeeA, void* pEmployeeB);


/**
 * @brief Function that compares employees by salary
 *
 * @param pEmployeeA void*
 * @param pEmployeeB void*
 * @return int -2: Error in parameters - -1: EmployeeA greater than EmployeeB - 0: EmployeeA equal to EmployeeB - 1: EmployeeB greater than EmployeeA
 */
int employee_compareBySalary(void* pEmployeeA, void* pEmployeeB);


/**
 * @brief Save last ID used in a single file
 *
 * @param pathIdFile char*
 * @param id int
 * @return int 0: Error in parameters - 1: Ok - 2: Error to save data in file
 */
int employee_saveLastId(char* pathIdFile, int id);


/**
 * @brief Restore last id saved to use it
 *
 * @param pathIdFile char*
 * @param pId int*
 * @return int 0: Error in parameters - 1: Ok - 2: Error to read data from file
 */
int employee_restoreLastId(char* pathIdFile, int* pId);


/**
 * @brief Validate if exists an employee with id
 *
 * @param pArrayLinkedList LinkedList*
 * @param id int
 * @return int 0: Not exists - 1: Exists
 */
int employee_validateId(LinkedList* pArrayLinkedList, int id);


/**
 * @brief Validate a name input by user from console
 *
 * @param name char*
 * @return int 0: name not valid - 1: name valid
 */
int employee_validateInputName(char* name);


/**
 * @brief Validate a salary input by user from console
 *
 * @param salary float
 * @return int 0: salary not valid - 1: salary valid
 */
int employee_validateInputSalary(float salary);


/**
 * @brief Validate an hours worked input by user from console
 *
 * @param hours int
 * @return int 0: hours not valid - 1: hours valid
 */
int employee_validateInputHoursWorked(int hours);

#endif // employee_H_INCLUDED
