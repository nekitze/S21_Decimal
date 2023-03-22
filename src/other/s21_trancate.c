#include "../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  s21_set_null(result);
  int sign = get_sign(value);
  *result = value;
  int pow = get_pow(value);
  for (int i = 0; i < pow; i++) s21_drop_last_digit(result);
  set_pow(result, 0);
  if (sign) set_sign(result, 1);

  return 0;
}
