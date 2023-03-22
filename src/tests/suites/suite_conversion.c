#include "../test.h"
#define DIFF pow(10, -7)

// from float

START_TEST(float_nan) {
  s21_decimal x;
  s21_decimal res = {{0, 0, 0, 0}};
  float y = 0.0 / 0.0;
  ck_assert_int_eq(s21_from_float_to_decimal(y, &x), 1);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(x.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(neg_inf) {
  s21_decimal x;
  s21_decimal res = {{0, 0, 0, 0}};
  float y = -1.0 / 0.0;
  ck_assert_int_eq(s21_from_float_to_decimal(y, &x), 1);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(x.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(pos_inf) {
  s21_decimal x;
  s21_decimal res = {{0, 0, 0, 0}};
  float y = 1.0 / 0.0;
  ck_assert_int_eq(s21_from_float_to_decimal(y, &x), 1);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(x.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(float_1) {
  s21_decimal x;
  s21_decimal res = {{0x0078E480, 0, 0, 0x00060000}};
  float y = 79228162514264337593543950335E-28;
  float z = 0;
  ck_assert_int_eq(s21_from_float_to_decimal(y, &x), 0);
  ck_assert_int_eq(s21_from_decimal_to_float(x, &z), 0);
  // float check = 0;
  // check = y - z;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(x.bits[i], res.bits[i]);
  }
  ck_assert_float_eq_tol(z, y, 1e08);
}
END_TEST

START_TEST(float_2) {
  s21_decimal x;
  s21_decimal res = {{1, 0, 0, 0}};
  float y = 1.0;
  float z;
  ck_assert_int_eq(s21_from_float_to_decimal(y, &x), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(x.bits[i], res.bits[i]);
  }
  ck_assert_int_eq(s21_from_decimal_to_float(x, &z), 0);
  // float check = y - z;
  ck_assert_float_eq_tol(z, y, 1e08);
}
END_TEST

START_TEST(float_3) {
  s21_decimal x;
  s21_decimal res = {{0x00000079, 0, 0, 0x80020000}};
  float y = -1.21;
  float z;
  ck_assert_int_eq(s21_from_float_to_decimal(y, &x), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(x.bits[i], res.bits[i]);
  }
  ck_assert_int_eq(s21_from_decimal_to_float(x, &z), 0);
  // float check = y - z;
  ck_assert_float_eq_tol(z, y, 1e08);
}
END_TEST

START_TEST(float_4) {
  s21_decimal x;
  s21_decimal res = {{0x00129C05, 0, 0, 0x80060000}};
  float y = -1.219589346;
  float z = 0;
  ck_assert_int_eq(s21_from_float_to_decimal(y, &x), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(x.bits[i], res.bits[i]);
  }
  ck_assert_int_eq(s21_from_decimal_to_float(x, &z), 0);
  ck_assert_float_eq_tol(z, y, 1e08);
}
END_TEST

START_TEST(float_5) {
  s21_decimal x;
  s21_decimal res = {{0x434E4AA0, 0x0000002E, 0, 0x80000000}};
  float y = -198697689809.219589346;
  ck_assert_int_eq(s21_from_float_to_decimal(y, &x), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(x.bits[i], res.bits[i]);
  }
  float z = 0;
  ck_assert_int_eq(s21_from_decimal_to_float(x, &z), 0);
  ck_assert_float_eq_tol(z, y, 1e08);
}
END_TEST

START_TEST(float_6) {
  s21_decimal x;
  s21_decimal res = {{0x001E5448, 0, 0, 0x001B0000}};
  float y = 1987656.098756E-27;
  ck_assert_int_eq(s21_from_float_to_decimal(y, &x), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(x.bits[i], res.bits[i]);
  }
  float z = 0;
  ck_assert_int_eq(s21_from_decimal_to_float(x, &z), 0);
  ck_assert_float_eq_tol(z, y, 1e08);
}
END_TEST

START_TEST(float_7) {
  s21_decimal x;
  s21_decimal res = {{0xB4880000, 0x42BA35C8, 0x0000029D, 0}};
  float y = 12345678099876543456773.463;
  ck_assert_int_eq(s21_from_float_to_decimal(y, &x), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(x.bits[i], res.bits[i]);
  }
  float z = 0;
  ck_assert_int_eq(s21_from_decimal_to_float(res, &z), 0);
  ck_assert_float_eq_tol(z, y, 1e16);
}
END_TEST

START_TEST(float_8) {
  s21_decimal x;
  s21_decimal res = {{0, 0, 0, 0}};
  float y = 1234E+35;
  ck_assert_int_eq(s21_from_float_to_decimal(y, &x), 1);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(x.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(float_9) {
  s21_decimal x;
  s21_decimal res = {{0x0000278B, 0, 0, 0x00030000}};
  float y = 10.123;
  ck_assert_int_eq(s21_from_float_to_decimal(y, &x), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(x.bits[i], res.bits[i]);
  }
  float z = 0;
  ck_assert_int_eq(s21_from_decimal_to_float(x, &z), 0);
  ck_assert_float_eq_tol(z, y, 1e08);
}
END_TEST

START_TEST(float_10) {
  s21_decimal x;
  s21_decimal res = {{0x83200000, 0x8703F6C7, 0x00001A21, 0x80000000}};
  float y = -0.00001234E28;
  ck_assert_int_eq(s21_from_float_to_decimal(y, &x), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(x.bits[i], res.bits[i]);
  }
  float z = 0;
  ck_assert_int_eq(s21_from_decimal_to_float(x, &z), 0);
  ck_assert_float_eq_tol(z, y, 1e08);
}
END_TEST

START_TEST(float_11) {
  s21_decimal x;
  s21_decimal res = {{0xE01BE8A0, 0x00000002, 0, 0x80000000}};
  float y = -0.0000001234985690E17;
  ck_assert_int_eq(s21_from_float_to_decimal(y, &x), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(x.bits[i], res.bits[i]);
  }
  float z = 0;
  ck_assert_int_eq(s21_from_decimal_to_float(x, &z), 0);
  ck_assert_float_eq_tol(z, y, 1e08);
}
END_TEST

START_TEST(float_12) {
  s21_decimal x;
  s21_decimal res = {{0, 0, 0, 0}};
  float y = 8.5E28;
  ck_assert_int_eq(s21_from_float_to_decimal(y, &x), 1);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(x.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(float_13) {
  s21_decimal x;
  s21_decimal res = {{0x00000004, 0x00000000, 0x00000000, 0x001C0000}};
  float y = 4.5E-28;
  ck_assert_int_eq(s21_from_float_to_decimal(y, &x), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(x.bits[i], res.bits[i]);
  }
  float z = 0;
  ck_assert_int_eq(s21_from_decimal_to_float(x, &z), 0);
  ck_assert_float_eq_tol(z, y, 1e08);
}
END_TEST

START_TEST(float_14) {
  s21_decimal x;
  s21_decimal res = {{0x00000009, 0x00000000, 0x00000000, 0x001C0000}};
  float y = 8.5E-28;
  ck_assert_int_eq(s21_from_float_to_decimal(y, &x), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(x.bits[i], res.bits[i]);
  }
  float z = 0;
  ck_assert_int_eq(s21_from_decimal_to_float(x, &z), 0);
  ck_assert_float_eq_tol(z, y, 1e08);
}
END_TEST

START_TEST(to_int_1) {
  s21_decimal x = {{0xffffffff, 0, 0, 0}};
  int y;
  int res = 0;
  ck_assert_int_eq(s21_from_decimal_to_int(x, &y), 1);
  ck_assert_int_eq(y, res);
}
END_TEST

START_TEST(to_int_2) {
  s21_decimal x = {{0x7FFFFFFF, 0, 0, 0}};
  int y;
  int res = 2147483647;
  ck_assert_int_eq(s21_from_decimal_to_int(x, &y), 0);
  ck_assert_int_eq(y, res);
  s21_decimal z;
  ck_assert_int_eq(s21_from_int_to_decimal(res, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], x.bits[i]);
  }
}
END_TEST

START_TEST(to_int_3) {
  s21_decimal x = {{0x80000000, 0, 0, 0x80000000}};
  int y;
  int res = -2147483648;
  ck_assert_int_eq(s21_from_decimal_to_int(x, &y), 0);
  ck_assert_int_eq(y, res);
  s21_decimal z;
  ck_assert_int_eq(s21_from_int_to_decimal(res, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], x.bits[i]);
  }
}
END_TEST

START_TEST(to_int_4) {
  s21_decimal x = {{0x00000001, 0, 0, 0x80000000}};
  int y;
  int res = -1;
  ck_assert_int_eq(s21_from_decimal_to_int(x, &y), 0);
  ck_assert_int_eq(y, res);
  s21_decimal z;
  ck_assert_int_eq(s21_from_int_to_decimal(res, &z), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(z.bits[i], x.bits[i]);
  }
}
END_TEST

START_TEST(s21_from_decimal_to_float_1) {
  s21_decimal src;
  int result = 0;
  float number = 0.0;
  long int c = 2147680256;
  src.bits[0] = 18122;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = c;

  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, -18.122);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_2) {
  s21_decimal src;
  int result = 0;
  float number = 0.0;
  long int c = 2147483648;
  src.bits[0] = 1812;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = c;
  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, -1812);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_3) {
  s21_decimal src;
  int result = 0;
  float number = 0.0;
  src.bits[0] = 0XFFFFFF;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, 16777215);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_4) {
  s21_decimal src;
  int result = 0;
  float number = 0.0;
  long int c = 2147745792;
  src.bits[0] = 23450987;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = c;
  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, -2345.0987);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_5) {
  s21_decimal src;
  int result = 0;
  float number = 0.0;
  long int c = 4294967295;
  src.bits[0] = c;
  src.bits[1] = c;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, 0xFFFFFFFFFFFFFFFF);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_7) {
  s21_decimal dec;
  int result = 0;
  float number = 0.0;
  long int c = 2147483648;
  dec.bits[0] = 1812;
  dec.bits[1] = 0;
  dec.bits[2] = 0;
  dec.bits[3] = c;
  result = s21_from_decimal_to_float(dec, &number);
  ck_assert_float_eq(number, -1812);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_8) {
  s21_decimal dec;
  int result = 0;
  float number = 0.0;

  dec.bits[0] = 0XFFFFFF;
  dec.bits[1] = 0;
  dec.bits[2] = 0;
  dec.bits[3] = 0;
  result = s21_from_decimal_to_float(dec, &number);
  ck_assert_float_eq(number, 16777215);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_9) {
  s21_decimal dec;
  int result = 0;
  float number = 0.0;
  long int c = 2147745792;
  dec.bits[0] = 23450987;
  dec.bits[1] = 0;
  dec.bits[2] = 0;
  dec.bits[3] = c;
  result = s21_from_decimal_to_float(dec, &number);
  ck_assert_float_eq(number, -2345.0987);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_10) {
  s21_decimal dec;
  int result = 0;
  float number = 0.0;
  long int c = 4294967295;
  dec.bits[0] = c;
  dec.bits[1] = c;
  dec.bits[2] = 0;
  dec.bits[3] = 0;
  result = s21_from_decimal_to_float(dec, &number);
  ck_assert_float_eq(number, 0xFFFFFFFFFFFFFFFF);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_floatTest1) {
  // 6997
  s21_decimal src1;

  float src2;
  float *srcp = &src2;
  // s21_decimal src1 = 2546.5;

  src1.bits[0] = 0b00000000000000000110001101111001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  s21_from_decimal_to_float(src1, srcp);
  char var3str[1000];
  char result[1000];
  snprintf(var3str, sizeof(var3str), "%.6f", 2546.5);
  snprintf(result, sizeof(result), "%f", src2);
  ck_assert_str_eq(result, var3str);
}
END_TEST

START_TEST(s21_from_decimal_to_floatTest2) {
  // 7016
  s21_decimal src1;

  float src2;
  float *srcp = &src2;
  // s21_decimal src1 = -0.46453;

  src1.bits[0] = 0b00000000000000001011010101110101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001010000000000000000;
  s21_from_decimal_to_float(src1, srcp);
  char var3str[1000];
  char result[1000];
  snprintf(var3str, sizeof(var3str), "%.6f", -0.46453);
  snprintf(result, sizeof(result), "%f", src2);
  ck_assert_str_eq(result, var3str);
}
END_TEST

START_TEST(s21_from_decimal_to_floatTest3) {
  // 7035
  s21_decimal src1;

  float src2;
  float *srcp = &src2;
  // s21_decimal src1 = 3.5;

  src1.bits[0] = 0b00000000000000000000000000100011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  s21_from_decimal_to_float(src1, srcp);
  char var3str[1000];
  char result[1000];
  snprintf(var3str, sizeof(var3str), "%.6f", 3.5);
  snprintf(result, sizeof(result), "%f", src2);
  ck_assert_str_eq(result, var3str);
}
END_TEST

START_TEST(s21_from_decimal_to_floatTest4) {
  // 7054
  s21_decimal src1;

  float src2;
  float *srcp = &src2;
  // s21_decimal src1 = 4.5;

  src1.bits[0] = 0b00000000000000000000000000101101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  s21_from_decimal_to_float(src1, srcp);
  char var3str[1000];
  char result[1000];
  snprintf(var3str, sizeof(var3str), "%.6f", 4.5);
  snprintf(result, sizeof(result), "%f", src2);
  ck_assert_str_eq(result, var3str);
}
END_TEST

START_TEST(s21_from_decimal_to_floatTest5) {
  // 7073
  s21_decimal src1;

  float src2;
  float *srcp = &src2;
  // s21_decimal src1 = -4.5;

  src1.bits[0] = 0b00000000000000000000000000101101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000010000000000000000;
  s21_from_decimal_to_float(src1, srcp);
  char var3str[1000];
  char result[1000];
  snprintf(var3str, sizeof(var3str), "%.6f", -4.5);
  snprintf(result, sizeof(result), "%f", src2);
  ck_assert_str_eq(result, var3str);
}
END_TEST

START_TEST(s21_from_decimal_to_floatTest6) {
  // 7092
  s21_decimal src1;

  float src2;
  float *srcp = &src2;
  // s21_decimal src1 = -5.49265;

  src1.bits[0] = 0b00000000000010000110000110010001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001010000000000000000;
  s21_from_decimal_to_float(src1, srcp);
  char var3str[1000];
  char result[1000];
  snprintf(var3str, sizeof(var3str), "%.6f", -5.49265);
  snprintf(result, sizeof(result), "%f", src2);
  ck_assert_str_eq(result, var3str);
}
END_TEST

START_TEST(s21_from_decimal_to_floatTest7) {
  // 7111
  s21_decimal src1;

  float src2;
  float *srcp = &src2;
  // s21_decimal src1 = 2.5086531268974139743;

  src1.bits[0] = 0b01100101111011101101100101011111;
  src1.bits[1] = 0b01011100001001010100001101000110;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  s21_from_decimal_to_float(src1, srcp);
  char var3str[1000];
  char result[1000];
  snprintf(var3str, sizeof(var3str), "%.6f", 2.50865312689741);
  snprintf(result, sizeof(result), "%f", src2);
  ck_assert_str_eq(result, var3str);
}
END_TEST

Suite *init_suite_conversiont() {  // add 1e-6
  Suite *suite = suite_create("suite_conversion");

  TCase *tc_s21_float = tcase_create("case float");
  tcase_add_test(tc_s21_float, float_nan);
  tcase_add_test(tc_s21_float, pos_inf);
  tcase_add_test(tc_s21_float, neg_inf);
  tcase_add_test(tc_s21_float, float_1);
  tcase_add_test(tc_s21_float, float_2);
  tcase_add_test(tc_s21_float, float_3);
  tcase_add_test(tc_s21_float, float_4);
  tcase_add_test(tc_s21_float, float_5);
  tcase_add_test(tc_s21_float, float_6);
  tcase_add_test(tc_s21_float, float_7);
  tcase_add_test(tc_s21_float, float_8);
  tcase_add_test(tc_s21_float, float_9);
  tcase_add_test(tc_s21_float, float_10);
  tcase_add_test(tc_s21_float, float_11);
  tcase_add_test(tc_s21_float, float_12);
  tcase_add_test(tc_s21_float, float_13);
  tcase_add_test(tc_s21_float, float_14);

  tcase_add_test(tc_s21_float, s21_from_decimal_to_float_1);
  tcase_add_test(tc_s21_float, s21_from_decimal_to_float_2);
  tcase_add_test(tc_s21_float, s21_from_decimal_to_float_3);
  tcase_add_test(tc_s21_float, s21_from_decimal_to_float_4);
  tcase_add_test(tc_s21_float, s21_from_decimal_to_float_5);
  tcase_add_test(tc_s21_float, s21_from_decimal_to_float_7);
  tcase_add_test(tc_s21_float, s21_from_decimal_to_float_8);
  tcase_add_test(tc_s21_float, s21_from_decimal_to_float_9);
  tcase_add_test(tc_s21_float, s21_from_decimal_to_float_10);
  tcase_add_test(tc_s21_float, s21_from_decimal_to_floatTest1);
  tcase_add_test(tc_s21_float, s21_from_decimal_to_floatTest2);
  tcase_add_test(tc_s21_float, s21_from_decimal_to_floatTest3);
  tcase_add_test(tc_s21_float, s21_from_decimal_to_floatTest4);
  tcase_add_test(tc_s21_float, s21_from_decimal_to_floatTest5);
  tcase_add_test(tc_s21_float, s21_from_decimal_to_floatTest6);
  tcase_add_test(tc_s21_float, s21_from_decimal_to_floatTest7);
  suite_add_tcase(suite, tc_s21_float);

  TCase *tc_s21_int = tcase_create("case int");
  tcase_add_test(tc_s21_int, to_int_1);
  tcase_add_test(tc_s21_int, to_int_2);
  tcase_add_test(tc_s21_int, to_int_3);
  tcase_add_test(tc_s21_int, to_int_4);
  suite_add_tcase(suite, tc_s21_int);

  return suite;
}