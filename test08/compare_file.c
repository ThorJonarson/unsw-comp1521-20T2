#include <stdio.h>


int main(int argc, char *argv[]) {
    
    FILE *in1 = fopen(argv[1], "r");
    FILE *in2 = fopen(argv[2], "r");
    int character1 = fgetc(in1);
    int character2 = fgetc(in2);
    int i = 0;
    while (character1 != EOF && character2 != EOF) {
        if (character1 != character2){
            printf("Files differ at byte %d\n", i);
            return 0;
        }
        i++;
        character1 = fgetc(in1);
        character2 = fgetc(in2);
    }
    if (character1 != EOF) {
        printf("EOF on %s\n", argv[2]);
        return 0;
    }
    if (character2 != EOF) {
        printf("EOF on %s\n", argv[1]);
        return 0;
    }
    printf("Files are identical\n");
    return 0;
}
