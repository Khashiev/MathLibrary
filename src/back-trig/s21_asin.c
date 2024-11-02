#include "../s21_math.h"

long double s21_asin(double x) { return (S21_PI_2 - s21_acos(x)); }
