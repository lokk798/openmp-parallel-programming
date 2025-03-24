#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>

#define N 1000000

int main()
{

    // Allocate memory for vectors
    double *A = (double *)malloc(N * sizeof(double));
    double *B = (double *)malloc(N * sizeof(double));
    double *C = (double *)malloc(N * sizeof(double));

    for (int i = 0; i < N; i++)
    {
        A[i] = i * 1.0;
        B[i] = i * 2.0;
    }

    // Serial execution
    double start_serial = omp_get_wtime();
    for (int i = 0; i < N; i++)
    {
        C[i] = A[i] + B[i];
    }
    double end_serial = omp_get_wtime();
    double serial_time = end_serial - start_serial;

    // Parallel execution
    double start_parallel = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < N; i++)
    {
        C[i] = A[i] + B[i];
    }
    double end_parallel = omp_get_wtime();
    double parallel_time = end_parallel - start_parallel;

    printf("Vector size %d\n", N);
    printf("Serial execution time: %.6f seconds\n", serial_time);
    printf("Parallel execution time: %.6f seconds\n", parallel_time);
    printf("Speedup: %.2fx\n", serial_time / parallel_time);

    free(A);
    free(B);
    free(C);

    return 0;
}