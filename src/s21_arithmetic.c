#include "s21_decimal.h"

// сложение
int s21_add(s21_decimal first_value, s21_decimal second_value,
            s21_decimal *result_value) {
  int return_value = 0;
  s21_init_decimal(result_value);
  s21_scale_equalization(&first_value, &second_value, 0);
  if (s21_getSign(first_value) == 1 && s21_getSign(second_value) == 0)
    inverse(&first_value);
  if (s21_getSign(first_value) == 0 && s21_getSign(second_value) == 1)
    inverse(&second_value);
  return_value = add_bit(second_value, first_value, result_value);
  if ((s21_getSign(first_value) == 1) && (s21_getSign(second_value) == 1))
    s21_negate(*result_value, result_value);
  return return_value;
}

int add_function(s21_decimal first_value, s21_decimal second_value,
                 s21_decimal *result_value, int *mind_value) {
  int return_value = 0;
  int mind_value1, mind_value2, mind_result;
  for (int i = 0; i <= 96; i++) {
    mind_value1 = s21_getBit(first_value, i);
    mind_value2 = s21_getBit(second_value, i);
    mind_result = mind_value1 + mind_value2 + *mind_value;
    if (mind_result == 0 || mind_result == 1) {
      s21_setBit(result_value, i, mind_result);
      *mind_value = 0;
    } else if ((mind_result == 2 || mind_result == 3) && i == 95) {
      return_value = 1;
      break;
    } else {
      s21_setBit(result_value, i, mind_result - 2);
      *mind_value = 1;
    }
  }
  return return_value;
}

void add_function2(s21_decimal *result_value) {
  int tmp = 1;
  for (int i = 0; i <= 96; i++) {
    int tmp1 = s21_getBit(*result_value, i);
    int tmp_res = tmp1 + tmp;
    if (tmp_res == 0) {
      s21_setBit(result_value, i, 0);
      tmp = 0;
    } else if (tmp_res == 1) {
      s21_setBit(result_value, i, 1);
      tmp = 0;
    } else if (tmp_res == 2 || tmp_res == 3) {
      s21_setBit(result_value, i, tmp_res == 2 ? 0 : 1);
      tmp = 1;
    }
  }
}

int add_bit(s21_decimal first_value, s21_decimal second_value,
            s21_decimal *result_value) {
  int temp_value = 0;
  int return_value =
      add_function(first_value, second_value, result_value, &temp_value);
  s21_setScale(result_value, s21_getScale(first_value));
  int setSingn =
      (s21_getSign(first_value) + s21_getSign(second_value) + temp_value) % 2;
  s21_setSign(result_value, setSingn);
  if (setSingn == 1) {
    result_value->bits[0] = ~result_value->bits[0];
    result_value->bits[1] = ~result_value->bits[1];
    result_value->bits[2] = ~result_value->bits[2];
    add_function2(result_value);
  }
  return return_value;
}

void inverse(s21_decimal *value) {
  value->bits[0] = ~value->bits[0];
  value->bits[1] = ~value->bits[1];
  value->bits[2] = ~value->bits[2];
  int tmp = 1;
  for (int i = 0; i <= 96; i++) {
    int tmp1 = s21_getBit(*value, i);
    int tmp_res = tmp1 + tmp;
    if (tmp_res == 0) {
      s21_setBit(value, i, 0);
      tmp = 0;
    } else if (tmp_res == 1) {
      s21_setBit(value, i, 1);
      tmp = 0;
    } else if (tmp_res == 2 || tmp_res == 3) {
      s21_setBit(value, i, tmp_res == 2 ? 0 : 1);
      tmp = 1;
    }
  }
  s21_setSign(value, (s21_getSign(*value) + tmp) % 2);
}

// вычитание

void sub_function(s21_decimal first_value, s21_decimal second_value,
                  s21_decimal *result_value) {
  for (int i = 0; i < 96; i++) {
    int tmp1 = s21_getBit(first_value, i);
    int tmp2 = s21_getBit(second_value, i);
    int tmp_res = tmp1 - tmp2;
    if (tmp_res == 0) {
      s21_setBit(result_value, i, 0);
      continue;
    } else if (tmp_res == 1) {
      s21_setBit(result_value, i, 1);
    } else if (tmp_res == -1) {
      int n = i + 1;
      while (s21_getBit(first_value, n) != 1) {
        s21_setBit(&first_value, n, 1);
        n++;
      }
      s21_setBit(&first_value, n, 0);
      s21_setBit(result_value, i, 1);
    }
  }
}

