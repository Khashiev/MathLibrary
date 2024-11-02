#include "../common_test.h"

START_TEST(s21_sqrt_test) {
  double a = -985554678.842562;
  long double result = S21_ISNAN(s21_sqrt(a));
  long double expected = isnan(sqrt(a));
  ck_assert_ldouble_eq(result, expected);

  double a2 = 175436.98046;
  ck_assert_ldouble_eq_tol(s21_sqrt(a2), sqrt(a2), 1e-7);

  double a3 = 0.0;
  ck_assert_ldouble_eq(s21_sqrt(a3), sqrt(a3));

  double a4 = 7234567895472489.0;
  ck_assert_ldouble_eq_tol(s21_sqrt(a4), sqrt(a4), 1e-7);

  double a5 = 1234567898.1234560;
  ck_assert_ldouble_eq_tol(s21_sqrt(a5), sqrt(a5), 1e-7);

  double a6 = 0.875421;
  ck_assert_ldouble_eq_tol(s21_sqrt(a6), sqrt(a6), 1e-7);

  double a7 = 17542186432.87426;
  ck_assert_ldouble_eq_tol(s21_sqrt(a7), sqrt(a7), 1e-7);
}

Suite *s21_sqrt_suite() {
  Suite *s = suite_create("s21_sqrt");
  TCase *s21_sqrt = tcase_create("s21_sqrt");

  tcase_add_test(s21_sqrt, s21_sqrt_test);
  suite_add_tcase(s, s21_sqrt);

  return s;
}
