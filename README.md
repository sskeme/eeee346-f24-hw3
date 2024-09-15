# Introduction

In this homework assignment, you will implement a function that performs matrix multiplication. You will practice dynamically allocating and deallocating memory for 2D arrays and using the allocated arrays.


# Background: Matrix Multiplication

Please refer to [this](https://en.wikipedia.org/wiki/Matrix_multiplication#:~:text=In%20mathematics%2C%20particularly%20in%20linear,rows%20in%20the%20second%20matrix.).

# Task

* Implement the printMatrixMul() function in matrixMul.cpp.
  * You must 1) create a 2D dynamic array for the resulting matrix, 2) compute and store the resulting values in the matrix, 3) display the element values using cout statements, and 4) deallocate the dynamic memory from the 2D array.
  * When displaying the element values, insert a space to separate columns and a line break to distinguish rows (see the test output example below).
  * This function is already declared in matrixMul.h, and you can find information about its parameters in this header file.
  * Assume that input matrix dimensions are always compatible.

# Compile and Test

1. Type the following commands on Terminal.

```
g++ -o main *.cpp *.h
```
```
./main
```

2. Enter the number of rows of Matrix A, the number of columns of Matrix A, the element values of Matrix A, the number of rows of Matrix B, the number of columns of Matrix B, and the element values of Matrix B in order. Here is an example.

![example](https://github.com/sskeme/eeee346-s24-hw3-/assets/154963758/788bd7e2-211e-4036-b059-b6de7bc6d7cf)

 * Input
 ```
 2
 3 
 1 2 3
 4 5 6
 3
 2
 7 8
 9 10
 11 12
 ```

 * Output
 ```
 58 64
 139 154
 ```

Here are the additional inputs for testing your program. Please calculate the expected outputs on your own and compare them with the results printed by your program.
```
1 
4 
2 -3 0 4
4 
1 
2 
4 
5 
-3
```

```
3 
2 
5 3 
-2 4 
-1 0
2 
4 
2 0 1 3 
4 5 2 6
```

```
2 
4 
3 2 1 5 
9 1 3 0
4 
3 
2 9 0 
1 3 5 
2 4 7 
8 1 5 
```

# Submit

Please upload your `matrixMul.cpp` file to `myCourses > Assignments > HW3`. Do not submit *.docx, *.pdf, *.txt, or *.zip file. 
