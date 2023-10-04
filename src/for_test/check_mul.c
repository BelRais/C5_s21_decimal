#include "check_main.h"

START_TEST(s21_mul_1) {
  s21_decimal x = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_mul_2) {
  s21_decimal x = {{2, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{5, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char res1[1000], res2[1000] = "10 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_mul_3) {
  s21_decimal x = {{2, 1, 2, 0b00000000000000000000000000000000}};
  s21_decimal y = {{5, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char res1[1000], res2[1000] = "10 5 10 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_mul_4) {
  s21_decimal x = {{2, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 10, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char res1[1000], res2[1000] = "0 0 20 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_mul_5) {
  s21_decimal x = {{1000000000, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{6, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char res1[1000], res2[1000] = "1705032704 1 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_mul_6) {
  s21_decimal x = {{1000000000, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal y = {{6, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char res1[1000], res2[1000] = "1705032704 1 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_mul_7) {
  s21_decimal x = {{1000000000, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal y = {{6, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char res1[1000], res2[1000] = "1705032704 1 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_mul_8) {
  s21_decimal x = {{1000000000, 0, 0, 0b00000000000011110000000000000000}};
  s21_decimal y = {{6, 0, 0, 0b10000000000000010000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char res1[1000], res2[1000] = "1705032704 1 0 2148532224";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_mul_9) {
  s21_decimal x = {{1, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{165, 22, 6587456, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char res1[1000], res2[1000] = "165 22 6587456 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_mul_10) {
  s21_decimal x = {{400, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{500, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 14);
  s21_setScale(&y, 14);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char res1[1000], res2[1000] = "200000 0 0 1835008";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_mul_11) {
  s21_decimal x = {{400, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{500, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 17);
  s21_setScale(&y, 18);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_mul_12) {
  s21_decimal x = {{400, 0, 5000000, 0b00000000000000000000000000000000}};
  s21_decimal y = {{500, 0, 5000000, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 12);
  s21_setScale(&y, 12);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_mul_13) {
  s21_decimal src1, src2;
  int a = 9403;
  int b = 202;
  int res_our_dec = 0;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  int res_origin = 1899406;
  s21_decimal res_od;
  s21_mul(src1, src2, &res_od);
  s21_from_decimal_to_int(res_od, &res_our_dec);
  ck_assert_int_eq(res_our_dec, res_origin);
}
END_TEST

Suite *s21_mul_suite(void) {
  Suite *s;
  TCase *ts_core;
  s = suite_create(
      "\033[45m-s21_mul-\033[0m");  // создает набор кейсов с заданным именем
  ts_core = tcase_create("case_mul");
  tcase_add_test(ts_core, s21_mul_1);
  tcase_add_test(ts_core, s21_mul_2);
  tcase_add_test(ts_core, s21_mul_3);
  tcase_add_test(ts_core, s21_mul_4);
  tcase_add_test(ts_core, s21_mul_5);
  tcase_add_test(ts_core, s21_mul_6);
  tcase_add_test(ts_core, s21_mul_7);
  tcase_add_test(ts_core, s21_mul_8);
  tcase_add_test(ts_core, s21_mul_9);
  tcase_add_test(ts_core, s21_mul_10);
  tcase_add_test(ts_core, s21_mul_11);
  tcase_add_test(ts_core, s21_mul_12);
  tcase_add_test(ts_core, s21_mul_13);

  suite_add_tcase(s, ts_core);
  return s;
}