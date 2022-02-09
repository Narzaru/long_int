#include <stddef.h>
#include <sys/types.h>
#include <string.h>

#include "convert_long_int.h"

#include "types_long_int.h"
#include "constants_long_int.h"

#include "utils_long_int.h"
#include "bit_operation_long_int.h"
#include "boolean_long_int.h"
#include "arithmetic_long_int.h"

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

void strrev(char *src) {
    ssize_t i;
    ssize_t len;
    len = strlen(src);
    char temp;

    for (i = 0; i < len/2; i++) {
        temp = src[i];
        src[i] = src[len - i - 1];
        src[len - i - 1] = temp;
    }
}

char *from_long_int_to_str(long_int_t src, char *dst) {

    long_int_t zero;
    from_int_to_long_int(0, &zero);

    long_int_t ten;
    from_int_to_long_int(10, &ten);

    long_int_t tmp;

    ssize_t i = 0;

    while (is_not_equal_long_int(src, zero)) {
        mod_long_int(src, ten, &tmp);
        dst[i++] = '0' + tmp.bytes[0];
        div_long_int(src, ten, &src);
    }

    dst[i] = '\0';
    strrev(dst);
    return dst;
}
#undef BUF_LEN
