#ifndef LONG_INT_TYPES__
#define LONG_INT_TYPES__

// standard libraries
#include <stdint.h>

// long int libraries
#include "constants_long_int.h"

typedef enum code_status {
    k_succes = 0,
    k_null_pointer = 1,
    k_overflow = 2,
    k_content_error = 3,
    k_malloc_error = 4
} code_status_t;

typedef enum sign {
    k_plus = 0,
    k_minus = 1,
} sign_t;

typedef enum notation {
    k_little_endian = 0,
    k_big_endian = 1,
} notation_t;

typedef struct long_int {
    uint8_t bytes[LONG_INT_BYTES_COUNT];
} long_int_t;

#endif  // LONG_INT_TYPES__
