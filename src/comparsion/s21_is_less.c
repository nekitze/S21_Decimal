#include "../s21_decimal.h"

int s21_is_less(s21_decimal a, s21_decimal b) {
  int res = 0;
  if (!s21_is_greater(a, b) && s21_is_not_equal(a, b)) res = 1;
  return res;
}
