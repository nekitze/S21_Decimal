#include "../test.h"

typedef enum {
  CONVERTATION_OK = 0,
  CONVERTATION_ERROR = 1
} convertation_result;

START_TEST(is_equal_simple) {
  s21_decimal decimal;
  s21_decimal second_decimal;
  init_decimal(&decimal);
  init_decimal(&second_decimal);
  int A = 5123;
  convertation_result status = s21_from_int_to_decimal(A, &decimal);
  convertation_result second_status =
      s21_from_int_to_decimal(A, &second_decimal);
  ck_assert_int_eq(1, s21_is_equal(decimal, second_decimal));
  ck_assert_int_eq(status, second_status);
}
END_TEST

START_TEST(is_equal_0_decimal) {
  s21_decimal decimal;
  s21_decimal second_decimal;
  init_decimal(&decimal);
  init_decimal(&second_decimal);
  int A = 5123;
  s21_from_int_to_decimal(A, &decimal);
  ck_assert_int_eq(0, s21_is_equal(decimal, second_decimal));
}
END_TEST

START_TEST(is_not_equal) {
  s21_decimal decimal;
  s21_decimal second_decimal;
  init_decimal(&decimal);
  init_decimal(&second_decimal);
  int A = 5123;
  int B = 5122;
  convertation_result status = s21_from_int_to_decimal(A, &decimal);
  convertation_result second_status =
      s21_from_int_to_decimal(B, &second_decimal);
  ck_assert_int_eq(status, second_status);
  ck_assert_int_eq(1, s21_is_not_equal(decimal, second_decimal));
}
END_TEST

START_TEST(is_not_equal_EQ) {
  s21_decimal decimal;
  s21_decimal second_decimal;
  init_decimal(&decimal);
  init_decimal(&second_decimal);
  int A = -5123;
  convertation_result status = s21_from_int_to_decimal(A, &decimal);
  s21_from_int_to_decimal(A, &second_decimal);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(0, s21_is_not_equal(decimal, second_decimal));
}
END_TEST

START_TEST(is_not_equal_SIGN) {
  s21_decimal decimal;
  s21_decimal second_decimal;
  init_decimal(&decimal);
  init_decimal(&second_decimal);
  int A = -5123;
  int B = 5123;
  convertation_result status = s21_from_int_to_decimal(A, &decimal);
  convertation_result second_status =
      s21_from_int_to_decimal(B, &second_decimal);
  ck_assert_int_eq(status, second_status);
  ck_assert_int_eq(1, s21_is_not_equal(decimal, second_decimal));
}
END_TEST

START_TEST(is_greater_le) {
  s21_decimal decimal;
  s21_decimal second_decimal;
  init_decimal(&decimal);
  init_decimal(&second_decimal);
  int A = 5123;
  int B = -5123;
  convertation_result status = s21_from_int_to_decimal(A, &decimal);
  convertation_result second_status =
      s21_from_int_to_decimal(B, &second_decimal);
  ck_assert_int_eq(status, second_status);
  ck_assert_int_eq(0, s21_is_greater(second_decimal, decimal));
}
END_TEST

START_TEST(is_greater_stand) {
  s21_decimal decimal;
  s21_decimal second_decimal;
  init_decimal(&decimal);
  init_decimal(&second_decimal);
  int A = -5123;
  int B = 5123;
  convertation_result status = s21_from_int_to_decimal(A, &decimal);
  convertation_result second_status =
      s21_from_int_to_decimal(B, &second_decimal);
  ck_assert_int_eq(status, second_status);
  ck_assert_int_eq(1, s21_is_greater(second_decimal, decimal));
}
END_TEST

START_TEST(is_greater_eq) {
  s21_decimal decimal;
  s21_decimal second_decimal;
  init_decimal(&decimal);
  init_decimal(&second_decimal);
  int B = 5123;
  int A = B;
  convertation_result status = s21_from_int_to_decimal(A, &decimal);
  convertation_result second_status =
      s21_from_int_to_decimal(B, &second_decimal);
  ck_assert_int_eq(status, second_status);
  ck_assert_int_eq(1, s21_is_greater_or_equal(decimal, second_decimal));
}
END_TEST

