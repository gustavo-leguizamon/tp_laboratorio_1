#include <stdio.h>
#include "menu.h"
#include "operacionesMatematicas.h"

int menu(int operandoA, int operandoB, int seIngresoOperandoA, int seIngresoOperandoB){
	int opcionSeleccionada;

	printf("\nMenu de opciones\n\n");
	if (seIngresoOperandoA){
		printf("1. Ingresar 1er operando (A=%d)\n", operandoA);
	}
	else{
		printf("1. Ingresar 1er operando (A=x)\n");
	}
	if (seIngresoOperandoB){
		printf("2. Ingresar 2do operando (B=%d)\n", operandoB);
	}
	else{
		printf("2. Ingresar 2do operando (B=y)\n");
	}
	printf("3. Calcular todas las operaciones\n");
	printf("4. Informar resultados\n");
	printf("5. Salir\n");

	printf("Indique una opcion\n");
	fflush(stdin);
	scanf("%d", &opcionSeleccionada);

	return opcionSeleccionada;
}

int cargarOperando(int* operando){
	int exito;

	printf("Ingrese el operando\n");
	exito = scanf("%d", operando);
	if (!exito){
		printf("No se pudo cargar el operando\n");
	}

	return exito;
}

int calcularTodasOperaciones(int operandoA, int operandoB, int* pSuma, int* pResta, float* pDivision, int* pMultiplicacion, long long int* pFactorialA, long long int* pFactorialB, int validaciones[]){
	int exito = 0;

	if (pSuma != NULL &&
		pResta != NULL &&
		pDivision != NULL &&
		pMultiplicacion != NULL &&
		pFactorialA != NULL &&
		pFactorialB != NULL &&
		validaciones != NULL){

		validaciones[0] = sumar(operandoA, operandoB, pSuma);
		validaciones[1] = restar(operandoA, operandoB, pResta);
		validaciones[2] = dividir(operandoA, operandoB, pDivision);
		validaciones[3] = multiplicar(operandoA, operandoB, pMultiplicacion);
		validaciones[4] = factorial(operandoA, pFactorialA);
		validaciones[5] = factorial(operandoB, pFactorialB);

		exito = 1;
	}

	return exito;
}

void mostrarResultados(int suma, int resta, float division, int multiplicacion, long long int factorialA, long long int factorialB, int validaciones[]){
	if (!validaciones[0]){
		printf("a) NO se pudo calcular la suma A+B\n");
	}
	else{
		printf("a) El resultado de A+B es: %d\n", suma);
	}

	if (!validaciones[1]){
		printf("b) NO se pudo calcular la resta A-B\n");
	}
	else{
		printf("b) El resultado de A-B es: %d\n", resta);
	}

	if (!validaciones[2]){
		printf("c) NO se pudo calcular la division A/B\n");
	}
	else if (validaciones[2] == DIVISION_POR_CERO){
		printf("c) No es posible dividir por cero\n");
	}
	else{
		printf("c) El resultado de A/B es: %.2f\n", division);
	}

	if (!validaciones[3]){
		printf("d) NO se pudo calcular la multiplicacion A*B\n");
	}
	else{
		printf("d) El resultado de A*B es: %d\n", multiplicacion);
	}

	if (!validaciones[4] && !validaciones[5]){
		printf("e) NO se pudo calcular el factorial de A ni de B\n");
	}
	else if (validaciones[4] == FACTORIAL_NEGATIVO && validaciones[5] == FACTORIAL_NEGATIVO){
		printf("e) NO se pudo calcular el factorial de A ni de B por ser negativos\n");
	}
	else if (validaciones[4] == FACTORIAL_CALCULADO && validaciones[5] == FACTORIAL_NEGATIVO){
		printf("e) El factorial de A es: %lli y NO se pudo calcular factorial de B por ser negativo\n", factorialA);
	}
	else if (validaciones[4] == FACTORIAL_NEGATIVO && validaciones[5] == FACTORIAL_CALCULADO){
		printf("e) NO se pudo calcular el factorial de A por ser negativo y el factorial de B es: %lli\n", factorialB);
	}
	else if (validaciones[4] == FACTORIAL_FUERA_DE_LIMITE && validaciones[5] == FACTORIAL_FUERA_DE_LIMITE){
		printf("e) NO se pudo calcular el factorial de A ni de B por ser mayores a 20 y salirse de limite\n");
	}
	else if (validaciones[4] == FACTORIAL_CALCULADO && validaciones[5] == FACTORIAL_FUERA_DE_LIMITE){
		printf("e) El factorial de A es: %lli y NO se pudo calcular factorial de B por ser mayor a 20 y salirse de limite\n", factorialA);
	}
	else if (validaciones[4] == FACTORIAL_FUERA_DE_LIMITE && validaciones[5] == FACTORIAL_CALCULADO){
		printf("e) NO se pudo calcular el factorial de A por ser mayor a 20 y salirse de limite y el factorial de B es: %lli\n", factorialB);
	}
	else{
		printf("e) El factorial de A es: %lli y El factorial de B es: %lli\n", factorialA, factorialB);
	}
}
