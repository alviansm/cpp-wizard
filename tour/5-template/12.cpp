// Lambda function
#include <iostream>
#include <functional>

int main() {
    int a=5,b=12;

    std::function<int(int, int)> sum = [=](int a, int b) {return a+b;}; // Capture by value
    
    int cbv = sum(a, b);
    a=7;b=24;
    std::cout << cbv << std::endl;

    auto sum_ref = [&](int& a, int& b) {return a+b;}; // Capture by reference
    int cbr = sum_ref(a,b);
    a=7;b=24;
    std::cout << cbr << std::endl;

    return 0;
}