#include "../s21_math.h"

long double s21_pow(double base, double exp) {
  long double res = 1;
  bool attenthion = false;
  bool minus_exp = false;
  if ((base == 0 && exp == -1) ||
      ((s21_fabs(base) > 1 || base == -S21_INF) && exp == S21_INF) ||
      ((base > 0 && base < 1) && exp == -S21_INF)) {
    res = S21_INF;
    attenthion = true;
  }
  if ((base == 0 && (exp == 1 || exp == S21_INF)) ||
      (base == S21_INF && (exp == -1 || exp == -S21_INF)) ||
      (base == -S21_INF && exp == -S21_INF) ||
      ((base > 0 && base < 1) && (exp == S21_INF)) ||
      (s21_fabs(base) > 1 && exp == -S21_INF)) {
    res = 0;
    attenthion = true;
  }
  if ((base == S21_INF && exp == 1) || (base == 0 && exp == 0) ||
      (s21_fabs(base) == 1 && (exp == -S21_INF || S21_ISNAN(exp)))) {
    res = 1;
    attenthion = true;
  }
  if (S21_ISNAN(base) || (base == -1 && S21_ISNAN(exp))) {
    res = S21_NAN;
    attenthion = true;
  }
  if (attenthion == false) {
    if (base < 0) {
      base = s21_fabs(base);
      long double overflow = __LDBL_MAX__ / base;
      if (exp == (int)exp) {
        if (exp < 0) {
          exp = -exp;
          minus_exp = true;
        }
        int i = (int)exp;
        while (i--) {
          res = res * base;
          if (res > overflow) {
            res = S21_INF;
            break;
          }
        }
        if ((int)exp % 2 != 0) {
          res = res * -1;
        }
      } else {
        if (base == S21_INF && !S21_ISNAN(exp)) {
          res = S21_INF;
        } else {
          res = S21_NAN;
        }
      }
    } else {
      res = s21_exp(exp * s21_log(base));
    }
  }
  if (minus_exp == true) res = 1.0 / res;
  if (exp == 0.0) res = 1;
  return res;
}
