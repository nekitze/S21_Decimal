#ifndef s21_MUL
#define s21_MUL

#include "../s21_decimal.h"

void to_small(s21_decimal *result, big_decimal res);
int drop_big_digit(big_decimal *src, unsigned long long *first);
int add_for_mul(big_decimal res_value, big_decimal value_1, big_decimal *res);
void to_big(s21_decimal from, big_decimal *to);
int is_null(s21_decimal src);
int last_one(big_decimal src, int small, int big);
int bank_rounding(big_decimal *src, unsigned long long div,
                  unsigned long long first);
int add_one(big_decimal *src);
// add
int s21_normalize_big(big_decimal *x1, big_decimal *x2);
int s21_mul10_big(big_decimal *src);
int basic_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
              int sign);
// sub
int basic_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
              int sign);

#endif  // S21_MUL