// print 5 numbers

#include <stdio.h>

int numbers[5] = { 3, 9, 27, 81, 243};

int main(void) {
    int i = 0;
loop:
    if (i >= 5) goto end;
        int j = numbers[i];
        printf("%d", j);
        printf("%c", '\n');
        i++;
    goto loop;
end:
    return 0;
}
