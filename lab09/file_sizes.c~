#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    long total = 0;
    for (int arg = 1; arg < argc; arg++) {
        struct stat s;
        stat(argv[arg], &s);
        printf("%s: %ld bytes\n", argv[arg], (long)s.st_size);
        total += (long)s.st_size;
    }
    printf("Total: %ld bytes\n", total);
}
