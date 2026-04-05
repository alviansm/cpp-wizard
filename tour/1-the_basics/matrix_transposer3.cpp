#include <iostream>

// Use const for parameters that shouldn't change
void display(int* mat, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            std::cout << mat[i * cols + j] << ' ';
        std::cout << '\n';
    }
}

int main() {
    constexpr int max_dim = 10;
    int mat[max_dim * max_dim];    // Flattened array is often cleaner
    int trans[max_dim * max_dim];
    
    int r, c;
    if (!(std::cin >> r >> c)) return 1; // Basic error check

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            std::cin >> mat[i * c + j];
            trans[j * r + i] = mat[i * c + j]; // Transpose logic is spot on
        }
    }

    std::cout << "Original:\n";
    display(mat, r, c);
    
    std::cout << "Transpose:\n";
    display(trans, c, r);
}