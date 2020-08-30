// swap pairs of bits of a 64-bit value, using bitwise operators

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
// return value with pairs of bits swapped
uint64_t bit_swap(uint64_t value) {
    // PUT YOUR CODE HERE
    uint64_t number1 = 0;
    uint64_t number2 = 0;
    //uint64_t tmp = 0x3;
    //for (int i = 31; i > 0; i = i - 2) {
        //number |= (value & (tmp << (31 - i))) << (i * 2);
        //number |= (value & (tmp << (31 + i))) >> (i * 2);
    //}
    number1 = 0xaaaaaaaaaaaaaaaa & (value << 1);
    number2 = 0x5555555555555555 & (value >> 1);
    return number1 | number2;
}
