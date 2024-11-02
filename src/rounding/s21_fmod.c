#include "../s21_math.h"

long double s21_fmod(double x, double y) {
  long double res;

  if (y == 0 || S21_ISINF(x))
    res = S21_NAN;
  else if (x == 0 || S21_ISINF(y)) {
    res = x;
  } else {
    int tmp = x / y;
    res = x - y * tmp;
  }

  return res;
}
