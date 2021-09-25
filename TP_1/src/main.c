/*
 ============================================================================
 Name        : TP_1.c
 Author      : Gustavo Leguizamon
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

#define CARGA_OPERANDO_A           1
#define CARGA_OPERANDO_B           2
#define CALCULAR_TODAS_OPERACIONES 3
#define REPORTAR_RESULTADOS        4
#define SALIR                      5

int main(void) {
	setbuf(stdout, NULL);

	int operandoA;
	int operandoB;

	int suma;
	int resta;
	float division;
	int multiplicacion;
	long long int factorialA;
	long long int factorialB;

	int validaciones[6];

	int operandoAEstaCargado = 0;
	int operandoBEstaCargado = 0;
	int resultadosCalculados = 0;
	int continuar = 1;

	do{
		switch (menu(operandoA, operandoB, operandoAEstaCargado, operandoBEstaCargado)){
			case CARGA_OPERANDO_A:
				operandoAEstaCargado = cargarOperando(&operandoA);
				break;
			case CARGA_OPERANDO_B:
				if (operandoAEstaCargado){
					operandoBEstaCargado = cargarOperando(&operandoB);
				}
				else{
					printf("Debe ingresar el primer operando\n");
				}
				break;
			case CALCULAR_TODAS_OPERACIONES:
				if (operandoBEstaCargado){
					resultadosCalculados = calcularTodasOperaciones(operandoA, operandoB, &suma, &resta, &division, &multiplicacion, &factorialA, &factorialB, validaciones);
					printf("Se realizaron los calculos\n");
				}
				else if (operandoAEstaCargado){
					printf("Para realizar calculos debe ingresar el 2do operando\n");
				}
				else{
					printf("Para realizar calculos debe ingresar el 1ro y 2do operando\n");
				}
				break;
			case REPORTAR_RESULTADOS:
				if (resultadosCalculados){
					mostrarResultados(suma, resta, division, multiplicacion, factorialA, factorialB, validaciones);
				}
				else{
					printf("Para reportar los calculos debe calcularlos previamente\n");
				}
				break;
			case SALIR:
				continuar = 0;
				break;
			default:
				printf("Opcion invalida\n");
				break;
		}
		//system("pause");
		printf("--------------------------------\n");
	} while (continuar);

	return EXIT_SUCCESS;
}
