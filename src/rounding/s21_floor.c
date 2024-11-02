#include "../s21_math.h"

long double s21_floor(double x) {
  long double res;

  if (x == 0 || S21_ISINF(x) || S21_ISNAN(x)) {
    res = x;
  } else {
    long long int tmp = x;

    res = (x < 0 && x != tmp) ? tmp - 1 : tmp;
  }

  return res;
}