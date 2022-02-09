#ifndef LONG_INT_ARITHMETIC__
#define LONG_INT_ARITHMETIC__

#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>

#include "types_long_int.h"

code_status_t add_long_int(long_int_t num1, long_int_t num2, long_int_t *dst);  

code_status_t add_const(long_int_t *num1, int num2);  

code_status_t sub_long_int(long_int_t num1, long_int_t num2, long_int_t *dst);  

code_status_t mul_long_int(long_int_t num1, long_int_t num2, long_int_t *dst);  

code_status_t div_long_int(long_int_t num1, long_int_t num2, long_int_t *dst);  

code_status_t mod_long_int(long_int_t num1, long_int_t num2, long_int_t *dst);


#endif  // LONG_INT_ARITHMETIC__