START_TEST(is_greater_0) {
  s21_decimal decimal;
  s21_decimal second_decimal;
  init_decimal(&decimal);
  init_decimal(&second_decimal);
  int A = 0;
  int B = 5123;
  convertation_result status = s21_from_int_to_decimal(A, &decimal);
  convertation_result second_status =
      s21_from_int_to_decimal(B, &second_decimal);
  ck_assert_int_eq(status, second_status);
  ck_assert_int_eq(0, s21_is_greater(decimal, second_decimal));
}
END_TEST

START_TEST(is_less_ne) {
  s21_decimal decimal;
  s21_decimal second_decimal;
  init_decimal(&decimal);
  init_decimal(&second_decimal);
  int A = -5124;
  int B = -5123;
  convertation_result status = s21_from_int_to_decimal(A, &decimal);
  convertation_result second_status =
      s21_from_int_to_decimal(B, &second_decimal);
  ck_assert_int_eq(status, second_status);
  ck_assert_int_eq(1, s21_is_less(decimal, second_decimal));
}
END_TEST

START_TEST(is_less_equal) {
  s21_decimal decimal;
  s21_decimal second_decimal;
  init_decimal(&decimal);
  init_decimal(&second_decimal);
  int B = 5123;
  int A = B;
  convertation_result status = s21_from_int_to_decimal(A, &decimal);
  convertation_result second_status =
      s21_from_int_to_decimal(B, &second_decimal);
  ck_assert_int_eq(status, second_status);
  ck_assert_int_eq(0, s21_is_less(decimal, second_decimal));
}
END_TEST

START_TEST(is_less_Classic) {
  s21_decimal decimal;
  s21_decimal second_decimal;
  init_decimal(&decimal);
  init_decimal(&second_decimal);
  int A = 0;
  int B = 5123;
  convertation_result status = s21_from_int_to_decimal(A, &decimal);
  convertation_result second_status =
      s21_from_int_to_decimal(B, &second_decimal);
  ck_assert_int_eq(status, second_status);
  ck_assert_int_eq(1, s21_is_less(decimal, second_decimal));
}
END_TEST

START_TEST(is_less_or_equal_Classic) {
  s21_decimal decimal;
  s21_decimal second_decimal;
  init_decimal(&decimal);
  init_decimal(&second_decimal);
  int B = 5123;
  int A = B;
  convertation_result status = s21_from_int_to_decimal(A, &decimal);
  convertation_result second_status =
      s21_from_int_to_decimal(B, &second_decimal);
  ck_assert_int_eq(status, second_status);
  ck_assert_int_eq(1, s21_is_less_or_equal(decimal, second_decimal));
}
END_TEST

START_TEST(is_less_or_equal_Norm) {
  s21_decimal decimal;
  s21_decimal second_decimal;
  init_decimal(&decimal);
  init_decimal(&second_decimal);
  int B = 5123;
  int A = 51240;
  convertation_result status = s21_from_int_to_decimal(A, &decimal);
  convertation_result second_status =
      s21_from_int_to_decimal(B, &second_decimal);
  ck_assert_int_eq(status, second_status);
  ck_assert_int_eq(0, s21_is_less_or_equal(decimal, second_decimal));
}
END_TEST

START_TEST(decimal_is_less_1) {
  s21_decimal x = {{4294967295, 0, 0, 0}};
  s21_decimal y = {{0, 1, 0, 0}};
  int res1 = s21_is_less(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_2) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  int res1 = s21_is_less(y, x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_3) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  int res1 = s21_is_less(y, x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_4) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  set_sign(&x, 1);
  set_sign(&y, 1);
  int res1 = s21_is_less(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_5) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  set_sign(&x, 1);
  set_sign(&y, 1);
  int res1 = s21_is_less(y, x);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_6) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  set_sign(&x, 1);
  set_sign(&y, 1);
  int res1 = s21_is_less(y, x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_7) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  set_sign(&x, 1);

  int res1 = s21_is_less(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_8) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};

  set_sign(&y, 1);
  int res1 = s21_is_less(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

/* ----------------------------------------------------------------
 * 21_is_less_or_equal    <=
 * ---------------------------------------------------------------- */

START_TEST(decimal_is_less_or_equal_1) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  int res1 = s21_is_less_or_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_or_equal_2) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  int res1 = s21_is_less_or_equal(y, x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_or_equal_or_equal_3) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  int res1 = s21_is_less_or_equal(y, x);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_or_equal_4) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  set_sign(&x, 1);
  set_sign(&y, 1);

  int res1 = s21_is_less_or_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_or_equal_5) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  set_sign(&x, 1);
  set_sign(&y, 1);

  int res1 = s21_is_less_or_equal(y, x);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_or_equal_6) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  set_sign(&x, 1);
  set_sign(&y, 1);

  int res1 = s21_is_less_or_equal(y, x);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_or_equal_7) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  set_sign(&x, 1);

  int res1 = s21_is_less_or_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_or_equal_8) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};

  set_sign(&y, 1);
  int res1 = s21_is_less_or_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

