#include <stdio.h>
#include <omp.h>

#define NUM_THREADS 4
#define NUM_INCREMENTS 10000

int main()
{

    int counter = 0;
    int expected = NUM_INCREMENTS * NUM_THREADS;

// Without synchronization
#pragma omp parallel num_threads(NUM_THREADS)
    {
        for (int i = 0; i < NUM_INCREMENTS; i++)
        {
            counter++;
        }
    }
    // End parallel

    printf("Without synchronization: Counter = %d (Expected = %d)\n", counter, expected);

    // reset counter
    counter = 0;
#pragma omp parallel num_threads(NUM_THREADS)
    {
        for (int i = 0; i < NUM_INCREMENTS; i++)
        {
#pragma omp critical
            {
                counter++;
            }
        }
    }
    // End parallel

    printf("With synchronization: Counter = %d (Expected = %d)\n", counter, NUM_THREADS * NUM_INCREMENTS);

    return 0;
}