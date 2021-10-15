#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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


int findEmployeeById(Employee* list, int len, int id){
	int indexEmployee = -1;

	if (list != NULL && len > 0){
		for (int i = 0; i < len; i++){
			if ((list + i)->id == id){
				indexEmployee = i;
				break;
			}
		}
	}

	return indexEmployee;
}


int removeEmployee(Employee* list, int len, int id){
	int success = -1;
	int indexEmployee;
	char confirmRemove;

	if (list != NULL && len > 0){
		puts("     *** BAJA EMPLEADO ***          ");

		indexEmployee = findEmployeeById(list, len, id);
		if (indexEmployee == -1){
			printf("No existe empleado con id: %d\n", id);
		}
		else{
			puts("    *** EMPLEADO ***     ");
			puts("-----------------------------------");
			puts("id     apellido    nombre   salario     sector");
			puts("-----------------------------------");
			printEmployee(*(list + indexEmployee));
			getChar("Confirma BAJA? (s)i, (n)o", &confirmRemove);
			confirmRemove = tolower(confirmRemove);
			while (confirmRemove != 's' && confirmRemove != 'n'){
				puts("Opcion no valida. Ingrese s para indicar SI o n para indicar NO");
				getChar("Confirma BAJA? (s)i, (n)o", &confirmRemove);
				confirmRemove = tolower(confirmRemove);
			}

			if (confirmRemove == 's'){
				(list + indexEmployee)->isEmpty = EMPTY;
				success = 0;
			}
			else{
				puts("Baja cancelada por el usuario");
			}
		}
	}

	return success;
}


int getID(void){
	int id;
	getInt("Ingrese el numero de ID: ", &id);
	return id;
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



int chargeDataEmployee(int* pId, char pName[], char pLastName[], float* pSalary, int* pSector){
	int success = 0;

	if (pId != NULL && pName != NULL && pLastName != NULL && pSalary != NULL && pSector != NULL){
		puts("     *** ALTA EMPLEADO ***          ");
		*pId += 1;
		getString("Ingrese nombre: ", pName, 51);
		getString("Ingrese apellido: ", pLastName, 51);
		getFloat("Ingrese salario: ", pSalary);

		while (*pSalary < 0){
			getFloat("Ingrese salario mayor a cero: ", pSalary);
		}

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
		puts("    *** LISTA DE EMPLEADOS ***     ");
		puts("-----------------------------------");
		puts("id     apellido    nombre   salario     sector");
		puts("-----------------------------------");

		for (int i = 0; i < length; i++){
			if (!(list + i)->isEmpty){
				printEmployee(*(list + i));
			}
		}

		success  = 1;
	}

	return success;
}
