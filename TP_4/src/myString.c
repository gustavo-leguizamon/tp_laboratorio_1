#ifndef SRC_MYSTRING_C_
#define SRC_MYSTRING_C_



#endif /* SRC_MYSTRING_C_ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../inc/myString.h"

int capitalize(char* text){
	int result = 0;
	int i;

	if (text != NULL){
		if (strlen(text) > 0){
			strlwr(text);
			text[0] = toupper(text[0]);
			i = 1;
			while (text[i] != CHAR_NULL){
				if (text[i] == ' '){
					text[i + 1] = toupper(text[i + 1]);
				}
				i++;
			}

			result = 1;
		}
	}

	return result;
}
