#include "../test.h"

START_TEST(add_1) {
  s21_decimal x = {{3, 0, 0, 0}};
  s21_decimal y = {{2, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{5, 0, 0, 0}};
  ck_assert_int_eq(s21_add(x, y, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(add_2) {
  s21_decimal x = {{1, 0, 0, 0}};
  s21_decimal y = {{0, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{1, 0, 0, 0}};
  ck_assert_int_eq(s21_add(x, y, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(add_3) {
  s21_decimal x = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};
  s21_decimal y = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0x33333333, 0x33333333, 0x33333333, 0x001B0000}};
  ck_assert_int_eq(s21_add(x, y, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(add_4) {
  s21_decimal x = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal y = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_add(x, y, &z), 1);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(add_5) {
  s21_decimal x = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal y = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_add(x, y, &z), 2);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(add_6) {
  s21_decimal x = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal y = {{1, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_add(x, y, &z), 1);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(add_7) {
  s21_decimal x = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};
  s21_decimal y = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_add(x, y, &z), 1);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(add_8) {
  s21_decimal x = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal y = {{1, 0, 0, 0}};
  set_pow(&y, 1);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  ck_assert_int_eq(s21_add(x, y, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(add_9) {
  s21_decimal x = {{1, 0, 0, 0x00000000}};
  s21_decimal y = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  // set_pow(&y, 1);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  ck_assert_int_eq(s21_add(x, y, &z), 0);
  for (int i = 3; i >= 0; i--) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(add_10) {
  s21_decimal x = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal y = {{2, 0, 0, 0}};
  set_pow(&y, 1);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  ck_assert_int_eq(s21_add(x, y, &z), 0);
  for (int i = 3; i >= 0; i--) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(add_11) {
  s21_decimal x = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal y = {{9, 0, 0, 0}};
  set_pow(&y, 1);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_add(x, y, &z), 1);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(add_12) {
  s21_decimal x = {{1, 0, 0, 0x00000000}};
  s21_decimal y = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x00010000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0x9999999A, 0x99999999, 0x19999999, 00000000}};
  ck_assert_int_eq(s21_add(x, y, &z), 0);
  for (int i = 3; i >= 0; i--) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(add_13) {
  s21_decimal x = {{0xFFFFFFFF, 0, 0, 0}};
  s21_decimal y = {{1, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 1, 0, 0}};
  ck_assert_int_eq(s21_add(x, y, &z), 0);
  for (int i = 3; i >= 0; i--) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(add_14) {
  s21_decimal x = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal y = {{1, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  ck_assert_int_eq(s21_add(x, y, &z), 0);
  for (int i = 3; i >= 0; i--) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(add_15) {
  s21_decimal x = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal y = {{13, 0, 0, 0}};
  set_pow(&y, 1);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  ck_assert_int_eq(s21_add(x, y, &z), 0);
  for (int i = 3; i >= 0; i--) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(add_16) {
  s21_decimal x = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal y = {{19, 0, 0, 0}};
  set_pow(&y, 1);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_add(x, y, &z), 1);
  for (int i = 3; i >= 0; i--) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(add_17) {
  s21_decimal x = {{8, 0, 0, 0x001C0000}};
  s21_decimal y = {{2, 0, 0, 0x001C0000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{10, 0, 0, 0x001C0000}};
  ck_assert_int_eq(s21_add(x, y, &z), 0);
  for (int i = 3; i >= 0; i--) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(add_18) {
  s21_decimal x = {{0xFFFFFFFF, 0, 0, 0x00160000}};
  s21_decimal y = {{0x00000037, 0, 0, 0x00170000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0x0000002D, 0x0000000A, 0, 0x00170000}};
  ck_assert_int_eq(s21_add(x, y, &z), 0);
  for (int i = 3; i >= 0; i--) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(add_19) {
  s21_decimal x = {{0xFFFFFFFF, 0x00000000, 0x00000000, 0x00160000}};
  s21_decimal y = {{0x00000038, 0x00000000, 0x00000000, 0x00170000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0x0000002E, 0x0000000A, 0x00000000, 0x00170000}};
  ck_assert_int_eq(s21_add(x, y, &z), 0);
  for (int i = 3; i >= 0; i--) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(add_20) {
  s21_decimal x = {{0xFFFFFFFF, 0x00000000, 0x00000000, 0x00170000}};
  s21_decimal y = {{0x00000036, 0x00000000, 0x00000000, 0x00170000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0x00000035, 0x00000001, 0x00000000, 0x00170000}};
  ck_assert_int_eq(s21_add(x, y, &z), 0);
  for (int i = 3; i >= 0; i--) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(add_21) {
  s21_decimal x = {{0x00000005, 0x00000000, 0x00000000, 0x001C0000}};
  s21_decimal y = {{0x00000005, 0x00000000, 0x00000000, 0x001C0000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0x0000000A, 0x00000000, 0x00000000, 0x001C0000}};
  ck_assert_int_eq(s21_add(x, y, &z), 0);
  for (int i = 3; i >= 0; i--) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(add_22) {  // 0 0
  s21_decimal x = {{3, 0, 0, 0}};
  s21_decimal y = {{2, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{5, 0, 0, 0}};
  ck_assert_int_eq(s21_add(x, y, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(add_23) {  // 1 0
  s21_decimal x = {{3, 0, 0, 0x80000000}};
  s21_decimal y = {{2, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{1, 0, 0, 0x80000000}};
  ck_assert_int_eq(s21_add(x, y, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(add_24) {  // 1 1
  s21_decimal x = {{3, 0, 0, 0x80000000}};
  s21_decimal y = {{2, 0, 0, 0x80000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{5, 0, 0, 0x80000000}};
  ck_assert_int_eq(s21_add(x, y, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(add_25) {  // 0 1
  s21_decimal x = {{3, 0, 0, 0}};
  s21_decimal y = {{2, 0, 0, 0x80000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{1, 0, 0, 0}};
  ck_assert_int_eq(s21_add(x, y, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(add_26) {  // 0 0
  s21_decimal x = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};
  s21_decimal y = {{0x000003E9, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0xF7B22D0E, 0x9FFFAB98, 0x20999D2A, 0x00190000}};
  ck_assert_int_eq(s21_add(x, y, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(add_27) {
  s21_decimal x = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal y = {{5, 0, 0, 0}};
  set_pow(&y, 1);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_add(x, y, &z), 1);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], res.bits[i]);
  }
}
END_TEST

Suite *init_suite_add() {
  Suite *suite = suite_create("suite_add");

  TCase *tcase_add = tcase_create("add");
  tcase_add_test(tcase_add, add_1);
  tcase_add_test(tcase_add, add_2);
  tcase_add_test(tcase_add, add_3);
  tcase_add_test(tcase_add, add_4);
  tcase_add_test(tcase_add, add_5);
  tcase_add_test(tcase_add, add_6);
  tcase_add_test(tcase_add, add_7);
  tcase_add_test(tcase_add, add_8);
  tcase_add_test(tcase_add, add_9);
  tcase_add_test(tcase_add, add_10);
  tcase_add_test(tcase_add, add_11);
  tcase_add_test(tcase_add, add_12);
  tcase_add_test(tcase_add, add_13);
  tcase_add_test(tcase_add, add_14);
  tcase_add_test(tcase_add, add_15);
  tcase_add_test(tcase_add, add_16);
  tcase_add_test(tcase_add, add_17);
  tcase_add_test(tcase_add, add_18);
  tcase_add_test(tcase_add, add_19);
  tcase_add_test(tcase_add, add_20);
  tcase_add_test(tcase_add, add_21);
  tcase_add_test(tcase_add, add_22);
  tcase_add_test(tcase_add, add_23);
  tcase_add_test(tcase_add, add_24);
  tcase_add_test(tcase_add, add_25);
  tcase_add_test(tcase_add, add_26);
  tcase_add_test(tcase_add, add_27);
  suite_add_tcase(suite, tcase_add);

  return suite;
}
