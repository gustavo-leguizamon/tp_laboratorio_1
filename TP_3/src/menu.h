#ifndef SRC_MENU_H_
#define SRC_MENU_H_

enum enumMainMenu {
	optLoadEmployeesTextFile = 1,
	optLoadEmployeesBinaryFile,
	optRegisterEmployee,
	optEditEmployee,
	optDeleteEmployee,
	optReportEmployees,
	optSortEmployees,
	optSaveEmployeesTextFile,
	optSaveEmployeesBinaryFile,
	optExitMainMenu
};

#endif /* SRC_MENU_H_ */


/**
 * @brief Displays a menu of options
 *
 * @return Selected option
 */
int menu();
