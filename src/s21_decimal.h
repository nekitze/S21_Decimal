#ifndef s21_DECIMAL
#define s21_DECIMAL

#include <math.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

typedef struct {
  int bits[4];
} s21_decimal;

#define S21_2IN32 4294967296

enum { OK, CONVERSION_ERROR };


// COMMON


// bit manipulation

int get_bit(int src, int pos);

void set_bit(int *dst, int pos, int value);

// decimal manipulation

void set_sign(s21_decimal *dst, int sign);

int get_sign(s21_decimal src);

int set_pow(s21_decimal *dst, int value);

int get_pow(s21_decimal dst);

void s21_set_null(s21_decimal *src);

// level 0 - только число
// level 1 - еще и побитовый вывод
void s21_decimal_print(s21_decimal src, int level);

void s21_normalize(s21_decimal *x1, s21_decimal *x2);

unsigned int s21_as_uint(int x);

int s21_as_int(unsigned int x);

void s21_drop_last_digit(s21_decimal *src);

// CONVERSIONS


int s21_from_int_to_decimal(int src, s21_decimal *dst);

int s21_from_decimal_to_int(s21_decimal src, int *dst);


// ARITHMETICS

// 0 - OK; 1 - переполнение
int s21_mul10(s21_decimal *src);

// - 0 - OK  
// - 1 - число слишком велико или равно бесконечности
// - 2 - число слишком мало или равно отрицательной бесконечности
// - 3 - деление на 0
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// COMPARSION

int s21_is_less(s21_decimal a, s21_decimal b);
int s21_is_less_or_equal(s21_decimal a, s21_decimal b);
int s21_is_greater(s21_decimal a, s21_decimal b);
int s21_is_greater_or_equal(s21_decimal a, s21_decimal b);
int s21_is_equal(s21_decimal a, s21_decimal b);
int s21_is_not_equal(s21_decimal a, s21_decimal b);
int is_zero(s21_decimal a, s21_decimal b);

#endif  // S21_DECIMAL
