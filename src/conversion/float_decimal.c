#include "../s21_decimal.h"

int s21_float_to_decimal(s21_decimal *dst, float src) {
  src = src;
  int code = 0;
  if (!dst) {
    code = CONVERSION_ERROR;
  } else {
    // CODE
  }
  return code;
}

unsigned int s21_get_float_pow(float src) {
  unsigned int pow = 0;
  unsigned int my_float = *((unsigned int *)&src);
  for (int i = 23, y = 0; i < 31; i++, y++) {
    pow = pow | (my_float & (1 << i));
  }
  return pow;
}

