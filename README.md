# OpenMP Parallel Programming

This repository contains code examples and exercises for learning the basics of parallel programming with OpenMP in C/C++.

1. **Basic Parallel Region:**

   - Demonstrates the execution of a parallel region using OpenMP.
   - Identifies and displays the thread number executing the code.

2. **Parallel Vector Operation:**

   - Implements vector addition of two large arrays with OpenMP directives.
   - Compares execution time between serial and parallel implementations.

3. **Parallel Matrix Computation:**

   - Performs matrix multiplication of two square matrices.
   - Parallelizes the matrix multiplication process and measures execution time for different matrix sizes and thread counts.

4. **Shared Resource Access:**
   - Simulates multiple threads incrementing a shared counter variable.
   - Compares results with and without synchronization to highlight the importance of managing shared resources in parallel programming.

## How to Run

1. Compile your code with OpenMP support (GCC example):
   ```bash
   gcc -fopenmp <filename>.c -o <executable_name>
   ```
2. Set the number of threads:
   ```bash
   export OMP_NUM_THREADS=4
   ```
3. Run the executable:
   ```bash
   ./<executable_name>
   ```
