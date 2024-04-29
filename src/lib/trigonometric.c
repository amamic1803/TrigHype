#include "trigonometric.h"
#include <math.h>

double t_sin(double x) {
    x = fmod(x, 2 * M_PI);

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
