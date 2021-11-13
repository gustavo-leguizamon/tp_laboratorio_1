#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

#include "menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

#define PATH_FILE_LAST_ID "last_id.bin"

int main()
{
	setbuf(stdout, NULL);

    int option;
	int result;
	int nextId = 1;

    LinkedList* listEmployees = ll_newLinkedList();
    if (listEmployees == NULL){
    	puts("No se pudo iniciar la lista");
    	exit(EXIT_FAILURE);
    }

    employee_restoreLastId(PATH_FILE_LAST_ID, &nextId);

    do{
    	option = menu();
        switch(option)
        {
            case optMainLoadEmployeesTextFile:
            	result = controller_loadFromText(NAME_FILE_TEXT, listEmployees);
                if (result == 1){
                	puts("Se cargaron los datos desde el archivo");
                }
                else if (result == 2){
                	puts("Carga de datos cancelada por el usuario");
                }
                else{
                	puts("Ocurrio un error al cargar los datos del archivo");
                }
                break;
            case optMainLoadEmployeesBinaryFile:
            	result = controller_loadFromBinary(NAME_FILE_BIN, listEmployees);
				if (result == 1){
					puts("Se cargaron los datos desde el archivo");
				}
                else if (result == 2){
                	puts("Carga de datos cancelada por el usuario");
                }
				else{
					puts("Ocurrio un error al cargar los datos del archivo");
				}
				break;
            case optMainRegisterEmployee:
            	result = controller_addEmployee(listEmployees, &nextId, PATH_FILE_LAST_ID);
            	if (result == 1){
            		puts("Alta exitosa");
            	}
            	else{
            		puts("No se pudo dar de alta el empleado");
            	}
            	break;
            case optMainEditEmployee:
            	if (ll_isEmpty(listEmployees)){
        			puts("NO hay empleados cargados en el sistema");
            	}
            	else{
            		result = controller_editEmployee(listEmployees);
					if (result){
						puts("Exito al modificar los datos del empleado");
					}
					else{
						puts("Ocurrio un error al modificar el empleado");
					}
            	}
            	break;
            case optMainDeleteEmployee:
            	if (ll_isEmpty(listEmployees)){
        			puts("NO hay empleados cargados en el sistema");
            	}
            	else{
            		result = controller_removeEmployee(listEmployees);
					if (result == 1){
						puts("Exito al eliminar al empleado");
					}
					else if (result == 2){
						puts("Eliminacion cancelada por el usuario");
					}
					else{
						puts("Ocurrio un error al eliminar el empleado");
					}
            	}
            	break;
            case optMainReportEmployees:
            	if (ll_isEmpty(listEmployees)){
        			puts("NO hay empleados cargados en el sistema");
            	}
            	else{
            		result = controller_ListEmployee(listEmployees);
					if (!result){
						puts("Ocurrio un error al mostrar empleados");
					}
            	}
            	break;
            case optMainSortEmployees:
            	if (ll_isEmpty(listEmployees)){
					puts("NO hay empleados cargados en el sistema");
				}
				else{
					result = controller_sortEmployee(listEmployees);
					if (result){
						puts("Empleados ordenados");
					}
					else{
						puts("Ocurrio un error al ordenar los empleados");
					}
				}
            	break;
            case optMainSaveEmployeesTextFile:
            	if (!ll_isEmpty(listEmployees)){
                	result = controller_saveAsText(NAME_FILE_TEXT, listEmployees);
                	if (result){
                		if (result == 1){
                    		printf("Empleados guardados con exito en el archivo: %s\n", NAME_FILE_TEXT);
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
            		puts("No hay empleados para guardar en el archivo");
            	}
            	break;
            case optMainSaveEmployeesBinaryFile:
            	if (!ll_isEmpty(listEmployees)){
					result = controller_saveAsBinary(NAME_FILE_BIN, listEmployees);
					if (result){
						if (result == 1){
							printf("Empleados guardados con exito en el archivo: %s\n", NAME_FILE_BIN);
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
					puts("No hay empleados para guardar en el archivo");
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

    ll_deleteLinkedList(listEmployees);

    puts("FIN DEL PROGRAMA");

    return EXIT_SUCCESS;
}

