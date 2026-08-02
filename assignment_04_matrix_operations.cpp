// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

void transpose(int a[10][10], int t[10][10], int r, int c)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            t[j][i] = a[i][j];
        }
    }
}

void add(int a[10][10], int b[10][10], int sum[10][10], int r, int c)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiply(int a[10][10], int b[10][10], int result[10][10],
              int r1, int c1, int c2)
{
    for(int i = 0; i < r1; i++)
    {
        for(int j = 0; j < c2; j++)
        {
            result[i][j] = 0;

            for(int k = 0; k < c1; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void print(int a[10][10], int r, int c)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cout << setw(5) << a[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int a[10][10], b[10][10], result[10][10];
    int r, col;

    cout << "=== Matrix Transpose ===\n";

    cout << "Enter number of rows: ";
    cin >> r;

    cout << "Enter number of columns: ";
    cin >> col;

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }

    transpose(a, result, r, col);

    cout << "\nTransposed Matrix:\n";
    print(result, col, r);


    cout << "\n=== Matrix Addition ===\n";

    cout << "Enter number of rows: ";
    cin >> r;

    cout << "Enter number of columns: ";
    cin >> col;

    cout << "\nEnter first matrix:\n";

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }

    cout << "\nEnter second matrix:\n";

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> b[i][j];
        }
    }

    add(a, b, result, r, col);

    cout << "\nSum Matrix:\n";
    print(result, r, col);


    int r1, c1, r2, c2;

    cout << "\n=== Matrix Multiplication ===\n";

    cout << "Enter rows of A: ";
    cin >> r1;

    cout << "Enter columns of A: ";
    cin >> c1;

    cout << "Enter rows of B: ";
    cin >> r2;

    cout << "Enter columns of B: ";
    cin >> c2;

    if(c1 != r2)
    {
        cout << "Cannot multiply matrices" << endl;
    }
    else
    {
        cout << "\nEnter Matrix A:\n";

        for(int i = 0; i < r1; i++)
        {
            for(int j = 0; j < c1; j++)
            {
                cout << "Enter element [" << i << "][" << j << "]: ";
                cin >> a[i][j];
            }
        }

        cout << "\nEnter Matrix B:\n";

        for(int i = 0; i < r2; i++)
        {
            for(int j = 0; j < c2; j++)
            {
                cout << "Enter element [" << i << "][" << j << "]: ";
                cin >> b[i][j];
            }
        }

        multiply(a, b, result, r1, c1, c2);

        cout << "\nProduct Matrix:\n";
        print(result, r1, c2);
    }

    return 0;
}
