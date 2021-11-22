#ifndef INC_PET_H_
#define INC_PET_H_

typedef struct {
	int id;
	char name[128];
} Pet;

#endif /* INC_PET_H_ */


/**
 * @brief Generate a new struct Pet in memory
 *
 * @return Pet* pointer to pet or NULL if not has been created
 */
Pet* pet_new();


/**
 * @brief Generate a new struct Pet in memory passing parameters of fields
 *
 * @param id int
 * @param name char*
 * @return Pet* pointer to pet or NULL if not has been created
 */
Pet* pet_newParameters(int id, char* name);


/**
 * @brief Generate a new struct Pet in memory passing parameters of fields as strings
 *
 * @param idStr char*
 * @param nameStr char*
 * @return Pet* pointer to pet or NULL if not has been created
 */
Pet* pet_newParametersStr(char* idStr, char* nameStr);



//GETTERS
/**
 * @brief Get value of id field from a Pet
 *
 * @param this  Pet*
 * @param pId int*
 * @return int 0: Error in parameters - 1: Ok
 */
int pet_getId(Pet* this, int* pId);


/**
 * @brief Get value of name field from a Pet
 *
 * @param this Pet*
 * @param pName char*
 * @return int 0: Error in parameters - 1: Ok
 */
int pet_getName(Pet* this, char* pName);


//SETTERS
/**
 * @brief Set a new id for a Pet
 *
 * @param this Pet*
 * @param id int
 * @return int 0: Error in parameters - 1: Ok
 */
int pet_setId(Pet* this, int id);



/**
 * @brief Set a new name for a Pet
 *
 * @param this Pet*
 * @param name char*
 * @return int 0: Error in parameters - 1: Ok
 */
int pet_setName(Pet* this, char* name);



/**
 * @brief Destroy Pet from memory
 *
 * @param pPet Pet*
 * @return int 0: Error in parameters - 1: Ok
 */
int pet_delete(Pet* pPet);
