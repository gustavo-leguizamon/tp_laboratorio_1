#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <ctype.h>
#include "../inc/Pet.h"


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
