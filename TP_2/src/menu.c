#include <stdio.h>
#include <stdlib.h>

#include "input.h"
#include "menu.h"


int menu(){
	int selectedOption;

	printf("**** ABM de Empleados ***\n");
	printf("1-Alta de empleado\n");
	printf("2-Modificar empleado\n");
	printf("3-Baja de empleado\n");
	printf("4-Informar\n");
	printf("5-Salir\n");
	printf("\n\n");
	getInt("Ingrese una opcion: ", &selectedOption);

	return selectedOption;
}
