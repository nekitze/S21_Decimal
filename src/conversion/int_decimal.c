#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {  // fixed
  int code = OK;
  s21_set_null(dst);
  if (!dst) {
    code = CONVERSION_ERROR;
  } else {
    if (src < 0) {
      src *= -1;
      set_sign(dst, 1);
    }
    dst->bits[0] = (unsigned int)src;
  }
  return code;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int code = 0;
  int sign = 0;
  sign = get_sign(src);
  *dst = 0;
  while (get_pow(src) > 0) {
    s21_drop_last_digit(&src);
    set_pow(&src, get_pow(src) - 1);
  }
  if (src.bits[1] || src.bits[2] || (get_bit(src.bits[0], 31) && !sign)) {
    code = 1;
  } else {
    *dst = src.bits[0];
    if (sign) *dst *= -1;
  }
  return code;
}