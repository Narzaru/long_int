#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <stdio.h>

#include "utils_long_int.h"

#include "types_long_int.h"
#include "constants_long_int.h"
#include "bit_operation_long_int.h"
#include "arithmetic_long_int.h"


code_status_t init_long_int(long_int_t *value) {
    code_status_t ret_val;
    if (value == NULL) {
        ret_val = k_null_pointer;
    } else {
        ret_val = k_succes;
        memset(value, 0, sizeof(long_int_t));
    }
    return ret_val;
}

code_status_t copy_long_int(long_int_t *dst, const long_int_t *src) {
    code_status_t ret_val;
    if (dst == NULL || src == NULL) {
        ret_val = k_null_pointer;
    } else {
        ret_val = k_succes;
        for (int i = 0; i < LONG_INT_BYTES_COUNT; ++i) {
            dst->bytes[i] = src->bytes[i];
        }
    }
    return ret_val;
}

// [0..7] char bits, [8] '\0'
#define BUF_LEN 9
void print_bin(long_int_t number, char bytes_delimiter, char end_char) {
    char str_buf[BUF_LEN];

    for (ssize_t i = 0; i < LONG_INT_BYTES_COUNT; ++i) {
        for (ssize_t j = 0; j < BYTE_BITS_COUNT; ++j) {
            str_buf[BYTE_BITS_COUNT - 1 - j] = '0' + !!((number.bytes[i]) & (1u << j));
        }
        str_buf[BYTE_BITS_COUNT] = '\0';
        printf("%s%c", str_buf, bytes_delimiter);
    }

    printf("%c", end_char);
}
#undef BUF_LEN

sign_t get_sign(long_int_t src) {
    sign_t number_sign;

    if(((src.bytes[LONG_INT_BYTES_COUNT - 1]) & (1u << 7)) == k_plus) {
        number_sign = k_plus;
    } else {
        number_sign = k_minus;
    }

    return number_sign;
}

code_status_t negate_long_int(long_int_t *src) {
    code_status_t ret_val;
    if (src == NULL) {
        ret_val = k_null_pointer;
    } else {
        ret_val = k_succes;
        inverse_bit_long_int(src);
        add_const(src, 1);
    }
    return ret_val;
}

code_status_t abs_long_int(long_int_t *src) {
    code_status_t ret_val;
    if (src == NULL) {
        ret_val = k_null_pointer;
    } else {
        ret_val = k_succes;
        if (get_sign(*src) == k_minus) {
            negate_long_int(src);
        }
    }
    return ret_val;
}