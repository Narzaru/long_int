#ifndef LONG_INT_CONVERTS__
#define LONG_INT_CONVERTS__

#include "types_long_int.h"

code_status_t from_int_to_long_int(int src, long_int_t *dst);  
char *from_long_int_to_str(long_int_t src, char *dst);

#endif // !LONG_INT_CONVERTS
