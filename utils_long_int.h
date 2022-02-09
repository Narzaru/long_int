#ifndef LONG_INT_UTILS__
#define LONG_INT_UTILS__

#include "types_long_int.h"

code_status_t init_long_int(long_int_t *value);  
code_status_t copy_long_int(long_int_t *dst, const long_int_t *src);  
void print_bin(long_int_t number, char bytes_delimiter, char end_char);  
sign_t get_sign(long_int_t src);  
code_status_t negate_long_int(long_int_t *src);  
code_status_t abs_long_int(long_int_t *src);  

#endif  // LONG_INT_UTILS_H
