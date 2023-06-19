#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdio.h>

#define S21_NAN __builtin_nan("")
#define S21_INF __builtin_inf()
#define s21_is_inf __builtin_isinf
#define s21_is_nan __builtin_isnan

long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);

#endif  // SRC_S21_MATH_H_