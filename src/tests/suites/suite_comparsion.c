#include "../test.h"

START_TEST(equal_default) {
    s21_decimal a = {{1, 2, 3, 0}};
    s21_decimal b = {{1, 2, 3, 0}};
    //s2_decimal_print(a);
    //s2_decimal_print(b);

    ck_assert_int_eq(s21_is_equal(a, b), 1);
}
END_TEST

START_TEST(equal_default_pow_not) {
    s21_decimal a = {{1, 2, 3, 0}};
    s21_decimal b = {{1, 2, 3, 0}};
    set_pow(&a, 2);
    set_pow(&b, 1);
    //s2_decimal_print(a);
    //s2_decimal_print(b);

    ck_assert_int_eq(s21_is_equal(a, b), 1);
}
END_TEST

START_TEST(equal_default_negative_num) {
    s21_decimal a = {{1, 2, 3, 0}};
    s21_decimal b = {{1, 2, 3, 0}};
    set_bit(&(b.bits[3]), 31, 1);
    //s2_decimal_print(a);
    //s2_decimal_print(b);

    ck_assert_int_eq(s21_is_equal(a, b), 0);
}
END_TEST

START_TEST(equal_default_not) {
    s21_decimal a = {{3, 2, 1, 0}};
    s21_decimal b = {{3, 2, 1, 0}};
    set_bit(&(b.bits[3]), 31, 1);
    //s2_decimal_print(a);
    //s2_decimal_print(b);

    ck_assert_int_eq(s21_is_equal(a, b), 0);
}
END_TEST

START_TEST(equal_zero_minus) {
    s21_decimal a = {{0, 0, 0, 0}};
    s21_decimal b = {{0, 0, 0, 0}};
    set_bit(&(b.bits[3]), 31, 1);
    //s2_decimal_print(a);
    //s2_decimal_print(b);

    ck_assert_int_eq(s21_is_equal(a, b), 1);
}
END_TEST

START_TEST(not_equal_default) {
    s21_decimal a = {{0, 0, 0, 0}};
    s21_decimal b = {{0, 1, 0, 0}};
    set_bit(&(b.bits[3]), 31, 1);

    ck_assert_int_eq(s21_is_not_equal(a, b), 1);
}
END_TEST

START_TEST(not_equal_zero_minus) {
    s21_decimal a = {{0, 0, 0, 0}};
    s21_decimal b = {{0, 0, 0, 0}};
    set_bit(&(b.bits[3]), 31, 1);

    ck_assert_int_eq(s21_is_not_equal(a, b), 0);
}
END_TEST

START_TEST(greater_default) {
    s21_decimal a = {{0, 0, 1, 0}};
    s21_decimal b = {{0, 0, 0, 0}};

    ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(greater_negative) {
    s21_decimal a = {{1, 1, 1, 0}};
    s21_decimal b = {{1, 1, 1, 0}};

    set_bit(&(a.bits[3]), 31, 1);

    ck_assert_int_eq(s21_is_greater(a, b), 0);
}
END_TEST

START_TEST(greater_pow) {
    s21_decimal a = {{1, 2, 3, 0}};
    s21_decimal b = {{1, 2, 3, 0}};

    set_pow(&a, 2);
    set_pow(&b, 3);

    ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

Suite *init_suite_comparsion(void) {
  Suite *s;
  TCase *tc_s21_comparsion;

  // Создаём сьют
  s = suite_create("[s21_decmial] suite");

  // Создаём кейс

  tc_s21_comparsion = tcase_create("[s21_comparsion] case");

  // Добавялем тесты в кейс

  tcase_add_test(tc_s21_comparsion, equal_default);
  tcase_add_test(tc_s21_comparsion, equal_default_not);
  tcase_add_test(tc_s21_comparsion, not_equal_default);
  tcase_add_test(tc_s21_comparsion, not_equal_zero_minus);
  tcase_add_test(tc_s21_comparsion, equal_zero_minus);
  tcase_add_test(tc_s21_comparsion, equal_default_pow_not);
  tcase_add_test(tc_s21_comparsion, equal_default_negative_num);
  tcase_add_test(tc_s21_comparsion, greater_default);
  tcase_add_test(tc_s21_comparsion, greater_negative);
  tcase_add_test(tc_s21_comparsion, greater_pow);

    // Добавляем кейсы в сьют

  suite_add_tcase(s, tc_s21_comparsion);

  return s;
}

// int main() {
//   int number_failed;
//   Suite *s;
//   SRunner *sr;

//   s = s21_comparsion_suite();
//   sr = srunner_create(s);

//   srunner_run_all(sr, CK_NORMAL);
//   number_failed = srunner_ntests_failed(sr);
//   srunner_free(sr);
//   return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
// }
