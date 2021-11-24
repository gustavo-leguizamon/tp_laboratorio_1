#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "../inc/Controller.h"
#include "../inc/Pet.h"
#include "../inc/parser.h"
//#include "output.h"
#include "../inc/menu.h"
#include "../inc/input.h"



int controller_loadNameOfFile(char* fileName, int len){
	int result = 0;

	if (fileName != NULL){
		getString("Indique el path del archivo: ", fileName, len);
		result = 1;
	}

	return result;
}


int controller_loadFromText(char* path, LinkedList* pPets)
{
	int result = 0;
	char confirmDeleteData = 's';

	if (path != NULL && pPets != NULL){
		FILE* file = fopen(path, "r");
		if (file != NULL){
			//CONFIRM OVERRIDE DATA IF EXISTS
			if (!ll_isEmpty(pPets)){
				getChar("Hay datos cargados, si continua se sobreescribiran. Confirma sobreescritura de datos actuales? n(NO) - s(SI): ", &confirmDeleteData);
				while (confirmDeleteData != 'n' && confirmDeleteData != 's'){
					getChar("Escriba n o s. Confirma sobreescritura de datos actuales? n(NO) - s(SI): ", &confirmDeleteData);
				}
			}

			if (confirmDeleteData == 's'){
				ll_clear(pPets);
				if (parser_PetsFromText(file, pPets)){
					result = 1;
				}
			}
			else{
				result = 2;
			}

			fclose(file);
		}
		else{
			result = 3;
		}
	}

    return result;
}


int controller_loadFromBinary(char* path, LinkedList* pPets)
{
	int result = 0;
	char confirmDeleteData = 's';

	if (path != NULL && pPets != NULL){
		FILE* file = fopen(path, "rb");
		if (file != NULL){
			if (!ll_isEmpty(pPets)){
				getChar("Hay datos cargados, si continua se sobreescribiran. Confirma sobreescritura de datos actuales? n(NO) - s(SI): ", &confirmDeleteData);
				while (confirmDeleteData != 'n' && confirmDeleteData != 's'){
					getChar("Escriba n o s. Confirma sobreescritura de datos actuales? n(NO) - s(SI): ", &confirmDeleteData);
				}
			}

			if (confirmDeleteData == 's'){
				ll_clear(pPets);
				if (parser_PetsFromBinary(file, pPets) == 1){
					result = 1;
				}
			}
			else{
				result = 2;
			}

			fclose(file);
		}
		else{
			result = 3;
		}
	}

    return result;
}


int controller_addPet(LinkedList* pPets, int* pNextId)
{
    int result = 0;
	char name[128];
	Pet* auxPet;

    if (pPets != NULL && pNextId != NULL){
		puts("     *** ALTA MASCOTA ***          ");
    	if (pet_chargeData(name)){
    		auxPet = pet_newParameters(*pNextId, name);
    		if (auxPet != NULL){
    			if (ll_add(pPets, auxPet) == 0){
        			*pNextId += 1;
        			result = 1;
    			}
    			else{
    				result = 4;
    			}
    		}
    		else{
    			result = 3;
    		}
    	}
    	else{
    		result = 2;
    	}
    }

    return result;
}


int controller_removePet(LinkedList* pPets)
{
    int result = 0;
    Pet* auxPet = NULL;
    int idPet;
    int indexPet = -1;
    char confirm = 'n';

    if (pPets != NULL){
    	pet_showPets(pPets);

    	getInt("Ingrese ID de mascota: ", &idPet);

    	while (indexPet == -1){
    		indexPet = pet_validateId(pPets, idPet);
    		if (indexPet == -1){
    			getInt("ID invalido. Ingrese ID de mascota: ", &idPet);
    		}
    	}

    	auxPet = (Pet*)ll_get(pPets, indexPet);

    	puts("\n******************************************************************************");
    	puts("MASCOTA:");
		pet_printHeaderReport();
		pet_showPet(auxPet);
		puts("");

		getChar("Confirma eliminacion de la mascota? n(NO) - s(SI): ", &confirm);
		while (confirm != 'n' && confirm != 's'){
			getChar("Escriba n o s. Confirma eliminacion de la mascota? n(NO) - s(SI): ", &confirm);
		}

		if (confirm == 's'){
			ll_remove(pPets, indexPet);
			result = 1;
		}
		else{
			result = 2;
		}
    }

    return result;
}


