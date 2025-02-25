#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	/*This ought to be simple file I/O. Basically file open 
	 * based on path and then all that needs to be done is to
	 * store into buffer and print contents.
	 *
	 * TODO: ADD SUPPORT FOR MULTIPLE FILES!!! PLEASE*/	
	if (argc < 2) {
		return 0;
	}
	char buffer[256];
	FILE* file;
	for (int i = 1; i < argc; i++) {
		char* fname = malloc(strlen(argv[i]) + 1);
		strcpy(fname, argv[i]);
		if ((file = fopen(fname, "r")) == NULL) {
			printf("wcat: cannot open file\n");
			return 1;
		}
		while(fgets(buffer, sizeof(buffer), file) != NULL) {
			printf("%s", buffer);
		}
		fclose(file);
		free(fname);
	}
	return 0;
}
