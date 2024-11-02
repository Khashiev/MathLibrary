#include "../s21_math.h"

long double s21_ceil(double x) {
  long long integer_number = (long long)x;
  long double result = 0.0;
  if (S21_ISNAN(x) || S21_ISINF(x)) {
    return x;
  }
  if (x == (double)integer_number) {
    result = (long double)integer_number;
  } else if (x > 0) {
    result = (long double)(integer_number + 1);
  } else {
    result = (long double)integer_number;
  }

  return result;
}
