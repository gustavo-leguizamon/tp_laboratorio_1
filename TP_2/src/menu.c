#include <stdio.h>
#include <stdlib.h>

#include "input.h"
#include "menu.h"


int menu(){
	int selectedOption;

	printf("**** ABM de Empleados ***");
	puts("1-Alta de empleado");
	puts("2-Modificar empleado");
	puts("3-Baja de empleado");
	puts("4-Informar");
	puts("5-Salir");
	puts("\n");
	getInt("Ingrese una opcion: ", &selectedOption);

	return selectedOption;
}
