#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>

double multiplyMatrix(int number, double **matrix1, double **matrix2);

void fillValues(int number, double **matrix1, double **matrix2);

void runApp(int number);


int main() {

    srand(time(NULL));  // get random number
    omp_set_num_threads(8);

    for (int i = 200; i <= 2000; i=i+200) {
        runApp(i);
    }
    return 0;
}


void runApp(int number) {
    // Input matrix
    double **matrix1 = (double **) malloc(sizeof(double *) * number);
    double **matrix2 = (double **) malloc(sizeof(double *) * number);
    for (int i = 0; i < number; i++)
        matrix1[i] = (double *) malloc(sizeof(double) * number);
    for (int i = 0; i < number; i++)
        matrix2[i] = (double *) malloc(sizeof(double) * number);

    fflush(stdout);
    fillValues(number, matrix1, matrix2);


    double sum = 0;
    for (int i=0;i<20;i++) {

        sum += multiplyMatrix(number, matrix1, matrix2);

    }

    printf("Average for n = %d is %f \n",number,sum/20);
}


void fillValues(int number, double **matrix1, double **matrix2) {
    // Fill values
    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            matrix1[i][j] = (float) rand() / (float) (RAND_MAX / 10000);
            matrix2[i][j] = (float) rand() / (float) (RAND_MAX / 10000);
        }
    }
}


double multiplyMatrix(int number, double **matrix1, double **matrix2) {
    // Output matrix
    double **matrix3 = (double **) malloc(sizeof(double *) * number);
    for (int i = 0; i < number; i++) {
        matrix3[i] = (double *) malloc(sizeof(double) * number);
    }


    // Multiplication

    double startTime = omp_get_wtime();

    #pragma omp parallel for
    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            for (int m = 0; m < number; m++) {
                matrix3[i][j] += matrix1[i][m] * matrix2[m][j];
            }
        }
    }

    double endTime = omp_get_wtime();

    return (endTime - startTime);
}
