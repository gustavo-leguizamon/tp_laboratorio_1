#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

#include "menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).a
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
	setbuf(stdout, NULL);

    int option;
	int result;

    LinkedList* listEmployees = ll_newLinkedList();

    do{
    	option = menu();
        switch(option)
        {
            case optLoadEmployeesTextFile:
            	result = controller_loadFromText(NAME_FILE_TEXT, listEmployees);
                if (result){
                	puts("Se cargaron los datos desde el archivo");
                }
                else{
                	puts("Ocurrio un error al cargar los datos del archivo");
                }
                break;
            case optLoadEmployeesBinaryFile:
            	result = controller_loadFromBinary(NAME_FILE_BIN, listEmployees);
				if (result){
					puts("Se cargaron los datos desde el archivo");
				}
				else{
					puts("Ocurrio un error al cargar los datos del archivo");
				}
				break;
            case optReportEmployees:
            	if (!ll_isEmpty(listEmployees)){
    				result = controller_ListEmployee(listEmployees);
                	if (!result){
                		puts("Ocurrio un error al mostrar empleados");
                	}
            	}
            	else{
        			puts("NO hay empleados cargados en el sistema");
            	}
            	break;
            case optSaveEmployeesTextFile:
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
            case optSaveEmployeesBinaryFile:
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
            case optExitMainMenu:
            	break;
            default:
            	puts("Opcion invalida");
            	break;
        }
        puts("\n");
    } while(option != optExitMainMenu);

    ll_deleteLinkedList(listEmployees);

    puts("FIN DEL PROGRAMA");

    return EXIT_SUCCESS;
}

