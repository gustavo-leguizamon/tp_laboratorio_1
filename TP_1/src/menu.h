#ifndef MENU_H_
#define MENU_H_

/**
 * @brief Muestra un menu de opciones
 *
 * @param operandoA Operando A
 * @param operandoB Operando B
 * @param seIngresoOperandoA 1: Indica que ya se ingreso el operando A - 0: Indica que no
 * @param seIngresoOperandoB 1: Indica que ya se ingreso el operando B - 0: Indica que no
 * @return Opcion seleccionada del menu
 */
int menu(int operandoA, int operandoB, int seIngresoOperandoA, int seIngresoOperandoB);

/**
 * @brief Carga una variable de operando
 *
 * @param operando Referencia a la variable operando
 * @return 1: Indica que se pudo cargar el operando - 0: Indica que no
 */
int cargarOperando(int* operando);

/**
 * @brief Calcula todas las operaciones matematicas
 *
 * @param operandoA Operando A
 * @param operandoB Operando B
 * @param pSuma Referncia a variable con resultado de la suma de operandos
 * @param pResta Referencia a variable con resultado de la resta de operandos
 * @param pDivision Referencia a variable con resultado de la division de operandos
 * @param pMultiplicacion Referencia a variable con resultado de la multiplicacion de operandos
 * @param pFactorialA Referencia a variable con resultado del factorial del operando A
 * @param pFactorialB Referencia a variable con resultado del factorial del operando B
 * @param validaciones Vector con los resultados de realizar las operaciones
 * @return 1: Indica que se pudo realizar los calculos - 0: Indica que no
 */
int calcularTodasOperaciones(int operandoA, int operandoB, int* pSuma, int* pResta, float* pDivision, int* pMultiplicacion, long long int* pFactorialA, long long int* pFactorialB, int validaciones[]);

/**
 * @brief Muestra los resultados de los calculos sobre los operandos
 *
 * @param suma Resultado de la suma
 * @param resta Resultado de la resta
 * @param division Resultado de la division
 * @param multiplicacion Resultado de la multiplicacion
 * @param factorialA Resultado del factorial de A
 * @param factorialB Resultado del factorial de B
 * @param validaciones Vector con las validaciones realizadas en los calculos
 */
void mostrarResultados(int suma, int resta, float division, int multiplicacion, long long int factorialA, long long int factorialB, int validaciones[]);

#endif /* MENU_H_ */
