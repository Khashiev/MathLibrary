#include "../common_test.h"

START_TEST(s21_asin_test) {
  long double precision = 1e-7;

  double a = -985554678.842562;
  ck_assert_ldouble_nan(s21_asin(a));

  double a2 = 175436.98046;
  ck_assert_ldouble_nan(s21_asin(a2));

  double a3 = 0.0;
  ck_assert_ldouble_eq(s21_asin(a3), asin(a3));

  double a4 = 0.7234567895472489;
  ck_assert_ldouble_eq_tol(s21_asin(a4), asin(a4), precision);

  double a5 = -0.1234560;
  ck_assert_ldouble_eq_tol(s21_asin(a5), asin(a5), precision);

  double a6 = 0.875421;
  ck_assert_ldouble_eq_tol(s21_asin(a6), asin(a6), precision);

  double a7 = 17542186432.87426;
  ck_assert_ldouble_nan(s21_asin(a7));

  double a8 = 0.10001;
  ck_assert_ldouble_eq_tol(s21_asin(a8), asin(a8), precision);
}
END_TEST

START_TEST(test1) { ck_assert_ldouble_nan(s21_asin(-2.0)); }
END_TEST

START_TEST(test2) {
  ck_assert_ldouble_eq_tol(s21_asin(-1.0), asin(-1.0), 1e-7);
}
END_TEST

START_TEST(test3) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.5), asin(-0.5), 1e-7);
}
END_TEST

START_TEST(test4) { ck_assert_ldouble_eq_tol(s21_asin(0.0), asin(0.0), 1e-7); }
END_TEST

START_TEST(test5) { ck_assert_ldouble_eq_tol(s21_asin(0.5), asin(0.5), 1e-7); }
END_TEST

START_TEST(test6) { ck_assert_ldouble_eq_tol(s21_asin(1.0), asin(1.0), 1e-7); }
END_TEST

START_TEST(test7) { ck_assert_ldouble_nan(s21_asin(2.0)); }
END_TEST

Suite *s21_asin_suite() {
  Suite *s = suite_create("s21_asin");
  TCase *s21_asin = tcase_create("s21_asin");

  tcase_add_test(s21_asin, s21_asin_test);
  tcase_add_test(s21_asin, test1);
  tcase_add_test(s21_asin, test2);
  tcase_add_test(s21_asin, test3);
  tcase_add_test(s21_asin, test4);
  tcase_add_test(s21_asin, test5);
  tcase_add_test(s21_asin, test6);
  tcase_add_test(s21_asin, test7);

  suite_add_tcase(s, s21_asin);

  return s;
}
