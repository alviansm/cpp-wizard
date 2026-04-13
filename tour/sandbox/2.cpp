#include <iostream>
#include <conio.h> // Windows specific

int main() {
    std::cout << "Press Ctrl+Q to quit immediately..." << std::endl;
    
    while (true) {
        if (_kbhit()) { // Check if a key was pressed
            char ch = _getch();
            if (ch == 17) { // 17 is Ctrl+Q
                break;
            }
            std::cout << "You pressed: " << ch << std::endl;
        }
    }
    return 0;
}