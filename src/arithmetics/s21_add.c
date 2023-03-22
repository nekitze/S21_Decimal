#include "../s21_decimal.h"
#include "s21_mul.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int check = 0;
  int sign = 0;
  if (get_sign(value_1) == 0 && get_sign(value_2) == 0) {
    // v1 + v2
    s21_set_null(result);
    check = basic_add(value_1, value_2, result, 0);
  } else if (get_sign(value_1) == 0 && get_sign(value_2) == 1) {
    // v1 - v2;
    s21_set_null(result);
    set_sign(&value_2, 0);
    sign = s21_is_less(value_1, value_2) ? 1 : 0;
    check = basic_sub(value_1, value_2, result, sign);
  } else if (get_sign(value_1) == 1 && get_sign(value_2) == 0) {
    // v2 - v1;
    s21_set_null(result);
    set_sign(&value_1, 0);
    check = s21_sub(value_2, value_1, result);
  } else if (get_sign(value_1) == 1 && get_sign(value_2) == 1) {
    // -(v1 + v2);
    s21_set_null(result);
    set_sign(&value_1, 0);
    set_sign(&value_2, 0);
    check = basic_add(value_1, value_2, result, 1);
  }
  return check;
}

int basic_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
              int sign) {
  int check = 0;
  big_decimal tmp_1, tmp_2;
  to_big(value_1, &tmp_1);
  to_big(value_2, &tmp_2);
  check = s21_normalize_big(&tmp_1, &tmp_2);
  big_decimal res = {{0}, 0};
  res.scale = tmp_1.scale;
  int add_bit = 0;

  unsigned long long first = 11;
  for (int i = 0; i < 192; i++) {
    int a = get_bit(tmp_1.bits[i / 32], i % 32);
    int b = get_bit(tmp_2.bits[i / 32], i % 32);
    set_bit(&(res.bits[i / 32]), i % 32, a ^ b ^ add_bit);
    add_bit = (a && b) || (b && add_bit) || (a && add_bit);
  }
  if (get_bit(res.bits[5], 31)) check = 1;
  if ((res.bits[5] || res.bits[4] || res.bits[3]) && res.scale == 0) {
    check = 1;
  } else if (res.bits[5] || res.bits[4] || res.bits[3]) {
    while ((res.bits[5] || res.bits[4] || res.bits[3]) && res.scale > 0) {
      check = drop_big_digit(&res, &first);
      res.scale -= 1;
    }
  }
  if ((res.bits[5] || res.bits[4] || res.bits[3])) check = 1;
  if (check) {
    check = sign ? 2 : 1;
    s21_set_null(result);
  } else {
    to_small(result, res);
    set_sign(result, sign);
  }
  return check;
}

int s21_normalize_big(big_decimal *x1, big_decimal *x2) {
  int check = 0;
  big_decimal *x_fix;
  int diff;
  if (x1->scale <= x2->scale) {
    x_fix = x1;
    diff = x2->scale - x1->scale;
  } else {
    x_fix = x2;
    diff = x1->scale - x2->scale;
  }
  while (diff--) {
    check = s21_mul10_big(x_fix);
    if (check) break;
    x_fix->scale += 1;
  }
  return check;
}

int s21_mul10_big(big_decimal *src) {
  big_decimal res = {{0}, 0};
  s21_decimal value_2 = {{10, 0, 0, 0}};
  int check = 0;
  big_decimal tmp_1 = *src;
  while (!is_null(value_2) && !check) {
    if (get_bit(value_2.bits[0], 0)) check = add_for_mul(res, tmp_1, &res);
    left_shift_big(&tmp_1);
    if (get_bit(res.bits[5], 31)) check = 1;
    right_shift(&value_2);
  }
  res.scale = src->scale;
  *src = res;
  return check;
}
