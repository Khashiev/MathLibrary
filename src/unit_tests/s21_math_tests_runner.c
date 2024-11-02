#include <check.h>

Suite *s21_abs_suite();
Suite *s21_fabs_suite();
Suite *s21_ceil_suite();
Suite *s21_floor_suite();
Suite *s21_fmod_suite();
Suite *s21_pow_suite();
Suite *s21_sqrt_suite();
Suite *s21_exp_suite();
Suite *s21_log_suite();
Suite *s21_sin_suite();
Suite *s21_cos_suite();
Suite *s21_tan_suite();
Suite *s21_asin_suite();
Suite *s21_acos_suite();
Suite *s21_atan_suite();
Suite *s21_factorial_suite();

int main() {
  int result = 0;
  SRunner *runner = srunner_create(suite_create("s21_math"));
#ifdef S21_NOFORK
  srunner_set_fork_status(runner, CK_NOFORK);
#endif
  srunner_add_suite(runner, s21_abs_suite());
  srunner_add_suite(runner, s21_fabs_suite());
  srunner_add_suite(runner, s21_ceil_suite());
  srunner_add_suite(runner, s21_floor_suite());
  srunner_add_suite(runner, s21_fmod_suite());
  srunner_add_suite(runner, s21_pow_suite());
  srunner_add_suite(runner, s21_sqrt_suite());
  srunner_add_suite(runner, s21_exp_suite());
  srunner_add_suite(runner, s21_log_suite());
  srunner_add_suite(runner, s21_sin_suite());
  srunner_add_suite(runner, s21_cos_suite());
  srunner_add_suite(runner, s21_tan_suite());
  srunner_add_suite(runner, s21_asin_suite());
  srunner_add_suite(runner, s21_acos_suite());
  srunner_add_suite(runner, s21_atan_suite());

  srunner_run_all(runner, CK_NORMAL);

  result = srunner_ntests_failed(runner) > 0;
  srunner_free(runner);
  return result;
}
