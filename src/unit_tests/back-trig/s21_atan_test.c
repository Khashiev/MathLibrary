#include "../common_test.h"

START_TEST(s21_atan_test) {
  long double precision = 1e-7;

  double a = -985554678.842562;
  ck_assert_ldouble_eq_tol(s21_atan(a), atan(a), precision);

  double a2 = 175436.98046;
  ck_assert_ldouble_eq_tol(s21_atan(a2), atan(a2), precision);

  double a3 = 0.0;
  ck_assert_ldouble_eq(s21_atan(a3), atan(a3));

  double a4 = 7234567895472489.0;
  ck_assert_ldouble_eq_tol(s21_atan(a4), atan(a4), precision);

  double a5 = 1234567898.1234560;
  ck_assert_ldouble_eq_tol(s21_atan(a5), atan(a5), precision);

  double a6 = 0.875421;
  ck_assert_ldouble_eq_tol(s21_atan(a6), atan(a6), precision);

  double a7 = 17542186432.87426;
  ck_assert_ldouble_eq_tol(s21_atan(a7), atan(a7), precision);

  double a8 = 0.10001;
  ck_assert_ldouble_eq_tol(s21_atan(a8), atan(a8), precision);
}
END_TEST

Suite *s21_atan_suite() {
  Suite *s = suite_create("s21_atan");
  TCase *s21_atan = tcase_create("s21_atan");

  tcase_add_test(s21_atan, s21_atan_test);
  suite_add_tcase(s, s21_atan);

  return s;
}
