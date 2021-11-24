/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"


#include "../inc/menu.h"
#include "../inc/Controller.h"
#include "../inc/Pet.h"

int main(void)
{
	/* TESTS
	startTesting(1);  // ll_newLinkedList
    startTesting(2);  // ll_len
	startTesting(3);  // getNode - test_getNode
	startTesting(4);  // addNode - test_addNode
	startTesting(5);  // ll_add
	startTesting(6);  // ll_get
	startTesting(7);  // ll_set
	startTesting(8);  // ll_remove
	startTesting(9);  // ll_clear
	startTesting(10); // ll_deleteLinkedList
	startTesting(11); // ll_indexOf
	startTesting(12); // ll_isEmpty
	startTesting(13); // ll_push
	startTesting(14); // ll_pop
	startTesting(15); // ll_contains
	startTesting(16); // ll_containsAll
	startTesting(17); // ll_subList
	startTesting(18); // ll_clone
	startTesting(19); // ll_sort

    return 0;
    */

	setbuf(stdout, NULL);


    int option;
	int result;
	int nextId = 1;
	int lenPath = 150;
	char path[lenPath];

	LinkedList* listPets = ll_newLinkedList();
	LinkedList* listAppointments = ll_newLinkedList();
	if (listPets == NULL){
		puts("No se pudo iniciar la lista");
		exit(EXIT_FAILURE);
	}


	do{
		option = menu();
		switch(option)
		{
			case optMainLoadPetsTextFile:
				controller_loadNameOfFile(path, lenPath);
				result = controller_loadFromText(path, listPets);
				if (result == 1){
					pet_findHighestId(listPets, &nextId);
					puts("Se cargaron los datos desde el archivo");
				}
				else if (result == 2){
					puts("Carga de datos cancelada por el usuario");
				}
				else if(result == 3){
					puts("No se pudo leer el archivo, asegurese de que exista");
				}
				else{
					puts("Ocurrio un error al cargar los datos del archivo");
				}
				break;
			case optMainLoadPetsBinaryFile:
				controller_loadNameOfFile(path, lenPath);
				result = controller_loadFromBinary(path, listPets);
				if (result == 1){
					pet_findHighestId(listPets, &nextId);
					puts("Se cargaron los datos desde el archivo");
				}
				else if (result == 2){
					puts("Carga de datos cancelada por el usuario");
				}
				else if(result == 3){
					puts("No se pudo leer el archivo, asegurese de que exista");
				}
				else{
					puts("Ocurrio un error al cargar los datos del archivo");
				}
				break;
			case optMainAddNewPet:
				result = controller_addPet(listPets, &nextId);
				if (result == 1){
					puts("Alta exitosa");
				}
				else{
					puts("No se pudo dar de alta la mascota");
				}
				break;
			case optMainDeletePet:
				if (ll_isEmpty(listPets)){
					puts("NO hay mascotas cargadas en el sistema");
				}
				else{
					result = controller_removePet(listPets);
					if (result == 1){
						puts("Exito al eliminar la mascota");
					}
					else if (result == 2){
						puts("Eliminacion cancelada por el usuario");
					}
					else{
						puts("Ocurrio un error al eliminar la mascota");
					}
				}
				break;
			case optMainReportPets:
				if (ll_isEmpty(listPets)){
					puts("NO hay mascotas cargadas en el sistema");
				}
				else{
					result = controller_listPets(listPets);
					if (!result){
						puts("Ocurrio un error al mostrar mascotas");
					}
				}
				break;
			case optMainSortPets:
				if (ll_isEmpty(listPets)){
					puts("NO hay mascotas cargadas en el sistema");
				}
				else{
					result = controller_sortPets(listPets);
					if (result == 1){
						puts("Mascotas ordenados");
					}
					else if (result == 2){
						puts("No se selecciono metodo de ordenamiento");
					}
					else{
						puts("Ocurrio un error al ordenar las mascotas");
					}
				}
				break;
			case optAddAppointment:
				if (ll_isEmpty(listPets)){
					puts("NO hay mascotas cargadas en el sistema");
				}
				else{
					result = controller_addAppointment(listAppointments, listPets);
					if (result == 1){
						puts("Turno registrado");
					}
					else{
						puts("Ocurrio un error al registrar el turno");
					}
				}
				break;
			case optOrderOfAppointment:
				if (ll_isEmpty(listPets)){
					puts("NO hay mascotas cargadas en el sistema");
				}
				else{
					result = controller_orderOfAppointment(listAppointments, listPets);
					if (result != 1){
						puts("Ocurrio un error al buscar orden de turno");
					}
				}
				break;
			case optMainSavePetsTextFile:
				if (!ll_isEmpty(listPets)){
					controller_loadNameOfFile(path, lenPath);
					result = controller_saveAsText(path, listPets);
					if (result){
						if (result == 1){
							printf("Mascotas guardadas con exito en el archivo: %s\n", path);
						}
						else if(result == 5){
							puts("Guardado cancelado por el usuario");
						}
						else{
							puts("Ocurrio un error al intentar guardar el archivo");
						}
					}
					else{
						puts("Ocurrio un error, datos no validos para guardar el archivo");
					}
				}
				else{
					puts("No hay mascotas para guardar en el archivo");
				}
				break;
			case optMainSavePetsBinaryFile:
				if (!ll_isEmpty(listPets)){
					controller_loadNameOfFile(path, lenPath);
					result = controller_saveAsBinary(path, listPets);
					if (result){
						if (result == 1){
							printf("Mascotas guardadas con exito en el archivo: %s\n", path);
						}
						else if(result == 5){
							puts("Guardado cancelado por el usuario");
						}
						else{
							puts("Ocurrio un error al intentar guardar el archivo");
						}
					}
					else{
						puts("Ocurrio un error, datos no validos para guardar el archivo");
					}
				}
				else{
					puts("No hay mascotas para guardar en el archivo");
				}
				break;
			case optMainExitMenu:
				break;
			default:
				puts("Opcion invalida");
				break;
		}
		puts("\n");
	} while(option != optMainExitMenu);

	ll_deleteLinkedList(listPets);

	puts("FIN DEL PROGRAMA");

	return EXIT_SUCCESS;
}

































