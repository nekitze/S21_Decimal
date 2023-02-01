#include "../s21_decimal.h"

int get_bit(int src, int pos) {
    if (src & (1 << pos)) {
        return 1;
    } else {
        return 0;
    }
}

void set_bit(int *dst, int pos, int value) {
    if (value) { // если хотим поставить 1
        *dst |= (1 << pos);
    } else { // если хотим поставить 0
        *dst &= ~(1 << pos);
    }
}


void set_sign(s21_decimal *dst, int sign) {
    set_bit(&((dst->bits)[3]), 31, sign);
}

int get_sign(s21_decimal src) {
    return get_bit(src.bits[3], 31);
}

int get_pow(s21_decimal src) {
    int dst = 0;
    for (int i = 16; i <= 23; i++) {
        dst += get_bit(src.bits[3], i) * ((int) pow(2, i));
    }
    return dst;
}

int set_pow(s21_decimal *dst, int value) {
    if (value < 0 || value > 28) {
        return 1;
    }
    
    int id = 0;
    while (value > 0) {
        set_bit(&((dst->bits)[3]), 16 + id, value % 2);
        value /= 2;
    }

    return 0;
}


void s2_decimal_print(s21_decimal src) {
    for (int bits_pos = 0; bits_pos < 4; bits_pos++) {
        printf("bits[%d] = ", bits_pos);
        for (int i = 31; i >= 0; i--) {
            printf("%d", get_bit(src.bits[bits_pos], i));
        }
        printf("\n");
    }
}

