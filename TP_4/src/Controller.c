#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "../inc/Controller.h"
#include "../inc/Pet.h"
#include "../inc/parser.h"
//#include "output.h"
//#include "menu.h"
#include "../inc/input.h"



int controller_loadFromText(char* path, LinkedList* pPets)
{
	int result = 0;
	char confirmDeleteData = 's';

	if (path != NULL && pPets != NULL){
		FILE* file = fopen(path, "r");
		if (file != NULL){
			//CONFIRM OVERRIDE DATA IF EXISTS
			if (!ll_isEmpty(pPets)){
				getChar("Hay datos cargados, si continua se sobreescribiran. Confirma sobreescritura de datos actuales? n(NO) - s(SI): ", &confirmDeleteData);
				while (confirmDeleteData != 'n' && confirmDeleteData != 's'){
					getChar("Escriba n o s. Confirma sobreescritura de datos actuales? n(NO) - s(SI): ", &confirmDeleteData);
				}
			}

			if (confirmDeleteData == 's'){
				ll_clear(pPets);
				if (parser_PetsFromText(file, pPets)){
					result = 1;
				}
			}
			else{
				result = 2;
			}

			fclose(file);
		}
		else{
			result = 3;
		}
	}

    return result;
}

/*
int controller_loadFromBinary(char* path , LinkedList* pPets)
{
	int result = 0;
	char confirmDeleteData = 's';

	if (path != NULL && pPets != NULL){
		FILE* file = fopen(path, "rb");
		if (file != NULL){
			if (!ll_isEmpty(pPets)){
				getChar("Hay datos cargados, si continua se sobreescribiran. Confirma sobreescritura de datos actuales? n(NO) - s(SI): ", &confirmDeleteData);
				while (confirmDeleteData != 'n' && confirmDeleteData != 's'){
					getChar("Escriba n o s. Confirma sobreescritura de datos actuales? n(NO) - s(SI): ", &confirmDeleteData);
				}
			}

			if (confirmDeleteData == 's'){
				ll_clear(pPets);
				if (parser_EmployeeFromBinary(file, pPets) == 1){
					result = 1;
				}
			}
			else{
				result = 2;
			}

			fclose(file);
		}
		else{
			result = 3;
		}
	}

    return result;
}


int controller_addEmployee(LinkedList* pPets, int* pNextId)
{
    int result = 0;
	char name[128];
	int hoursWorked;
	float salary;
	Employee* auxEmployee;

    if (pPets != NULL && pNextId != NULL){
		puts("     *** ALTA EMPLEADO ***          ");
    	if (employee_chargeData(name, &hoursWorked, &salary)){
    		auxEmployee = employee_newParametros(*pNextId, name, hoursWorked, salary);
    		if (auxEmployee != NULL){
    			if (ll_add(pPets, auxEmployee)){
        			*pNextId += 1;
        			//employee_saveLastId(pathIdFile, *pNextId);
        			result = 1;
    			}
    			else{
    				result = 4;
    			}
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


int controller_removeEmployee(LinkedList* pPets)
{
    int result = 0;
    Employee* auxEmployee = NULL;
    int idEmployee;
    int indexEmployee = -1;
    char confirm = 'n';

    if (pPets != NULL){
    	employee_showEmployees(pPets);

    	getInt("Ingrese ID de empleado: ", &idEmployee);

    	while (indexEmployee == -1){
    		indexEmployee = employee_validateId(pPets, idEmployee);
    		if (indexEmployee == -1){
    			getInt("ID invalido. Ingrese ID de empleado: ", &idEmployee);
    		}
    	}

    	auxEmployee = (Employee*)ll_get(pPets, indexEmployee);

    	puts("\n******************************************************************************");
    	puts("EMPLEADO:");
		employee_printHeaderReport();
		employee_showEmployee(auxEmployee);
		puts("");

		getChar("Confirma eliminacion del empleado? n(NO) - s(SI): ", &confirm);
		while (confirm != 'n' && confirm != 's'){
			getChar("Escriba n o s. Confirma eliminacion del empleado? n(NO) - s(SI): ", &confirm);
		}

		if (confirm == 's'){
			ll_remove(pPets, indexEmployee);
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

	if (pArrayListEmployee != NULL){
		employee_showEmployees(pArrayListEmployee);
		result = 1;
	}

    return result;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int result = 0;
    int option;

    if (pArrayListEmployee != NULL){
    	result = 1;

    	//ll_sort(LinkedList* this, int(*)(void*,void*) pFunc, int order)
    	option = submenuOrder();
    	switch(option){
			case optOrderId:
		    	puts("Ordenando los empleados por ID...Por favor espere");
		    	ll_sort(pArrayListEmployee, employee_compareById, 1);
				break;
			case optOrderName:
		    	puts("Ordenando los empleados por nombre...Por favor espere");
		    	ll_sort(pArrayListEmployee, employee_compareByName, 1);
				break;
			case optOrderHoursWorked:
		    	puts("Ordenando los empleados por horas trabajadas...Por favor espere");
		    	ll_sort(pArrayListEmployee, employee_compareByHoursWorked, 1);
				break;
			case optOrderSalary:
		    	puts("Ordenando los empleados por salario...Por favor espere");
		    	ll_sort(pArrayListEmployee, employee_compareBySalary, 1);
				break;
			case optOrderExitMenu:
				result = 2;
				break;
			default:
				puts("Opcion invalida");
				break;
    	}
		puts("\n");
    }

    return result;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
	int result = 0;
	Employee* auxEmployee = NULL;
	char confirm = 's';
	int count;
	int id;
	char name[128];
	int hoursWorked;
	float salary;

	if (path != NULL && pArrayListEmployee != NULL){
		FILE* fileR = fopen(path, "r");
		if (fileR != NULL){
			getChar("Existe otro archivo con el mismo nombre. Confirma sobreescribirlo? n(NO) - s(SI): ", &confirm);
			while (confirm != 'n' && confirm != 's'){
				getChar("Escriba n o s. Confirma sobreescribir el archivo? n(NO) - s(SI): ", &confirm);
			}
			fclose(fileR);
		}

		if (confirm == 's'){
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
				fclose(file);
			}
			else{
				result = 2;
			}
		}
		else{
			result = 5;
		}
	}

    return result;
}



int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
	int result = 0;
	Employee* auxEmployee = NULL;
	char confirm = 's';
	int count;

	if (path != NULL && pArrayListEmployee != NULL){
		FILE* fileR = fopen(path, "r");
		if (fileR != NULL){
			getChar("Existe otro archivo con el mismo nombre. Confirma sobreescribirlo? n(NO) - s(SI): ", &confirm);
			while (confirm != 'n' && confirm != 's'){
				getChar("Escriba n o s. Confirma sobreescribir el archivo? n(NO) - s(SI): ", &confirm);
			}
			fclose(fileR);
		}

		if (confirm == 's'){
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
		else{
			result = 5;
		}
	}

	return result;
}

*/
