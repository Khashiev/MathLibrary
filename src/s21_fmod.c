#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double res;

  if (y == 0 || s21_is_inf(x))
    res = S21_NAN;
  else if (x == 0 || s21_is_inf(y)) {
    res = x;
  } else {
    int tmp = x / y;
    res = x - y * tmp;
  }

  return res;
}
