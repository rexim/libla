#include <la/triangulators.h>

void upper_triangulate_matrix(double *a, int n, int m)
{
    int t = n <= m ? 0 : n - m;

    for (int i = t; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double x = a[i * m + i - t];
            double y = a[j * m + i - t];
            double alpha = y / x;
            for (int k = 0; k < m; k++) {
                a[j * m + k] -= alpha * a[i * m + k];
            }
        }
    }
}
