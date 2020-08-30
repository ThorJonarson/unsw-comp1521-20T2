#include <ctype.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "the number of arguments is wrong!");
        return 1;
    }
    FILE *in = fopen(argv[1], "r");
    if (in == NULL) {
        perror("argv[1]");
        return 1;
    }
    long i = 0;
    int character = fgetc(in);
    while (character != EOF) {
        printf("byte %4ld: %3d 0x%02x", i, character, character);
        if (isprint(character))
            printf(" '%c'", character);
        printf("\n");
        i++;
        character = fgetc(in);
    }
    return 0;
}
