#ifndef MATRIXMUL_H // header guard: to avoid the problem of multiple inclusion
#define MATRIXMUL_H
/*
 * performs MatrixA * MatrixB
 * @param mat1 - MatrixA
 * @param r1 - the number of rows of MatrixA
 * @param c1 - the number of columns of MatrixA
 * @param mat2 - MatrixB
 * @param r2 - the number of rows of MatrixB
 * @param c2 - the number of columns of MatrixB
 */
void printMatrixMul(int** mat1, int r1, int c1, int** mat2, int r2, int c2);
#endif
