#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trighype.h"

int main(int argc, char *argv[]) {
    char *filename = argv[0];
    for (int i = (int) strlen(argv[0]) - 1; i >= 0; i--) {
        if (argv[0][i] == '/' || argv[0][i] == '\\') {
            filename = &argv[0][i + 1];
            break;
        }
    }

    if (argc <= 1) {
        printf("trighype v%s\n\n", TRIGHYPE_VERSION);
        printf("Usage: %s [OPTIONS] <COMMAND> <VALUE>\n\n", filename);
        printf("Try '%s --help' for more information.\n", filename);
        return 1;

    } else {
        bool version_flag = false;
        bool help_flag = false;
        bool degrees_flag = false;
        char *command = "";
        char *value_str = "";

        for (int i = 1; i < argc; i++) {
            if (strcmp("--version", argv[i]) == 0 || strcmp("-V", argv[i]) == 0) {
                version_flag = true;
            } else if (strcmp("--help", argv[i]) == 0 || strcmp("-h", argv[i]) == 0) {
                help_flag = true;
            } else if (strcmp("--degrees", argv[i]) == 0 || strcmp("-d", argv[i]) == 0) {
                degrees_flag = true;
            } else if (strcmp(command, "") == 0) {
                command = argv[i];
            } else if (strcmp(value_str, "") == 0) {
                value_str = argv[i];
            } else {
                fprintf(stderr, "Too many arguments\n");
                return 1;
            }
        }

        if (help_flag) {
            printf("trighype v%s\n\n", TRIGHYPE_VERSION);
            printf("Usage: %s [OPTIONS] <COMMAND> <VALUE>\n\n", filename);
            printf("Arguments:\n");
            printf("  <COMMAND>       The command to run\n");
            printf("  <VALUE>         The value parameter (in radians by default for trigonometric functions)\n\n");
            printf("Commands:\n");
            printf("  sin             Calculate the sine of a value\n");
            printf("  sin_t           Calculate the sine of a value using Taylor series\n");
            printf("  cos             Calculate the cosine of a value\n");
            printf("  cos_t           Calculate the cosine of a value using Taylor series\n");
            printf("  tan             Calculate the tangent of a value\n");
            printf("  cot             Calculate the cotangent of a value\n");
            printf("  sinh            Calculate the hyperbolic sine of a value\n");
            printf("  sinh_t          Calculate the hyperbolic sine of a value using Taylor series\n");
            printf("  cosh            Calculate the hyperbolic cosine of a value\n");
            printf("  cosh_t          Calculate the hyperbolic cosine of a value using Taylor series\n");
            printf("  tanh            Calculate the hyperbolic tangent of a value\n");
            printf("  coth            Calculate the hyperbolic cotangent of a value\n");
            printf("  deg2rad         Convert degrees to radians\n");
            printf("  rad2deg         Convert radians to degrees\n\n");
            printf("Options:\n");
            printf("  -V, --version   Print version\n");
            printf("  -h, --help      Print help\n");
            printf("  -d, --degrees   Use degrees instead of radians\n");
        } else if (version_flag) {
            printf("%s\n", TRIGHYPE_VERSION);
        } else if (strcmp(command, "") != 0 && strcmp(value_str, "") == 0) {
            fprintf(stderr, "Missing value parameter\n");
            return 1;
        } else {
            char *endptr;
            double value = strtod(value_str, &endptr);
            if (value_str == endptr && value == 0.0) {
                fprintf(stderr, "Invalid value parameter\n");
                return 1;
            }
            if (degrees_flag) {
                value = t_deg2rad(value);
            }

            if (strcmp("sin_t", command) == 0) {
                printf("%.*g\n", DBL_DIG, t_sin_t(value));
            } else if (strcmp("cos_t", command) == 0) {
                printf("%.*g\n", DBL_DIG, t_cos_t(value));
            } else if (strcmp("sinh_t", command) == 0) {
                printf("%.*g\n", DBL_DIG, t_sinh_t(value));
            } else if (strcmp("cosh_t", command) == 0) {
                printf("%.*g\n", DBL_DIG, t_cosh_t(value));
            } else if (strcmp("deg2rad", command) == 0) {
                printf("%.*g\n", DBL_DIG, t_deg2rad(value));
            } else if (strcmp("rad2deg", command) == 0) {
                printf("%.*g\n", DBL_DIG, degrees_flag ? value : t_rad2deg(value));
            } else {
                printf("Unknown command: %s\n", argv[1]);
                return 1;
            }
        }
    }

    return 0;
}
