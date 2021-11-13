#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int success = 0;
	char buffer[4][128];
	int count;
	Employee* auxEmployee = NULL;

	if (pFile != NULL && pArrayListEmployee != NULL){
		//SALTO CABECERA
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

		do{
			//cantidad = fscanf("%d,%[^,],%c,%f", &legajo, nombre, &sexo, &sueldo);
			count = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
			if (count < 4){
				break;
			}

			auxEmployee = employee_newParametrosStr(buffer[0], buffer[1], buffer[2], buffer[3]);
			if  (auxEmployee != NULL){
				ll_add(pArrayListEmployee, auxEmployee);
				auxEmployee = NULL;
			}
		} while(!feof(pFile));
		success = 1;
	}

    return success;
}


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int result = 0;
	Employee* auxEmployee = NULL;
	int count;

	if (pFile != NULL && pArrayListEmployee != NULL){
		result = 1; //"Empleados cargados correctamente"
		while(!feof(pFile)){
			auxEmployee = employee_new();
			if (auxEmployee != NULL){
				count = fread(auxEmployee, sizeof(Employee), 1, pFile);
				if (count == 1){
					ll_add(pArrayListEmployee, auxEmployee);
					auxEmployee = NULL;
				}
				else{
					if (feof(pFile)){
						employee_delete(auxEmployee);
						break;
					}
					result = 2; //"Hubo problemas para leer el empleado"
					break;
				}
			}
			else{
				result = 3; //"Hubo problemas para crear empleado"
				break;
			}
		}
	}

	return result;
}

/*
int parser_SaveEmployeeInText(FILE* pFile, LinkedList* pArrayListEmployee){
	int result = 0;
	Employee* auxEmployee;
	int count;
	int id;
	char name[128];
	int hoursWorked;
	float salary;

	if (pFile != NULL && pArrayListEmployee != NULL){
		result = 1;
		fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n"); //PRINT HEADER

		for (int i = 0; i < ll_len(pArrayListEmployee); i++){
			auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
			if (auxEmployee != NULL &&
				employee_getId(auxEmployee, &id) &&
				employee_getNombre(auxEmployee, name) &&
				employee_getHorasTrabajadas(auxEmployee, &hoursWorked) &&
				employee_getSueldo(auxEmployee, &salary)){
				count = fprintf(pFile, "%d,%s,%d,%f\n", id, name, hoursWorked, salary);

				if (count < 4){
					result = 2;
					break;
				}
			}
			else{
				result = 3;
				break;
			}
		}
	}

	return result;
}
*/

/*
int parser_SaveEmployeeInBinary(FILE* pFile, LinkedList* pArrayListEmployee){
	int result = 0;
	Employee* auxEmployee;
	int count;

	if (pFile != NULL && pArrayListEmployee != NULL){
		result = 1;

		for (int i = 0; i < ll_len(pArrayListEmployee); i++){
			auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
			if (auxEmployee != NULL){
				count = fwrite(auxEmployee, sizeof(Employee), 1, pFile);

				if (count < 1){
					result = 2;
					break;
				}
			}
			else{
				result = 3;
				break;
			}
		}
	}

	return result;
}
*/
