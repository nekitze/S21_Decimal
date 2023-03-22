#ifndef s21_DECIMAL
#define s21_DECIMAL

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int bits[4];
} s21_decimal;

typedef struct {
  int bits[6];
  int scale;
} big_decimal;

#define S21_2IN32 4294967296

enum { OK, CONVERSION_ERROR };

// COMMON

// bit manipulation

int get_bit(int src, int pos);

void set_bit(int *dst, int pos, int value);

void right_shift(s21_decimal *value);

void left_shift(s21_decimal *value);

void left_shift_big(big_decimal *value);

// decimal manipulation

void set_sign(s21_decimal *dst, int sign);

int get_sign(s21_decimal src);

int set_pow(s21_decimal *dst, int value);

int get_pow(s21_decimal dst);

void s21_set_null(s21_decimal *src);

// level 0 - только число
// level 1 - еще и побитовый вывод

int s21_normalize(s21_decimal *x1, s21_decimal *x2);

unsigned int s21_as_uint(int x);

int s21_as_int(unsigned int x);

int s21_drop_last_digit(s21_decimal *src);

// CONVERSIONS

int s21_from_int_to_decimal(int src, s21_decimal *dst);

int s21_from_decimal_to_int(s21_decimal src, int *dst);

int s21_from_float_to_decimal(float src, s21_decimal *dst);

int s21_from_decimal_to_float(s21_decimal src, float *dst);

// ARITHMETICS

// 0 - OK; 1 - переполнение

// - 0 - OK
// - 1 - число слишком велико или равно бесконечности
// - 2 - число слишком мало или равно отрицательной бесконечности
// - 3 - деление на 0
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// - 0 - OK
// - 1 - число слишком велико или равно бесконечности
// - 2 - число слишком мало или равно отрицательной бесконечности
// - 3 - деление на 0
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// mul

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// div

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// mod

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// COMPARSION

int s21_is_less(s21_decimal a, s21_decimal b);
int s21_is_less_or_equal(s21_decimal a, s21_decimal b);
int s21_is_greater(s21_decimal a, s21_decimal b);
int s21_is_greater_or_equal(s21_decimal a, s21_decimal b);
int s21_is_equal(s21_decimal a, s21_decimal b);
int s21_is_not_equal(s21_decimal a, s21_decimal b);
int is_zero(s21_decimal a, s21_decimal b);

// OTHER

// - 0 - OK; 1 - ошибка вычисления
int s21_floor(s21_decimal value, s21_decimal *result);
// - 0 - OK; 1 - ошибка вычисления
int s21_round(s21_decimal value, s21_decimal *result);
// - 0 - OK; 1 - ошибка вычисления
int s21_negate(s21_decimal value, s21_decimal *result);
// - 0 - OK; 1 - ошибка вычисления
int s21_truncate(s21_decimal value, s21_decimal *result);

#endif  // S21_DECIMAL