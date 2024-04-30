#include "hyperbolic.h"
#include <math.h>

double t_sinh(double x) {
    // Taylor series: sinh(x) = x + x^3 / 3! + x^5 / 5! + x^7 / 7! + ...

    double result = x;
    double old_result = INFINITY;
    double factorial = 1.0;
    double power = x;

    for (unsigned short int counter = 2; old_result != result; counter += 2) {
        factorial *= (double) (counter * (counter + 1));
        power *= x * x;
        old_result = result;
        result += power / factorial;
    }
    return result;
}

double t_cosh(double x) {
    // Taylor series: cosh(x) = 1 + x^2 / 2! + x^4 / 4! + x^6 / 6! + ...

    double result = 1;
    double old_result = INFINITY;
    double factorial = 1.0;
    double power = 1.0;

    for (unsigned short int counter = 1; old_result != result; counter += 2) {
        factorial *= (double) (counter * (counter + 1));
        power *= x * x;
        old_result = result;
        result += power / factorial;
    }

    return result;
}
