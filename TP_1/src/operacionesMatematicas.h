#ifndef OPERACIONESMATEMATICAS_H_
#define OPERACIONESMATEMATICAS_H_

#define DIVISION_POR_CERO -1
#define FACTORIAL_NEGATIVO -1

/**
 * @brief Realiza la suma de dos numeros
 *
 * @param a Primer operando
 * @param b Segundo operando
 * @param resultado Referencia a variabe resultado de la operacion
 * @return Estado la operacion: 1 si se pudo realizar - 0 si no se pudo realizar
 */
int sumar(int a, int b, int* resultado);

/**
 * @brief Realiza la resta de dos numeros
 *
 * @param a Primer operando
 * @param b Segundo operando
 * @param resultado Referencia a variabe resultado de la operacion
 * @return Estado la operacion: 1 si se pudo realizar - 0 si no se pudo realizar
 */
int restar(int a, int b, int* resultado);

/**
 * @brief Realiza la division de dos numeros
 *
 * @param a Primer operando
 * @param b Segundo operando
 * @param resultado Referencia a variabe resultado de la operacion
 * @return Estado la operacion: 1 si se pudo realizar - 0 si no se pudo realizar - -1 Error division por cero
 */
int dividir(int a, int b, float* resultado);

/**
 * @brief Realiza la multiplicacion de dos numeros
 *
 * @param a Primer operando
 * @param b Segundo operando
 * @param resultado Referencia a variabe resultado de la operacion
 * @return Estado la operacion: 1 si se pudo realizar - 0 si no se pudo realizar
 */
int multiplicar(int a, int b, int* resultado);

/**
 * @brief Calcula el factorial de un numero
 *
 * @param numero Numero a calcular el factorial
 * @param resultado Referencia a variabe resultado de la operacion
 * @return Estado la operacion: 1 si se pudo realizar - 0 si no se pudo realizar - -1 Error factorial de numero negativo
 */
int factorial(int numero, long long  int* resultado);

#endif /* OPERACIONESMATEMATICAS_H_ */
