#include "../s21_math.h"

long double s21_sqrt(double x) {
  long double result = 0.0;

  if (x < 0) {
    return S21_NAN;
  }
  if (x == 0) {
    result = 0.0;
  } else {
    long double n = x;
    long double prev;
    do {
      prev = n;
      n = 0.5 * (n + x / n);
    } while (s21_fabs(n - prev) > S21_EPS * s21_fabs(prev));
    result = n;
  }

  return result;
}
