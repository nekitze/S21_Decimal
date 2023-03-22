#include "../test.h"

START_TEST(sub_1) {  // 0 0
  s21_decimal x = {{3, 0, 0, 0}};
  s21_decimal y = {{2, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{1, 0, 0, 0}};
  ck_assert_int_eq(s21_sub(x, y, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(sub_2) {  // 0 0
  s21_decimal x = {{3, 0, 0, 0}};
  s21_decimal y = {{2, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{1, 0, 0, 0x80000000}};
  ck_assert_int_eq(s21_sub(y, x, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(sub_3) {  // 1 0
  s21_decimal x = {{3, 0, 0, 0x80000000}};
  s21_decimal y = {{2, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{5, 0, 0, 0x80000000}};
  ck_assert_int_eq(s21_sub(x, y, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(sub_4) {  // 1 1
  s21_decimal x = {{3, 0, 0, 0x80000000}};
  s21_decimal y = {{2, 0, 0, 0x80000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{1, 0, 0, 0x80000000}};
  ck_assert_int_eq(s21_sub(x, y, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(sub_5) {  // 0 1
  s21_decimal x = {{3, 0, 0, 0}};
  s21_decimal y = {{2, 0, 0, 0x80000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{5, 0, 0, 0}};
  ck_assert_int_eq(s21_sub(x, y, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(sub_6) {  // 0 1
  s21_decimal x = {{2, 0, 0, 0}};
  s21_decimal y = {{0xfffffffe, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_sub(x, y, &z), 1);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(sub_7) {  // 1 0
  s21_decimal x = {{2, 0, 0, 0x80000000}};
  s21_decimal y = {{0xfffffffe, 0xffffffff, 0xffffffff, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_sub(x, y, &z), 2);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(sub_8) {  // 0 1 //
  s21_decimal x = {{0x00000037, 0x00000000, 0x00000000, 0x001C0000}};
  s21_decimal y = {{0x00000002, 0x00000000, 0x00000000, 0}};
  // set_pow(&x, 26);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0x1FFFFFC9, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  ck_assert_int_eq(s21_sub(x, y, &z), 0);
  for (int i = 3; i >= 0; i--) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(sub_9) {  // 0 0
  s21_decimal x = {{0, 1, 0, 0}};
  s21_decimal y = {{1, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0xffffffff, 0, 0, 0}};
  ck_assert_int_eq(s21_sub(x, y, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(sub_10) {  // 0 0
  s21_decimal x = {{0x00000037, 0x00000000, 0x00000000, 0x001C0000}};
  s21_decimal y = {{2, 0, 0, 0x80000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0x020000037, 0x7C4A04C2, 0x409F9CBC, 0x001C0000}};
  ck_assert_int_eq(s21_sub(x, y, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(sub_11) {  // 0 0
  s21_decimal x = {{0x00000037, 0x00000000, 0x00000000, 0x001C0000}};
  s21_decimal y = {{2, 0, 0, 0x80000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0x1FFFFFC9, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  ck_assert_int_eq(s21_add(x, y, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(sub_12) {  // 1 0
  s21_decimal x = {{0x000000A1, 0x00000000, 0x00000000, 0x80020000}};
  s21_decimal y = {{0x00000005, 0x00000000, 0x00000000, 0x00010000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0x000000D3, 0x00000000, 0x00000000, 0x80020000}};
  ck_assert_int_eq(s21_sub(x, y, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

Suite *init_suite_sub() {
  Suite *suite = suite_create("suite_sub");

  TCase *tcase_sub = tcase_create("sub");
  tcase_add_test(tcase_sub, sub_1);
  tcase_add_test(tcase_sub, sub_2);
  tcase_add_test(tcase_sub, sub_3);
  tcase_add_test(tcase_sub, sub_4);
  tcase_add_test(tcase_sub, sub_5);
  tcase_add_test(tcase_sub, sub_6);
  tcase_add_test(tcase_sub, sub_7);
  tcase_add_test(tcase_sub, sub_8);
  tcase_add_test(tcase_sub, sub_9);
  tcase_add_test(tcase_sub, sub_10);
  tcase_add_test(tcase_sub, sub_11);
  tcase_add_test(tcase_sub, sub_12);
  suite_add_tcase(suite, tcase_sub);

  return suite;
}