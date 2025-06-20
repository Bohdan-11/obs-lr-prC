#ifndef LINALG_H
#define LINALG_H
// Функция для умножения матриц.
// A размером r1 x c1, B размером c1 x c2; результат C размером r1 x c2 (должен быть выделен
void mat_multiply(double **A, double **B, double **C, int r1, int c1, int c2);
// Функция для выделения памяти под матрицу r x c
double **alloc_matrix(int r, int c);
// Освобождение памяти матрицы
void free_matrix(double **M, int r);
#endif
