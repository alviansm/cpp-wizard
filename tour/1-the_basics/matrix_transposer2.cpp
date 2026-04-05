#include <iostream>
using namespace std;

void inputMatrix(int *mat, int* mat_tp, int row, int col) {
    for (int i=0;i<row;i++) {
        for (int j=0;j<col;j++) {
            cin >> mat[i*col+j];
            mat_tp[j*row+i] = mat[i*col+j];
        }
    }
}

void displayMatrix(int *mat, const int row, const int col) {
    for (int i=0;i<row;i++) {
        for (int j=0;j<col;j++) {
            cout << mat[i*col+j] << " ";
        }
        cout << endl;
    }
}

int main() {
    constexpr int MAXSIZE = 10;
    int matrix[MAXSIZE][MAXSIZE];
    int matrix_transposed[MAXSIZE][MAXSIZE];
    int i, j;
    cin >> i >> j;

    inputMatrix(&matrix[0][0], &matrix_transposed[0][0], i, j);
    displayMatrix(&matrix[0][0], i, j);
    displayMatrix(&matrix_transposed[0][0], i, j);
}