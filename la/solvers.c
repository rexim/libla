#include <stdio.h>
#include <math.h>

#include <la/solvers.h>

void backward_substitude(double const *u, int n, double *x)
{
    for (int i = n - 1; i >= 0; i--) {
        double s = 0.0;
        for (int j = n - 1; j > i; j--) {
            s += u[i * (n + 1) + j] * x[j];
        }

        x[i] = (u[i * (n + 1) + n] - s) / u[i * (n + 1) + i];
    }
}

int check_solution(double const *a, double const *x,
                   int n, double precision)
{
    for (int i = 0; i < n; i++) {
        float d = 0.0;
        for (int j = 0; j < n; j++) {
            d += a[i * (n + 1) + j] * x[j];
        }

        if (fabs(d - a[i * (n + 1) + n]) >= precision) {
            return 1;
        }
    }

    return 0;
}
