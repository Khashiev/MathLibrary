#include "../common_test.h"

START_TEST(test1) { ck_assert_ldouble_eq_tol(s21_sin(1), sin(1), 1e-6); }
END_TEST

START_TEST(test2) { ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), 1e-6); }
END_TEST

START_TEST(test3) { ck_assert_ldouble_eq_tol(s21_sin(-1), sin(-1), 1e-6); }
END_TEST

START_TEST(test4) {
  ck_assert_ldouble_eq_tol(s21_sin(0.000009), sin(0.000009), 1e-6);
}
END_TEST

START_TEST(test5) {
  ck_assert_ldouble_eq_tol(s21_sin(12345), sin(12345), 1e-6);
}
END_TEST

START_TEST(test6) {
  ck_assert_ldouble_eq_tol(s21_sin(-12345), sin(-12345), 1e-6);
}
END_TEST

START_TEST(test7) {
  ck_assert_ldouble_eq_tol(s21_sin(S21_PI), sin(S21_PI), 1e-6);
}
END_TEST

START_TEST(test8) {
  ck_assert_ldouble_eq_tol(s21_sin(S21_2PI), sin(S21_2PI), 1e-6);
}
END_TEST

START_TEST(test9) {
  ck_assert_ldouble_eq_tol(s21_sin(S21_PI_2), sin(S21_PI_2), 1e-6);
}
END_TEST

START_TEST(test10) {
  ck_assert_ldouble_eq_tol(s21_sin(-0.000009), sin(-0.000009), 1e-6);
}
END_TEST

START_TEST(test11) { ck_assert_int_eq(isnan(s21_sin(S21_NAN)), 1); }
END_TEST

START_TEST(test12) { ck_assert_ldouble_nan(s21_sin(S21_INF)); }
END_TEST

START_TEST(test13) { ck_assert_ldouble_nan(s21_sin(-S21_INF)); }
END_TEST

Suite *s21_sin_suite() {
  Suite *s = suite_create("s21_sin");
  TCase *s21_sin = tcase_create("s21_sin");

  tcase_add_test(s21_sin, test1);
  tcase_add_test(s21_sin, test2);
  tcase_add_test(s21_sin, test3);
  tcase_add_test(s21_sin, test4);
  tcase_add_test(s21_sin, test5);
  tcase_add_test(s21_sin, test6);
  tcase_add_test(s21_sin, test7);
  tcase_add_test(s21_sin, test8);
  tcase_add_test(s21_sin, test9);
  tcase_add_test(s21_sin, test10);
  tcase_add_test(s21_sin, test11);
  tcase_add_test(s21_sin, test12);
  tcase_add_test(s21_sin, test13);

  suite_add_tcase(s, s21_sin);

  return s;
}
