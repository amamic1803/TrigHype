#include <stdio.h>
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
    char *version = "0.1.0";

    if (argc <= 1) {
        printf("trighype v%s\n\n", version);
        printf("Usage: %s [OPTIONS] <COMMAND> <VALUE>\n\n", filename);
        printf("Try '%s --help' for more information.\n", filename);
        return 1;

    } else {
        bool version_flag = false;
        bool help_flag = false;
        bool degrees_flag = false;
        char *command = "";
        char *value_str = "";

        for (int i = 0; i < argc; i++) {
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
            printf("trighype v%s\n\n", version);
            printf("Usage: %s [OPTIONS] <COMMAND> <VALUE>\n\n", filename);
            printf("Arguments:\n");
            printf("  <COMMAND>       The command to run\n");
            printf("  <VALUE>         The value parameter (in radians by default for trigonometric functions)\n\n");
            printf("Commands:\n");
            printf("  sin             Calculate the sine of a value\n");
            printf("  cos             Calculate the cosine of a value\n");
            printf("  sinh            Calculate the hyperbolic sine of a value\n");
            printf("  cosh            Calculate the hyperbolic cosine of a value\n");
            printf("  degrad          Convert degrees to radians\n");
            printf("  raddeg          Convert radians to degrees\n\n");
            printf("Options:\n");
            printf("  -V, --version   Print version\n");
            printf("  -h, --help      Print help\n");
            printf("  -d, --degrees   Use degrees instead of radians\n");
        } else if (version_flag) {
            printf("%s\n", version);
        } else if (strcmp(command, "") != 0 && strcmp(value_str, "") == 0) {
            fprintf(stderr, "Missing value parameter\n");
            return 1;
        } else if (strcmp("sin", command) == 0) {
            if (argc <= 2) {
                printf("Usage: %s sin <VALUE>\n", filename);
                return 1;
            } else {
                double value = atof(argv[2]);
                printf("sin(%f) = %f\n", value, t_sin(value));
            }
        } else if (strcmp("cos", command) == 0) {
            if (argc <= 2) {
                printf("Usage: %s cos <VALUE>\n", filename);
                return 1;
            } else {
                double value = atof(argv[2]);
                printf("cos(%f) = %f\n", value, t_cos(value));
            }
        } else if (strcmp("sinh", command) == 0) {
            if (argc <= 2) {
                printf("Usage: %s sinh <VALUE>\n", filename);
                return 1;
            } else {
                double value = atof(argv[2]);
                printf("sinh(%f) = %f\n", value, t_sinh(value));
            }
        } else if (strcmp("cosh", command) == 0) {
            if (argc <= 2) {
                printf("Usage: %s cosh <VALUE>\n", filename);
                return 1;
            } else {
                double value = atof(argv[2]);
                printf("cosh(%f) = %f\n", value, t_cosh(value));
            }
        } else if (strcmp("degrad", command) == 0) {
            if (argc <= 2) {
                printf("Usage: %s degrad <VALUE>\n", filename);
                return 1;
            } else {
                double value = atof(argv[2]);
                printf("degrad(%f) = %f\n", value, t_degrad(value));
            }
        } else if (strcmp("raddeg", command) == 0) {
            if (argc <= 2) {
                printf("Usage: %s raddeg <VALUE>\n", filename);
                return 1;
            } else {
                double value = atof(argv[2]);
                printf("raddeg(%f) = %f\n", value, t_raddeg(value));
            }
        } else {
            printf("Unknown command: %s\n", argv[1]);
            return 1;
        }
    }

    // printf("mod: %f", t_sin(3.14159265358979323846 / 2.0));

    return 0;
}
