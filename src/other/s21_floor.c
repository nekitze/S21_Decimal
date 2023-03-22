#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  s21_set_null(result);
  *result = value;
  const s21_decimal one = {{1}};
  int sign = get_sign(value);
  set_sign(result, sign);
  s21_truncate(*result, result);
  if (get_sign(value) && get_pow(value)) {
    s21_sub(*result, one, result);
  }

  return 0;
}
