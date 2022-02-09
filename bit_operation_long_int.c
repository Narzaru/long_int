#include <stddef.h>
#include <sys/types.h>

#include "bit_operation_long_int.h"

#include "types_long_int.h"
#include "constants_long_int.h"

code_status_t inverse_bit(long_int_t *num) {
    code_status_t ret_val;

    if (num == NULL) {
        ret_val = k_null_pointer;
    } else {
        ret_val = k_succes;
        for (int i = 0; i < LONG_INT_BYTES_COUNT; ++i) {
            num->bytes[i] = ~(num->bytes[i]);
        }
    }
    return ret_val;
}

code_status_t shift_left(long_int_t *num, uint32_t shift) {
    code_status_t ret_val;

    if (num == NULL) {
        ret_val = k_null_pointer;
    } else {
        if (shift >= LONG_INT_BYTES_COUNT * BYTE_BITS_COUNT) {
            shift = LONG_INT_BYTES_COUNT * BYTE_BITS_COUNT;
        }

        for (ssize_t i = 0; i < shift; ++i) {
            uint16_t carying_shift = 0;
            for (ssize_t j = 0; j < LONG_INT_BYTES_COUNT; ++j) {
                carying_shift = (num->bytes[j] << 1) + carying_shift;
                num->bytes[j] = (uint8_t)carying_shift;
                carying_shift = (carying_shift >> BYTE_BITS_COUNT);
            }
            if (carying_shift > 0) {
                ret_val = k_overflow;
            }
        }

        if (ret_val != k_overflow) {
            ret_val = k_succes;
        }
    }

    return ret_val;
}

code_status_t shift_right(long_int_t *num, uint32_t shift) {
    code_status_t ret_val;

    if (num == NULL) {
        ret_val = k_null_pointer;
    } else {
        if (shift >= LONG_INT_BYTES_COUNT * BYTE_BITS_COUNT) {
            shift = LONG_INT_BYTES_COUNT * BYTE_BITS_COUNT;
        }

        for (ssize_t i = 0; i < shift; ++i) {
            uint16_t carying_shift = (uint16_t)num->bytes[0] & 0x01;
            for (ssize_t j = 0; j < LONG_INT_BYTES_COUNT - 1; ++j) {
                num->bytes[j] = num->bytes[j] >> 1u;
                num->bytes[j] = num->bytes[j] +  ((num->bytes[j + 1] & 1u) << 7);
            }
            num->bytes[LONG_INT_BYTES_COUNT - 1] = num->bytes[LONG_INT_BYTES_COUNT - 1] >> 1u;

            if (carying_shift > 0) {
                ret_val = k_overflow;
            }
        }

        if (ret_val != k_overflow) {
            ret_val = k_succes;
        }
    }

    return ret_val;
}
