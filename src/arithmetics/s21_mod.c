#include "../s21_decimal.h"

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int is_result_subzero = 0;
  int is_err = 0;
  int count_int = 0;

  if (is_zero(value_2, value_2)) return 3;
  if (is_zero(value_1, value_1)) {
    *result = value_1;
    return 0;
  }

  if (s21_is_less(value_1, value_2) && !get_sign(value_1)) {
    *result = value_1;
    return 0;
  }

  *result = value_1;
  s21_decimal divider = value_2;

  if (get_sign(*result)) {
    set_sign(result, 0);
    is_result_subzero = 1;
  }

  if (get_sign(divider)) {
    set_sign(&divider, 0);
  }

  s21_decimal count;
  s21_decimal sub;

  is_err = s21_div(*result, divider, &count);
  if (is_err) return is_err;

  s21_from_decimal_to_int(count, &count_int);
  s21_from_int_to_decimal(count_int, &count);

  is_err = s21_mul(count, divider, &sub);
  if (is_err) return is_err;

  is_err = s21_sub(*result, sub, result);
  if (is_err) return is_err;

  if (is_result_subzero) set_sign(result, 1);

  return 0;
}