int s21_sub(s21_decimal first_value, s21_decimal second_value,
            s21_decimal *result_value) {
  s21_init_decimal(result_value);
  s21_scale_equalization(&first_value, &second_value, 0);
  int return_value = 0, sign_flag = 0;
  int sign1 = s21_getBit(first_value, 127);
  int sign2 = s21_getSign(second_value);
  if (sign1 != sign2 && sign1 == 0) sign_flag = 1;
  if (sign1 != sign2 && sign2 == 0) sign_flag = 2;
  if (sign_flag == 0 && sign1 == 0 && s21_is_less(first_value, second_value)) {
    s21_setSign(result_value, 1);
    s21_decimal hold = first_value;
    first_value = second_value;
    second_value = hold;
  }
  if (sign_flag == 0 && sign1 == 0) {
    sub_function(first_value, second_value, result_value);
    s21_setScale(result_value, s21_getScale(first_value));
  } else if (sign_flag == 0 && sign1 == 1) {
    s21_setBit(&first_value, 127, 0);
    s21_setBit(&second_value, 127, 0);
    return_value = s21_sub(second_value, first_value, result_value);
  } else if (sign_flag == 1) {
    s21_setBit(&second_value, 127, 0);
    return_value = s21_add(first_value, second_value, result_value);
  } else if (sign_flag == 2) {
    s21_setBit(&second_value, 127, 1);
    return_value = s21_add(first_value, second_value, result_value);
  }
  if (s21_getScale(*result_value) > 28 ||
      (s21_getScale(*result_value) == 28 && result_value->bits[0] == 0 &&
       result_value->bits[1] == 0 && result_value->bits[2] == 0))
    return_value = 2;
  if (return_value != 0) s21_init_decimal(result_value);
  return return_value;
}

// умножение

int mul_function(s21_decimal first_value, s21_decimal second_value,
                 s21_decimal *result_value, int sign) {
  int return_value = 0;
  s21_decimal temp = {{0, 0, 0, 0}};
  int last_bit_1 = s21_last_bit(first_value);
  for (int i = 0; i <= last_bit_1; i++) {
    s21_init_decimal(&temp);
    int value_bit_1 = s21_getBit(first_value, i);
    if (value_bit_1) {
      temp = second_value;
      if ((95 - last_bit_1 - 1) == i && sign == 0) {
        return_value = TOO_MUCH_OR_INF;
        break;
      } else if ((95 - last_bit_1 - 1) == i && sign == 1) {
        return_value = TOO_FEW_OR_NEG_INF;
        break;
      }
      s21_shift_left(&temp, i);
      return_value = mul_add_bit(result_value, &temp, result_value);
    }
  }
  return return_value;
}

int s21_mul(s21_decimal first_value, s21_decimal second_value,
            s21_decimal *result_value) {
  s21_init_decimal(result_value);
  int sign = s21_getSign(first_value) != s21_getSign(second_value) ? 1 : 0;
  int return_value =
      mul_function(first_value, second_value, result_value, sign);
  while (return_value != 0 &&
         (s21_getScale(first_value) > 0 || s21_getScale(second_value) > 0)) {
    s21_decimal *val1 = NULL;
    s21_decimal *val2 = NULL;
    if (s21_last_bit(first_value) > s21_last_bit(second_value) &&
        s21_getScale(first_value) > 0) {
      val1 = &first_value;
      val2 = &second_value;
    } else if (s21_last_bit(second_value) > s21_last_bit(first_value) &&
               s21_getScale(second_value) > 0) {
      val1 = &second_value;
      val2 = &first_value;
    } else {
      break;
    }
    int chosen_num_scale = s21_getScale(*val1);
    s21_decimal buf_ten = {{10, 0, 0, 0}};
    s21_decimal buf_residue = {{0, 0, 0, 0}};
    s21_decimal buf_div = mul_bits(*val1, buf_ten, &buf_residue);
    s21_decimal buf_zero = {{0, 0, 0, 0}};
    if (zero_flag(buf_div, buf_zero) == 1) {
      s21_bits_copy(buf_div, val1);
    } else {
      s21_bits_copy(buf_residue, val1);
    }
    s21_setScale(val1, --chosen_num_scale);
    return_value = s21_mul(*val1, *val2, result_value);
  }
  int scale = s21_getScale(first_value) + s21_getScale(second_value);
  s21_setScale(result_value, scale);
  s21_setSign(result_value, sign);
  if ((return_value != 0) || scale > 28) s21_init_decimal(result_value);
  return return_value;
}

