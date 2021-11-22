#ifndef INC_PARSER_H_
#define INC_PARSER_H_



#endif /* INC_PARSER_H_ */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


/**
 * @brief Parser data of structures from file data.csv (text mode).
 *
 * @param pFile FILE*
 * @param pPets LinkedList*
 * @return int 0: No se pudo parsear - 1: Ok
 */
int parser_PetsFromText(FILE* pFile, LinkedList* pPets);


/**
 * @brief Parser data of structures from file data.bin (binary mode).
 *
 * @param pFile FILE*
 * @param pPets LinkedList*
 * @return int 0: No se pudo parsear - 1: Ok
 */
int parser_PetsFromBinary(FILE* pFile, LinkedList* pPets);

