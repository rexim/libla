#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <la/matrix.h>
#include <la/triangulators.h>
#include <la/solvers.h>

#define FREE_IF_NOT_NULL(x) if (x != NULL) free(x);

int n = 0;
double minimum = 0.0, maximum = 0.0;
double precision = 0.0;
unsigned int seed = 0.0;

double *a = NULL;
double *b = NULL;
double *x = NULL;

void free_resources()
{
    FREE_IF_NOT_NULL(a);
    FREE_IF_NOT_NULL(b);
    FREE_IF_NOT_NULL(x);
}

void read_input_parameters(const char *data_file_name)
{
    FILE *data_file = fopen(data_file_name, "r");
    if (data_file == NULL) {
        perror(data_file_name);
        exit(EXIT_FAILURE);
    }
    fscanf(data_file, "%d%lf%lf%lf%d", &n, &minimum, &maximum, &precision, &seed);
    fclose(data_file);
}

void underline()
{
    printf("------------------------------\n");
}

void *malloc_or_die(size_t size)
{
    void *result = malloc(size);
    if (result == NULL) {
        perror(NULL);
        exit(EXIT_FAILURE);
    }
    return result;
}

void print_parameters()
{
    printf("  n: %d\n"
           "  minimum: %lf\n"
           "  maximum: %lf\n"
           "  precision: %lf\n"
           "  seed: %d\n",
           n, minimum, maximum, precision, seed);
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: ./la <data-file>\n");
        exit(EXIT_FAILURE);
    }

    const char *data_file_name = argv[1];
    read_input_parameters(data_file_name);

    atexit(free_resources);

    double *a = malloc_or_die(sizeof(double) * n * (n + 1));
    double *b = malloc_or_die(sizeof(double) * n * (n + 1));
    double *x = malloc_or_die(sizeof(double) * n);

    generate_random_matrix(a, n, n + 1, minimum, maximum, precision, seed);
    memcpy(b, a, sizeof(double) * n * (n + 1));

    printf("Gaussian Elimination\n");

    print_parameters();
    underline();

    print_matrix(a, n, n + 1, "A");
    underline();

    upper_triangulate_matrix(a, n, n + 1);
    backward_substitude(a, n, x);

    print_matrix(a, n, n + 1, "U");
    underline();

    print_matrix(x, n, 1, "x");
    underline();

    printf("Check Solution: ");

    if (check_solution(b, x, n, precision) == 0) {
        printf("OK\n");
        return EXIT_SUCCESS;
    } else {
        printf("WRONG\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
