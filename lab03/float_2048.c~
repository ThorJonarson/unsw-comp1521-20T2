// Multiply a float by 2048 using bit operations only

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#include "floats.h"

// float_2048 is given the bits of a float f as a uint32_t
// it uses bit operations and + to calculate f * 2048
// and returns the bits of this value as a uint32_t
//
// if the result is too large to be represented as a float +inf or -inf is returned
//
// if f is +0, -0, +inf or -int, or Nan it is returned unchanged
//
// float_2048 assumes f is not a denormal number
//
uint32_t float_2048(uint32_t f) {
    // PUT YOUR CODE HERE
    float_components_t comp = float_bits(f);
    if (is_nan(comp) || is_negative_infinity(comp)) {
        return f;
    } else if (is_positive_infinity(comp) || is_zero(comp)) {
        return f;
    }
    comp.exponent += 11;
    if (comp.exponent >= 0xff) {
        if (comp.sign == 1) {
            uint32_t num1 = 0;
            num1 |= 1 << 31;
            num1 |= 0xff << 23;
            return num1;
        } else {
            uint32_t num2 = 0;
            num2 |= 0xff << 23;
            return num2;
        }
    }
    uint32_t number = 0;
    number |= comp.sign << 31;
    number |= comp.exponent << 23;
    number |= comp.fraction;
    return number;
}

// separate out the 3 components of a float
float_components_t float_bits(uint32_t f) {
    // PUT YOUR CODE HERE
    float_components_t comp;
    //the sign
    if ((f >> 31) | 0) {
        comp.sign = 1;
    } else {
        comp.sign = 0;
    }
    //next 8 bits
    uint32_t num = (f >> 23) & 0xff;
    comp.exponent = num;
    //last 23 bits
    uint32_t i = 0xffffffff >> 9;
    comp.fraction = f & i;
    return comp;
}

// given the 3 components of a float
// return 1 if it is NaN, 0 otherwise
int is_nan(float_components_t f) {
    // PUT YOUR CODE HERE
    if ((f.exponent == 0xff) && (f.fraction != 0)) {
        return 1;
    } else {
        return 0;
    }
}

// given the 3 components of a float
// return 1 if it is inf, 0 otherwise
int is_positive_infinity(float_components_t f) {
    // PUT YOUR CODE HERE
    if ((f.exponent == 0xff) && (f.fraction == 0) && (f.sign == 0)) {
        return 1;
    } else {
        return 0;
    }
}

// given the 3 components of a float
// return 1 if it is -inf, 0 otherwise
int is_negative_infinity(float_components_t f) {
    // PUT YOUR CODE HERE
    if ((f.exponent == 0xff) && (f.fraction == 0) && (f.sign == 1)) {
        return 1;
    } else {
        return 0;
    }
}

// given the 3 components of a float
// return 1 if it is 0 or -0, 0 otherwise
int is_zero(float_components_t f) {
    // PUT YOUR CODE HERE
    if ((f.exponent == 0) && (f.fraction == 0)) {
        return 1;
    } else {
        return 0;
    }
}
