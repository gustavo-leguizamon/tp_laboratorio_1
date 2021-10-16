#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayEmployees.h"
#include "menu.h"

#define LEN 1000

void hardCodeEmployees(Employee* list, int len, int* id);

int main(void) {
	setbuf(stdout, NULL);

	Employee employees[LEN];

	char keep = 's';
	char keepEditing = 's';

	int nextId = 0;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int idInput;
	Employee* employee;

	if (initEmployees(employees, LEN)){
		hardCodeEmployees(employees, LEN, &nextId);

		do{
			//system("clear");

			switch(menu()){
				case RegisterEmployee:
					puts("***   ALTA EMPLEDO   ***");
					if (chargeDataEmployee(&nextId, name, lastName, &salary, &sector)){
						if (addEmployee(employees, LEN, nextId, name, lastName, salary, sector) == 0){
							puts("Alta exitosa!!!");
						}
						else{
							puts("No se pudo realizar el alta");
						}
					}
					else{
						puts("No se pudo cargar los datos ingresados");
					}
					break;
				case EditEmployee:
					puts("***   MODIFICAR EMPLEDO   ***");
					if (thereIsAnyEmployee(employees, LEN)){
						idInput = getID();
						employee = getEmployee(employees, LEN, idInput);
						printHeaderEmployee();
						printEmployee(*employee);

						do{
							switch(submenuEdit()){
								case Name:
									if (editName(employee, 51) == 0){
										puts("Modificacion exitosa!!!");
									}
									else{
										puts("No se pudo modificar el nombre del empleado");
									}
									break;
								case LastName:
									if (editLastName(employee, 51) == 0){
										puts("Modificacion exitosa!!!");
									}
									else{
										puts("No se pudo modificar el apellido del empleado");
									}
									break;
								case Salary:
									if (editSalary(employee) == 0){
										puts("Modificacion exitosa!!!");
									}
									else{
										puts("No se pudo modificar el salario del empleado");
									}
									break;
								case Sector:
									if (editSector(employee) == 0){
										puts("Modificacion exitosa!!!");
									}
									else{
										puts("No se pudo modificar el sector del empleado");
									}
									break;
								case ExitEditMenu:
									keepEditing = 'n';
									break;
								default:
									puts("Opcion invalida");
									break;
							}
						} while (keepEditing == 's');



						//if (editEmployee(employees, LEN, idInput) == 0){
						//	puts("Modificacion exitosa!!!");
						//}
						//else{
						//	puts("No se pudo modificar el empleado");
						//}
					}
					else{
						puts("No hay empleados para modificar");
					}
					break;
				case DeleteEmployee:
					puts("***   BAJA EMPLEDO   ***");
					if (thereIsAnyEmployee(employees, LEN)){
						idInput = getID();
						if (removeEmployee(employees, LEN, idInput) == 0){
							puts("Baja exitosa!!!");
						}
						else{
							puts("No se pudo dar de baja el empleado");
						}
					}
					else{
						puts("No hay empleados para dar de baja");
					}
					break;
				case ReportEmployees:
					if (thereIsAnyEmployee(employees, LEN)){
						if (!printEmployees(employees, LEN)){
							puts("No se pudo mostrar los empleados");
						}
					}
					else{
						puts("No hay empleados para mostrar");
					}
					break;
				case ExitMainMenu:
					keep = 'n';
					break;
				default:
					puts("Opcion invalida");
					break;
			}

			system("pause");
		} while (keep == 's');
	}
	else{
		puts("No se pudo inicializar el array de empleados");
	}

	return EXIT_SUCCESS;
}

void hardCodeEmployees(Employee* list, int len, int* id){
	int i;
	Employee auxEmployee;

	if (list != NULL && len > 0 && id != NULL){
		i = 0;
		*id += 1;
		auxEmployee.id = *id;
		strcpy(auxEmployee.name, "Juan");
		strcpy(auxEmployee.lastName, "Perez");
		auxEmployee.salary = 15000;
		auxEmployee.sector = 1;
		auxEmployee.isEmpty = FILL;
		*(list + i) = auxEmployee;


		i = 1;
		*id = *id + 1;
		(list + i)->id = *id;
		strcpy((list + i)->name, "Sebastian");
		strcpy((list + i)->lastName, "Rodriguez");
		(list + i)->salary = 5000;
		(list + i)->sector = 2;
		(list + i)->isEmpty = FILL;


		i = 2;
		*id = *id + 1;
		(list + i)->id = *id;
		strcpy((list + i)->name, "Juana");
		strcpy((list + i)->lastName, "Lopez");
		(list + i)->salary = 50000;
		(list + i)->sector = 3;
		(list + i)->isEmpty = FILL;
	}
}
