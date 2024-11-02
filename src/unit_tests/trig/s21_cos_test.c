#include "../common_test.h"

START_TEST(test1) { ck_assert_ldouble_eq_tol(s21_cos(1), cos(1), 1e-6); }
END_TEST

START_TEST(test2) { ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-6); }
END_TEST

START_TEST(test3) { ck_assert_ldouble_eq_tol(s21_cos(-1), cos(-1), 1e-6); }
END_TEST

START_TEST(test4) {
  ck_assert_ldouble_eq_tol(s21_cos(S21_PI), cos(S21_PI), 1e-6);
}
END_TEST

START_TEST(test5) {
  ck_assert_ldouble_eq_tol(s21_cos(S21_2PI), cos(S21_2PI), 1e-6);
}
END_TEST

START_TEST(test6) {
  ck_assert_ldouble_eq_tol(s21_cos(S21_PI_2), cos(S21_PI_2), 1e-6);
}
END_TEST

START_TEST(test7) {
  ck_assert_ldouble_eq_tol(s21_cos(12345), cos(12345), 1e-6);
}
END_TEST

START_TEST(test8) {
  ck_assert_ldouble_eq_tol(s21_cos(-12345), cos(-12345), 1e-6);
}
END_TEST

START_TEST(test9) {
  ck_assert_ldouble_eq_tol(s21_cos(0.000009), cos(0.000009), 1e-6);
}
END_TEST

START_TEST(test10) {
  ck_assert_ldouble_eq_tol(s21_cos(-0.000009), cos(-0.000009), 1e-6);
}
END_TEST

START_TEST(test11) { ck_assert_int_eq(isnan(s21_cos(S21_NAN)), 1); }
END_TEST

START_TEST(test12) { ck_assert_ldouble_nan(s21_cos(S21_INF)); }
END_TEST

START_TEST(test13) { ck_assert_ldouble_nan(s21_cos(-S21_INF)); }
END_TEST

Suite *s21_cos_suite() {
  Suite *s = suite_create("s21_cos");
  TCase *s21_cos = tcase_create("s21_cos");

  tcase_add_test(s21_cos, test1);
  tcase_add_test(s21_cos, test2);
  tcase_add_test(s21_cos, test3);
  tcase_add_test(s21_cos, test4);
  tcase_add_test(s21_cos, test5);
  tcase_add_test(s21_cos, test6);
  tcase_add_test(s21_cos, test7);
  tcase_add_test(s21_cos, test8);
  tcase_add_test(s21_cos, test9);
  tcase_add_test(s21_cos, test10);
  tcase_add_test(s21_cos, test11);
  tcase_add_test(s21_cos, test12);
  tcase_add_test(s21_cos, test13);

  suite_add_tcase(s, s21_cos);

  return s;
}
