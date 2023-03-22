#include "../test.h"

START_TEST(mod_1) {
  s21_decimal x = {{3, 0, 0, 0}};
  s21_decimal y = {{2, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{1, 0, 0, 0}};
  ck_assert_int_eq(s21_mod(x, y, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(mod_2) {
  s21_decimal x = {{3}};
  s21_decimal y = {{2}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{2, 0, 0, 0}};
  ck_assert_int_eq(s21_mod(y, x, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(mod_3) {
  s21_decimal x = {{2, 0, 0, 0}};
  s21_decimal y = {{3, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{2, 0, 0, 0}};
  ck_assert_int_eq(s21_mod(x, y, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(mod_4) {
  s21_decimal x = {{3, 0, 0, 0}};
  s21_decimal y = {{2, 0, 0, 0x80000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{1, 0, 0, 0}};
  ck_assert_int_eq(s21_mod(x, y, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(mod_5) {
  s21_decimal x = {{2, 0, 0, 0}};
  s21_decimal y = {{0xfffffffe, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{2, 0, 0, 0}};
  ck_assert_int_eq(s21_mod(x, y, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(mod_6) {
  s21_decimal x = {{0, 0, 0, 0}};
  s21_decimal y = {{0, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_mod(x, y, &z), 3);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(mod_7) {
  s21_decimal x = {{0, 1, 0, 0}};
  s21_decimal y = {{1, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 1, 0, 0}};
  ck_assert_int_eq(s21_mod(x, y, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(mod_8) {
  s21_decimal x = {{0, 0, 0, 0}};
  s21_decimal y = {{0, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_mod(x, y, &z), 3);
}
END_TEST

START_TEST(mod_9) {
  s21_decimal x = {{0, 0, 0, 0}};
  s21_decimal y = {{1, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_mod(x, y, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(mod_test_1) {
  int num1 = 3;
  int num2 = 2;
  int res_origin = num1 % num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mod(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(mod_test_2) {
  int num1 = -98765;
  int num2 = 1234;
  int res_origin = num1 % num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mod(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(mod_test_3) {
  int num1 = 30198;
  int num2 = 20210;
  int res_origin = num1 % num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mod(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(mod_test_4) {
  int num1 = -98765;
  int num2 = -1234;
  int res_origin = num1 % num2;
  // printf("%f", fmod(-98765, -1234));
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mod(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(mod_test_5) {
  int num1 = 98765;
  int num2 = 127234;
  int res_origin = num1 % num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mod(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(mod_test_6) {
  int num1 = 342576;
  int num2 = 1542134;
  int res_origin = num1 % num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mod(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(s21_mod_7) {
  s21_decimal dec1;
  s21_decimal dec2;
  int tmp1 = 99;
  int tmp2 = 2;
  int res_s21 = 0;
  int res = tmp1 % tmp2;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_decimal res1;
  s21_mod(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_mod_8) {
  s21_decimal dec1;
  s21_decimal dec2;
  int tmp1 = 100;
  int tmp2 = 2;
  int res_s21 = 0;
  float res = tmp1 % tmp2;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_decimal res1;
  s21_mod(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_mod_9) {
  s21_decimal dec1;
  s21_decimal dec2;
  int tmp1 = -100;
  int tmp2 = 2;
  float res_s21 = 0;
  float res = tmp1 % tmp2;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_decimal res1;
  s21_mod(dec1, dec2, &res1);
  s21_from_decimal_to_float(res1, &res_s21);
  ck_assert_float_eq(res_s21, res);
}
END_TEST

START_TEST(s21_mod_10) {
  s21_decimal dec1;
  s21_decimal dec2;
  int tmp1 = 99;
  int tmp2 = -2;
  int res_s21 = 0;
  float res = tmp1 % tmp2;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_decimal res1;
  s21_mod(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_mod_11) {
  s21_decimal dec1;
  s21_decimal dec2;
  float tmp1 = 1.2;
  float tmp2 = 0.2;
  float res_s21 = 0.0;
  float res = fmod(tmp1, tmp2);
  s21_from_float_to_decimal(tmp1, &dec1);
  s21_from_float_to_decimal(tmp2, &dec2);
  s21_decimal res1;
  s21_mod(dec1, dec2, &res1);
  s21_from_decimal_to_float(res1, &res_s21);
  ck_assert_float_eq_tol(res_s21, res, 6);
}
END_TEST

START_TEST(s21_mod_12) {
  s21_decimal dec1;
  s21_decimal dec2;
  float tmp1 = 1.2;
  float tmp2 = 0.25;
  float res_s21 = 0.0;
  float res = fmod(tmp1, tmp2);
  s21_from_float_to_decimal(tmp1, &dec1);
  s21_from_float_to_decimal(tmp2, &dec2);
  s21_decimal res1;
  s21_mod(dec1, dec2, &res1);
  s21_from_decimal_to_float(res1, &res_s21);
  ck_assert_float_eq_tol(res_s21, res, 6);
}
END_TEST

START_TEST(s21_mod_13) {
  s21_decimal dec1;
  s21_decimal dec2;
  int tmp1 = -99;
  int tmp2 = -2;
  int res_s21 = 0;
  int res = tmp1 % tmp2;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_decimal res1;
  s21_mod(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_mod_div_null_14) {
  s21_decimal dec1;
  s21_decimal dec2 = {{0, 0, 0, 0}};
  float tmp1 = 1.2;
  float tmp2 = 0.0;
  s21_from_float_to_decimal(tmp1, &dec1);
  s21_from_float_to_decimal(tmp2, &dec2);
  s21_decimal res_d;
  int res = s21_mod(dec1, dec2, &res_d);

  ck_assert_int_eq(res, 3);
}
END_TEST

Suite *init_suite_mod() {
  Suite *suite = suite_create("suite_mod");

  TCase *tcase_mod = tcase_create("mod");
  tcase_add_test(tcase_mod, mod_1);
  tcase_add_test(tcase_mod, mod_2);
  tcase_add_test(tcase_mod, mod_3);
  tcase_add_test(tcase_mod, mod_4);
  tcase_add_test(tcase_mod, mod_5);
  tcase_add_test(tcase_mod, mod_6);
  tcase_add_test(tcase_mod, mod_7);
  tcase_add_test(tcase_mod, mod_8);
  tcase_add_test(tcase_mod, mod_9);

  tcase_add_test(tcase_mod, mod_test_1);
  tcase_add_test(tcase_mod, mod_test_2);
  tcase_add_test(tcase_mod, mod_test_3);
  tcase_add_test(tcase_mod, mod_test_4);
  tcase_add_test(tcase_mod, mod_test_5);
  tcase_add_test(tcase_mod, mod_test_6);
  tcase_add_test(tcase_mod, s21_mod_7);
  tcase_add_test(tcase_mod, s21_mod_8);
  tcase_add_test(tcase_mod, s21_mod_9);
  tcase_add_test(tcase_mod, s21_mod_10);
  tcase_add_test(tcase_mod, s21_mod_11);
  tcase_add_test(tcase_mod, s21_mod_12);
  tcase_add_test(tcase_mod, s21_mod_13);
  tcase_add_test(tcase_mod, s21_mod_div_null_14);
  suite_add_tcase(suite, tcase_mod);

  return suite;
}