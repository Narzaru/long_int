#ifndef LONG_INT_UTILS__
#define LONG_INT_UTILS__

#include "types_long_int.h"

code_status_t init_long_int(long_int_t *value);  //!COMPLETE
code_status_t copy_long_int(long_int_t *dst, const long_int_t *src);  //!COMPLETE
void print_bin(long_int_t number, char bytes_delimiter, char end_char);  //!COMPLETE
sign_t get_sign(long_int_t src);  //!COMPLETE

#endif  // LONG_INT_UTILS_H
