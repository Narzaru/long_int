#ifndef LONG_INT_BOOLEAN__
#define LONG_INT_BOOLEAN__

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

bool is_equal_long_int(int8_t *num1, int8_t *num2, size_t arrays_size);

bool is_not_equal_long_int(int8_t *num1, int8_t *num2, size_t arrays_size);

bool is_less_long_int(int8_t *num1, int8_t *num2, size_t arrays_size);

bool is_less_or_equal(int8_t *num1, int8_t *num2, size_t arrays_size);

bool is_greater(int8_t *num1, int8_t *num2, size_t arrays_size);

bool is_greater_or_equal(int8_t *num1, int8_t *num2, size_t arrays_size);

#endif  // LONG_INT_BOOLEAN_H_
