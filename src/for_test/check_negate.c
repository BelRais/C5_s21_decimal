#include "check_main.h"

START_TEST(s21_negate_1) {
  int a = 15;
  int res_a = 0;
  s21_decimal src;
  s21_decimal res;
  s21_from_int_to_decimal(a, &src);
  s21_negate(src, &res);
  s21_from_decimal_to_int(res, &res_a);
  ck_assert_int_eq(-15, res_a);
}
END_TEST

START_TEST(s21_negate_2) {
  float a = 10.12345;
  float res_a = 0;
  s21_decimal src;
  s21_decimal res;
  s21_from_float_to_decimal(a, &src);
  s21_negate(src, &res);
  s21_from_decimal_to_float(res, &res_a);
  ck_assert_float_eq(-10.12345, res_a);
}
END_TEST

START_TEST(s21_negate_3) {
  float a = 10.1234e5;
  float res_a = 0;
  s21_decimal src;
  s21_decimal res;
  s21_from_float_to_decimal(a, &src);
  s21_negate(src, &res);
  s21_from_decimal_to_float(res, &res_a);
  ck_assert_float_eq(-10.1234e5, res_a);
}
END_TEST

START_TEST(s21_negate_4) {
  float a = -10.1234e5;
  float res_a = 0;
  s21_decimal src;
  s21_decimal res;
  s21_from_float_to_decimal(a, &src);
  s21_negate(src, &res);
  s21_from_decimal_to_float(res, &res_a);
  ck_assert_float_eq(10.1234e5, res_a);
}
END_TEST

START_TEST(s21_negate_5) {
  int a = -15;
  int res_a = 0;
  s21_decimal src;
  s21_decimal res;
  s21_from_int_to_decimal(a, &src);
  s21_negate(src, &res);
  s21_from_decimal_to_int(res, &res_a);
  ck_assert_int_eq(15, res_a);
}
END_TEST

START_TEST(s21_negate_6) {  // 0 * -1 = 0
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal etalon = {{0, 0, 0, ~(INT_MAX)}};
  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  // int equal = s21_is_equal(b, etalon);
  int negate = s21_negate(b, &etalon);
  ck_assert_int_eq(negate, 0);
}
END_TEST

START_TEST(s21_negate_7) {  // 1 * -1 = -1
  s21_decimal a = {{1, 0, 0, 0}};
  s21_decimal etalon = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_negate_8) {  // -1 * -1 = 1
  s21_decimal a = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal etalon = {{1, 0, 0, 0}};

  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_negate_9) {  // 100 * -1 = -100
  s21_decimal a = {{100, 0, 0, 0}};
  s21_decimal etalon = {{100, 0, 0, ~(INT_MAX)}};
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_negate_10) {  //
  s21_decimal a = {{100, 0, 0, ~(INT_MAX)}};
  s21_decimal etalon = {{100, 0, 0, 0}};

  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_negate_11) {  //
  s21_decimal a = {{S21_MAX_UINT, 0, 0, 0}};
  s21_decimal etalon = {{S21_MAX_UINT, 0, 0, ~(INT_MAX)}};

  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_negate_12) {  //
  s21_decimal a = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}};
  s21_decimal etalon = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}};

  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 0);
}
END_TEST

START_TEST(s21_negate_13) {  //
  s21_decimal a = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}};
  s21_decimal etalon = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, ~(INT_MAX)}};

  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_negate_14) {  //
  s21_decimal a = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, ~(INT_MAX)}};
  s21_decimal etalon = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}};

  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_negate_15) {
  s21_decimal val = {{2, 0, 0, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

START_TEST(s21_negate_16) {
  s21_decimal val = {{2, 0, 0, ~(S21_MAX_UINT / 2)}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

START_TEST(s21_negate_17) {
  s21_decimal val = {{0, 0, 0, ~(S21_MAX_UINT / 2)}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

START_TEST(s21_negate_18) {
  s21_decimal val = {0};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

START_TEST(s21_negate_19) {
  s21_decimal val = {{2, 0, 0, 0}};
  s21_decimal res = {0};
  int sign_before = s21_getSign(val);
  s21_negate(val, &res);
  int sign_after = s21_getSign(res);

  ck_assert_int_ne(sign_before, sign_after);
}
END_TEST

START_TEST(s21_negate_20) {
  s21_decimal val = {{2, 0, 0, ~(S21_MAX_UINT / 2)}};
  s21_decimal res = {0};
  int sign_before = s21_getSign(val);
  s21_negate(val, &res);
  int sign_after = s21_getSign(res);
  ck_assert_int_ne(sign_before, sign_after);
}
END_TEST

START_TEST(s21_negate_21) {
  s21_decimal val = {{0, 0, 0, ~(S21_MAX_UINT / 2)}};
  s21_decimal res = {0};
  int sign_before = s21_getSign(val);
  s21_negate(val, &res);
  int sign_after = s21_getSign(res);
  ck_assert_int_ne(sign_before, sign_after);
}
END_TEST

START_TEST(s21_negate_22) {
  s21_decimal val = {0};
  s21_decimal res = {0};
  int sign_before = s21_getSign(val);
  s21_negate(val, &res);
  int sign_after = s21_getSign(res);
  ck_assert_int_ne(sign_before, sign_after);
}
END_TEST

Suite* s21_negate_suite(void) {
  Suite* s;
  TCase* ts_core;
  s = suite_create(
      "\033[45m-s21_negate-\033[0m");  // создает набор кейсов с заданным именем
  ts_core = tcase_create("case_negate");
  tcase_add_test(ts_core, s21_negate_1);
  tcase_add_test(ts_core, s21_negate_2);
  tcase_add_test(ts_core, s21_negate_3);
  tcase_add_test(ts_core, s21_negate_4);
  tcase_add_test(ts_core, s21_negate_5);
  tcase_add_test(ts_core, s21_negate_6);
  tcase_add_test(ts_core, s21_negate_7);
  tcase_add_test(ts_core, s21_negate_8);
  tcase_add_test(ts_core, s21_negate_9);
  tcase_add_test(ts_core, s21_negate_10);
  tcase_add_test(ts_core, s21_negate_11);
  tcase_add_test(ts_core, s21_negate_12);
  tcase_add_test(ts_core, s21_negate_13);
  tcase_add_test(ts_core, s21_negate_14);
  tcase_add_test(ts_core, s21_negate_15);
  tcase_add_test(ts_core, s21_negate_16);
  tcase_add_test(ts_core, s21_negate_17);
  tcase_add_test(ts_core, s21_negate_18);
  tcase_add_test(ts_core, s21_negate_19);
  tcase_add_test(ts_core, s21_negate_20);
  tcase_add_test(ts_core, s21_negate_21);
  tcase_add_test(ts_core, s21_negate_22);

  suite_add_tcase(s, ts_core);
  return s;
}