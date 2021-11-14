#include <stdio.h>
#include <stdlib.h>

#include "input.h"
#include "menu.h"


int menu(){
	int selectedOption;

	puts("**** ABM DE EMPLEADOS ****");
	printf("%d. Cargar los datos de los empleados desde el archivo .csv (modo texto)\n", optMainLoadEmployeesTextFile);
	printf("%d. Cargar los datos de los empleados desde el archivo .bin (modo binario)\n", optMainLoadEmployeesBinaryFile);
	printf("%d. Alta de empleado\n", optMainRegisterEmployee);
	printf("%d. Modificar datos de empleado\n", optMainEditEmployee);
	printf("%d. Baja de empleado\n", optMainDeleteEmployee);
	printf("%d. Listar empleados\n", optMainReportEmployees);
	printf("%d. Ordenar empleados\n", optMainSortEmployees);
	printf("%d. Guardar los datos de los empleados en el archivo .csv (modo texto)\n", optMainSaveEmployeesTextFile);
	printf("%d. Guardar los datos de los empleados en el archivo .bin (modo binario)\n", optMainSaveEmployeesBinaryFile);
	printf("%d. Salir\n", optMainExitMenu);
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
