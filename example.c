#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "long_int.h"

int main() {
    long_int_t num1;
    long_int_t num2;
    long_int_t dst;

    int int_num1 = INT32_MAX;
    int int_num2 = INT32_MAX;

    init_long_int(&num1);
    init_long_int(&num2);
    init_long_int(&dst);

    from_int_to_long_int(int_num1, &num1);
    printf("[NUM1]\n");
    print_bin(num1, ' ', '\n');

    from_int_to_long_int(int_num2, &num2);
    printf("[NUM2]\n");
    print_bin(num2, ' ', '\n');

    div_long_int(num1, num2, &dst);
    printf("[dst = num1 %% num2]\n");
    print_bin(dst, ' ', '\n');


    printf("[dst SIGN]\n");
    get_sign(dst) == k_plus ? printf("k_plus\n") : printf("k_minus\n");

    printf("[num1 == num2 = ");
    is_equal_long_int(num1, num2) == true ? printf("true]\n") : printf("false]\n");

    printf("[num1 != num2 = ");
    is_not_equal_long_int(num1, num2) == true ? printf("true]\n") : printf("false]\n");

    printf("[num1 <  num2 = ");
    is_less_long_int(num1, num2) == true ? printf("true]\n") : printf("false]\n");

    printf("[num1 <= num2 = ");
    is_less_or_equal_long_int(num1, num2) == true ? printf("true]\n") : printf("false]\n");

    printf("[num1 >  num2 = ");
    is_greater_long_int(num1, num2) == true ? printf("true]\n") : printf("false]\n");

    printf("[num1 >= num2 = ");
    is_greater_or_equal_long_int(num1, num2) == true ? printf("true]\n") : printf("false]\n");

    return 0;
}
