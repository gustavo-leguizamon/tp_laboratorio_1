#include <stdio.h>
#include "operacionesMatematicas.h"

int sumar(int a, int b, int* resultado){
	int exito = 0;

	if (resultado != NULL){
		*resultado = a + b;
		exito = 1;
	}

	return exito;
}

int restar(int a, int b, int* resultado){
	int exito = 0;

	if (resultado != NULL){
		*resultado = a - b;
		exito = 1;
	}

	return exito;
}

int dividir(int a, int b, float* resultado){
	int exito = 0;

	if (resultado != NULL){
		if (b != 0){
			*resultado = (float)a / b;
			exito = 1;
		}
		else{
			exito = DIVISION_POR_CERO;
		}
	}

	return exito;
}

int multiplicar(int a, int b, int* resultado){
	int exito = 0;

	if (resultado != NULL){
		*resultado = a * b;
		exito = 1;
	}

	return exito;
}

int factorial(int numero, long long  int* resultado){
	int exito = 0;
	unsigned long long int factorialCalculado = 0;

	if (numero >= 0){
		factorialCalculado = 1;
		for (int i = 2; i <= numero; i++){
			factorialCalculado *= i;
		}

		*resultado = factorialCalculado;
		exito = 1;
	}
	else{
		exito = FACTORIAL_NEGATIVO;
	}

	return exito;
}
