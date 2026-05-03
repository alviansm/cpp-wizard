// Variadic Templates
#include <iostream>

template <typename T>
void g(T x) {
    std::cout << x << " ";
}

void f() {
    std::cout << std::endl;
}

template<typename X, typename... Y>
void f(X head, Y... tail) {
    g(head);
    f(tail...);
}

int main() {
    f(5, "tail", 2.2, "14");

    return 0;
}