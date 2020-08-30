

// not finished

#include <stdio.h>
#include <ctype.h>

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
    int character = fgetc(in);
    while (character != '\n' && character != EOF) {  
        character = fgetc(in);
    }
    if (character == '\n')
        character = fgetc(in);
    if (character == EOF) {
        fseek(in, 0, SEEK_SET);
        while ((character = fgetc(in)) != EOF) {
            fputc(character, stdout);
        }
        return 0;
    }
        
    long i = -2;
    fseek(in, i, SEEK_END);
    while (fgetc(in) != '\n') {
        i--;
        fseek(in, i, SEEK_END);
    }
    while ((character = fgetc(in)) != EOF) {
        fputc(character, stdout);
    }
    return 0;
}
