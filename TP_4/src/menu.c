#include <stdio.h>
#include <stdlib.h>

#include "../inc/input.h"
#include "../inc/menu.h"


int menu(){
	int selectedOption;

	puts("**** ABM DE EMPLEADOS ****");
	printf("%d. Cargar los datos de las mascotas desde el archivo .csv (modo texto)\n", optMainLoadPetsTextFile);
	printf("%d. Cargar los datos de las mascotas desde el archivo .bin (modo binario)\n", optMainLoadPetsBinaryFile);
	printf("%d. Agregar nueva mascota\n", optMainAddNewPet);
	//printf("%d. Modificar datos de empleado\n", optMainEditEmployee);
	printf("%d. Eliminar mascota\n", optMainDeletePet);
	printf("%d. Listar mascotas\n", optMainReportPets);
	printf("%d. Ordenar mascotas\n", optMainSortPets);
	printf("%d. Agregar turno\n", optAddAppointment);
	printf("%d. Orden de turno\n", optOrderOfAppointment);
	printf("%d. Guardar los datos de las mascotas en el archivo .csv (modo texto)\n", optMainSavePetsTextFile);
	printf("%d. Guardar los datos de las mascotas en el archivo .bin (modo binario)\n", optMainSavePetsBinaryFile);
	printf("%d. Salir\n", optMainExitMenu);
	printf("\n");

	getInt("Ingrese una opcion: ", &selectedOption);
	puts("");

	return selectedOption;
}


int submenuOrder(){
	int selectedOption;

	puts("**** TIPO DE ORDENAMIENTO ***");
	printf("%d. Por ID\n", optOrderId);
	printf("%d. Por Nombre\n", optOrderName);
	printf("%d. Salir\n", optOrderExitMenu);
	printf("\n");

	getInt("Ingrese una opcion: ", &selectedOption);
	puts("");

	return selectedOption;
}

