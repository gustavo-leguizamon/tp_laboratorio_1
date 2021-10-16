#ifndef MENU_H_
#define MENU_H_

/*
#define REGISTER_EMPLOYEE  1
#define EDIT_EMPLOYEE      2
#define DELETE_EMPLOYEE    3
#define REPORT             4
#define EXIT               5

#define
*/

enum eMainMenu {
	RegisterEmployee = 1,
	EditEmployee,
	DeleteEmployee,
	ReportEmployees,
	ExitMainMenu
};

enum eEditMenu {
	Name = 1,
	LastName,
	Salary,
	Sector,
	ExitEditMenu
};

/**
 * @brief Displays a menu of options
 *
 * @return Selected option
 */
int menu();


int submenuEdit();


#endif /* MENU_H_ */

