#include "../test.h"

START_TEST(mul10_simple) {
  s21_decimal x;
  x.bits[0] = 5;
  ck_assert_int_eq(s21_mul10(&x), 0);
  ck_assert_int_eq(x.bits[0], 50);
}
END_TEST

Suite *init_suite_normalize() {
  Suite *suite = suite_create("suite_common");

  TCase *tcase_mul_div_10 = tcase_create("mul_div_10");
  tcase_add_test(tcase_mul_div_10, mul10_simple);
  suite_add_tcase(suite, tcase_mul_div_10);
}