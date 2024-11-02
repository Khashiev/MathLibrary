#include "../s21_math.h"

long double s21_atan(double x) {
  long double result = 0.0;

  if (x > 1) {
    result = S21_PI_2 - s21_atan(1 / x);
  } else if (x < -1) {
    result = -S21_PI_2 - s21_atan(1 / x);
  } else {
    double sum = x;
    double curr = x;
    double prev;

    for (int i = 3; s21_fabs(curr) > S21_EPS; i += 2) {
      prev = curr;
      curr = -curr * x * x * ((i - 2) / (double)i);
      sum += curr;

      if (s21_fabs(prev - curr) < S21_EPS) {
        break;
      }
    }
    result = (long double)sum;
  }

  return result;
}
