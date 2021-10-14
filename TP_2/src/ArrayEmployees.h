#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define EMPTY 1
#define FILL  0

typedef struct {
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
} Employee;

#endif /* ARRAYEMPLOYEES_H_ */

/**
 * @brief To indicate that all position in the array are empty,
 *        this function put the flag (isEmpty) in TRUE in all
 *        position of the array
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int initEmployees(Employee* list, int len);

/**
 * @brief look for a free position in the list
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @return int Return (-1) if there is no free position - else index of free position
 */
int findFreeSpace(Employee* list, int len);

/**
 * @brief add in a existing list of employees the values received as parameters
 *        in the first empty position
 *
 * @param list int
 * @param len int
 * @param id int
 * @param name[] char
 * @param lastName[] char
 * @param salary float
 * @param sector int
 * @return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);


/**
 * @brief Gets data for an employee
 *
 * @param id int*
 * @param name char[]
 * @param lastName char[]
 * @param salary float*
 * @param sector int*
 * @return 0: if fail - 1: if success
 */
int chargeDataEmployee(int* id, char name[], char lastName[], float* salary, int* sector);

int thereIsAnyEmployee(Employee* list, int len);

void printEmployee(Employee employee);

/**
 * @brief print the content of employees array
 *
 * @param list Employee*
 * @param length int
 * @return int
 */
int printEmployees(Employee* list, int length);
