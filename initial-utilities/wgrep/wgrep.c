#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <sys/types.h>

int main(int argc, char* argv[]) {
    /*General approach here: More File I/O
    Read argv[1] from the input and that becomes target
    check all args after and open them as files.
    Do this, and print out all lines with a match*/
    if (argc < 2) {
        printf("wgrep: searchterm [file ...]\n");
        return 1;
    }
    
    FILE* file;
    char buf[256];
    char* line = NULL;
    ssize_t l_read;
    ssize_t len = 0;
    char* tgt = malloc(strlen(argv[1]) + 1);
    strcpy(tgt, argv[1]);

    if (argc == 2) {
        while ((fgets(buf, sizeof(buf), stdin)) != NULL) {
            if (strstr(buf, tgt) != NULL) {
                printf("%s", buf);
            }
        }
        return 0;
        //TODO: now read with fgets and use similar comparison logic
        //maybe make a function for strstr logic.
        //at this point i just need to handle stdout now
    }

    for (size_t i = 2; i < argc; i++) {
        char* fname = malloc(strlen(argv[i]) + 1);
        strcpy(fname, argv[i]);
        if ((file = fopen(fname, "r")) == NULL) {
            printf("wgrep: cannot open file\n");
            free(fname);
            return 1;
        }
        while ((l_read = getline(&line, &len, file)) != -1) {
            if (strstr(line, tgt) != NULL) {
                printf("%s", line);
            }
        }
        free(fname);
        line = NULL; //need to do this to not reuse the pointer
    }

    return 0;
}