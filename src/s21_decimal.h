#ifndef S21_DECIMAL
#define S21_DECIMAL

#include <stdio.h>
#include <math.h>

typedef struct {
    int bits[4];
} s21_decimal;

// comparsion

// int s21_is_less(s21_decimal a, s21_decimal b);
// int s21_is_less_or_equal(s21_decimal a, s21_decimal b);
// int s21_is_greater(s21_decimal a, s21_decimal b);
// int s21_is_greater_or_equal(s21_decimal a, s21_decimal b);
int s21_is_equal(s21_decimal a, s21_decimal b);
int s21_is_not_equal(s21_decimal a, s21_decimal b);

// bit processing 

int get_bit(int src, int pos);

void set_bit(int *dst, int pos, int value);


// basic manipulation

void set_sign(s21_decimal *dst, int sign);

int get_sign(s21_decimal src);

int set_pow(s21_decimal *dst, int value);

int get_pow(s21_decimal dst);


// conversations

int s21_from_int_to_decimal(int src, s21_decimal *dst);

int s21_from_decimal_to_int(s21_decimal src, int *dst);

// debug

void s2_decimal_print(s21_decimal src);

#endif