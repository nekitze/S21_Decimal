#include "s21_decimal.h"
#include <stdio.h>

int main() {
  s21_decimal x;
  s21_set_null(&x);
  x.bits[0] = (int)S21_2IN32-1;
  x.bits[1] = (int)S21_2IN32-1;
  x.bits[2] = (int)S21_2IN32-1;
  // set_pow(&x, 2);

  s21_decimal y;
  s21_set_null(&y);
  y.bits[0] = (int)S21_2IN32-1;
  y.bits[1] = (int)S21_2IN32-1;
  y.bits[2] = (int)S21_2IN32-1;
  // set_pow(&y, 6);

  s21_decimal res;

  int rc = s21_add(x, y, &res);
  s21_decimal_print(x, 0);
  s21_decimal_print(y, 0);
  s21_decimal_print(res, 0);
  printf("rc = %d", rc);

}