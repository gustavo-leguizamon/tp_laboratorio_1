#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
//#include "output.h"


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

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int success = 0;
	Employee* auxEmployee = NULL;
	/*
	int lenColumns = 4;
	char columns[4][128] = { "ID", "NOMBRE", "HORAS TRABAJADAS", "SALARIO" };
	int lengths[4] = { 6, 130, 18, 9 };
	*/

	if (pArrayListEmployee != NULL){
		success = 1;
		//printHeader(columns, lengths, lenColumns);
		printf("| %4s | %20s | %4s | %6s |\n", "ID", "NOMBRE", "HORAS", "SALARIO");
		for (int i = 0; i < ll_len(pArrayListEmployee); i++){
			auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
			showEmployee(auxEmployee);
			//printFooter(lengths, lenColumns);
		}
	}

    return success;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
	int result = 0;

	if (path != NULL && pArrayListEmployee != NULL){
		FILE* file = fopen(path, "w");
		if (file != NULL){
			if (parser_SaveEmployeeInText(file, pArrayListEmployee) == 1){
				result = 1;
			}
			else{
				result = 3;
			}

			fclose(file);
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

	if (path != NULL && pArrayListEmployee != NULL){
		FILE* file = fopen(path, "wb");
		if (file != NULL){
			if (parser_SaveEmployeeInBinary(file, pArrayListEmployee) == 1){
				result = 1;
			}
			else{
				result = 3;
			}

			fclose(file);
		}
		else{
			result = 2;
		}
	}

	return result;
}