// /* ----------------------------------------------------------------
//  * s21_is_greater   >
//  * ---------------------------------------------------------------- */

START_TEST(decimal_is_greater_1) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  int res1 = s21_is_greater(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_2) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  int res1 = s21_is_greater(y, x);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_3) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  int res1 = s21_is_greater(y, x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_4) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  set_sign(&x, 1);
  set_sign(&y, 1);

  int res1 = s21_is_greater(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_5) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  set_sign(&x, 1);
  set_sign(&y, 1);
  int res1 = s21_is_greater(y, x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_6) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  set_sign(&x, 1);
  set_sign(&y, 1);

  int res1 = s21_is_greater(y, x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_7) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  set_sign(&x, 1);

  int res1 = s21_is_greater(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_8) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};

  set_sign(&y, 1);
  int res1 = s21_is_greater(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

// /* ----------------------------------------------------------------
//  * 21_is_greater_or_equal   >=
//  * ---------------------------------------------------------------- */

START_TEST(decimal_is_greater_or_equal_1) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  int res1 = s21_is_greater_or_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_or_equal_2) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  int res1 = s21_is_greater_or_equal(y, x);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_or_equal_or_equal_3) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  int res1 = s21_is_greater_or_equal(y, x);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_or_equal_4) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  set_sign(&x, 1);
  set_sign(&y, 1);

  int res1 = s21_is_greater_or_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_or_equal_5) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  set_sign(&x, 1);
  set_sign(&y, 1);
  int res1 = s21_is_greater_or_equal(y, x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_or_equal_6) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  set_sign(&x, 1);
  set_sign(&y, 1);

  int res1 = s21_is_greater_or_equal(y, x);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_or_equal_7) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  set_sign(&x, 1);

  int res1 = s21_is_greater_or_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_or_equal_8) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};

  set_sign(&y, 1);
  int res1 = s21_is_greater_or_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

// /* ----------------------------------------------------------------
//  * s21_is_equal      ==
//  * ---------------------------------------------------------------- */

START_TEST(decimal_is_equal_1) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  int res1 = s21_is_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_equal_2) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  set_sign(&x, 1);
  set_sign(&y, 1);
  int res1 = s21_is_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_equal_3) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};

  set_sign(&y, 1);
  int res1 = s21_is_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_equal_4) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  set_sign(&x, 1);

  int res1 = s21_is_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_equal_5) {
  s21_decimal x = {{0, 52, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  int res1 = s21_is_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_equal_6) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{1747, 0, 1, 0}};
  int res1 = s21_is_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_equal_7) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{1747, 0, 1, 0}};
  set_sign(&x, 1);

  int res1 = s21_is_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

// /* ----------------------------------------------------------------
//  * s21_is_not_equal     !=
//  * ---------------------------------------------------------------- */

