#ifndef LONG_INT_BOOLEAN__
#define LONG_INT_BOOLEAN__

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "types_long_int.h"

bool is_equal_long_int(long_int_t num1, long_int_t num2);  

bool is_not_equal_long_int(long_int_t num1, long_int_t num2); 

bool is_less_long_int(long_int_t num1, long_int_t num2);  

bool is_less_or_equal_long_int(long_int_t num1, long_int_t num2); 

bool is_greater_long_int(long_int_t num1, long_int_t num2);  

bool is_greater_or_equal_long_int(long_int_t num1, long_int_t num2);  

#endif  // LONG_INT_BOOLEAN_H_