int controller_listPets(LinkedList* pPets)
{
	return pet_showPets(pPets);
}


int controller_sortPets(LinkedList* pPets)
{
    int result = 0;
    int option;

    if (pPets != NULL){
    	result = 1;

    	//ll_sort(LinkedList* this, int(*)(void*,void*) pFunc, int order)
    	option = submenuOrder();
    	switch(option){
			case optOrderId:
		    	puts("Ordenando las mascotas por ID...Por favor espere");
		    	ll_sort(pPets, pet_compareById, 1);
				break;
			case optOrderName:
		    	puts("Ordenando las mascotas por nombre...Por favor espere");
		    	ll_sort(pPets, pet_compareByName, 1);
				break;
			case optOrderExitMenu:
				result = 2;
				break;
			default:
				puts("Opcion invalida");
				break;
    	}
		puts("\n");
    }

    return result;
}


int controller_saveAsText(char* path, LinkedList* pPets)
{
	int result = 0;
	Pet* auxPet = NULL;
	char confirm = 's';
	int count;
	int id;
	char name[128];

	if (path != NULL && pPets != NULL){
		FILE* fileR = fopen(path, "r");
		if (fileR != NULL){
			getChar("Existe otro archivo con el mismo nombre. Confirma sobreescribirlo? n(NO) - s(SI): ", &confirm);
			while (confirm != 'n' && confirm != 's'){
				getChar("Escriba n o s. Confirma sobreescribir el archivo? n(NO) - s(SI): ", &confirm);
			}
			fclose(fileR);
		}

		if (confirm == 's'){
			FILE* file = fopen(path, "w");
			if (file != NULL){
				result = 1;
				fprintf(file, "id,nombre\n"); //PRINT HEADER

				for (int i = 0; i < ll_len(pPets); i++){
					auxPet = (Pet*)ll_get(pPets, i);
					if (auxPet != NULL &&
						pet_getId(auxPet, &id) &&
						pet_getName(auxPet, name)){
						count = fprintf(file, "%d,%s\n", id, name);

						if (count < 2){
							result = 3;
							break;
						}
					}
					else{
						result = 4;
						break;
					}
				}
				fclose(file);
			}
			else{
				result = 2;
			}
		}
		else{
			result = 5;
		}
	}

    return result;
}



int controller_saveAsBinary(char* path, LinkedList* pPets)
{
	int result = 0;
	Pet* auxPet = NULL;
	char confirm = 's';
	int count;

	if (path != NULL && pPets != NULL){
		FILE* fileR = fopen(path, "r");
		if (fileR != NULL){
			getChar("Existe otro archivo con el mismo nombre. Confirma sobreescribirlo? n(NO) - s(SI): ", &confirm);
			while (confirm != 'n' && confirm != 's'){
				getChar("Escriba n o s. Confirma sobreescribir el archivo? n(NO) - s(SI): ", &confirm);
			}
			fclose(fileR);
		}

		if (confirm == 's'){
			FILE* file = fopen(path, "wb");
			if (file != NULL){
				result = 1;

				for (int i = 0; i < ll_len(pPets); i++){
					auxPet = (Pet*)ll_get(pPets, i);
					if (auxPet != NULL){
						count = fwrite(auxPet, sizeof(Pet), 1, file);

						if (count < 1){
							result = 3;
							break;
						}
					}
					else{
						result = 4;
						break;
					}
				}

				fclose(file);
			}
			else{
				result = 2;
			}
		}
		else{
			result = 5;
		}
	}

	return result;
}
