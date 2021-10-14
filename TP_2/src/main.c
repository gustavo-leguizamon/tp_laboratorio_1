#include <stdio.h>
#include <stdlib.h>

#include "ArrayEmployees.h"
#include "menu.h"

#define LEN 1000
//#define NONE     0
//#define REGISTER 1

int main(void) {
	setbuf(stdout, NULL);

	Employee employees[LEN];

	char seguir = 's';
	//int lastAction = NONE;

	int nextId = 0000;
	char name[51];
	char lastName[51];
	float salary;
	int sector;

	if (initEmployees(employees, LEN)){
		do{
			//system("clear");

			switch(menu()){
				case REGISTER_EMPLOYEE:
					printf("     *** ALTA EMPLEADO ***          \n\n");
					if (chargeDataEmployee(&nextId, name, lastName, &salary, &sector)){
						if (addEmployee(employees, LEN, nextId, name, lastName, salary, sector) == 0){
							//lastAction = REGISTER;
							printf("Alta exitosa!!!\n\n");
						}
						else{
							printf("No se pudo realizar el alta\n");
						}
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
					printf("Baja empleado\n");
					break;
				case REPORT:
					if (thereIsAnyEmployee(employees, LEN)){
						printEmployees(employees, LEN);
					}
					else{
						puts("No hay empleados para mostrar\n\n");
					}
					break;
				case EXIT:
					seguir = 'n';
					break;
				default:
					printf("Opcion invalida\n");
					break;
			}

			system("pause");
		} while (seguir == 's');
	}
	else{
		printf("No se pudo inicializar el array de empleados\n");
	}

	return EXIT_SUCCESS;
}
