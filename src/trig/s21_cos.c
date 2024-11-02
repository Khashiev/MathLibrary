#include "../s21_math.h"

long double s21_cos(double x) {
  x = s21_fmod(x, S21_2PI);
  long double res = 1.0, pow = x * x;
  int sing = 1;
  long double fact = 2.0;
  for (int i = 2; i < 25; i++) {
    sing = -sing;
    res += (pow / fact) * sing;
    fact *= (i * 2 - 1) * (i * 2);
    pow *= (x * x);
  }
  return res;
}
