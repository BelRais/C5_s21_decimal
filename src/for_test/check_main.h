#ifndef SRC_TEST
#define SRC_TEST

#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_decimal.h"

Suite *s21_sub_suite(void);
Suite *s21_add_suite(void);
Suite *s21_mul_suite(void);
Suite *s21_div_suite(void);

Suite *s21_is_equal_suite(void);
Suite *s21_is_not_equal_suite(void);
Suite *s21_is_greater_suite(void);
Suite *s21_is_greater_or_equal_suite(void);
Suite *s21_is_less_suite(void);
Suite *s21_is_less_or_equal_suite(void);

Suite *s21_negate_suite(void);
Suite *s21_mod_suite(void);
Suite *s21_truncate_suite(void);
Suite *s21_round_suite(void);
Suite *s21_floor_suite(void);

Suite *s21_is_dec_to_int(void);
Suite *s21_is_int_to_dec_21(void);
Suite *s21_is_from_decimal_to_float(void);
Suite *s21_from_float_to_decimal_suite(void);

#endif  // TEST
