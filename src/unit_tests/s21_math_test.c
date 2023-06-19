#include "s21_math_test.h"

int main(void) {
  Suite *list_cases[] = {suite_fabs(), suite_floor(), suite_fmod(), NULL};

  for (Suite **cur_case = list_cases; *cur_case != NULL; cur_case++) {
    SRunner *sr = srunner_create(*cur_case);
    srunner_run_all(sr, CK_VERBOSE);
    srunner_free(sr);
  }

  return 0;
}
