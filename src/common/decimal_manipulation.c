#include "../s21_decimal.h"

// перед сдачей из функции печати удалить инт128!!!!

void set_sign(s21_decimal *dst, int sign) {
  set_bit(&((dst->bits)[3]), 31, sign);
}

int get_sign(s21_decimal src) { return get_bit(src.bits[3], 31); }

int get_pow(s21_decimal src) {
  int dst = 0;
  for (int i = 16; i <= 23; i++) {
    dst += get_bit(src.bits[3], i) * ((int)pow(2, i - 16));
  }
  return dst;
}

int set_pow(s21_decimal *dst, int value) {
  int sign = get_sign(*dst);
  if (value < 0 || value > 28) {
    return 1;
  }
  (dst->bits)[3] = 0;
  int id = 0;
  while (value > 0) {
    set_bit(&((dst->bits)[3]), 16 + id, value % 2);
    value /= 2;
    id++;
  }
  set_sign(dst, sign);
  return 0;
}

void s21_set_null(s21_decimal *src) {
  for (int i = 0; i < 4; i++) {
    src->bits[i] = 0;
  }
}

int s21_normalize(s21_decimal *x1, s21_decimal *x2) {
  int check = 0;
  s21_decimal *x_fix;
  int diff;
  if (get_pow(*x1) <= get_pow(*x2)) {
    x_fix = x1;
    diff = get_pow(*x2) - get_pow(*x1);
  } else {
    x_fix = x2;
    diff = get_pow(*x1) - get_pow(*x2);
  }
  while (diff--) {
    s21_decimal x = {{10, 0, 0, 0}};
    check = s21_mul(*x_fix, x, x_fix);
    if (check) break;
    set_pow(x_fix, get_pow(*x_fix) + 1);
  }
  return check;
}

unsigned int s21_as_uint(int x) { return *((unsigned int *)&x); }

int s21_as_int(unsigned int x) { return *((int *)&x); }

int s21_drop_last_digit(s21_decimal *src) {
  unsigned long long last, div;

  last = s21_as_uint(src->bits[2]);
  div = last % 10;
  src->bits[2] = s21_as_int((unsigned int)(last / 10));

  last = s21_as_uint(src->bits[1]) + div * S21_2IN32;
  div = last % 10;
  src->bits[1] = s21_as_int((unsigned int)(last / 10));

  last = s21_as_uint(src->bits[0]) + div * S21_2IN32;
  div = last % 10;
  src->bits[0] = s21_as_int((unsigned int)(last / 10));
  return (int)div;
}
