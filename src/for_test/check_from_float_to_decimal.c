#include "check_main.h"

START_TEST(s21_from_float_to_decimal_1) {
  float src = 56.986;
  s21_decimal z = {{0, 0, 0, 0}};
  int n1 = s21_from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "56986 0 0 196608";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_2) {
  float src = -1.596;
  s21_decimal z = {{0, 0, 0, 0}};
  int n1 = s21_from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "1596 0 0 2147680256";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_3) {
  float src = 46237.42332 / 12712.37834;
  s21_decimal z = {{0, 0, 0, 0}};
  int n1 = s21_from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "3637197 0 0 393216";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

Suite *s21_from_float_to_decimal_suite(void) {
  Suite *s = suite_create(
      "\033[45m-s21_from_float_to_decimal-\033[0m");  // создает набор кейсов с
                                                      // заданным именем
  TCase *tc1_1 = tcase_create("case_from_float_to_decimal");
  tcase_add_test(tc1_1, s21_from_float_to_decimal_1);
  tcase_add_test(tc1_1, s21_from_float_to_decimal_2);
  tcase_add_test(tc1_1, s21_from_float_to_decimal_3);

  suite_add_tcase(s, tc1_1);
  return s;
}