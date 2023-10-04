#include "check_main.h"

START_TEST(s21_truncate_1) {
  float a = 2.6;
  s21_decimal fl_d;
  s21_from_float_to_decimal(a, &fl_d);
  s21_truncate(fl_d, &fl_d);
  float result;
  s21_from_decimal_to_float(fl_d, &result);
  ck_assert_double_eq(result, 2);
  a = -4.5;
  s21_from_float_to_decimal(a, &fl_d);
  s21_truncate(fl_d, &fl_d);
  s21_from_decimal_to_float(fl_d, &result);
  ck_assert_double_eq(result, -4);
}
END_TEST

START_TEST(s21_truncate_2) {
  s21_decimal x = {{15008, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 3);
  s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_truncate(x, &z);
  char res1[1000], res2[1000] = "15 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_truncate_3) {
  s21_decimal x = {{15008, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 2);
  s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_truncate(x, &z);
  char res1[1000], res2[1000] = "150 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_truncate_4) {
  s21_decimal val = {{2, 0, 0, ~(S21_MAX_UINT / 2)}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_truncate(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = -2.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(s21_truncate_5) {
  s21_decimal val = {{2, 0, 0, ~(S21_MAX_UINT / 2)}};
  s21_decimal res = {0};
  s21_setScale(&val, 5);
  ck_assert_int_eq(0, s21_truncate(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = -0.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(s21_truncate_6) {
  s21_decimal val = {{128, 0, 0, 0}};
  s21_decimal res = {0};
  s21_setScale(&val, 1);
  ck_assert_int_eq(0, s21_truncate(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = 12;
  ck_assert_float_eq(need, fres);
}
END_TEST

Suite *s21_truncate_suite(void) {
  Suite *s;
  TCase *ts_core;
  s = suite_create("\033[45m-s21_truncate-\033[0m");  // создает набор кейсов с
                                                      // заданным именем
  ts_core = tcase_create("case_truncate");
  tcase_add_test(ts_core, s21_truncate_1);
  tcase_add_test(ts_core, s21_truncate_2);
  tcase_add_test(ts_core, s21_truncate_3);
  tcase_add_test(ts_core, s21_truncate_4);
  tcase_add_test(ts_core, s21_truncate_5);
  tcase_add_test(ts_core, s21_truncate_6);

  suite_add_tcase(s, ts_core);
  return s;
}