#include <iostream>

int main() {
    int matrix[3][3];

    std::cout << "Enter a 3x3 matrix (you can use spaces and enters):" << std::endl;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    // Displaying it back to verify
    std::cout << "\nYour matrix is:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}