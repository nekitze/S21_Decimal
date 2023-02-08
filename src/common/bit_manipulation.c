#include "../s21_decimal.h"

int get_bit(int src, int pos) {
  if (src & (1 << pos)) {
    return 1;
  } else {
    return 0;
  }
}

void set_bit(int *dst, int pos, int value) {
  if (value) {  
    *dst |= (1 << pos);
  } else {  
    *dst &= ~(1 << pos);
  }
}