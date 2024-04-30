#include "trigonometric.h"
#include <math.h>

double t_sin(double x) {
    x = fmod(x, 2 * M_PI);

    // Taylor series: sin(x) = x - x^3 / 3! + x^5 / 5! - x^7 / 7! + ...

    double result = x;
    double old_result = INFINITY;
    double factorial = 1.0;
    double power = x;

    bool sign = false;  // false for negative, true for positive
    for (unsigned short int counter = 2; old_result != result; counter += 2, sign = !sign) {
        factorial *= (double) (counter * (counter + 1));
        power *= x * x;

        old_result = result;
        if (sign) {
            result += power / factorial;
        } else {
            result -= power / factorial;
        }
    }

    return result;
}

double t_cos(double x) {
    x = fmod(x, 2 * M_PI);

    // Taylor series: cos(x) = 1 - x^2 / 2! + x^4 / 4! - x^6 / 6! + ...

    double result = 1;
    double old_result = INFINITY;
    double factorial = 1.0;
    double power = 1.0;

    bool sign = false;  // false for negative, true for positive
    for (unsigned short int counter = 1; old_result != result; counter += 2, sign = !sign) {
        factorial *= (double) (counter * (counter + 1));
        power *= x * x;

        old_result = result;
        if (sign) {
            result += power / factorial;
        } else {
            result -= power / factorial;
        }
    }

    return result;
}
