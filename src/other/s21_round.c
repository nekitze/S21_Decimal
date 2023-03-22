#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  s21_decimal half = {{5}};
  set_pow(&half, 1);
  s21_set_null(result);
  int pow = get_pow(value);
  *result = value;

  if (pow) {
    if (get_sign(value)) {
      s21_sub(value, half, result);  // - 0.5
    } else {
      s21_add(value, half, result);  // + 0.5
    }
  }
  s21_truncate(*result, result);
  return 0;
}