#include <stdio.h>
#include <omp.h>

int main()
{

    printf("Starting program with OpenMP version: %d \n", _OPENMP);

    // By default, OpenMP can dynamically change the number
    // of threads at runtime. Turn off the dynamic adjustment
    // to ensure the number of threads stays fixed.
    omp_set_dynamic(0);

    printf("This is the sequential part before the parallel region\n");

    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int total_threads = omp_get_num_threads();

        printf("Hello from thread %d from %d threads\n", thread_id, total_threads);

        // This makes all threads wait at this point until
        // each thread reaches the barrier.
        #pragma omp barrier
        if (thread_id == 0)
        {
            printf("Master thread (id: %d), reports: Total number of threads is: %d\n",
                   thread_id, total_threads);
        }
    }
    // End parallel region

    printf("This is the sequential part after the parallel region\n");

    return 0;
}