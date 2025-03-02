#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    /* RLE implementation - count char occurences with a ptr probably
    then you just need to add that to the output.*/
    FILE* file;
    char* fname;
    char buf[256];
    for (size_t i = 1; i < argc; i++) {
        fname = malloc(strlen(argv[i]) + 1);
        if ((file = fopen(fname, "r")) == NULL) {
            return 1;
        }
        while (fgets(buf, sizeof(buf), file)) {
            
        }
    }
}