#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
//#include "output.h"
#include "menu.h"
#include "input.h"


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int result = 0;

	if (path != NULL && pArrayListEmployee != NULL){
		FILE* file = fopen(path, "r");
		if (file != NULL){
			if (parser_EmployeeFromText(file, pArrayListEmployee)){
				result = 1;
			}

			fclose(file);
		}
	}

    return result;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int result = 0;

	if (path != NULL && pArrayListEmployee != NULL){
		FILE* file = fopen(path, "rb");
		if (file != NULL){
			if (parser_EmployeeFromBinary(file, pArrayListEmployee) == 1){
				result = 1;
			}

			fclose(file);
		}
	}

    return result;
}


int controller_addEmployee(LinkedList* pArrayListEmployee, int* pNextId, char* pathIdFile)
{
    int result = 0;
	char name[128];
	int hoursWorked;
	float salary;
	Employee* auxEmployee;

    if (pArrayListEmployee != NULL && pNextId != NULL && pathIdFile != NULL){
		puts("     *** ALTA EMPLEADO ***          ");
    	if (employee_chargeData(name, &hoursWorked, &salary)){
    		auxEmployee = employee_newParametros(*pNextId, name, hoursWorked, salary);
    		if (auxEmployee != NULL){
    			ll_add(pArrayListEmployee, auxEmployee);
    			*pNextId += 1;
    			employee_saveLastId(pathIdFile, *pNextId);
    			result = 1;
    		}
    		else{
    			result = 3;
    		}
    	}
    	else{
    		result = 2;
    	}
    }

    return result;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int result = 0;
    int option;
    Employee* auxEmployee = NULL;
    int idEmployee;
    int indexEmployee = -1;

    if (pArrayListEmployee != NULL){
    	controller_ListEmployee(pArrayListEmployee);

    	getInt("Ingrese ID de empleado: ", &idEmployee);

    	while (indexEmployee == -1){
    		indexEmployee = employee_validateId(pArrayListEmployee, idEmployee);
    		if (indexEmployee == -1){
    			getInt("ID invalido. Ingrese ID de empleado: ", &idEmployee);
    		}
    	}

    	auxEmployee = (Employee*)ll_get(pArrayListEmployee, indexEmployee);

		employee_printHeaderReport();
		employee_showEmployee(auxEmployee);
    	//do{
    		option = submenuEdit();
			switch(option){
				case optEditName:
					if (employee_editName(auxEmployee, 128)){
						result = 1;
						puts("Modificacion exitosa!!!");
					}
					else{
						puts("No se pudo modificar el nombre del empleado");
					}
					break;
				case optEditHoursWorked:
					if (employee_editHoursWorked(auxEmployee)){
						result = 1;
						puts("Modificacion exitosa!!!");
					}
					else{
						puts("No se pudo modificar las horas trabajadas del empleado");
					}
					break;
				case optEditSalary:
					if (employee_editSalary(auxEmployee)){
						result = 1;
						puts("Modificacion exitosa!!!");
					}
					else{
						puts("No se pudo modificar el salario del empleado");
					}
					break;
				case optEditExitMenu:
					break;
				default:
					puts("Opcion invalida");
					break;
			}
			puts("\n");
		//} while (option != optEditExitMenu);
    }

    return result;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int result = 0;
    Employee* auxEmployee = NULL;
    int idEmployee;
    int indexEmployee = -1;
    char confirm = 'n';

    if (pArrayListEmployee != NULL){
    	controller_ListEmployee(pArrayListEmployee);

    	getInt("Ingrese ID de empleado: ", &idEmployee);

    	while (indexEmployee == -1){
    		indexEmployee = employee_validateId(pArrayListEmployee, idEmployee);
    		if (indexEmployee == -1){
    			getInt("ID invalido. Ingrese ID de empleado: ", &idEmployee);
    		}
    	}

    	auxEmployee = (Employee*)ll_get(pArrayListEmployee, indexEmployee);

    	puts("\nEMPLEADO:");
		employee_printHeaderReport();
		employee_showEmployee(auxEmployee);

		getChar("Confirma eliminacion del empleado? n(NO) - s(SI): ", &confirm);
		while (confirm != 'n' && confirm != 's'){
			getChar("Escriba n o s. Confirma eliminacion del empleado? n(NO) - s(SI): ", &confirm);
		}

		if (confirm == 's'){
			ll_remove(pArrayListEmployee, indexEmployee);
			result = 1;
		}
		else{
			result = 2;
		}
    }

    return result;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int result = 0;
	Employee* auxEmployee = NULL;
	/*
	int lenColumns = 4;
	char columns[4][128] = { "ID", "NOMBRE", "HORAS TRABAJADAS", "SALARIO" };
	int lengths[4] = { 6, 130, 18, 9 };
	*/

	if (pArrayListEmployee != NULL){
		result = 1;
		//printHeader(columns, lengths, lenColumns);
		employee_printHeaderReport();
		for (int i = 0; i < ll_len(pArrayListEmployee); i++){
			auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
			employee_showEmployee(auxEmployee);
			//printFooter(lengths, lenColumns);
		}
	}

    return result;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int result = 0;

    if (pArrayListEmployee != NULL){
    	//ll_sort(LinkedList* this, int(*)(void*,void*) pFunc, int order)

    	puts("Ordenando los empleados por nombre...Por favor espere");
    	ll_sort(pArrayListEmployee, employee_compareByName, 1);
    	result = 1;
    }

    return result;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
	int result = 0;
	Employee* auxEmployee;
	int count;
	int id;
	char name[128];
	int hoursWorked;
	float salary;

	if (path != NULL && pArrayListEmployee != NULL){
		FILE* file = fopen(path, "w");
		if (file != NULL){
			result = 1;
			fprintf(file, "id,nombre,horasTrabajadas,sueldo\n"); //PRINT HEADER

			for (int i = 0; i < ll_len(pArrayListEmployee); i++){
				auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
				if (auxEmployee != NULL &&
					employee_getId(auxEmployee, &id) &&
					employee_getNombre(auxEmployee, name) &&
					employee_getHorasTrabajadas(auxEmployee, &hoursWorked) &&
					employee_getSueldo(auxEmployee, &salary)){
					count = fprintf(file, "%d,%s,%d,%f\n", id, name, hoursWorked, salary);

					if (count < 4){
						result = 3;
						break;
					}
				}
				else{
					result = 4;
					break;
				}
			}
		}
		else{
			result = 2;
		}
	}

    return result;
}



int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
	int result = 0;
	Employee* auxEmployee;
	int count;

	if (path != NULL && pArrayListEmployee != NULL){
		FILE* file = fopen(path, "wb");
		if (file != NULL){
			result = 1;

			for (int i = 0; i < ll_len(pArrayListEmployee); i++){
				auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
				if (auxEmployee != NULL){
					count = fwrite(auxEmployee, sizeof(Employee), 1, file);

					if (count < 1){
						result = 3;
						break;
					}
				}
				else{
					result = 4;
					break;
				}
			}

			fclose(file);
		}
		else{
			result = 2;
		}
	}

	return result;
}

