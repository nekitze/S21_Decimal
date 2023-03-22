#include "../test.h"
#include "check.h"

START_TEST(div_1) {
  s21_decimal x = {{0}};
  s21_decimal y = {{1, 0, 0, 0}};
  s21_decimal result = {{0}};
  s21_decimal correct = {{0}};
  s21_div(x, y, &result);
  ck_assert(s21_is_equal(result, correct));
}
END_TEST

START_TEST(div_2) {
  s21_decimal x = {{1, 0, 0, 0}};
  s21_decimal y = {{0}};
  s21_decimal result = {{0}};
  ck_assert(s21_div(x, y, &result) == 3);
}
END_TEST

START_TEST(div_3) {
  s21_decimal x = {{10}};
  s21_decimal y = {{5}};
  s21_decimal result = {{0}};
  s21_decimal correct = {{2, 0, 0, 0}};
  s21_div(x, y, &result);
  ck_assert(s21_is_equal(result, correct));
}
END_TEST

START_TEST(div_4) {
  s21_decimal x = {{5}};
  s21_decimal y = {{10}};
  s21_decimal result = {{0}};
  s21_decimal correct = {{5, 0, 0, 0}};
  set_pow(&correct, 1);
  s21_div(x, y, &result);
  ck_assert(s21_is_equal(result, correct));
}
END_TEST

START_TEST(div_5) {
  s21_decimal x = {{1}};
  s21_decimal y = {{3}};
  s21_decimal result = {{0}};
  s21_decimal correct = {{0x5555555, 0x14B700CB, 0xAC544CA, 0}};
  set_pow(&correct, 28);
  s21_div(x, y, &result);
  ck_assert(s21_is_equal(result, correct));
}
END_TEST

START_TEST(div_6) {
  s21_decimal x = {{2}};
  s21_decimal y = {{3}};
  s21_decimal result = {{0}};
  s21_decimal correct = {{0xAAAAAAB, 0x296E0196, 0x158A8994, 0}};
  set_pow(&correct, 28);
  s21_div(x, y, &result);
  ck_assert(s21_is_equal(result, correct));
}
END_TEST

START_TEST(div_7) {
  s21_decimal x = {{1}};
  set_pow(&x, 28);
  s21_decimal y = {{2}};
  s21_decimal result = {{0}};
  s21_decimal correct = {{0}};
  s21_div(x, y, &result);
  ck_assert(s21_is_equal(result, correct));
}
END_TEST

START_TEST(div_8) {
  s21_decimal x = {{11}};
  set_pow(&x, 28);
  s21_decimal y = {{2}};
  s21_decimal result = {{0}};
  s21_decimal correct = {{6}};
  set_pow(&correct, 28);
  s21_div(x, y, &result);
  ck_assert(s21_is_equal(result, correct));
}
END_TEST

START_TEST(div_9) {
  s21_decimal x = {{10}};
  s21_decimal y = {{1}};
  set_pow(&y, 28);
  s21_decimal result = {{0}};
  ck_assert(s21_div(x, y, &result) == 1);
}
END_TEST

START_TEST(div_10) {
  s21_decimal x = {{10}};
  set_sign(&x, 1);
  s21_decimal y = {{1}};
  set_pow(&y, 28);
  s21_decimal result = {{0}};
  ck_assert(s21_div(x, y, &result) == 2);
}
END_TEST

Suite *init_suite_div() {
  Suite *suite = suite_create("suite_div");

  TCase *tcase_div = tcase_create("division");
  tcase_add_test(tcase_div, div_1);
  tcase_add_test(tcase_div, div_2);
  tcase_add_test(tcase_div, div_3);
  tcase_add_test(tcase_div, div_4);
  tcase_add_test(tcase_div, div_5);
  tcase_add_test(tcase_div, div_6);
  tcase_add_test(tcase_div, div_7);
  tcase_add_test(tcase_div, div_8);
  tcase_add_test(tcase_div, div_9);
  tcase_add_test(tcase_div, div_10);
  suite_add_tcase(suite, tcase_div);

  return suite;
}