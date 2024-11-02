#include "../common_test.h"

START_TEST(exp_test_1) {
  for (double k = -18; k < 18; k += 1) {
    double a = s21_exp(k);
    double b = exp(k);
    ck_assert_double_eq_tol(a, b, 1e-07);
  }
}
END_TEST

START_TEST(exp_test_2) {
  for (double k = -15; k < 15; k += 0.123) {
    double a = s21_exp(k);
    double b = exp(k);
    ck_assert_double_eq_tol(a, b, 1e-7);
  }
}
END_TEST

START_TEST(exp_test_3) {
  for (double k = -5; k < 5; k += 0.00573) {
    double a = s21_exp(k);
    double b = exp(k);
    ck_assert_double_eq_tol(a, b, 1e-7);
  }
}
END_TEST

START_TEST(exp_test_4) {
  ck_assert_double_nan(s21_exp(S21_NAN));
  ck_assert_double_eq(exp(INFINITY), s21_exp(S21_INF));
  ck_assert_double_eq(exp(-INFINITY), s21_exp(-S21_INF));
  ck_assert_double_eq(exp(0), s21_exp(0));
  ck_assert_double_eq_tol(exp(1), s21_exp(1), 1e-7);
}
END_TEST

Suite *s21_exp_suite() {
  Suite *suite;

  suite = suite_create("s21_exp");
  TCase *tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, exp_test_1);
  tcase_add_test(tcase_core, exp_test_2);
  tcase_add_test(tcase_core, exp_test_3);
  tcase_add_test(tcase_core, exp_test_4);

  suite_add_tcase(suite, tcase_core);

  return suite;
}