#include <stdio.h>
#include "s21_decimal.h"

int main() {
    // s21_decimal x;
    // x.bits[0] = 10;
    // x.bits[1] = 0;
    // x.bits[2] = 5;
    // x.bits[3] = 31;
    // set_bit(&(x.bits[0]), 31, 1);
    // // set_bit(&x, 3, 1);
    // // set_bit(&x, 3, 0);
    // s2_decimal_print(x);

    s21_decimal a = {{1, 2, 3, 0}};
    s21_decimal b = {{1, 2, 3, 0}};
    set_bit(&(b.bits[3]), 31, 0);
    s2_decimal_print(a);
    s2_decimal_print(b);

    // printf("%d\n", get_bit(x.bits[3], 4));
    printf("comparsion equal: %d\n", s21_is_equal(a, b));
    printf("comparsion not equal: %d\n", s21_is_not_equal(a, b));
}