#ifndef MATRIX_H_
#define MATRIX_H_

void print_matrix(double const *a, int n, int m,
                  const char *matrix_name);
void generate_random_matrix(double *a, int n, int m,
                            double minimum, double maximum,
                            double precision,
                            unsigned int seed);

#endif  // MATRIX_H_
