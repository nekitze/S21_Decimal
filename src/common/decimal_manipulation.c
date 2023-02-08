#include "../s21_decimal.h"

// перед сдачей из функции печати удалить инт128!!!!

void set_sign(s21_decimal *dst, int sign) {
  set_bit(&((dst->bits)[3]), 31, sign);
}

int get_sign(s21_decimal src) { return get_bit(src.bits[3], 31); }

int get_pow(s21_decimal src) {
  int dst = 0;
  for (int i = 16; i <= 23; i++) {
    dst += get_bit(src.bits[3], i) * ((int)pow(2, i - 16));
  }
  return dst;
}

int set_pow(s21_decimal *dst, int value) {
  if (value < 0 || value > 28) {
    return 1;
  }
  (dst->bits)[3] = 0;
  int id = 0;
  while (value > 0) {
    set_bit(&((dst->bits)[3]), 16 + id, value % 2);
    value /= 2;
    id++;
  }

  return 0;
}

void s21_set_null(s21_decimal *src) {
  for (int i = 0; i < 4; i++) {
    src->bits[i] = 0;
  }
}

void s21_decimal_print(s21_decimal src, int level) {
  if (level == 1) {
    for (int bits_pos = 0; bits_pos < 4; bits_pos++) {
    printf("bits[%d] = ", bits_pos);
    for (int i = 31; i >= 0; i--) {
      printf("%d", get_bit(src.bits[bits_pos], i));
      if (i % 8 == 0) {
        printf(" ");
      }
    }
    printf("\tunsigned form: %u\n", src.bits[bits_pos]);
  }
  }
  __int128_t full_form = 0;
  full_form += (unsigned)src.bits[2];
  full_form *= S21_2IN32;
  full_form += (unsigned)src.bits[1];
  full_form *= S21_2IN32;
  full_form += (unsigned)src.bits[0];
  char str_full_form[1000];
  int i = 0;
  for (; full_form > 0; i++) {
    str_full_form[i] = (full_form % 10) + '0';
    full_form /= 10;
  }
  str_full_form[i] = '\0';
  int l = 0, r = strlen(str_full_form) - 1;
  while (l < r) {
    char buff = str_full_form[l];
    str_full_form[l] = str_full_form[r];
    str_full_form[r] = buff;
    l++;
    r--;
  }
  printf("full form = ");
  if (get_sign(src) == 1) {
    printf("-");
  }
  if (strlen(str_full_form) == 0) {
    printf("0");
  }
  for (size_t i = 0; i < strlen(str_full_form); i++) {
    if ((size_t)get_pow(src) == strlen(str_full_form)-i) {
      printf(".");
    }
    printf("%c", str_full_form[i]);
  }
  printf("\n\n");
}


void s21_normalize(s21_decimal *x1, s21_decimal *x2) {
    s21_decimal *x_fix;
    int diff;
    if (get_pow(*x1) <= get_pow(*x2)) {
      x_fix = x1;
      diff = get_pow(*x2) - get_pow(*x1);
    } else {
      x_fix = x2;
      diff = get_pow(*x1) - get_pow(*x2);
    }
    while (diff--) {
      s21_mul10(x_fix);
      set_pow(x_fix, get_pow(*x_fix) + 1);
    }
}

unsigned int s21_as_uint(int x) { return *((unsigned int *)&x); }

int s21_as_int(unsigned int x) { return *((int *)&x); }

void s21_drop_last_digit(s21_decimal *src) {
  unsigned long long last, div;

  last = s21_as_uint(src->bits[2]);
  div = last % 10;
  src->bits[2] = s21_as_int((unsigned int)(last / 10));

  last = s21_as_uint(src->bits[1]) + div * S21_2IN32;
  div = last % 10;
  src->bits[1] = s21_as_int((unsigned int)(last / 10));

  last = s21_as_uint(src->bits[0]) + div * S21_2IN32;
  div = last % 10;
  src->bits[0] = s21_as_int((unsigned int)(last / 10));
}