s21_decimal mul_bits(s21_decimal first_value, s21_decimal second_value,
                     s21_decimal *buffer) {
  s21_init_decimal(buffer);
  s21_decimal result = {{0, 0, 0, 0}};
  for (int i = s21_last_bit(first_value); i >= 0; i--) {
    if (s21_getBit(first_value, i)) s21_setBit(buffer, 0, 1);
    if (s21_is_greater_or_equal(*buffer, second_value) == 1) {
      s21_sub(*buffer, second_value, buffer);
      if (i != 0) s21_shift_left(buffer, 1);
      if (s21_getBit(first_value, i - 1)) s21_setBit(buffer, 0, 1);
      s21_shift_left(&result, 1);
      s21_setBit(&result, 0, 1);
    } else {
      s21_shift_left(&result, 1);
      if (i != 0) s21_shift_left(buffer, 1);
      if ((i - 1) >= 0 && s21_getBit(first_value, i - 1))
        s21_setBit(buffer, 0, 1);
    }
  }
  return result;
}

int zero_flag(s21_decimal first_value, s21_decimal second_value) {
  int flag = 1;
  s21_decimal *tmp1 = &first_value;
  s21_decimal *tmp2 = &second_value;
  if (tmp1 && tmp2 && !first_value.bits[0] && !second_value.bits[0] &&
      !first_value.bits[1] && !second_value.bits[1] && !first_value.bits[2] &&
      !second_value.bits[2])
    flag = 0;
  return flag;
}

int mul_add_bit(s21_decimal *value1, s21_decimal *value2, s21_decimal *result) {
  int buf = 0, res = OK;
  for (int i = 0; i < 96; i++) {
    int bit1 = s21_getBit(*value1, i);
    int bit2 = s21_getBit(*value2, i);
    if (bit1 && bit2 && buf) {
      s21_setBit(result, i, 1);
    } else if (bit1 && bit2) {
      s21_setBit(result, i, 0);
      buf = 1;
    } else if (!bit1 && !bit2 && buf) {
      s21_setBit(result, i, 1);
      buf = 0;
    } else if (!bit1 && !bit2) {
      s21_setBit(result, i, 0);
    } else if (bit1 != bit2 && buf) {
      s21_setBit(result, i, 0);
    } else if (bit1 != bit2) {
      s21_setBit(result, i, 1);
    }
    if (i == 95 && buf == 1) res = TOO_MUCH_OR_INF;
  }
  return res;
}

// деление

int div_value(s21_decimal *first_value, s21_decimal second_value,
              s21_decimal *result_value, int scale) {
  int return_value = 0;
  int count = 0;
  s21_decimal buf_residue = {{1, 0, 0, 0}};
  s21_decimal buf_result = {{0, 0, 0, 0}};
  while (count < 10) {
    *result_value = buf_result;
    return_value = s21_integer_division(*first_value, second_value, &buf_result,
                                        &buf_residue, 0);
    if (s21_getScale(buf_result) == 0 && s21_last_bit(buf_result) > 93) {
      return_value = TOO_MUCH_OR_INF;
      break;
    }
    s21_add(buf_result, *result_value, &buf_result);
    if (buf_residue.bits[0] == 0 && buf_residue.bits[1] == 0 &&
        buf_residue.bits[2] == 0)
      break;
    *first_value = buf_residue;
    s21_setScale(first_value, scale + count);
    count++;
  }
  *result_value = buf_result;
  return return_value;
}

int s21_div(s21_decimal first_value, s21_decimal second_value,
            s21_decimal *result_value) {
  int return_value = 0;
  s21_decimal buf_zero = {{0, 0, 0, 0}};
  int sign_first_value = s21_getSign(first_value);
  int sign_second_value = s21_getSign(second_value);
  s21_setSign(&first_value, 0);
  s21_setSign(&second_value, 0);
  int scale = s21_getScale(first_value) - s21_getScale(second_value);
  if (scale < 0) scale = s21_scale_equalization(&first_value, &second_value, 0);
  if (s21_is_equal(second_value, buf_zero)) return_value = s21_NAN;
  if (s21_is_greater(second_value, first_value) && scale == 0) {
    s21_decimal ten = {{10, 0, 0, 0}};
    while (s21_is_greater(second_value, first_value)) {
      s21_mul(first_value, ten, &first_value);
      scale++;
      if (scale == 28) break;
    }
  }
  s21_setScale(&first_value, scale);
  return_value = div_value(&first_value, second_value, result_value, scale);
  if (sign_first_value != sign_second_value) s21_setSign(result_value, 1);
  if (return_value != 0) s21_init_decimal(result_value);
  return return_value;
}

// остаток от деления
int s21_mod(s21_decimal first_value, s21_decimal second_value,
            s21_decimal *result_value) {
  s21_decimal buffer = {{0, 0, 0, 0}};
  int return_value = s21_div(first_value, second_value, &buffer);
  if (return_value == 0) return_value = s21_truncate(buffer, &buffer);
  if (return_value == 0) return_value = s21_mul(buffer, second_value, &buffer);
  if (return_value == 0)
    return_value = s21_sub(first_value, buffer, result_value);
  return return_value;
}
