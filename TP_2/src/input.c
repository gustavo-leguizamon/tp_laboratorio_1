#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"

int getInt(char message[], int* input){
	int success = 0;

	if (input != NULL){
		printf("%s", message);
		scanf("%d", input);
		success = 1;
	}

	return success;
}

int getFloat(char message[], float* input){
	int success = 0;

	if (input != NULL){
		printf("%s", message);
		scanf("%f", input);

		success = 1;
	}

	return success;
}

int getString(char message[], char input[], int len){
	int success = 0;

	char auxStr[len];

	if (input != NULL){
		printf("%s", message);
		fflush(stdin);
		gets(auxStr);

		while (strlen(auxStr) > len){
			printf("Reingrese un texto mas corto, hasta %d carateres", len - 1);
			fflush(stdin);
			gets(auxStr);
		}

		strcpy(input, auxStr);

		success = 1;
	}

	return success;
}
