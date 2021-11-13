#include <stdio.h>
#include <stdlib.h>

#include "input.h"
#include "menu.h"


int menu(){
	int selectedOption;

	puts("**** ABM de Empleados ***");
	printf("%d. Cargar los datos de los empleados desde el archivo %s (modo texto)\n", optLoadEmployeesTextFile, NAME_FILE_TEXT);
	printf("%d. Cargar los datos de los empleados desde el archivo %s (modo binario)\n", optLoadEmployeesBinaryFile, NAME_FILE_BIN);
	printf("%d. Alta de empleado\n", optRegisterEmployee);
	printf("%d. Modificar datos de empleado\n", optEditEmployee);
	//printf("%d. Baja de empleado\n", optDeleteEmployee);
	printf("%d. Listar empleados\n", optReportEmployees);
	//printf("%d. Ordenar empleados\n", optSortEmployees);
	printf("%d. Guardar los datos de los empleados en el archivo %s (modo texto)\n", optSaveEmployeesTextFile, NAME_FILE_TEXT);
	printf("%d. Guardar los datos de los empleados en el archivo %s (modo binario)\n", optSaveEmployeesBinaryFile, NAME_FILE_BIN);
	printf("%d. Salir\n", optExitMainMenu);
	printf("\n");

	getInt("Ingrese una opcion: ", &selectedOption);
	puts("");

	return selectedOption;
}


int submenuEdit(){
	int selectedOption;

	puts("**** MODIFICACION DE EMPLEADO ***");
	printf("%d. Nombre\n", optEditName);
	printf("%d. Horas trabajadas\n", optEditHoursWorked);
	printf("%d. Salario\n", optEditSalary);
	printf("%d. Salir\n", optEditExitMenu);
	printf("\n");

	getInt("Ingrese una opcion: ", &selectedOption);
	puts("");

	return selectedOption;
}
