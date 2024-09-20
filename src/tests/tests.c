#include <math.h>
#include <string.h>
#include "trighype.h"
#include "tests.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return -1;
    }

    if (strcmp(argv[1], "sin_t") == 0) {
        return test_sin_t() ? 0 : 1;
    } else if (strcmp(argv[1], "cos_t") == 0) {
        return test_cos_t() ? 0 : 1;
    } else if (strcmp(argv[1], "sinh_t") == 0) {
        return test_sinh_t() ? 0 : 1;
    } else if (strcmp(argv[1], "cosh_t") == 0) {
        return test_cosh_t() ? 0 : 1;
    } else {
        return -1;
    }
}

bool test_sin_t(void) {
    double x = - PI * 5;
    while (x <= PI * 5) {
        double result = t_sin_t(x);
        double expected = sin(x);
        if (fabs(result - expected) > 0.0000000000001) {
            return false;
        }
        x += 0.00001;
    }
    return true;
}

bool test_cos_t(void) {
    double x = - PI * 5;
    while (x <= PI * 5) {
        double result = t_cos_t(x);
        double expected = cos(x);
        if (fabs(result - expected) > 0.0000000000001) {
            return false;
        }
        x += 0.00001;
    }
    return true;
}

bool test_sinh_t(void) {
    double x = - PI * 5;
    while (x <= PI * 5) {
        double result = t_sinh_t(x);
        double expected = sinh(x);
        if (fabs(result - expected) > 0.000001) {
            return false;
        }
        x += 0.00001;
    }
    return true;
}

bool test_cosh_t(void) {
    double x = - PI * 5;
    while (x <= PI * 5) {
        double result = t_cosh_t(x);
        double expected = cosh(x);
        if (fabs(result - expected) > 0.000001) {
            return false;
        }
        x += 0.00001;
    }
    return true;
}
