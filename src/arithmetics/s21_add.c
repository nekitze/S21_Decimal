#include "../s21_decimal.h"



int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    s21_normalize(&value_1, &value_2);
    int result_sign = 0;
    if (get_sign(value_1) == 0 && get_sign(value_2) == 0) {
        // v1 + v2
        result_sign = 0;
    } else if (get_sign(value_1) == 0 && get_sign(value_2) == 1) {
        // v1 - v2;
    }  else if (get_sign(value_1) == 1 && get_sign(value_2) == 0) {
        // v2 - v1;
    }  else if (get_sign(value_1) == 1 && get_sign(value_2) == 1) {
        // -(v1 + v2);
        result_sign = 0;
        set_sign(&value_1, 0);
        set_sign(&value_2, 0);
    }

    s21_set_null(result);
    long long int buff;
    int add = 0;
    for (int i = 0; i <= 2; i++) {
        buff = (unsigned)value_1.bits[i];
        buff += (unsigned)value_2.bits[i];
        buff += add;
        printf("i = %d\nbuff  = %lld\n2in23 = %ld\n\n", i, buff, S21_2IN32);
        if (buff >= S21_2IN32) {
            if (i == 2) {
                return 1;
            }
            add = buff / S21_2IN32;
            buff %= S21_2IN32;
        } else {
            add = 0;
        }
        result->bits[i] = buff;
    }
    set_pow(result, get_pow(value_1));
    set_sign(result, result_sign);
    return 0;
}