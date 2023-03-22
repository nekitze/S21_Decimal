#include "../s21_decimal.h"
#include "s21_mul.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int check = 0;
  int sign = 0;
  if (get_sign(value_1) == 0 && get_sign(value_2) == 0) {
    // v1 - v2
    s21_set_null(result);
    sign = s21_is_less(value_1, value_2) ? 1 : 0;
    if (!(s21_is_equal(value_1, value_2) || is_zero(value_1, value_2)))
      check = basic_sub(value_1, value_2, result, sign);
  } else if (get_sign(value_1) == 0 && get_sign(value_2) == 1) {
    // v1 - (-v2)
    s21_set_null(result);
    set_sign(&value_2, 0);
    check = basic_add(value_1, value_2, result, 0);
  } else if (get_sign(value_1) == 1 && get_sign(value_2) == 0) {
    // - (v1 + v2)
    s21_set_null(result);
    set_sign(&value_1, 0);
    check = basic_add(value_1, value_2, result, 1);
  } else if (get_sign(value_1) == 1 && get_sign(value_2) == 1) {
    // (-v1) + (v2)
    s21_set_null(result);
    sign = s21_is_less(value_1, value_2) ? 1 : 0;
    set_sign(&value_1, 0);
    set_sign(&value_2, 0);
    if (!(s21_is_equal(value_1, value_2) || is_zero(value_1, value_2)))
      check = basic_sub(value_1, value_2, result, sign);
  }
  return check;
}

int basic_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
              int sign) {
  int check = 0;
  big_decimal tmp_1, tmp_2;
  to_big(value_1, &tmp_1);
  to_big(value_2, &tmp_2);
  check = s21_normalize_big(&tmp_1, &tmp_2);
  if (s21_is_less(value_1, value_2)) {
    big_decimal tmp = tmp_1;
    tmp_1 = tmp_2;
    tmp_2 = tmp;
    // добавить знак
  }
  s21_set_null(result);
  big_decimal res = {{0}, 0};
  res.scale = tmp_1.scale;
  int sub_bit = 0;
  for (int i = 0; i < 192; i++) {
    int a = get_bit(tmp_1.bits[i / 32], i % 32);
    int b = get_bit(tmp_2.bits[i / 32], i % 32);
    if (a && sub_bit) {
      a = 0;
      sub_bit = 0;
    }
    if (!a && sub_bit) a = 1;
    if (a == 0 && b == 1) {
      sub_bit = 1;
      a = 1;
      b = 0;
    }
    set_bit(&(res.bits[i / 32]), i % 32, a - b);
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
