// do not change the code in this source file
#include <iostream>
#include "matrixMul.h"

using namespace std;

int main() {
    int row1, col1; // for matrix1
    int row2, col2; // for matrix2

    // create 2D matrix1
    cin >> row1 >> col1; // get the number of rows and columns
    int** matrix1 = new int* [row1]; // create an array for row1 pointers
    for (int i=0; i<row1; i++) {
        matrix1[i] = new int [col1]; // create an array for col1 integers for each array pointer
    }
    // get row1 x col1 element values of matrix1
    for (int r=0; r<row1; r++) {
        for (int c=0; c<col1; c++) {
            cin >> matrix1[r][c];
        }
    }

    // create 2D matrix2
    cin >> row2 >> col2;
    int** matrix2 = new int* [row2];
    for (int i=0; i<row2; i++) {
        matrix2[i] = new int [col2];
    }
    for (int r=0; r<row2; r++) {
        for (int c=0; c<col2; c++) {
            cin >> matrix2[r][c];
        }
    }

    printMatrixMul(matrix1, row1, col1, matrix2, row2, col2); // call printMatrixMul() to compute matrix1 * matrix2

    // deallocate the memory
    for (int i=0; i<row2; i++) {
        delete [] matrix2[i];
    }
    delete [] matrix2;

    for (int i=0; i<row1; i++) {
        delete [] matrix1[i];
    }
    delete [] matrix1;

    return 0;
}
