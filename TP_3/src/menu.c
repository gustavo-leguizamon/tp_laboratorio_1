#include <stdio.h>
#include <stdlib.h>

#include "input.h"
#include "menu.h"


int menu(){
	int selectedOption;

	puts("**** ABM de Empleados ***");
	printf("%d. Cargar los datos de los empleados desde el archivo data.csv (modo texto)", optLoadEmployeesTextFile);
	//printf("%d. Cargar los datos de los empleados desde el archivo data.csv (modo binario)", optLoadEmployeesBinaryFile);
	//printf("%d. Alta de empleado", optRegisterEmployee);
	//printf("%d. Modificar datos de empleado", optEditEmployee);
	//printf("%d. Baja de empleado", optDeleteEmployee);
	//printf("%d. Listar empleados", optReportEmployees);
	//printf("%d. Ordenar empleados", optSortEmployees);
	//printf("%d. Guardar los datos de los empleados en el archivo data.csv (modo texto)", optSaveEmployeesTextFile);
	//printf("%d. Guardar los datos de los empleados en el archivo data.csv (modo binario)", optSaveEmployeesBinaryFile);
	printf("%d. Salir", optExitMainMenu);
	printf("\n\n");

	getInt("Ingrese una opcion: ", &selectedOption);
	puts("");

	return selectedOption;
}
