#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    
    char *home = getenv("HOME");
    int length = strlen(home);
    char path[length + 10];
    snprintf(path, length + 8, "%s/.diary", home);
    FILE *in = fopen(path, "a");
    if (in == NULL) {
        fprintf(stderr, "wrong");
        exit(0);
    }
    for (int i = 1; i < argc; i++) {
        fprintf(in, "%s ", argv[i]);
    }
    fprintf(in, "\n");
    return 0;
}
