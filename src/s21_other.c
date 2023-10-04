
#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {  // Готов 1
  int res = 0;
  if (result) {
    s21_decimal zero = {{0, 0, 0, 0}};
    s21_decimal one = {{1, 0, 0, 0}};
    s21_decimal value_int;
    s21_truncate(value, result);
    s21_truncate(value, &value_int);
    if (s21_is_less(value, zero) && s21_is_not_equal(value, value_int)) {
      s21_sub(value_int, one, result);
    }
  } else {
    res = 1;
  }
  return res;
}

int s21_round(s21_decimal value, s21_decimal *result) {  // Готов 2
  int res = 0;
  if (result) {
    int left_to_zero = 0;
    s21_decimal half;
    s21_decimal zero = {{0, 0, 0, 0}};
    s21_decimal one = {{1, 0, 0, 0}};
    s21_decimal value_int;
    s21_decimal mant;
    s21_from_float_to_decimal(0.5, &half);
    if (s21_is_less(value, zero)) {
      left_to_zero = 1;
      s21_negate(value, &value);
    }
    s21_truncate(value, &value_int);
    s21_sub(value, value_int, &mant);
    if (s21_is_greater_or_equal(mant, half))
      s21_add(value_int, one, result);
    else
      *result = value_int;
    if (left_to_zero == 1) s21_negate(*result, result);
  } else {
    res = 1;
  }
  return res;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {  // Готов 3
  int res = 0;
  if (result) {
    int degree = s21_getScale(value), minus = s21_getSign(value);
    for (int i = 0; i < degree; i++) div_ten(&value);
    *result = value;
    s21_setSign(result, minus);
  } else {
    res = 1;
  }
  return res;
}

int div_ten(s21_decimal *a) {
  unsigned int ost = 0;
  s21_decimal result = {{0, 0, 0, 0}};
  int highest_bit = s21_last_bit(*a);
  for (int i = highest_bit; i >= 0; i--) {
    int new_bit = s21_getBit(*a, i);
    int item = (new_bit + ost * 2) / 10;
    ost = (new_bit + ost * 2) % 10;
    s21_shift_left(&result, 1);
    s21_setBit(&result, 0, item);
  }
  *a = result;
  s21_setScale(a, 0);
  return ost;
}

int s21_negate(s21_decimal value, s21_decimal *result) {  // Готов 4
  *result = value;
  s21_setSign(result, !s21_getSign(value));
  return 0;
}
