#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
//#include "output.h"


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int success = 0;

	FILE* file = fopen(path, "r");
	if (file != NULL){
		if (parser_EmployeeFromText(file, pArrayListEmployee)){
			success = 1;
		}

		fclose(file);
	}

    return success;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
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
	int listEmpty = 1;
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
			listEmpty = 0;
		}

		if (listEmpty){
			success = 2;
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

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

