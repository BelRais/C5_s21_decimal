#include "check_main.h"

START_TEST(s21_add_1) {
  s21_decimal x = {{4294967294, S21_MAX_UINT, S21_MAX_UINT,
                    0b00000000000000000000000000000000}};
  s21_decimal y = {{1, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char res1[1000], res2[1000] = "4294967295 4294967295 4294967295 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_add_2) {
  s21_decimal x = {{20, 1, 0, 0b10000000000000000000000000000000}};
  s21_decimal y = {{21, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char res1[1000], res2[1000] = "4294967295 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_add_3) {
  s21_decimal x = {{20, 1, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{21, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char res1[1000], res2[1000] = "4294967295 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_add_4) {
  s21_decimal x = {{20, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal y = {{21, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char res1[1000], res2[1000] = "1 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_add_5) {
  s21_decimal x = {{25, 1, 0, 0b10000000000000000000000000000000}};
  s21_decimal y = {{21, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char res1[1000], res2[1000] = "4 1 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_add_6) {
  s21_decimal x = {{100, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal y = {{100, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_add_7) {
  s21_decimal x = {{99, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{100, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char res1[1000], res2[1000] = "1 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_add_8) {
  s21_decimal x = {{0, 0, 300000000, 1835008}};
  s21_decimal y = {{0, 0, 300000000, 1835008}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char res1[1000], res2[1000] = "0 0 600000000 1835008";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_add_9) {
  s21_decimal x = {{0, 0, 3000000000, 0}};
  s21_decimal y = {{0, 0, 3000000000, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char res1[1000], res2[1000] = "0 0 1705032704 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_add_10) {
  s21_decimal x = {{1, 0, 0, 1835008}};
  s21_decimal y = {{1, 0, 0, 2149318656}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 1835008";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

Suite *s21_add_suite(void) {
  Suite *s;
  TCase *ts_core;
  s = suite_create("\033[45m-s21_add-\033[0m");
  ts_core = tcase_create("case_add");
  tcase_add_test(ts_core, s21_add_1);
  tcase_add_test(ts_core, s21_add_2);
  tcase_add_test(ts_core, s21_add_3);
  tcase_add_test(ts_core, s21_add_4);
  tcase_add_test(ts_core, s21_add_5);
  tcase_add_test(ts_core, s21_add_6);
  tcase_add_test(ts_core, s21_add_7);
  tcase_add_test(ts_core, s21_add_8);
  tcase_add_test(ts_core, s21_add_9);
  tcase_add_test(ts_core, s21_add_10);

  suite_add_tcase(s, ts_core);
  return s;
}