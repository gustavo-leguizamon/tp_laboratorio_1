#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
//#include "output.h"
#include "menu.h"
#include "input.h"



int controller_loadNameOfFile(char* fileName, int len){
	int result = 0;

	if (fileName != NULL){
		getString("Indique el path del archivo: ", fileName, len);
		result = 1;
	}

	return result;
}


int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
	int result = 0;
	char confirmDeleteData = 's';

	if (path != NULL && pArrayListEmployee != NULL){
		FILE* file = fopen(path, "r");
		if (file != NULL){
			//CONFIRM OVERRIDE DATA IF EXISTS
			if (!ll_isEmpty(pArrayListEmployee)){
				getChar("Hay datos cargados, si continua se sobreescribiran. Confirma sobreescritura de datos actuales? n(NO) - s(SI): ", &confirmDeleteData);
				while (confirmDeleteData != 'n' && confirmDeleteData != 's'){
					getChar("Escriba n o s. Confirma sobreescritura de datos actuales? n(NO) - s(SI): ", &confirmDeleteData);
				}
			}

			if (confirmDeleteData == 's'){
				ll_clear(pArrayListEmployee);
				if (parser_EmployeeFromText(file, pArrayListEmployee)){
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


int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int result = 0;
	char confirmDeleteData = 's';

	if (path != NULL && pArrayListEmployee != NULL){
		FILE* file = fopen(path, "rb");
		if (file != NULL){
			if (!ll_isEmpty(pArrayListEmployee)){
				getChar("Hay datos cargados, si continua se sobreescribiran. Confirma sobreescritura de datos actuales? n(NO) - s(SI): ", &confirmDeleteData);
				while (confirmDeleteData != 'n' && confirmDeleteData != 's'){
					getChar("Escriba n o s. Confirma sobreescritura de datos actuales? n(NO) - s(SI): ", &confirmDeleteData);
				}
			}

			if (confirmDeleteData == 's'){
				ll_clear(pArrayListEmployee);
				if (parser_EmployeeFromBinary(file, pArrayListEmployee) == 1){
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


int controller_addEmployee(LinkedList* pArrayListEmployee, int* pNextId)
{
    int result = 0;
	char name[128];
	int hoursWorked;
	float salary;
	Employee* auxEmployee;

    if (pArrayListEmployee != NULL && pNextId != NULL){
		puts("     *** ALTA EMPLEADO ***          ");
    	if (employee_chargeData(name, &hoursWorked, &salary)){
    		auxEmployee = employee_newParametros(*pNextId, name, hoursWorked, salary);
    		if (auxEmployee != NULL){
    			if (ll_add(pArrayListEmployee, auxEmployee)){
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


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int result = 0;
    int option;
    Employee* auxEmployee = NULL;
    int idEmployee;
    int indexEmployee = -1;

    if (pArrayListEmployee != NULL){
    	employee_showEmployees(pArrayListEmployee);

    	getInt("Ingrese ID de empleado: ", &idEmployee);

    	while (indexEmployee == -1){
    		indexEmployee = employee_validateId(pArrayListEmployee, idEmployee);
    		if (indexEmployee == -1){
    			getInt("ID invalido. Ingrese ID de empleado: ", &idEmployee);
    		}
    	}

    	auxEmployee = (Employee*)ll_get(pArrayListEmployee, indexEmployee);

    	puts("\n******************************************************************************");
    	puts("EMPLEADO:");
		employee_printHeaderReport();
		employee_showEmployee(auxEmployee);
		puts("");
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
    	employee_showEmployees(pArrayListEmployee);

    	getInt("Ingrese ID de empleado: ", &idEmployee);

    	while (indexEmployee == -1){
    		indexEmployee = employee_validateId(pArrayListEmployee, idEmployee);
    		if (indexEmployee == -1){
    			getInt("ID invalido. Ingrese ID de empleado: ", &idEmployee);
    		}
    	}

    	auxEmployee = (Employee*)ll_get(pArrayListEmployee, indexEmployee);

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

