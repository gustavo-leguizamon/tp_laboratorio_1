#include <stdio.h>
#include <stdlib.h>

#include "ArrayEmployees.h"
#include "menu.h"

#define LEN 1000

int main(void) {
	setbuf(stdout, NULL);

	Employee employees[LEN];

	char seguir = 's';

	int nextId = 0;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int idToRemove;

	if (initEmployees(employees, LEN)){
		do{
			//system("clear");

			switch(menu()){
				case REGISTER_EMPLOYEE:
					if (chargeDataEmployee(&nextId, name, lastName, &salary, &sector)){
						if (addEmployee(employees, LEN, nextId, name, lastName, salary, sector) == 0){
							puts("Alta exitosa!!!\n");
						}
						else{
							puts("No se pudo realizar el alta");
						}
					}
					else{
						puts("No se pudo cargar los datos ingresados");
					}
					break;
				case EDIT_EMPLOYEE:
					/*if (!bajaPersona(listaPersonas, TAM)){
						printf("No se pude realizar la baja\n");
					}
					else{
						printf("Baja exitosa!!!\n\n");
					}*/
					break;
				case DELETE_EMPLOYEE:
					if (thereIsAnyEmployee(employees, LEN)){
						idToRemove = getID();
						if (removeEmployee(employees, LEN, idToRemove) == 0){
							puts("Baja exitosa!!!\n");
						}
						else{
							puts("No se pudo dar de baja el empleado");
						}
					}
					else{
						puts("No hay empleados para dar de baja\n");
					}
					break;
				case REPORT:
					if (thereIsAnyEmployee(employees, LEN)){
						if (!printEmployees(employees, LEN)){
							puts("No se pudo mostrar los empleados");
						}
					}
					else{
						puts("No hay empleados para mostrar\n");
					}
					break;
				case EXIT:
					seguir = 'n';
					break;
				default:
					puts("Opcion invalida");
					break;
			}

			system("pause");
		} while (seguir == 's');
	}
	else{
		puts("No se pudo inicializar el array de empleados");
	}

	return EXIT_SUCCESS;
}
