#include "../s21_decimal.h"

int float_sign(int *i, char my_float[20]);
int get_num(int *i, int *float_pow, char my_float[20]);
int get_true_pow(int *i, int *pow_sign, int *float_pow, char my_float[20]);
int true_converter(int num, int float_pow, int pow_sign, s21_decimal *dst,
                   float src);

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  char my_float[20] = {'\0'};
  sprintf(my_float, "%e", src);
  s21_set_null(dst);
  int status = 0;
  int sign = 0;       // знак числа
  int float_pow = 1;  // степень экспоненты
  int pow_sign = 0;   // знак экспоненты
  int num = 0;        // само число
  int i = 0;
  int true_pow = 0;
  if (isnan(src) || isinf(src)) {
    status = 1;
  } else {
    sign = float_sign(&i, my_float);
    num = get_num(&i, &float_pow, my_float);
    true_pow = get_true_pow(&i, &pow_sign, &float_pow, my_float);
    float_pow += true_pow;
    if (i) i = 0;
    if (true_pow < 29 && true_pow > -29) {
      status = true_converter(num, float_pow, pow_sign, dst, src);
    } else {
      status = 1;
    }
    set_sign(dst, sign);
    if (status) {
      status = 1;
      s21_set_null(dst);
    }
  }
  return status;
}

int float_sign(int *i, char my_float[20]) {
  int sign = 0;
  if (my_float[*i] == '-') {
    sign = 1;
    *i += 1;
  }
  return sign;
}

int get_num(int *i, int *float_pow, char my_float[20]) {
  int num = 0;
  for (; my_float[*i] != 'e'; *i += 1) {
    if (my_float[*i] == '.') continue;
    num *= 10;
    num += my_float[*i] - '0';
    *float_pow -= 1;
  }
  *i += 1;
  return num;
}

int get_true_pow(int *i, int *pow_sign, int *float_pow, char my_float[20]) {
  int tmp = 0;
  if (my_float[*i] == '-') {
    *pow_sign = 1;
    *i += 1;
  } else if (my_float[*i] == '+') {
    *i += 1;
  }
  for (; my_float[*i]; *i += 1) {
    tmp *= 10;
    tmp += my_float[*i] - '0';
  }
  if (*pow_sign) *float_pow *= -1;
  return tmp;
}

int true_converter(int num, int float_pow, int pow_sign, s21_decimal *dst,
                   float src) {
  int status = 0;
  while (num % 10 == 0 && float_pow != 0) {
    num /= 10;
    float_pow += pow_sign ? -1 : 1;
  }
  s21_set_null(dst);
  dst->bits[0] = num;
  if ((!pow_sign && float_pow > 0)) {
    while (float_pow) {
      s21_decimal dec = {{10, 0, 0, 0}};
      status = s21_mul(*dst, dec, dst);
      float_pow--;
      if (status) break;
    }
    set_pow(dst, abs(float_pow));
  } else {
    int last = 0;
    if (float_pow > 28) {
      char float_tmp[20] = {'\0'};
      sprintf(float_tmp, "%.7e", src);
      if (float_tmp[2] == '.') {
        last = float_tmp[3] - '0';
      } else {
        last = float_tmp[2] - '0';
      }
    }
    while (float_pow > 28) {
      s21_drop_last_digit(dst);
      float_pow--;
    }
    if (last > 4) dst->bits[0] += 1;
    set_pow(dst, abs(float_pow));
  }
  return status;
}
