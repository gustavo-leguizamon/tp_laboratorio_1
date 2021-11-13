#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Employee.h"
#include "myString.h"
#include "input.h"



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


Employee* employee_newParametrosStr(char* idStr, char* nameStr, char* hoursWorkedStr, char* salaryStr){
	/*
	Employee* newEmployee;

	newEmployee = employee_new();
	if (newEmployee != NULL){
		if (!(employee_setId(newEmployee, atoi(idStr)) &&
			  employee_setNombre(newEmployee, nameStr) &&
			  employee_setHorasTrabajadas(newEmployee, atoi(hoursWorkedStr)) &&
			  employee_setSueldo(newEmployee, atof(salaryStr)))){
			free(newEmployee);
			newEmployee = NULL;
		}
	}

	return newEmployee;
	*/

	return employee_newParametros(atoi(idStr), nameStr, atoi(hoursWorkedStr), atof(salaryStr));
}

Employee* employee_newParametros(int id, char* name, int hoursWorked, float salary){
	Employee* newEmployee;

	newEmployee = employee_new();
	if (newEmployee != NULL){
		if (!(employee_setId(newEmployee, id) &&
			  employee_setNombre(newEmployee, name) &&
			  employee_setHorasTrabajadas(newEmployee, hoursWorked) &&
			  employee_setSueldo(newEmployee, salary))){
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

int employee_setSueldo(Employee* this, float salary){
	int success = 0;

	if (this != NULL && salary > 0){
		this->sueldo = salary;
		success = 1;
	}

	return success;
}
int employee_getSueldo(Employee* this, float* pSalary){
	int success = 0;

	if (this != NULL && pSalary != NULL){
		*pSalary = this->sueldo;
		success = 1;
	}

	return success;
}


void printHeaderEmployee(){
	printf("| %4s | %20s | %4s | %9s |\n", "ID", "NOMBRE", "HORAS", "SALARIO");
}

int showEmployee(Employee* pEmployee){
	int success = 0;
	int id;
	char name[128];
	int hoursWorked;
	float salary;

	if (pEmployee != NULL &&
		employee_getId(pEmployee, &id) &&
		employee_getNombre(pEmployee, name) &&
		employee_getHorasTrabajadas(pEmployee, &hoursWorked) &&
		employee_getSueldo(pEmployee, &salary)){
		printf("| %4d | %20s | %5d | $%8.2f |\n", id, name, hoursWorked, salary);
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

int chargeDataEmployee(char* pName, int* pHoursWorked, float* pSalary){
	int result = 0;

	if (pName != NULL && pHoursWorked != NULL && pSalary != NULL){
		/*
		getString("Ingrese nombre: ", pName, 128);
		while (!validateName(pName)){
			puts("El nombre no es valido");
			getString("Ingrese nombre: ", pName, 128);
		}
		capitalize(pName);
		*/
		//chargeName(pName, 128);

		/*
		getInt("Ingrese horas trabajadas: ", pHoursWorked);
		while (!validateHoursWorked(*pHoursWorked)){
			puts("Las horas ingresadas no son validas");
			getInt("Ingrese horas trabajadas: ", pHoursWorked);
		}
		*/
		//chargeHoursWorked(pHoursWorked);

		/*
		getFloat("Ingrese salario: ", pSalary);
		while (!validateSalary(*pSalary)){
			puts("El salario ingresado no es valido");
			getFloat("Ingrese salario: ", pSalary);
		}
		*/
		//chargeSalary(pSalary);

		result = chargeName(pName, 128) && chargeHoursWorked(pHoursWorked) && chargeSalary(pSalary);
	}

	return result;
}


int chargeName(char* pName, int len){
	int result = 0;

	if (pName != NULL && len > 0){
		getString("Ingrese nombre: ", pName, len);
		while (!validateName(pName)){
			puts("El nombre no es valido");
			getString("Ingrese nombre: ", pName, len);
		}
		capitalize(pName);
		result = 1;
	}

	return result;
}


int chargeHoursWorked(int* pHoursWorked){
	int result = 0;

	if (pHoursWorked != NULL){
		getInt("Ingrese horas trabajadas: ", pHoursWorked);
		while (!validateHoursWorked(*pHoursWorked)){
			puts("Las horas ingresadas no son validas");
			getInt("Ingrese horas trabajadas: ", pHoursWorked);
		}
		result = 1;
	}

	return result;
}


int chargeSalary(float* pSalary){
	int result = 0;

	if (pSalary != NULL){
		getFloat("Ingrese salario: ", pSalary);
		while (!validateSalary(*pSalary)){
			puts("El salario ingresado no es valido");
			getFloat("Ingrese salario: ", pSalary);
		}
		result = 1;
	}

	return result;
}


int employee_editName(Employee* pEmployee, int len){
	int result = 0;
	char name[len];

	if (pEmployee != NULL){
		result = 1;
		if (chargeName(name, len)){
			if (!employee_setNombre(pEmployee, name)){
				result = 3;
			}
		}
		else{
			result = 2;
		}
	}

	return result;
}


int employee_editHoursWorked(Employee* pEmployee){
	int result = 0;
	int hoursWorked;

	if (pEmployee != NULL){
		result = 1;
		if (chargeHoursWorked(&hoursWorked)){
			if (!employee_setHorasTrabajadas(pEmployee, hoursWorked)){
				result = 3;
			}
		}
		else{
			result = 2;
		}
	}

	return result;
}


int employee_editSalary(Employee* pEmployee){
	int result = 0;
	float salary;

	if (pEmployee != NULL){
		result = 1;
		if (chargeSalary(&salary)){
			if (!employee_setSueldo(pEmployee, salary)){
				result = 3;
			}
		}
		else{
			result = 2;
		}
	}

	return result;
}




int employee_validateId(LinkedList* pArrayLinkedList, int id){
	int index = -1;
	Employee* auxEmployee = NULL;

	if (pArrayLinkedList != NULL){
		for (int i = 0; i < ll_len(pArrayLinkedList); i++){
			auxEmployee = (Employee*)ll_get(pArrayLinkedList, i);
			if (auxEmployee->id == id){
				index = i;
				break;
			}
		}
	}

	return index;
}

int validateName(char* name){
	int valid = 1;
	int index = 1;

	if (name != NULL){
		while (name[index] != CHAR_NULL){
			if (!isalpha(name[index]) && name[index] != ' '){
				valid = 0;
				break;
			}
			index++;
		}
	}

	return valid;
}

int validateSalary(float salary){
	return salary > 0;
}

int validateHoursWorked(int hours){
	return hours > 0;
}
