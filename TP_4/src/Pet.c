#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <ctype.h>
#include "../inc/Pet.h"
#include "../inc/input.h"
#include "../inc/myString.h"


Pet* pet_new(){
	Pet* newPet = NULL;

	newPet = (Pet*)malloc(sizeof(Pet)); //calloc(cantidad, sizeof) //inicializa estrustura en vacios
	if (newPet != NULL){
		newPet->id = 0;
		strcpy(newPet->name, "");
	}

	return newPet;
}



Pet* pet_newParameters(int id, char* name){
	Pet* newPet;

	newPet = pet_new();
	if (newPet != NULL){
		if (!(pet_setId(newPet, id) &&
			  pet_setName(newPet, name))){
			free(newPet);
			newPet = NULL;
		}
	}

	return newPet;
}



Pet* pet_newParametersStr(char* idStr, char* nameStr){
	return pet_newParameters(atoi(idStr), nameStr);
}


//GETTERS
int pet_getId(Pet* this, int* pId){
	int success = 0;

	if (this != NULL && pId != NULL){
		*pId = this->id;
		success = 1;
	}

	return success;
}


int pet_getName(Pet* this, char* pName){
	int success = 0;

	if (this != NULL && pName != NULL){
		strcpy(pName, this->name);
		success = 1;
	}

	return success;
}


//SETTERS
int pet_setId(Pet* this, int id){
	int success = 0;

	if (this != NULL && id > 0){
		this->id = id;
		success = 1;
	}

	return success;
}


int pet_setName(Pet* this, char* name){
	int success = 0;

	if (this != NULL && name != NULL && strlen(name) > 0 && strlen(name) < 128){
		strcpy(this->name, name);
		success = 1;
	}

	return success;
}



int pet_delete(Pet* pPet){
	int result = 0;

	if (pPet != NULL){
		free(pPet);
		result = 1;
	}

	return result;
}


int pet_findHighestId(LinkedList* pArrayLinkedList, int* pId){
	int result = 0;
	int highestId;
	Pet* auxPet = NULL;

	if (pArrayLinkedList != NULL && pId != NULL){
		for (int i = 0; i < ll_len(pArrayLinkedList); i++){
			auxPet = ll_get(pArrayLinkedList, i);
			if (i == 0 || auxPet->id > highestId){
				highestId = auxPet->id;
			}
		}

		*pId = highestId + 1;
		result = 1;
	}

	return result;
}


int pet_chargeData(char* pName){
	int result = 0;

	if (pName != NULL){

		getString("Ingrese nombre: ", pName, 128);
		while (strlen(pName) > 128){
			puts("El nombre no es valido");
			getString("Ingrese nombre: ", pName, 128);
		}
		capitalize(pName);
		
		result = 1;
	}

	return result;
}



void pet_printHeaderReport(){
	printf("| %4s | %-20s |\n", "ID", "NOMBRE");
}


int pet_showPet(Pet* pPet){
	int result = 0;
	int id;
	char name[128];

	if (pPet != NULL &&
		pet_getId(pPet, &id) &&
		pet_getName(pPet, name)){
		printf("| %4d | %-20s |\n", id, name);
	}

	return result;
}


int pet_showPets(LinkedList* pPets){
	int result = 0;
	Pet* auxPet = NULL;

	if (pPets != NULL){
		//printHeader(columns, lengths, lenColumns);
		pet_printHeaderReport();
		for (int i = 0; i < ll_len(pPets); i++){
			auxPet = (Pet*)ll_get(pPets, i);
			pet_showPet(auxPet);
			//printFooter(lengths, lenColumns);
		}
		result = 1;
	}

    return result;
}






int pet_compareById(void* pPetA, void* pPetB){
	int result = -2;
	Pet* auxPetA = NULL;
	Pet* auxPetB = NULL;

	if (pPetA != NULL && pPetB != NULL){
		auxPetA = (Pet*)pPetA;
		auxPetB = (Pet*)pPetB;

		if (auxPetA->id > auxPetB->id){
			result = 1;
		}
		else if (auxPetA->id < auxPetB->id){
			result = -1;
		}
		else{
			result = 0;
		}
	}

	return result;
}


int pet_compareByName(void* pPetA, void* pPetB){
	int result = -2;
	Pet* auxPetA = NULL;
	Pet* auxPetB = NULL;

	if (pPetA != NULL && pPetB != NULL){
		auxPetA = (Pet*)pPetA;
		auxPetB = (Pet*)pPetB;

		result = strcmp(auxPetA->name, auxPetB->name);
	}

	return result;
}




int pet_validateId(LinkedList* pArrayLinkedList, int id){
	int index = -1;
	Pet* auxPet = NULL;
	int length;

	if (pArrayLinkedList != NULL){
		length = ll_len(pArrayLinkedList);
		for (int i = 0; i < length; i++){
			auxPet = (Pet*)ll_get(pArrayLinkedList, i);
			if (auxPet->id == id){
				index = i;
				break;
			}
		}
	}

	return index;
}
