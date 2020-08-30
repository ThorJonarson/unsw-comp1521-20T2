#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *in = fopen(argv[1], "r");
    int counter = 0;
    int character;
    while ((character = fgetc(in)) != EOF) {
        if (character >= 0 && character <= 127)
            counter++;
    }
    printf("%s: %d UTF-8 characters\n", argv[1], counter);
    return 0;
}
