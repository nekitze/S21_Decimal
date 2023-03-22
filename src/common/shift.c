#include "../s21_decimal.h"

void right_shift(s21_decimal *value) {
  int old = 0;
  for (int i = 2; i >= 0; i--) {
    int new_bit = get_bit(value->bits[i], 0);
    value->bits[i] = value->bits[i] >> 1;
    set_bit(&(value->bits[i]), 31, old);
    old = new_bit;
  }
}

void left_shift(s21_decimal *value) {
  int old = 0;
  for (int i = 0; i < 3; i++) {
    int new_bit = get_bit(value->bits[i], 31);
    value->bits[i] = value->bits[i] << 1;
    set_bit(&(value->bits[i]), 0, old);
    old = new_bit;
  }
}

void left_shift_big(big_decimal *value) {
  int old = 0;
  for (int i = 0; i < 6; i++) {
    int new_bit = get_bit(value->bits[i], 31);
    value->bits[i] = value->bits[i] << 1;
    set_bit(&(value->bits[i]), 0, old);
    old = new_bit;
  }
}