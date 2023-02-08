#include "../s21_decimal.h"

int s21_mul10(s21_decimal *src) {
    s21_decimal new_src = *src;

    long long int buff;
    int add = 0;
    for (int i = 0; i <= 2; i++) {
        buff = new_src.bits[i];
        buff *= 10;
        buff += add;
        if (buff >= S21_2IN32) {
            if (i == 2) {
                return 1;
            }
            add = buff / S21_2IN32;
            buff %= S21_2IN32;
        } else {
            add = 0;
        }
        
        new_src.bits[i] = buff;
    }
    *src = new_src;
    return 0;
}