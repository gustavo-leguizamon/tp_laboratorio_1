#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"
#include "ArrayEmployees.h"

int initEmployees(Employee* list, int len){
	int success = 0;

	if (list != NULL && len > 0){
		for (int i = 0; i < len; i++){
			(list + i)->isEmpty = EMPTY;
		}

		success = 1;
	}

	return success;
}

int findFreeSpace(Employee* list, int len){
	int posFreeSpace = -1;

	if (list != NULL && len > 0){
		for (int i = 0; i < len; i++){
			if ((list + i)->isEmpty){
				posFreeSpace = i;
				break;
			}
		}
	}

	return posFreeSpace;
}


int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector){
	int success = -1;
	int freeIndex;
	Employee auxEmployee;

	if (list != NULL && len > 0 && name != NULL && lastName != NULL){
		freeIndex = findFreeSpace(list, len);

		if (freeIndex >= 0){
			auxEmployee.id = id;
			strcpy(auxEmployee.name, name);
			strcpy(auxEmployee.lastName, lastName);
			auxEmployee.salary = salary;
			auxEmployee.sector = sector;
			auxEmployee.isEmpty = FILL;

			*(list + freeIndex) = auxEmployee;

			success = 0;
		}
	}

	return success;
}

int chargeDataEmployee(int* pId, char pName[], char pLastName[], float* pSalary, int* pSector){
	int success = 0;

	if (pId != NULL && pName != NULL && pLastName != NULL && pSalary != NULL && pSector != NULL){
		*pId += 1;
		getString("Ingrese nombre: ", pName, 51);
		getString("Ingrese apellido: ", pLastName, 51);
		getFloat("Ingrese salario: ", pSalary);
		getInt("Ingrese sector: ", pSector);

		success = 1;
	}

	return success;
}

void printEmployee(Employee employee){
	printf("%d     %s      %s      %.2f      %d\n", employee.id,
													employee.lastName,
													employee.name,
													employee.salary,
													employee.sector);
}

int thereIsAnyEmployee(Employee* list, int len){
	int any = 0;

	if (list != NULL && len > 0){
		for (int i = 0; i < len; i++){
			if (!(list + i)->isEmpty){
				any = 1;
				break;
			}
		}
	}

	return any;
}

int printEmployees(Employee* list, int length)
{
	int success = 0;

	if (list != NULL && length > 0){
		printf("    *** LISTA DE EMPLEADOS ***     \n");
		printf("-----------------------------------\n");
		printf("id     apellido    nombre   salario     sector\n");
		printf("-----------------------------------\n");

		for (int i = 0; i < length; i++){
			if (!(list + i)->isEmpty){
				printEmployee(*(list + i));
			}
		}

		success  = 1;
	}

	return success;
}
