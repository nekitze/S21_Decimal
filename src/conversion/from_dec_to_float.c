#include "../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int return_code = OK;

  if (!dst) {
    return_code = 1;
  } else {
    double reserve = 0;
    for (int i = 0; i < 96; i++)
      if (src.bits[i / 32] & (1u << (i % 32))) reserve += pow(2, i);
    int sign = (src.bits[3] < 0) ? 1 : 0;
    int ten_pow = (src.bits[3] << 1) >> 17;
    if (ten_pow >= 0) {
      if (ten_pow > 28) {
        *dst = 0;
        return_code = 1;
      } else {
        for (int i = ten_pow; i > 0; i--) {
          reserve /= 10;
        }
        *dst = (float)reserve;
        if (sign) *dst *= -1;
      }
    }
  }
  return return_code;
}