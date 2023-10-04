#include "check_main.h"

START_TEST(s21_mod_1) {
  s21_decimal x = {{150000008, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{15, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 3);
  s21_setScale(&y, 0);
  int n1 = 0;
  n1 = s21_mod(x, y, &z);
  char res1[1000], res2[1000] = "8 0 0 196608";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(s21_mod_2) {
  s21_decimal x = {{91, 0, 0, 0}};
  s21_decimal y = {{50, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_setScale(&x, 0);
  s21_setScale(&y, 0);
  int n1 = 0;
  n1 = s21_mod(x, y, &z);
  char res1[1000], res2[1000] = "41 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(s21_mod_3) {
  s21_decimal x = {{91, 0, 0, 0}};
  s21_decimal y = {{95, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_setScale(&x, 0);
  s21_setScale(&y, 0);
  int n1 = 0;
  n1 = s21_mod(x, y, &z);
  char res1[1000], res2[1000] = "91 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(s21_mod_4) {
  s21_decimal x = {{91, 0, 0, 0}};
  s21_decimal y = {{0, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_setScale(&x, 0);
  s21_setScale(&y, 0);
  int n1 = 0;
  n1 = s21_mod(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 3);
}
END_TEST

START_TEST(s21_mod_5) {
  s21_decimal x = {{91, 0, 0, 0}};
  s21_decimal y = {{5, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_setScale(&x, 50);
  s21_setScale(&y, 0);
  int n1 = 0;
  n1 = s21_mod(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 2);
}
END_TEST

START_TEST(s21_mod_6) {
  s21_decimal x = {{125, 0, 0, 0}};
  s21_decimal y = {{3, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_setScale(&x, 1);
  s21_setScale(&y, 0);
  int n1 = 0;
  n1 = s21_mod(x, y, &z);
  char res1[1000], res2[1000] = "5 0 0 65536";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(s21_mod_7) {
  s21_decimal x = {{125, 0, 0, 0}};
  s21_decimal y = {{3, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_setScale(&x, 0);
  s21_setScale(&y, 1);
  int n1 = 0;
  n1 = s21_mod(x, y, &z);
  char res1[1000], res2[1000] = "2 0 0 65536";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

Suite *s21_mod_suite(void) {
  Suite *s;
  TCase *ts_core;
  s = suite_create(
      "\033[45m-s21_mod-\033[0m");  // создает набор кейсов с заданным именем
  ts_core = tcase_create("case_mod");
  tcase_add_test(ts_core, s21_mod_1);
  tcase_add_test(ts_core, s21_mod_2);
  tcase_add_test(ts_core, s21_mod_3);
  tcase_add_test(ts_core, s21_mod_4);
  tcase_add_test(ts_core, s21_mod_5);
  tcase_add_test(ts_core, s21_mod_6);
  tcase_add_test(ts_core, s21_mod_7);

  suite_add_tcase(s, ts_core);
  return s;
}