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

			auxEmployee = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
			if  (auxEmployee != NULL){
				ll_add(pArrayListEmployee, auxEmployee);
				auxEmployee = NULL;
			}
		} while(!feof(pFile));
		success = 1;
	}

    return success;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}


int parser_SaveEmployeeInText(FILE* pFile, LinkedList* pArrayListEmployee){
	int result = 0;
	Employee* auxEmployee;
	int count;
	int id;
	char name[128];
	int hoursWorked;
	int salary;

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
				count = fprintf(pFile, "%d,%s,%d,%d\n", id, name, hoursWorked, salary);

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
