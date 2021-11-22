#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "../inc/Pet.h"
#include "../inc/parser.h"


int parser_PetsFromText(FILE* pFile, LinkedList* pPets)
{
	int success = 0;
	char buffer[2][128];
	int count;
	Pet* auxPet = NULL;

	if (pFile != NULL && pPets != NULL){
		//SALTO CABECERA
		fscanf(pFile, "%[^,],%[^\n]\n", buffer[0], buffer[1]);

		do{
			count = fscanf(pFile, "%[^,],%[^\n]\n", buffer[0], buffer[1]);
			if (count < 2){
				break;
			}

			auxPet = pet_newParametersStr(buffer[0], buffer[1]);
			if  (auxPet != NULL){
				ll_add(pPets, auxPet);
				auxPet = NULL;
			}
		} while(!feof(pFile));
		success = 1;
	}

    return success;
}


int parser_PetsFromBinary(FILE* pFile, LinkedList* pPets)
{
	int result = 0;
	Pet* auxPet = NULL;
	int count;

	if (pFile != NULL && pPets != NULL){
		result = 1; //"Mascota cargados correctamente"
		while(!feof(pFile)){
			auxPet = pet_new();
			if (auxPet != NULL){
				count = fread(auxPet, sizeof(Pet), 1, pFile);
				if (count == 1){
					ll_add(pPets, auxPet);
					auxPet = NULL;
				}
				else{
					if (feof(pFile)){
						pet_delete(auxPet);
						break;
					}
					result = 2; //"Hubo problemas para leer la mascota"
					break;
				}
			}
			else{
				result = 3; //"Hubo problemas para crear la mascota"
				break;
			}
		}
	}

	return result;
}
