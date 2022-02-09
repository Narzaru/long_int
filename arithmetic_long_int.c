#include <stdlib.h>

#include "arithmetic_long_int.h"

#include "types_long_int.h"
#include "constants_long_int.h"

#include "convert_long_int.h"
#include "utils_long_int.h"
#include "bit_operation_long_int.h"
#include "boolean_long_int.h"

code_status_t add_long_int(long_int_t num1, long_int_t num2, long_int_t *dst) {
    code_status_t ret_val;

    if (dst == NULL) {
        ret_val = k_null_pointer;
    } else {
        uint16_t overflow_byte = 0;
        init_long_int(dst);

        for (ssize_t i = 0; i < LONG_INT_BYTES_COUNT; ++i) {
            uint16_t sum = num1.bytes[i] + num2.bytes[i] + overflow_byte;
            dst->bytes[i] = (uint8_t)sum;
            overflow_byte = (sum >> BYTE_BITS_COUNT);
        }

        if (overflow_byte > 0) {
            ret_val = k_overflow;
        } else {
            ret_val = k_succes;
        }
    }

    return ret_val;
}

code_status_t add_const(long_int_t *num1, int num2) {
    code_status_t ret_val;

    if (num1 == NULL) {
        ret_val = k_null_pointer;
    } else {
        long_int_t tmp;
        from_int_to_long_int(num2, &tmp);
        ret_val = add_long_int(*num1, tmp, num1);
    }

    return ret_val;
}

code_status_t sub_long_int(long_int_t num1, long_int_t num2, long_int_t *dst) {
    code_status_t ret_val;

    if (dst == NULL) {
        ret_val = k_null_pointer;
    } else {
        init_long_int(dst);

        negate_long_int(&num2);
        ret_val = add_long_int(num1, num2, dst);
    }

    return ret_val;
}

code_status_t mul_long_int(long_int_t num1, long_int_t num2, long_int_t *dst) {
    code_status_t ret_val;
    long_int_t tmp;

    if (dst == NULL) {
        ret_val = k_null_pointer;
    } else {
        init_long_int(dst);

        for (int i = 0; i < LONG_INT_BYTES_COUNT * BYTE_BITS_COUNT; ++i) {
            copy_long_int(&tmp, &num1);
            if ((num2.bytes[0] & 0x01) == 1) {
                shift_left(&tmp, i);
                add_long_int(*dst, tmp, dst);
            }
            shift_right(&num2, 1);
        }
        ret_val = k_succes;
    }

    return ret_val;
}

code_status_t div_long_int(long_int_t num1, long_int_t num2, long_int_t *dst) {
    code_status_t ret_val;

    if (dst == NULL) {
        ret_val = k_null_pointer;
    } else {
        long_int_t tmp;
        from_int_to_long_int(0, &tmp);
        if (is_equal_long_int(num2, tmp)) {
            ret_val = k_divide_by_zero;
        } else {
            ret_val = k_succes;
            init_long_int(dst);

            sign_t sign = (sign_t)(get_sign(num1) ^ get_sign(num2));
            abs_long_int(&num1);
            abs_long_int(&num2);

            while(is_greater_or_equal_long_int(num1, num2) == true) {
                add_const(dst, 1);
                sub_long_int(num1, num2, &num1);
            }

            if (sign == k_minus) {
                negate_long_int(dst);
            }
        }
    }

    return ret_val;
}

code_status_t mod_long_int(long_int_t num1, long_int_t num2, long_int_t *dst) {
    code_status_t ret_val;

    if (dst == NULL) {
        ret_val = k_null_pointer;
    } else {
        init_long_int(dst);

        long_int_t tmp;
        if (div_long_int(num1, num2, &tmp) == k_divide_by_zero) {
            ret_val = k_divide_by_zero;
        } else {
            mul_long_int(num2, tmp, &tmp);
            sub_long_int(num1, tmp, dst);
            ret_val = k_succes;
        }
    }

    return ret_val;
}