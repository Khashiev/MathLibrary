#include "../common_test.h"

START_TEST(s21_acos_test) {
  long double precision = 1e-7;

  double a = -985554678.842562;
  ck_assert_ldouble_nan(s21_acos(a));

  double a2 = 175436.98046;
  ck_assert_ldouble_nan(s21_acos(a2));

  double a3 = 0.0;
  ck_assert_ldouble_eq(s21_acos(a3), acos(a3));

  double a4 = 1.0;
  ck_assert_ldouble_eq(s21_acos(a4), acos(a4));

  double a5 = -0.8765432;
  ck_assert_ldouble_eq_tol(s21_acos(a5), acos(a5), precision);

  double a6 = 0.875421;
  ck_assert_ldouble_eq_tol(s21_acos(a6), acos(a6), precision);

  double a7 = 17542186432.87426;
  ck_assert_ldouble_nan(s21_acos(a7));

  double a8 = 0.10001;
  ck_assert_ldouble_eq_tol(s21_acos(a8), acos(a8), precision);
}
END_TEST

START_TEST(test1) { ck_assert_ldouble_nan(s21_acos(-2.0)); }
END_TEST

START_TEST(test2) { ck_assert_ldouble_eq(s21_acos(-1.0), acos(-1.0)); }
END_TEST

START_TEST(test3) {
  ck_assert_ldouble_eq_tol(s21_acos(-0.5), acos(-0.5), 1e-7);
}
END_TEST

START_TEST(test4) { ck_assert_ldouble_eq(s21_acos(0.0), acos(0.0)); }
END_TEST

START_TEST(test5) { ck_assert_ldouble_eq_tol(s21_acos(0.5), acos(0.5), 1e-7); }
END_TEST

START_TEST(test6) { ck_assert_ldouble_eq(s21_acos(1.0), acos(1.0)); }
END_TEST

START_TEST(test7) { ck_assert_ldouble_nan(s21_acos(2.0)); }
END_TEST

Suite *s21_acos_suite() {
  Suite *s = suite_create("s21_acos");
  TCase *s21_acos = tcase_create("s21_acos");

  tcase_add_test(s21_acos, s21_acos_test);
  tcase_add_test(s21_acos, test1);
  tcase_add_test(s21_acos, test2);
  tcase_add_test(s21_acos, test3);
  tcase_add_test(s21_acos, test4);
  tcase_add_test(s21_acos, test5);
  tcase_add_test(s21_acos, test6);
  tcase_add_test(s21_acos, test7);

  suite_add_tcase(s, s21_acos);

  return s;
}
