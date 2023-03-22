#include "../s21_decimal.h"

int s21_is_less_or_equal(s21_decimal a, s21_decimal b) {
  int res = 0;
  if (!s21_is_greater(a, b)) res = 1;
  return res;
}
