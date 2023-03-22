#include "../s21_decimal.h"

int s21_is_equal(s21_decimal a, s21_decimal b) {
  int res = 0;
  s21_normalize(&a, &b);
  if (s21_as_uint(a.bits[0]) == s21_as_uint(b.bits[0]) &&
      s21_as_uint(a.bits[1]) == s21_as_uint(b.bits[1]) &&
      s21_as_uint(a.bits[2]) == s21_as_uint(b.bits[2]) &&
      get_sign(a) == get_sign(b) && get_pow(a) == get_pow(b))
    res = 1;
  else if (is_zero(a, b))
    res = 1;
  else
    res = 0;

  return res;
}
