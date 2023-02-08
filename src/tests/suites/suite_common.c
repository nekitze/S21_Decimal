#include "../test.h"

START_TEST(set_pow_1) {
  s21_decimal x;
  set_pow(&x, 5);
  ck_assert_int_eq(get_pow(x), 5);
}
END_TEST

START_TEST(set_sign_1) {
  s21_decimal x;
  set_sign(&x, 1);
  ck_assert_int_eq(get_sign(x), 1);
}
END_TEST

Suite *init_suite_common() {
  Suite *suite = suite_create("suite_common");

  TCase *tcase_bit_manipulation = tcase_create("bit_manipulation");
  tcase_add_test(tcase_bit_manipulation, set_pow_1);
  tcase_add_test(tcase_bit_manipulation, set_sign_1);
  suite_add_tcase(suite, tcase_bit_manipulation);

  return suite;
}
