#include "s21_decimal.h"

int s21_is_less(s21_decimal a, s21_decimal b) { return s21_is_greater(b, a); }

int s21_is_less_or_equal(s21_decimal a, s21_decimal b) {
  return (s21_is_less(a, b) || s21_is_equal(a, b));
}

int s21_is_greater(s21_decimal a, s21_decimal b) {
  int res = 0;
  s21_check_scale(&a, &b);
  int minus1 = s21_getSign(a), minus2 = s21_getSign(b);
  if (minus1 && !minus2)
    res = 0;
  else if (!minus1 && minus2)
    res = 1;
  else {
    for (int i = 95; i >= 0; i--) {
      int bit1 = s21_getBit(a, i), bit2 = s21_getBit(b, i);
      if (bit1 > bit2) {
        res = 1;
        break;
      }
      if (bit1 < bit2) {
        res = 0;
        break;
      }
    }
    if (minus1 && minus2) res = !res;
  }
  return s21_is_equal(a, b) ? 0 : res;
}

int s21_is_greater_or_equal(s21_decimal a, s21_decimal b) {
  return (s21_is_greater(a, b) || s21_is_equal(a, b));
}

int s21_is_equal(s21_decimal a, s21_decimal b) {
  s21_check_scale(&a, &b);
  int res = 1;
  int minus1 = s21_getSign(a), minus2 = s21_getSign(b);
  if (minus1 != minus2)
    res = 0;
  else {
    for (int i = 95; i >= 0; i--) {
      if (s21_getBit(a, i) != s21_getBit(b, i)) {
        res = 0;
        break;
      }
    }
  }
  return res;
}

int s21_is_not_equal(s21_decimal a, s21_decimal b) {
  return (!s21_is_equal(a, b));
}