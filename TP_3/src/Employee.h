
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


int validateName(char* name);
int validateSalary(float salary);
int validateHoursWorked(int hours);

#endif // employee_H_INCLUDED
