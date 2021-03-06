#include <stdio.h>
#include "operacionesMatematicas.h"

int sumar(int a, int b, int* pResultado){
	int exito = 0;

	if (pResultado != NULL){
		*pResultado = a + b;
		exito = 1;
	}

	return exito;
}

int restar(int a, int b, int* pResultado){
	int exito = 0;

	if (pResultado != NULL){
		*pResultado = a - b;
		exito = 1;
	}

	return exito;
}

int dividir(int a, int b, float* pResultado){
	int exito = 0;

	if (pResultado != NULL){
		if (b != 0){
			*pResultado = (float)a / b;
			exito = 1;
		}
		else{
			exito = DIVISION_POR_CERO;
		}
	}

	return exito;
}

int multiplicar(int a, int b, int* pResultado){
	int exito = 0;

	if (pResultado != NULL){
		*pResultado = a * b;
		exito = 1;
	}

	return exito;
}

int factorial(int numero, long long  int* pResultado){
	int exito = 0;
	unsigned long long int factorialCalculado = 0;

	if (numero < 0){
		exito = FACTORIAL_NEGATIVO;
	}
	else if (numero <= 20){
		factorialCalculado = 1;
		for (int i = 2; i <= numero; i++){
			factorialCalculado *= i;
		}

		*pResultado = factorialCalculado;
		exito = 1;
	}
	else{
		exito = FACTORIAL_FUERA_DE_LIMITE;
	}

	return exito;
}
