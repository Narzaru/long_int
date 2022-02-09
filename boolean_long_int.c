#include <sys/types.h>

#include "boolean_long_int.h"

#include "types_long_int.h"

#include "utils_long_int.h"
#include "bit_operation_long_int.h"

bool is_equal_long_int(long_int_t num1, long_int_t num2) {
    for (ssize_t i = 0; i < LONG_INT_BYTES_COUNT; ++i) {
        if (num1.bytes[i] != num2.bytes[i]) {
            return false;
        }
    }
    return true;
}

bool is_not_equal_long_int(long_int_t num1, long_int_t num2) {
    return !is_equal_long_int(num1, num2);
}

bool is_less_long_int(long_int_t num1, long_int_t num2) {
    long_int_t tmp;
    sign_t sign = (sign_t)(get_sign(num1) ^ get_sign(num2));

    xor_long_int(num1, num2, &tmp);

    for (ssize_t i = 0; i < LONG_INT_BYTES_COUNT; ++i) {
        for (ssize_t j = 0; j < BYTE_BITS_COUNT; ++j) {
            if(!!(tmp.bytes[LONG_INT_BYTES_COUNT - 1 - i] & (1u << (BYTE_BITS_COUNT - 1 - j))) == 1) {
                int a = !!((num1.bytes[LONG_INT_BYTES_COUNT - 1 - i]) & (1u << (BYTE_BITS_COUNT - 1 - j)));
                int b = !!((num2.bytes[LONG_INT_BYTES_COUNT - 1 - i]) & (1u << (BYTE_BITS_COUNT - 1 - j)));
                return (a < b) ^ sign;
            }
        }
    }
    return false;
}

bool is_less_or_equal_long_int(long_int_t num1, long_int_t num2) {
    return !is_greater_long_int(num1, num2);
}

bool is_greater_long_int(long_int_t num1, long_int_t num2) {
    return !is_less_long_int(num1, num2) && is_not_equal_long_int(num1, num2);
}

bool is_greater_or_equal_long_int(long_int_t num1, long_int_t num2) {
    return is_greater_long_int(num1, num2) || is_equal_long_int(num1, num2);
}
