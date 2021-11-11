/**
 * @brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * @param path char*
 * @param pArrayListEmployee LinkedList*
 * @return int 0: No se pudo cargar el archivo - 1: Ok
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);


/**
 * @brief Listar empleados
 *
 * @param pArrayListEmployee LinkedList*
 * @return int
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


