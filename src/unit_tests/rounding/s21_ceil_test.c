#include "../common_test.h"

START_TEST(s21_ceil_test) {
  double a = -985554678.842562;
  ck_assert_ldouble_eq(s21_ceil(a), ceil(a));

  double a2 = 175436.98046;
  ck_assert_ldouble_eq(s21_ceil(a2), ceil(a2));

  double a3 = 0.0;
  ck_assert_ldouble_eq(s21_ceil(a3), ceil(a3));

  double a4 = 7234567895472489.0;
  ck_assert_ldouble_eq(s21_ceil(a4), ceil(a4));

  double a5 = 1234567898.1234560;
  ck_assert_ldouble_eq(s21_ceil(a5), ceil(a5));

  double a6 = 0.875421;
  ck_assert_ldouble_eq(s21_ceil(a6), ceil(a6));

  double a7 = 17542186432.87426;
  ck_assert_ldouble_eq(s21_ceil(a7), ceil(a7));

  double a8 = S21_INF;
  ck_assert(isinf(s21_ceil(a8)));

  double a9 = S21_NAN;
  ck_assert_ldouble_nan(s21_ceil(a9));
}

Suite *s21_ceil_suite() {
  Suite *s = suite_create("s21_ceil");
  TCase *s21_ceil = tcase_create("s21_ceil");

  tcase_add_test(s21_ceil, s21_ceil_test);
  suite_add_tcase(s, s21_ceil);

  return s;
}
