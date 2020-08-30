#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 1) {
        fprintf(stderr, "the number of arguments is wrong!");
        return 1;
    }
    FILE *in = fopen(argv[1], "w");
    if (in == NULL) {
        perror(argv[1]);
        return 1;
    }
    for (int i = 2; argv[i] != NULL; i++) {
        int number = atoi(argv[i]);
        fputc(number, in);
    }
    return 0;
}
