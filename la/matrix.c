#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <la/matrix.h>

static double random_double(double minimum, double maximum, double precision)
{
    int alpha = (int)ceil(fabs(maximum - minimum) / precision);
    return (rand() % alpha) * precision + minimum;
}

void print_matrix(double const *a, int n, int m,
                  const char *matrix_name)
{
    printf("%s = \n", matrix_name);
    for (int i = 0; i < n; i++) {
        printf("  [%d]", i);
        for (int j = 0; j < m; j++) {
            printf("\t%f", a[i * m + j]);
        }
        printf("\n");
    }
}

void generate_random_matrix(double *a, int n, int m,
                            double minimum, double maximum,
                            double precision,
                            unsigned int seed)
{
    srand(seed);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i * m + j] = random_double(minimum, maximum, precision);
        }
    }
}
