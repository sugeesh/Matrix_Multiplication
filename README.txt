Matrix Multipication

Matrix Multipication code written in C. Both serial and parallel multipication codes available.

To run the code use follwing commands

1.) Serial Program
    compile -   gcc -o serial -fopenmp serial.c
    run     -   ./serial

2.) Parallel Program
    compile -   gcc -o parallel -fopenmp parallel.c
    run     -   ./parallel

3.) Optimized Parallel Program
    compile -   gcc -O2 -ftree-vectorize -msse2 -ftree-vectorizer-verbose=5 -fopenmp optimizedParallel1.c -o optimized1
    run     -   ./optimized1
