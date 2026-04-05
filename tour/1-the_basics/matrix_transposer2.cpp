#include <iostream>
using namespace std;

void inputMatrix(int *mat, int row, int col) {
    for (int i=0;i<row;i++) {
        for (int j=0;j<col;j++) {
            cin >> mat[i*row+j];
        }
    }
}

void inputMatrix(int &mat) {

}

int main() {
    constexpr int MAXSIZE = 10;
    int matrix[MAXSIZE][MAXSIZE];
    int matrix_transposed[MAXSIZE][MAXSIZE];
    int i, j;
    cin >> i >> j;

    inputMatrix(&matrix[0][0], i, j);

    inputMatrix(&matrix[0][0]);
}