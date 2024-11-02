#include "../common_test.h"

START_TEST(test1) { ck_assert_ldouble_eq_tol(s21_tan(1), tan(1), 1e-6); }
END_TEST

START_TEST(test2) { ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), 1e-6); }
END_TEST

START_TEST(test3) { ck_assert_ldouble_eq_tol(s21_tan(-1), tan(-1), 1e-6); }
END_TEST

START_TEST(test4) {
  ck_assert_ldouble_eq_tol(s21_tan(0.0009), tan(0.0009), 1e-8);
}
END_TEST

START_TEST(test5) {
  ck_assert_ldouble_eq_tol(s21_tan(12345), tan(12345), 1e-6);
}
END_TEST

START_TEST(test6) {
  ck_assert_ldouble_eq_tol(s21_tan(-12345), tan(-12345), 1e-6);
}
END_TEST

START_TEST(test7) {
  ck_assert_ldouble_eq_tol(s21_tan(S21_PI), tan(S21_PI), 1e-6);
}
END_TEST

START_TEST(test8) {
  ck_assert_ldouble_eq_tol(s21_tan(S21_2PI), tan(S21_2PI), 1e-6);
}
END_TEST

START_TEST(test9) {
  ck_assert_ldouble_eq_tol(s21_tan(-0.000009), tan(-0.000009), 1e-6);
}
END_TEST

START_TEST(test10) { ck_assert_int_eq(isnan(s21_tan(S21_NAN)), 1); }
END_TEST

START_TEST(test11) { ck_assert_ldouble_nan(s21_tan(S21_INF)); }
END_TEST

START_TEST(test12) { ck_assert_ldouble_nan(s21_tan(-S21_INF)); }
END_TEST

Suite *s21_tan_suite() {
  Suite *s = suite_create("s21_tan");
  TCase *s21_tan = tcase_create("s21_tan");

  tcase_add_test(s21_tan, test1);
  tcase_add_test(s21_tan, test2);
  tcase_add_test(s21_tan, test3);
  tcase_add_test(s21_tan, test4);
  tcase_add_test(s21_tan, test5);
  tcase_add_test(s21_tan, test6);
  tcase_add_test(s21_tan, test7);
  tcase_add_test(s21_tan, test8);
  tcase_add_test(s21_tan, test9);
  tcase_add_test(s21_tan, test10);
  tcase_add_test(s21_tan, test11);
  tcase_add_test(s21_tan, test12);

  suite_add_tcase(s, s21_tan);

  return s;
}
