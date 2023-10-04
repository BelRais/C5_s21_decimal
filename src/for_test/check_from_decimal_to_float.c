#include "check_main.h"

START_TEST(dec_to_float_1) {
  s21_decimal x = {{15008, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 3);
  float res1;
  int n1 = s21_from_decimal_to_float(x, &res1);
  float res2 = 15.008;
  ck_assert_float_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(dec_to_float_2) {
  s21_decimal x = {{15008, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 3);
  float res1;
  int n1 = s21_from_decimal_to_float(x, &res1);
  float res2 = -15.008;
  ck_assert_float_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(dec_to_float_3) {
  s21_decimal x = {{15008, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 3);
  float res1 = 0;
  int n1 = s21_from_decimal_to_float(x, NULL);
  float res2 = 0;
  ck_assert_float_eq(res1, res2);
  ck_assert_int_eq(n1, 1);
}
END_TEST

Suite *s21_is_from_decimal_to_float(void) {
  Suite *s = suite_create(
      "\033[45m-s21_from_decimal_to_float-\033[0m");  // создает набор кейсов с
                                                      // заданным именем
  TCase *tc1_1 = tcase_create("case_is_equal");
  tcase_add_test(tc1_1, dec_to_float_1);
  tcase_add_test(tc1_1, dec_to_float_2);
  tcase_add_test(tc1_1, dec_to_float_3);

  suite_add_tcase(s, tc1_1);
  return s;
}