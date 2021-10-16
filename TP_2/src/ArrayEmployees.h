#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define FILL  0
#define EMPTY 1
#define DOWN 0
#define UP   1

enum eSector {
	Administration,
	RRHH,
	Infrastructure
};

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


/**
 * @brief find an Employee by Id and returns the index position in array.
 *
 * @param list Employee*
 * @param len int
 * @param id int
 * @return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 */
int findEmployeeById(Employee* list, int len, int id);


/**
 * @brief Remove an Employee by Id (put isEmpty Flag in 1)
 *
 * @param list Employee*
 * @param len int
 * @param id int
 * @return Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 */
int removeEmployee(Employee* list, int len, int id);


/**
 * @brief Sort the elements in the array of employees, the argument order
 *        indicate UP or DOWN order
 *
 * @param list Employee*
 * @param len int
 * @param order int [1] indicate UP - [0] indicate DOWN
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortEmployees(Employee* list, int len, int order);




int validateSalary(float salary);


//int editEmployee(Employee* list, int len, int id);

int editName(Employee* employee, int len);

int editLastName(Employee* employee, int len);

int editSalary(Employee* employee);

int editSector(Employee* employee);

int getID(void);

Employee* getEmployee(Employee* list, int len, int id);

int thereIsAnyEmployee(Employee* list, int len);

void printHeaderEmployee();

void printEmployee(Employee employee);

/**
 * @brief print the content of employees array
 *
 * @param list Employee*
 * @param length int
 * @return int
 */
int printEmployees(Employee* list, int length);
