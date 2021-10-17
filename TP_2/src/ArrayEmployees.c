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


int sortEmployees(Employee* list, int len, int order){
	int success = -1;
	Employee auxEmployee;

	if (list != NULL && len > 0 && (order == 0 || order == 1)){
		for (int i = 0; i < len - 1; i++){
			for (int j = i + 1; j < len; j++){
				if ((strcmp((list + i)->lastName, (list + j)->lastName) == 1 && order) ||
					(strcmp((list + i)->lastName, (list + j)->lastName) == 0 && (list + i)->sector > (list + j)->sector && order) ||
					(strcmp((list + i)->lastName, (list + j)->lastName) == -1 && !order) ||
					(strcmp((list + i)->lastName, (list + j)->lastName) == 0 && (list + i)->sector < (list + j)->sector && !order)){
					auxEmployee = *(list + i);
					*(list + i) = *(list + j);
					*(list + j) = auxEmployee;
				}
			}
		}

		success = 0;
	}

	return success;
}



int getID(void){
	int id;
	getInt("Ingrese el numero de ID: ", &id);
	return id;
}

Employee* getEmployee(Employee* list, int len, int id){
	Employee* employee = NULL;
	int indexEmployee;

	indexEmployee = findEmployeeById(list, len, id);
	if (indexEmployee >= 0){
		employee = (list + indexEmployee);
	}

	return employee;
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

void printHeaderEmployee(){
	puts(" _________________________________________________________________________________________________________________________________");
	puts("| ID    | Apellido                                 | Nombre                                   | Salario         | Sector          |");
	puts("|_______|__________________________________________|__________________________________________|_________________|_________________|");
}

void printEmployee(Employee employee){
	  //puts(" _________________________________________________________________________________________________");
	printf("| %04d  | %-40s | %-40s | $%14.2f | %-15d |\n", employee.id,
													employee.lastName,
													employee.name,
													employee.salary,
													employee.sector);
	  puts("|_______|__________________________________________|__________________________________________|_________________|_________________|");
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
	float totalSalary;
	float averageSalary;
	int totalEmpleyeesWhoExceedTheAverageSalary;

	if (list != NULL && length > 0){
		puts("    *** LISTA DE EMPLEADOS ***     ");
		printHeaderEmployee();

		sortEmployees(list, length, DOWN); //PEDIR POR CONSOLA EL ORDENAMIENTO

		for (int i = 0; i < length; i++){
			if (!(list + i)->isEmpty){
				printEmployee(*(list + i));
			}
		}

		calcTotalSalary(list, length, &totalSalary);
		calcAverageSalary(list, length, &averageSalary);
		numberEmployeesWhoExceedTheAverageSalary(list, length, &totalEmpleyeesWhoExceedTheAverageSalary);

		printf("El total de salarios es: $%.2f\n", totalSalary);
		printf("El salario promedio es: $%.2f\n", averageSalary);
		printf("La cantidad de empleados que superan el salario promedio es: %d\n", totalEmpleyeesWhoExceedTheAverageSalary);

		success  = 1;
	}

	return success;
}

int validateSalary(float salary){
	int valid = -1;

	if (salary > 0){
		valid = 0;
	}

	return valid;
}

/*
int editEmployee(Employee* list, int len, int id){
	int success = -1;
	int indexEmployee;

	if (list != NULL && len > 0){
		puts("     *** MODIFICACION EMPLEADO ***          ");

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
*/

int editName(Employee* employee, int len){
	int success = -1;
	char auxName[len];

	if (employee != NULL && len > 0){
		getString("Ingrese el nuevo nombre: ", auxName, len);

		strcpy(employee->name, auxName);
		success = 0;
	}

	return success;
}

int editLastName(Employee* employee, int len){
	int success = -1;
	char auxLastName[len];

	if (employee != NULL && len > 0){
		getString("Ingrese el nuevo apellido: ", auxLastName, len);

		strcpy(employee->lastName, auxLastName);
		success = 0;
	}

	return success;
}

int editSalary(Employee* employee){
	int success = -1;
	float auxSalary;

	if (employee != NULL){
		getFloat("Ingrese el nuevo salario: ", &auxSalary);

		while(validateSalary(auxSalary) < 0){
			puts("El salario no es valido");
			getFloat("Ingrese el nuevo salario: ", &auxSalary);
		}

		employee->salary = auxSalary;
		success = 0;
	}

	return success;
}

int editSector(Employee* employee){
	int success = -1;
	int auxSector;

	if (employee != NULL){
		getInt("Ingrese el nuevo sector: ", &auxSector);

		employee->sector = auxSector;
		success = 0;
	}

	return success;
}


int calcTotalSalary(Employee* list, int len, float* pTotal){
	int success = -1;
	float auxTotal = 0;

	if (list != NULL && len > 0 && pTotal != NULL){
		for (int i = 0; i < len; i++){
			if ((list + i)->isEmpty == FILL){
				auxTotal += (list + i)->salary;
			}
		}

		*pTotal = auxTotal;
		success = 0;
	}

	return success;
}

int calcAverageSalary(Employee* list, int len, float* pAverage){
	int success = -1;
	int auxAmountEmployees = 0;
	float totalSalary;

	if (list != NULL && len > 0 && pAverage != NULL){
		calcTotalSalary(list, len, &totalSalary);

		for (int i = 0; i < len; i++){
			if ((list + i)->isEmpty == FILL){
				auxAmountEmployees++;
			}
		}

		*pAverage = totalSalary / auxAmountEmployees;
		success = 0;
	}

	return success;
}

int numberEmployeesWhoExceedTheAverageSalary(Employee* list, int len, int* pAmountEmployees){
	int success = -1;
	int auxAmountEmployees = 0;
	float totalSalary;
	float averageSalary;

	if (list != NULL && len > 0 && pAmountEmployees != NULL){
		calcTotalSalary(list, len, &totalSalary);
		calcAverageSalary(list, len, &averageSalary);

		for (int i = 0; i < len; i++){
			if ((list + i)->isEmpty == FILL && (list + i)->salary > averageSalary){
				auxAmountEmployees++;
			}
		}

		*pAmountEmployees = auxAmountEmployees;
		success = 0;
	}

	return success;
}
