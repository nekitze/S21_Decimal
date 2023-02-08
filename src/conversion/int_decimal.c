#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {  // fixed
  int code = OK;
  if (!dst) {
    code = CONVERSION_ERROR;
  } else {
    s21_set_null(dst);
    if (src < 0) {
      src *= -1;
      set_sign(dst, 1);
    }
    dst->bits[0] = (unsigned int)src;
  }
  return code;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {  // needs more debug
  *dst = 0;
  while (get_pow(src) > 0) {
    s21_drop_last_digit(&src);
    set_pow(&src, get_pow(src) - 1);
  }
  *dst = (int)s21_as_uint(src.bits[0]);
  return 0;
}