START_TEST(decimal_is_not_equal_1) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  int res1 = s21_is_not_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_not_equal_2) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  set_sign(&x, 1);
  set_sign(&y, 1);

  int res1 = s21_is_not_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_not_equal_3) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};

  set_sign(&y, 1);
  int res1 = s21_is_not_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_not_equal_4) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  set_sign(&x, 1);

  int res1 = s21_is_not_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_not_equal_5) {
  s21_decimal x = {{0, 52, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  int res1 = s21_is_not_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_not_equal_6) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{1747, 0, 1, 0}};
  int res1 = s21_is_not_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_not_equal_7) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{1747, 0, 1, 0}};
  set_sign(&x, 1);

  int res1 = s21_is_not_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite* comparsion_suite() {
  Suite* s;
  TCase* tc_core;

  s = suite_create("equal");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, is_equal_simple);
  tcase_add_test(tc_core, is_equal_0_decimal);
  tcase_add_test(tc_core, is_not_equal);
  tcase_add_test(tc_core, is_not_equal_SIGN);
  tcase_add_test(tc_core, is_not_equal_EQ);
  tcase_add_test(tc_core, is_greater_stand);
  tcase_add_test(tc_core, is_greater_le);
  tcase_add_test(tc_core, is_greater_0);
  tcase_add_test(tc_core, is_greater_eq);
  tcase_add_test(tc_core, is_less_Classic);
  tcase_add_test(tc_core, is_less_equal);
  tcase_add_test(tc_core, is_less_ne);
  tcase_add_test(tc_core, is_less_or_equal_Classic);
  tcase_add_test(tc_core, is_less_or_equal_Norm);
  tcase_add_test(tc_core, decimal_is_less_1);
  tcase_add_test(tc_core, decimal_is_less_2);
  tcase_add_test(tc_core, decimal_is_less_3);
  tcase_add_test(tc_core, decimal_is_less_4);
  tcase_add_test(tc_core, decimal_is_less_5);
  tcase_add_test(tc_core, decimal_is_less_6);
  tcase_add_test(tc_core, decimal_is_less_7);
  tcase_add_test(tc_core, decimal_is_less_8);
  tcase_add_test(tc_core, decimal_is_less_or_equal_1);
  tcase_add_test(tc_core, decimal_is_less_or_equal_2);
  tcase_add_test(tc_core, decimal_is_less_or_equal_or_equal_3);
  tcase_add_test(tc_core, decimal_is_less_or_equal_4);
  tcase_add_test(tc_core, decimal_is_less_or_equal_5);
  tcase_add_test(tc_core, decimal_is_less_or_equal_6);
  tcase_add_test(tc_core, decimal_is_less_or_equal_7);
  tcase_add_test(tc_core, decimal_is_less_or_equal_8);
  tcase_add_test(tc_core, decimal_is_greater_1);
  tcase_add_test(tc_core, decimal_is_greater_2);
  tcase_add_test(tc_core, decimal_is_greater_3);
  tcase_add_test(tc_core, decimal_is_greater_4);
  tcase_add_test(tc_core, decimal_is_greater_5);
  tcase_add_test(tc_core, decimal_is_greater_6);
  tcase_add_test(tc_core, decimal_is_greater_7);
  tcase_add_test(tc_core, decimal_is_greater_8);
  tcase_add_test(tc_core, decimal_is_greater_or_equal_1);
  tcase_add_test(tc_core, decimal_is_greater_or_equal_2);
  tcase_add_test(tc_core, decimal_is_greater_or_equal_or_equal_3);
  tcase_add_test(tc_core, decimal_is_greater_or_equal_4);
  tcase_add_test(tc_core, decimal_is_greater_or_equal_5);
  tcase_add_test(tc_core, decimal_is_greater_or_equal_6);
  tcase_add_test(tc_core, decimal_is_greater_or_equal_7);
  tcase_add_test(tc_core, decimal_is_greater_or_equal_8);
  tcase_add_test(tc_core, decimal_is_equal_1);
  tcase_add_test(tc_core, decimal_is_equal_2);
  tcase_add_test(tc_core, decimal_is_equal_3);
  tcase_add_test(tc_core, decimal_is_equal_4);
  tcase_add_test(tc_core, decimal_is_equal_5);
  tcase_add_test(tc_core, decimal_is_equal_6);
  tcase_add_test(tc_core, decimal_is_equal_7);
  tcase_add_test(tc_core, decimal_is_not_equal_1);
  tcase_add_test(tc_core, decimal_is_not_equal_2);
  tcase_add_test(tc_core, decimal_is_not_equal_3);
  tcase_add_test(tc_core, decimal_is_not_equal_4);
  tcase_add_test(tc_core, decimal_is_not_equal_5);
  tcase_add_test(tc_core, decimal_is_not_equal_6);
  tcase_add_test(tc_core, decimal_is_not_equal_7);
  suite_add_tcase(s, tc_core);

  return s;
}