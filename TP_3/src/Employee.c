#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Employee.h"



Employee* employee_new(){
	Employee* newEmployee;

	newEmployee = (Employee*)malloc(sizeof(Employee)); //calloc(cantidad, sizeof) //inicializa estrustura en vacios
	if (newEmployee != NULL){
		newEmployee->id = 0;
		strcpy(newEmployee->nombre, "");
		newEmployee->horasTrabajadas = 0;
		newEmployee->sueldo = 0;
	}

	return newEmployee;
}


Employee* employee_newParametros(char* idStr, char* nameStr, char* hoursWorkedStr, char* salaryStr){
	Employee* newEmployee;

	newEmployee = employee_new();
	if (newEmployee != NULL){
		if (!(employee_setId(newEmployee, atoi(idStr)) &&
			  employee_setNombre(newEmployee, nameStr) &&
			  employee_setHorasTrabajadas(newEmployee, atoi(hoursWorkedStr)) &&
			  employee_setSueldo(newEmployee, atoi(salaryStr)))){
			free(newEmployee);
			newEmployee = NULL;
		}
	}

	return newEmployee;
}


int employee_delete(Employee* pEmployee){
	int result = 0;

	if (pEmployee != NULL){
		free(pEmployee);
		result = 1;
	}

	return result;
}



int employee_setId(Employee* this, int id){
	int success = 0;

	if (this != NULL && id > 0){
		this->id = id;
		success = 1;
	}

	return success;
}
int employee_getId(Employee* this, int* pId){
	int success = 0;

	if (this != NULL && pId != NULL){
		*pId = this->id;
		success = 1;
	}

	return success;
}

int employee_setNombre(Employee* this, char* name){
	int success = 0;

	if (this != NULL && name != NULL && strlen(name) > 0 && strlen(name) < 128){
		strcpy(this->nombre, name);
		success = 1;
	}

	return success;
}
int employee_getNombre(Employee* this, char* pName){
	int success = 0;

	if (this != NULL && pName != NULL){
		strcpy(pName, this->nombre);
		success = 1;
	}

	return success;
}

int employee_setHorasTrabajadas(Employee* this, int hoursWorked){
	int success = 0;

	if (this != NULL && hoursWorked >= 0){
		this->horasTrabajadas = hoursWorked;
		success = 1;
	}

	return success;
}
int employee_getHorasTrabajadas(Employee* this, int* pHoursWorked){
	int success = 0;

	if (this != NULL && pHoursWorked != NULL){
		*pHoursWorked = this->horasTrabajadas;
		success = 1;
	}

	return success;
}

int employee_setSueldo(Employee* this, int salary){
	int success = 0;

	if (this != NULL && salary > 0){
		this->sueldo = salary;
		success = 1;
	}

	return success;
}
int employee_getSueldo(Employee* this, int* pSalary){
	int success = 0;

	if (this != NULL && pSalary != NULL){
		*pSalary = this->sueldo;
		success = 1;
	}

	return success;
}


int showEmployee(Employee* pEmployee){
	int success = 0;
	int id;
	char name[128];
	int hoursWorked;
	int salary;

	if (pEmployee != NULL &&
		employee_getId(pEmployee, &id) &&
		employee_getNombre(pEmployee, name) &&
		employee_getHorasTrabajadas(pEmployee, &hoursWorked) &&
		employee_getSueldo(pEmployee, &salary)){
		printf("| %4d | %20s | %5d | $%6d |\n", id, name, hoursWorked, salary);
	}

	return success;
}

int findHighestId(LinkedList* pArrayLinkedList, int* pId){
	int result = 0;
	int highestId = 0;
	Employee* auxEmployee = NULL;

	if (pArrayLinkedList != NULL && pId != NULL){
		for (int i = 0; i < ll_len(pArrayLinkedList); i++){
			auxEmployee = ll_get(pArrayLinkedList, i);
			if (auxEmployee->id > highestId){
				highestId = auxEmployee->id;
			}
		}

		*pId = highestId + 1;
		result = 1;
	}

	return result;
}
