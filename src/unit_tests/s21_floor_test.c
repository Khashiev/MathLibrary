#include "s21_math_test.h"

START_TEST(floor_test1) {
  double x = 1.0;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 6);
}
END_TEST

START_TEST(floor_test2) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 6);
}
END_TEST

START_TEST(floor_test3) {
  double x = -0.0;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 6);
}
END_TEST

START_TEST(floor_test4) {
  double x = S21_INF;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(floor_test5) {
  double x = -S21_INF;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(floor_test6) {
  double x = NAN;
  ck_assert_ldouble_nan(s21_floor(x));
}
END_TEST

START_TEST(floor_test7) {
  double x = -4.7;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 6);
}
END_TEST

START_TEST(floor_test8) {
  double x = 4.7323234567890765;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 6);
}
END_TEST

START_TEST(floor_test9) {
  double x = 4732323456789076.5;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 6);
}
END_TEST

START_TEST(floor_test10) {
  double x = -4.7323234567890765;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 6);
}
END_TEST

Suite *suite_floor(void) {
  Suite *s = suite_create("suite_floor");
  TCase *tc = tcase_create("floor_tc");

  tcase_add_test(tc, floor_test1);
  tcase_add_test(tc, floor_test2);
  tcase_add_test(tc, floor_test3);
  tcase_add_test(tc, floor_test4);
  tcase_add_test(tc, floor_test5);
  tcase_add_test(tc, floor_test6);
  tcase_add_test(tc, floor_test7);
  tcase_add_test(tc, floor_test8);
  tcase_add_test(tc, floor_test9);
  tcase_add_test(tc, floor_test10);
  suite_add_tcase(s, tc);
  return s;
}