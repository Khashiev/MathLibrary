#include "../common_test.h"

START_TEST(log_test_1) {
  for (double k = 1; k < 100; k += 13.2) {
    double a = s21_log(k);
    double b = log(k);
    ck_assert_double_eq_tol(a, b, 1e-7);
  }
}
END_TEST

START_TEST(log_test_2) {
  for (double k = 0.1; k < 4; k += 0.24) {
    double a = s21_log(k);
    double b = log(k);
    ck_assert_double_eq_tol(a, b, 1e-7);
  }
}
END_TEST

START_TEST(log_test_3) {
  for (double k = 0.1; k < 10000; k += 123) {
    double a = s21_log(k);
    double b = log(k);
    ck_assert_double_eq_tol(a, b, 1e-7);
  }
}
END_TEST

START_TEST(log_test_4) {
  for (double k = 0.000005; k < 1; k *= 5) {
    double a = s21_log(k);
    double b = log(k);
    ck_assert_double_eq_tol(a, b, 1e-7);
  }
}
END_TEST

START_TEST(log_test_5) {
  ck_assert_ldouble_nan(s21_log(S21_NAN));
  ck_assert_double_eq(log(0), s21_log(0));
  ck_assert_double_nan(s21_log(-3));
  ck_assert_double_eq(log(INFINITY), s21_log(S21_INF));
  ck_assert_double_nan(s21_log(-S21_INF));
  ck_assert_double_eq(log(1), s21_log(1));
  ck_assert_double_eq(log(S21_M_E), s21_log(S21_M_E));
  ck_assert_double_eq_tol(log(2), s21_log(2), 1e-7);
}
END_TEST

Suite *s21_log_suite() {
  Suite *suite;

  suite = suite_create("s21_log");
  TCase *tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, log_test_1);
  tcase_add_test(tcase_core, log_test_2);
  tcase_add_test(tcase_core, log_test_3);
  tcase_add_test(tcase_core, log_test_4);
  tcase_add_test(tcase_core, log_test_5);

  suite_add_tcase(suite, tcase_core);

  return suite;
}