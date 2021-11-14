#ifndef SRC_MENU_H_
#define SRC_MENU_H_

enum enumMainMenu {
	optMainLoadEmployeesTextFile = 1,
	optMainLoadEmployeesBinaryFile,
	optMainRegisterEmployee,
	optMainEditEmployee,
	optMainDeleteEmployee,
	optMainReportEmployees,
	optMainSortEmployees,
	optMainSaveEmployeesTextFile,
	optMainSaveEmployeesBinaryFile,
	optMainExitMenu
};


enum enumEditMenu {
	optEditName = 1,
	optEditHoursWorked,
	optEditSalary,
	optEditExitMenu
};


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
