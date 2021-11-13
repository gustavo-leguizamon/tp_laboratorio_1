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


enum enumEditMenu {
	optEditName = 1,
	optEditHoursWorked,
	optEditSalary,
	optEditExitMenu
};

#define NAME_FILE_TEXT "data.csv"
#define NAME_FILE_BIN  "data.bin"

#endif /* SRC_MENU_H_ */


/**
 * @brief Displays a menu of options
 *
 * @return Selected option
 */
int menu();


/**
 * @brief Displays a menu of options for edit
 *
 * @return Selected option
 */
int submenuEdit();
