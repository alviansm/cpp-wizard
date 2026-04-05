// 1. Ask the user the number of row i and column j of the matrix
// 2. Print the initial matix
// 3. Print the transposed matrix

#include <iostream>
using namespace std;

#define ll long long
constexpr int MAXSIZE = 10;

void askRowColumn(int &i, int &j) {
    cout << "(10 Max)\n";
    cout << "Number of row: ";
    cin >> i;

    cout << "Number of column: ";
    cin >> j;    

    cout << "i: " << i << ", j: " << j << "\n";
}

void askRowColumnValue(int *mat, const int row, const int col) {
    for (int i=0; i < row; i++) {
        for (int j=0; j < col; j++) {
            cin >> mat[i*col+j];
        }
    }
}

void displayMatrix(int *mat, const int row, const int col) {
    cout << "\nYour matrix is:\n";
    for (int i=0; i < row; i++) {
        for (int j=0; j < col; j++) {
            cout << mat[i*col+j] << " ";
        }
        cout << "\n";
    }
}

void transposeMatrix(int *mat, const int row, const int col) {
    int res[MAXSIZE][MAXSIZE];
    for (int i=0;i<row;i++) {
        for (int j=0;j<col;j++) {
            *res[i*row+j] = mat[j*col+i];
        }
    }

    mat = *res;
}

int main() {
    int i, j; // i rows and j columns
    askRowColumn(i, j);
    if (i <= 0 || i > 10 || j <= 0 || j > 10) {
        cout << "\nPlease enter number correctly.\n";
        return -1;
    }
    
    int matrix[MAXSIZE][MAXSIZE];
    askRowColumnValue(*matrix, i, j);
    
    displayMatrix(*matrix, i, j);
    transposeMatrix(*matrix, i, j);
    displayMatrix(*matrix, i, j);

    return 0;
}