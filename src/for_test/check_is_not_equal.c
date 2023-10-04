#include "check_main.h"

START_TEST(s21_not_equal_1) {
  s21_decimal x = {{0, 0, 1, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b00000000000000000000000000000000}};
  int res1 = s21_is_not_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_not_equal_2) {
  s21_decimal x = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b10000000000000000000000000000000}};
  int res1 = s21_is_not_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_not_equal_3) {
  s21_decimal x = {{0, 0, 1, 0b0000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b10000000000000000000000000000000}};
  int res1 = s21_is_not_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_not_equal_4) {
  s21_decimal x = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b00000000000000000000000000000000}};
  int res1 = s21_is_not_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_not_equal_5) {
  s21_decimal x = {{0, 52, 1, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b00000000000000000000000000000000}};
  int res1 = s21_is_not_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_not_equal_6) {
  s21_decimal x = {{0, 0, 1, 0b00000000000000000000000000000000}};
  s21_decimal y = {{1747, 0, 1, 0b00000000000000000000000000000000}};
  int res1 = s21_is_not_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_not_equal_7) {
  s21_decimal x = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_decimal y = {{1747, 0, 1, 0b00000000000000000000000000000000}};
  int res1 = s21_is_not_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_is_not_equal_suite(void) {
  Suite *s;
  TCase *ts_core;
  s = suite_create(
      "\033[45m-s21_is_not_equal-\033[0m");  // создает набор кейсов с заданным
                                             // именем
  ts_core = tcase_create("case_is_not_equal");
  tcase_add_test(ts_core, s21_not_equal_1);
  tcase_add_test(ts_core, s21_not_equal_2);
  tcase_add_test(ts_core, s21_not_equal_3);
  tcase_add_test(ts_core, s21_not_equal_4);
  tcase_add_test(ts_core, s21_not_equal_5);
  tcase_add_test(ts_core, s21_not_equal_6);
  tcase_add_test(ts_core, s21_not_equal_7);

  suite_add_tcase(s, ts_core);
  return s;
}