#include "check_main.h"

START_TEST(s21_floor_1) {
  s21_decimal val = {{2, 0, 0, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_floor(val, &res));
}
END_TEST

START_TEST(s21_floor_2) {
  s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {0};
  s21_floor(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  ck_assert_float_eq(-2, fres);
}
END_TEST

START_TEST(s21_floor_3) {
  s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {0};
  s21_setScale(&val, 5);
  s21_floor(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  ck_assert_float_eq(-1, fres);
}
END_TEST

START_TEST(s21_floor_4) {
  s21_decimal val = {{2, 0, 0, 0}};
  s21_decimal res = {0};
  s21_setScale(&val, 5);
  s21_floor(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  ck_assert_float_eq(0, fres);
}
END_TEST

START_TEST(s21_floor_5) {
  s21_decimal x = {{15008, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 3);
  s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_floor(x, &z);
  char res1[1000], res2[1000] = "16 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_floor_6) {
  s21_decimal x = {{15008, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 3);
  s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_floor(x, &z);
  char res1[1000], res2[1000] = "15 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_floor_7) {
  s21_decimal x = {{15008, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 10);
  s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_floor(x, &z);
  char res1[1000], res2[1000] = "1 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_floor_8) {
  s21_decimal value_1 = {{7444923, 0, 0, 0}};
  s21_setScale(&value_1, 5);
  s21_decimal check = {{74, 0, 0, 0}};
  s21_decimal result;
  int return_value = s21_floor(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_floor_9) {
  s21_decimal value_1 = {{7444923, 0, 0, 0}};
  s21_setScale(&value_1, 5);
  s21_setSign(&value_1, 1);
  s21_decimal check = {{75, 0, 0, 0}};
  s21_setSign(&check, 1);
  s21_decimal result;
  int return_value = s21_floor(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_floor_10) {
  float a = 0.4;
  s21_decimal fl_d;
  s21_from_float_to_decimal(a, &fl_d);
  s21_floor(fl_d, &fl_d);
  float result;
  s21_from_decimal_to_float(fl_d, &result);
  ck_assert_double_eq(result, 0.0);

  a = -0.4;
  s21_from_float_to_decimal(a, &fl_d);
  s21_floor(fl_d, &fl_d);
  s21_from_decimal_to_float(fl_d, &result);
  ck_assert_double_eq(result, -1);
  a = 0;
  s21_from_float_to_decimal(a, &fl_d);
  s21_floor(fl_d, &fl_d);
  s21_from_decimal_to_float(fl_d, &result);
  ck_assert_double_eq(result, 0);
}
END_TEST

Suite *s21_floor_suite(void) {
  Suite *s;
  TCase *ts_core;
  s = suite_create(
      "\033[45m-s21_floor-\033[0m");  // создает набор кейсов с заданным именем
  ts_core = tcase_create("case_floor");
  tcase_add_test(ts_core, s21_floor_1);
  tcase_add_test(ts_core, s21_floor_2);
  tcase_add_test(ts_core, s21_floor_3);
  tcase_add_test(ts_core, s21_floor_4);
  tcase_add_test(ts_core, s21_floor_5);
  tcase_add_test(ts_core, s21_floor_6);
  tcase_add_test(ts_core, s21_floor_7);
  tcase_add_test(ts_core, s21_floor_8);
  tcase_add_test(ts_core, s21_floor_9);
  tcase_add_test(ts_core, s21_floor_10);

  suite_add_tcase(s, ts_core);
  return s;
}