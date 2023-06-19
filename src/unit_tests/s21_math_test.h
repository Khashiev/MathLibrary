#ifndef SRC_S21_MATH_TEST_H_
#define SRC_S21_MATH_TEST_H_

#include <check.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_math.h"

Suite *suite_fabs(void);
Suite *suite_floor(void);
Suite *suite_fmod(void);

#endif  //  SRC_S21_MATH_TEST_H_