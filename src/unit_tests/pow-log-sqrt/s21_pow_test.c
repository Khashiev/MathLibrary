#include "../common_test.h"

START_TEST(pow_test_1) {
  for (double k = -9; k <= 9; k += 1.7) {
    for (double g = -5; g < 5; g += 1.0) {
      long double a = s21_pow(k, g);
      long double b = pow(k, g);
      if ((!S21_ISNAN(a) && !isnan(b)) && !(a == INFINITY && b == INFINITY) &&
          !(a == -INFINITY && b == -INFINITY)) {
        ck_assert_double_eq_tol(a, b, 1e-7);
      }
      a = s21_pow(g, k);
      b = pow(g, k);
      if ((!S21_ISNAN(a) && !isnan(b)) && !(a == S21_INF && b == S21_INF) &&
          !(a == -INFINITY && b == -INFINITY)) {
        ck_assert_double_eq_tol(a, b, 1e-7);
      }
    }
  }
}
END_TEST

START_TEST(pow_test_2) {
  for (double k = -1e-1; k <= 1; k += 1.1e-1) {
    for (double g = -2.55; g < 2; g += 1.1) {
      long double a = s21_pow(k, g);
      long double b = pow(k, g);
      if ((!S21_ISNAN(a) && !isnan(b)) && !(a == INFINITY && b == INFINITY) &&
          !(a == -INFINITY && b == -INFINITY)) {
        ck_assert_double_eq_tol(a, b, 1e-7);
      }
      a = s21_pow(g, k);
      b = pow(g, k);
      if ((!S21_ISNAN(a) && !isnan(b)) && !(a == INFINITY && b == INFINITY) &&
          !(a == -INFINITY && b == -INFINITY)) {
        ck_assert_double_eq_tol(a, b, 1e-7);
      }
    }
  }
}
END_TEST

START_TEST(pow_test_3) {
  ck_assert_double_eq(pow(1, 0), s21_pow(1, 0));
  ck_assert_double_eq(pow(-1, 3), s21_pow(-1, 3));
  ck_assert_double_eq(pow(-1, 4), s21_pow(-1, 4));
  ck_assert_double_eq(pow(0, 0), s21_pow(0, 0));
  ck_assert_double_eq(pow(0, -1), s21_pow(0, -1));
  ck_assert_double_eq(pow(0, 1), s21_pow(0, 1));
  ck_assert_double_eq(pow(INFINITY, 0), s21_pow(S21_INF, 0));
  ck_assert_double_eq(pow(INFINITY, -1), s21_pow(INFINITY, -1));
  ck_assert_double_eq(pow(-1, -INFINITY), s21_pow(-1, -S21_INF));
  ck_assert_double_eq(pow(0, INFINITY), s21_pow(0, S21_INF));
  ck_assert_double_nan(s21_pow(0, S21_NAN));
  ck_assert_double_eq(pow(NAN, 0), s21_pow(S21_NAN, 0));
  ck_assert_double_nan(s21_pow(S21_NAN, S21_NAN));
  ck_assert_double_eq(pow(INFINITY, INFINITY), s21_pow(S21_INF, S21_INF));
  ck_assert_double_eq(pow(INFINITY, -INFINITY), s21_pow(S21_INF, -S21_INF));
  ck_assert_double_eq(pow(-INFINITY, INFINITY), s21_pow(-S21_INF, S21_INF));
  ck_assert_double_eq(pow(-INFINITY, -INFINITY), s21_pow(-S21_INF, -S21_INF));
  ck_assert_double_eq(pow(1, -INFINITY), s21_pow(1, -S21_INF));
  ck_assert_double_eq(pow(1, NAN), s21_pow(1, S21_NAN));
  ck_assert_double_nan(s21_pow(S21_NAN, S21_INF));
  ck_assert_double_nan(s21_pow(S21_INF, S21_NAN));
  ck_assert_double_nan(s21_pow(S21_NAN, -S21_INF));
  ck_assert_double_nan(s21_pow(-S21_INF, S21_NAN));
  ck_assert_double_eq(pow(2, INFINITY), s21_pow(2, S21_INF));
  ck_assert_double_eq(pow(0.5, INFINITY), s21_pow(0.5, S21_INF));
  ck_assert_double_eq(pow(-2, INFINITY), s21_pow(-2, S21_INF));
  ck_assert_double_eq(pow(2, -INFINITY), s21_pow(2, -S21_INF));
  ck_assert_double_eq(pow(0.5, -INFINITY), s21_pow(0.5, -S21_INF));
  ck_assert_double_eq(pow(-2, -INFINITY), s21_pow(-2, -S21_INF));
}
END_TEST

Suite *s21_pow_suite() {
  Suite *suite;

  suite = suite_create("s21_pow");
  TCase *tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, pow_test_1);
  tcase_add_test(tcase_core, pow_test_2);
  tcase_add_test(tcase_core, pow_test_3);

  suite_add_tcase(suite, tcase_core);

  return suite;
}