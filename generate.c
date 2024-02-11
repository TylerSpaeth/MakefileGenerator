#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]) {

	char *template = NULL; 
	char *cfile = NULL;

	template = argv[1];
	cfile = argv[2];

	FILE *fptr; // template file ptr
	FILE *nfptr; // new file ptr

	fptr = fopen(template, "r");
	if(fptr == NULL) {
		printf("Failed to open template file.");
		exit(1);
	}

	nfptr = fopen("Makefile", "w+");
	if(nfptr == NULL) {
		printf("Failed to open new Makefile.");
		exit(1);
	}

	char current;

	do {
		current = fgetc(fptr);
		if(feof(fptr)) break;
		if(current == '@') {
			for(int i = 0; i < strlen(cfile); i++) {
				putc(cfile[i], nfptr);
			}
		}
		else {
			putc(current, nfptr);
		}
	}while(1);
	
	fclose(fptr);
	fclose(nfptr);

	return 0;
}
