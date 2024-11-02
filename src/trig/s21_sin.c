#include "../s21_math.h"

long double s21_sin(double x) {
  x = s21_fmod(x, S21_2PI);
  long double res = x, pow = x;
  int sing = 1;
  long double x2 = x * x;
  long double fact = 1.0;
  for (int i = 1; i < 25; i++) {
    sing = -sing;
    fact *= (i * 2) * (i * 2 + 1);
    pow *= x2;
    res += (pow / fact) * sing;
  }
  return res;
}
