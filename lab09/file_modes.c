#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

    for (int arg = 1; arg < argc; arg++) {
        struct stat s;
        stat(argv[arg], &s);
        if (((s.st_mode) & S_IFDIR) == S_IFDIR)
            printf("d");
        else
            printf("-");
        if (((s.st_mode) & S_IRUSR) == S_IRUSR)
            printf("r");
        else
            printf("-");
        if (((s.st_mode) & S_IWUSR) == S_IWUSR)
            printf("w");
        else
            printf("-");
        if (((s.st_mode) & S_IXUSR) == S_IXUSR)
            printf("x");
        else
            printf("-");
        if (((s.st_mode) & S_IRGRP) == S_IRGRP)
            printf("r");
        else
            printf("-");
        if (((s.st_mode) & S_IWGRP) == S_IWGRP)
            printf("w");
        else
            printf("-");
        if (((s.st_mode) & S_IXGRP) == S_IXGRP)
            printf("x");
        else
            printf("-");
        if (((s.st_mode) & S_IROTH) == S_IROTH)
            printf("r");
        else
            printf("-");
        if (((s.st_mode) & S_IWOTH) == S_IWOTH)
            printf("w");
        else
            printf("-");
        if (((s.st_mode) & S_IXOTH) == S_IXOTH)
            printf("x");
        else
            printf("-");
        
        printf(" %s\n", argv[arg]);

    }
}
