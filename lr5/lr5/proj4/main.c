#include "linalg.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    if(argc < 2) {
        fprintf(stderr, "Usage: %s <matrix_file>\n", argv[0]);
        return 1;
    }
    FILE *f = fopen(argv[1], "r");
    if(!f) { perror("fopen"); return 1; }
    int r1, c1, r2, c2;
    // ожидаем в файле: размеры первой матрицы, потом сами элементы, затем размеры второй и
    if(fscanf(f, "%d %d", &r1, &c1) != 2) { fprintf(stderr, "Invalid format\n"); return 1; }
    double **A = alloc_matrix(r1, c1);

    for(int i=0; i<r1; ++i) {
        for(int j=0; j<c1; ++j) {
            fscanf(f, "%lf", &A[i][j]);
        }
    }
    if(fscanf(f, "%d %d", &r2, &c2) != 2) { fprintf(stderr, "Invalid format\n"); return 1; }
    double **B = alloc_matrix(r2, c2);
    for(int i=0; i<r2; ++i) {
        for(int j=0; j<c2; ++j) {
            fscanf(f, "%lf", &B[i][j]);
        }
    }
    fclose(f);
    if(c1 != r2) {
        fprintf(stderr, "Matrix dimensions incompatible for multiplication\n");
        return 1;
    }
    double **C = alloc_matrix(r1, c2);
    mat_multiply(A, B, C, r1, c1, c2);
    // Вывод результата
    printf("Result matrix (%dx%d):\n", r1, c2);
    for(int i=0; i<r1; ++i) {
        for(int j=0; j<c2; ++j) {
            printf("%8.2f ", C[i][j]);
        }
        printf("\n");
    }
    // освобождаем память
    free_matrix(A, r1);
    free_matrix(B, r2);
    free_matrix(C, r1);
    return 0;
}