#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

void numberValidator(char* str) {
	assert(str != NULL && *str != '\0' && "void symbol");
	assert((isdigit(*str) || *str == '-') && "not number");
	++str;
	while(*str) {
		assert(isdigit(*str) && "not number");
		++str;
	}
}

void formatValidator(int argc, char** argv) {
	assert(argc > 5 && "too few arguments");
	assert((strcmp(argv[argc - 2], "-k") == 0) && "no key -k");
	numberValidator(argv[argc - 1]);
	assert((argc % 3 == 0) && "wrong count arguments");
	for(int i = 0; i < (argc / 3) - 1; i++) {
		for(int j = 0; j < 3; j++) {
			if(j % 2 == 0) {
				numberValidator(argv[i * 3 + j + 1]);
			}
			else {		
				assert(strlen(argv[i * 3 + j + 1]) == 1 && "unknown operation");
				switch(argv[i * 3 + j + 1][0]) {
					case '+':
						break;
					case '-':
						break;
					case '*':
						break;
					case '%':
						break;
					default:
						assert(0 && "unknown operation");
				}
			}
		}
	}
}

int* calculation(int argc, char** argv) {
	int* arr = (int*)malloc((argc / 3 - 1) * sizeof(int));
	assert(arr != NULL && "memory allocation error");
	for(int i = 0; i < argc / 3 - 1; i++){
		switch(argv[i * 3 + 2][0]) {
			case '+':
				arr[i] = atoi(argv[i * 3 + 1]) + atoi(argv[i * 3 + 3]);
				break;
			case '-':
				arr[i] = atoi(argv[i * 3 + 1]) - atoi(argv[i * 3 + 3]);	
				break;
			case '*':
				arr[i] = atoi(argv[i * 3 + 1]) * atoi(argv[i * 3 + 3]);
			        break;
			case '%':
				arr[i] = atoi(argv[i * 3 + 1]) % atoi(argv[i * 3 + 3]);
				break;
		}	
	}	
	return arr;
}

char* vordDecode(int* numbers, int len, int key_num) { 
	char* arr = malloc((len + 1) * sizeof(char));
	assert(arr != NULL && "memory allocation error");
	arr[len] = 0;
	for(int i = 0; i < len; i++) {
		if(numbers[i] - key_num < 32 || numbers[i] - key_num > 126) {
			arr[len] = ' ';
			arr[i] = '#';
		}
		else {
			arr[i] = (char)(numbers[i] - key_num);
		}
	}
	return arr;
}
