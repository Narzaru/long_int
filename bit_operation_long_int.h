#ifndef LONG_INT_BIT_OPERATIONS__
#define LONG_INT_BIT_OPERATIONS__

#include "types_long_int.h"

code_status_t inverse_bit_long_int(long_int_t *num);  

code_status_t xor_long_int(long_int_t num1, long_int_t num2, long_int_t *dst);  

code_status_t and_long_int(long_int_t num1, long_int_t num2, long_int_t *dst);

code_status_t orr_long_int(long_int_t num1, long_int_t num2, long_int_t *dst);

code_status_t shift_left(long_int_t *num, uint32_t shift);  

code_status_t shift_right(long_int_t *num, uint32_t shift);  

#endif  // LONG_INT_BIT_OPERATIONS__
