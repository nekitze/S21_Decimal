#include "../test.h"

START_TEST(mul_1) {
  s21_decimal x = {{3, 0, 0, 0}};
  s21_decimal y = {{2, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{6, 0, 0, 0}};
  ck_assert_int_eq(s21_mul(x, y, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(mul_2) {
  s21_decimal x = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};
  s21_decimal y = {{0x0000000B, 0x00000000, 0x00000000, 0x00010000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0xC28F5C29, 0x8F5C28F5, 0x1C28F5C2, 0x001B0000}};
  ck_assert_int_eq(s21_mul(x, y, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(mul_3) {
  s21_decimal x = {{0x2110991E, 0x1ED3CC02, 0x00000023, 0x000E0000}};
  s21_decimal y = {{0xC09256A0, 0x00000C41, 0x00000000, 0x00100000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0xBA2121FE, 0x3DE0F035, 0x1C360358, 0x00180000}};
  ck_assert_int_eq(s21_mul(x, y, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(mul_4) {
  s21_decimal x = {{0x2110991F, 0x1ED3CC02, 0x00000023, 0x000E0000}};
  s21_decimal y = {{0xC092569D, 0x00000C41, 0x00000000, 0x00100000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0x92DF46D1, 0x3DDA088A, 0x1C360358, 0x00180000}};
  ck_assert_int_eq(s21_mul(x, y, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

Suite *init_suite_mul() {
  Suite *suite = suite_create("suite_mul");

  TCase *tcase_mul = tcase_create("mul");
  tcase_add_test(tcase_mul, mul_1);
  tcase_add_test(tcase_mul, mul_2);
  tcase_add_test(tcase_mul, mul_3);
  tcase_add_test(tcase_mul, mul_4);

  suite_add_tcase(suite, tcase_mul);

  return suite;
}