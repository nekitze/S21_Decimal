#include "../arithmetics/s21_mul.h"
#include "../s21_decimal.h"

int s21_is_greater(s21_decimal a, s21_decimal b) {
  big_decimal a_big, b_big;

  to_big(a, &a_big);
  to_big(b, &b_big);

  s21_normalize_big(&a_big, &b_big);

  int res = 0;
  if (is_zero(a, b)) {
    res = 0;
  } else if (get_sign(a) < get_sign(b)) {
    res = 1;
  } else if (get_sign(a) > get_sign(b)) {
    res = 0;
  } else if (s21_is_equal(a, b)) {
    res = 0;
  } else {
    for (int i = 191; i >= 0; i--) {
      if (get_bit(a_big.bits[i / 32], i % 32) >
          get_bit(b_big.bits[i / 32], i % 32)) {
        res = 1;
        break;
      } else if (get_bit(a_big.bits[i / 32], i % 32) <
                 get_bit(b_big.bits[i / 32], i % 32)) {
        res = 0;
        break;
      }
    }
    if (get_sign(a) && get_sign(b)) res = res ? 0 : 1;
  }
  return res;
}