#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calclib.h"

int main(int argc, char **argv) {
	formatValidator(argc, argv);
	int* arr = calculation(argc, argv);
	for(int i = 0; i < argc / 3 - 1; i++) {
		printf("Ответ №%d: %d \n", i + 1, arr[i]);
	}	
	char* vord = vordDecode(arr, argc / 3 - 1, atoi(argv[argc - 1]));
	printf("Результирующая строка: %s\n", vord);
	if(vord[argc / 3 - 1] == ' ') {
		printf("Непечатные символы заменены на \'#\'\n");
	}
	free(vord);
	free(arr);
}
