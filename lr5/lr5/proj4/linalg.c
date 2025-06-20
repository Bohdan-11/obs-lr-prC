#include "linalg.h"
#include <stdlib.h>
void mat_multiply(double **A, double **B, double **C, int r1, int c1, int c2) {
    for(int i=0; i<r1; ++i) {
        for(int j=0; j<c2; ++j) {
            C[i][j] = 0.0;
            for(int k=0; k<c1; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
double **alloc_matrix(int r, int c) {
    double **M = malloc(r * sizeof(double*));
    if (!M) return NULL;
    for(int i=0; i<r; ++i) {
        M[i] = malloc(c * sizeof(double));
        if(!M[i]) { /* handle allocation error, not shown for brevity */ }
    }
    return M;
}
void free_matrix(double **M, int r) {
    if (!M) return;
    for(int i=0; i<r; ++i) {
        free(M[i]);
    }
    free(M);
}
