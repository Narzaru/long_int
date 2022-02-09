#include <stddef.h>
#include <sys/types.h>

#include "convert_long_int.h"

#include "types_long_int.h"
#include "constants_long_int.h"

#include "utils_long_int.h"
#include "bit_operation_long_int.h"

code_status_t from_int_to_long_int(int src, long_int_t *dst) {
    code_status_t ret_val;
    if (dst == NULL) {
        ret_val = k_null_pointer;
    } else {
        ret_val = k_succes;

        init_long_int(dst);

        if (src < 0) {
            inverse_bit_long_int(dst);
        }

        int16_t test_value = 1;
        if (TO_P_UINT8(&test_value)[0] == 1) {
            for (ssize_t i = 0; i < ssizeof(int); ++i) {
                dst->bytes[i] = TO_P_UINT8(&src)[i];
            }
        } else {
            for (ssize_t i = ssizeof(int) - 1; i >= 0; --i) {
                dst->bytes[ssizeof(int) - 1 - i] = TO_P_UINT8(&src)[i];
            }
        }
    }

    return ret_val;
}