#include "s21_mul.h"

#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int check = 0;
  big_decimal tmp_1;
  to_big(value_1, &tmp_1);
  big_decimal res = {{0}, 0};
  int sign = (get_sign(value_1)) ^ (get_sign(value_2));
  while (!is_null(value_2) && !check) {
    if (get_bit(value_2.bits[0], 0)) check = add_for_mul(res, tmp_1, &res);
    left_shift_big(&tmp_1);
    if (get_bit(res.bits[5], 31)) check = 1;
    right_shift(&value_2);
  }
  res.scale = get_pow(value_1) + get_pow(value_2);

  // пляска с бубном
  unsigned long long first = 11;  // потому что оно всегда однозначное

  while ((res.bits[5] || res.bits[4] || res.bits[3]) || res.scale > 28) {
    if ((res.bits[5] || res.bits[4] || res.bits[3]) && res.scale == 0) {
      check = 1;
      break;
    }
    check = drop_big_digit(&res, &first);
    res.scale -= 1;
  }
  if (check) {  // отладочная
    check = sign ? 2 : 1;
    s21_set_null(result);
  } else {
    to_small(result, res);
    set_sign(result, sign);
  }
  return check;
}

void to_small(s21_decimal *result, big_decimal res) {
  for (int i = 0; i < 3; i++) {
    result->bits[i] = res.bits[i];
  }
  set_pow(result, res.scale);
}

int drop_big_digit(big_decimal *src, unsigned long long *first) {
  int check = 0;
  int big = 0;
  int small = 0;
  if (src->bits[5] || src->bits[4] || src->bits[3]) big = 1;
  unsigned long long last, div;

  last = s21_as_uint(src->bits[5]);
  div = last % 10;
  src->bits[5] = s21_as_int((unsigned int)(last / 10));
  for (int i = 0; i < 6; i++) {
  }
  for (int i = 4; i >= 0; i--) {
    last = s21_as_uint(src->bits[i]) + div * S21_2IN32;
    div = last % 10;
    src->bits[i] = s21_as_int((unsigned int)(last / 10));
  }
  if (!src->bits[5] && !src->bits[4] && !src->bits[3]) small = 1;
  if (!last_one(*src, small, big) && *first == 11) {
    *first = div;
  } else if (last_one(*src, small, big)) {
    check = bank_rounding(src, div, *first);
  }
  return check;
}

int last_one(big_decimal src, int small, int big) {
  int check = 0;
  if (big && small && src.scale < 29) {
    check = 1;
  } else if (src.scale - 1 == 28 && !big) {
    check = 1;
  }
  return check;
}

int bank_rounding(big_decimal *src, unsigned long long div,
                  unsigned long long first) {
  int check = 0;
  if (div > 5) {
    check = add_one(src);
  } else if (div == 5 && (first == 0 || first == 11)) {
    if (src->bits[0] % 2) check = add_one(src);
  } else if (div == 5) {
    check = add_one(src);
  }
  return check;
}

int add_one(big_decimal *src) {
  int check = 0;
  if (src->bits[0] == -1) {
    src->bits[0] += 1;
    if (src->bits[1] == -1) {
      src->bits[1] += 1;
      if (src->bits[2] == -1) {
        check = 1;
      } else {
        src->bits[2] += 1;
      }
    } else {
      src->bits[1] += 1;
    }
  } else {
    src->bits[0] += 1;
  }
  return check;
}
int add_for_mul(big_decimal res_value, big_decimal value_1, big_decimal *res) {
  int check = 0;
  int add_bit = 0;
  for (int i = 0; i < 192; i++) {
    int a = get_bit(value_1.bits[i / 32], i % 32);
    int b = get_bit(res_value.bits[i / 32], i % 32);
    set_bit(&(res->bits[i / 32]), i % 32, a ^ b ^ add_bit);
    add_bit = (a && b) || (b && add_bit) || (a && add_bit);
  }
  if (add_bit) check = 1;
  return check;
}

void to_big(s21_decimal from, big_decimal *to) {
  for (int i = 0; i < 3; i++) {
    to->bits[i] = from.bits[i];
  }
  to->bits[3] = 0;
  to->bits[4] = 0;
  to->bits[5] = 0;
  to->scale = get_pow(from);
}

int is_null(s21_decimal src) {
  int res = 1;
  for (int i = 0; i < 3; i++) {
    if (src.bits[i] != 0) {
      res = 0;
      break;
    }
  }
  return res;
}
