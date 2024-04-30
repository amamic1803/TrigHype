#include <math.h>
#include <stdio.h>
#include <string.h>
#include "trighype.h"
#include "tests.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return -1;
    }

    if (strcmp(argv[1], "sin") == 0) {
        return test_sin();
    } else if (strcmp(argv[1], "cos") == 0) {
        return test_cos();
    } else if (strcmp(argv[1], "sinh") == 0) {
        return test_sinh();
    } else if (strcmp(argv[1], "cosh") == 0) {
        return test_cosh();
    } else {
        return -1;
    }
}

int test_sin() {
    double x = - M_PI * 5;
    while (x <= M_PI * 5) {
        double result = t_sin(x);
        double expected = sin(x);
        if (fabs(result - expected) > 0.0000000000001) {
            return -1;
        }
        x += 0.00001;
    }
    return 0;
}

int test_cos() {
    double x = - M_PI * 5;
    while (x <= M_PI * 5) {
        double result = t_cos(x);
        double expected = cos(x);
        if (fabs(result - expected) > 0.0000000000001) {
            return -1;
        }
        x += 0.00001;
    }
    return 0;
}

int test_sinh() {
    double x = - M_PI * 5;
    while (x <= M_PI * 5) {
        double result = t_sinh(x);
        double expected = sinh(x);
        if (fabs(result - expected) > 0.000001) {
            return -1;
        }
        x += 0.00001;
    }
    return 0;
}

int test_cosh() {
    double x = - M_PI * 5;
    while (x <= M_PI * 5) {
        double result = t_cosh(x);
        double expected = cosh(x);
        if (fabs(result - expected) > 0.000001) {
            return -1;
        }
        x += 0.00001;
    }
    return 0;
}
