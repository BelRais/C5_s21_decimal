#include "check_main.h"

START_TEST(dec_to_int_1) {
  s21_decimal x = {{150, 0, 0}};
  int y;
  s21_from_decimal_to_int(x, &y);
  ck_assert_int_eq(y, 150);
}
END_TEST

START_TEST(dec_to_int_2) {
  s21_decimal x = {{12, 0, 0, 13653}};
  int y;
  s21_from_decimal_to_int(x, &y);
  ck_assert_int_eq(y, 12);
}
END_TEST

START_TEST(dec_to_int_3) {
  s21_decimal x = {{123554, 0, 0, 0}};
  int y;
  s21_from_decimal_to_int(x, &y);
  ck_assert_int_eq(y, 123554);
}
END_TEST

START_TEST(dec_to_int_4) {
  s21_decimal x = {{2100000000, 0, 0, 0}};
  int y;
  s21_from_decimal_to_int(x, &y);
  ck_assert_int_eq(y, 2100000000);
}
END_TEST

START_TEST(dec_to_int_5) {
  s21_decimal x = {{2100000000, 0, 0, 0}};
  int y;
  s21_from_decimal_to_int(x, &y);
  ck_assert_int_eq(y, 2100000000);
}
END_TEST

START_TEST(dec_to_int_6) {
  s21_decimal x = {{4234234, 0, 0, 0}};
  int y;
  s21_from_decimal_to_int(x, &y);
  ck_assert_int_eq(y, 4234234);
}
END_TEST

START_TEST(dec_to_int_7) {
  s21_decimal x = {{1231231, 0, 0, 0}};
  int y;
  s21_from_decimal_to_int(x, &y);
  ck_assert_int_eq(y, 1231231);
}
END_TEST

START_TEST(dec_to_int_8) {
  s21_decimal x = {{9, 0, 0, 0}};
  int y;
  s21_from_decimal_to_int(x, &y);
  ck_assert_int_eq(y, 9);
}
END_TEST

Suite *s21_is_dec_to_int(void) {
  Suite *s = suite_create(
      "\033[45m-s21_is_dec_to_int-\033[0m");  // создает набор кейсов с заданным
                                              // именем
  TCase *tc1_1 = tcase_create("case_is_equal");
  tcase_add_test(tc1_1, dec_to_int_1);
  tcase_add_test(tc1_1, dec_to_int_2);
  tcase_add_test(tc1_1, dec_to_int_3);
  tcase_add_test(tc1_1, dec_to_int_4);
  tcase_add_test(tc1_1, dec_to_int_5);
  tcase_add_test(tc1_1, dec_to_int_6);
  tcase_add_test(tc1_1, dec_to_int_7);
  tcase_add_test(tc1_1, dec_to_int_8);

  suite_add_tcase(s, tc1_1);
  return s;
}
