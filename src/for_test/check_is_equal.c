#include "check_main.h"

START_TEST(s21_equal_1) {
  s21_decimal x = {{10, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 1);
  s21_setScale(&y, 0);
  s21_scale_equalization(&x, &y, 0);
  s21_decimal x_test = {{10, 0, 0, 65536}};
  s21_decimal y_test = {{0, 0, 0, 65536}};
  char res1[1000], res2[1000];
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x.bits[0],
           x.bits[1], x.bits[2], x.bits[3], y.bits[0], y.bits[1], y.bits[2],
           y.bits[3]);
  snprintf(res2, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x_test.bits[0],
           x_test.bits[1], x_test.bits[2], x_test.bits[3], y_test.bits[0],
           y_test.bits[1], y_test.bits[2], y_test.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_equal_2) {
  s21_decimal x = {{10, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{1, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 2);
  s21_setScale(&y, 0);
  s21_scale_equalization(&x, &y, 0);
  s21_decimal x_test = {{10, 0, 0, 131072}};
  s21_decimal y_test = {{100, 0, 0, 131072}};
  char res1[1000], res2[1000];
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x.bits[0],
           x.bits[1], x.bits[2], x.bits[3], y.bits[0], y.bits[1], y.bits[2],
           y.bits[3]);
  snprintf(res2, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x_test.bits[0],
           x_test.bits[1], x_test.bits[2], x_test.bits[3], y_test.bits[0],
           y_test.bits[1], y_test.bits[2], y_test.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_equal_3) {
  s21_decimal x = {{10, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{1, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 28);
  s21_setScale(&y, 0);
  s21_scale_equalization(&x, &y, 0);
  s21_decimal x_test = {{10, 0, 0, 1835008}};
  s21_decimal y_test = {{268435456, 1042612833, 542101086, 1835008}};
  char res1[1000], res2[1000];
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x.bits[0],
           x.bits[1], x.bits[2], x.bits[3], y.bits[0], y.bits[1], y.bits[2],
           y.bits[3]);
  snprintf(res2, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x_test.bits[0],
           x_test.bits[1], x_test.bits[2], x_test.bits[3], y_test.bits[0],
           y_test.bits[1], y_test.bits[2], y_test.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_equal_4) {
  s21_decimal x = {{10, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{5, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 28);
  s21_setScale(&y, 0);
  s21_scale_equalization(&x, &y, 0);
  s21_decimal x_test = {{10, 0, 0, 1835008}};
  s21_decimal y_test = {{1342177280, 918096869, 2710505431, 1835008}};
  char res1[1000], res2[1000];
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x.bits[0],
           x.bits[1], x.bits[2], x.bits[3], y.bits[0], y.bits[1], y.bits[2],
           y.bits[3]);
  snprintf(res2, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x_test.bits[0],
           x_test.bits[1], x_test.bits[2], x_test.bits[3], y_test.bits[0],
           y_test.bits[1], y_test.bits[2], y_test.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_equal_5) {
  s21_decimal x = {{10, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{5, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 0);
  s21_setScale(&y, 28);
  s21_scale_equalization(&x, &y, OK);
  s21_decimal x_test = {{268435456, 1042612833, 542101086, 1769472}};
  s21_decimal y_test = {{1, 0, 0, 1769472}};
  char res1[1000], res2[1000];
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x.bits[0],
           x.bits[1], x.bits[2], x.bits[3], y.bits[0], y.bits[1], y.bits[2],
           y.bits[3]);
  snprintf(res2, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x_test.bits[0],
           x_test.bits[1], x_test.bits[2], x_test.bits[3], y_test.bits[0],
           y_test.bits[1], y_test.bits[2], y_test.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_equal_6) {
  s21_decimal x = {{10, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal y = {{5, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 0);
  s21_setScale(&y, 28);
  s21_scale_equalization(&x, &y, OK);
  s21_decimal x_test = {{268435456, 1042612833, 542101086, 2149253120}};
  s21_decimal y_test = {{1, 0, 0, 2149253120}};
  char res1[1000], res2[1000];
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x.bits[0],
           x.bits[1], x.bits[2], x.bits[3], y.bits[0], y.bits[1], y.bits[2],
           y.bits[3]);
  snprintf(res2, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x_test.bits[0],
           x_test.bits[1], x_test.bits[2], x_test.bits[3], y_test.bits[0],
           y_test.bits[1], y_test.bits[2], y_test.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_equal_7) {
  s21_decimal x = {{10, 0, 100, 0b00000000000000000000000000000000}};
  s21_decimal y = {{5, 0, 1565, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 7);
  s21_setScale(&y, 0);
  s21_scale_equalization(&x, &y, OK);
  s21_decimal x_test = {{1, 0, 10, 393216}};
  s21_decimal y_test = {{5000000, 0, 1565000000, 393216}};
  char res1[1000], res2[1000];
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x.bits[0],
           x.bits[1], x.bits[2], x.bits[3], y.bits[0], y.bits[1], y.bits[2],
           y.bits[3]);
  snprintf(res2, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x_test.bits[0],
           x_test.bits[1], x_test.bits[2], x_test.bits[3], y_test.bits[0],
           y_test.bits[1], y_test.bits[2], y_test.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_equal_8) {
  s21_decimal x = {{10, 0, 3000000000, 0b10000000000000000000000000000000}};
  s21_decimal y = {{13, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 28);
  s21_setScale(&y, 0);
  s21_scale_equalization(&x, &y, OK);
  s21_decimal x_test = {{1, 0, 300000000, 2149253120}};
  s21_decimal y_test = {{3355443200, 496403223, 704731412, 2149253120}};
  char res1[1000], res2[1000];
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x.bits[0],
           x.bits[1], x.bits[2], x.bits[3], y.bits[0], y.bits[1], y.bits[2],
           y.bits[3]);
  snprintf(res2, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x_test.bits[0],
           x_test.bits[1], x_test.bits[2], x_test.bits[3], y_test.bits[0],
           y_test.bits[1], y_test.bits[2], y_test.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

Suite *s21_is_equal_suite(void) {
  Suite *s;
  TCase *ts_core;
  s = suite_create("\033[45m-s21_is_equal-\033[0m");  // создает набор кейсов с
                                                      // заданным именем
  ts_core = tcase_create("case_is_equal");
  tcase_add_test(ts_core, s21_equal_1);
  tcase_add_test(ts_core, s21_equal_2);
  tcase_add_test(ts_core, s21_equal_3);
  tcase_add_test(ts_core, s21_equal_4);
  tcase_add_test(ts_core, s21_equal_5);
  tcase_add_test(ts_core, s21_equal_6);
  tcase_add_test(ts_core, s21_equal_7);
  tcase_add_test(ts_core, s21_equal_8);
  suite_add_tcase(s, ts_core);
  return s;
}