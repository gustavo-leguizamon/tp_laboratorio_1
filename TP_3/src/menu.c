#include <stdio.h>
#include <stdlib.h>

#include "input.h"
#include "menu.h"


int menu(){
	int selectedOption;

	puts("**** ABM de Empleados ***");
	printf("%d. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n", optLoadEmployeesTextFile);
	//printf("%d. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n", optLoadEmployeesBinaryFile);
	//printf("%d. Alta de empleado\n", optRegisterEmployee);
	//printf("%d. Modificar datos de empleado\n", optEditEmployee);
	//printf("%d. Baja de empleado\n", optDeleteEmployee);
	printf("%d. Listar empleados\n", optReportEmployees);
	//printf("%d. Ordenar empleados\n", optSortEmployees);
	printf("%d. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n", optSaveEmployeesTextFile);
	printf("%d. Guardar los datos de los empleados en el archivo data.bin (modo binario)\n", optSaveEmployeesBinaryFile);
	printf("%d. Salir\n", optExitMainMenu);
	printf("\n");

	getInt("Ingrese una opcion: ", &selectedOption);
	puts("");

	return selectedOption;
}
