#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "long_int.h"

#define ELEM_COUNT 8
int main() {
    long_int_t num1;
    long_int_t num2;
    long_int_t dst;

    init_long_int(&num1);
    init_long_int(&num2);
    init_long_int(&dst);

    from_int_to_long_int(-5, &num1);
    printf("[NUM1]\n");
    print_bin(num1, ' ', '\n');

    from_int_to_long_int(-5, &num2);
    printf("[NUM2]\n");
    print_bin(num2, ' ', '\n');

    sub_long_int(num1, num2, &dst);
    printf("[dst = num1 + num2]\n");
    print_bin(dst, ' ', '\n');


    printf("[dst SIGN]\n");
    get_sign(dst) == k_plus ? printf("k_plus") : printf("k_minus");

    return 0;
}
