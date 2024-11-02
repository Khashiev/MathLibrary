#include "../s21_math.h"

long double s21_log(double x) {
  int int_counter = 0;
  double res_after_dot = 0;
  bool inf_test = false;
  if (x == 0.0) inf_test = true;
  if (x > 0) {
    if (x == S21_INF) {
      res_after_dot = S21_INF;
    } else {
      for (; x >= S21_M_E; int_counter++) {
        x = x / S21_M_E;
      }
      for (int i = 0; i < 100; i++) {
        res_after_dot = res_after_dot + 2 * ((x - s21_exp(res_after_dot)) /
                                             (x + s21_exp(res_after_dot)));
      }
    }
  } else {
    res_after_dot = S21_NAN;
  }
  return inf_test == true ? -S21_INF : (int_counter + res_after_dot);
}
