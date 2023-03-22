#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  s21_set_null(result);
  *result = value;

  set_sign(result, !get_bit(value.bits[3], 31));

  return OK;
}
