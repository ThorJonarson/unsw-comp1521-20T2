#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#include "add.h"

// return the MIPS opcode for add $d, $s, $t
uint32_t add(uint32_t d, uint32_t s, uint32_t t) {

    return (1 << 5) | (d << 11) | (t << 16) | (s << 21); // REPLACE WITH YOUR CODE

}
