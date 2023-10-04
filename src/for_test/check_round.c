#include "check_main.h"

START_TEST(s21_round_1) {
  s21_decimal val = {{128, 0, 0, 0}};
  s21_decimal res = {0};
  s21_setScale(&val, 1);
  s21_round(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = 13;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(s21_round_2) {
  s21_decimal x = {{95008, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 0);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_round(x, &z);
  char res1[1000], res2[1000] = "95008 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_3) {
  s21_decimal x = {{95008, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 1);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_round(x, &z);
  char res1[1000], res2[1000] = "9501 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_4) {
  s21_decimal x = {{95008, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 2);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_round(x, &z);
  char res1[1000], res2[1000] = "950 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_5) {
  s21_decimal x = {{95008, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 4);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_round(x, &z);
  char res1[1000], res2[1000] = "10 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_6) {
  s21_decimal x = {{95008, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 5);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_round(x, &z);
  char res1[1000], res2[1000] = "1 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_7) {
  s21_decimal x = {{95008, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 6);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_round(x, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_8) {
  s21_decimal x = {{95008, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 0);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_round(x, &z);
  char res1[1000], res2[1000] = "95008 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_9) {
  s21_decimal x = {{95008, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 1);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_round(x, &z);
  char res1[1000], res2[1000] = "9501 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_10) {
  s21_decimal x = {{95008, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 2);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_round(x, &z);
  char res1[1000], res2[1000] = "950 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_11) {
  s21_decimal x = {{95008, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 4);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_round(x, &z);
  char res1[1000], res2[1000] = "10 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_12) {
  s21_decimal x = {{95008, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 5);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_round(x, &z);
  char res1[1000], res2[1000] = "1 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_13) {
  s21_decimal x = {{95008, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 6);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_round(x, &z);
  char res1[1000], res2[1000] = "0 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_14) {
  s21_decimal value_1 = {{7464923, 0, 0, 0}};
  s21_setScale(&value_1, 5);
  s21_decimal check = {{75, 0, 0, 0}};
  s21_decimal result;
  int return_value = s21_round(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_round_15) {
  s21_decimal value_1 = {{7444923, 0, 0, 0}};
  s21_setScale(&value_1, 5);
  s21_decimal check = {{74, 0, 0, 0}};
  s21_decimal result;
  int return_value = s21_round(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_round_16) {
  s21_decimal value_1 = {{7464923, 0, 0, 0}};
  s21_setSign(&value_1, 1);
  s21_setScale(&value_1, 5);
  s21_decimal check = {{75, 0, 0, 0}};
  s21_setSign(&check, 1);
  s21_decimal result;
  int return_value = s21_round(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_round_17) {
  s21_decimal value_1 = {{7444923, 0, 0, 0}};
  s21_setSign(&value_1, 1);
  s21_setScale(&value_1, 5);
  s21_decimal check = {{74, 0, 0, 0}};
  s21_setSign(&check, 1);
  s21_decimal result;
  int return_value = s21_round(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_round_18) {
  float a = 0.4;
  s21_decimal fl_d;
  s21_from_float_to_decimal(a, &fl_d);
  s21_round(fl_d, &fl_d);
  float result;
  s21_from_decimal_to_float(fl_d, &result);
  ck_assert_double_eq(result, round(0.4));
  a = -3.5;
  s21_from_float_to_decimal(a, &fl_d);
  s21_round(fl_d, &fl_d);
  s21_from_decimal_to_float(fl_d, &result);
  ck_assert_double_eq(result, round(-3.5));
  s21_decimal d1 = {{12345}};
  s21_setScale(&d1, 1);
  s21_round(d1, &d1);
  ck_assert_double_eq(d1.bits[0], round(1234.5));
}
END_TEST

Suite *s21_round_suite(void) {
  Suite *s;
  TCase *ts_core;
  s = suite_create(
      "\033[45m-s21_round-\033[0m");  // создает набор кейсов с заданным именем
  ts_core = tcase_create("case_round");
  tcase_add_test(ts_core, s21_round_1);
  tcase_add_test(ts_core, s21_round_2);
  tcase_add_test(ts_core, s21_round_3);
  tcase_add_test(ts_core, s21_round_4);
  tcase_add_test(ts_core, s21_round_5);
  tcase_add_test(ts_core, s21_round_6);
  tcase_add_test(ts_core, s21_round_7);
  tcase_add_test(ts_core, s21_round_8);
  tcase_add_test(ts_core, s21_round_9);
  tcase_add_test(ts_core, s21_round_10);
  tcase_add_test(ts_core, s21_round_11);
  tcase_add_test(ts_core, s21_round_12);
  tcase_add_test(ts_core, s21_round_13);
  tcase_add_test(ts_core, s21_round_14);
  tcase_add_test(ts_core, s21_round_15);
  tcase_add_test(ts_core, s21_round_16);
  tcase_add_test(ts_core, s21_round_17);
  tcase_add_test(ts_core, s21_round_18);

  suite_add_tcase(s, ts_core);
  return s;
}