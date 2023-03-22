#include "../s21_decimal.h"

int is_zero(s21_decimal a, s21_decimal b) {
  int res = 0;

  if (a.bits[0] == 0 && a.bits[1] == 0 && a.bits[2] == 0 && b.bits[0] == 0 &&
      b.bits[1] == 0 && b.bits[2] == 0)
    res = 1;

  return res;
}
