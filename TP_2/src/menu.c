#include <stdio.h>
#include <stdlib.h>

#include "input.h"
#include "menu.h"


int menu(){
	int selectedOption;

	puts("**** ABM de Empleados ***");
	puts("1-Alta de empleado");
	puts("2-Modificar empleado");
	puts("3-Baja de empleado");
	puts("4-Informar");
	puts("5-Salir");
	puts("\n");
	getInt("Ingrese una opcion: ", &selectedOption);

	return selectedOption;
}


int submenuEdit(){
	int selectedOption;

	puts("**** Que quiere modificar? ***");
	puts("1-Nombre");
	puts("2-Apellido");
	puts("3-Salario");
	puts("4-Sector");
	puts("5-Cancelar");
	puts("\n");
	getInt("Ingrese una opcion: ", &selectedOption);

	return selectedOption;
}
