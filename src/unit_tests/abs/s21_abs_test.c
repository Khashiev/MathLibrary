#include "../common_test.h"

START_TEST(test1) { ck_assert_ldouble_eq(s21_abs(1), abs(1)); }
END_TEST

START_TEST(test2) { ck_assert_ldouble_eq(s21_abs(-1), abs(-1)); }
END_TEST

START_TEST(test3) { ck_assert_ldouble_eq(s21_abs(0), abs(0)); }
END_TEST

START_TEST(test4) { ck_assert_ldouble_eq(s21_abs(-10), abs(-10)); }
END_TEST

START_TEST(test5) { ck_assert_ldouble_eq(s21_abs(100), abs(100)); }
END_TEST

START_TEST(test6) { ck_assert_ldouble_eq(s21_abs(-100), abs(-100)); }
END_TEST

START_TEST(test7) { ck_assert_ldouble_eq(s21_abs(123456789), abs(123456789)); }
END_TEST

START_TEST(test8) { ck_assert_ldouble_eq(s21_abs(125), abs(125)); }
END_TEST

START_TEST(test9) { ck_assert_ldouble_eq(s21_abs(-125), abs(-125)); }
END_TEST

START_TEST(test10) {
  ck_assert_ldouble_eq(s21_abs(-123456789), abs(-123456789));
}
END_TEST

Suite *s21_abs_suite() {
  Suite *s = suite_create("s21_abs");
  TCase *s21_abs = tcase_create("s21_abs");

  tcase_add_test(s21_abs, test1);
  tcase_add_test(s21_abs, test2);
  tcase_add_test(s21_abs, test3);
  tcase_add_test(s21_abs, test4);
  tcase_add_test(s21_abs, test5);
  tcase_add_test(s21_abs, test6);
  tcase_add_test(s21_abs, test7);
  tcase_add_test(s21_abs, test8);
  tcase_add_test(s21_abs, test9);
  tcase_add_test(s21_abs, test10);

  suite_add_tcase(s, s21_abs);

  return s;
}
