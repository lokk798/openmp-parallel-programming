#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

#define N 100

void initialize_matrix(double matrix[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = rand() % 100;
        }
    }
}

void serial_matrix_multiply(double A[N][N], double B[N][N], double C[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            C[i][j] = 0.0;
            for (int k = 0; k < N; k++)
            {
                C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
            }
        }
    }
}

void parallel_matrix_multiply(double A[N][N], double B[N][N], double C[N][N])
{
#pragma omp parallel for collapse(2)
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            C[i][j] = 0.0;
            for (int k = 0; k < N; k++)
            {
                C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
            }
        }
    }
}

int main()
{

    double A[N][N], B[N][N], C_serial[N][N], C_parallel[N][N];

    // Initialize matrices
    initialize_matrix(A);
    initialize_matrix(B);

    // Measure serial execution time
    double start_serial = omp_get_wtime();
    serial_matrix_multiply(A, B, C_serial);
    double end_serial = omp_get_wtime();
    double serial_time = end_serial - start_serial;

    // Measure parallel execution time
    double start_parallel = omp_get_wtime();
    parallel_matrix_multiply(A, B, C_parallel);
    double end_parallel = omp_get_wtime();
    double parallel_time = end_parallel - start_parallel;

    // Output execution times
    printf("Serial Execution Time: %f seconds\n", serial_time);
    printf("Parallel Execution Time: %f seconds\n", parallel_time);
    printf("Speedup: %.2fx\n", serial_time / parallel_time);

    return 0;
}