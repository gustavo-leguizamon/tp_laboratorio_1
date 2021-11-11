
#include "output.h"

int printHeader(char columnNames[][128], int columnLengths[], int lenColumns){
	int success = 0;
	int totalLen = 0;
	int leftLen;

	if (columnNames != NULL && columnLengths != NULL && lenColumns > 0){
		for (int i = 0; i < lenColumns; i++){
			totalLen += columnLengths[i];
		}

		printf(" ");
		for (int i = 0; i < totalLen + lenColumns - 1; i++){
			printf("_");
		}

		printf("\n|");
		for (int i = 0; i < lenColumns; i++){
			printf(" %s ", columnNames[i]);
			leftLen = columnLengths[i] - strlen(columnNames[i]) - 2;
			for (int j = 0; j < leftLen; j++){
				printf(" ");
			}
			printf("|");
		}

		printf("\n");
		printFooter(columnLengths, lenColumns);
	}

	return success;
}

int printFooter(int columnLengths[], int lenColumns){
	int success = 0;

	if (columnLengths != NULL && lenColumns > 0){
		printf("|");
		for (int i = 0; i < lenColumns; i++){
			for (int j = 0; j < columnLengths[i]; j++){
				printf("_");
			}
			printf("|");
		}
		printf("\n");
	}

	return success;
}
