#include <iostream>
#include <math.h>

class Vector2D {
public:
    Vector2D(int x, int y) : x{x}, y{y} {}
    double magnitude() {return sqrt(pow(x, 2)+pow(y, 2));}

private:
    int x;
    int y;
};

int main() {
    Vector2D a{3, 4};
    std::cout << a.magnitude() << "\n";

    return 0;
}