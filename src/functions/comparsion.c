#include "../s21_decimal.h"

// int s21_is_less(s21_decimal, s21_decimal);
// int s21_is_less_or_equal(s21_decimal, s21_decimal);
// int s21_is_greater(s21_decimal, s21_decimal);
// int s21_is_greater_or_equal(s21_decimal, s21_decimal);

int s21_is_equal(s21_decimal a, s21_decimal b) {
    if(a.bits[0] == b.bits[0] && a.bits[1] == b.bits[1] 
    && a.bits[2] == b.bits[2] &&
    get_sign(a) == get_sign(b) &&
    get_pow(a) == get_pow(b)) return 1;
    else return 0;
}

int s21_is_not_equal(s21_decimal a, s21_decimal b) {
    return !s21_is_equal(a, b);
}