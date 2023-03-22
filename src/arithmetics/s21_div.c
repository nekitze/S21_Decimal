#include "../s21_decimal.h"

int eq_zero(s21_decimal num) {
  return !num.bits[0] && !num.bits[1] && !num.bits[2];
}

s21_decimal divide(s21_decimal *first, s21_decimal second) {
  int moves = 1;
  if (s21_is_less_or_equal(second, *first) &&
      (get_bit(second.bits[2], 31) == 0)) {
    while (s21_is_less_or_equal(second, *first) &&
           get_bit(second.bits[2], 31) == 0) {
      left_shift(&second);
      moves += 1;
    }
    if (get_bit(first->bits[2], 31) == 0) {
      right_shift(&second);
      moves -= 1;
    }
  }
  s21_decimal one = {{1, 0, 0, 0}};
  s21_decimal result = {0};
  for (int i = 0; i < moves; i++) {
    left_shift(&result);
    if (s21_is_greater_or_equal(*first, second)) {
      s21_sub(*first, second, first);
      s21_add(result, one, &result);
    }
    right_shift(&second);
  }
  return result;
}

int get_div_sign(s21_decimal *first, s21_decimal *second) {
  int sign = (get_sign(*first) != get_sign(*second));
  set_sign(first, 0);
  set_sign(second, 0);
  return sign;
}

int get_div_power(s21_decimal *first, s21_decimal *second) {
  int power = get_pow(*first) - get_pow(*second);
  set_pow(first, 0);
  set_pow(second, 0);
  return power;
}

void increase_last(s21_decimal *a) {
  int pow = get_pow(*a);
  set_pow(a, 0);
  int sign = get_sign(*a);
  set_sign(a, 0);
  s21_decimal one = {{1, 0, 0, 0}};
  s21_add(*a, one, a);
  set_pow(a, pow);
  set_sign(a, sign);
}

void round_last(s21_decimal *a, int digit) {
  int increase = 0;
  increase = (digit > 5);
  if (digit == 5) {
    increase = get_bit(a->bits[0], 0);
  }
  if (increase) {
    increase_last(a);
  }
}

int update_power(s21_decimal *result, int *power, int last_digit) {
  int error = 0;
  s21_decimal ten = {{10, 0, 0, 0}};
  if (*power > 28) {
    last_digit = 0;
    while (*power > 28) {
      last_digit = s21_drop_last_digit(result);
      *power -= 1;
    }
  }
  round_last(result, last_digit);
  if (*power < 0) {
    while (*power < 0 && !error) {
      s21_decimal temp = {0};
      error = s21_mul(*result, ten, &temp);
      if (!error) {
        *result = temp;
        *power += 1;
      }
    }
  }
  return error;
}

int inner_divide(s21_decimal first, s21_decimal second, s21_decimal *result,
                 int power) {
  int error = 0;
  *result = divide(&first, second);
  s21_decimal ten = {{10, 0, 0, 0}};
  s21_decimal digit = {0};
  int too_big = 0;
  int after_dot = 0;
  while (after_dot < 28 && !eq_zero(first) && !too_big) {
    s21_mul(first, ten, &first);
    s21_decimal new_result = {0};
    too_big = s21_mul(*result, ten, &new_result);
    if (!too_big) {
      digit = divide(&first, second);
      too_big |= s21_add(new_result, digit, &new_result);
    }
    if (!too_big) {
      *result = new_result;
      after_dot += 1;
    }
  }
  power += after_dot;
  s21_mul(first, ten, &first);
  digit = divide(&first, second);
  error = update_power(result, &power, digit.bits[0]);
  set_pow(result, power);
  return error;
}

int s21_div(s21_decimal first, s21_decimal second, s21_decimal *result) {
  int error = 0;
  if (!eq_zero(second)) {
    int sign = get_div_sign(&first, &second);
    int power = get_div_power(&first, &second);
    error = inner_divide(first, second, result, power);
    set_sign(result, sign);
    if (sign && (error == 1)) {
      error = 2;
    }
  } else {
    error = 3;
  }
  return error;
}
