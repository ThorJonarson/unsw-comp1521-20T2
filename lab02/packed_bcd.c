#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#define N_BCD_DIGITS 8

uint32_t packed_bcd(uint32_t packed_bcd);

int main(int argc, char *argv[]) {

    for (int arg = 1; arg < argc; arg++) {
        long l = strtol(argv[arg], NULL, 0);
        assert(l >= 0 && l <= UINT32_MAX);
        uint32_t packed_bcd_value = l;

        printf("%lu\n", (unsigned long)packed_bcd(packed_bcd_value));
    }

    return 0;
}

// given a packed BCD encoded value between 0 .. 99999999
// return the corresponding integer
uint32_t packed_bcd(uint32_t packed_bcd_value) {

    // PUT YOUR CODE HERE
    int i = 0;
    uint32_t value = 0;
    int counter = N_BCD_DIGITS - 1;
    for (; i < N_BCD_DIGITS; i++) {
        int j = 0;
        int power = 1;
        for (; j < counter; j++)  {
            power *= 10;
        }
        int tmp = (packed_bcd_value >> ((N_BCD_DIGITS - 1 - i) * 4)) & 0xf;
        value += tmp * power;
        counter--;
    }
    return value;
}
