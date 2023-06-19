#include "s21_math.h"

long double s21_floor(double x) {
  long double res;

  if (x == 0 || s21_is_inf(x) || s21_is_nan(x)) {
    res = x;
  } else {
    long long int tmp = x;

    res = (x < 0 && x != tmp) ? tmp - 1 : tmp;
  }

  return res;
}