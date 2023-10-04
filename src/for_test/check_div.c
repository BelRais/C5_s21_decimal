#include "check_main.h"

START_TEST(s21_div_1) {
  s21_decimal x = {{3100000000, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{1, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_div(x, y, &z);
  char res1[1000], res2[1000] = "3100000000 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_div_2) {
  s21_decimal x = {{1, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{3100000000, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_div(x, y, &z);
  char res1[1000], res2[1000] = "3225810516 0 0 1245184";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_div_3) {
  s21_decimal x = {{52525252, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
  int n1 = 0;
  n1 = s21_div(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 3);
}
END_TEST

START_TEST(s21_div_4) {
  s21_decimal x = {{52525252, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
  int n1 = 0;
  n1 = s21_div(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 3);
}
END_TEST

START_TEST(s21_div_5) {
  s21_decimal x = {{52525252, 0, 0, 0b0000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
  int n1 = 0;
  n1 = s21_div(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 3);
}
END_TEST

START_TEST(s21_div_6) {
  s21_decimal x = {{52525252, 0, 0, 8845}};
  s21_decimal y = {{0, 0, 0, 10}};
  s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
  int n1 = 0;
  n1 = s21_div(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 3);
}
END_TEST

START_TEST(s21_div_7) {
  s21_decimal x = {{52525252, 0, 0, 65465}};
  s21_decimal y = {{0, 0, 0, 9598595}};
  s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
  int n1 = 0;
  n1 = s21_div(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 3);
}
END_TEST

START_TEST(s21_div_8) {
  s21_decimal x = {{5, 0, 0, 0}};
  s21_decimal y = {{3, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_setScale(&x, 0);
  s21_setScale(&y, 20);
  int n1 = 0;
  n1 = s21_div(x, y, &z);
  char res1[1000], res2[1000] = "447392427 1737688055 903501810 524288";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(s21_div_9) {
  s21_decimal x = {{5, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{3, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_setScale(&x, 0);
  s21_setScale(&y, 20);
  int n1 = 0;
  n1 = s21_div(x, y, &z);
  char res1[1000], res2[1000] = "447392427 1737688055 903501810 2148007936";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(s21_div_10) {
  s21_decimal x = {{5, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal y = {{3, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_setScale(&x, 0);
  s21_setScale(&y, 20);
  int n1 = 0;
  n1 = s21_div(x, y, &z);
  char res1[1000], res2[1000] = "447392427 1737688055 903501810 2148007936";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(s21_div_11) {
  s21_decimal x = {{5, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal y = {{3, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_setScale(&x, 0);
  s21_setScale(&y, 20);
  int n1 = 0;
  n1 = s21_div(x, y, &z);
  char res1[1000], res2[1000] = "447392427 1737688055 903501810 524288";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(s21_div_12) {
  s21_decimal x = {{5, 0, 50, 0b10000000000000000000000000000000}};
  s21_decimal y = {{5, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_setScale(&x, 0);
  s21_setScale(&y, 20);
  int n1 = 0;
  n1 = s21_div(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 3);
}
END_TEST

Suite *s21_div_suite(void) {
  Suite *s;
  TCase *ts_core;
  s = suite_create(
      "\033[45m-s21_div-\033[0m");  // создает набор кейсов с заданным именем
  ts_core = tcase_create("case_div");
  tcase_add_test(ts_core, s21_div_1);
  tcase_add_test(ts_core, s21_div_2);
  tcase_add_test(ts_core, s21_div_3);
  tcase_add_test(ts_core, s21_div_4);
  tcase_add_test(ts_core, s21_div_5);
  tcase_add_test(ts_core, s21_div_6);
  tcase_add_test(ts_core, s21_div_7);
  tcase_add_test(ts_core, s21_div_8);
  tcase_add_test(ts_core, s21_div_9);
  tcase_add_test(ts_core, s21_div_10);
  tcase_add_test(ts_core, s21_div_11);
  tcase_add_test(ts_core, s21_div_12);
  suite_add_tcase(s, ts_core);
  return s;
}