/**
 * @brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * @param path char*
 * @param pArrayListEmployee LinkedList*
 * @return int 0: No se pudo cargar el archivo - 1: Ok - 2: Load cancelled by user
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);


/**
 * @brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * @param path char*
 * @param pArrayListEmployee LinkedList*
 * @return int 0: No se pudo cargar el archivo - 1: Ok - 2: Load cancelled by user
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);



/**
 * @brief Alta de empleados
 *
 * @param pArrayListEmployee LinkedList*
 * @param pId int*
 * @param pathIdFile char*
 * @return int 0: Error in parameters - 1: Ok - 2: Error in data from user - 3: Error to build employee - 4: Error to add employee in LinkedList
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* pNextId, char* pathIdFile);



/**
 * @brief Modificar datos de empleado
 *
 * @param pArrayListEmployee LinkedList*
 * @return int 0: Error in parameters - 1: Ok
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);



/**
 * @brief Baja de empleado
 *
 * @param pArrayListEmployee LinkedList*
 * @return int 0: Error in parameters - 1: Ok - 2: Canceled by user
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);


/**
 * @brief Listar empleados
 *
 * @param pArrayListEmployee LinkedList*
 * @return int 0: Error in parameters - 1: Ok
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);


/**
 * @brief Ordenar empleados
 *
 * @param pArrayListEmployee LinkedList*
 * @return int 0: Error in parameters - 1: Ok
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);


/**
 * @brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * @param path char*
 * @param pArrayListEmployee LinkedList*
 * @return int 0: Error in parameters - 1: Ok - 2: Error to open file - 3: Error to save data - 4: Error in data of employee
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);


/**
 * @brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * @param path char*
 * @param pArrayListEmployee LinkedList*
 * @return int 0: Error in parameters - 1: Ok - 2: Error to open file - 3: Error to save data - 4: Error in data of employee
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee);


