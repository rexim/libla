#ifndef SOLVERS_H_
#define SOLVERS_H_

// Takes upper trapezoidal matrix NxN+1 and produces vector of
// solutions x by backward substituting rows of u.
void backward_substitude(double const *u, int n, double *x);

// Takes a matrix NxN+1 and vector Nx1 of solutions. Checks weather
// the solutions are correct.
int check_solution(double const *a, double const *x, int n, double precision);

#endif  // SOLVERS_H_
