#ifndef SRC_PARSER_H_
#define SRC_PARSER_H_



#endif /* SRC_PARSER_H_ */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/**
 * @brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * @param pFile FILE*
 * @param pArrayListEmployee LinkedList*
 * @return int 0: No se pudo parsear - 1: Ok
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee);


/**
 * @brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * @param pFile FILE*
 * @param pArrayListEmployee LinkedList*
 * @return int 0: No se pudo parsear - 1: Ok
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee);


/**
 * @brief Parsea los datos de los empleados desde el LinkedList a un archivo data.csv (modo texto).
 *
 * @param pFile FILE*
 * @param pArrayListEmployee LinkedList*
 * @return int 0: Error en los parametros - 1: Ok - 2: Error al escribir datos en el archivo - 3: Error en datos del empleado
 */
int parser_SaveEmployeeInText(FILE* pFile, LinkedList* pArrayListEmployee);
