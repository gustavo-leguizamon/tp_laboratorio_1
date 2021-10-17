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
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @param id int ID for new employee
 * @param name[] char Name of new employee
 * @param lastName[] char Lastname of new employee
 * @param salary float Salary of new employee
 * @param sector int Sector of new employee
 * @return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);


/**
 * @brief Gets data for an employee
 *
 * @param id int* Pointer to id
 * @param name char[] Array of characters of name
 * @param lastName char[] Array of characters of lastname
 * @param salary float* Pointer to salary
 * @param sector int* Pointer to Sector
 * @return Returns (-1) if fails - (0) if success
 */
int chargeDataEmployee(int* pId, char name[], char lastName[], float* pSalary, int* pSector);


/**
 * @brief find an Employee by Id and returns the index position in array.
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @param id int ID of employee
 * @return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 */
int findEmployeeById(Employee* list, int len, int id);


/**
 * @brief Remove an Employee by Id (put isEmpty Flag in 1)
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @param id int ID of employee
 * @return Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 */
int removeEmployee(Employee* list, int len, int id);


/**
 * @brief Sort the elements in the array of employees, the argument order
 *        indicate UP or DOWN order
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @param order int [1] indicate UP - [0] indicate DOWN
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortEmployees(Employee* list, int len, int order);



/**
 * @brief Calculate total active employee salaries
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @param pTotal float* Pointer to total of salary
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int calcTotalSalary(Employee* list, int len, float* pTotal);


/**
 * @brief Calculate average of avtive employee salaries
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @param pAverage float* Pointer to average salaries
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int calcAverageSalary(Employee* list, int len, float* pAverage);


/**
 * @brief Calculate amount of employeeswho exceed the average salary
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @param pAmountEmployees int* Pointer to amoiunt of employees
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int numberEmployeesWhoExceedTheAverageSalary(Employee* list, int len, int* pAmountEmployees);


/**
 * @brief  Indicates if salary complies with system validations
 *
 * @param salary float
 * @return [0] if is invalid - [1] if is valid
 */
int validateSalary(float salary);


/**
 * @brief Indicates if name complies with sistem validations
 *
 * @param name char[]
 * @return [0] if is invalid - [1] if is valid
 */
int validateName(char name[]);


/**
 * @brief Indicates if name complies with sistem validations
 *
 * @param lastname char[]
 * @return [0] if is invalid - [1] if is valid
 */
int validateLastname(char lastname[]);


/**
 * @brief Transform first character of words to uppercase
 *
 * @param vector char[] Array of characters
 * @return Returns (-1) if fails - (0) if ok
 */
int capitalize(char vector[]);


/**
 * @brief Edit name of an employee
 *
 * @param employee Employee* Pointer to employee
 * @param len int Array length of name
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int editName(Employee* employee, int len);


/**
 * @brief Edit lastname of an employee
 *
 * @param employee Employee* Pointer to employee
 * @param len int Array length of lastname
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int editLastName(Employee* employee, int len);


/**
 * @brief Edit salary of an employee
 *
 * @param employee Employee* Pointer to employee
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int editSalary(Employee* employee);


/**
 * @brief Edit sector of an employee
 *
 * @param employee Employee* Pointer to employee
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int editSector(Employee* employee);


/**
 * @brief Get an number of ID from console
 *
 * @return Number of ID
 */
int getID(void);


/**
 * @brief Get an employee
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @param id int ID of employee
 * @return Returns (NULL) if not exists employee - or Employee struct
 */
Employee* getEmployee(Employee* list, int len, int id);


/**
 * @brief Indicates if there are active employees
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @return Returns (0) if not exist any - (1) if exists someone
 */
int thereIsAnyEmployee(Employee* list, int len);


/**
 * @brief Prints header for report of employees
 *
 */
void printHeaderEmployee();


/**
 * @brief Prints information of an employee
 *
 * @param employee Employee employee for print
 */
void printEmployee(Employee employee);

/**
 * @brief print the content of employees array
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @return int Returns (-1) if fails - (0) if ok
 */
int printEmployees(Employee* list, int length);
