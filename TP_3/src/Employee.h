#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr, char* nameStr, char* hoursWorkedStr, char* salaryStr);
void employee_delete();

int employee_setId(Employee* this, int id);
int employee_getId(Employee* this, int* pId);

int employee_setNombre(Employee* this, char* name);
int employee_getNombre(Employee* this, char* pName);

int employee_setHorasTrabajadas(Employee* this, int hoursWorked);
int employee_getHorasTrabajadas(Employee* this, int* pHoursWorked);

int employee_setSueldo(Employee* this, int salary);
int employee_getSueldo(Employee* this, int* pSalary);

int showEmployee(Employee* pEmployee);

#endif // employee_H_INCLUDED
