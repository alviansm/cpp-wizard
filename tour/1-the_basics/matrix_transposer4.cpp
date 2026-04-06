#include <iostream>

void dispMatrix(int* m, int row, int col) {
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++)
            std::cout << m[i*col+j] << " ";
        std::cout << "\n";
    }
}

int main() {
    constexpr int MAX_DIM = 10;
    int matrix[MAX_DIM * MAX_DIM];
    int matrix_transposed[MAX_DIM * MAX_DIM];
    
    int r, c; // Row, Column number from the user
    if (!(std::cin >> r >> c)) { return 1; }

    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            std::cin >> matrix[i*c+j];
            matrix_transposed[j*r+i] = matrix[i*c+j]; 
        }
    }

    std::cout << "Matrix: \n";
    dispMatrix(matrix, r, c);

    std::cout << "Transposed: \n";
    dispMatrix(matrix_transposed, c, r);
}