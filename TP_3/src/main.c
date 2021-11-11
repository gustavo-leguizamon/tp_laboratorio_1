#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

#include "menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
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
            	result = controller_loadFromText("data.csv", listEmployees);
                if (result){
                	puts("Se cargaron los datos desde el archivo");
                }
                else{
                	puts("Ocurrio un error al cargar los datos del archivo");
                }
                puts("\n");
                break;
            case optReportEmployees:
				result = controller_ListEmployee(listEmployees);
            	if (result){
                	if (result == 2){
            			puts("NO hay empleados cargados en el sistema");
                	}
            	}
            	else{
            		puts("Ocurrio un error al mostrar empleados");
            	}
            	puts("\n");
            	break;
            case optExitMainMenu:
            	break;
            default:
            	puts("Opcion invalida\n");
            	break;
        }
    } while(option != optExitMainMenu);

    puts("FIN DEL PROGRAMA");

    return EXIT_SUCCESS;
}

