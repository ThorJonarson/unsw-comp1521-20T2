#include <stdlib.h>
#include <stdio.h>
#include <string.h>



int main(int argc, char *argv[]) {
    char *env = getenv(argv[1]);
    if (env == NULL || strcmp(env, "") == 0) {
        printf("0\n");
        return 0;
    }
    printf("1\n");
    return 0;
}
